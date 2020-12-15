/*
 * file NaoSonarProtectedWalkCommand.h
 *
 * This file was generated by classgenerator from nao_sonar_protected_walk_command.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2020 Vlad Estivill-Castro. All rights reserved.
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
 *        This product includes software developed by Vlad Estivill-Castro.
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

#ifndef NaoSonarProtectedWalkCommand_DEFINED
#define NaoSonarProtectedWalkCommand_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_nao_sonar_protected_walk_command.h"



namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_nao_sonar_protected_walk_command`.
     */
    class NaoSonarProtectedWalkCommand: public wb_nao_sonar_protected_walk_command {

    private:

        /**
         * Set the members of the class.
         */
        void init(bool t_walkEngineOn = false, int16_t t_forward = 0, int16_t t_left = 0, int8_t t_turn = 0, int8_t t_priority = 1, bool t_exactStepsRequested = false, uint8_t t_speed = 100, bool t_isFast = false, bool t_kickWithLeftFoot = true, bool t_useShuffle = true, bool t_leftArmLimp = false, bool t_rightArmLimp = false, uint8_t t_power = 0, uint8_t t_odometryResetCounter = 0, uint8_t t_bend = 0) {
            set_walkEngineOn(t_walkEngineOn);
            set_forward(t_forward);
            set_left(t_left);
            set_turn(t_turn);
            set_priority(t_priority);
            set_exactStepsRequested(t_exactStepsRequested);
            set_speed(t_speed);
            set_isFast(t_isFast);
            set_kickWithLeftFoot(t_kickWithLeftFoot);
            set_useShuffle(t_useShuffle);
            set_leftArmLimp(t_leftArmLimp);
            set_rightArmLimp(t_rightArmLimp);
            set_power(t_power);
            set_odometryResetCounter(t_odometryResetCounter);
            set_bend(t_bend);
        }

    public:

        /**
         * Create a new `NaoSonarProtectedWalkCommand`.
         */
        NaoSonarProtectedWalkCommand(bool t_walkEngineOn = false, int16_t t_forward = 0, int16_t t_left = 0, int8_t t_turn = 0, int8_t t_priority = 1, bool t_exactStepsRequested = false, uint8_t t_speed = 100, bool t_isFast = false, bool t_kickWithLeftFoot = true, bool t_useShuffle = true, bool t_leftArmLimp = false, bool t_rightArmLimp = false, uint8_t t_power = 0, uint8_t t_odometryResetCounter = 0, uint8_t t_bend = 0) {
            this->init(t_walkEngineOn, t_forward, t_left, t_turn, t_priority, t_exactStepsRequested, t_speed, t_isFast, t_kickWithLeftFoot, t_useShuffle, t_leftArmLimp, t_rightArmLimp, t_power, t_odometryResetCounter, t_bend);
        }

        /**
         * Copy Constructor.
         */
        NaoSonarProtectedWalkCommand(const NaoSonarProtectedWalkCommand &t_other): wb_nao_sonar_protected_walk_command() {
            this->init(t_other.walkEngineOn(), t_other.forward(), t_other.left(), t_other.turn(), t_other.priority(), t_other.exactStepsRequested(), t_other.speed(), t_other.isFast(), t_other.kickWithLeftFoot(), t_other.useShuffle(), t_other.leftArmLimp(), t_other.rightArmLimp(), t_other.power(), t_other.odometryResetCounter(), t_other.bend());
        }

        /**
         * Copy Constructor.
         */
        NaoSonarProtectedWalkCommand(const struct wb_nao_sonar_protected_walk_command &t_other): wb_nao_sonar_protected_walk_command() {
            this->init(t_other.walkEngineOn, t_other.forward, t_other.left, t_other.turn, t_other.priority, t_other.exactStepsRequested, t_other.speed, t_other.isFast, t_other.kickWithLeftFoot, t_other.useShuffle, t_other.leftArmLimp, t_other.rightArmLimp, t_other.power, t_other.odometryResetCounter, t_other.bend);
        }

        /**
         * Copy Assignment Operator.
         */
        NaoSonarProtectedWalkCommand &operator = (const NaoSonarProtectedWalkCommand &t_other) {
            this->init(t_other.walkEngineOn(), t_other.forward(), t_other.left(), t_other.turn(), t_other.priority(), t_other.exactStepsRequested(), t_other.speed(), t_other.isFast(), t_other.kickWithLeftFoot(), t_other.useShuffle(), t_other.leftArmLimp(), t_other.rightArmLimp(), t_other.power(), t_other.odometryResetCounter(), t_other.bend());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        NaoSonarProtectedWalkCommand &operator = (const struct wb_nao_sonar_protected_walk_command &t_other) {
            this->init(t_other.walkEngineOn, t_other.forward, t_other.left, t_other.turn, t_other.priority, t_other.exactStepsRequested, t_other.speed, t_other.isFast, t_other.kickWithLeftFoot, t_other.useShuffle, t_other.leftArmLimp, t_other.rightArmLimp, t_other.power, t_other.odometryResetCounter, t_other.bend);
            return *this;
        }

        bool operator ==(const NaoSonarProtectedWalkCommand &t_other) const
        {
            return walkEngineOn() == t_other.walkEngineOn()
                && forward() == t_other.forward()
                && left() == t_other.left()
                && turn() == t_other.turn()
                && priority() == t_other.priority()
                && exactStepsRequested() == t_other.exactStepsRequested()
                && speed() == t_other.speed()
                && isFast() == t_other.isFast()
                && kickWithLeftFoot() == t_other.kickWithLeftFoot()
                && useShuffle() == t_other.useShuffle()
                && leftArmLimp() == t_other.leftArmLimp()
                && rightArmLimp() == t_other.rightArmLimp()
                && power() == t_other.power()
                && odometryResetCounter() == t_other.odometryResetCounter()
                && bend() == t_other.bend();
        }

        bool operator !=(const NaoSonarProtectedWalkCommand &t_other) const
        {
            return !(*this == t_other);
        }

        bool operator ==(const wb_nao_sonar_protected_walk_command &t_other) const
        {
            return *this == NaoSonarProtectedWalkCommand(t_other);
        }

        bool operator !=(const wb_nao_sonar_protected_walk_command &t_other) const
        {
            return !(*this == t_other);
        }

        bool walkEngineOn() const
        {
            return wb_nao_sonar_protected_walk_command::walkEngineOn;
        }

        void set_walkEngineOn(const bool &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::walkEngineOn = t_newValue;
        }

        int16_t forward() const
        {
            return wb_nao_sonar_protected_walk_command::forward;
        }

        void set_forward(const int16_t &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::forward = t_newValue;
        }

        int16_t left() const
        {
            return wb_nao_sonar_protected_walk_command::left;
        }

        void set_left(const int16_t &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::left = t_newValue;
        }

        int8_t turn() const
        {
            return wb_nao_sonar_protected_walk_command::turn;
        }

        void set_turn(const int8_t &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::turn = t_newValue;
        }

        int8_t priority() const
        {
            return wb_nao_sonar_protected_walk_command::priority;
        }

        void set_priority(const int8_t &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::priority = t_newValue;
        }

        bool exactStepsRequested() const
        {
            return wb_nao_sonar_protected_walk_command::exactStepsRequested;
        }

        void set_exactStepsRequested(const bool &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::exactStepsRequested = t_newValue;
        }

        uint8_t speed() const
        {
            return wb_nao_sonar_protected_walk_command::speed;
        }

        void set_speed(const uint8_t &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::speed = t_newValue;
        }

        bool isFast() const
        {
            return wb_nao_sonar_protected_walk_command::isFast;
        }

        void set_isFast(const bool &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::isFast = t_newValue;
        }

        bool kickWithLeftFoot() const
        {
            return wb_nao_sonar_protected_walk_command::kickWithLeftFoot;
        }

        void set_kickWithLeftFoot(const bool &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::kickWithLeftFoot = t_newValue;
        }

        bool useShuffle() const
        {
            return wb_nao_sonar_protected_walk_command::useShuffle;
        }

        void set_useShuffle(const bool &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::useShuffle = t_newValue;
        }

        bool leftArmLimp() const
        {
            return wb_nao_sonar_protected_walk_command::leftArmLimp;
        }

        void set_leftArmLimp(const bool &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::leftArmLimp = t_newValue;
        }

        bool rightArmLimp() const
        {
            return wb_nao_sonar_protected_walk_command::rightArmLimp;
        }

        void set_rightArmLimp(const bool &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::rightArmLimp = t_newValue;
        }

        uint8_t power() const
        {
            return wb_nao_sonar_protected_walk_command::power;
        }

        void set_power(const uint8_t &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::power = t_newValue;
        }

        uint8_t odometryResetCounter() const
        {
            return wb_nao_sonar_protected_walk_command::odometryResetCounter;
        }

        void set_odometryResetCounter(const uint8_t &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::odometryResetCounter = t_newValue;
        }

        uint8_t bend() const
        {
            return wb_nao_sonar_protected_walk_command::bend;
        }

        void set_bend(const uint8_t &t_newValue)
        {
            wb_nao_sonar_protected_walk_command::bend = t_newValue;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        NaoSonarProtectedWalkCommand(const std::string &t_str) {
            this->init();
            this->from_string(t_str);
        }

        std::string description() {
#ifdef USE_WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_CONVERSION
            char buffer[NAO_SONAR_PROTECTED_WALK_COMMAND_DESC_BUFFER_SIZE];
            wb_nao_sonar_protected_walk_command_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "walkEngineOn=" << (this->walkEngineOn() ? "true" : "false");
            ss << ", ";
            ss << "forward=" << static_cast<signed>(this->forward());
            ss << ", ";
            ss << "left=" << static_cast<signed>(this->left());
            ss << ", ";
            ss << "turn=" << static_cast<signed>(this->turn());
            ss << ", ";
            ss << "priority=" << static_cast<signed>(this->priority());
            ss << ", ";
            ss << "exactStepsRequested=" << (this->exactStepsRequested() ? "true" : "false");
            ss << ", ";
            ss << "speed=" << static_cast<unsigned>(this->speed());
            ss << ", ";
            ss << "isFast=" << (this->isFast() ? "true" : "false");
            ss << ", ";
            ss << "kickWithLeftFoot=" << (this->kickWithLeftFoot() ? "true" : "false");
            ss << ", ";
            ss << "useShuffle=" << (this->useShuffle() ? "true" : "false");
            ss << ", ";
            ss << "leftArmLimp=" << (this->leftArmLimp() ? "true" : "false");
            ss << ", ";
            ss << "rightArmLimp=" << (this->rightArmLimp() ? "true" : "false");
            ss << ", ";
            ss << "power=" << static_cast<unsigned>(this->power());
            ss << ", ";
            ss << "odometryResetCounter=" << static_cast<unsigned>(this->odometryResetCounter());
            ss << ", ";
            ss << "bend=" << static_cast<unsigned>(this->bend());
            return ss.str();
#endif /// USE_WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_CONVERSION
            char buffer[NAO_SONAR_PROTECTED_WALK_COMMAND_TO_STRING_BUFFER_SIZE];
            wb_nao_sonar_protected_walk_command_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << (this->walkEngineOn() ? "true" : "false");
            ss << ", ";
            ss << static_cast<signed>(this->forward());
            ss << ", ";
            ss << static_cast<signed>(this->left());
            ss << ", ";
            ss << static_cast<signed>(this->turn());
            ss << ", ";
            ss << static_cast<signed>(this->priority());
            ss << ", ";
            ss << (this->exactStepsRequested() ? "true" : "false");
            ss << ", ";
            ss << static_cast<unsigned>(this->speed());
            ss << ", ";
            ss << (this->isFast() ? "true" : "false");
            ss << ", ";
            ss << (this->kickWithLeftFoot() ? "true" : "false");
            ss << ", ";
            ss << (this->useShuffle() ? "true" : "false");
            ss << ", ";
            ss << (this->leftArmLimp() ? "true" : "false");
            ss << ", ";
            ss << (this->rightArmLimp() ? "true" : "false");
            ss << ", ";
            ss << static_cast<unsigned>(this->power());
            ss << ", ";
            ss << static_cast<unsigned>(this->odometryResetCounter());
            ss << ", ";
            ss << static_cast<unsigned>(this->bend());
            return ss.str();
#endif /// USE_WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_CONVERSION
        }

#ifdef USE_WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_CONVERSION
        void from_string(const std::string &t_str) {
            wb_nao_sonar_protected_walk_command_from_string(this, t_str.c_str());
#else
        void from_string(const std::string &t_str) {
            char * str_cstr = const_cast<char *>(t_str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > NAO_SONAR_PROTECTED_WALK_COMMAND_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[NAO_SONAR_PROTECTED_WALK_COMMAND_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[21];
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
                    if (0 == strcmp("walkEngineOn", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("forward", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("left", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("turn", key)) {
                        varIndex = 3;
                    } else if (0 == strcmp("priority", key)) {
                        varIndex = 4;
                    } else if (0 == strcmp("exactStepsRequested", key)) {
                        varIndex = 5;
                    } else if (0 == strcmp("speed", key)) {
                        varIndex = 6;
                    } else if (0 == strcmp("isFast", key)) {
                        varIndex = 7;
                    } else if (0 == strcmp("kickWithLeftFoot", key)) {
                        varIndex = 8;
                    } else if (0 == strcmp("useShuffle", key)) {
                        varIndex = 9;
                    } else if (0 == strcmp("leftArmLimp", key)) {
                        varIndex = 10;
                    } else if (0 == strcmp("rightArmLimp", key)) {
                        varIndex = 11;
                    } else if (0 == strcmp("power", key)) {
                        varIndex = 12;
                    } else if (0 == strcmp("odometryResetCounter", key)) {
                        varIndex = 13;
                    } else if (0 == strcmp("bend", key)) {
                        varIndex = 14;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        this->set_walkEngineOn(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 1:
                    {
                        this->set_forward(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 2:
                    {
                        this->set_left(static_cast<int16_t>(atoi(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_turn(static_cast<int8_t>(atoi(var_str)));
                        break;
                    }
                    case 4:
                    {
                        this->set_priority(static_cast<int8_t>(atoi(var_str)));
                        break;
                    }
                    case 5:
                    {
                        this->set_exactStepsRequested(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 6:
                    {
                        this->set_speed(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 7:
                    {
                        this->set_isFast(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 8:
                    {
                        this->set_kickWithLeftFoot(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 9:
                    {
                        this->set_useShuffle(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 10:
                    {
                        this->set_leftArmLimp(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 11:
                    {
                        this->set_rightArmLimp(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 12:
                    {
                        this->set_power(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 13:
                    {
                        this->set_odometryResetCounter(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 14:
                    {
                        this->set_bend(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

        public:

        /**
         * Convenience function to make the nao walk.
         * @param t_forward see struct documentation.
         * @param t_left see struct documentation.
         * @param t_turn see struct documentation.
         * @return A NaoSonarProtectedWalkCommand instance
         */
        static NaoSonarProtectedWalkCommand walkProtected(int8_t t_priority, int16_t t_forward, int16_t t_left, int8_t t_turn) {
            NaoSonarProtectedWalkCommand cmd = NaoSonarProtectedWalkCommand();
            cmd.set_priority(t_priority);
            cmd.set_walkEngineOn(true);
            cmd.set_forward(t_forward);
            cmd.set_left(t_left);
            cmd.set_turn(t_turn);
            cmd.set_bend(1);
            return cmd;
        }

        /**
         * Convenience function to make the nao walk, with precise step distances. There is no speed buildup with this method, it uses a consistent step size and speed. This is good for small accurate movements, like lining up a kick.
         * @param t_forward see struct documentation.
         * @param t_left see struct documentation.
         * @param t_turn see struct documentation.
         * @return A NaoSonarProtectedWalkCommand instance
         */
        static NaoSonarProtectedWalkCommand walkProtectedPrecisely(int8_t t_priority, int16_t t_forward, int16_t t_left, int8_t t_turn) {
            NaoSonarProtectedWalkCommand cmd = walkProtected(t_priority, t_forward, t_left, t_turn);
            cmd.set_exactStepsRequested(true);
            return cmd;
        }

        /**
         * Convenience function to make the nao stop walking. The robot will slow down and stop, remaining in the 'walking' position (slightly crouched).
         * @return A NaoSonarProtectedWalkCommand instance
         */
        static NaoSonarProtectedWalkCommand stop() {
            NaoSonarProtectedWalkCommand cmd = NaoSonarProtectedWalkCommand();
            cmd.set_priority(1);
            cmd.set_walkEngineOn(true);
            cmd.set_forward(0);
            cmd.set_left(0);
            cmd.set_turn(0);
            cmd.set_bend(1);
            return cmd;
        }

        /**
         * Convenience function to make the nao stand in the 'walk' position (slightly crouched), ready to immediately start walking again. This is handy for returning from the STANDING position, reached via 'standWithMinimalStiffness'.
         * @return A NaoSonarProtectedWalkCommand instance
         */
        static NaoSonarProtectedWalkCommand standWithStiffness() {
            NaoSonarProtectedWalkCommand cmd = stop();
            cmd.set_walkEngineOn(true);
            cmd.set_priority(1);
            cmd.set_bend(1);
            return cmd;
        }



        /**
         * Convenience function to make the nao stand in the 'STANDING' position, upright with minimal stiffness. Good for longer pauses in movement, to save on battery and motor wear. You should always return to the CROUCH position before giving up control of the DCM with a 'disconnectWalk'. If you don't return to that position, other motion activities like the MotionPlayer may 'jerk' when activated. You do not need to return to the CROUCH position when you issue walk commands, it will be done automatically.
         * @return A NaoSonarProtectedWalkCommand instance
         */
        static NaoSonarProtectedWalkCommand standWithMinimalStiffness() {
            NaoSonarProtectedWalkCommand cmd = stop();
            cmd.set_priority(1);
            cmd.set_walkEngineOn(true);
            cmd.set_bend(0);
            return cmd;
        }

        /**
         * Convenience function to disconnect the walk engine from the DCM. This must be done in order to give control of the joints to another module, like the Motion Player. You should return to the CROUCH position via 'standWithStiffness' or 'stop' before doing this, to ensure a smooth motion control transition.
         * @return A NaoSonarProtectedWalkCommand instance
         */
        static NaoSonarProtectedWalkCommand disconnectWalk() {
            NaoSonarProtectedWalkCommand cmd = NaoSonarProtectedWalkCommand();
            cmd.set_priority(1);
            cmd.set_walkEngineOn(false);
            return cmd;
        }
    };

} /// namespace guWhiteboard

#endif /// NaoSonarProtectedWalkCommand_DEFINED
