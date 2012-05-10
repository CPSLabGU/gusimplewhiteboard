/*
 *  ObjCWhiteboard.mm
 *  guobjcwhiteboard
 *  
 *  Created by René Hexel on 6/05/12.
 *  Copyright (c) 2012 Rene Hexel.
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
#ifndef	__STDC_LIMIT_MACROS
#define	__STDC_LIMIT_MACROS
#endif
#include <string>
#include <vector>
#include <gusimplewhiteboard.h>
#include <Whiteboard.h>
#include <RemoteWhiteboard.h>
#import "ObjCWhiteboard.h"

using namespace guWhiteboard;
using namespace std;

#pragma mark - private properties

class ObjCWBCallback;

@interface ObjCWhiteboard ()
@property (nonatomic, assign) ObjCWBCallback *wbcallback;

- (void) whiteboardMessageReceived: (const char *) msgType withContent: (WBMsg *) msgContent;
@end

class ObjCWBCallback
{
        ObjCWhiteboard *self;
public:
        ObjCWBCallback(ObjCWhiteboard *s, Whiteboard *wb, const char *msg = "*"): self(s) { if (wb) subscribe(wb, msg); }
        void subscribe(Whiteboard *wb, const char *msg = "*") { Whiteboard::WBResult r; wb->subscribeToMessage(msg, WB_BIND(ObjCWBCallback::callback), r); }
        void unsubscribe(Whiteboard *wb, const char *msg = "*") { Whiteboard::WBResult r; wb->unsubscribeToMessage(msg, r); }
        void callback(string type, WBMsg *msg) { [self whiteboardMessageReceived: type.c_str() withContent: msg]; }
};

#pragma mark - class implementation

@implementation ObjCWhiteboard
@synthesize delegate;
@synthesize gu_whiteboard;
@synthesize wbcallback;
@synthesize knownWhiteboardMessages;

- (id) initWithWhiteboardNamed: (NSString *) wbname
{
        if (!(self = [super init]))
                return nil;

        if (wbname)
                gu_whiteboard = new Whiteboard([wbname UTF8String]);
        else
                gu_whiteboard = new Whiteboard();
        wbcallback = new ObjCWBCallback(self, gu_whiteboard);

        return self;
}


- (id) initWithRobotWhiteboard: (NSInteger) n named: (NSString *) wbname
{
        if (!(self = [super init]))
                return nil;

        if (!wbname || n < 0 || n >= RWBMachine::NUM_OF_MACHINES)
        {
                [self release];
                return nil;
        }
        
        gu_whiteboard = new RemoteWhiteboard([wbname UTF8String], RWBMachine(n));

        wbcallback = new ObjCWBCallback(self, gu_whiteboard);
        
        return self;
}

- (id) init
{
#ifdef GSW_IOS
        NSString *docsDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
        return [self initWithWhiteboardNamed: [docsDir stringByAppendingPathComponent: @"guWhiteboard"]];
#else
        return [self initWithWhiteboardNamed: nil];
#endif
}

- (id) initWithRobotNumbered: (NSInteger) n
{
        if (n <= 0 || n > RWBMachine::NUM_OF_MACHINES)
                return [self init];

        string name = nameForMachine(RWBMachine(--n));
        NSString *wbname = [NSString stringWithFormat: @"%s", name.c_str()];
#ifdef GSW_IOS
        NSString *docsDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
        wbname = [docsDir stringByAppendingPathComponent: wbname];
#endif
        return [self initWithRobotWhiteboard: n named: wbname];
}


- (void) dealloc
{
        if (gu_whiteboard) delete gu_whiteboard;

        [super dealloc];
}


#pragma mark - access methods

- (void) setGu_whiteboard: (Whiteboard *) wb
{
        if (wb == gu_whiteboard) return;
        
        Whiteboard *oldwb = gu_whiteboard;
        gu_whiteboard = wb;
        if (oldwb)
        {
                if (wbcallback) wbcallback->unsubscribe(oldwb);
                delete oldwb;
        }
        if (wb && wbcallback) wbcallback->subscribe(wb);
        
        self.knownWhiteboardMessages = nil;
}


- (NSMutableDictionary *) knownWhiteboardMessages
{
        if (knownWhiteboardMessages) return knownWhiteboardMessages;
        
        self.knownWhiteboardMessages = [NSMutableDictionary dictionaryWithCapacity: GSW_TOTAL_MESSAGE_TYPES];

        if (!gu_whiteboard) return knownWhiteboardMessages;

        /*
         * populate array of known whiteboard message types
         */
        gu_simple_whiteboard *wb = gu_whiteboard->_wbd->wb;
        for (int i = 0; i < wb->num_types; i++)
        {
                NSString *type = [NSString stringWithUTF8String: wb->typenames[i].hash.string];
                [knownWhiteboardMessages setObject: [self dataTypeForMessageType: type]
                                            forKey: type];
        }
        
        return knownWhiteboardMessages;
}

