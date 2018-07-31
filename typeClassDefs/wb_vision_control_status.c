/*
 * file wb_vision_control_status.c
 *
 * This file was generated by classgenerator from vision_control_status.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Eugene Gilmore at 11:58, 27/07/2018.
 * Copyright © 2018 Eugene Gilmore. All rights reserved.
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
 *        This product includes software developed by Eugene Gilmore.
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

#include "wb_vision_control_status.h"
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
const char* wb_vision_control_status_description(const struct wb_vision_control_status* self, char* descString, size_t bufferSize)
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
    size_t len = 0;
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "cameraResolution=%d", self->cameraResolution);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, self->pipelineRunning ? "pipelineRunning=true" : "pipelineRunning=false", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "selectedCamera=%d", self->selectedCamera);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "saveImage=%d", self->saveImage);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, self->saveClassifiedImage ? "saveClassifiedImage=true" : "saveClassifiedImage=false", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "pipeline=%d", self->pipeline);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "chooseCamera=%d", self->chooseCamera);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "networkTop=%d", self->networkTop);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "networkBottom=%d", self->networkBottom);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "streamingSource=%d", self->streamingSource);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, self->imageInput ? "imageInput=true" : "imageInput=false", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "jpegStreamQuality=%d", self->jpegStreamQuality);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "jpegStreamStride=%d", self->jpegStreamStride);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len += snprintf(descString + len, bufferSize - len, "frameRate=%d", self->frameRate);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, self->runPipelineOnce ? "runPipelineOnce=true" : "runPipelineOnce=false", bufferSize);
    if (len >= bufferSize) {
        return descString;
    }
    len = gu_strlcat(descString, ", ", bufferSize);
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
    len += snprintf(descString + len, bufferSize - len, "colourCalibration=%s", self->colourCalibration);
    return descString;
}

/**
 * Convert to a string.
 */
const char* wb_vision_control_status_to_string(const struct wb_vision_control_status* self, char* toString, size_t bufferSize)
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
    size_t len = 0;
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->cameraResolution);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, self->pipelineRunning ? "true" : "false", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->selectedCamera);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->saveImage);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, self->saveClassifiedImage ? "true" : "false", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->pipeline);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->chooseCamera);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->networkTop);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->networkBottom);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->streamingSource);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, self->imageInput ? "true" : "false", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->jpegStreamQuality);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->jpegStreamStride);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len += snprintf(toString + len, bufferSize - len, "%d", self->frameRate);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, self->runPipelineOnce ? "true" : "false", bufferSize);
    if (len >= bufferSize) {
        return toString;
    }
    len = gu_strlcat(toString, ", ", bufferSize);
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
    len += snprintf(toString + len, bufferSize - len, "%s", self->colourCalibration);
    return toString;
}

/**
 * Convert from a string.
 */
