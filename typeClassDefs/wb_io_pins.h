/*
 *  wb_io_pins.h
 *  gusimplewhiteboard / arduino simulator
 *
 *  Created by Rene Hexel on 5/08/2015.
 *  Copyright © 2015, 2016 Rene Hexel. All rights reserved.
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
#ifndef wb_io_pins_h
#define wb_io_pins_h

#include <gu_util.h>
#include <gusimplewhiteboard/gusimplewhiteboard.h>

#define IO_PIN_BYTE_SIZE     (sizeof(gu_simple_message))    ///< bytes to occupy
#define IO_PIN_BIT_SIZE      (IO_PIN_BYTE_SIZE*8)    ///< bits available

#define IO_PIN_CLR(s, n)    ((s)->_pins[(n)/8] &=~(1<<((n)%8)))
#define IO_PIN_SET(s, n)    ((s)->_pins[(n)/8] |= (1<<((n)%8)))
#define IO_PIN_GET(s, n)    ((((s)->_pins[(n)/8]) & (1<<((n)%8))) != 0)

/**
 * Simulated I/O pins.
 * This is implemented as a bit vector with
 * one bit per pin and controlled by the following macros:
 *
 * IO_PIN_CLR(s, n)    set pin `n` to zero (false, clear)
 * IO_PIN_SET(s, n)    set pin `n` to one (true, set)
 * IO_PIN_GET(s, n)    check if pin `n` is set
 */
struct wb_io_pins
{
    /// bit vector of I/O pin values
    ARRAY_PROPERTY(uint8_t, pins, IO_PIN_BYTE_SIZE)

#ifdef __cplusplus
    /// convenience constructor: clears all I/O pins
    wb_io_pins(int value = 0) { memset(this, value, sizeof(*this)); }
#endif
};


#endif /* wb_io_pins_h */
