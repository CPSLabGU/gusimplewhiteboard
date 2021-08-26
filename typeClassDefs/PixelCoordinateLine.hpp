/*
 * file PixelCoordinateLine.hpp
 *
 * This file was generated by classgenerator from pixel_coordinate_line.gen.
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

#ifndef guWhiteboard_PixelCoordinateLine_h
#define guWhiteboard_PixelCoordinateLine_h

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_pixel_coordinate_line.h"

#undef guWhiteboard_PixelCoordinateLine_DEFINED
#define guWhiteboard_PixelCoordinateLine_DEFINED

#undef PixelCoordinateLine_DEFINED
#define PixelCoordinateLine_DEFINED

#include "PixelCoordinate.h"

#include <guunits/guunits.h>
#include <gucoordinates/gucoordinates.h>
#include "PixelCoordinate.h"

#include <guunits/guunits.h>
#include <gucoordinates/gucoordinates.h>

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_pixel_coordinate_line`.
     */
    class PixelCoordinateLine: public wb_pixel_coordinate_line {

    private:

        /**
         * Set the members of the class.
         */
        void init(struct wb_pixel_coordinate t_start = wb_pixel_coordinate(), struct wb_pixel_coordinate t_end = wb_pixel_coordinate()) {
            set_start(t_start);
            set_end(t_end);
        }

    public:

        /**
         * Create a new `PixelCoordinateLine`.
         */
        PixelCoordinateLine(struct wb_pixel_coordinate t_start = wb_pixel_coordinate(), struct wb_pixel_coordinate t_end = wb_pixel_coordinate()) {
            this->init(t_start, t_end);
        }

        /**
         * Copy Constructor.
         */
        PixelCoordinateLine(const PixelCoordinateLine &t_other): wb_pixel_coordinate_line() {
            this->init(t_other.start(), t_other.end());
        }

        /**
         * Copy Constructor.
         */
        PixelCoordinateLine(const struct wb_pixel_coordinate_line &t_other): wb_pixel_coordinate_line() {
            this->init(t_other.start, t_other.end);
        }

        /**
         * Copy Assignment Operator.
         */
        PixelCoordinateLine &operator = (const PixelCoordinateLine &t_other) {
            this->init(t_other.start(), t_other.end());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        PixelCoordinateLine &operator = (const struct wb_pixel_coordinate_line &t_other) {
            this->init(t_other.start, t_other.end);
            return *this;
        }

        bool operator ==(const PixelCoordinateLine &t_other) const
        {
            return PixelCoordinate(start()) == PixelCoordinate(t_other.start())
                && PixelCoordinate(end()) == PixelCoordinate(t_other.end());
        }

        bool operator !=(const PixelCoordinateLine &t_other) const
        {
            return !(*this == t_other);
        }

        bool operator ==(const wb_pixel_coordinate_line &t_other) const
        {
            return *this == PixelCoordinateLine(t_other);
        }

        bool operator !=(const wb_pixel_coordinate_line &t_other) const
        {
            return !(*this == t_other);
        }

        PixelCoordinate & start()
        {
            return const_cast<PixelCoordinate &>(static_cast<const PixelCoordinate &>(wb_pixel_coordinate_line::start));
        }

        const PixelCoordinate & start() const
        {
            return static_cast<const PixelCoordinate &>(wb_pixel_coordinate_line::start);
        }

        void set_start(const PixelCoordinate &t_newValue)
        {
            wb_pixel_coordinate_line::start = static_cast<wb_pixel_coordinate>(t_newValue);
        }

        PixelCoordinate & end()
        {
            return const_cast<PixelCoordinate &>(static_cast<const PixelCoordinate &>(wb_pixel_coordinate_line::end));
        }

        const PixelCoordinate & end() const
        {
            return static_cast<const PixelCoordinate &>(wb_pixel_coordinate_line::end);
        }

        void set_end(const PixelCoordinate &t_newValue)
        {
            wb_pixel_coordinate_line::end = static_cast<wb_pixel_coordinate>(t_newValue);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        PixelCoordinateLine(const std::string &t_str) {
            this->init();
            this->from_string(t_str);
        }

        std::string description() {
#ifdef USE_WB_PIXEL_COORDINATE_LINE_C_CONVERSION
            char buffer[PIXEL_COORDINATE_LINE_DESC_BUFFER_SIZE];
            wb_pixel_coordinate_line_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "start=" << "{" << PixelCoordinate(this->start()).description() << "}";
            ss << ", ";
            ss << "end=" << "{" << PixelCoordinate(this->end()).description() << "}";
            return ss.str();
#endif /// USE_WB_PIXEL_COORDINATE_LINE_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_PIXEL_COORDINATE_LINE_C_CONVERSION
            char buffer[PIXEL_COORDINATE_LINE_TO_STRING_BUFFER_SIZE];
            wb_pixel_coordinate_line_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << "{" << PixelCoordinate(this->start()).to_string() << "}";
            ss << ", ";
            ss << "{" << PixelCoordinate(this->end()).to_string() << "}";
            return ss.str();
#endif /// USE_WB_PIXEL_COORDINATE_LINE_C_CONVERSION
        }

#ifdef USE_WB_PIXEL_COORDINATE_LINE_C_CONVERSION
        void from_string(const std::string &t_str) {
            wb_pixel_coordinate_line_from_string(this, t_str.c_str());
#else
        void from_string(const std::string &t_str) {
            char * str_cstr = const_cast<char *>(t_str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > PIXEL_COORDINATE_LINE_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[PIXEL_COORDINATE_LINE_DESC_BUFFER_SIZE + 1];
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
                    if (0 == strcmp("start", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("end", key)) {
                        varIndex = 1;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        PixelCoordinate start_temp = PixelCoordinate();
                        start_temp.from_string(var_str);
                        this->set_start(start_temp);
                        break;
                    }
                    case 1:
                    {
                        PixelCoordinate end_temp = PixelCoordinate();
                        end_temp.from_string(var_str);
                        this->set_end(end_temp);
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_PIXEL_COORDINATE_LINE_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

        GU::PixelCoordinate startPixelCoordinate(const uint16_t resWidth, const uint16_t resHeight)
        {
            return PixelCoordinate(start()).pixelCoordinate(resWidth, resHeight);
        }
        GU::PixelCoordinate endPixelCoordinate(const uint16_t resWidth, const uint16_t resHeight)
        {
            return PixelCoordinate(end()).pixelCoordinate(resWidth, resHeight);
        }
    };

} /// namespace guWhiteboard

#endif /// guWhiteboard_PixelCoordinateLine_h
