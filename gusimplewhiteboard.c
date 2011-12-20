/*
 *  gusimplewhiteboard.h
 *  
 *  Created by René Hexel on 20/12/11.
 *  Copyright (c) 2011 Rene Hexel.
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Rene Hexel.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <gu_util.h>
#include "gusimplewhiteboard.h"

#define WHITEBOARD_MAGIC        0xfeeda11deadbeef5ULL
#define SEMAPHORE_MAGIC_KEY     4242
#define SEM_ERROR               -1

static const char *known_message_types[GSW_NUM_RESERVED] =
{
        "Print", "Say", "Speech"
};


void gsw_init_semaphores(gsw_sema_t s)
{
        union semun init;
        init.val = 1;
        for (enum gsw_semaphores i = 0; i < GSW_NUM_SEM; i++)
                if (semctl(s, 1, SETVAL, init) == -1)
                        fprintf(stderr, "Warning; failed to initialise whiteboard semaphore %d: %s\n", i, strerror(errno));
}


gsw_sema_t gsw_setup_semaphores(void)
{
        int semflg = SEM_R|SEM_A|(SEM_R>>3)|(SEM_A>>3);
        gsw_sema_t s = semget(SEMAPHORE_MAGIC_KEY, GSW_NUM_SEM, semflg);

        if (s == SEM_ERROR)
        {
                s = semget(SEMAPHORE_MAGIC_KEY, GSW_NUM_SEM, semflg | IPC_CREAT);
                if (s == SEM_ERROR) return s;

                gsw_init_semaphores(s);
        }
        return s;
}


gu_simple_whiteboard_descriptor *gsw_new_whiteboard(const char *name)
{
        gu_simple_whiteboard_descriptor *wbd = calloc(sizeof(gu_simple_whiteboard_descriptor), 1);
        if (!wbd)
        {
                fprintf(stderr, "Not enough memory to create whiteboard '%s': %s\n", name, strerror(errno));
                return NULL;
        }

        wbd->sem = gsw_setup_semaphores();
        if (wbd->sem == SEM_ERROR)
                fprintf(stderr, "Warning; cannot get semaphore %d for whiteboard '%s': %s (proceeding without)\n", SEMAPHORE_MAGIC_KEY, name, strerror(errno));

        bool init = false;
        wbd->wb = gsw_create(name, &wbd->fd, &init);
        if (!wbd->wb)
        {
                gsw_free_whiteboard(wbd);
                return NULL;
        }
        if (init)
        {
                gsw_init_semaphores(wbd->sem);

                for (enum gsw_message_types i = 0; i < GSW_NUM_RESERVED; i++)
                        gsw_register_message_type(wbd, known_message_types[i]);
        }
        return wbd;
}

gu_simple_whiteboard *gsw_create(const char *name, int *fdp, bool *initial)
{
        char path[PATH_MAX] = "/tmp/";
        if (!name || strlen(name) > PATH_MAX-strlen(path)-1) name = GSW_DEFAULT_NAME;

        int fd = open(path, O_CREAT|O_RDWR, 0660);
        if (fd == -1)
        {
                fprintf(stderr, "Cannot open/create '%s': %s\n", path, strerror(errno));
                return NULL;
        }

        if (ftruncate(fd, sizeof(gu_simple_whiteboard)) == -1)
            fprintf(stderr, "Warning; cannot reserve %lu bytes for '%s': %s\n", sizeof(gu_simple_whiteboard), path, strerror(errno));

        gu_simple_whiteboard *wb = mmap(NULL, sizeof(*wb), PROT_READ|PROT_WRITE, MAP_FILE|MAP_SHARED, fd, 0);
        if (!wb)
        {
                fprintf(stderr, "Cannot mmap '%s': %s\n", path, strerror(errno));
                close(fd);
        }
        else if (fdp) *fdp = fd;

        if (wb->magic != WHITEBOARD_MAGIC)      // new whiteboard? -> initialise
        {
                memset(wb, 0, sizeof(*wb));
                wb->version      = GU_SIMPLE_WHITEBOARD_VERSION;
                wb->max_lifespan = GU_SIMPLE_WHITEBOARD_GENERATIONS;
                wb->num_reserved = GSW_NUM_RESERVED;
                wb->magic = WHITEBOARD_MAGIC;

                if (initial) *initial = true;

                DBG(printf("New Whiteboard version %d created and initialised at '%s'\n", wb->version, path));
        }
        else if (initial) *initial = false;

        bool bailout = wb->version != GU_SIMPLE_WHITEBOARD_VERSION;
        if (bailout) fprintf(stderr, "*** Unexpected Whiteboard version %d (expected %d for '%s')\n", wb->version, GU_SIMPLE_WHITEBOARD_VERSION, path);

        bailout |= wb->max_lifespan != GU_SIMPLE_WHITEBOARD_GENERATIONS;
        if (bailout) fprintf(stderr, "*** Invalid maximum lifespan %d (expected %d for '%s')\n", wb->max_lifespan, GU_SIMPLE_WHITEBOARD_GENERATIONS, path);
        
        bailout |= wb->num_reserved != GSW_NUM_RESERVED;
        if (bailout) fprintf(stderr, "*** Invalid number of reserved messages: %d (expected %d for '%s')\n", wb->num_reserved, GSW_NUM_RESERVED, path);

        if (bailout)
        {
                gsw_free(wb, fd);
                return NULL;
        }
        return wb;
}


void gsw_free(gu_simple_whiteboard *wb, int fd)
{
        if (munmap(wb, sizeof(*wb)) == -1)
                fprintf(stderr, "Cannot unmap whiteboard at %p with fd %d: %s\n", wb, fd, strerror(errno));
        if (fd >= 0) if (close(fd) == -1)
                fprintf(stderr, "Cannot close whiteboard at %p with fd %d: %s\n", wb, fd, strerror(errno));
}


int gsw_procure(gsw_sema_t sem, enum gsw_semaphores s)
{
        struct sembuf op = { s, -1, 0 };
        int rv;
        while ((rv = semop(sem, &op, 1)) == -1)
               if (errno != EAGAIN)
                       break;
        return rv;
}


int gsw_vacate(gsw_sema_t sem, enum gsw_semaphores s)
{
        struct sembuf op = { s, 1, 0 };
        int rv;
        while ((rv = semop(sem, &op, 1)) == -1)
                if (errno != EAGAIN)
                        break;
        return rv;
}


static u_int32_t hash_of(const char *s)
{
        u_int32_t hash = *s;
        while (*s++)
        {
                u_int32_t stir = hash & 0xf8000000U;
                hash &= 0x07ffffffU;
                hash <<= 5;
                hash ^= stir >> 27;
                hash ^= *s;
        }
        return hash;
}


static u_int32_t alt_hash(const char *s)
{
        u_int32_t hash = *s;
        while (*s++)
        {
                hash &= 0x0fffffffU;
                hash <<= 4;
                hash += *s;
                u_int32_t stir = hash & 0xf0000000U;
                if (stir != 0)
                {
                        hash ^= stir >> 24;
                        hash ^= stir;
                }
        }
        hash |= 1;              // needs to be an odd number

        return hash;
}


int gsw_register_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name)
{
        gsw_procure(wbd->sem, GSW_SEM_MSGTYPE);

        bool exists = false;
        gu_simple_whiteboard *wb = wbd->wb;
        unsigned offs = hash_of(name) % GSW_TOTAL_MESSAGE_TYPES;
        gu_simple_message *type = &wb->hashes[offs];

        while (wb->num_types < GSW_TOTAL_MESSAGE_TYPES)
        {
                gu_simple_message *type = &wb->hashes[offs];
                if (!*type->hash.string)
                {
                        strlcpy(type->hash.string, name, sizeof(type->hash.string));
                        DBG(printf(" - registering wb message type #%d for '%s' at %d", wb->num_types, type->hash.string, offs));
                        type->hash.value = wb->num_types++;
                        break;
                }
                if (strcmp(type->hash.string, name) == 0)
                {
                        exists = true;
                        break;
                }
                /* collision, add to the offset */
                offs += alt_hash(name);
                offs %= GSW_TOTAL_MESSAGE_TYPES;
        }

        gsw_vacate(wbd->sem, GSW_SEM_MSGTYPE);

        if (wb->num_types < GSW_TOTAL_MESSAGE_TYPES)
                return type->hash.value;

        fprintf(stderr, "Cannot register whiteboard message type '%s': hash table capacity %d reached!\n", name, wb->num_types);

        return -1;
}


