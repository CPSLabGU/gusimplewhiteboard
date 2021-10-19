/*
 *  gusimplewhiteboard.h
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
#ifndef c_whiteboard_h
#define c_whiteboard_h

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wdeprecated"
#pragma clang diagnostic ignored "-Wold-style-cast"

#ifdef __APPLE__
# ifndef TARGET_OS_IPHONE
#  include <AvailabilityMacros.h>
# endif
#endif
#ifndef WITHOUT_LIBDISPATCH
#include <dispatch/dispatch.h>
#endif
#include <sys/types.h>

#ifndef __cplusplus
#include <stdbool.h>
#include <stdint.h>
#else
#if __cplusplus < 201103L
#include <stdbool.h>
#else
#include <cstdbool>
#include <cstdint>
#endif

#ifndef DBG
#define DBG(x)
#endif

extern "C"
{
#endif // __cplusplus
#undef __block
#define __block _xblock
#include <unistd.h>
#undef __block
#define __block __attribute__((__blocks__(byref)))

#ifndef __has_feature           // Optional of course.
#define __has_feature(x) 0      // Compatibility with non-clang compilers.
#endif

#ifdef __cplusplus

#pragma clang diagnostic ignored "-Wc++11-long-long"

#ifdef bool
#undef bool
#endif

#ifdef true
#undef true
#undef false
#endif
#endif // __cplusplus

#if defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR
#define GSW_IOS_SIMULATOR                               ///< IOS device (but not simulator)
#endif

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE && !defined (GSW_IOS_SIMULATOR)
#define GSW_IOS_DEVICE                                  ///< IOS device (but not simulator)
#endif

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE || defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR
#define GSW_IOS                                         ///< IOS device or simulator
#endif

#define GU_SIMPLE_WHITEBOARD_VERSION            6       ///< version
#ifndef GU_SIMPLE_WHITEBOARD_GENERATIONS
#define GU_SIMPLE_WHITEBOARD_GENERATIONS        4       ///< lifespan (max)
#endif
#ifndef GU_SIMPLE_WHITEBOARD_BUFSIZE
#define GU_SIMPLE_WHITEBOARD_BUFSIZE            128     ///< message len (max)
#endif
#ifndef GSW_TOTAL_MESSAGE_TYPES
#define GSW_TOTAL_MESSAGE_TYPES                 512     ///< message types (max)
#endif
#ifndef GSW_NUM_RESERVED
#define GSW_NUM_RESERVED                        (GSW_TOTAL_MESSAGE_TYPES/2)    // message types (max)
#endif
#define GSW_TOTAL_PROCESSES                     256     ///< maximum subscriber procs
#define GSW_NON_RESERVED_MESSAGE_TYPES  (GSW_TOTAL_MESSAGE_TYPES-GSW_NUM_RESERVED)

/// environment variable containing the default whiteboard file name
#ifndef GSW_DEFAULT_ENV
#define GSW_DEFAULT_ENV     "WHITEBOARD_NAME"
#endif
#ifndef GSW_DEFAULT_NAME
#define GSW_DEFAULT_NAME    "guWhiteboard"              ///< fallback default wb
#endif
#ifndef GSWR_BASE_NAME
#define GSWR_BASE_NAME      "guudpwhiteboard"           ///< UDP whiteboard name
#endif
#ifndef WHITEBOARD_SIGNAL
#define WHITEBOARD_SIGNAL       SIGUSR2
#endif
#ifndef WHITEBOARD_POLL_PERIOD
#define WHITEBOARD_POLL_PERIOD  10000
#endif

struct gsw_whiteboard_s;

typedef void (*gsw_subscription_f)(struct gsw_whiteboard_s *wbd);

/** union type that is used to store data in shared memory */
typedef union gsw_simple_message
{
        /*
         * standard types
         */
        unsigned long long      ulonglong;      ///< unsigned long long value
        long long               slonglong;      ///< long long value
        unsigned long           ulong;          ///< unsigned long value
        long                    slong;          ///< singed long value
        unsigned                uint;           ///< unsigned integer
        int                     sint;           ///< signed integer
        unsigned short          ushort;         ///< unsigned short
        short                   sshort;         ///< signed short
        unsigned char           uchar;          ///< unsigned char
        signed char             schar;          ///< signed char
        char                    xchar;          ///< standard char

        long double             slongdouble;    ///< long double
        double                  sdouble;        ///< signed double
        float                   sfloat;         ///< signed float

        /*
         * POSIX defined length types
         */
        uint64_t               u64;            ///< unsigned 64 bit value
        uint32_t               u32;            ///< unsigned 32 bit value
        uint16_t               u16;            ///< unsigned 16 bit value
        uint8_t                u8;             ///< unsigned  8 bit value
        
        int64_t                 s64;            ///< signed 64 bit value
        int32_t                 s32;            ///< signed 32 bit value
        int16_t                 s16;            ///< signed 16 bit value
        int8_t                  s8;             ///< signed  8 bit value

        /**
         * vector types
         */
        unsigned long long      ullvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned long long)];///< unsigned long long array
        unsigned long           ulvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned long)];	///< unsigned long array
        unsigned                uivec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned)];		///< unsigned array
        unsigned short          usvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned short)];	///< unsigned short array
        unsigned char           ucvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(unsigned char)];	///< unsigned char array
 
        long long               llvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(long long)];	///< long long array
        long                    lvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(long)];	///< long array
        int                     ivec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(int)];		///< int array
        short                   svec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(short)];	///< short array
        signed char             cvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(signed char)];	///< signed char array
        bool                    bvec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(bool)];	///< bool array
 
        uint64_t               u64vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(uint64_t)];	///< uint64_t array
        uint32_t               u32vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(uint32_t)];	///< uint32_t array
        uint16_t               u16vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(uint16_t)];	///< uint16_t array
        uint8_t                u8vec[GU_SIMPLE_WHITEBOARD_BUFSIZE];			///< uint8_t array
 
        int64_t                 s64vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(int64_t)];	///< int64_t array
        int32_t                 s32vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(int32_t)];	///< int32_t array
        int16_t                 s16vec[GU_SIMPLE_WHITEBOARD_BUFSIZE/sizeof(int16_t)];	///< int16_t array
        int8_t                  s8vec[GU_SIMPLE_WHITEBOARD_BUFSIZE];			///< int8_t array

        /*
         * simple compound types
         */
        struct {int16_t x,y,z,a,b,c,d,e; } coord;  ///< simple 16 bit integer coordinates
        struct {double x,y,z,a,b,c,d,e;} dcoord;///< simple double coordinates
        struct {float x,y,z,a,b,c,d,e;} fcoord; ///< simple float coordinates

        /** string type */
        char                    string[GU_SIMPLE_WHITEBOARD_BUFSIZE];

        /** whiteboard hash type */
        struct { uint16_t value; char string[GU_SIMPLE_WHITEBOARD_BUFSIZE-sizeof(uint16_t)]; } hash;

        /** compatibility WBMsg type */
        struct { char data[GU_SIMPLE_WHITEBOARD_BUFSIZE-2]; unsigned char len; unsigned char type; } wbmsg;
} gu_simple_message;

