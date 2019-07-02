/*
 * file MicrophoneFrequencies.swift
 *
 * This file was generated by classgenerator from microphone_frequencies.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2019 Rene Hexel. All rights reserved.
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

//swiftlint:disable function_body_length
//swiftlint:disable file_length
//swiftlint:disable line_length
//swiftlint:disable identifier_name

/**
 * Frequency quadruple for rear and front stereo channels
 */
extension wb_microphone_frequencies {

    /**
     * Create a new `wb_microphone_frequencies`.
     */
    public static func make() -> wb_microphone_frequencies {
        return wb_microphone_frequencies(0)
    }

    /**
     * Create a new `wb_microphone_frequencies`.
     */
    public init(_ rear_left: Int16 = 0, rear_right: Int16 = 0, front_left: Int16 = 0, front_right: Int16 = 0) {
        self.init()
        self.rear_left = rear_left
        self.rear_right = rear_right
        self.front_left = front_left
        self.front_right = front_right
    }

    /**
     * Create a `wb_microphone_frequencies` from a dictionary.
     */
    public init(fromDictionary dictionary: [String: Any]) {
        self.init()
        guard
            let rear_left = dictionary["rear_left"] as? Int16,
            let rear_right = dictionary["rear_right"] as? Int16,
            let front_left = dictionary["front_left"] as? Int16,
            let front_right = dictionary["front_right"] as? Int16
        else {
            fatalError("Unable to convert \(dictionary) to wb_microphone_frequencies.")
        }
        self.rear_left = rear_left
        self.rear_right = rear_right
        self.front_left = front_left
        self.front_right = front_right
    }

}

extension wb_microphone_frequencies: CustomStringConvertible {

    /**
     * Convert to a description String.
     */
    public var description: String {
        var descString = ""
        descString += "rear_left=\(self.rear_left)"
        descString += ", "
        descString += "rear_right=\(self.rear_right)"
        descString += ", "
        descString += "front_left=\(self.front_left)"
        descString += ", "
        descString += "front_right=\(self.front_right)"
        return descString
    }

}

extension wb_microphone_frequencies: Equatable {}

public func == (lhs: wb_microphone_frequencies, rhs: wb_microphone_frequencies) -> Bool {
    return lhs.rear_left == rhs.rear_left
        && lhs.rear_right == rhs.rear_right
        && lhs.front_left == rhs.front_left
        && lhs.front_right == rhs.front_right
}
