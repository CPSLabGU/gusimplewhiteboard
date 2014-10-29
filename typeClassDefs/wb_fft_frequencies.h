/**
 *  \file wb_fft_frequencies.h
 *  gusimplewhiteboard
 *
 *  Created by
 *  \author Rene Hexel on
 *  \date 24/06/2014.
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

#ifdef GU_SIMPLE_WHITEBOARD_BUFSIZE
#define FFT_DOMINANT_NUMFREQ    ((GU_SIMPLE_WHITEBOARD_BUFSIZE - sizeof(struct rms_strength) - sizeof(struct fsk_frequencies)) / sizeof(fft_frequency_level_pair))
#else
#define FFT_DOMINANT_NUMFREQ    0   // no wb -> don't register size
#endif

#define FSK_DEFAULT_HI  320     ///< default hi frequency for fsk
#define FSK_DEFAULT_LO  200     ///< default lo frequency for fsk

/**
 * \brief Frequency pair for a stereo channel
 * This struct contains a single frequency pair (in Hz)
 * for a stereo channel pair (left and right channels).
 */
struct fft_frequency_level_pair
{
    /** left frequency in Hz (0 means not measured) */
    PROPERTY(int16_t, left)
    /** right frequency in Hz (0 means not measured) */
    PROPERTY(int16_t, right)

#ifdef __cplusplus
    /** constructor with 0 Hz default values (C++ only) */
    fft_frequency_level_pair(int16_t l = 0, int16_t r = 0): _left(l), _right(r) {}
#endif
};

/**
 * \brief RMS levels for a stereo channel pair
 * This struct contains the RMS (root mean square) level
 * measured for the left and the right channel
 */
struct rms_strength
{
    /** RMS level for the left channel */
    PROPERTY(int16_t, left)
    /** RMS level for the right channel */
    PROPERTY(int16_t, right)

#ifdef __cplusplus
    /** constructor with zero strength default values (C++ only) */
    rms_strength(int16_t l = 0, int16_t r = 0): _left(l), _right(r) {}
#endif
};

/**
 * \brief FSK frequency pair and keying values
 * This struct contains the main components of the FSK analysis.
 * The results of the analysis contain the two strongest frequencies
 * measured and their relative percentage (the percentage the high
 * requency was present versus the low frequency).
 */
struct fsk_frequencies
{
    unsigned _hi_freq: 12;      ///< high frequency (0..8191 Hz) divided by 2
    unsigned _lo_freq: 12;      ///< low frequency (0..8191 Hz) divided by 2
    unsigned _hi_percentage: 7; ///< FSK hi percentage (0..100 %)
    unsigned _unused_pad: 1;    ///< reserved for future use

#ifdef __cplusplus
    /** constructor with default hi and low frequencies (C++ only) */
    fsk_frequencies(uint16_t hi = FSK_DEFAULT_HI, uint16_t lo = FSK_DEFAULT_LO, uint16_t fsk = 0): _hi_freq(hi/2), _lo_freq(lo/2), _hi_percentage(fsk), _unused_pad(0) {}

    /** getter for the high frequency (C++ only) */
    uint16_t hi_freq() const { return _hi_freq * 2; }

    /** getter for the low frequency (C++ only) */
    uint16_t lo_freq() const { return _lo_freq * 2; }

    /** getter for the high frequency FSK percentage (C++ only) */
    uint16_t hi_percentage() const { return _hi_percentage; }

    /** convenience getter for the high to low FSK ratio (C++ only) */
    float hi_ratio() const { return static_cast<float>(_hi_percentage) / 100.f; }

    /** setter for the high frequency FSK percentage (C++ only) */
    void set_hi_freq(uint16_t hi = FSK_DEFAULT_HI) { _hi_freq = hi/2; }

    /** setter for the low frequency FSK percentage (C++ only) */
    void set_lo_freq(uint16_t lo = FSK_DEFAULT_LO) { _lo_freq = lo/2; }

    /** setter for the high frequency FSK percentage (C++ only) */
    void set_hi_percentage(uint16_t percent = 0) { _hi_percentage = percent; }
    
    /** convenience setter for the high to low FSK ratio (C++ only) */
    void set_hi_ratio(float r) { _hi_percentage = static_cast<unsigned>(100.f * r); }
#endif
};


/**
 * \brief Main FFT Analysis Structure
 * This structure contains all the components of the FFT analysis, 
 * including the overall RMS levels on the left and right channels,
 * the FSK frequency analysis, and a list of frequency pairs in order
 * of their measured signal strength (strongest to weakest)
 */
struct fft_dominant_frequency
{
    /** overall RMS levels **/
    PROPERTY(struct rms_strength, rms)

    /** FSK frequency comparison between low and high requencies */
    PROPERTY(struct fsk_frequencies, fsk)

    /** Array of frequency pairs ordered by level (strongest first */
    ARRAY_PROPERTY(struct fft_frequency_level_pair, frequencies, FFT_DOMINANT_NUMFREQ)

#ifdef __cplusplus
    /**
     * default constructor (C++ only)
     * @param lrms  RMS level on the left channel
     * @param rrms  RMS level on the right channel
     * @param hi    High frequency (in Hz) to measure FSK percentage on
     * @param lo    Low frequency (in Hz) to measure FSK percentage on
     * @param fsk   FSK percentage of high frequency presence (0..100)%
     * @param freqs List of frequency pairs (in Hz) measured (terminated by 0)
     */
    fft_dominant_frequency(int16_t lrms, int16_t rrms, uint16_t hi, uint16_t lo, uint16_t fsk, va_list freqs): _rms(lrms, rrms), _fsk(hi, lo, fsk)
    {
        if (freqs)
        {
            int16_t *freqp = &_frequencies->left();
            int16_t freq = static_cast<int16_t>(va_arg(freqs, int));
            while (freq) { *freqp++ = freq; freq = static_cast<int16_t>(va_arg(freqs, int)); }
        }
    }

    /**
     * Convenience constructor (C++ only)
     * This constructor is a varargs version of the default constructor
     * allowing the inline specification of the frequency list (instead of
     * using va_list).  This constructor substitutes default values for all
     * parameters if necessary.
     * @param lrms  RMS level on the left channel (0)
     * @param rrms  RMS level on the right channel (0)
     * @param hi    High frequency (in Hz) to measure FSK percentage on (FSK_DEFAULT_HI)
     * @param lo    Low frequency (in Hz) to measure FSK percentage on (FSK_DEFAULT_LO)
     * @param fsk   FSK percentage of high frequency presence (0%)
     * @param freqs List of frequency pairs (in Hz) measured (terminated by 0)
     */
    fft_dominant_frequency(int16_t lrms = 0, int16_t rrms = 0, uint16_t hi = FSK_DEFAULT_HI, uint16_t lo = FSK_DEFAULT_LO, uint16_t fsk = 0, ...): _rms(lrms, rrms), _fsk(hi, lo, fsk)
    {
        if (!rrms) return;

        va_list freqs;
        va_start(freqs, fsk);
        int16_t freq = static_cast<int16_t>(va_arg(freqs, int));
        int16_t *freqp = &_frequencies->left();
        while (freq) { *freqp++ = freq; freq = static_cast<int16_t>(va_arg(freqs, int)); }
        va_end(freqs);
    }
#endif
};

#endif //#_wb_fft_frequencies_h_
