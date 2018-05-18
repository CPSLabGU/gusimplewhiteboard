/*
 * file VisionDetectionHorizons.h
 *
 * This file was generated by classgenerator from vision_detection_horizons.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 14:45, 18/05/2018.
 * Copyright © 2018 Carl Lusty. All rights reserved.
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

#ifndef VisionDetectionHorizons_DEFINED
#define VisionDetectionHorizons_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_detection_horizons.h"

#include <gusimplewhiteboard/typeClassDefs/VisionDetectionHorizon.h>

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_detection_horizons`.
     */
    class VisionDetectionHorizons: public wb_vision_detection_horizons {

    public:

        /**
         * Create a new `VisionDetectionHorizons`.
         */
        VisionDetectionHorizons(struct wb_field_horizon horizons[2] = NULLPTR) {
            if (horizons != NULLPTR) {
                std::memcpy(this->_horizons, horizons, VISION_DETECTION_HORIZONS_HORIZONS_ARRAY_SIZE * sizeof (struct wb_field_horizon));
            } else {
                struct wb_field_horizon horizons_temp[VISION_DETECTION_HORIZONS_HORIZONS_ARRAY_SIZE] = {wb_field_horizon(), wb_field_horizon()};
                std::memcpy(this->_horizons, horizons_temp, VISION_DETECTION_HORIZONS_HORIZONS_ARRAY_SIZE * sizeof (struct wb_field_horizon));
            }
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionHorizons(const VisionDetectionHorizons &other): wb_vision_detection_horizons() {
            if (other.horizons() != NULLPTR) {
                std::memcpy(this->_horizons, other.horizons(), VISION_DETECTION_HORIZONS_HORIZONS_ARRAY_SIZE * sizeof (struct wb_field_horizon));
            }
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionHorizons &operator = (const VisionDetectionHorizons &other) {
            if (other.horizons() != NULLPTR) {
                std::memcpy(this->_horizons, other.horizons(), VISION_DETECTION_HORIZONS_HORIZONS_ARRAY_SIZE * sizeof (struct wb_field_horizon));
            }
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionDetectionHorizons(const std::string &str) { wb_vision_detection_horizons_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_VISION_DETECTION_HORIZONS_C_CONVERSION
            char buffer[VISION_DETECTION_HORIZONS_DESC_BUFFER_SIZE];
            wb_vision_detection_horizons_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            bool horizons_first = true;
            ss << "horizons={";
            for (int i = 0; i < VISIONDETECTIONHORIZONS_HORIZONS_ARRAY_SIZE; i++) {
                guWhiteboard::FieldHorizon * horizons_cast = const_cast<guWhiteboard::FieldHorizon *>(static_cast<const guWhiteboard::FieldHorizon *>(&this->horizons(i)));
                ss << (horizons_first ? "" : ", ") << "{" << horizons_cast->description() << "}";
                horizons_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_HORIZONS_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_DETECTION_HORIZONS_C_CONVERSION
            char buffer[VISION_DETECTION_HORIZONS_TO_STRING_BUFFER_SIZE];
            wb_vision_detection_horizons_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            bool horizons_first = true;
            ss << "{";
            for (int i = 0; i < VISIONDETECTIONHORIZONS_HORIZONS_ARRAY_SIZE; i++) {
                guWhiteboard::FieldHorizon * horizons_cast = const_cast<guWhiteboard::FieldHorizon *>(static_cast<const guWhiteboard::FieldHorizon *>(&this->horizons(i)));
                ss << (horizons_first ? "" : ", ") << "{" << horizons_cast->to_string() << "}";
                horizons_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_HORIZONS_C_CONVERSION
        }

#ifdef USE_WB_VISION_DETECTION_HORIZONS_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_detection_horizons_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char var[255];
            unsigned long horizons_index = str.find("horizons=");
            if (horizons_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(horizons_index, str.length()).c_str(), "horizons = { %[^}]", var) == 1) {
                    std::string value = std::string(var);
                    int horizons_bracecount = 0;
                    unsigned long horizons_lastBrace = horizons_index;
                    int horizons_array_index = 0;
                    for (unsigned long horizons_loop_index = horizons_index; horizons_loop_index < str.length(); horizons_loop_index++) {
                        if (str.at(horizons_loop_index) == '{') {
                            horizons_bracecount++;
                            if (horizons_bracecount == 2) {
                                horizons_lastBrace = horizons_loop_index;
                            }
                            continue;
                        }
                        if (str.at(horizons_loop_index) == '}') {
                            horizons_bracecount--;
                            if (horizons_bracecount < 1) {
                                break;
                            }
                            if (horizons_bracecount > 1) {
                                continue;
                            }
                            std::string horizons_value = str.substr(horizons_lastBrace, horizons_loop_index - horizons_lastBrace + 1);
                            FieldHorizon horizons = FieldHorizon();
                            horizons.from_string(horizons_value);
                            set_horizons(horizons, horizons_array_index++);
                            continue;
                        }
                    }
                }
            }
#endif /// USE_WB_VISION_DETECTION_HORIZONS_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard
#endif /// VisionDetectionHorizons_DEFINED
