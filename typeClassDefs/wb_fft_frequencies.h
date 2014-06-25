/*
 *  fft_frequencies.h
 *  gusimplewhiteboard
 *
 *  reated by Rene Hexel on 24/06/2014.
 *  Copyright (c) 2014 Rene Hexel. All rights reserved.
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
#ifndef _wb_fft_frequencies_h_
#define _wb_fft_frequencies_h_

#ifdef __cplusplus
#include <cstdarg>
#endif

#include <gu_util.h>

struct fft_frequency_pair       ///< one frequency pair for a stereo channels
{
    PROPERTY(int16_t, left)     ///< left frequency in Hz
    PROPERTY(int16_t, right)    ///< right frequency in Hz

#ifdef __cplusplus
    fft_frequency_pair(int16_t l = 0, int16_t r = 0): _left(l), _right(r) {}
#endif
};

struct rms_strength             ///< RMS levels for a stereo channel pair
{
    PROPERTY(int16_t, left)     ///< RMS level for the left channel
    PROPERTY(int16_t, right)    ///< RMS level for the right channel

#ifdef __cplusplus
    rms_strength(int16_t l = 0, int16_t r = 0): _left(l), _right(r) {}
#endif
};

struct fft_dominant_frequency   ///< A list of dominant frequencies (top to bottom)
{
    PROPERTY(struct rms_strength, rms)                          ///< RMS levels
    ARRAY_PROPERTY(struct fft_frequency_pair, frequencies, 0)   ///< frequency levels

#ifdef __cplusplus
    fft_dominant_frequency(int16_t lrms, int16_t rrms, va_list freqs): _rms_strength(lrms, rrms)
    {
        int16_t *freqp = _frequencies;
        int16_t freq = va_arg(freqs, freq);
        while (freq) { *freqp++ = freq; freq = va_arg(freqs, freq); }
    }
    fft_dominant_frequency(int16_t lrms = 0, int16_t rrms = 0, ...): _rms_strength(lrms, rrms)
    {
        if (!rrms) return;

        va_list freqs;
        va_start(freqs, rrms)
        int16_t freq = va_arg(freqs, freq);
        int16_t *freqp = _frequencies;
        while (freq) { *freqp++ = freq; freq = va_arg(freqs, freq); }
        va_end(freqs)
    }
#endif
}

#endif //#_wb_fft_frequencies_h_
