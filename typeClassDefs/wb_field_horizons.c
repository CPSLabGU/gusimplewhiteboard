/*
 * file wb_field_horizons.c
 *
 * This file was generated by classgenerator from fieldHorizons.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 13:07, 11/05/2018.
 * Copyright © 2018 Carl Lusty. All rights reserved.
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
 *        This product includes software developed by Carl Lusty.
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

#include "wb_field_horizons.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Network byte order functions */
#if defined(__linux)
#  include <endian.h>
#  include <byteswap.h>
#elif defined(__APPLE__) //Needs double checking
#  include <machine/endian.h>
#  include <machine/byte_order.h>
#  define bswap_16(x) NXSwapShort(x)
#  define bswap_32(x) NXSwapInt(x)
#  define bswap_64(x) NXSwapLongLong(x)
#elif defined(ESP8266)
#  define bswap_16(x) __builtin_bswap16(x)
#  define bswap_32(x) __builtin_bswap32(x)
#  define bswap_64(x) __builtin_bswap64(x)
#else
  //Manually define swap macros?
#endif

#if __BYTE_ORDER == __LITTLE_ENDIAN
#  if !defined(htonll) && !defined(ntohll)
#   define htonll(x) bswap_64(x)
#   define ntohll(x) bswap_64(x)
#  endif
#  if !defined(htonl) && !defined(ntohl)
#   define htonl(x) bswap_32(x)
#   define ntohl(x) bswap_32(x)
#  endif
#  if !defined(htons) && !defined(ntohs)
#   define htons(x) bswap_16(x)
#   define ntohs(x) bswap_16(x)
#  endif
#else
#  if !defined(htonll) && !defined(ntohll)
#   define htonll(x) (x)
#   define ntohll(x) (x)
#  endif
#  if !defined(htonl) && !defined(ntohl)
#   define htonl(x) (x)
#   define ntohl(x) (x)
#  endif
#  if !defined(htons) && !defined(ntohs)
#   define htons(x) (x)
#   define ntohs(x) (x)
#  endif
#endif

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

/**
 * Convert to a description string.
 */
const char* wb_field_horizons_description(const struct wb_field_horizons* self, char* descString, size_t bufferSize)
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
    size_t len = 0;
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, "horizons={", bufferSize);
    for (int horizons_index = 0; horizons_index < FIELD_HORIZONS_HORIZONS_ARRAY_SIZE; horizons_index++) {
        if (len >= bufferSize) {
            return descString;
        }
        if (horizons_index > 0) {
            len = gu_strlcat(descString, ", ", bufferSize);
        }
        len = gu_strlcat(descString, "{", bufferSize);
        if (len >= bufferSize) {
            return descString;
        }
        char horizons_1_buffer[FIELDHORIZON_DESC_BUFFER_SIZE];
        char* horizons_1_p = horizons_1_buffer;
        const char* horizons_1_description = wb_field_horizon_description(&self->horizons[horizons_index], horizons_1_p, FIELDHORIZON_DESC_BUFFER_SIZE);
        len = gu_strlcat(descString, horizons_1_p, bufferSize);
        if (len >= bufferSize) {
            return descString;
        }
        len = gu_strlcat(descString, "}", bufferSize);
    }
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, "}", bufferSize);
    return descString;
}

/**
 * Convert to a string.
 */
const char* wb_field_horizons_to_string(const struct wb_field_horizons* self, char* toString, size_t bufferSize)
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
    size_t len = 0;
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, "{", bufferSize);
    for (int horizons_index = 0; horizons_index < FIELD_HORIZONS_HORIZONS_ARRAY_SIZE; horizons_index++) {
        if (len >= bufferSize) {
            return toString;
        }
        if (horizons_index > 0) {
            len = gu_strlcat(toString, ", ", bufferSize);
        }
        len = gu_strlcat(toString, "{", bufferSize);
        if (len >= bufferSize) {
            return toString;
        }
        char horizons_1_buffer[FIELDHORIZON_TO_STRING_BUFFER_SIZE];
        char* horizons_1_p = horizons_1_buffer;
        const char* horizons_1_to_string = wb_field_horizon_to_string(&self->horizons[horizons_index], horizons_1_p, FIELDHORIZON_TO_STRING_BUFFER_SIZE);
        len = gu_strlcat(toString, horizons_1_p, bufferSize);
        if (len >= bufferSize) {
            return toString;
        }
        len = gu_strlcat(toString, "}", bufferSize);
    }
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, "}", bufferSize);
    return toString;
}

/**
 * Convert from a string.
 */