struct wb_vision_control_status* wb_vision_control_status_from_string(struct wb_vision_control_status* self, const char* str)
{
    size_t temp_length = strlen(str);
    int length = (temp_length <= INT_MAX) ? ((int)((ssize_t)temp_length)) : -1;
    if (length < 1) {
        return self;
    }
    char var_str_buffer[VISION_CONTROL_STATUS_TO_STRING_BUFFER_SIZE + 1];
    char* var_str = &var_str_buffer[0];
    char key_buffer[20];
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
            if (0 == strcmp("cameraResolution", key)) {
                varIndex = 0;
            } else if (0 == strcmp("pipelineRunning", key)) {
                varIndex = 1;
            } else if (0 == strcmp("selectedCamera", key)) {
                varIndex = 2;
            } else if (0 == strcmp("saveImage", key)) {
                varIndex = 3;
            } else if (0 == strcmp("saveClassifiedImage", key)) {
                varIndex = 4;
            } else if (0 == strcmp("pipeline", key)) {
                varIndex = 5;
            } else if (0 == strcmp("chooseCamera", key)) {
                varIndex = 6;
            } else if (0 == strcmp("networkTop", key)) {
                varIndex = 7;
            } else if (0 == strcmp("networkBottom", key)) {
                varIndex = 8;
            } else if (0 == strcmp("streamingSource", key)) {
                varIndex = 9;
            } else if (0 == strcmp("imageInput", key)) {
                varIndex = 10;
            } else if (0 == strcmp("jpegStreamQuality", key)) {
                varIndex = 11;
            } else if (0 == strcmp("jpegStreamStride", key)) {
                varIndex = 12;
            } else if (0 == strcmp("frameRate", key)) {
                varIndex = 13;
            } else if (0 == strcmp("runPipelineOnce", key)) {
                varIndex = 14;
            } else if (0 == strcmp("frameNumber", key)) {
                varIndex = 15;
            } else if (0 == strcmp("colourCalibration", key)) {
                varIndex = 16;
            }
        }
        switch (varIndex) {
            case 0:
            {
                self->cameraResolution = ((enum Resolutions)atoi(var_str));
                break;
            }
            case 1:
            {
                self->pipelineRunning = strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0;
                break;
            }
            case 2:
            {
                self->selectedCamera = ((enum VisionCamera)atoi(var_str));
                break;
            }
            case 3:
            {
                self->saveImage = ((enum SaveFileType)atoi(var_str));
                break;
            }
            case 4:
            {
                self->saveClassifiedImage = strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0;
                break;
            }
            case 5:
            {
                self->pipeline = ((enum NamedPipeline)atoi(var_str));
                break;
            }
            case 6:
            {
                self->chooseCamera = ((int)atoi(var_str));
                break;
            }
            case 7:
            {
                self->networkTop = ((enum NeuralNetworkType)atoi(var_str));
                break;
            }
            case 8:
            {
                self->networkBottom = ((enum NeuralNetworkType)atoi(var_str));
                break;
            }
            case 9:
            {
                self->streamingSource = ((enum StreamingType)atoi(var_str));
                break;
            }
            case 10:
            {
                self->imageInput = strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0;
                break;
            }
            case 11:
            {
                self->jpegStreamQuality = ((int)atoi(var_str));
                break;
            }
            case 12:
            {
                self->jpegStreamStride = ((int)atoi(var_str));
                break;
            }
            case 13:
            {
                self->frameRate = ((int)atoi(var_str));
                break;
            }
            case 14:
            {
                self->runPipelineOnce = strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0;
                break;
            }
            case 15:
            {
                self->frameNumber = ((uint64_t)atoll(var_str));
                break;
            }
            case 16:
            {
                strncpy(self->colourCalibration, var_str, 10);
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
size_t wb_vision_control_status_to_network_serialised(const struct wb_vision_control_status *self, char *dst)
{
    uint16_t bit_offset = 0;
      do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!(self->pipelineRunning ? 1U : 0U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);

      do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!(self->saveClassifiedImage ? 1U : 0U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);

    int chooseCamera_nbo = htonl(self->chooseCamera);
    do {
      int8_t b;
      for (b = (32 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!((chooseCamera_nbo >> b) & 1U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);

      do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!(self->imageInput ? 1U : 0U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);

    int jpegStreamQuality_nbo = htonl(self->jpegStreamQuality);
    do {
      int8_t b;
      for (b = (32 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!((jpegStreamQuality_nbo >> b) & 1U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);

    int jpegStreamStride_nbo = htonl(self->jpegStreamStride);
    do {
      int8_t b;
      for (b = (32 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!((jpegStreamStride_nbo >> b) & 1U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);

    int frameRate_nbo = htonl(self->frameRate);
    do {
      int8_t b;
      for (b = (32 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!((frameRate_nbo >> b) & 1U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);

      do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!(self->runPipelineOnce ? 1U : 0U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);

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

    do { //limit declaration scope
      uint8_t len = strlen(self->colourCalibration);
      int8_t b;
      for (b = 7; b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!((len >> b) & 1U);
        dst[byte] ^= (-newbit ^ dst[byte]) & (1UL << bit);
        bit_offset = bit_offset + 1;
      } while(false);
      }
      uint8_t c;
      for (c = 0; c < len; c++) {
        for (b = 7; b >= 0; b--) {
            do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        unsigned long newbit = !!((self->colourCalibration[c] >> b) & 1U);
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
size_t wb_vision_control_status_from_network_serialised(const char *src, struct wb_vision_control_status *dst)
{
    uint16_t bit_offset = 0;
      do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->pipelineRunning = bitValue != 0;
        bit_offset = bit_offset + 1;
      } while(false);

      do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->saveClassifiedImage = bitValue != 0;
        bit_offset = bit_offset + 1;
      } while(false);

    do {
      int8_t b;
      for (b = (32 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->chooseCamera ^= (-bitValue ^ dst->chooseCamera) & (1UL << b);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);
    dst->chooseCamera = ntohl(dst->chooseCamera);

      do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->imageInput = bitValue != 0;
        bit_offset = bit_offset + 1;
      } while(false);

    do {
      int8_t b;
      for (b = (32 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->jpegStreamQuality ^= (-bitValue ^ dst->jpegStreamQuality) & (1UL << b);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);
    dst->jpegStreamQuality = ntohl(dst->jpegStreamQuality);

    do {
      int8_t b;
      for (b = (32 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->jpegStreamStride ^= (-bitValue ^ dst->jpegStreamStride) & (1UL << b);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);
    dst->jpegStreamStride = ntohl(dst->jpegStreamStride);

    do {
      int8_t b;
      for (b = (32 - 1); b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->frameRate ^= (-bitValue ^ dst->frameRate) & (1UL << b);
        bit_offset = bit_offset + 1;
      } while(false);
      }
    } while(false);
    dst->frameRate = ntohl(dst->frameRate);

      do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->runPipelineOnce = bitValue != 0;
        bit_offset = bit_offset + 1;
      } while(false);

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

    do {
      uint8_t len = 0;
      int8_t b;
      for (b = 7; b >= 0; b--) {
          do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        len ^= (-bitValue ^ len) & (1UL << b);
        bit_offset = bit_offset + 1;
      } while(false);
      }
      uint8_t c;
      for (c = 0; c < len; c++) {
        for (b = 7; b >= 0; b--) {
            do {
        uint16_t byte = bit_offset / 8;
        uint16_t bit = 7 - (bit_offset % 8);
        char dataByte = src[byte];
        unsigned char bitValue = (dataByte >> bit) & 1U;
        dst->colourCalibration[c] ^= (-bitValue ^ dst->colourCalibration[c]) & (1UL << b);
        bit_offset = bit_offset + 1;
      } while(false);
        }
      }
    } while (false);
    return bit_offset;
}

/*#endif // WHITEBOARD_SERIALISATION*/
