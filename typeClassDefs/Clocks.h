/*
 *  Clocks.h
 *  gusimplewhiteboard
 *
 *  Created by Josh Stover on 02/09/2015.
 *  Copyright © 2015 Josh Stover. All rights reserved.
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

#ifndef Clocks_DEFINED
#define Clocks_DEFINED


#include "wb_clocks.h"
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

namespace guWhiteboard
{
    /**
    * @brief Class for working with timing and clock messages
    *
    * Examples
    * --------
    *
    * reset timer 3 to the current time
    *     Clocks c = Clocks_t.get();
    *     c.reset(3);
    *
    * get the time since the last reset of clock 3
    *     Clocks c = Clock_t.get();
    *     long long t = c.timeSince(3);
    *
    */
    class Clocks: public wb_clocks
    {
    public:
        /** clock counter getter */
        long long get(uint8_t clock_id) const {
            return ( clock_id<static_cast<uint8_t>(CLOCKS_SIZE) ? clocks(clock_id) : -1 );
        }

        /** clock counter setter */
        void set(int clock_id, long long value) { set_clocks(value, clock_id); }

        /** reset a clock counter to the current time */
        void reset(int clock_id) { set_clocks(get_utime(), clock_id); }

        /** get the current time of a given clock */
        long long timeSince(int clock_id) { return get_utime() - clocks(clock_id); }


#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        Clocks(const std::string &state): wb_clocks() { from_string(state); }

        /** convert to a string */
        std::string description() const
        {
            std::ostringstream ss;
            bool first = true;
            for (unsigned int i=0; i<CLOCKS_SIZE; i++) {
                if (clocks(i)) {
                    ss<< (first ? "" : ",") << i << "=" << clocks(i) ;
                    first = false;
                }
            }
            return ss.str();
        }

        /** convert from a string */
        void from_string(const std::string &str)
        {
            std::vector<std::string> msg;
            std::vector<std::string> kv;
            std::vector<std::string>::const_iterator it;

            msg = components_of_string_separated(str, ',', true);
            for (it = msg.begin(); it!=msg.end(); ++it) {
                kv = components_of_string_separated(*it, '=', true);
                if (VALID_KEYVALUE(kv)) {
                    set_clocks(atoll(kv[1].c_str()), atoi(kv[0].c_str()));
                }
            }
        }
#endif
    };
}

#endif /* Clocks_DEFINED */