/** the actual whiteboard in shared mem */
typedef struct gsw_simple_whiteboard_s
{
        uint16_t               version;        ///< whiteboard version
        uint16_t               eventcount;     ///< current event count
        uint16_t               subscribed;     ///< subscribed processes
        uint16_t               num_types;      ///< total number of current, registered types

        uint8_t                indexes[GSW_TOTAL_MESSAGE_TYPES];       ///< ring buffer indexes
        uint16_t               event_counters[GSW_TOTAL_MESSAGE_TYPES];       ///< event counter loops

        /**
         * the actual messages stored in the whiteboard
         */
        gu_simple_message       messages[GSW_TOTAL_MESSAGE_TYPES][GU_SIMPLE_WHITEBOARD_GENERATIONS];

        /**
         * hashes for registered message types
         */
        gu_simple_message       hashes[GSW_TOTAL_MESSAGE_TYPES];

        /**
         * message types for numbers
         */
        gu_simple_message       typenames[GSW_TOTAL_MESSAGE_TYPES];

        /**
         * list of subscribed processes
         */
        pid_t                   processes[GSW_TOTAL_PROCESSES];

        /**
         * end of whiteboard marker
         */
        uint64_t               magic;
} gu_simple_whiteboard;

/** the underlying whiteboard object */
typedef struct gsw_whiteboard_s
{
        gu_simple_whiteboard    *wb;            ///< the actual whiteboard in shared mem
        const char             **message_names; ///< human-readable name for whiteboard messages
        int                      num_messages;  ///< number of named messages registered
        int                      fd;            ///< the associated memory-mapped file
#if __has_feature(objc_arc) || defined(WITHOUT_LIBDISPATCH)
        void                    *callback_queue;///< subscription callback queue
#else
        dispatch_queue_t         callback_queue;///< subscription callback queue
#endif
        gsw_subscription_f       callback;      ///< subscription callback function
        void                    *context;       ///< callback context
        bool                     got_monitor;   ///< have a running monitor
        bool                     exit_monitor;  ///< exit the monitor
} gu_simple_whiteboard_descriptor;

