/*
 * file wb_vision_detection_balls.c
 *
 * This file was generated by classgenerator from vision_detection_balls.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 14:40, 26/07/2018.
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

#include "wb_vision_detection_balls.h"
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
const char* wb_vision_detection_balls_description(const struct wb_vision_detection_balls* self, char* descString, size_t bufferSize)
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
    size_t len = 0;
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "frameNumber=%llu", self->frameNumber);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, "balls={", bufferSize);
    for (int balls_index = 0; balls_index < VISION_DETECTION_BALLS_BALLS_ARRAY_SIZE; balls_index++) {
        if (len >= bufferSize) {
            return descString;
        }
        if (balls_index > 0) {
            len = gu_strlcat(descString, ", ", bufferSize);
        }
        len = gu_strlcat(descString, "{", bufferSize);
        if (len >= bufferSize) {
            return descString;
        }
        char balls_1_buffer[VISION_DETECTION_BALL_DESC_BUFFER_SIZE];
        char* balls_1_p = balls_1_buffer;
        const char* balls_1_description = wb_vision_detection_ball_description(&self->balls[balls_index], balls_1_p, VISION_DETECTION_BALL_DESC_BUFFER_SIZE);
        len = gu_strlcat(descString, balls_1_p, bufferSize);
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
const char* wb_vision_detection_balls_to_string(const struct wb_vision_detection_balls* self, char* toString, size_t bufferSize)
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
    size_t len = 0;
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%llu", self->frameNumber);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, "{", bufferSize);
    for (int balls_index = 0; balls_index < VISION_DETECTION_BALLS_BALLS_ARRAY_SIZE; balls_index++) {
        if (len >= bufferSize) {
            return toString;
        }
        if (balls_index > 0) {
            len = gu_strlcat(toString, ", ", bufferSize);
        }
        len = gu_strlcat(toString, "{", bufferSize);
        if (len >= bufferSize) {
            return toString;
        }
        char balls_1_buffer[VISION_DETECTION_BALL_TO_STRING_BUFFER_SIZE];
        char* balls_1_p = balls_1_buffer;
        const char* balls_1_to_string = wb_vision_detection_ball_to_string(&self->balls[balls_index], balls_1_p, VISION_DETECTION_BALL_TO_STRING_BUFFER_SIZE);
        len = gu_strlcat(toString, balls_1_p, bufferSize);
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
struct wb_vision_detection_balls* wb_vision_detection_balls_from_string(struct wb_vision_detection_balls* self, const char* str)
{
    size_t temp_length = strlen(str);
    int length = (temp_length <= INT_MAX) ? ((int)((ssize_t)temp_length)) : -1;
    if (length < 1) {
        return self;
    }
    char var_str_buffer[VISION_DETECTION_BALLS_TO_STRING_BUFFER_SIZE + 1];
    char* var_str = &var_str_buffer[0];
    char key_buffer[12];
    char* key = &key_buffer[0];
    int bracecount = 0;
    int lastBrace = -1;
    int startVar = 0;
    int index = 0;
    int startKey = 0;
    int endKey = 0;
    int varIndex = 0;
    if (index == 0 && str[0] == '{') {
        index = 1;
    }
    startVar = index;
    startKey = startVar;
    do {
        for (int i = index; i < length; i++) {
            index = i + 1;
            if (bracecount == 0 && str[i] == '=') {
                endKey = i - 1;
                startVar = index;
                continue;
            }
            if (bracecount == 0 && isspace(str[i])) {
                startVar = index;
                if (endKey == -1) {
                    startKey = index;
                }
                continue;
            }
            if (bracecount == 0 && str[i] == ',') {
                index = i - 1;
                break;
            }
            if (str[i] == '{') {
                bracecount++;
                if (bracecount == 1) {
                    lastBrace = i;
                }
                continue;
            }
            if (str[i] == '}') {
                bracecount--;
                if (bracecount < 0) {
                    index = i - 1;
                    break;
                }
            }
            if (i == length - 1) {
                index = i;
            }
        }
        if (endKey >= startKey && endKey - startKey < length) {
            strncpy(key, str + startKey, (endKey - startKey) + 1);
            key[(endKey - startKey) + 1] = 0;
        } else {
            key[0] = 0;
        }
        strncpy(var_str, str + startVar, (index - startVar) + 1);
        var_str[(index - startVar) + 1] = 0;
        bracecount = 0;
        index += 2;
        startVar = index;
        startKey = startVar;
        endKey = -1;
        if (key != NULLPTR) {
            if (0 == strcmp("frameNumber", key)) {
                varIndex = 0;
            } else if (0 == strcmp("balls", key)) {
                varIndex = 1;
            }
        }
        switch (varIndex) {
            case 0:
            {
                self->frameNumber = ((uint64_t)atoll(var_str));
                break;
            }
            case 1:
            {
                int restartIndex = index;
                index = lastBrace + 1;
                startVar = index;
                startKey = startVar;
                endKey = -1;
                bracecount = 0;
                for (int balls_0_index = 0; balls_0_index < VISION_DETECTION_BALLS_BALLS_ARRAY_SIZE; balls_0_index++) {
                    for (int i = index; i < length; i++) {
                        index = i + 1;
                        if (bracecount == 0 && str[i] == '=') {
                            endKey = i - 1;
                            startVar = index;
                            continue;
                        }
                        if (bracecount == 0 && isspace(str[i])) {
                            startVar = index;
                            if (endKey == -1) {
                                startKey = index;
                            }
                            continue;
                        }
                        if (bracecount == 0 && str[i] == ',') {
                            index = i - 1;
                            break;
                        }
                        if (str[i] == '{') {
                            bracecount++;
                            if (bracecount == 1) {
                                lastBrace = i;
                            }
                            continue;
                        }
                        if (str[i] == '}') {
                            bracecount--;
                            if (bracecount < 0) {
                                index = i - 1;
                                break;
                            }
                        }
                        if (i == length - 1) {
                            index = i;
                        }
                    }
                    if (endKey >= startKey && endKey - startKey < length) {
                        strncpy(key, str + startKey, (endKey - startKey) + 1);
                        key[(endKey - startKey) + 1] = 0;
                    } else {
                        key[0] = 0;
                    }
                    strncpy(var_str, str + startVar, (index - startVar) + 1);
                    var_str[(index - startVar) + 1] = 0;
                    bracecount = 0;
                    index += 2;
                    startVar = index;
                    startKey = startVar;
                    endKey = -1;
                    struct wb_vision_detection_ball balls_0;
                    wb_vision_detection_ball_from_string(&balls_0, var_str);
                    self->balls[balls_0_index] = balls_0;;
                }
                index = restartIndex;
                break;
            }
        }
        varIndex++;
    } while(index < length);
    return self;
}

#endif // WHITEBOARD_POSTER_STRING_CONVERSION

/*#ifdef WHITEBOARD_SERIALISATION*/

