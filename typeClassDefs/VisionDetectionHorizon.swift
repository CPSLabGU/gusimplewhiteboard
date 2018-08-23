/*
 * file VisionDetectionHorizon.swift
 *
 * This file was generated by classgenerator from vision_detection_horizon.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 17:00, 14/08/2018.
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
 * This class is for Vision to report the edge of the SPL soccer field.
 * It does not report the field Bounds, that needs white line detection.
 * This is for the edge of green. 
 * 
 * Results are a percentage of the image utilised, at whatever the resolution and FOV happen to be.
 * You can check the vision status message for resolution and FOV information.
 * Coords:
 *     x, Int16.MinValue <-> Int16.MaxValue
 *     y, Int16.MinValue <-> Int16.MaxValue
 * Minus x Left
 * Plus x Right
 * Plus y Up
 * Minus y Down
 * Center near 0,0
 * 
 * It will attempt to report the projected horizon to the far left X position and the far right position.
 * In the event that the projected position is outside the image bounds. It will project the horizon only as far as the image bound.
 */
extension wb_vision_detection_horizon {

    /**
     * Create a new `wb_vision_detection_horizon`.
     */
    public static func make() -> wb_vision_detection_horizon {
        return wb_vision_detection_horizon(HorizonFailed)
    }

    /**
     * Create a new `wb_vision_detection_horizon`.
     */
    public init(_ horizonType: HorizonOptions = HorizonFailed, lhp_x: Int16 = 0, lhp_y: Int16 = 0, rhp_x: Int16 = 0, rhp_y: Int16 = 0, chp_x: Int16 = 0, chp_y: Int16 = 0) {
        self.init()
        self.horizonType = horizonType
        self.lhp_x = lhp_x
        self.lhp_y = lhp_y
        self.rhp_x = rhp_x
        self.rhp_y = rhp_y
        self.chp_x = chp_x
        self.chp_y = chp_y
    }

    /**
     * Create a `wb_vision_detection_horizon` from a dictionary.
     */
    public init(fromDictionary dictionary: [String: Any]) {
        self.init()
        guard
            let horizonType = dictionary["horizonType"] as? HorizonOptions,
            let lhp_x = dictionary["lhp_x"] as? Int16,
            let lhp_y = dictionary["lhp_y"] as? Int16,
            let rhp_x = dictionary["rhp_x"] as? Int16,
            let rhp_y = dictionary["rhp_y"] as? Int16,
            let chp_x = dictionary["chp_x"] as? Int16,
            let chp_y = dictionary["chp_y"] as? Int16
        else {
            fatalError("Unable to convert \(dictionary) to wb_vision_detection_horizon.")
        }
        self.horizonType = horizonType
        self.lhp_x = lhp_x
        self.lhp_y = lhp_y
        self.rhp_x = rhp_x
        self.rhp_y = rhp_y
        self.chp_x = chp_x
        self.chp_y = chp_y
    }

}

extension wb_vision_detection_horizon: CustomStringConvertible {

    /**
     * Convert to a description String.
     */
    public var description: String {
        var descString = ""
        descString += "horizonType=\(self.horizonType.rawValue)"
        descString += ", "
        descString += "lhp_x=\(self.lhp_x)"
        descString += ", "
        descString += "lhp_y=\(self.lhp_y)"
        descString += ", "
        descString += "rhp_x=\(self.rhp_x)"
        descString += ", "
        descString += "rhp_y=\(self.rhp_y)"
        descString += ", "
        descString += "chp_x=\(self.chp_x)"
        descString += ", "
        descString += "chp_y=\(self.chp_y)"
        return descString
    }

}

extension wb_vision_detection_horizon: Equatable {}

public func == (lhs: wb_vision_detection_horizon, rhs: wb_vision_detection_horizon) -> Bool {
    return lhs.horizonType == rhs.horizonType
        && lhs.lhp_x == rhs.lhp_x
        && lhs.lhp_y == rhs.lhp_y
        && lhs.rhp_x == rhs.rhp_x
        && lhs.rhp_y == rhs.rhp_y
        && lhs.chp_x == rhs.chp_x
        && lhs.chp_y == rhs.chp_y
}
