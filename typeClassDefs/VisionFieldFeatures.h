/*
 * file VisionFieldFeatures.h
 *
 * This file was generated by classgenerator from Vision_FieldFeatures.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Eugene Gilmore at 16:12, 08/11/2018.
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

#ifndef VisionFieldFeatures_DEFINED
#define VisionFieldFeatures_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_field_features.h"

#include "VisionFieldFeature.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_field_features`.
     */
    class VisionFieldFeatures: public wb_vision_field_features {

    public:

        /**
         * Create a new `VisionFieldFeatures`.
         */
        VisionFieldFeatures(struct wb_vision_field_feature fieldCorner[8] = NULLPTR, struct wb_vision_field_feature fieldIntersection[8] = NULLPTR, uint8_t numCorners = 0, uint8_t numIntersections = 0) {
            if (fieldCorner != NULLPTR) {
                std::memcpy(this->_fieldCorner, fieldCorner, VISION_FIELDFEATURES_FIELDCORNER_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            } else {
                struct wb_vision_field_feature fieldCorner_temp[VISION_FIELDFEATURES_FIELDCORNER_ARRAY_SIZE] = { wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature() };
                std::memcpy(this->_fieldCorner, fieldCorner_temp, VISION_FIELDFEATURES_FIELDCORNER_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            if (fieldIntersection != NULLPTR) {
                std::memcpy(this->_fieldIntersection, fieldIntersection, VISION_FIELDFEATURES_FIELDINTERSECTION_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            } else {
                struct wb_vision_field_feature fieldIntersection_temp[VISION_FIELDFEATURES_FIELDINTERSECTION_ARRAY_SIZE] = { wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature(), wb_vision_field_feature() };
                std::memcpy(this->_fieldIntersection, fieldIntersection_temp, VISION_FIELDFEATURES_FIELDINTERSECTION_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            set_numCorners(numCorners);
            set_numIntersections(numIntersections);
        }

        /**
         * Copy Constructor.
         */
        VisionFieldFeatures(const VisionFieldFeatures &other): wb_vision_field_features() {
            if (other.fieldCorner() != NULLPTR) {
                std::memcpy(this->_fieldCorner, other.fieldCorner(), VISION_FIELDFEATURES_FIELDCORNER_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            if (other.fieldIntersection() != NULLPTR) {
                std::memcpy(this->_fieldIntersection, other.fieldIntersection(), VISION_FIELDFEATURES_FIELDINTERSECTION_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            set_numCorners(other.numCorners());
            set_numIntersections(other.numIntersections());
        }

        /**
         * Copy Constructor.
         */
        VisionFieldFeatures(const struct wb_vision_field_features &other): wb_vision_field_features() {
            if (other.fieldCorner() != NULLPTR) {
                std::memcpy(this->_fieldCorner, other.fieldCorner(), VISION_FIELDFEATURES_FIELDCORNER_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            if (other.fieldIntersection() != NULLPTR) {
                std::memcpy(this->_fieldIntersection, other.fieldIntersection(), VISION_FIELDFEATURES_FIELDINTERSECTION_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            set_numCorners(other.numCorners());
            set_numIntersections(other.numIntersections());
        }

        /**
         * Copy Assignment Operator.
         */
        VisionFieldFeatures &operator = (const VisionFieldFeatures &other) {
            if (other.fieldCorner() != NULLPTR) {
                std::memcpy(this->_fieldCorner, other.fieldCorner(), VISION_FIELDFEATURES_FIELDCORNER_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            if (other.fieldIntersection() != NULLPTR) {
                std::memcpy(this->_fieldIntersection, other.fieldIntersection(), VISION_FIELDFEATURES_FIELDINTERSECTION_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            set_numCorners(other.numCorners());
            set_numIntersections(other.numIntersections());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        VisionFieldFeatures &operator = (const struct wb_vision_field_features &other) {
            if (other.fieldCorner() != NULLPTR) {
                std::memcpy(this->_fieldCorner, other.fieldCorner(), VISION_FIELDFEATURES_FIELDCORNER_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            if (other.fieldIntersection() != NULLPTR) {
                std::memcpy(this->_fieldIntersection, other.fieldIntersection(), VISION_FIELDFEATURES_FIELDINTERSECTION_ARRAY_SIZE * sizeof (struct wb_vision_field_feature));
            }
            set_numCorners(other.numCorners());
            set_numIntersections(other.numIntersections());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionFieldFeatures(const std::string &str) { wb_vision_field_features_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_VISION_FIELD_FEATURES_C_CONVERSION
            char buffer[VISION_FIELDFEATURES_DESC_BUFFER_SIZE];
            wb_vision_field_features_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "numCorners=" << static_cast<unsigned>(this->numCorners());
            ss << ", ";
            ss << "numIntersections=" << static_cast<unsigned>(this->numIntersections());
            return ss.str();
#endif /// USE_WB_VISION_FIELD_FEATURES_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_FIELD_FEATURES_C_CONVERSION
            char buffer[VISION_FIELDFEATURES_TO_STRING_BUFFER_SIZE];
            wb_vision_field_features_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << static_cast<unsigned>(this->numCorners());
            ss << ", ";
            ss << static_cast<unsigned>(this->numIntersections());
            return ss.str();
#endif /// USE_WB_VISION_FIELD_FEATURES_C_CONVERSION
        }

#ifdef USE_WB_VISION_FIELDFEATURES_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_field_features_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1) {
                return;
            }
            char var_str_buffer[VISION_FIELDFEATURES_TO_STRING_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[18];
            char* key = &key_buffer[0];
            int bracecount = 0;
            int lastBrace = -1;
            int startVar = 0;
            int index = 0;
            int startKey = 0;
            int endKey = 0;
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
                        if (bracecount == 1) {
                            lastBrace = i;
                        }
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
                    strncpy(key, str_cstr + startKey, (endKey - startKey) + 1);
                    key[(endKey - startKey) + 1] = 0;
                } else {
                    key[0] = 0;
                }
                strncpy(var_str, str_cstr + startVar, (index - startVar) + 1);
                var_str[(index - startVar) + 1] = 0;
                bracecount = 0;
                index += 2;
                startVar = index;
                startKey = startVar;
                endKey = -1;
                if (key != NULLPTR) {
                    if (0 == strcmp("fieldCorner", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("fieldIntersection", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("numCorners", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("numIntersections", key)) {
                        varIndex = 3;
                    }
                }
                switch (varIndex) {
                    case 2:
                    {
                        this->set_numCorners(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_numIntersections(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                }
                varIndex++;
            } while(index < length);
#endif /// USE_WB_VISION_FIELDFEATURES_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard
#endif /// VisionFieldFeatures_DEFINED