- (NSArray *) knownWhiteboardMessagesSortedByName
{
        return [self.knownWhiteboardMessages.allKeys sortedArrayUsingSelector: @selector(compare:)];
}


- (void) messageReceived: (NSDictionary *) dic
{
        NSString *msg = [dic objectForKey: @"msg"];
        NSString *dataType = [dic objectForKey: @"dataType"];
        NSString *content = [dic objectForKey: @"content"];

        [knownWhiteboardMessages setObject: dataType forKey: msg];

        if ([delegate respondsToSelector: @selector(objcWhiteboard:message:ofType:receivedWithContent:)])
                [delegate objcWhiteboard: self
                                 message: msg
                                  ofType: dataType
                     receivedWithContent: content];
}


- (void) whiteboardMessageReceived: (const char *) msgType withContent: (WBMsg *) wbmsg
{
        @autoreleasepool
        {
                NSString *msg = [NSString stringWithUTF8String: msgType];
                NSString *content = [self contentForWBMsg: wbmsg];
                NSString *dataType = [self dataTypeForWBMsg: wbmsg];
                
                [self performSelectorOnMainThread: @selector(messageReceived:)
                                       withObject: [NSDictionary dictionaryWithObjectsAndKeys:
                                                    msg, @"msg", content, @"content", dataType, @"dataType", nil]
                                    waitUntilDone: NO];
        }
}

#pragma mark - Whiteboard interaction

- (NSString *) contentForWBMsg: (const WBMsg *) msg
{
        switch (msg->getType())
        {
                case WBMsg::TypeBool:
                        return [NSString stringWithUTF8String: msg->getBoolValue() ? "true" : "false"];
                        
                case WBMsg::TypeInt:
                        return [NSString stringWithFormat: @"%d", msg->getIntValue()];
                        
                case WBMsg::TypeFloat:
                        return [NSString stringWithFormat: @"%g", msg->getFloatValue()];
                        
                case WBMsg::TypeString:
                        return [NSString stringWithFormat: @"%s", msg->getStringValue().c_str()];
                        
                case WBMsg::TypeArray:
                {
                        const vector<int> *v = &msg->getArrayValue();
                        NSMutableArray *a = [NSMutableArray arrayWithCapacity: v->size()];
                        for (int i: *v) [a addObject: [NSNumber numberWithInt: i]];
                        return [a componentsJoinedByString: @", "];
                }
                        
                case WBMsg::TypeBinary:
                        return [NSString stringWithFormat: @"%d bytes", msg->getSizeInBytes()];
                        
                case WBMsg::TypeEmpty:
                        return @"- empty -";
                        
                default:
                        break;
        }
        return @"- unknown -";
}


- (NSString *) contentForMessageType: (NSString *) msgType
{
        if (!gu_whiteboard) return @"- nowb -";
        if (!msgType.length) return @"- nomsg -";

        Whiteboard::WBResult result;
        const WBMsg msg = gu_whiteboard->getMessage([msgType UTF8String], &result);
        
        if (result == Whiteboard::METHOD_FAIL)
                return @"- nonexistent -";
        
        return [self contentForWBMsg: &msg];
}

