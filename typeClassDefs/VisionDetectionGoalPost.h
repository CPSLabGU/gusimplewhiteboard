/*
 * file VisionDetectionGoalPost.h
 *
 * This file was generated by classgenerator from vision_detection_goal_post.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2019 Carl Lusty. All rights reserved.
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

    private:

        /**
         * Set the members of the class.
         */
        void init(enum GoalPostOptions sightingType = NoPostDetected, enum GoalPostOrientation orientation = GenericPost, int16_t tl_x = 0, int16_t tl_y = 0, int16_t tr_x = 0, int16_t tr_y = 0, int16_t bl_x = 0, int16_t bl_y = 0, int16_t br_x = 0, int16_t br_y = 0) {
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

    public:

        /**
         * Create a new `VisionDetectionGoalPost`.
         */
        VisionDetectionGoalPost(enum GoalPostOptions sightingType = NoPostDetected, enum GoalPostOrientation orientation = GenericPost, int16_t tl_x = 0, int16_t tl_y = 0, int16_t tr_x = 0, int16_t tr_y = 0, int16_t bl_x = 0, int16_t bl_y = 0, int16_t br_x = 0, int16_t br_y = 0) {
            this->init(sightingType, orientation, tl_x, tl_y, tr_x, tr_y, bl_x, bl_y, br_x, br_y);
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionGoalPost(const VisionDetectionGoalPost &other): wb_vision_detection_goal_post() {
            this->init(other.sightingType(), other.orientation(), other.tl_x(), other.tl_y(), other.tr_x(), other.tr_y(), other.bl_x(), other.bl_y(), other.br_x(), other.br_y());
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionGoalPost(const struct wb_vision_detection_goal_post &other): wb_vision_detection_goal_post() {
            this->init(other.sightingType(), other.orientation(), other.tl_x(), other.tl_y(), other.tr_x(), other.tr_y(), other.bl_x(), other.bl_y(), other.br_x(), other.br_y());
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionGoalPost &operator = (const VisionDetectionGoalPost &other) {
            this->init(other.sightingType(), other.orientation(), other.tl_x(), other.tl_y(), other.tr_x(), other.tr_y(), other.bl_x(), other.bl_y(), other.br_x(), other.br_y());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionGoalPost &operator = (const struct wb_vision_detection_goal_post &other) {
            this->init(other.sightingType(), other.orientation(), other.tl_x(), other.tl_y(), other.tr_x(), other.tr_y(), other.bl_x(), other.bl_y(), other.br_x(), other.br_y());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionDetectionGoalPost(const std::string &str) {
            this->init();
            this->from_string(str);
        }

        std::string description() {
#ifdef USE_WB_VISION_DETECTION_GOAL_POST_C_CONVERSION
            char buffer[VISION_DETECTION_GOAL_POST_DESC_BUFFER_SIZE];
            wb_vision_detection_goal_post_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            switch (this->sightingType()) {
                case FullPostSeen:
                {
                    ss << "sightingType=" << "FullPostSeen";
                    break;
                }
                case NoPostDetected:
                {
                    ss << "sightingType=" << "NoPostDetected";
                    break;
                }
                case PartialPostSeen:
                {
                    ss << "sightingType=" << "PartialPostSeen";
                    break;
                }
            }
            ss << ", ";
            switch (this->orientation()) {
                case GenericPost:
                {
                    ss << "orientation=" << "GenericPost";
                    break;
                }
                case LeftPost:
                {
                    ss << "orientation=" << "LeftPost";
                    break;
                }
                case RightPost:
                {
                    ss << "orientation=" << "RightPost";
                    break;
                }
            }
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
            switch (this->sightingType()) {
                case FullPostSeen:
                {
                    ss << "FullPostSeen";
                    break;
                }
                case NoPostDetected:
                {
                    ss << "NoPostDetected";
                    break;
                }
                case PartialPostSeen:
                {
                    ss << "PartialPostSeen";
                    break;
                }
            }
            ss << ", ";
            switch (this->orientation()) {
                case GenericPost:
                {
                    ss << "GenericPost";
                    break;
                }
                case LeftPost:
                {
                    ss << "LeftPost";
                    break;
                }
                case RightPost:
                {
                    ss << "RightPost";
                    break;
                }
            }
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
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > VISION_DETECTION_GOAL_POST_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[VISION_DETECTION_GOAL_POST_DESC_BUFFER_SIZE + 1];
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
                    } else if (0 == strcmp("orientation", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("tl_x", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("tl_y", key)) {
                        varIndex = 3;
                    } else if (0 == strcmp("tr_x", key)) {
                        varIndex = 4;
                    } else if (0 == strcmp("tr_y", key)) {
                        varIndex = 5;
                    } else if (0 == strcmp("bl_x", key)) {
                        varIndex = 6;
                    } else if (0 == strcmp("bl_y", key)) {
                        varIndex = 7;
                    } else if (0 == strcmp("br_x", key)) {
                        varIndex = 8;
                    } else if (0 == strcmp("br_y", key)) {
                        varIndex = 9;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        if (strcmp("FullPostSeen", var_str) == 0) {
                            this->set_sightingType(FullPostSeen);
                        } else if (strcmp("NoPostDetected", var_str) == 0) {
                            this->set_sightingType(NoPostDetected);
                        } else if (strcmp("PartialPostSeen", var_str) == 0) {
                            this->set_sightingType(PartialPostSeen);
                        } else {
                            this->set_sightingType(static_cast<enum GoalPostOptions>(atoi(var_str)));
                        }
                        break;
                    }
                    case 1:
                    {
                        if (strcmp("GenericPost", var_str) == 0) {
                            this->set_orientation(GenericPost);
                        } else if (strcmp("LeftPost", var_str) == 0) {
                            this->set_orientation(LeftPost);
                        } else if (strcmp("RightPost", var_str) == 0) {
                            this->set_orientation(RightPost);
                        } else {
                            this->set_orientation(static_cast<enum GoalPostOrientation>(atoi(var_str)));
                        }
                        break;
                    }
                    case 2:
                    {
                        this->set_tl_x(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_tl_y(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 4:
                    {
                        this->set_tr_x(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 5:
                    {
                        this->set_tr_y(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 6:
                    {
                        this->set_bl_x(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 7:
                    {
                        this->set_bl_y(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 8:
                    {
                        this->set_br_x(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 9:
                    {
                        this->set_br_y(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_VISION_DETECTION_GOAL_POST_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard
#endif /// VisionDetectionGoalPost_DEFINED