/**
 * Convert to a compressed, serialised, network byte order byte stream.
 */
size_t wb_vision_detection_balls_to_network_serialised(const struct wb_vision_detection_balls *self, char *dst)
{
    uint16_t bit_offset = 0;
    uint64_t frameNumber_nbo = htonll(self->frameNumber);
    do {
      int8_t b;
      for (b = (64 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!((frameNumber_nbo >> b) & 1U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);

        //Class generator does not support array network compression.
        //Copying into the buffer, uncompressed
        do { //limit declaration scope
          uint32_t len = 2;
          uint32_t bytes = len * sizeof(struct wb_vision_detection_ball);
          char *buf = (char *)&self->balls[0];
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
size_t wb_vision_detection_balls_from_network_serialised(const char *src, struct wb_vision_detection_balls *dst)
{
    uint16_t bit_offset = 0;
    do {
      int8_t b;
      for (b = (64 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->frameNumber ^= (-bitValue ^ dst->frameNumber) & (1UL << b);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);
    dst->frameNumber = ntohll(dst->frameNumber);

        //Class generator does not support array network compression.
        //Copying into the buffer, uncompressed
        do { //limit declaration scope
          uint32_t len = 2;
          uint32_t bytes = len * sizeof(struct wb_vision_detection_ball);
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
          memcpy(&dst->balls[0], &buf[0], bytes);
          free(buf);
        } while(false);
    return bit_offset;
}

/*#endif // WHITEBOARD_SERIALISATION*/
