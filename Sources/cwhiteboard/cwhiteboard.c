/*
 *  gusimplewhiteboard.c
 *  
 *  Created by René Hexel on 20/12/11.
 *  Copyright (c) 2011, 2012, 2013, 2014, 2015, 2020, 2021 Rene Hexel.
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
 *    software must display the following acknowledgment:
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wclass-varargs"
#pragma clang diagnostic ignored "-Wbuiltin-requires-header"
#pragma clang diagnostic ignored "-W#warnings"

#ifdef __linux
#ifndef _BSD_SOURCE
#define _BSD_SOURCE
#endif
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE 200112L
#endif
#endif
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif
#ifdef __APPLE__
#ifndef _DARWIN_C_SOURCE
#define _DARWIN_C_SOURCE 200112L
#define __DARWIN_C_LEVEL 200112L
#endif
#endif
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>

#undef __block
#define __block _xblock
#include <unistd.h>
#undef __block
#define __block __attribute__((__blocks__(byref)))
#pragma clang diagnostic pop

#include <limits.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/file.h>
#include <sys/mman.h>
#include "cwhiteboard.h"

#define WHITEBOARD_MAGIC        0xfeeda11deadbeef5ULL

static gu_simple_whiteboard_descriptor *local_whiteboard_descriptor;

extern gu_simple_whiteboard_descriptor *gsw_new_simple_whiteboard(const char *name, const char *message_names[], int num_messages)
{
    gu_simple_whiteboard_descriptor *wbd = calloc(sizeof(gu_simple_whiteboard_descriptor), 1);
    if (!wbd)
    {
            fprintf(stderr, "Cannot allocate memory for whiteboard '%s': %s\n", name, strerror(errno));
            return NULL;
    }

    bool needs_init = false;
    wbd->wb = gsw_create(name, &wbd->fd, &needs_init);
    if (!wbd->wb)
    {
            gsw_free_whiteboard(wbd);
            return NULL;
    }
    if (needs_init)
    {
        for (int i = 0; i < num_messages; i++)
                gsw_register_message_type(wbd, message_names[i]);
    }
#ifdef WITHOUT_LIBDISPATCH
    wbd->callback_queue = NULL;
#else
    wbd->callback_queue = dispatch_queue_create(NULL, NULL);
#endif
    return wbd;
}

void gsw_free_whiteboard(gu_simple_whiteboard_descriptor *wbd)
{
        if (wbd && wbd != local_whiteboard_descriptor)
        {
                if (wbd->wb) gsw_free(wbd->wb, wbd->fd);
#ifndef WITHOUT_LIBDISPATCH
                if (wbd->callback_queue) dispatch_release(wbd->callback_queue);
#endif
                free(wbd);
        }
}

gu_simple_whiteboard *gsw_create(const char *name, int *fdp, bool *initial)
{
        assert(sizeof(gu_simple_message) == GU_SIMPLE_WHITEBOARD_BUFSIZE);
        char path[PATH_MAX]
#ifdef GSW_IOS_DEVICE
        = "";
#else
        = "/tmp/";
#endif
        if (!name || strlen(name) > PATH_MAX-strlen(path)-1) name = GSW_DEFAULT_NAME;
        strncat(path, name, sizeof(path) - strlen(path) - 1);
        path[sizeof(path)-1]  = '\0';

        int fd = open(path, O_CREAT|O_RDWR, 0666);
        if (fd == -1)
        {
                fprintf(stderr, "Cannot open/create '%s': %s\n", path, strerror(errno));
                return NULL;
        }

        if (ftruncate(fd, sizeof(gu_simple_whiteboard)) == -1)
            fprintf(stderr, "Warning; cannot reserve %lu bytes for '%s': %s\n", (unsigned long) sizeof(gu_simple_whiteboard), path, strerror(errno));

        gu_simple_whiteboard *wb = mmap(NULL, sizeof(*wb), PROT_READ|PROT_WRITE, MAP_FILE|MAP_SHARED, fd, 0);
        if (!wb)
        {
                fprintf(stderr, "Cannot mmap '%s': %s\n", path, strerror(errno));
                close(fd);
                return NULL;
        }
        else if (fdp) *fdp = fd;

        if (wb->magic != WHITEBOARD_MAGIC)      // new whiteboard? -> initialise
        {
                memset(wb, 0, sizeof(*wb));
                wb->version      = GU_SIMPLE_WHITEBOARD_VERSION;
                wb->magic = WHITEBOARD_MAGIC;

                if (initial) *initial = true;

//                DBG(printf("New Whiteboard version %d created and initialised at '%s'\n", wb->version, path));
        }
        else if (initial) *initial = false;

        bool bailout = wb->version != GU_SIMPLE_WHITEBOARD_VERSION;
        if (bailout) fprintf(stderr, "*** Unexpected Whiteboard version %d (expected %d for '%s')\n", wb->version, GU_SIMPLE_WHITEBOARD_VERSION, path);

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
                fprintf(stderr, "Cannot unmap whiteboard at %p with fd %d: %s\n", (void *)wb, fd, strerror(errno));
        if (fd >= 0) if (close(fd) == -1)
                fprintf(stderr, "Cannot close whiteboard at %p with fd %d: %s\n", (void *)wb, fd, strerror(errno));
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
        //bool exists = false;
        gu_simple_whiteboard *wb = wbd->wb;
        unsigned offs = hash_of(name) % GSW_TOTAL_MESSAGE_TYPES;
        gu_simple_message *type = &wb->hashes[offs];

        while (wb->num_types < GSW_TOTAL_MESSAGE_TYPES)
        {
                type = &wb->hashes[offs];
                if (!*type->hash.string)
                {
                        strncpy(type->hash.string, name, sizeof(type->hash.string));
                        type->hash.string[sizeof(type->hash.string)-1] = '\0';
//                        DBG(printf(" - registering wb message type #%d for '%s' at %d\n", wb->num_types, type->hash.string, offs));
                        type->hash.value = wb->num_types++;
                        wb->typenames[type->hash.value] = *type;
                        break;
                }
                if (strcmp(type->hash.string, name) == 0)
                {
                        //exists = true;
                        break;
                }
                /* collision, add to the offset */
