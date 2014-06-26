/*
 *  FFTStatus.h
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
#ifndef FFTStatus_DEFINED
#define FFTStatus_DEFINED

#include <cstdarg>
#include <cstring>
#include "gusimplewhiteboard.h"
#include "wb_fft_frequencies.h"

namespace guWhiteboard
{
    /**
     * Container for RMS levels and dominant frequencies
     */
    class FFTStatus: public fft_dominant_frequency
    {
    public:
        /** designated constructor */
        FFTStatus(int16_t lrms, int16_t rrms, va_list freqs): fft_dominant_frequency(lrms, rrms, freqs) {}

        /** alternate constructor */
        FFTStatus(int16_t lrms = 0, int16_t rrms = 0, ...): fft_dominant_frequency(lrms, rrms, 0)
        {
            memset(static_cast<void *>(_frequencies), 0, GU_SIMPLE_WHITEBOARD_BUFSIZE - offsetof(FFTStatus, _frequencies));

            if (!rrms) return;

            va_list freqs;
            va_start(freqs, rrms);
            int16_t freq = static_cast<int16_t>(va_arg(freqs, int));
            int16_t *freqp = &_frequencies->left();
            while (freq) { *freqp++ = freq; freq = static_cast<int16_t>(va_arg(freqs, int)); }
            va_end(freqs);
        }

        /** copy constructor */
        FFTStatus(const FFTStatus &other) { memcpy(static_cast<void *>(this), static_cast<const void *>(&other), GU_SIMPLE_WHITEBOARD_BUFSIZE); }

        /** copy assignment operator */
        FFTStatus &operator=(const FFTStatus &other) { memcpy(static_cast<void *>(this), static_cast<const void *>(&other), GU_SIMPLE_WHITEBOARD_BUFSIZE); return *this; }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        FFTStatus(const std::string &names) { from_string(names); }

        /** const char *constructor */
        FFTStatus(const char *names): FFTStatus(std::string(names)) { }

        /** convert to a string */
        std::string description()
        {
            return "NYI";   // FIXME: description needs implementation
        }

        /** convert from a string */
        void from_string(const std::string &/*str*/)
        {
            // FIXME: from_string needs implementation
        }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
    };
}

#endif // FFTStatus_DEFINED