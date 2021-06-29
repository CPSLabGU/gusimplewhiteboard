/*
 * file TopParticles.h
 *
 * This file was generated by classgenerator from TopParticles.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2021 Vlad Estivill-Castro. All rights reserved.
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

#ifndef guWhiteboard_TopParticles_h
#define guWhiteboard_TopParticles_h

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_top_particles.h"

#undef guWhiteboard_TopParticles_DEFINED
#define guWhiteboard_TopParticles_DEFINED

#undef TopParticles_DEFINED
#define TopParticles_DEFINED

#define TOPPARTICLES_PARTICLES_ARRAY_SIZE 4

#include "ParticlePosition.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_top_particles`.
     */
    class TopParticles: public wb_top_particles {

    private:

        /**
         * Set the members of the class.
         */
        void init(const struct wb_particle_position t_particles[4] = NULLPTR) {
            if (t_particles != NULLPTR) {
                std::memcpy(wb_top_particles::particles, t_particles, TOPPARTICLES_PARTICLES_ARRAY_SIZE * sizeof (struct wb_particle_position));
            } else {
                struct wb_particle_position particles_temp[TOPPARTICLES_PARTICLES_ARRAY_SIZE] = {wb_particle_position(),wb_particle_position(),wb_particle_position(),wb_particle_position()};
                std::memcpy(wb_top_particles::particles, particles_temp, TOPPARTICLES_PARTICLES_ARRAY_SIZE * sizeof (struct wb_particle_position));
            }
        }

    public:

        /**
         * Create a new `TopParticles`.
         */
        TopParticles(const struct wb_particle_position t_particles[4] = NULLPTR) {
            this->init(t_particles);
        }

        /**
         * Copy Constructor.
         */
        TopParticles(const TopParticles &t_other): wb_top_particles() {
            this->init(t_other.particles());
        }

        /**
         * Copy Constructor.
         */
        TopParticles(const struct wb_top_particles &t_other): wb_top_particles() {
            this->init(t_other.particles);
        }

        /**
         * Copy Assignment Operator.
         */
        TopParticles &operator = (const TopParticles &t_other) {
            this->init(t_other.particles());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        TopParticles &operator = (const struct wb_top_particles &t_other) {
            this->init(t_other.particles);
            return *this;
        }

        bool operator ==(const TopParticles &t_other) const
        {
            for (int particles_0_index = 0; particles_0_index < 4; particles_0_index++)
            {
                if (!(ParticlePosition(particles(particles_0_index)) == ParticlePosition(t_other.particles(particles_0_index)))) return false;
            }
            return true;
        }

        bool operator !=(const TopParticles &t_other) const
        {
            return !(*this == t_other);
        }

        bool operator ==(const wb_top_particles &t_other) const
        {
            return *this == TopParticles(t_other);
        }

        bool operator !=(const wb_top_particles &t_other) const
        {
            return !(*this == t_other);
        }

        const ParticlePosition * particles() const
        {
            return static_cast<const ParticlePosition *>(&(wb_top_particles::particles[0]));
        }

        size_t particles_size() const
        {
            return TOPPARTICLES_PARTICLES_ARRAY_SIZE;
        }

        ParticlePosition & particles(int t_i)
        {
            return const_cast<ParticlePosition &>(static_cast<const ParticlePosition &>(wb_top_particles::particles[t_i]));
        }

        const ParticlePosition & particles(int t_i) const
        {
            return static_cast<const ParticlePosition &>(wb_top_particles::particles[t_i]);
        }

        void set_particles(const ParticlePosition *t_newValue)
        {
            memcpy(wb_top_particles::particles, static_cast<const struct wb_particle_position *>(t_newValue), TOPPARTICLES_PARTICLES_ARRAY_SIZE * (sizeof (struct wb_particle_position)));
        }

        void set_particles(const ParticlePosition &t_newValue, int t_i)
        {
            wb_top_particles::particles[t_i] = static_cast<wb_particle_position>(t_newValue);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        TopParticles(const std::string &t_str) {
            this->init();
            this->from_string(t_str);
        }

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
                ss << (particles_first ? "" : ", ") << "{" << ParticlePosition(this->particles(i)).description() << "}";
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
                ss << (particles_first ? "" : ", ") << "{" << ParticlePosition(this->particles(i)).to_string() << "}";
                particles_first = false;
            }
            ss << "}";
            return ss.str();
#endif /// USE_WB_TOP_PARTICLES_C_CONVERSION
        }

#ifdef USE_WB_TOP_PARTICLES_C_CONVERSION
        void from_string(const std::string &t_str) {
            wb_top_particles_from_string(this, t_str.c_str());
#else
        void from_string(const std::string &t_str) {
            char * str_cstr = const_cast<char *>(t_str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > TOPPARTICLES_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[TOPPARTICLES_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[10];
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
                    if (0 == strcmp("particles", key)) {
                        varIndex = 0;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
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
                            ParticlePosition particles_0_temp = ParticlePosition();
                            particles_0_temp.from_string(var_str);
                            struct wb_particle_position particles_0 = particles_0_temp;
                            this->set_particles(particles_0, particles_0_index);
                        }
                        index = restartIndex;
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_TOP_PARTICLES_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

        const ParticlePosition topParticle() {
            return this->particles(0);
        }
    };

} /// namespace guWhiteboard

#endif /// guWhiteboard_TopParticles_h
