/*
 * file PixelToRobotRelativeCoord.swift
 *
 * This file was generated by classgenerator from pixel_to_robot_relative_coord.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 04:41, 11/06/2018.
 * Copyright © 2018 Carl Lusty. All rights reserved.
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
 *        This product includes software developed by Carl Lusty.
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
 * Contains a static method for converting from Nao vision format to a bearing and a dist
 */
extension wb_pixel_to_robot_relative_coord {

    /**
     * Create a new `wb_pixel_to_robot_relative_coord`.
     */
    public static func make() -> wb_pixel_to_robot_relative_coord {
        return wb_pixel_to_robot_relative_coord()
    }

    /**
     * Create a new `wb_pixel_to_robot_relative_coord`.
     */
    public init() {
        self.init()

    }

    /**
     * Create a `wb_pixel_to_robot_relative_coord` from a dictionary.
     */
    public init(fromDictionary dictionary: [String: Any]) {
        self.init()
        guard

        else {
            fatalError("Unable to convert \(dictionary) to wb_pixel_to_robot_relative_coord.")
        }

    }

}

extension wb_pixel_to_robot_relative_coord: CustomStringConvertible {

    public var description: String {
        return ""
    }

}

extension wb_pixel_to_robot_relative_coord: Equatable {}

public func == (lhs: wb_pixel_to_robot_relative_coord, rhs: wb_pixel_to_robot_relative_coord) -> Bool {
    return 
}