static NSArray *wbnames;

+ (NSArray *) whiteboardNames
{
        if (!wbnames) wbnames = [[NSArray arrayWithObjects:
                                  @"local", @"Robot 1", @"Robot 2", @"Robot 3",
                                  @"Robot 4", nil] retain];
        return wbnames;
}


static NSArray *wbtypes;

+ (NSArray *) whiteboardTypes
{
        if (!wbtypes) wbtypes = [[NSArray arrayWithObjects:
                                  @"bool", @"int", @"float", @"string",
                                  @"array", @"binary", @"empty", nil] retain];
        return wbtypes;
}

- (NSString *) dataTypeForWBMsg: (const WBMsg *) msg
{
        NSArray *types = [ObjCWhiteboard whiteboardTypes];

        enum WBMsg::wb_type type = msg->getType();
        if (type < [types count])
                return [types objectAtIndex: type];
        
        return @"- unknown -";
}


- (NSString *) dataTypeForMessageType: (NSString *) msgType
{
        if (!msgType) return @"- empty -";
        if (!gu_whiteboard) return @"- nowb -";
        
        Whiteboard::WBResult result;
        const WBMsg msg = gu_whiteboard->getMessage([msgType UTF8String], &result);
        
        if (result == Whiteboard::METHOD_FAIL)
                return @"- none -";
        
        return [self dataTypeForWBMsg: &msg];
}


- (NSString *) cachedDataTypeForMessageType: (NSString *) msgType
{
        NSString *result = [knownWhiteboardMessages objectForKey: msgType];
        
        if (!result) result = [self dataTypeForMessageType: msgType];
        
        return result;
}


- (WBMsg::WBType) wbTypeForType: (NSString *) dataType
{
        NSUInteger i = [wbtypes indexOfObject: dataType];
        if (i == NSNotFound)
                return WBMsg::TypeEmpty;
        
        return (WBMsg::WBType) i;
}


static vector<int> convToArrayType(const char *s)
{
        const char *sep = "|,";
        std::vector<int> array;
        char * cord2 = strtok ((char *)s, sep);	
        while (cord2 != NULL)
        {
                array.push_back(atoi(cord2));
                cord2 = strtok (NULL, sep);
        }
        return array;
}



- (WBMsg) wbMsg: (NSString *) msg
         ofType: (NSString *) dataType
    withContent: (NSString *) content
{
        switch ([self wbTypeForType: dataType])
        {
                case WBMsg::TypeBool:
                        if ([content caseInsensitiveCompare: @"true"] == NSOrderedSame ||
                            [content caseInsensitiveCompare: @"yes"] == NSOrderedSame ||
                            [content caseInsensitiveCompare: @"on"] == NSOrderedSame ||
                            [content integerValue])
                                return WBMsg(true);
                        else
                                return WBMsg(false);
                        break;
                case WBMsg::TypeInt:
                        return WBMsg([content intValue]);
                        
                case WBMsg::TypeFloat:
                        return WBMsg([content floatValue]);
                        
                case WBMsg::TypeString:
                        return WBMsg([content UTF8String]);
                        
                case WBMsg::TypeArray:
                        return WBMsg(convToArrayType([content UTF8String]));
                        
                case WBMsg::TypeBinary:
                        return WBMsg([content intValue]);
                        
                case WBMsg::TypeEmpty:
                default:
                        return WBMsg();
        }
}

- (void) postWBMessage: (NSString *) msg
               content: (NSString *) content
              withType: (NSString *) dataType
{
        if (!gu_whiteboard || !msg.length) return;

        WBMsg wbmsg = [self wbMsg: msg ofType: dataType withContent: content];
        gu_whiteboard->addMessage([msg UTF8String], wbmsg);
}


@end
