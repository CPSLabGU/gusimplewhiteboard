/*
 * file NaoWalkCommand.swift
 *
 * This file was generated by classgenerator from naoWalkCommand.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Carl Lusty at 03:18, 21/05/2018.
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
 * Control message for sending commands to the walk engine created by UNSW.
 * LICENSE:
 * https://github.com/UNSWComputing/rUNSWift-2017-release/blob/master/LICENSE
 * Source:
 * https://github.com/UNSWComputing/rUNSWift-2017-release/blob/master/robot/motion/generator/Walk2014Generator.cpp
 * Some of their documentation:
 * https://github.com/UNSWComputing/rUNSWift-2017-release/wiki/Motion#walk2014-generator
 */
extension wb_nao_walk_command {

    /**
     * Create a new `wb_nao_walk_command`.
     */
    public static func make() -> wb_nao_walk_command {
        return wb_nao_walk_command(false)
    }

    /**
     * Create a new `wb_nao_walk_command`.
     */
    public init(_ walkEngineOn: Bool = false, forward: Int16 = 0, left: Int16 = 0, turn: Int8 = 0, exactStepsRequested: Bool = false, speed: UInt8 = 100, odometryResetCounter: UInt8 = 0, isFast: Bool = false, kickWithLeftFoot: Bool = true, useShuffle: Bool = false, leftArmLimp: Bool = true, rightArmLimp: Bool = true, power: UInt8 = 0, bend: UInt8 = 0) {
        self.init()
        self.walkEngineOn = walkEngineOn
        self.forward = forward
        self.left = left
        self.turn = turn
        self.exactStepsRequested = exactStepsRequested
        self.speed = speed
        self.odometryResetCounter = odometryResetCounter
        self.isFast = isFast
        self.kickWithLeftFoot = kickWithLeftFoot
        self.useShuffle = useShuffle
        self.leftArmLimp = leftArmLimp
        self.rightArmLimp = rightArmLimp
        self.power = power
        self.bend = bend
    }

    /**
     * Create a `wb_nao_walk_command` from a dictionary.
     */
    public init(fromDictionary dictionary: [String: Any]) {
        self.init()
        guard
            let walkEngineOn = dictionary["walkEngineOn"] as? Bool,
            let forward = dictionary["forward"] as? Int16,
            let left = dictionary["left"] as? Int16,
            let turn = dictionary["turn"] as? Int8,
            let exactStepsRequested = dictionary["exactStepsRequested"] as? Bool,
            let speed = dictionary["speed"] as? UInt8,
            let odometryResetCounter = dictionary["odometryResetCounter"] as? UInt8,
            let isFast = dictionary["isFast"] as? Bool,
            let kickWithLeftFoot = dictionary["kickWithLeftFoot"] as? Bool,
            let useShuffle = dictionary["useShuffle"] as? Bool,
            let leftArmLimp = dictionary["leftArmLimp"] as? Bool,
            let rightArmLimp = dictionary["rightArmLimp"] as? Bool,
            let power = dictionary["power"] as? UInt8,
            let bend = dictionary["bend"] as? UInt8
        else {
            fatalError("Unable to convert \(dictionary) to wb_nao_walk_command.")
        }
        self.walkEngineOn = walkEngineOn
        self.forward = forward
        self.left = left
        self.turn = turn
        self.exactStepsRequested = exactStepsRequested
        self.speed = speed
        self.odometryResetCounter = odometryResetCounter
        self.isFast = isFast
        self.kickWithLeftFoot = kickWithLeftFoot
        self.useShuffle = useShuffle
        self.leftArmLimp = leftArmLimp
        self.rightArmLimp = rightArmLimp
        self.power = power
        self.bend = bend
    }

}

extension wb_nao_walk_command: CustomStringConvertible {

    /**
     * Convert to a description String.
     */
    public var description: String {
        var descString = ""
        descString += "walkEngineOn=\(self.walkEngineOn)"
        descString += ", "
        descString += "forward=\(self.forward)"
        descString += ", "
        descString += "left=\(self.left)"
        descString += ", "
        descString += "turn=\(self.turn)"
        descString += ", "
        descString += "exactStepsRequested=\(self.exactStepsRequested)"
        descString += ", "
        descString += "speed=\(self.speed)"
        descString += ", "
        descString += "odometryResetCounter=\(self.odometryResetCounter)"
        descString += ", "
        descString += "isFast=\(self.isFast)"
        descString += ", "
        descString += "kickWithLeftFoot=\(self.kickWithLeftFoot)"
        descString += ", "
        descString += "useShuffle=\(self.useShuffle)"
        descString += ", "
        descString += "leftArmLimp=\(self.leftArmLimp)"
        descString += ", "
        descString += "rightArmLimp=\(self.rightArmLimp)"
        descString += ", "
        descString += "power=\(self.power)"
        descString += ", "
        descString += "bend=\(self.bend)"
        return descString
    }

}

extension wb_nao_walk_command: Equatable {}

public func == (lhs: wb_nao_walk_command, rhs: wb_nao_walk_command) -> Bool {
    return lhs.walkEngineOn == rhs.walkEngineOn
        && lhs.forward == rhs.forward
        && lhs.left == rhs.left
        && lhs.turn == rhs.turn
        && lhs.exactStepsRequested == rhs.exactStepsRequested
        && lhs.speed == rhs.speed
        && lhs.odometryResetCounter == rhs.odometryResetCounter
        && lhs.isFast == rhs.isFast
        && lhs.kickWithLeftFoot == rhs.kickWithLeftFoot
        && lhs.useShuffle == rhs.useShuffle
        && lhs.leftArmLimp == rhs.leftArmLimp
        && lhs.rightArmLimp == rhs.rightArmLimp
        && lhs.power == rhs.power
        && lhs.bend == rhs.bend
}
