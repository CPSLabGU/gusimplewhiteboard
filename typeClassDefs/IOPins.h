/*
 *  IOPins.h
 *  gusimplewhiteboard / arduino simulator
 *
 *  Created by Rene Hexel on 5/08/2015.
 *  Copyright © 2015 Rene Hexel. All rights reserved.
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

#ifndef IOPins_DEFINED
#define IOPins_DEFINED

#include "wb_io_pins.h"
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

namespace guWhiteboard
{
    /**
     * Class for controlling and getting the status of IO pins.
     * This is implemented as a bit vector with one bit per pin.
     */
    class IOPins: public wb_io_pins
    {
    public:
        /** pin value setter */
        bool get(int pin) const { return IO_PIN_GET(this, pin); }

        /** pin value setter */
        void set(int pin) { IO_PIN_SET(this, pin); }

        /** clear the given pin */
        void clr(int pin) { IO_PIN_CLR(this, pin); }

        /** set the given pin to the given value */
        void set(int pin, bool value) { value ? set(pin) : clr(pin); }

        /** set all pins to the given value */
        void reset(int value = 0) { memset(this, value, sizeof(*this)); }

        /** comparison operator **/
        bool operator==(const IOPins &other) const { return memcmp(this, &other, sizeof(*this)) == 0; }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        IOPins(const std::string &pinvalues): wb_io_pins() { from_string(pinvalues); }

        /** convert to a string */
        std::string description() const
        {
            std::ostringstream ss;
            ss << IO_PIN_GET(this, 0);
            for (size_t i = 1; i < IO_PIN_BIT_SIZE; i++)
                if (IO_PIN_GET(this, i))
                    ss << "," << i;

            return ss.str();
        }

        /** convert from a string */
        void from_string(const std::string &str)
        {
            std::istringstream iss(str);
            std::string token;
            for (int i = 0; i < static_cast<int>(IO_PIN_BIT_SIZE) && getline(iss, token, ','); i++)
            {
                const int v = atoi(token.c_str());
                set(i, v != 0);
            }
        }
#endif
    };
}

#endif /* IOPins_DEFINED */
