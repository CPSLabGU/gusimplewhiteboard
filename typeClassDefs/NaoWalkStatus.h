/*
 * file NaoWalkStatus.h
 *
 * This file was generated by classgenerator from naoWalkStatus.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 06:21, 14/11/2017.
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

#ifndef NaoWalkStatus_DEFINED
#define NaoWalkStatus_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include "gu_util.h"
#include "wb_nao_walk_status.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_nao_walk_status`.
     */
    class NaoWalkStatus: public wb_nao_walk_status {

    public:

        /**
         * Create a new `NaoWalkStatus`.
         */
        NaoWalkStatus(enum WalkEngineState walkEngineState = wes_Disconnected, struct Odometry_s odometry = Odometry_s(), uint8_t odometryResetCounter = 0) {
            set_walkEngineState(walkEngineState);
            set_odometry(odometry);
            set_odometryResetCounter(odometryResetCounter);
        }

        /**
         * Copy Constructor.
         */
        NaoWalkStatus(const NaoWalkStatus &other): wb_nao_walk_status() {
            set_walkEngineState(other.walkEngineState());
            set_odometry(other.odometry());
            set_odometryResetCounter(other.odometryResetCounter());
        }

        /**
         * Copy Assignment Operator.
         */
        NaoWalkStatus &operator = (const NaoWalkStatus &other) {
            set_walkEngineState(other.walkEngineState());
            set_odometry(other.odometry());
            set_odometryResetCounter(other.odometryResetCounter());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        NaoWalkStatus(const std::string &str) { wb_nao_walk_status_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_NAO_WALK_STATUS_C_CONVERSION
            char buffer[NAOWALKSTATUS_DESC_BUFFER_SIZE];
            wb_nao_walk_status_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "walkEngineState=" << static_cast<signed>(this->walkEngineState());
            ss << ", ";
            ss << "odometryResetCounter=" << static_cast<unsigned>(this->odometryResetCounter());
            return ss.str();
#endif /// USE_WB_NAO_WALK_STATUS_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_NAO_WALK_STATUS_C_CONVERSION
            char buffer[NAOWALKSTATUS_TO_STRING_BUFFER_SIZE];
            wb_nao_walk_status_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << static_cast<signed>(this->walkEngineState());
            ss << ", ";
            ss << static_cast<unsigned>(this->odometryResetCounter());
            return ss.str();
#endif /// USE_WB_NAO_WALK_STATUS_C_CONVERSION
        }

        void from_string(const std::string &str) {
#ifdef USE_WB_NAOWALKSTATUS_C_CONVERSION
            wb_nao_walk_status_from_string(this, str.c_str());
#else
            char var[255];
            unsigned long walkEngineState_index = str.find("walkEngineState=");
            if (walkEngineState_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(walkEngineState_index, str.length()).c_str(), "walkEngineState = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_walkEngineState(static_cast<enum WalkEngineState>(atoi(value.c_str())));
                }
            }
            unsigned long odometryResetCounter_index = str.find(" odometryResetCounter=");
            if (odometryResetCounter_index != std::string::npos) {
                memset(&var[0], 0, sizeof(var));
                if (sscanf(str.substr(odometryResetCounter_index + 1, str.length()).c_str(), "odometryResetCounter = %[^,]", var) == 1) {
                    std::string value = std::string(var);
                    set_odometryResetCounter(static_cast<uint8_t>(atoi(value.c_str())));
                }
            }
#endif /// USE_WB_NAOWALKSTATUS_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

        /** comparison operator **/
        bool operator == (const NaoWalkStatus &other) { 
            return walkEngineState() == other.walkEngineState() &&
                odometry() == other.odometry() &&
                odometryResetCounter() == other.odometryResetCounter();
        }

        /** comparison operator **/
        bool operator != (const NaoWalkStatus &s) { return !(*this == s); }
    };

} /// namespace guWhiteboard
#endif /// NaoWalkStatus_DEFINED