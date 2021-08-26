/*
 * file FilteredArrayBallSightings.hpp
 *
 * This file was generated by classgenerator from Filtered_ArrayBallSightings.txt.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2021 Vlad Estivill-Castro. All rights reserved.
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
 *        This product includes software developed by Vlad Estivill-Castro.
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

#ifndef guWhiteboard_FilteredArrayBallSightings_h
#define guWhiteboard_FilteredArrayBallSightings_h

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_filtered_arrayballsightings.h"

#undef guWhiteboard_FilteredArrayBallSightings_DEFINED
#define guWhiteboard_FilteredArrayBallSightings_DEFINED

#undef FilteredArrayBallSightings_DEFINED
#define FilteredArrayBallSightings_DEFINED

#include "FilteredVisionObject.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_filtered_arrayballsightings`.
     */
    class FilteredArrayBallSightings: public wb_filtered_arrayballsightings {

    private:

        /**
         * Set the members of the class.
         */
        void init(const struct wb_filtered_vision_object t_objects[2] = NULLPTR) {
            if (t_objects != NULLPTR) {
                std::memcpy(wb_filtered_arrayballsightings::objects, t_objects, FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE * sizeof (struct wb_filtered_vision_object));
            } else {
                struct wb_filtered_vision_object objects_temp[FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE] = {wb_filtered_vision_object(), wb_filtered_vision_object()};
                std::memcpy(wb_filtered_arrayballsightings::objects, objects_temp, FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE * sizeof (struct wb_filtered_vision_object));
            }
        }

    public:

        /**
         * Create a new `FilteredArrayBallSightings`.
         */
        FilteredArrayBallSightings(const struct wb_filtered_vision_object t_objects[2] = NULLPTR) {
            this->init(t_objects);
        }

        /**
         * Copy Constructor.
         */
        FilteredArrayBallSightings(const FilteredArrayBallSightings &t_other): wb_filtered_arrayballsightings() {
            this->init(t_other.objects());
        }

        /**
         * Copy Constructor.
         */
        FilteredArrayBallSightings(const struct wb_filtered_arrayballsightings &t_other): wb_filtered_arrayballsightings() {
            this->init(t_other.objects);
        }

        /**
         * Copy Assignment Operator.
         */
        FilteredArrayBallSightings &operator = (const FilteredArrayBallSightings &t_other) {
            this->init(t_other.objects());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        FilteredArrayBallSightings &operator = (const struct wb_filtered_arrayballsightings &t_other) {
            this->init(t_other.objects);
            return *this;
        }

        bool operator ==(const FilteredArrayBallSightings &t_other) const
        {
            for (int objects_0_index = 0; objects_0_index < 2; objects_0_index++)
            {
                if (!(FilteredVisionObject(objects(objects_0_index)) == FilteredVisionObject(t_other.objects(objects_0_index)))) return false;
            }
            return true;
        }

        bool operator !=(const FilteredArrayBallSightings &t_other) const
        {
            return !(*this == t_other);
        }

        bool operator ==(const wb_filtered_arrayballsightings &t_other) const
        {
            return *this == FilteredArrayBallSightings(t_other);
        }

        bool operator !=(const wb_filtered_arrayballsightings &t_other) const
        {
            return !(*this == t_other);
        }

        const FilteredVisionObject * objects() const
        {
            return static_cast<const FilteredVisionObject *>(&(wb_filtered_arrayballsightings::objects[0]));
        }

        size_t objects_size() const
        {
            return FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE;
        }

        FilteredVisionObject & objects(int t_i)
        {
            return const_cast<FilteredVisionObject &>(static_cast<const FilteredVisionObject &>(wb_filtered_arrayballsightings::objects[t_i]));
        }

        const FilteredVisionObject & objects(int t_i) const
        {
            return static_cast<const FilteredVisionObject &>(wb_filtered_arrayballsightings::objects[t_i]);
        }

        void set_objects(const FilteredVisionObject *t_newValue)
        {
            memcpy(wb_filtered_arrayballsightings::objects, static_cast<const struct wb_filtered_vision_object *>(t_newValue), FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE * (sizeof (struct wb_filtered_vision_object)));
        }

        void set_objects(const FilteredVisionObject &t_newValue, int t_i)
        {
            wb_filtered_arrayballsightings::objects[t_i] = static_cast<wb_filtered_vision_object>(t_newValue);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        FilteredArrayBallSightings(const std::string &t_str) {
            this->init();
            this->from_string(t_str);
        }

        std::string description() {
#ifdef USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
            char buffer[FILTERED_ARRAYBALLSIGHTINGS_DESC_BUFFER_SIZE];
            wb_filtered_arrayballsightings_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            bool objects_first = true;
            ss << "objects={";
            for (int i = 0; i < FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE; i++) {
                ss << (objects_first ? "" : ", ") << "{" << FilteredVisionObject(this->objects(i)).description() << "}";
                objects_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
            char buffer[FILTERED_ARRAYBALLSIGHTINGS_TO_STRING_BUFFER_SIZE];
            wb_filtered_arrayballsightings_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            bool objects_first = true;
            ss << "{";
            for (int i = 0; i < FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE; i++) {
                ss << (objects_first ? "" : ", ") << "{" << FilteredVisionObject(this->objects(i)).to_string() << "}";
                objects_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
        }

#ifdef USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
        void from_string(const std::string &t_str) {
            wb_filtered_arrayballsightings_from_string(this, t_str.c_str());
#else
        void from_string(const std::string &t_str) {
            char * str_cstr = const_cast<char *>(t_str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > FILTERED_ARRAYBALLSIGHTINGS_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[FILTERED_ARRAYBALLSIGHTINGS_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[8];
            char* key = &key_buffer[0];
            int bracecount = 0;
            int lastBrace = -1;
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
                    if (0 == strcmp("objects", key)) {
                        varIndex = 0;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        int restartIndex = index;
                        index = lastBrace + 1;
                        startVar = index;
                        startKey = startVar;
                        endKey = -1;
                        bracecount = 0;
                        for (int objects_0_index = 0; objects_0_index < FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE; objects_0_index++) {
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
                            FilteredVisionObject objects_0_temp = FilteredVisionObject();
                            objects_0_temp.from_string(var_str);
                            struct wb_filtered_vision_object objects_0 = objects_0_temp;
                            this->set_objects(objects_0, objects_0_index);
                        }
                        index = restartIndex;
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard

#endif /// guWhiteboard_FilteredArrayBallSightings_h
