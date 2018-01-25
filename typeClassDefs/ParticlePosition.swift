/*
 * file ParticlePosition.swift
 *
 * This file was generated by classgenerator from Particle_Position.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Vlad Estivill-Castro at 16:40, 19/01/2018.
 * Copyright © 2018 Vlad Estivill-Castro. All rights reserved.
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
 *        This product includes software developed by Vlad Estivill-Castro.
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
 * @brief Posting by Particle Filter and Localization simulator to create localization based amchines behavior
 */
extension wb_particle_position {



    /**
     * Create a new `wb_particle_position`.
     */
    public static func make() -> wb_particle_position {
        return wb_particle_position(position: wb_point2d())
    }

    /**
     * Create a new `wb_particle_position`.
     */
    public init(position: wb_point2d = wb_point2d(), headingInDegrees: Int16 = 0, confidence: Float = 0.0) {
        self.position = position
        self.headingInDegrees = headingInDegrees
        self.confidence = confidence
    }

    /**
     * Create a `wb_particle_position` from a dictionary.
     */
    public init(fromDictionary dictionary: [String: Any]) {
        guard
            let position = dictionary["position"] as? wb_point2d,
            let headingInDegrees = dictionary["headingInDegrees"] as? Int16,
            let confidence = dictionary["confidence"] as? Float
        else {
            fatalError("Unable to convert \(dictionary) to wb_particle_position.")
        }
        self.position = position
        self.headingInDegrees = headingInDegrees
        self.confidence = confidence
    }

}

extension wb_particle_position: CustomStringConvertible {

    /**
     * Convert to a description String.
     */
    public var description: String {
        var descString = ""
        descString += "headingInDegrees=\(self.headingInDegrees)"
        descString += ", "
        descString += "confidence=\(self.confidence)"
        return descString
    }

}

extension wb_particle_position: Equatable {}

public func == (lhs: wb_particle_position, rhs: wb_particle_position) -> Bool {
    return lhs.headingInDegrees == rhs.headingInDegrees
        && lhs.confidence == rhs.confidence
}
