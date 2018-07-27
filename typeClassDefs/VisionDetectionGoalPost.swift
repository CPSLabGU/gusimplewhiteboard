/*
 * file VisionDetectionGoalPost.swift
 *
 * This file was generated by classgenerator from vision_detection_goal_post.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 11:58, 27/07/2018.
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
 * Results for the Goal Ray Tracer (guvision). 
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
 */
extension wb_vision_detection_goal_post {

    /**
     * Create a new `wb_vision_detection_goal_post`.
     */
    public static func make() -> wb_vision_detection_goal_post {
        return wb_vision_detection_goal_post(NoPostDetected)
    }

    /**
     * Create a new `wb_vision_detection_goal_post`.
     */
    public init(_ sightingType: GoalPostOptions = NoPostDetected, orientation: GoalPostOrientation = GenericPost, tl_x: Int16 = 0, tl_y: Int16 = 0, tr_x: Int16 = 0, tr_y: Int16 = 0, bl_x: Int16 = 0, bl_y: Int16 = 0, br_x: Int16 = 0, br_y: Int16 = 0) {
        self.init()
        self.sightingType = sightingType
        self.orientation = orientation
        self.tl_x = tl_x
        self.tl_y = tl_y
        self.tr_x = tr_x
        self.tr_y = tr_y
        self.bl_x = bl_x
        self.bl_y = bl_y
        self.br_x = br_x
        self.br_y = br_y
    }

    /**
     * Create a `wb_vision_detection_goal_post` from a dictionary.
     */
    public init(fromDictionary dictionary: [String: Any]) {
        self.init()
        guard
            let sightingType = dictionary["sightingType"] as? GoalPostOptions,
            let orientation = dictionary["orientation"] as? GoalPostOrientation,
            let tl_x = dictionary["tl_x"] as? Int16,
            let tl_y = dictionary["tl_y"] as? Int16,
            let tr_x = dictionary["tr_x"] as? Int16,
            let tr_y = dictionary["tr_y"] as? Int16,
            let bl_x = dictionary["bl_x"] as? Int16,
            let bl_y = dictionary["bl_y"] as? Int16,
            let br_x = dictionary["br_x"] as? Int16,
            let br_y = dictionary["br_y"] as? Int16
        else {
            fatalError("Unable to convert \(dictionary) to wb_vision_detection_goal_post.")
        }
        self.sightingType = sightingType
        self.orientation = orientation
        self.tl_x = tl_x
        self.tl_y = tl_y
        self.tr_x = tr_x
        self.tr_y = tr_y
        self.bl_x = bl_x
        self.bl_y = bl_y
        self.br_x = br_x
        self.br_y = br_y
    }

}

extension wb_vision_detection_goal_post: CustomStringConvertible {

    /**
     * Convert to a description String.
     */
    public var description: String {
        var descString = ""
        descString += "sightingType=\(self.sightingType.rawValue)"
        descString += ", "
        descString += "orientation=\(self.orientation.rawValue)"
        descString += ", "
        descString += "tl_x=\(self.tl_x)"
        descString += ", "
        descString += "tl_y=\(self.tl_y)"
        descString += ", "
        descString += "tr_x=\(self.tr_x)"
        descString += ", "
        descString += "tr_y=\(self.tr_y)"
        descString += ", "
        descString += "bl_x=\(self.bl_x)"
        descString += ", "
        descString += "bl_y=\(self.bl_y)"
        descString += ", "
        descString += "br_x=\(self.br_x)"
        descString += ", "
        descString += "br_y=\(self.br_y)"
        return descString
    }

}

extension wb_vision_detection_goal_post: Equatable {}

public func == (lhs: wb_vision_detection_goal_post, rhs: wb_vision_detection_goal_post) -> Bool {
    return lhs.sightingType == rhs.sightingType
        && lhs.orientation == rhs.orientation
        && lhs.tl_x == rhs.tl_x
        && lhs.tl_y == rhs.tl_y
        && lhs.tr_x == rhs.tr_x
        && lhs.tr_y == rhs.tr_y
        && lhs.bl_x == rhs.bl_x
        && lhs.bl_y == rhs.bl_y
        && lhs.br_x == rhs.br_x
        && lhs.br_y == rhs.br_y
}
