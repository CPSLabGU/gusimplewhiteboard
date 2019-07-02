/*
 * file NaoSonarProtectedWalkCommand.h
 *
 * This file was generated by classgenerator from nao_sonar_protected_walk_command.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2019 Vlad Estivill-Castro. All rights reserved.
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
        void init(bool walkEngineOn = false, int16_t forward = 0, int16_t left = 0, int8_t turn = 0, bool exactStepsRequested = false, uint8_t odometryResetCounter = 0) {
            set_walkEngineOn(walkEngineOn);
            set_forward(forward);
            set_left(left);
            set_turn(turn);
            set_exactStepsRequested(exactStepsRequested);
            set_odometryResetCounter(odometryResetCounter);
        }

    public:

        /**
         * Create a new `NaoSonarProtectedWalkCommand`.
         */
        NaoSonarProtectedWalkCommand(bool walkEngineOn = false, int16_t forward = 0, int16_t left = 0, int8_t turn = 0, bool exactStepsRequested = false, uint8_t odometryResetCounter = 0) {
            this->init(walkEngineOn, forward, left, turn, exactStepsRequested, odometryResetCounter);
        }

        /**
         * Copy Constructor.
         */
        NaoSonarProtectedWalkCommand(const NaoSonarProtectedWalkCommand &other): wb_nao_sonar_protected_walk_command() {
            this->init(other.walkEngineOn(), other.forward(), other.left(), other.turn(), other.exactStepsRequested(), other.odometryResetCounter());
        }

        /**
         * Copy Constructor.
         */
        NaoSonarProtectedWalkCommand(const struct wb_nao_sonar_protected_walk_command &other): wb_nao_sonar_protected_walk_command() {
            this->init(other.walkEngineOn(), other.forward(), other.left(), other.turn(), other.exactStepsRequested(), other.odometryResetCounter());
        }

        /**
         * Copy Assignment Operator.
         */
        NaoSonarProtectedWalkCommand &operator = (const NaoSonarProtectedWalkCommand &other) {
            this->init(other.walkEngineOn(), other.forward(), other.left(), other.turn(), other.exactStepsRequested(), other.odometryResetCounter());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        NaoSonarProtectedWalkCommand &operator = (const struct wb_nao_sonar_protected_walk_command &other) {
            this->init(other.walkEngineOn(), other.forward(), other.left(), other.turn(), other.exactStepsRequested(), other.odometryResetCounter());
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        NaoSonarProtectedWalkCommand(const std::string &str) {
            this->init();
            this->from_string(str);
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
            ss << "exactStepsRequested=" << (this->exactStepsRequested() ? "true" : "false");
            ss << ", ";
            ss << "odometryResetCounter=" << static_cast<unsigned>(this->odometryResetCounter());
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
            ss << (this->exactStepsRequested() ? "true" : "false");
            ss << ", ";
            ss << static_cast<unsigned>(this->odometryResetCounter());
            return ss.str();
#endif /// USE_WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_CONVERSION
        }

#ifdef USE_WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_CONVERSION
        void from_string(const std::string &str) {
            wb_nao_sonar_protected_walk_command_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
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
                    } else if (0 == strcmp("exactStepsRequested", key)) {
                        varIndex = 4;
                    } else if (0 == strcmp("odometryResetCounter", key)) {
                        varIndex = 5;
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
                        this->set_exactStepsRequested(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 5:
                    {
                        this->set_odometryResetCounter(static_cast<uint8_t>(atoi(var_str)));
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
         * @param forward see struct documentation.
         * @param left see struct documentation.
         * @param turn see struct documentation.
         * @return A NaoWalkCommand instance
         */
        static NaoSonarProtectedWalkCommand walkProtected(int16_t forward, int16_t left, int8_t turn) {
            NaoSonarProtectedWalkCommand cmd = NaoSonarProtectedWalkCommand();
            cmd.set_forward(forward);
            cmd.set_left(left);
            cmd.set_turn(turn);
            return cmd;
        }

        /**
         * Convenience function to make the nao walk, with precise step distances. There is no speed buildup with this method, it uses a consistent step size and speed. This is good for small accurate movements, like lining up a kick.
         * @param forward see struct documentation.
         * @param left see struct documentation.
         * @param turn see struct documentation.
         * @return A NaoWalkCommand instance
         */
        static NaoSonarProtectedWalkCommand walkProtectedPrecisely(int16_t forward, int16_t left, int8_t turn) {
            NaoSonarProtectedWalkCommand cmd = walkProtected(forward, left, turn);
            cmd.set_exactStepsRequested(true);
            return cmd;
        }
    };

} /// namespace guWhiteboard
#endif /// NaoSonarProtectedWalkCommand_DEFINED