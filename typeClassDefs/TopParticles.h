/*
 * file TopParticles.h
 *
 * This file was generated by classgenerator from TopParticles.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Vlad Estivill-Castro at 16:12, 08/11/2018.
 * Copyright © 2018 Vlad Estivill-Castro. All rights reserved.
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

#ifndef TopParticles_DEFINED
#define TopParticles_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_top_particles.h"

#define TOPPARTICLES_PARTICLES_ARRAY_SIZE 4

#include "ParticlePosition.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_top_particles`.
     */
    class TopParticles: public wb_top_particles {

    public:

        /**
         * Create a new `TopParticles`.
         */
        TopParticles(struct wb_particle_position particles[4] = NULLPTR) {
            if (particles != NULLPTR) {
                std::memcpy(this->_particles, particles, TOPPARTICLES_PARTICLES_ARRAY_SIZE * sizeof (struct wb_particle_position));
            } else {
                struct wb_particle_position particles_temp[TOPPARTICLES_PARTICLES_ARRAY_SIZE] = {wb_particle_position(),wb_particle_position(),wb_particle_position(),wb_particle_position()};
                std::memcpy(this->_particles, particles_temp, TOPPARTICLES_PARTICLES_ARRAY_SIZE * sizeof (struct wb_particle_position));
            }
        }

        /**
         * Copy Constructor.
         */
        TopParticles(const TopParticles &other): wb_top_particles() {
            if (other.particles() != NULLPTR) {
                std::memcpy(this->_particles, other.particles(), TOPPARTICLES_PARTICLES_ARRAY_SIZE * sizeof (struct wb_particle_position));
            }
        }

        /**
         * Copy Constructor.
         */
        TopParticles(const struct wb_top_particles &other): wb_top_particles() {
            if (other.particles() != NULLPTR) {
                std::memcpy(this->_particles, other.particles(), TOPPARTICLES_PARTICLES_ARRAY_SIZE * sizeof (struct wb_particle_position));
            }
        }

        /**
         * Copy Assignment Operator.
         */
        TopParticles &operator = (const TopParticles &other) {
            if (other.particles() != NULLPTR) {
                std::memcpy(this->_particles, other.particles(), TOPPARTICLES_PARTICLES_ARRAY_SIZE * sizeof (struct wb_particle_position));
            }
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        TopParticles &operator = (const struct wb_top_particles &other) {
            if (other.particles() != NULLPTR) {
                std::memcpy(this->_particles, other.particles(), TOPPARTICLES_PARTICLES_ARRAY_SIZE * sizeof (struct wb_particle_position));
            }
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        TopParticles(const std::string &str) { wb_top_particles_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_TOP_PARTICLES_C_CONVERSION
            char buffer[TOPPARTICLES_DESC_BUFFER_SIZE];
            wb_top_particles_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            bool particles_first = true;
            ss << "particles={";
            for (int i = 0; i < TOPPARTICLES_PARTICLES_ARRAY_SIZE; i++) {
                guWhiteboard::ParticlePosition * particles_cast = const_cast<guWhiteboard::ParticlePosition *>(static_cast<const guWhiteboard::ParticlePosition *>(&this->particles(i)));
                ss << (particles_first ? "" : ", ") << "{" << particles_cast->description() << "}";
                particles_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_TOP_PARTICLES_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_TOP_PARTICLES_C_CONVERSION
            char buffer[TOPPARTICLES_TO_STRING_BUFFER_SIZE];
            wb_top_particles_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            bool particles_first = true;
            ss << "{";
            for (int i = 0; i < TOPPARTICLES_PARTICLES_ARRAY_SIZE; i++) {
                guWhiteboard::ParticlePosition * particles_cast = const_cast<guWhiteboard::ParticlePosition *>(static_cast<const guWhiteboard::ParticlePosition *>(&this->particles(i)));
                ss << (particles_first ? "" : ", ") << "{" << particles_cast->to_string() << "}";
                particles_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_TOP_PARTICLES_C_CONVERSION
        }

#ifdef USE_WB_TOPPARTICLES_C_CONVERSION
        void from_string(const std::string &str) {
            wb_top_particles_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1) {
                return;
            }
            char var_str_buffer[TOPPARTICLES_TO_STRING_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[10];
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
                    if (0 == strcmp("particles", key)) {
                        varIndex = 0;
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
                        for (int particles_0_index = 0; particles_0_index < TOPPARTICLES_PARTICLES_ARRAY_SIZE; particles_0_index++) {
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
                            ParticlePosition particles_0_temp = ParticlePosition();
                            particles_0_temp.from_string(var_str);
                            struct wb_particle_position particles_0 = particles_0_temp;
                            this->set_particles(particles_0, particles_0_index);;
                        }
                        index = restartIndex;
                        break;
                    }
                }
                varIndex++;
            } while(index < length);
#endif /// USE_WB_TOPPARTICLES_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

        const ParticlePosition topParticle() {
            return this->particles(0);
        }
    };

} /// namespace guWhiteboard
#endif /// TopParticles_DEFINED
