/*
 * file VisionDetectionLineArray.h
 *
 * This file was generated by classgenerator from vision_detection_line_array.gen.
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

#ifndef guWhiteboard_VisionDetectionLineArray_h
#define guWhiteboard_VisionDetectionLineArray_h

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_detection_line_array.h"

#undef guWhiteboard_VisionDetectionLineArray_DEFINED
#define guWhiteboard_VisionDetectionLineArray_DEFINED

#undef VisionDetectionLineArray_DEFINED
#define VisionDetectionLineArray_DEFINED

#include <gusimplewhiteboard/typeClassDefs/PixelCoordinateLine.h>

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_detection_line_array`.
     */
    class VisionDetectionLineArray: public wb_vision_detection_line_array {

    private:

        /**
         * Set the members of the class.
         */
        void init(uint8_t t_numLines = 0, const struct wb_pixel_coordinate_line t_lines[7] = NULLPTR) {
            set_numLines(t_numLines);
            if (t_lines != NULLPTR) {
                std::memcpy(wb_vision_detection_line_array::lines, t_lines, VISION_DETECTION_LINE_ARRAY_LINES_ARRAY_SIZE * sizeof (struct wb_pixel_coordinate_line));
            } else {
                struct wb_pixel_coordinate_line lines_temp[VISION_DETECTION_LINE_ARRAY_LINES_ARRAY_SIZE] = {wb_pixel_coordinate_line(), wb_pixel_coordinate_line(), wb_pixel_coordinate_line(), wb_pixel_coordinate_line(), wb_pixel_coordinate_line(), wb_pixel_coordinate_line(), wb_pixel_coordinate_line()};
                std::memcpy(wb_vision_detection_line_array::lines, lines_temp, VISION_DETECTION_LINE_ARRAY_LINES_ARRAY_SIZE * sizeof (struct wb_pixel_coordinate_line));
            }
        }

    public:

        /**
         * Create a new `VisionDetectionLineArray`.
         */
        VisionDetectionLineArray(uint8_t t_numLines = 0, const struct wb_pixel_coordinate_line t_lines[7] = NULLPTR) {
            this->init(t_numLines, t_lines);
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionLineArray(const VisionDetectionLineArray &t_other): wb_vision_detection_line_array() {
            this->init(t_other.numLines(), t_other.lines());
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionLineArray(const struct wb_vision_detection_line_array &t_other): wb_vision_detection_line_array() {
            this->init(t_other.numLines, t_other.lines);
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionLineArray &operator = (const VisionDetectionLineArray &t_other) {
            this->init(t_other.numLines(), t_other.lines());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionLineArray &operator = (const struct wb_vision_detection_line_array &t_other) {
            this->init(t_other.numLines, t_other.lines);
            return *this;
        }

        bool operator ==(const VisionDetectionLineArray &t_other) const
        {
            if (!(numLines() == t_other.numLines()))
            {
                return false;
            }
            for (int lines_0_index = 0; lines_0_index < 7; lines_0_index++)
            {
                if (!(PixelCoordinateLine(lines(lines_0_index)) == PixelCoordinateLine(t_other.lines(lines_0_index)))) return false;
            }
            return true;
        }

        bool operator !=(const VisionDetectionLineArray &t_other) const
        {
            return !(*this == t_other);
        }

        bool operator ==(const wb_vision_detection_line_array &t_other) const
        {
            return *this == VisionDetectionLineArray(t_other);
        }

        bool operator !=(const wb_vision_detection_line_array &t_other) const
        {
            return !(*this == t_other);
        }

        uint8_t & numLines()
        {
            return wb_vision_detection_line_array::numLines;
        }

        const uint8_t & numLines() const
        {
            return wb_vision_detection_line_array::numLines;
        }

        void set_numLines(const uint8_t &t_newValue)
        {
            wb_vision_detection_line_array::numLines = t_newValue;
        }

        const PixelCoordinateLine * lines() const
        {
            return static_cast<const PixelCoordinateLine *>(&(wb_vision_detection_line_array::lines[0]));
        }

        size_t lines_size() const
        {
            return VISION_DETECTION_LINE_ARRAY_LINES_ARRAY_SIZE;
        }

        PixelCoordinateLine & lines(int t_i)
        {
            return const_cast<PixelCoordinateLine &>(static_cast<const PixelCoordinateLine &>(wb_vision_detection_line_array::lines[t_i]));
        }

        const PixelCoordinateLine & lines(int t_i) const
        {
            return static_cast<const PixelCoordinateLine &>(wb_vision_detection_line_array::lines[t_i]);
        }

        void set_lines(const PixelCoordinateLine *t_newValue)
        {
            memcpy(wb_vision_detection_line_array::lines, static_cast<const struct wb_pixel_coordinate_line *>(t_newValue), VISION_DETECTION_LINE_ARRAY_LINES_ARRAY_SIZE * (sizeof (struct wb_pixel_coordinate_line)));
        }

        void set_lines(const PixelCoordinateLine &t_newValue, int t_i)
        {
            wb_vision_detection_line_array::lines[t_i] = static_cast<wb_pixel_coordinate_line>(t_newValue);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionDetectionLineArray(const std::string &t_str) {
            this->init();
            this->from_string(t_str);
        }

        std::string description() {
#ifdef USE_WB_VISION_DETECTION_LINE_ARRAY_C_CONVERSION
            char buffer[VISION_DETECTION_LINE_ARRAY_DESC_BUFFER_SIZE];
            wb_vision_detection_line_array_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "numLines=" << static_cast<unsigned>(this->numLines());
            ss << ", ";
            bool lines_first = true;
            ss << "lines={";
            for (int i = 0; i < VISION_DETECTION_LINE_ARRAY_LINES_ARRAY_SIZE; i++) {
                ss << (lines_first ? "" : ", ") << "{" << PixelCoordinateLine(this->lines(i)).description() << "}";
                lines_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_LINE_ARRAY_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_DETECTION_LINE_ARRAY_C_CONVERSION
            char buffer[VISION_DETECTION_LINE_ARRAY_TO_STRING_BUFFER_SIZE];
            wb_vision_detection_line_array_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << static_cast<unsigned>(this->numLines());
            ss << ", ";
            bool lines_first = true;
            ss << "{";
            for (int i = 0; i < VISION_DETECTION_LINE_ARRAY_LINES_ARRAY_SIZE; i++) {
                ss << (lines_first ? "" : ", ") << "{" << PixelCoordinateLine(this->lines(i)).to_string() << "}";
                lines_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_LINE_ARRAY_C_CONVERSION
        }

#ifdef USE_WB_VISION_DETECTION_LINE_ARRAY_C_CONVERSION
        void from_string(const std::string &t_str) {
            wb_vision_detection_line_array_from_string(this, t_str.c_str());
#else
        void from_string(const std::string &t_str) {
            char * str_cstr = const_cast<char *>(t_str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > VISION_DETECTION_LINE_ARRAY_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[VISION_DETECTION_LINE_ARRAY_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[9];
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
                    if (0 == strcmp("numLines", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("lines", key)) {
                        varIndex = 1;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        this->set_numLines(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 1:
                    {
                        int restartIndex = index;
                        index = lastBrace + 1;
                        startVar = index;
                        startKey = startVar;
                        endKey = -1;
                        bracecount = 0;
                        for (int lines_0_index = 0; lines_0_index < VISION_DETECTION_LINE_ARRAY_LINES_ARRAY_SIZE; lines_0_index++) {
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
                            PixelCoordinateLine lines_0_temp = PixelCoordinateLine();
                            lines_0_temp.from_string(var_str);
                            struct wb_pixel_coordinate_line lines_0 = lines_0_temp;
                            this->set_lines(lines_0, lines_0_index);
                        }
                        index = restartIndex;
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_VISION_DETECTION_LINE_ARRAY_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard

#endif /// guWhiteboard_VisionDetectionLineArray_h
