/*
 * file wb_nao_walk_command.h
 *
 * This file was generated by classgenerator from naoWalkCommand.gen.
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

#ifndef wb_nao_walk_command_h
#define wb_nao_walk_command_h

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

#include <gu_util.h>
#include <stdint.h>

#define NAOWALKCOMMAND_GENERATED 
#define NAOWALKCOMMAND_C_STRUCT wb_nao_walk_command 
#define NAOWALKCOMMAND_NUMBER_OF_VARIABLES 14

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#define NAOWALKCOMMAND_DESC_BUFFER_SIZE 239
#define NAOWALKCOMMAND_TO_STRING_BUFFER_SIZE 90
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

/**
 * Control message for sending commands to the walk engine created by UNSW.
 * LICENSE:
 * https://github.com/UNSWComputing/rUNSWift-2017-release/blob/master/LICENSE
 * Source:
 * https://github.com/UNSWComputing/rUNSWift-2017-release/blob/master/robot/motion/generator/Walk2014Generator.cpp
 * Some of their documentation:
 * https://github.com/UNSWComputing/rUNSWift-2017-release/wiki/Motion#walk2014-generator
 */
struct wb_nao_walk_command
{

    /**
     * connects the dcm callbacks. Essentially turning the walk on. When enabled, the walk engine controls all joint values except the head pitch and yaw.
     */
    PROPERTY(bool, walkEngineOn)

    /**
     * [-300 - 300] step-size(mm) per second, limited to +/- 300mm/step
     */
    PROPERTY(int16_t, forward)

    /**
     * [-200 - 200] step-size(mm) per second, limited to +/- 200mm/step
     */
    PROPERTY(int16_t, left)

    /**
     * [-85 - 85] step-size(mm) per second, limited to +/- 85deg/step
     */
    PROPERTY(int8_t, turn)

    /**
     * No ratcheting, no speed 'buildup', just full step sizes. This is good for exact movements, like walk 23cm forward for a kick.
     */
    PROPERTY(bool, exactStepsRequested)

    /**
     * [0 - 100] modifier for forward etc.. when using exactStepsRequested = true
     */
    PROPERTY(uint8_t, speed)

    /**
     * Odometry will reset any time this is changed or incremented.
     */
    PROPERTY(uint8_t, odometryResetCounter)

    /**
     * for kicks. True results in a 'Jab'/rapid kick.
     */
    PROPERTY(bool, isFast)

    /**
     * which foot to use for kicking
     */
    PROPERTY(bool, kickWithLeftFoot)

    /**
     * limits the step height so the robot 'shuffles' instead of taking larger steps. Good for walking near other robots or small obstacles that could trip the robot, if it tried to step onto it.
     */
    PROPERTY(bool, useShuffle)

    /**
     * lower stiffness in the arms when walking, allows the arm to move a little more. This is for robot collisions to allow the arm to absorb some of the collision instead of rigidly transferring the force to the whole body.
     */
    PROPERTY(bool, leftArmLimp)

    /**
     * lower stiffness in the arms when walking, allows the arm to move a little more. This is for robot collisions to allow the arm to absorb some of the collision instead of rigidly transferring the force to the whole body.
     */
    PROPERTY(bool, rightArmLimp)

    /**
     * [0 - 100] stiffness, auto set to minimum needed values. Advanced pararm! don't alter this without knowledge of exactly what it does.
     */
    PROPERTY(uint8_t, power)

    /**
     * [0 - 1] controls what the robot does when stopped, 0 == STAND and lower stiffness, 1 == stay in READY, crouched and ready to walk immediately.
     */
    PROPERTY(uint8_t, bend)

};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

/**
 * Convert to a description string.
 */
const char* wb_nao_walk_command_description(const struct wb_nao_walk_command* self, char* descString, size_t bufferSize);

/**
 * Convert to a string.
 */
const char* wb_nao_walk_command_to_string(const struct wb_nao_walk_command* self, char* toString, size_t bufferSize);

/**
 * Convert from a string.
 */
struct wb_nao_walk_command* wb_nao_walk_command_from_string(struct wb_nao_walk_command* self, const char* str);

#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

/*#ifdef WHITEBOARD_SERIALISATION*/

/**
 * Network stream serialisation
 */
size_t wb_nao_walk_command_to_network_serialised(const struct wb_nao_walk_command *self, char *dst);

/**
 * Network stream deserialisation
 */
size_t wb_nao_walk_command_from_network_serialised(const char *src, struct wb_nao_walk_command *dst);

/*#endif /// WHITEBOARD_SERIALISATION*/

#ifdef __cplusplus
}
#endif

#endif /// wb_nao_walk_command_h
