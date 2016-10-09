/*
 *  Channels.h
 *  gusimplewhiteboard
 *
 *  Created by Josh Stover on 07/09/2015.
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

#ifndef Channels_DEFINED
#define Channels_DEFINED

#include "wb_channels.h"
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

namespace guWhiteboard
{
    /**
     * Class which emulates the 2-process channel synchronisation system from UPPAAL
     * 
     * This is implemented as a bit vector, 1 bit per channel
     * 
     * Examples
     * --------
     *
     *     // send a signal to channel #4
     *     channels = Channels_t();
     *     channels.send(4);
     * 
     *     // wait for a channel signal to be sent
     *     channels = Channels_t();
     *     while (!channels.recieve(4)) { }
     */
    class Channels: public wb_channels
    {
    public:
	/** check if a signal has been sent on a channel */
	bool waiting(int channel) { return CHANNEL_WAITING(this, channel); }

	/** synchronise two machines: sender */
	void send(int channel) { CHANNEL_SEND(this, channel); }

        /** clear sync signal from a channel */
        void clear(int channel) { CHANNEL_CLEAR(this, channel); }

	/** reset all channel signals to zero */
	void reset() { memset(this, 0, sizeof(*this)); }

        /** comparison operator **/
        bool operator==(const Channels &other) const { return memcmp(this, &other, sizeof(*this)) == 0; }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        Channels(const std::string &channel_values): wb_channels() { from_string(channel_values); }

        /** convert to a string */
        std::string description() const
        {
            std::ostringstream ss;
            bool first = true;
	    for (size_t i=0; i<CHANNELS_COUNT; i++) {
		if (CHANNEL_WAITING(this, i)) {
		    ss << (first ? "" : ",") << i ;
		    first = false;
		}
	    }
	    return ss.str();
        }

        /** convert from a string */
        void from_string(const std::string &str)
        {
            std::istringstream iss(str);
            std::string token;
            for (size_t i=0; i<CHANNELS_COUNT && getline(iss, token, ','); i++)
            {
                const int n = atoi(token.c_str());
                if (n >= 0 && n < static_cast<int>(CHANNELS_COUNT))
                    send(n);
                else if (-n >= 0 && -n < static_cast<int>(IO_PIN_BIT_SIZE))
                    clear(n);
            }
        }
#endif
    };
}

#endif /* Channels_DEFINED */

