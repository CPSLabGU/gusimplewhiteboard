/*
 * file SENSORSTorsoJointSensors.h
 *
 * This file was generated by classgenerator from SENSORS_TorsoJointSensors.txt.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2020 Carl Lusty & Dimitri Joukoff. All rights reserved.
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
 *        This product includes software developed by Carl Lusty & Dimitri Joukoff.
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

#ifndef SENSORSTorsoJointSensors_DEFINED
#define SENSORSTorsoJointSensors_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_sensors_torsojointsensors.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_sensors_torsojointsensors`.
     */
    class SENSORSTorsoJointSensors: public wb_sensors_torsojointsensors {

    private:

        /**
         * Set the members of the class.
         */
        void init(float HeadYaw = 0.0f, float HeadPitch = 0.0f, float LShoulderPitch = 0.0f, float LShoulderRoll = 0.0f, float LElbowYaw = 0.0f, float LElbowRoll = 0.0f, float RShoulderPitch = 0.0f, float RShoulderRoll = 0.0f, float RElbowYaw = 0.0f, float RElbowRoll = 0.0f, float LWristYaw = 0.0f, float RWristYaw = 0.0f) {
            set_HeadYaw(HeadYaw);
            set_HeadPitch(HeadPitch);
            set_LShoulderPitch(LShoulderPitch);
            set_LShoulderRoll(LShoulderRoll);
            set_LElbowYaw(LElbowYaw);
            set_LElbowRoll(LElbowRoll);
            set_RShoulderPitch(RShoulderPitch);
            set_RShoulderRoll(RShoulderRoll);
            set_RElbowYaw(RElbowYaw);
            set_RElbowRoll(RElbowRoll);
            set_LWristYaw(LWristYaw);
            set_RWristYaw(RWristYaw);
        }

    public:

        /**
         * Create a new `SENSORSTorsoJointSensors`.
         */
        SENSORSTorsoJointSensors(float HeadYaw = 0.0f, float HeadPitch = 0.0f, float LShoulderPitch = 0.0f, float LShoulderRoll = 0.0f, float LElbowYaw = 0.0f, float LElbowRoll = 0.0f, float RShoulderPitch = 0.0f, float RShoulderRoll = 0.0f, float RElbowYaw = 0.0f, float RElbowRoll = 0.0f, float LWristYaw = 0.0f, float RWristYaw = 0.0f) {
            this->init(HeadYaw, HeadPitch, LShoulderPitch, LShoulderRoll, LElbowYaw, LElbowRoll, RShoulderPitch, RShoulderRoll, RElbowYaw, RElbowRoll, LWristYaw, RWristYaw);
        }

        /**
         * Copy Constructor.
         */
        SENSORSTorsoJointSensors(const SENSORSTorsoJointSensors &other): wb_sensors_torsojointsensors() {
            this->init(other.HeadYaw(), other.HeadPitch(), other.LShoulderPitch(), other.LShoulderRoll(), other.LElbowYaw(), other.LElbowRoll(), other.RShoulderPitch(), other.RShoulderRoll(), other.RElbowYaw(), other.RElbowRoll(), other.LWristYaw(), other.RWristYaw());
        }

        /**
         * Copy Constructor.
         */
        SENSORSTorsoJointSensors(const struct wb_sensors_torsojointsensors &other): wb_sensors_torsojointsensors() {
            this->init(other.HeadYaw(), other.HeadPitch(), other.LShoulderPitch(), other.LShoulderRoll(), other.LElbowYaw(), other.LElbowRoll(), other.RShoulderPitch(), other.RShoulderRoll(), other.RElbowYaw(), other.RElbowRoll(), other.LWristYaw(), other.RWristYaw());
        }

        /**
         * Copy Assignment Operator.
         */
        SENSORSTorsoJointSensors &operator = (const SENSORSTorsoJointSensors &other) {
            this->init(other.HeadYaw(), other.HeadPitch(), other.LShoulderPitch(), other.LShoulderRoll(), other.LElbowYaw(), other.LElbowRoll(), other.RShoulderPitch(), other.RShoulderRoll(), other.RElbowYaw(), other.RElbowRoll(), other.LWristYaw(), other.RWristYaw());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        SENSORSTorsoJointSensors &operator = (const struct wb_sensors_torsojointsensors &other) {
            this->init(other.HeadYaw(), other.HeadPitch(), other.LShoulderPitch(), other.LShoulderRoll(), other.LElbowYaw(), other.LElbowRoll(), other.RShoulderPitch(), other.RShoulderRoll(), other.RElbowYaw(), other.RElbowRoll(), other.LWristYaw(), other.RWristYaw());
            return *this;
        }

        bool operator ==(const SENSORSTorsoJointSensors &other) const
        {
            return fabsf(HeadYaw() - other.HeadYaw()) < FLT_EPSILON
                && fabsf(HeadPitch() - other.HeadPitch()) < FLT_EPSILON
                && fabsf(LShoulderPitch() - other.LShoulderPitch()) < FLT_EPSILON
                && fabsf(LShoulderRoll() - other.LShoulderRoll()) < FLT_EPSILON
                && fabsf(LElbowYaw() - other.LElbowYaw()) < FLT_EPSILON
                && fabsf(LElbowRoll() - other.LElbowRoll()) < FLT_EPSILON
                && fabsf(RShoulderPitch() - other.RShoulderPitch()) < FLT_EPSILON
                && fabsf(RShoulderRoll() - other.RShoulderRoll()) < FLT_EPSILON
                && fabsf(RElbowYaw() - other.RElbowYaw()) < FLT_EPSILON
                && fabsf(RElbowRoll() - other.RElbowRoll()) < FLT_EPSILON
                && fabsf(LWristYaw() - other.LWristYaw()) < FLT_EPSILON
                && fabsf(RWristYaw() - other.RWristYaw()) < FLT_EPSILON;
        }

        bool operator !=(const SENSORSTorsoJointSensors &other) const
        {
            return !(*this == other);
        }

        bool operator ==(const wb_sensors_torsojointsensors &other) const
        {
            return *this == SENSORSTorsoJointSensors(other);
        }

        bool operator !=(const wb_sensors_torsojointsensors &other) const
        {
            return !(*this == other);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        SENSORSTorsoJointSensors(const std::string &str) {
            this->init();
            this->from_string(str);
        }

        std::string description() {
#ifdef USE_WB_SENSORS_TORSOJOINTSENSORS_C_CONVERSION
            char buffer[SENSORS_TORSOJOINTSENSORS_DESC_BUFFER_SIZE];
            wb_sensors_torsojointsensors_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "HeadYaw=" << this->HeadYaw();
            ss << ", ";
            ss << "HeadPitch=" << this->HeadPitch();
            ss << ", ";
            ss << "LShoulderPitch=" << this->LShoulderPitch();
            ss << ", ";
            ss << "LShoulderRoll=" << this->LShoulderRoll();
            ss << ", ";
            ss << "LElbowYaw=" << this->LElbowYaw();
            ss << ", ";
            ss << "LElbowRoll=" << this->LElbowRoll();
            ss << ", ";
            ss << "RShoulderPitch=" << this->RShoulderPitch();
            ss << ", ";
            ss << "RShoulderRoll=" << this->RShoulderRoll();
            ss << ", ";
            ss << "RElbowYaw=" << this->RElbowYaw();
            ss << ", ";
            ss << "RElbowRoll=" << this->RElbowRoll();
            ss << ", ";
            ss << "LWristYaw=" << this->LWristYaw();
            ss << ", ";
            ss << "RWristYaw=" << this->RWristYaw();
            return ss.str();
#endif /// USE_WB_SENSORS_TORSOJOINTSENSORS_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_SENSORS_TORSOJOINTSENSORS_C_CONVERSION
            char buffer[SENSORS_TORSOJOINTSENSORS_TO_STRING_BUFFER_SIZE];
            wb_sensors_torsojointsensors_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << this->HeadYaw();
            ss << ", ";
            ss << this->HeadPitch();
            ss << ", ";
            ss << this->LShoulderPitch();
            ss << ", ";
            ss << this->LShoulderRoll();
            ss << ", ";
            ss << this->LElbowYaw();
            ss << ", ";
            ss << this->LElbowRoll();
            ss << ", ";
            ss << this->RShoulderPitch();
            ss << ", ";
            ss << this->RShoulderRoll();
            ss << ", ";
            ss << this->RElbowYaw();
            ss << ", ";
            ss << this->RElbowRoll();
            ss << ", ";
            ss << this->LWristYaw();
            ss << ", ";
            ss << this->RWristYaw();
            return ss.str();
#endif /// USE_WB_SENSORS_TORSOJOINTSENSORS_C_CONVERSION
        }

#ifdef USE_WB_SENSORS_TORSOJOINTSENSORS_C_CONVERSION
        void from_string(const std::string &str) {
            wb_sensors_torsojointsensors_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > SENSORS_TORSOJOINTSENSORS_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[SENSORS_TORSOJOINTSENSORS_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[15];
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
                    if (0 == strcmp("HeadYaw", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("HeadPitch", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("LShoulderPitch", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("LShoulderRoll", key)) {
                        varIndex = 3;
                    } else if (0 == strcmp("LElbowYaw", key)) {
                        varIndex = 4;
                    } else if (0 == strcmp("LElbowRoll", key)) {
                        varIndex = 5;
                    } else if (0 == strcmp("RShoulderPitch", key)) {
                        varIndex = 6;
                    } else if (0 == strcmp("RShoulderRoll", key)) {
                        varIndex = 7;
                    } else if (0 == strcmp("RElbowYaw", key)) {
                        varIndex = 8;
                    } else if (0 == strcmp("RElbowRoll", key)) {
                        varIndex = 9;
                    } else if (0 == strcmp("LWristYaw", key)) {
                        varIndex = 10;
                    } else if (0 == strcmp("RWristYaw", key)) {
                        varIndex = 11;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        this->set_HeadYaw(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 1:
                    {
                        this->set_HeadPitch(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 2:
                    {
                        this->set_LShoulderPitch(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_LShoulderRoll(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 4:
                    {
                        this->set_LElbowYaw(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 5:
                    {
                        this->set_LElbowRoll(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 6:
                    {
                        this->set_RShoulderPitch(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 7:
                    {
                        this->set_RShoulderRoll(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 8:
                    {
                        this->set_RElbowYaw(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 9:
                    {
                        this->set_RElbowRoll(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 10:
                    {
                        this->set_LWristYaw(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 11:
                    {
                        this->set_RWristYaw(static_cast<float>(atof(var_str)));
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_SENSORS_TORSOJOINTSENSORS_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard

#endif /// SENSORSTorsoJointSensors_DEFINED
