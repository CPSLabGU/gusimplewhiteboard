/*
 * file Input3D.h
 *
 * This file was generated by classgenerator from Input3D.txt.
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

#ifndef Input3D_DEFINED
#define Input3D_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_input3d.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_input3d`.
     */
    class Input3D: public wb_input3d {

    private:

        /**
         * Set the members of the class.
         */
        void init(int16_t yaw = 0, int16_t pitch = 0, int16_t roll = 0, int16_t power = 0) {
            set_yaw(yaw);
            set_pitch(pitch);
            set_roll(roll);
            set_power(power);
        }

    public:

        /**
         * Create a new `Input3D`.
         */
        Input3D(int16_t yaw = 0, int16_t pitch = 0, int16_t roll = 0, int16_t power = 0) {
            this->init(yaw, pitch, roll, power);
        }

        /**
         * Copy Constructor.
         */
        Input3D(const Input3D &other): wb_input3d() {
            this->init(other.yaw(), other.pitch(), other.roll(), other.power());
        }

        /**
         * Copy Constructor.
         */
        Input3D(const struct wb_input3d &other): wb_input3d() {
            this->init(other.yaw(), other.pitch(), other.roll(), other.power());
        }

        /**
         * Copy Assignment Operator.
         */
        Input3D &operator = (const Input3D &other) {
            this->init(other.yaw(), other.pitch(), other.roll(), other.power());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        Input3D &operator = (const struct wb_input3d &other) {
            this->init(other.yaw(), other.pitch(), other.roll(), other.power());
            return *this;
        }

        bool operator ==(const Input3D &other) const
        {
            return yaw() == other.yaw()
                && pitch() == other.pitch()
                && roll() == other.roll()
                && power() == other.power();
        }

        bool operator !=(const Input3D &other) const
        {
            return !(*this == other);
        }

        bool operator ==(const wb_input3d &other) const
        {
            return *this == Input3D(other);
        }

        bool operator !=(const wb_input3d &other) const
        {
            return !(*this == other);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        Input3D(const std::string &str) {
            this->init();
            this->from_string(str);
        }

        std::string description() {
#ifdef USE_WB_INPUT3D_C_CONVERSION
            char buffer[INPUT3D_DESC_BUFFER_SIZE];
            wb_input3d_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "yaw=" << static_cast<signed>(this->yaw());
            ss << ", ";
            ss << "pitch=" << static_cast<signed>(this->pitch());
            ss << ", ";
            ss << "roll=" << static_cast<signed>(this->roll());
            ss << ", ";
            ss << "power=" << static_cast<signed>(this->power());
            return ss.str();
#endif /// USE_WB_INPUT3D_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_INPUT3D_C_CONVERSION
            char buffer[INPUT3D_TO_STRING_BUFFER_SIZE];
            wb_input3d_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << static_cast<signed>(this->yaw());
            ss << ", ";
            ss << static_cast<signed>(this->pitch());
            ss << ", ";
            ss << static_cast<signed>(this->roll());
            ss << ", ";
            ss << static_cast<signed>(this->power());
            return ss.str();
#endif /// USE_WB_INPUT3D_C_CONVERSION
        }

#ifdef USE_WB_INPUT3D_C_CONVERSION
        void from_string(const std::string &str) {
            wb_input3d_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > INPUT3D_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[INPUT3D_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[6];
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
                    if (0 == strcmp("yaw", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("pitch", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("roll", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("power", key)) {
                        varIndex = 3;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        this->set_yaw(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 1:
                    {
                        this->set_pitch(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 2:
                    {
                        this->set_roll(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_power(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_INPUT3D_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard

#endif /// Input3D_DEFINED
