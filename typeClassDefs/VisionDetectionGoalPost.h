/*
 * file VisionDetectionGoalPost.h
 *
 * This file was generated by classgenerator from vision_detection_goal_post.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 14:45, 18/05/2018.
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

#ifndef VisionDetectionGoalPost_DEFINED
#define VisionDetectionGoalPost_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_detection_goal_post.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_detection_goal_post`.
     */
    class VisionDetectionGoalPost: public wb_vision_detection_goal_post {

    public:

        /**
         * Create a new `VisionDetectionGoalPost`.
         */
        VisionDetectionGoalPost(enum GoalPostOptions sightingType = NoPostDetected, enum GoalPostOrientation orientation = GenericPost, int16_t tl_x = 0, int16_t tl_y = 0, int16_t tr_x = 0, int16_t tr_y = 0, int16_t bl_x = 0, int16_t bl_y = 0, int16_t br_x = 0, int16_t br_y = 0) {
            set_sightingType(sightingType);
            set_orientation(orientation);
            set_tl_x(tl_x);
            set_tl_y(tl_y);
            set_tr_x(tr_x);
            set_tr_y(tr_y);
            set_bl_x(bl_x);
            set_bl_y(bl_y);
            set_br_x(br_x);
            set_br_y(br_y);
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionGoalPost(const VisionDetectionGoalPost &other): wb_vision_detection_goal_post() {
            set_sightingType(other.sightingType());
            set_orientation(other.orientation());
            set_tl_x(other.tl_x());
            set_tl_y(other.tl_y());
            set_tr_x(other.tr_x());
            set_tr_y(other.tr_y());
            set_bl_x(other.bl_x());
            set_bl_y(other.bl_y());
            set_br_x(other.br_x());
            set_br_y(other.br_y());
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionGoalPost &operator = (const VisionDetectionGoalPost &other) {
            set_sightingType(other.sightingType());
            set_orientation(other.orientation());
            set_tl_x(other.tl_x());
            set_tl_y(other.tl_y());
            set_tr_x(other.tr_x());
            set_tr_y(other.tr_y());
            set_bl_x(other.bl_x());
            set_bl_y(other.bl_y());
            set_br_x(other.br_x());
            set_br_y(other.br_y());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionDetectionGoalPost(const std::string &str) { wb_vision_detection_goal_post_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_VISION_DETECTION_GOAL_POST_C_CONVERSION
            char buffer[VISION_DETECTION_GOAL_POST_DESC_BUFFER_SIZE];
            wb_vision_detection_goal_post_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "sightingType=" << static_cast<signed>(this->sightingType());
            ss << ", ";
            ss << "orientation=" << static_cast<signed>(this->orientation());
            ss << ", ";
            ss << "tl_x=" << static_cast<signed>(this->tl_x());
            ss << ", ";
            ss << "tl_y=" << static_cast<signed>(this->tl_y());
            ss << ", ";
            ss << "tr_x=" << static_cast<signed>(this->tr_x());
            ss << ", ";
            ss << "tr_y=" << static_cast<signed>(this->tr_y());
            ss << ", ";
            ss << "bl_x=" << static_cast<signed>(this->bl_x());
            ss << ", ";
            ss << "bl_y=" << static_cast<signed>(this->bl_y());
            ss << ", ";
            ss << "br_x=" << static_cast<signed>(this->br_x());
            ss << ", ";
            ss << "br_y=" << static_cast<signed>(this->br_y());
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_GOAL_POST_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_DETECTION_GOAL_POST_C_CONVERSION
            char buffer[VISION_DETECTION_GOAL_POST_TO_STRING_BUFFER_SIZE];
            wb_vision_detection_goal_post_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << static_cast<signed>(this->sightingType());
            ss << ", ";
            ss << static_cast<signed>(this->orientation());
            ss << ", ";
            ss << static_cast<signed>(this->tl_x());
            ss << ", ";
            ss << static_cast<signed>(this->tl_y());
            ss << ", ";
            ss << static_cast<signed>(this->tr_x());
            ss << ", ";
            ss << static_cast<signed>(this->tr_y());
            ss << ", ";
            ss << static_cast<signed>(this->bl_x());
            ss << ", ";
            ss << static_cast<signed>(this->bl_y());
            ss << ", ";
            ss << static_cast<signed>(this->br_x());
            ss << ", ";
            ss << static_cast<signed>(this->br_y());
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_GOAL_POST_C_CONVERSION
        }

#ifdef USE_WB_VISION_DETECTION_GOAL_POST_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_detection_goal_post_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char var[255];
            unsigned long sightingType_index = str.find("sightingType=");
            if (sightingType_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(sightingType_index, str.length()).c_str(), "sightingType = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_sightingType(static_cast<enum GoalPostOptions>(atoi(value.c_str())));
                }
            }
            unsigned long orientation_index = str.find("orientation=");
            if (orientation_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(orientation_index, str.length()).c_str(), "orientation = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_orientation(static_cast<enum GoalPostOrientation>(atoi(value.c_str())));
                }
            }
            unsigned long tl_x_index = str.find("tl_x=");
            if (tl_x_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(tl_x_index, str.length()).c_str(), "tl_x = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_tl_x(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long tl_y_index = str.find("tl_y=");
            if (tl_y_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(tl_y_index, str.length()).c_str(), "tl_y = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_tl_y(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long tr_x_index = str.find("tr_x=");
            if (tr_x_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(tr_x_index, str.length()).c_str(), "tr_x = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_tr_x(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long tr_y_index = str.find("tr_y=");
            if (tr_y_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(tr_y_index, str.length()).c_str(), "tr_y = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_tr_y(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long bl_x_index = str.find("bl_x=");
            if (bl_x_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(bl_x_index, str.length()).c_str(), "bl_x = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_bl_x(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long bl_y_index = str.find("bl_y=");
            if (bl_y_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(bl_y_index, str.length()).c_str(), "bl_y = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_bl_y(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long br_x_index = str.find("br_x=");
            if (br_x_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(br_x_index, str.length()).c_str(), "br_x = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_br_x(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
            unsigned long br_y_index = str.find("br_y=");
            if (br_y_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(br_y_index, str.length()).c_str(), "br_y = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_br_y(static_cast<int16_t>(atoi(value.c_str())));
                }
            }
#endif /// USE_WB_VISION_DETECTION_GOAL_POST_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard
#endif /// VisionDetectionGoalPost_DEFINED
