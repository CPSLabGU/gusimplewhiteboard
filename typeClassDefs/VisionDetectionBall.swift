/*
 * file VisionDetectionBall.swift
 *
 * This file was generated by classgenerator from vision_detection_ball.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 22:28, 30/05/2018.
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
 * Results for the Ball Ray Tracer (guvision). 
 * Results are a percentage of the image utilised, at whatever the resolution and FOV happen to be.
 * You can check the vision status message for resolution and FOV information.
 * Coords:
 *     x, Int16.MinValue <-> Int16.MaxValue
 *     y, Int16.MinValue <-> Int16.MaxValue
 *     r, 0 <-> UInt16.MaxValue
 * Minus x Left-Most Position in the image : MinValue
 * Plus x Right-Most Position of the image :MaxValue
 * Plus y Up-Most Position of the image : MaxValue
 * Minus y Down-most position of the image: MinValue
 * Center near 0,0
 * 
 * Radius is relative to width. A radius is always positive. A radius of 0 pixels in
 * a width of resolution 640 posts 0, a radius of 640 pixels post MaxValue,
 * a radius of 64 pixels posts MaxValue/10
 */
extension wb_vision_detection_ball {

    /**
     * Create a new `wb_vision_detection_ball`.
     */
    public static func make() -> wb_vision_detection_ball {
        return wb_vision_detection_ball(NoBallDetected)
    }

    /**
     * Create a new `wb_vision_detection_ball`.
     */
    public init(_ sightingType: BallOptions = NoBallDetected, x: Int16 = 0, y: Int16 = 0, r: UInt16 = 0) {
        self.init()
        self.sightingType = sightingType
        self.x = x
        self.y = y
        self.r = r
    }

    /**
     * Create a `wb_vision_detection_ball` from a dictionary.
     */
    public init(fromDictionary dictionary: [String: Any]) {
        self.init()
        guard
            let sightingType = dictionary["sightingType"] as? BallOptions,
            let x = dictionary["x"] as? Int16,
            let y = dictionary["y"] as? Int16,
            let r = dictionary["r"] as? UInt16
        else {
            fatalError("Unable to convert \(dictionary) to wb_vision_detection_ball.")
        }
        self.sightingType = sightingType
        self.x = x
        self.y = y
        self.r = r
    }

}

extension wb_vision_detection_ball: CustomStringConvertible {

    /**
     * Convert to a description String.
     */
    public var description: String {
        var descString = ""
        descString += "sightingType=\(self.sightingType.rawValue)"
        descString += ", "
        descString += "x=\(self.x)"
        descString += ", "
        descString += "y=\(self.y)"
        descString += ", "
        descString += "r=\(self.r)"
        return descString
    }

}

extension wb_vision_detection_ball: Equatable {}

public func == (lhs: wb_vision_detection_ball, rhs: wb_vision_detection_ball) -> Bool {
    return lhs.sightingType == rhs.sightingType
        && lhs.x == rhs.x
        && lhs.y == rhs.y
        && lhs.r == rhs.r
}