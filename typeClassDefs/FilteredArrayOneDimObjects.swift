/*
 * file FilteredArrayOneDimObjects.swift
 *
 * This file was generated by classgenerator from Filtered_ArrayOneDimObjects.txt.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2019 Vlad Estivill-Castro. All rights reserved.
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
 * The class of landmarks filtered regarding goal sightings
 */
extension wb_filtered_arrayonedimobjects {

    public var _objects: [wb_filtered_vision_object] {
        get {
            var objects = self.objects
            return withUnsafePointer(to: &objects.0) { objects_p in
                var objects: [wb_filtered_vision_object] = []
                objects.reserveCapacity(4)
                for objects_index in 0..<4 {
                    objects.append(objects_p[objects_index])
                }
                return objects
            }
        } set {
            _ = withUnsafeMutablePointer(to: &self.objects.0) { objects_p in
                for objects_index in 0..<4 {
                    objects_p[objects_index] = newValue[objects_index]
                }
            }
        }
    }

    /**
     * Create a new `wb_filtered_arrayonedimobjects`.
     */
    public static func make() -> wb_filtered_arrayonedimobjects {
        return wb_filtered_arrayonedimobjects([wb_filtered_vision_object(), wb_filtered_vision_object(), wb_filtered_vision_object(), wb_filtered_vision_object()])
    }

    /**
     * Create a new `wb_filtered_arrayonedimobjects`.
     */
    public init(_ objects: [wb_filtered_vision_object] = [wb_filtered_vision_object(), wb_filtered_vision_object(), wb_filtered_vision_object(), wb_filtered_vision_object()]) {
        self.init()
        self._objects = objects
    }

    /**
     * Create a `wb_filtered_arrayonedimobjects` from a dictionary.
     */
    public init(fromDictionary dictionary: [String: Any]) {
        self.init()
        guard
            var objects = dictionary["objects"]
        else {
            fatalError("Unable to convert \(dictionary) to wb_filtered_arrayonedimobjects.")
        }
        self.objects = withUnsafePointer(to: &objects) {
            $0.withMemoryRebound(to: type(of: wb_filtered_arrayonedimobjects().objects), capacity: 1) {
                $0.pointee
            }
        }
    }

}

extension wb_filtered_arrayonedimobjects: CustomStringConvertible {

    /**
     * Convert to a description String.
     */
    public var description: String {
        var descString = ""
        if self._objects.isEmpty {
            descString += "objects={}"
        } else {
            let first = "{" + self.objects.0.description + "}"
            descString += "objects={"
            descString += self._objects.dropFirst().reduce("\(first)") { $0 + ", " + "{" + $1.description + "}" }
            descString += "}"
        }
        return descString
    }

}

extension wb_filtered_arrayonedimobjects: Equatable {}

public func == (lhs: wb_filtered_arrayonedimobjects, rhs: wb_filtered_arrayonedimobjects) -> Bool {
    return lhs._objects == rhs._objects
}