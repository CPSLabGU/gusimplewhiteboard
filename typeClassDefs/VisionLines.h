/*
 * file VisionLines.h
 *
 * This file was generated by classgenerator from vision_lines.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Eugene Gilmore at 17:00, 14/08/2018.
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

#ifndef VisionLines_DEFINED
#define VisionLines_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_lines.h"

#include <gusimplewhiteboard/typeClassDefs/VisionLine.h>

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_lines`.
     */
    class VisionLines: public wb_vision_lines {

    public:

        /**
         * Create a new `VisionLines`.
         */
        VisionLines(struct wb_vision_line topLines[5] = NULLPTR, struct wb_vision_line bottomLines[5] = NULLPTR, uint8_t numTopLines = 0, uint8_t numBottomLines = 0, uint64_t frameNumber = 0) {
            if (topLines != NULLPTR) {
                std::memcpy(this->_topLines, topLines, VISION_LINES_TOPLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            } else {
                struct wb_vision_line topLines_temp[VISION_LINES_TOPLINES_ARRAY_SIZE] = {wb_vision_line(), wb_vision_line(), wb_vision_line(), wb_vision_line(), wb_vision_line()};
                std::memcpy(this->_topLines, topLines_temp, VISION_LINES_TOPLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            if (bottomLines != NULLPTR) {
                std::memcpy(this->_bottomLines, bottomLines, VISION_LINES_BOTTOMLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            } else {
                struct wb_vision_line bottomLines_temp[VISION_LINES_BOTTOMLINES_ARRAY_SIZE] = {wb_vision_line(), wb_vision_line(), wb_vision_line(), wb_vision_line(), wb_vision_line()};
                std::memcpy(this->_bottomLines, bottomLines_temp, VISION_LINES_BOTTOMLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            set_numTopLines(numTopLines);
            set_numBottomLines(numBottomLines);
            set_frameNumber(frameNumber);
        }

        /**
         * Copy Constructor.
         */
        VisionLines(const VisionLines &other): wb_vision_lines() {
            if (other.topLines() != NULLPTR) {
                std::memcpy(this->_topLines, other.topLines(), VISION_LINES_TOPLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            if (other.bottomLines() != NULLPTR) {
                std::memcpy(this->_bottomLines, other.bottomLines(), VISION_LINES_BOTTOMLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            set_numTopLines(other.numTopLines());
            set_numBottomLines(other.numBottomLines());
            set_frameNumber(other.frameNumber());
        }

        /**
         * Copy Constructor.
         */
        VisionLines(const struct wb_vision_lines &other): wb_vision_lines() {
            if (other.topLines() != NULLPTR) {
                std::memcpy(this->_topLines, other.topLines(), VISION_LINES_TOPLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            if (other.bottomLines() != NULLPTR) {
                std::memcpy(this->_bottomLines, other.bottomLines(), VISION_LINES_BOTTOMLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            set_numTopLines(other.numTopLines());
            set_numBottomLines(other.numBottomLines());
            set_frameNumber(other.frameNumber());
        }

        /**
         * Copy Assignment Operator.
         */
        VisionLines &operator = (const VisionLines &other) {
            if (other.topLines() != NULLPTR) {
                std::memcpy(this->_topLines, other.topLines(), VISION_LINES_TOPLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            if (other.bottomLines() != NULLPTR) {
                std::memcpy(this->_bottomLines, other.bottomLines(), VISION_LINES_BOTTOMLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            set_numTopLines(other.numTopLines());
            set_numBottomLines(other.numBottomLines());
            set_frameNumber(other.frameNumber());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        VisionLines &operator = (const struct wb_vision_lines &other) {
            if (other.topLines() != NULLPTR) {
                std::memcpy(this->_topLines, other.topLines(), VISION_LINES_TOPLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            if (other.bottomLines() != NULLPTR) {
                std::memcpy(this->_bottomLines, other.bottomLines(), VISION_LINES_BOTTOMLINES_ARRAY_SIZE * sizeof (struct wb_vision_line));
            }
            set_numTopLines(other.numTopLines());
            set_numBottomLines(other.numBottomLines());
            set_frameNumber(other.frameNumber());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionLines(const std::string &str) { wb_vision_lines_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_VISION_LINES_C_CONVERSION
            char buffer[VISION_LINES_DESC_BUFFER_SIZE];
            wb_vision_lines_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            bool topLines_first = true;
            ss << "topLines={";
            for (int i = 0; i < VISION_LINES_TOPLINES_ARRAY_SIZE; i++) {
                guWhiteboard::VisionLine * topLines_cast = const_cast<guWhiteboard::VisionLine *>(static_cast<const guWhiteboard::VisionLine *>(&this->topLines(i)));
                ss << (topLines_first ? "" : ", ") << "{" << topLines_cast->description() << "}";
                topLines_first = false;
            }
            ss << "}";
            ss << ", ";
            bool bottomLines_first = true;
            ss << "bottomLines={";
            for (int i = 0; i < VISION_LINES_BOTTOMLINES_ARRAY_SIZE; i++) {
                guWhiteboard::VisionLine * bottomLines_cast = const_cast<guWhiteboard::VisionLine *>(static_cast<const guWhiteboard::VisionLine *>(&this->bottomLines(i)));
                ss << (bottomLines_first ? "" : ", ") << "{" << bottomLines_cast->description() << "}";
                bottomLines_first = false;
            }
            ss << "}";
            ss << ", ";
            ss << "numTopLines=" << static_cast<unsigned>(this->numTopLines());
            ss << ", ";
            ss << "numBottomLines=" << static_cast<unsigned>(this->numBottomLines());
            ss << ", ";
            ss << "frameNumber=" << this->frameNumber();
            return ss.str();
#endif /// USE_WB_VISION_LINES_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_LINES_C_CONVERSION
            char buffer[VISION_LINES_TO_STRING_BUFFER_SIZE];
            wb_vision_lines_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            bool topLines_first = true;
            ss << "{";
            for (int i = 0; i < VISION_LINES_TOPLINES_ARRAY_SIZE; i++) {
                guWhiteboard::VisionLine * topLines_cast = const_cast<guWhiteboard::VisionLine *>(static_cast<const guWhiteboard::VisionLine *>(&this->topLines(i)));
                ss << (topLines_first ? "" : ", ") << "{" << topLines_cast->to_string() << "}";
                topLines_first = false;
            }
            ss << "}";
            ss << ", ";
            bool bottomLines_first = true;
            ss << "{";
            for (int i = 0; i < VISION_LINES_BOTTOMLINES_ARRAY_SIZE; i++) {
                guWhiteboard::VisionLine * bottomLines_cast = const_cast<guWhiteboard::VisionLine *>(static_cast<const guWhiteboard::VisionLine *>(&this->bottomLines(i)));
                ss << (bottomLines_first ? "" : ", ") << "{" << bottomLines_cast->to_string() << "}";
                bottomLines_first = false;
            }
            ss << "}";
            ss << ", ";
            ss << static_cast<unsigned>(this->numTopLines());
            ss << ", ";
            ss << static_cast<unsigned>(this->numBottomLines());
            ss << ", ";
            ss << this->frameNumber();
            return ss.str();
#endif /// USE_WB_VISION_LINES_C_CONVERSION
        }

#ifdef USE_WB_VISION_LINES_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_lines_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1) {
                return;
            }
            char var_str_buffer[VISION_LINES_TO_STRING_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[15];
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
                    if (0 == strcmp("topLines", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("bottomLines", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("numTopLines", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("numBottomLines", key)) {
                        varIndex = 3;
                    } else if (0 == strcmp("frameNumber", key)) {
                        varIndex = 4;
                    }
                }
                switch (varIndex) {
                    case 0:
                    {
                        int restartIndex = index;
                        index = lastBrace + 1;
                        startVar = index;
                        startKey = startVar;
                        endKey = -1;
                        bracecount = 0;
                        for (int topLines_0_index = 0; topLines_0_index < VISION_LINES_TOPLINES_ARRAY_SIZE; topLines_0_index++) {
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
                            VisionLine topLines_0_temp = VisionLine();
                            topLines_0_temp.from_string(var_str);
                            struct wb_vision_line topLines_0 = topLines_0_temp;
                            this->set_topLines(topLines_0, topLines_0_index);;
                        }
                        index = restartIndex;
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
                        for (int bottomLines_0_index = 0; bottomLines_0_index < VISION_LINES_BOTTOMLINES_ARRAY_SIZE; bottomLines_0_index++) {
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
                            VisionLine bottomLines_0_temp = VisionLine();
                            bottomLines_0_temp.from_string(var_str);
                            struct wb_vision_line bottomLines_0 = bottomLines_0_temp;
                            this->set_bottomLines(bottomLines_0, bottomLines_0_index);;
                        }
                        index = restartIndex;
                        break;
                    }
                    case 2:
                    {
                        this->set_numTopLines(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_numBottomLines(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 4:
                    {
                        this->set_frameNumber(static_cast<uint64_t>(atoll(var_str)));
                        break;
                    }
                }
                varIndex++;
            } while(index < length);
#endif /// USE_WB_VISION_LINES_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard
#endif /// VisionLines_DEFINED