struct wb_field_horizons* wb_field_horizons_from_string(struct wb_field_horizons* self, const char* str)
{
    size_t temp_length = strlen(str);
    int length = (temp_length <= INT_MAX) ? (int)((ssize_t)temp_length) : -1;
    if (length < 1) {
        return self;
    }
    char var_str_buffer[FIELDHORIZONS_TO_STRING_BUFFER_SIZE + 1];
    char* var_str = &var_str_buffer[0];
    int bracecount = 0;
    int lastBrace = -1;
    int startVar = 0;
    int index = 0;
    if (index == 0 && str[0] == '{') {
        index = 1;
    }
    startVar = index;
    for (int i = index; i < length; i++) {
        index = i;
        if (bracecount == 0 && str[index] == '=') {
            startVar = index + 1;
            continue;
        }
        if (bracecount == 0 && isspace(str[index])) {
            startVar = index + 1;
            continue;
        }
        if (bracecount == 0 && str[index] == ',') {
            break;
        }
        if (bracecount == 0 && str[index] == '}') {
            break;
        }
        if (str[index] == '{') {
            bracecount++;
            if (bracecount == 1) {
                lastBrace = index;
            }
            continue;
        }
        if (str[index] == '}') {
            bracecount--;
            if (bracecount < 0) {
                return self;
            }
            if (bracecount != 0) {
                continue;
            }
            break;
        }
    }
    strncpy(var_str, str + startVar, index - startVar);
    var_str[index - startVar] = 0;
    if (bracecount == 0 && str[index] == '}') {
        index++;
    }
    index++;
    bracecount = 0;
    index = lastBrace + 1;
    for (int horizons_0_index = 0; horizons_0_index < FIELDHORIZONS_HORIZONS_ARRAY_SIZE; horizons_0_index++) {
        startVar = index;
        for (int i = index; i < length; i++) {
            index = i;
            if (bracecount == 0 && str[index] == '=') {
                startVar = index + 1;
                continue;
            }
            if (bracecount == 0 && isspace(str[index])) {
                startVar = index + 1;
                continue;
            }
            if (bracecount == 0 && str[index] == ',') {
                break;
            }
            if (bracecount == 0 && str[index] == '}') {
                break;
            }
            if (str[index] == '{') {
                bracecount++;
                if (bracecount == 1) {
                    lastBrace = index;
                }
                continue;
            }
            if (str[index] == '}') {
                bracecount--;
                if (bracecount < 0) {
                    return self;
                }
                if (bracecount != 0) {
                    continue;
                }
                break;
            }
        }
        strncpy(var_str, str + startVar, (index - startVar) + 1);
        var_str[(index - startVar) + 1] = 0;
        if (bracecount == 0 && str[index] == '}') {
            index++;
        }
        index++;
        bracecount = 0;
        struct wb_field_horizon horizons_0;
        wb_field_horizon_from_string(&horizons_0, var_str);
        self->horizons[horizons_0_index] = horizons_0;
    }
    return self;
}

#endif // WHITEBOARD_POSTER_STRING_CONVERSION

/*#ifdef WHITEBOARD_SERIALISATION*/

/**
 * Convert to a compressed, serialised, network byte order byte stream.
 */
size_t wb_field_horizons_to_network_serialised(const struct wb_field_horizons *self, char *dst)
{
    uint16_t bit_offset = 0;
        //Class generator does not support array network compression.
        //Copying into the buffer, uncompressed
        do { //limit declaration scope
          uint32_t len = 2;
          uint32_t bytes = len * sizeof(struct wb_field_horizon);
          char *buf = (char *)&self->horizons[0];
          uint32_t c;
          int8_t b;
          for (c = 0; c < bytes; c++) {
            for (b = 7; b >= 0; b--) {
                do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!((buf[c] >> b) & 1U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);
            }
          }
        } while(false);
    return bit_offset;
}

/**
 * Convert from a compressed, serialised, network byte order byte stream.
 */
size_t wb_field_horizons_from_network_serialised(const char *src, struct wb_field_horizons *dst)
{
    uint16_t bit_offset = 0;
        //Class generator does not support array network compression.
        //Copying into the buffer, uncompressed
        do { //limit declaration scope
          uint32_t len = 2;
          uint32_t bytes = len * sizeof(struct wb_field_horizon);
          char *buf = (char *)malloc(bytes);
          uint32_t c;
          int8_t b;
          for (c = 0; c < bytes; c++) {
            for (b = 7; b >= 0; b--) {
                do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        buf[c] ^= (-bitValue ^ buf[c]) & (1UL << b);
        bit_offset = bit_offset + 1;
      } while(false);
            }
          }
          memcpy(&dst->horizons[0], &buf[0], bytes);
          free(buf);
        } while(false);
    return bit_offset;
}

/*#endif // WHITEBOARD_SERIALISATION*/
