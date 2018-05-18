/*
 * file VisionDetectionBall.h
 *
 * This file was generated by classgenerator from vision_detection_ball.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 14:48, 18/05/2018.
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

#ifndef VisionDetectionBall_DEFINED
#define VisionDetectionBall_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_detection_ball.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_detection_ball`.
     */
    class VisionDetectionBall: public wb_vision_detection_ball {

    public:

        /**
         * Create a new `VisionDetectionBall`.
         */
        VisionDetectionBall(enum BallOptions sightingType = NoBallDetected, int16_t x = 0, int16_t y = 0, uint16_t r = 0) {
            set_sightingType(sightingType);
            set_x(x);
            set_y(y);
            set_r(r);
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionBall(const VisionDetectionBall &other): wb_vision_detection_ball() {
            set_sightingType(other.sightingType());
            set_x(other.x());
            set_y(other.y());
            set_r(other.r());
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionBall &operator = (const VisionDetectionBall &other) {
            set_sightingType(other.sightingType());
            set_x(other.x());
            set_y(other.y());
            set_r(other.r());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionDetectionBall(const std::string &str) { wb_vision_detection_ball_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_VISION_DETECTION_BALL_C_CONVERSION
            char buffer[VISION_DETECTION_BALL_DESC_BUFFER_SIZE];
            wb_vision_detection_ball_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "sightingType=" << static_cast<signed>(this->sightingType());
            ss << ", ";
            ss << "x=" << static_cast<signed>(this->x());
            ss << ", ";
            ss << "y=" << static_cast<signed>(this->y());
            ss << ", ";
            ss << "r=" << static_cast<unsigned>(this->r());
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_BALL_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_DETECTION_BALL_C_CONVERSION
            char buffer[VISION_DETECTION_BALL_TO_STRING_BUFFER_SIZE];
            wb_vision_detection_ball_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << static_cast<signed>(this->sightingType());
            ss << ", ";
            ss << static_cast<signed>(this->x());
            ss << ", ";
            ss << static_cast<signed>(this->y());
            ss << ", ";
            ss << static_cast<unsigned>(this->r());
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_BALL_C_CONVERSION
        }

#ifdef USE_WB_VISION_DETECTION_BALL_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_detection_ball_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char var[255];
            unsigned long sightingType_index = str.find("sightingType=");
            if (sightingType_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(sightingType_index, str.length()).c_str(), "sightingType = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_sightingType(static_cast<enum BallOptions>(atoi(value.c_str())));
                }
            }
            unsigned long x_index = str.find("x=");
            if (x_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(x_index, str.length()).c_str(), "x = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_x(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long y_index = str.find("y=");
            if (y_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(y_index, str.length()).c_str(), "y = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_y(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long r_index = str.find("r=");
            if (r_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(r_index, str.length()).c_str(), "r = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_r(static_cast<uint16_t>(atoi(value.c_str())));
                }
            }
#endif /// USE_WB_VISION_DETECTION_BALL_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard
#endif /// VisionDetectionBall_DEFINED