int gsw_offset_for_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name)
{
        gu_simple_whiteboard *wb = wbd->wb;
        unsigned offs = hash_of(name) % GSW_TOTAL_MESSAGE_TYPES;
        gu_simple_message *type = &wb->hashes[offs];
        for (int i = 0; i < GSW_TOTAL_MESSAGE_TYPES; i++)
        {
                if (!*type->hash.string)                        // new message type?
                        return gsw_register_message_type(wbd, name);
                if (strcmp(type->hash.string, name) == 0)
                        return offs;
                /* hash collision, add to the offset */
                offs += alt_hash(name);
                offs %= GSW_TOTAL_MESSAGE_TYPES;
        }

        fprintf(stderr, "Cannot get offset for message type '%s': hash table full (%d entries)\n", name, wb->num_types);

        return -1;
}

gu_simple_message *gsw_current_message(gu_simple_whiteboard *wb, int i)
{
        u_int8_t j = wb->indexes[i];
        if (j >= GU_SIMPLE_WHITEBOARD_GENERATIONS) j = 0;
        return &wb->messages[i][j];
}


gu_simple_message *gsw_next_message(gu_simple_whiteboard *wb, int i)
{
        u_int8_t j = wb->indexes[i];
        if (++j >= GU_SIMPLE_WHITEBOARD_GENERATIONS) j = 0;
        wb->indexes[i] = j;
        return &wb->messages[i][j];
}

