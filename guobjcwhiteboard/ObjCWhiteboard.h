/*
 *  ObjCWhiteboard.h
 *  guobjcwhiteboard
 *  
 *  Created by René Hexel on 6/05/12.
 *  Copyright (c) 2012, 2014 Rene Hexel.
 *  All rights reserved.
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
#import <Foundation/Foundation.h>
#import "ObjCWhiteboardDelegate.h"

extern const NSString *kWBTypeBool;
extern const NSString *kWBTypeInt;
extern const NSString *kWBTypeArray;
extern const NSString *kWBTypeFloat;
extern const NSString *kWBTypeString;
extern const NSString *kWBTypeBinary;
extern const NSString *kWBTypeEmpty;

struct gsw_whiteboard_s;
typedef struct gsw_whiteboard_s oc_whiteboard_t;

#ifdef __cplusplus
typedef class whiteboard_watcher oc_watcher_t;
#else
typedef struct whiteboard_watcher oc_watcher_t;
#endif

@interface ObjCWhiteboard: NSObject
@property (nonatomic, weak) id<ObjCWhiteboardDelegate> delegate;
@property (nonatomic, assign) oc_whiteboard_t *gu_whiteboard;
@property (nonatomic, assign) oc_watcher_t *watcher;
@property (nonatomic, strong) NSMutableDictionary *knownWhiteboardMessages;

- (instancetype) init;
- (instancetype) initWithRobotNumbered: (NSInteger) n;
- (instancetype) initWithWhiteboardNamed: (NSString *) wbname;
- (instancetype) initWithRobotWhiteboard: (NSInteger) n named: (NSString *) wbname;

+ (NSArray *) whiteboardTypes;  ///< supported whiteboard type names
+ (NSArray *) whiteboardNames;  ///< names of local and remote robot whiteboards

/// return an array of the known whiteboard names sorted alphabetically
- (NSArray *) knownWhiteboardMessagesSortedByName;

/// get a message of a given type index off the whiteboard
- (NSString *) getMessageOfType: (wbtypes_t) msgType;

/// get a message of a given name off the whiteboard
- (NSString *) getMessageOfTypeNamed: (const NSString *) typeName;

/// return the content of the given whiteboard message as a string
- (NSString *) contentForWBMsg: (const gu_simple_message *) msg ofType: (wbtypes_t) type;

/// return the name of the given message type
- (NSString *) typeNameForMessageType: (wbtypes_t) msgType;

/// get the whiteboard type index for a given type name
- (wbtypes_t) wbTypeForTypeNamed: (const NSString *) dataType;

/// post msg of given type with given string content to the whiteboard
- (BOOL) postWBMessageOfType: (wbtypes_t) msgType withContent: (const NSString *) content;

/// post a wb message of the given type name with the given string content
- (BOOL) postWBMessageOfTypeNamed: (const NSString *) msg withContent: (const NSString *) content;

- getWBMessage: (const NSString *) msg; ///< get wb msg and return as objc object

@end
