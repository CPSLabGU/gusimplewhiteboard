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
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/sem.h>
#include "gusimplewhiteboard.h"

#define SEMAPHORE_MAGIC_KEY     4242
#define SEM_ERROR               -1

gsw_sema_t gsw_setup_semaphores(void)
{
        int semflg = SEM_R|SEM_A|(SEM_R>>3)|(SEM_A>>3);
        gsw_sema_t s = semget(SEMAPHORE_MAGIC_KEY, GSW_NUM_SEM, semflg);

        if (s == SEM_ERROR)
        {
                s = semget(SEMAPHORE_MAGIC_KEY, GSW_NUM_SEM, semflg | IPC_CREAT);
                if (s == SEM_ERROR) return s;

                union semun init;
                init.val = 1;
                for (enum gsw_semaphores i = 0; i < GSW_NUM_SEM; i++)
                        if (semctl(s, 1, SETVAL, init) == -1)
                                fprintf(stderr, "Warning; failed to initialise whiteboard semaphore %d: %s\n", i, strerror(errno));
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

        wbd->wb = gsw_create(name, &wbd->fd);
        if (!wbd->wb)
        {
                gsw_free_whiteboard(wbd);
                return NULL;
        }
        return wbd;
}

gu_simple_whiteboard *gsw_create(const char *name, int *fdp)
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


gu_simple_message *gsw_current_index_of(gu_simple_whiteboard *wb, int i)
{
        u_int8_t j = wb->indexes[i];
        if (j >= GU_SIMPLE_WHITEBOARD_GENERATIONS) j = 0;
        return &wb->messages[i][j];
}


gu_simple_message *gsw_next_index_of(gu_simple_whiteboard *wb, int i)
{
        u_int8_t j = wb->indexes[i];
        if (++j >= GU_SIMPLE_WHITEBOARD_GENERATIONS) j = 0;
        wb->indexes[i] = j;
        return &wb->messages[i][j];
}

