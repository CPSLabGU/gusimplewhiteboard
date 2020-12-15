/*
 * file RMSLevels.h
 *
 * This file was generated by classgenerator from RMS_levels.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2020 Rene Hexel. All rights reserved.
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
 *        This product includes software developed by Rene Hexel.
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

#ifndef RMSLevels_DEFINED
#define RMSLevels_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_r_m_s_levels.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_r_m_s_levels`.
     */
    class RMSLevels: public wb_r_m_s_levels {

    private:

        /**
         * Set the members of the class.
         */
        void init(int16_t t_rear_left = 0, int16_t t_rear_right = 0, int16_t t_front_left = 0, int16_t t_front_right = 0) {
            set_rear_left(t_rear_left);
            set_rear_right(t_rear_right);
            set_front_left(t_front_left);
            set_front_right(t_front_right);
        }

    public:

        /**
         * Create a new `RMSLevels`.
         */
        RMSLevels(int16_t t_rear_left = 0, int16_t t_rear_right = 0, int16_t t_front_left = 0, int16_t t_front_right = 0) {
            this->init(t_rear_left, t_rear_right, t_front_left, t_front_right);
        }

        /**
         * Copy Constructor.
         */
        RMSLevels(const RMSLevels &t_other): wb_r_m_s_levels() {
            this->init(t_other.rear_left(), t_other.rear_right(), t_other.front_left(), t_other.front_right());
        }

        /**
         * Copy Constructor.
         */
        RMSLevels(const struct wb_r_m_s_levels &t_other): wb_r_m_s_levels() {
            this->init(t_other.rear_left, t_other.rear_right, t_other.front_left, t_other.front_right);
        }

        /**
         * Copy Assignment Operator.
         */
        RMSLevels &operator = (const RMSLevels &t_other) {
            this->init(t_other.rear_left(), t_other.rear_right(), t_other.front_left(), t_other.front_right());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        RMSLevels &operator = (const struct wb_r_m_s_levels &t_other) {
            this->init(t_other.rear_left, t_other.rear_right, t_other.front_left, t_other.front_right);
            return *this;
        }

        bool operator ==(const RMSLevels &t_other) const
        {
            return rear_left() == t_other.rear_left()
                && rear_right() == t_other.rear_right()
                && front_left() == t_other.front_left()
                && front_right() == t_other.front_right();
        }

        bool operator !=(const RMSLevels &t_other) const
        {
            return !(*this == t_other);
        }

        bool operator ==(const wb_r_m_s_levels &t_other) const
        {
            return *this == RMSLevels(t_other);
        }

        bool operator !=(const wb_r_m_s_levels &t_other) const
        {
            return !(*this == t_other);
        }

        int16_t rear_left() const
        {
            return wb_r_m_s_levels::rear_left;
        }

        void set_rear_left(const int16_t &t_newValue)
        {
            wb_r_m_s_levels::rear_left = t_newValue;
        }

        int16_t rear_right() const
        {
            return wb_r_m_s_levels::rear_right;
        }

        void set_rear_right(const int16_t &t_newValue)
        {
            wb_r_m_s_levels::rear_right = t_newValue;
        }

        int16_t front_left() const
        {
            return wb_r_m_s_levels::front_left;
        }

        void set_front_left(const int16_t &t_newValue)
        {
            wb_r_m_s_levels::front_left = t_newValue;
        }

        int16_t front_right() const
        {
            return wb_r_m_s_levels::front_right;
        }

        void set_front_right(const int16_t &t_newValue)
        {
            wb_r_m_s_levels::front_right = t_newValue;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        RMSLevels(const std::string &t_str) {
            this->init();
            this->from_string(t_str);
        }

        std::string description() {
#ifdef USE_WB_R_M_S_LEVELS_C_CONVERSION
            char buffer[RMS_LEVELS_DESC_BUFFER_SIZE];
            wb_r_m_s_levels_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "rear_left=" << static_cast<signed>(this->rear_left());
            ss << ", ";
            ss << "rear_right=" << static_cast<signed>(this->rear_right());
            ss << ", ";
            ss << "front_left=" << static_cast<signed>(this->front_left());
            ss << ", ";
            ss << "front_right=" << static_cast<signed>(this->front_right());
            return ss.str();
#endif /// USE_WB_R_M_S_LEVELS_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_R_M_S_LEVELS_C_CONVERSION
            char buffer[RMS_LEVELS_TO_STRING_BUFFER_SIZE];
            wb_r_m_s_levels_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << static_cast<signed>(this->rear_left());
            ss << ", ";
            ss << static_cast<signed>(this->rear_right());
            ss << ", ";
            ss << static_cast<signed>(this->front_left());
            ss << ", ";
            ss << static_cast<signed>(this->front_right());
            return ss.str();
#endif /// USE_WB_R_M_S_LEVELS_C_CONVERSION
        }

#ifdef USE_WB_RMS_LEVELS_C_CONVERSION
        void from_string(const std::string &t_str) {
            wb_r_m_s_levels_from_string(this, t_str.c_str());
#else
        void from_string(const std::string &t_str) {
            char * str_cstr = const_cast<char *>(t_str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > RMS_LEVELS_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[RMS_LEVELS_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[12];
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
                    if (0 == strcmp("rear_left", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("rear_right", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("front_left", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("front_right", key)) {
                        varIndex = 3;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        this->set_rear_left(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 1:
                    {
                        this->set_rear_right(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 2:
                    {
                        this->set_front_left(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_front_right(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_RMS_LEVELS_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard

#endif /// RMSLevels_DEFINED
