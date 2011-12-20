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
#ifndef gusimplewhiteboard_gusimplewhiteboard_h
#define gusimplewhiteboard_gusimplewhiteboard_h

#include <sys/types.h>

#define GU_SIMPLE_WHITEBOARD_VERSION            1       // version
#define GU_SIMPLE_WHITEBOARD_GENERATIONS        4       // lifespan (max)
#define GU_SIMPLE_WHITEBOARD_BUFSIZE            64      // message len (max)
#define GSW_TOTAL_MESSAGE_TYPES                 1024    // message types (max)
#define GSW_NON_RESERVED_MESSAGE_TYPES  (GSW_TOTAL_MESSAGE_TYPES-GSW_NUM_RESERVED)

#define GSW_DEFAULT_NAME "simple_whiteboard"

enum gsw_message_types
{
        GSW_PRINT,                      // print to stdout
        GSW_SAY,                        // text to speech
        GSW_SPEECH,                     // debug speech message
        GSW_NUM_RESERVED
};

typedef union gsw_simple_message
{
        /*
         * standard types
         */
        unsigned long long      ulonglong;      /// unsigned long long value
        long long               slonglong;      /// long long value
        unsigned long           ulong;          /// unsigned long value
        long                    slong;          /// singed long value
        unsigned                uint;           /// unsigned integer
        int                     sint;           /// signed integer
        unsigned short          ushort;         /// unsigned short
        short                   sshort;         /// signed short
        unsigned char           uchar;          /// unsigned char
        signed char             schar;          /// signed char
        char                    xchar;          /// standard char

        long double             slongdouble;    /// long double
        double                  sdouble;        /// signed double
        float                   sfloat;         /// signed float

        /*
         * POSIX defined length types
         */
        u_int64_t               u64;            /// unsigned 64 bit value
        u_int32_t               u32;            /// unsigned 32 bit value
        u_int16_t               u16;            /// unsigned 16 bit value
        u_int8_t                u8;             /// unsigned  8 bit value
        
        int64_t                 s64;            /// signed 64 bit value
        int32_t                 s32;            /// signed 32 bit value
        int16_t                 s16;            /// signed 16 bit value
        int8_t                  s8;             /// signed  8 bit value

        /**
         * vector types
         */
        unsigned long long      ullvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned long long)];
        unsigned long           ulvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned long)];
        unsigned                uivec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned)];
        unsigned short          usvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned short)];
        unsigned char           ucvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned char)];

        long long               llvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(long long)];
        long                    lvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(long)];
        int                     ivec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(int)];
        short                   svec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(short)];
        signed char             cvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(signed char)];

        u_int64_t               u64vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(u_int64_t)];
        u_int32_t               u32vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(u_int32_t)];
        u_int16_t               u16vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(u_int16_t)];
        u_int8_t                u8vec[GU_SIMPLE_WHITEBOARD_BUFSIZE];

        int64_t                 s64vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(u_int64_t)];
        int32_t                 s32vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(u_int32_t)];
        int16_t                 s16vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(u_int16_t)];
        int8_t                  s8vec[GU_SIMPLE_WHITEBOARD_BUFSIZE];

        /*
         * simple compound types
         */
        struct { int x,y,z,a,b,c,d,e; } coord;  /// simple integer coordinates
        struct {double x,y,z,a,b,c,d,e;} dcoord;/// simple double coordinates
        struct {float x,y,z,a,b,c,d,e;} fcoord; /// simple float coordinates

        /** string type */
        char                    string[GU_SIMPLE_WHITEBOARD_BUFSIZE];

        /** whiteboard hash type */
        struct { u_int16_t value; char string[GU_SIMPLE_WHITEBOARD_BUFSIZE-sizeof(u_int16_t)]; } hash;
} gu_simple_message;

typedef struct gsw_simple_whiteboard_s
{
        u_int16_t               version;        /// whiteboard version
        u_int16_t               num_reserved;   /// number of reserved message types
        u_int16_t               max_lifespan;   /// number of generations
        u_int16_t               num_types;      /// total number of current, registered types

        u_int8_t                indexes[GSW_TOTAL_MESSAGE_TYPES];       /// ring buffer indexes

        /**
         * the actual messages stored in the whiteboard
         */
        gu_simple_message       messages[GSW_TOTAL_MESSAGE_TYPES][GU_SIMPLE_WHITEBOARD_GENERATIONS];

        /**
         * hashes for registered message types
         */
        gu_simple_message       hashes[GSW_TOTAL_MESSAGE_TYPES];
} gu_simple_whiteboard;

/**
 * create a simple whiteboard
 * @param name  name of the whiteboard
 * @param fdp   pointer to internal file descriptor storage (NULL if not needed)
 */
extern gu_simple_whiteboard *gsw_create(const char *name, int *fdp);

/**
 * free the whiteboard
 * @param wb    whiteboard to free
 * @param fd    file descriptor to close (-1 to skip)
 */
extern void gsw_free(gu_simple_whiteboard *wb, int fd);

/**
 * get the current shared memory location for the given whiteboard message type i
 */
gu_simple_message *gsw_current_index_of(gu_simple_whiteboard *wb, int i);

/**
 * get the next shared memory location for the given whiteboard message type i
 */
gu_simple_message *gsw_next_index_of(gu_simple_whiteboard *wb, int i);

#endif
