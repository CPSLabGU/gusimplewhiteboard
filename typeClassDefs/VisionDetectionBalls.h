/*
 * file VisionDetectionBalls.h
 *
 * This file was generated by classgenerator from vision_detection_balls.gen.
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

#ifndef VisionDetectionBalls_DEFINED
#define VisionDetectionBalls_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_detection_balls.h"

#include <gusimplewhiteboard/typeClassDefs/VisionDetectionBall.h>

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_detection_balls`.
     */
    class VisionDetectionBalls: public wb_vision_detection_balls {

    public:

        /**
         * Create a new `VisionDetectionBalls`.
         */
        VisionDetectionBalls(uint64_t frameNumber = 0, struct wb_vision_detection_ball balls[2] = NULLPTR) {
            set_frameNumber(frameNumber);
            if (balls != NULLPTR) {
                std::memcpy(this->_balls, balls, VISION_DETECTION_BALLS_BALLS_ARRAY_SIZE * sizeof (struct wb_vision_detection_ball));
            } else {
                struct wb_vision_detection_ball balls_temp[VISION_DETECTION_BALLS_BALLS_ARRAY_SIZE] = {wb_vision_detection_ball(), wb_vision_detection_ball()};
                std::memcpy(this->_balls, balls_temp, VISION_DETECTION_BALLS_BALLS_ARRAY_SIZE * sizeof (struct wb_vision_detection_ball));
            }
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionBalls(const VisionDetectionBalls &other): wb_vision_detection_balls() {
            set_frameNumber(other.frameNumber());
            if (other.balls() != NULLPTR) {
                std::memcpy(this->_balls, other.balls(), VISION_DETECTION_BALLS_BALLS_ARRAY_SIZE * sizeof (struct wb_vision_detection_ball));
            }
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionBalls &operator = (const VisionDetectionBalls &other) {
            set_frameNumber(other.frameNumber());
            if (other.balls() != NULLPTR) {
                std::memcpy(this->_balls, other.balls(), VISION_DETECTION_BALLS_BALLS_ARRAY_SIZE * sizeof (struct wb_vision_detection_ball));
            }
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionDetectionBalls(const std::string &str) { wb_vision_detection_balls_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_VISION_DETECTION_BALLS_C_CONVERSION
            char buffer[VISION_DETECTION_BALLS_DESC_BUFFER_SIZE];
            wb_vision_detection_balls_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "frameNumber=" << this->frameNumber();
            ss << ", ";
            bool balls_first = true;
            ss << "balls={";
            for (int i = 0; i < VISIONDETECTIONBALLS_BALLS_ARRAY_SIZE; i++) {
                guWhiteboard::VisionDetectionBall * balls_cast = const_cast<guWhiteboard::VisionDetectionBall *>(static_cast<const guWhiteboard::VisionDetectionBall *>(&this->balls(i)));
                ss << (balls_first ? "" : ", ") << "{" << balls_cast->description() << "}";
                balls_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_BALLS_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_DETECTION_BALLS_C_CONVERSION
            char buffer[VISION_DETECTION_BALLS_TO_STRING_BUFFER_SIZE];
            wb_vision_detection_balls_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << this->frameNumber();
            ss << ", ";
            bool balls_first = true;
            ss << "{";
            for (int i = 0; i < VISIONDETECTIONBALLS_BALLS_ARRAY_SIZE; i++) {
                guWhiteboard::VisionDetectionBall * balls_cast = const_cast<guWhiteboard::VisionDetectionBall *>(static_cast<const guWhiteboard::VisionDetectionBall *>(&this->balls(i)));
                ss << (balls_first ? "" : ", ") << "{" << balls_cast->to_string() << "}";
                balls_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_BALLS_C_CONVERSION
        }

#ifdef USE_WB_VISION_DETECTION_BALLS_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_detection_balls_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char var[255];
            unsigned long frameNumber_index = str.find("frameNumber=");
            if (frameNumber_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(frameNumber_index, str.length()).c_str(), "frameNumber = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_frameNumber(static_cast<uint64_t>(atoll(value.c_str())));
                }
            }
            unsigned long balls_index = str.find("balls=");
            if (balls_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(balls_index, str.length()).c_str(), "balls = { %[^}]", var) == 1) {
                    std::string value = std::string(var);
                    int balls_bracecount = 0;
                    unsigned long balls_lastBrace = balls_index;
                    int balls_array_index = 0;
                    for (unsigned long balls_loop_index = balls_index; balls_loop_index < str.length(); balls_loop_index++) {
                        if (str.at(balls_loop_index) == '{') {
                            balls_bracecount++;
                            if (balls_bracecount == 2) {
                                balls_lastBrace = balls_loop_index;
                            }
                            continue;
                        }
                        if (str.at(balls_loop_index) == '}') {
                            balls_bracecount--;
                            if (balls_bracecount < 1) {
                                break;
                            }
                            if (balls_bracecount > 1) {
                                continue;
                            }
                            std::string balls_value = str.substr(balls_lastBrace, balls_loop_index - balls_lastBrace + 1);
                            VisionDetectionBall balls = VisionDetectionBall();
                            balls.from_string(balls_value);
                            set_balls(balls, balls_array_index++);
                            continue;
                        }
                    }
                }
            }
#endif /// USE_WB_VISION_DETECTION_BALLS_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard
#endif /// VisionDetectionBalls_DEFINED
