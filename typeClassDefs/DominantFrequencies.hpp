/*
 * file DominantFrequencies.hpp
 *
 * This file was generated by classgenerator from dominant_frequencies.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2021 Rene Hexel. All rights reserved.
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

#ifndef guWhiteboard_DominantFrequencies_h
#define guWhiteboard_DominantFrequencies_h

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_dominant_frequencies.h"

#undef guWhiteboard_DominantFrequencies_DEFINED
#define guWhiteboard_DominantFrequencies_DEFINED

#undef DominantFrequencies_DEFINED
#define DominantFrequencies_DEFINED

#include "MicrophoneFrequencies.h"
#include "RMSLevels.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_dominant_frequencies`.
     */
    class DominantFrequencies: public wb_dominant_frequencies {

    private:

        /**
         * Set the members of the class.
         */
        void init(struct wb_r_m_s_levels t_rms = wb_r_m_s_levels(), const struct wb_microphone_frequencies t_frequencies[DOMINANT_NUMFREQi] = NULLPTR) {
            set_rms(t_rms);
            if (t_frequencies != NULLPTR) {
                std::memcpy(wb_dominant_frequencies::frequencies, t_frequencies, DOMINANT_FREQUENCIES_FREQUENCIES_ARRAY_SIZE * sizeof (struct wb_microphone_frequencies));
            } else {
                struct wb_microphone_frequencies frequencies_temp[DOMINANT_FREQUENCIES_FREQUENCIES_ARRAY_SIZE] = {};
                std::memcpy(wb_dominant_frequencies::frequencies, frequencies_temp, DOMINANT_FREQUENCIES_FREQUENCIES_ARRAY_SIZE * sizeof (struct wb_microphone_frequencies));
            }
        }

    public:

        /**
         * Create a new `DominantFrequencies`.
         */
        DominantFrequencies(struct wb_r_m_s_levels t_rms = wb_r_m_s_levels(), const struct wb_microphone_frequencies t_frequencies[DOMINANT_NUMFREQi] = NULLPTR) {
            this->init(t_rms, t_frequencies);
        }

        /**
         * Copy Constructor.
         */
        DominantFrequencies(const DominantFrequencies &t_other): wb_dominant_frequencies() {
            this->init(t_other.rms(), t_other.frequencies());
        }

        /**
         * Copy Constructor.
         */
        DominantFrequencies(const struct wb_dominant_frequencies &t_other): wb_dominant_frequencies() {
            this->init(t_other.rms, t_other.frequencies);
        }

        /**
         * Copy Assignment Operator.
         */
        DominantFrequencies &operator = (const DominantFrequencies &t_other) {
            this->init(t_other.rms(), t_other.frequencies());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        DominantFrequencies &operator = (const struct wb_dominant_frequencies &t_other) {
            this->init(t_other.rms, t_other.frequencies);
            return *this;
        }

        bool operator ==(const DominantFrequencies &t_other) const
        {
            if (!(RMSLevels(rms()) == RMSLevels(t_other.rms())))
            {
                return false;
            }
            for (int frequencies_0_index = 0; frequencies_0_index < DOMINANT_NUMFREQi; frequencies_0_index++)
            {
                if (!(MicrophoneFrequencies(frequencies(frequencies_0_index)) == MicrophoneFrequencies(t_other.frequencies(frequencies_0_index)))) return false;
            }
            return true;
        }

        bool operator !=(const DominantFrequencies &t_other) const
        {
            return !(*this == t_other);
        }

        bool operator ==(const wb_dominant_frequencies &t_other) const
        {
            return *this == DominantFrequencies(t_other);
        }

        bool operator !=(const wb_dominant_frequencies &t_other) const
        {
            return !(*this == t_other);
        }

        RMSLevels & rms()
        {
            return const_cast<RMSLevels &>(static_cast<const RMSLevels &>(wb_dominant_frequencies::rms));
        }

        const RMSLevels & rms() const
        {
            return static_cast<const RMSLevels &>(wb_dominant_frequencies::rms);
        }

        void set_rms(const RMSLevels &t_newValue)
        {
            wb_dominant_frequencies::rms = static_cast<wb_r_m_s_levels>(t_newValue);
        }

        const MicrophoneFrequencies * frequencies() const
        {
            return static_cast<const MicrophoneFrequencies *>(&(wb_dominant_frequencies::frequencies[0]));
        }

        size_t frequencies_size() const
        {
            return DOMINANT_FREQUENCIES_FREQUENCIES_ARRAY_SIZE;
        }

        MicrophoneFrequencies & frequencies(int t_i)
        {
            return const_cast<MicrophoneFrequencies &>(static_cast<const MicrophoneFrequencies &>(wb_dominant_frequencies::frequencies[t_i]));
        }

        const MicrophoneFrequencies & frequencies(int t_i) const
        {
            return static_cast<const MicrophoneFrequencies &>(wb_dominant_frequencies::frequencies[t_i]);
        }

        void set_frequencies(const MicrophoneFrequencies *t_newValue)
        {
            memcpy(wb_dominant_frequencies::frequencies, static_cast<const struct wb_microphone_frequencies *>(t_newValue), DOMINANT_FREQUENCIES_FREQUENCIES_ARRAY_SIZE * (sizeof (struct wb_microphone_frequencies)));
        }

        void set_frequencies(const MicrophoneFrequencies &t_newValue, int t_i)
        {
            wb_dominant_frequencies::frequencies[t_i] = static_cast<wb_microphone_frequencies>(t_newValue);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        DominantFrequencies(const std::string &t_str) {
            this->init();
            this->from_string(t_str);
        }

        std::string description() {
#ifdef USE_WB_DOMINANT_FREQUENCIES_C_CONVERSION
            char buffer[DOMINANT_FREQUENCIES_DESC_BUFFER_SIZE];
            wb_dominant_frequencies_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "rms=" << "{" << RMSLevels(this->rms()).description() << "}";
            ss << ", ";
            bool frequencies_first = true;
            ss << "frequencies={";
            for (int i = 0; i < DOMINANT_FREQUENCIES_FREQUENCIES_ARRAY_SIZE; i++) {
                ss << (frequencies_first ? "" : ", ") << "{" << MicrophoneFrequencies(this->frequencies(i)).description() << "}";
                frequencies_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_DOMINANT_FREQUENCIES_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_DOMINANT_FREQUENCIES_C_CONVERSION
            char buffer[DOMINANT_FREQUENCIES_TO_STRING_BUFFER_SIZE];
            wb_dominant_frequencies_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << "{" << RMSLevels(this->rms()).to_string() << "}";
            ss << ", ";
            bool frequencies_first = true;
            ss << "{";
            for (int i = 0; i < DOMINANT_FREQUENCIES_FREQUENCIES_ARRAY_SIZE; i++) {
                ss << (frequencies_first ? "" : ", ") << "{" << MicrophoneFrequencies(this->frequencies(i)).to_string() << "}";
                frequencies_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_DOMINANT_FREQUENCIES_C_CONVERSION
        }

#ifdef USE_WB_DOMINANT_FREQUENCIES_C_CONVERSION
        void from_string(const std::string &t_str) {
            wb_dominant_frequencies_from_string(this, t_str.c_str());
#else
        void from_string(const std::string &t_str) {
            char * str_cstr = const_cast<char *>(t_str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > DOMINANT_FREQUENCIES_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[DOMINANT_FREQUENCIES_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[12];
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
                    if (0 == strcmp("rms", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("frequencies", key)) {
                        varIndex = 1;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        RMSLevels rms_temp = RMSLevels();
                        rms_temp.from_string(var_str);
                        this->set_rms(rms_temp);
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
                        for (int frequencies_0_index = 0; frequencies_0_index < DOMINANT_FREQUENCIES_FREQUENCIES_ARRAY_SIZE; frequencies_0_index++) {
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
                            MicrophoneFrequencies frequencies_0_temp = MicrophoneFrequencies();
                            frequencies_0_temp.from_string(var_str);
                            struct wb_microphone_frequencies frequencies_0 = frequencies_0_temp;
                            this->set_frequencies(frequencies_0, frequencies_0_index);
                        }
                        index = restartIndex;
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_DOMINANT_FREQUENCIES_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

        static int num_frequencies() { return DOMINANT_NUMFREQi; }
    };

} /// namespace guWhiteboard

#endif /// guWhiteboard_DominantFrequencies_h
