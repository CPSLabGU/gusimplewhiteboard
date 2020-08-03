/*
 * file VisionDetectionGoal.h
 *
 * This file was generated by classgenerator from vision_detection_goal.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2020 Carl Lusty. All rights reserved.
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

#ifndef VisionDetectionGoal_DEFINED
#define VisionDetectionGoal_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_detection_goal.h"

#include <gusimplewhiteboard/typeClassDefs/VisionDetectionGoalPost.h>

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_detection_goal`.
     */
    class VisionDetectionGoal: public wb_vision_detection_goal {

    private:

        /**
         * Set the members of the class.
         */
        void init(enum GoalOptions sightingType = NoGoalDetected, struct wb_vision_detection_goal_post post1 = wb_vision_detection_goal_post(), struct wb_vision_detection_goal_post post2 = wb_vision_detection_goal_post()) {
            set_sightingType(sightingType);
            set_post1(post1);
            set_post2(post2);
        }

    public:

        /**
         * Create a new `VisionDetectionGoal`.
         */
        VisionDetectionGoal(enum GoalOptions sightingType = NoGoalDetected, struct wb_vision_detection_goal_post post1 = wb_vision_detection_goal_post(), struct wb_vision_detection_goal_post post2 = wb_vision_detection_goal_post()) {
            this->init(sightingType, post1, post2);
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionGoal(const VisionDetectionGoal &other): wb_vision_detection_goal() {
            this->init(other.sightingType(), other.post1(), other.post2());
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionGoal(const struct wb_vision_detection_goal &other): wb_vision_detection_goal() {
            this->init(other.sightingType(), other.post1(), other.post2());
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionGoal &operator = (const VisionDetectionGoal &other) {
            this->init(other.sightingType(), other.post1(), other.post2());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionGoal &operator = (const struct wb_vision_detection_goal &other) {
            this->init(other.sightingType(), other.post1(), other.post2());
            return *this;
        }

        bool operator ==(const VisionDetectionGoal &other) const
        {
            return sightingType() == other.sightingType()
                && VisionDetectionGoalPost(_post1) == VisionDetectionGoalPost(other._post1)
                && VisionDetectionGoalPost(_post2) == VisionDetectionGoalPost(other._post2);
        }

        bool operator !=(const VisionDetectionGoal &other) const
        {
            return !(*this == other);
        }

        bool operator ==(const wb_vision_detection_goal &other) const
        {
            return *this == VisionDetectionGoal(other);
        }

        bool operator !=(const wb_vision_detection_goal &other) const
        {
            return !(*this == other);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionDetectionGoal(const std::string &str) {
            this->init();
            this->from_string(str);
        }

        std::string description() {
#ifdef USE_WB_VISION_DETECTION_GOAL_C_CONVERSION
            char buffer[VISION_DETECTION_GOAL_DESC_BUFFER_SIZE];
            wb_vision_detection_goal_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            switch (this->sightingType()) {
                case DoublePostGoal:
                {
                    ss << "sightingType=" << "DoublePostGoal";
                    break;
                }
                case NoGoalDetected:
                {
                    ss << "sightingType=" << "NoGoalDetected";
                    break;
                }
                case SinglePostGoal:
                {
                    ss << "sightingType=" << "SinglePostGoal";
                    break;
                }
            }
            ss << ", ";
            guWhiteboard::VisionDetectionGoalPost * post1_cast = const_cast<guWhiteboard::VisionDetectionGoalPost *>(static_cast<const guWhiteboard::VisionDetectionGoalPost *>(&this->post1()));
            ss << "post1=" << "{" << post1_cast->description() << "}";
            ss << ", ";
            guWhiteboard::VisionDetectionGoalPost * post2_cast = const_cast<guWhiteboard::VisionDetectionGoalPost *>(static_cast<const guWhiteboard::VisionDetectionGoalPost *>(&this->post2()));
            ss << "post2=" << "{" << post2_cast->description() << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_GOAL_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_DETECTION_GOAL_C_CONVERSION
            char buffer[VISION_DETECTION_GOAL_TO_STRING_BUFFER_SIZE];
            wb_vision_detection_goal_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            switch (this->sightingType()) {
                case DoublePostGoal:
                {
                    ss << "DoublePostGoal";
                    break;
                }
                case NoGoalDetected:
                {
                    ss << "NoGoalDetected";
                    break;
                }
                case SinglePostGoal:
                {
                    ss << "SinglePostGoal";
                    break;
                }
            }
            ss << ", ";
            guWhiteboard::VisionDetectionGoalPost * post1_cast = const_cast<guWhiteboard::VisionDetectionGoalPost *>(static_cast<const guWhiteboard::VisionDetectionGoalPost *>(&this->post1()));
            ss << "{" << post1_cast->to_string() << "}";
            ss << ", ";
            guWhiteboard::VisionDetectionGoalPost * post2_cast = const_cast<guWhiteboard::VisionDetectionGoalPost *>(static_cast<const guWhiteboard::VisionDetectionGoalPost *>(&this->post2()));
            ss << "{" << post2_cast->to_string() << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_GOAL_C_CONVERSION
        }

#ifdef USE_WB_VISION_DETECTION_GOAL_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_detection_goal_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > VISION_DETECTION_GOAL_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[VISION_DETECTION_GOAL_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[13];
            char* key = &key_buffer[0];
            int bracecount = 0;
            int startVar = 0;
            int index = 0;
            int startKey = 0;
            int endKey = -1;
            int varIndex = 0;
            if (index == 0 && str_cstr[0] == '{') {
                index = 1;
            }
            startVar = index;
            startKey = startVar;
            do {
                for (int i = index; i < length; i++) {
                    index = i + 1;
                    if (bracecount == 0 && str_cstr[i] == '=') {
                        endKey = i - 1;
                        startVar = index;
                        continue;
                    }
                    if (bracecount == 0 && isspace(str_cstr[i])) {
                        startVar = index;
                        if (endKey == -1) {
                            startKey = index;
                        }
                        continue;
                    }
                    if (bracecount == 0 && str_cstr[i] == ',') {
                        index = i - 1;
                        break;
                    }
                    if (str_cstr[i] == '{') {
                        bracecount++;
                        continue;
                    }
                    if (str_cstr[i] == '}') {
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
                    strncpy(key, str_cstr + startKey, static_cast<size_t>((endKey - startKey) + 1));
                    key[(endKey - startKey) + 1] = 0;
                } else {
                    key[0] = 0;
                }
                strncpy(var_str, str_cstr + startVar, static_cast<size_t>((index - startVar) + 1));
                var_str[(index - startVar) + 1] = 0;
                bracecount = 0;
                index += 2;
                startVar = index;
                startKey = startVar;
                endKey = -1;
                if (strlen(key) > 0) {
                    if (0 == strcmp("sightingType", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("post1", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("post2", key)) {
                        varIndex = 2;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        if (strcmp("DoublePostGoal", var_str) == 0) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_sightingType(DoublePostGoal);
#pragma clang diagnostic pop
                        } else if (strcmp("NoGoalDetected", var_str) == 0) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_sightingType(NoGoalDetected);
#pragma clang diagnostic pop
                        } else if (strcmp("SinglePostGoal", var_str) == 0) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_sightingType(SinglePostGoal);
#pragma clang diagnostic pop
                        } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_sightingType(static_cast<enum GoalOptions>(atoi(var_str)));
#pragma clang diagnostic pop
                        }
                        break;
                    }
                    case 1:
                    {
                        VisionDetectionGoalPost post1_temp = VisionDetectionGoalPost();
                        post1_temp.from_string(var_str);
                        this->set_post1(post1_temp);
                        break;
                    }
                    case 2:
                    {
                        VisionDetectionGoalPost post2_temp = VisionDetectionGoalPost();
                        post2_temp.from_string(var_str);
                        this->set_post2(post2_temp);
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_VISION_DETECTION_GOAL_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard

#endif /// VisionDetectionGoal_DEFINED