/**
 * global whiteboard name
 */
extern const char *gsw_global_whiteboard_name;

///
/// Designated whiteboard constructor.
/// If the whtibeboard witht the given name does not exist, it will be created.
/// @param name The name of the whiteboard to create/access
/// @param message_names Array of `char *` containing the pre-defined (static) message names
/// @param num_messages Number of messages in the `message_names` array
/// @param semaphore_magic_key Semaphore magic key to use
///
extern gu_simple_whiteboard_descriptor *gsw_new_simple_whiteboard(const char *name, const char *message_names[], int num_messages);

/**
 * free the given whiteboard descriptor
 * @param wbd  descriptor for the whiteboard
 */
extern void gsw_free_whiteboard(gu_simple_whiteboard_descriptor *wbd);

/**
 * register a new whiteboard message type
 * @param wbd  descriptor for the whiteboard
 * @param name  string to use for identification
 * @return numerical identifier to use
 */
extern int gsw_register_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name);

/**
 * get the numerical index of a whiteboard message type
 * @param wbd  descriptor for the whiteboard
 * @param name  string to use for identification
 * @return numerical identifier to use
 */
extern int gsw_offset_for_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name);

/**
 * create a simple whiteboard
 * @param name  name of the whiteboard
 * @param fdp   pointer to internal file descriptor storage (NULL if not needed)
 * @param ini   pointer to boolean recording wb initialisation
 */
extern gu_simple_whiteboard *gsw_create(const char *name, int *fdp, bool *ini);
	
/**
 * free the whiteboard
 * @param wb    whiteboard to free
 * @param fd    file descriptor to close (-1 to skip)
 */
extern void gsw_free(gu_simple_whiteboard *wb, int fd);

/**
 * get the current shared memory location for the given whiteboard message type i
 */
gu_simple_message *gsw_current_message(gu_simple_whiteboard *wb, int i);

/**
 * get the next shared memory location for the given whiteboard message type i
 */
gu_simple_message *gsw_next_message(gu_simple_whiteboard *wb, int i);

/**
 * get the next shared memory location for the given whiteboard message type i
 */
void gsw_increment(gu_simple_whiteboard *wb, int i);

/**
* add to a messages event counter on the wb
*/
void gsw_increment_event_counter(gu_simple_whiteboard *wb, int i);

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop

#endif // c_whiteboard_h
