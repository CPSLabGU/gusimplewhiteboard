/*
 * file wb_gu_vr_teleop_vulkan_control.h
 *
 * This file was generated by classgenerator from gu_vr_teleop_vulkan_control.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2021 Carl Lusty. All rights reserved.
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

#ifndef wb_gu_vr_teleop_vulkan_control_h
#define wb_gu_vr_teleop_vulkan_control_h

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

enum VRControlMovementOptions {
	VRResting = 0,
	VRStanding,
	VRWalking
};

enum VRControlWalkingOptions {
	VRMovementForward = 0,
	VRMovementBack,
    VRMovementLeft,
    VRMovementRight,
    VRMovementRotateLeft,
    VRMovementRotateRight,
    NUM_VR_CONTROL_WALKING_OPTIONS
};

#define GU_VR_TELEOP_VULKAN_CONTROL_GENERATED 
#define GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT wb_gu_vr_teleop_vulkan_control 
#define GU_VR_TELEOP_VULKAN_CONTROL_NUMBER_OF_VARIABLES 2

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#define GU_VR_TELEOP_VULKAN_CONTROL_DESC_BUFFER_SIZE 1058
#define GU_VR_TELEOP_VULKAN_CONTROL_TO_STRING_BUFFER_SIZE 1027
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Control class for messages from the vulkan vr teleop application
 */
struct wb_gu_vr_teleop_vulkan_control
{

    /**
     * controls the robots movement
     */
    enum VRControlMovementOptions movementOptions;

    /**
     * controls the direction of high-level walk commands
     */
    enum VRControlWalkingOptions walkingOptions;

};

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

/**
 * Convert to a description string.
 */
const char* wb_gu_vr_teleop_vulkan_control_description(const struct wb_gu_vr_teleop_vulkan_control* self, char* descString, size_t bufferSize);

/**
 * Convert to a string.
 */
const char* wb_gu_vr_teleop_vulkan_control_to_string(const struct wb_gu_vr_teleop_vulkan_control* self, char* toString, size_t bufferSize);

/**
 * Convert from a string.
 */
struct wb_gu_vr_teleop_vulkan_control* wb_gu_vr_teleop_vulkan_control_from_string(struct wb_gu_vr_teleop_vulkan_control* self, const char* str);

#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

/*#ifdef WHITEBOARD_SERIALISATION*/

/**
 * Network stream serialisation
 */
size_t wb_gu_vr_teleop_vulkan_control_to_network_serialised(const struct wb_gu_vr_teleop_vulkan_control *self, char *dst);

/**
 * Network stream deserialisation
 */
size_t wb_gu_vr_teleop_vulkan_control_from_network_serialised(const char *src, struct wb_gu_vr_teleop_vulkan_control *dst);

/*#endif /// WHITEBOARD_SERIALISATION*/

#ifdef __cplusplus
}
#endif

#endif /// wb_gu_vr_teleop_vulkan_control_h