//                DBG(printf("Hash collision at offset %u: %u == %u %% %d for:\n'%s' <> '%s'",
//                           offs, hash_of(name), hash_of(type->hash.string), GSW_TOTAL_MESSAGE_TYPES,
//                           name, type->hash.string));
                offs += alt_hash(name);
                offs %= GSW_TOTAL_MESSAGE_TYPES;
        }

        if (wb->num_types < GSW_TOTAL_MESSAGE_TYPES)
                return type->hash.value;

        fprintf(stderr, "Cannot register whiteboard message type '%s': hash table capacity %d reached!\n", name, wb->num_types);

        return -1;
}


int gsw_offset_for_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name)
{
        gu_simple_whiteboard *wb = wbd->wb;
        unsigned offs = hash_of(name) % GSW_TOTAL_MESSAGE_TYPES;
        gu_simple_message *type; // = &wb->hashes[offs];
        for (int i = 0; i < GSW_TOTAL_MESSAGE_TYPES; i++)
        {
                type = &wb->hashes[offs];
                if (!*type->hash.string)                        // new message type?
                        return gsw_register_message_type(wbd, name);
                if (strcmp(type->hash.string, name) == 0)
                        return type->hash.value;
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
        return &wb->messages[i][j];
}


void gsw_increment(gu_simple_whiteboard *wb, int i)
{
        u_int8_t j = wb->indexes[i];
        if (++j >= GU_SIMPLE_WHITEBOARD_GENERATIONS) j = 0;
        wb->indexes[i] = j;
}

void gsw_increment_event_counter(gu_simple_whiteboard *wb, int i)
{
        wb->event_counters[i]++; //unsigned, will wrap if exceeds UINT16_MAX
}
