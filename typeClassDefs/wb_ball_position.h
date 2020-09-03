/*
 * file wb_ball_position.h
 *
 * This file was generated by classgenerator from ball_position.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2020 Callum McColl. All rights reserved.
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
 *        This product includes software developed by Callum McColl.
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

#ifndef wb_ball_position_h
#define wb_ball_position_h

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"

#ifdef __linux
# ifndef _POSIX_SOURCE
#  define _POSIX_SOURCE 200112L
# endif
#endif
#ifndef _XOPEN_SOURCE
# define _XOPEN_SOURCE 700
#endif
#ifdef __APPLE__
# ifndef _DARWIN_C_SOURCE
#  define _DARWIN_C_SOURCE 200112L
# endif
# ifndef __DARWIN_C_LEVEL
#  define __DARWIN_C_LEVEL 200112L
# endif
#endif

#pragma clang diagnostic pop

#include <gu_util.h>
#include <stdint.h>

#define BALL_POSITION_GENERATED 
#define BALL_POSITION_C_STRUCT wb_ball_position 
#define BALL_POSITION_NUMBER_OF_VARIABLES 6

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#define BALL_POSITION_DESC_BUFFER_SIZE 101
#define BALL_POSITION_TO_STRING_BUFFER_SIZE 44
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

/**
 * A type providing position and orientation of the ball on the soccer field.
 */
struct wb_ball_position
{

    /**
     * The x coordinate
     */
    PROPERTY(int16_t, x)

    /**
     * The y coordinate.
     */
    PROPERTY(int16_t, y)

    /**
     * The pitch orientation.
     */
    PROPERTY(int16_t, pitchInDegrees)

    /**
     * The yaw orientation.
     */
    PROPERTY(int16_t, yawInDegrees)

    /**
     * The roll orientation.
     */
    PROPERTY(int16_t, rollInDegrees)

    /**
     * The confidence that the ball is at this position. This value represents a percentage value where the 0 percent is equal to 0 and 100 percent is equal to 255.
     */
    PROPERTY(uint8_t, confidence)

};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

/**
 * Convert to a description string.
 */
const char* wb_ball_position_description(const struct wb_ball_position* self, char* descString, size_t bufferSize);

/**
 * Convert to a string.
 */
const char* wb_ball_position_to_string(const struct wb_ball_position* self, char* toString, size_t bufferSize);

/**
 * Convert from a string.
 */
struct wb_ball_position* wb_ball_position_from_string(struct wb_ball_position* self, const char* str);

#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

/**
 *  \brief Converts wb_ball_position.confidence to its corresponding floating point
 *  percentage representation.
 *
 *  \param[in] strct The wb_ball_position containing the confidence property
 *  being converted.
 *
 *  \returns A double representing wb_ball_position.confidence as a percentage
 *  where 0 represents 0.0 and 255 represents 1.0.
 */
double wb_ball_position_confidence_percent(const struct wb_ball_position strct) __attribute__((const));

/**
 *  \brief Converts and stores a percentage floating point value in
 *  wb_ball_position.confidence.
 *
 *  \param[in,out] strct A pointer to awb_ball_position containing the confidence
 *  property which will be set.
 *
 *  \param[in] newValue The floating point percentage value which will be
 *  converted to the integer representations such that 0.0 equals 0 and
 *  1.0 equals 255.
 */
void wb_ball_position_set_confidence_percent(struct wb_ball_position *strct, const double newValue) __attribute__((nonnull));

/*#ifdef WHITEBOARD_SERIALISATION*/

/**
 * Network stream serialisation
 */
size_t wb_ball_position_to_network_serialised(const struct wb_ball_position *self, char *dst);

/**
 * Network stream deserialisation
 */
size_t wb_ball_position_from_network_serialised(const char *src, struct wb_ball_position *dst);

/*#endif /// WHITEBOARD_SERIALISATION*/

#ifdef __cplusplus
}
#endif

#endif /// wb_ball_position_h
