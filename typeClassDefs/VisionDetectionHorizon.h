/*
 * file VisionDetectionHorizon.h
 *
 * This file was generated by classgenerator from vision_detection_horizon.gen.
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

#ifndef VisionDetectionHorizon_DEFINED
#define VisionDetectionHorizon_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_detection_horizon.h"

#include "PixelCoordinate.h"

#include <guunits/guunits.h>
#include <gucoordinates/gucoordinates.h>
#include "PixelCoordinate.h"

#include <guunits/guunits.h>
#include <gucoordinates/gucoordinates.h>
#include "PixelCoordinate.h"

#include <guunits/guunits.h>
#include <gucoordinates/gucoordinates.h>

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_detection_horizon`.
     */
    class VisionDetectionHorizon: public wb_vision_detection_horizon {

    private:

        /**
         * Set the members of the class.
         */
        void init(enum HorizonOptions horizonType = HorizonFailed, struct wb_pixel_coordinate leftCoordinate = wb_pixel_coordinate(), struct wb_pixel_coordinate centerCoordinate = wb_pixel_coordinate(), struct wb_pixel_coordinate rightCoordinate = wb_pixel_coordinate()) {
            set_horizonType(horizonType);
            set_leftCoordinate(leftCoordinate);
            set_centerCoordinate(centerCoordinate);
            set_rightCoordinate(rightCoordinate);
        }

    public:

        /**
         * Create a new `VisionDetectionHorizon`.
         */
        VisionDetectionHorizon(enum HorizonOptions horizonType = HorizonFailed, struct wb_pixel_coordinate leftCoordinate = wb_pixel_coordinate(), struct wb_pixel_coordinate centerCoordinate = wb_pixel_coordinate(), struct wb_pixel_coordinate rightCoordinate = wb_pixel_coordinate()) {
            this->init(horizonType, leftCoordinate, centerCoordinate, rightCoordinate);
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionHorizon(const VisionDetectionHorizon &other): wb_vision_detection_horizon() {
            this->init(other.horizonType(), other.leftCoordinate(), other.centerCoordinate(), other.rightCoordinate());
        }

        /**
         * Copy Constructor.
         */
        VisionDetectionHorizon(const struct wb_vision_detection_horizon &other): wb_vision_detection_horizon() {
            this->init(other.horizonType(), other.leftCoordinate(), other.centerCoordinate(), other.rightCoordinate());
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionHorizon &operator = (const VisionDetectionHorizon &other) {
            this->init(other.horizonType(), other.leftCoordinate(), other.centerCoordinate(), other.rightCoordinate());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        VisionDetectionHorizon &operator = (const struct wb_vision_detection_horizon &other) {
            this->init(other.horizonType(), other.leftCoordinate(), other.centerCoordinate(), other.rightCoordinate());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionDetectionHorizon(const std::string &str) {
            this->init();
            this->from_string(str);
        }

        std::string description() {
#ifdef USE_WB_VISION_DETECTION_HORIZON_C_CONVERSION
            char buffer[VISION_DETECTION_HORIZON_DESC_BUFFER_SIZE];
            wb_vision_detection_horizon_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            switch (this->horizonType()) {
                case CornerHorizon:
                {
                    ss << "horizonType=" << "CornerHorizon";
                    break;
                }
                case HorizonFailed:
                {
                    ss << "horizonType=" << "HorizonFailed";
                    break;
                }
                case OnlyField:
                {
                    ss << "horizonType=" << "OnlyField";
                    break;
                }
                case SingleHorizon:
                {
                    ss << "horizonType=" << "SingleHorizon";
                    break;
                }
            }
            ss << ", ";
            guWhiteboard::PixelCoordinate * leftCoordinate_cast = const_cast<guWhiteboard::PixelCoordinate *>(static_cast<const guWhiteboard::PixelCoordinate *>(&this->leftCoordinate()));
            ss << "leftCoordinate=" << "{" << leftCoordinate_cast->description() << "}";
            ss << ", ";
            guWhiteboard::PixelCoordinate * centerCoordinate_cast = const_cast<guWhiteboard::PixelCoordinate *>(static_cast<const guWhiteboard::PixelCoordinate *>(&this->centerCoordinate()));
            ss << "centerCoordinate=" << "{" << centerCoordinate_cast->description() << "}";
            ss << ", ";
            guWhiteboard::PixelCoordinate * rightCoordinate_cast = const_cast<guWhiteboard::PixelCoordinate *>(static_cast<const guWhiteboard::PixelCoordinate *>(&this->rightCoordinate()));
            ss << "rightCoordinate=" << "{" << rightCoordinate_cast->description() << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_HORIZON_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_DETECTION_HORIZON_C_CONVERSION
            char buffer[VISION_DETECTION_HORIZON_TO_STRING_BUFFER_SIZE];
            wb_vision_detection_horizon_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            switch (this->horizonType()) {
                case CornerHorizon:
                {
                    ss << "CornerHorizon";
                    break;
                }
                case HorizonFailed:
                {
                    ss << "HorizonFailed";
                    break;
                }
                case OnlyField:
                {
                    ss << "OnlyField";
                    break;
                }
                case SingleHorizon:
                {
                    ss << "SingleHorizon";
                    break;
                }
            }
            ss << ", ";
            guWhiteboard::PixelCoordinate * leftCoordinate_cast = const_cast<guWhiteboard::PixelCoordinate *>(static_cast<const guWhiteboard::PixelCoordinate *>(&this->leftCoordinate()));
            ss << "{" << leftCoordinate_cast->to_string() << "}";
            ss << ", ";
            guWhiteboard::PixelCoordinate * centerCoordinate_cast = const_cast<guWhiteboard::PixelCoordinate *>(static_cast<const guWhiteboard::PixelCoordinate *>(&this->centerCoordinate()));
            ss << "{" << centerCoordinate_cast->to_string() << "}";
            ss << ", ";
            guWhiteboard::PixelCoordinate * rightCoordinate_cast = const_cast<guWhiteboard::PixelCoordinate *>(static_cast<const guWhiteboard::PixelCoordinate *>(&this->rightCoordinate()));
            ss << "{" << rightCoordinate_cast->to_string() << "}";
            return ss.str();
#endif /// USE_WB_VISION_DETECTION_HORIZON_C_CONVERSION
        }

#ifdef USE_WB_VISION_DETECTION_HORIZON_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_detection_horizon_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > VISION_DETECTION_HORIZON_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[VISION_DETECTION_HORIZON_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[17];
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
                    if (0 == strcmp("horizonType", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("leftCoordinate", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("centerCoordinate", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("rightCoordinate", key)) {
                        varIndex = 3;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        if (strcmp("CornerHorizon", var_str) == 0) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_horizonType(CornerHorizon);
#pragma clang diagnostic pop
                        } else if (strcmp("HorizonFailed", var_str) == 0) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_horizonType(HorizonFailed);
#pragma clang diagnostic pop
                        } else if (strcmp("OnlyField", var_str) == 0) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_horizonType(OnlyField);
#pragma clang diagnostic pop
                        } else if (strcmp("SingleHorizon", var_str) == 0) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_horizonType(SingleHorizon);
#pragma clang diagnostic pop
                        } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast"
                        this->set_horizonType(static_cast<enum HorizonOptions>(atoi(var_str)));
#pragma clang diagnostic pop
                        }
                        break;
                    }
                    case 1:
                    {
                        PixelCoordinate leftCoordinate_temp = PixelCoordinate();
                        leftCoordinate_temp.from_string(var_str);
                        this->set_leftCoordinate(leftCoordinate_temp);
                        break;
                    }
                    case 2:
                    {
                        PixelCoordinate centerCoordinate_temp = PixelCoordinate();
                        centerCoordinate_temp.from_string(var_str);
                        this->set_centerCoordinate(centerCoordinate_temp);
                        break;
                    }
                    case 3:
                    {
                        PixelCoordinate rightCoordinate_temp = PixelCoordinate();
                        rightCoordinate_temp.from_string(var_str);
                        this->set_rightCoordinate(rightCoordinate_temp);
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_VISION_DETECTION_HORIZON_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

        GU::PixelCoordinate leftCoordinatePixelCoordinate(const uint16_t resWidth, const uint16_t resHeight)
        {
            return PixelCoordinate(leftCoordinate()).pixelCoordinate(resWidth, resHeight);
        }
        GU::PixelCoordinate centerCoordinatePixelCoordinate(const uint16_t resWidth, const uint16_t resHeight)
        {
            return PixelCoordinate(centerCoordinate()).pixelCoordinate(resWidth, resHeight);
        }
        GU::PixelCoordinate rightCoordinatePixelCoordinate(const uint16_t resWidth, const uint16_t resHeight)
        {
            return PixelCoordinate(rightCoordinate()).pixelCoordinate(resWidth, resHeight);
        }
    };

} /// namespace guWhiteboard

#endif /// VisionDetectionHorizon_DEFINED
