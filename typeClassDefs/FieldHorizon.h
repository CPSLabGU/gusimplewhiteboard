/*
 * file FieldHorizon.h
 *
 * This file was generated by classgenerator from fieldHorizon.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 03:54, 30/09/2017.
 * Copyright © 2017 Carl Lusty. All rights reserved.
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

#ifndef FieldHorizon_DEFINED
#define FieldHorizon_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include "gu_util.h"
#include "wb_field_horizon.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_field_horizon`.
     */
    class FieldHorizon: public wb_field_horizon {

    public:

        /**
         * Create a new `FieldHorizon`.
         */
        FieldHorizon(HorizonOptions horizonType = HorizonFailed, uint16_t lhp_x = 0, uint16_t lhp_y = 0, uint16_t rhp_x = 0, uint16_t rhp_y = 0, uint16_t chp_x = 0, uint16_t chp_y = 0) {
            set_horizonType(horizonType);
            set_lhp_x(lhp_x);
            set_lhp_y(lhp_y);
            set_rhp_x(rhp_x);
            set_rhp_y(rhp_y);
            set_chp_x(chp_x);
            set_chp_y(chp_y);
        }

        /**
         * Copy Constructor.
         */
        FieldHorizon(const FieldHorizon &other): wb_field_horizon() {
            set_horizonType(other.horizonType());
            set_lhp_x(other.lhp_x());
            set_lhp_y(other.lhp_y());
            set_rhp_x(other.rhp_x());
            set_rhp_y(other.rhp_y());
            set_chp_x(other.chp_x());
            set_chp_y(other.chp_y());
        }

        /**
         * Copy Assignment Operator.
         */
        FieldHorizon &operator = (const FieldHorizon &other) {
            set_horizonType(other.horizonType());
            set_lhp_x(other.lhp_x());
            set_lhp_y(other.lhp_y());
            set_rhp_x(other.rhp_x());
            set_rhp_y(other.rhp_y());
            set_chp_x(other.chp_x());
            set_chp_y(other.chp_y());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        FieldHorizon(const std::string &str) { wb_field_horizon_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_FIELD_HORIZON_C_CONVERSION
            char buffer[FIELDHORIZON_DESC_BUFFER_SIZE];
            wb_field_horizon_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "horizonType=" << this->horizonType();
            ss << ", ";
            ss << "lhp_x=" << this->lhp_x();
            ss << ", ";
            ss << "lhp_y=" << this->lhp_y();
            ss << ", ";
            ss << "rhp_x=" << this->rhp_x();
            ss << ", ";
            ss << "rhp_y=" << this->rhp_y();
            ss << ", ";
            ss << "chp_x=" << this->chp_x();
            ss << ", ";
            ss << "chp_y=" << this->chp_y();
            return ss.str();
#endif /// USE_WB_FIELD_HORIZON_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_FIELD_HORIZON_C_CONVERSION
            char buffer[FIELDHORIZON_TO_STRING_BUFFER_SIZE];
            wb_field_horizon_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << this->horizonType();
            ss << ", ";
            ss << this->lhp_x();
            ss << ", ";
            ss << this->lhp_y();
            ss << ", ";
            ss << this->rhp_x();
            ss << ", ";
            ss << this->rhp_y();
            ss << ", ";
            ss << this->chp_x();
            ss << ", ";
            ss << this->chp_y();
            return ss.str();
#endif /// USE_WB_FIELD_HORIZON_C_CONVERSION
        }

        void from_string(const std::string &str) {
#ifdef USE_WB_OLD_C_CONVERSION
            wb_field_horizon_from_string(this, str);
#else
            char var[255];
            unsigned long lhp_x_index = str.find("lhp_x");
            if (lhp_x_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(lhp_x_index, str.length()).c_str(), "lhp_x = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_lhp_x((uint16_t) (atoi(value.c_str())));
                }
            }
            unsigned long lhp_y_index = str.find("lhp_y");
            if (lhp_y_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(lhp_y_index, str.length()).c_str(), "lhp_y = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_lhp_y((uint16_t) (atoi(value.c_str())));
                }
            }
            unsigned long rhp_x_index = str.find("rhp_x");
            if (rhp_x_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(rhp_x_index, str.length()).c_str(), "rhp_x = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_rhp_x((uint16_t) (atoi(value.c_str())));
                }
            }
            unsigned long rhp_y_index = str.find("rhp_y");
            if (rhp_y_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(rhp_y_index, str.length()).c_str(), "rhp_y = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_rhp_y((uint16_t) (atoi(value.c_str())));
                }
            }
            unsigned long chp_x_index = str.find("chp_x");
            if (chp_x_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(chp_x_index, str.length()).c_str(), "chp_x = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_chp_x((uint16_t) (atoi(value.c_str())));
                }
            }
            unsigned long chp_y_index = str.find("chp_y");
            if (chp_y_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(chp_y_index, str.length()).c_str(), "chp_y = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_chp_y((uint16_t) (atoi(value.c_str())));
                }
            }
#endif /// USE_WB_OLD_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard
#endif /// FieldHorizon_DEFINED
