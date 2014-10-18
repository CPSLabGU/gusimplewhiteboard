/*
 *  ObjCWhiteboard.mm
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
#ifndef	__STDC_LIMIT_MACROS
#define	__STDC_LIMIT_MACROS
#endif
#include <string>
#include <vector>
#include <gusimplewhiteboard.h>
#ifdef USE_OLD_WB
#include <Whiteboard.h>
#include <RemoteWhiteboard.h>
#else
#include "gugenericwhiteboardobject.h"
#include "guwhiteboardtypelist_generated.h"
#include "guwhiteboardtypelist_c_generated.h"
#include "guwhiteboardposter.h"
#include "guwhiteboardgetter.h"
#include "guwhiteboardwatcher.h"
#endif
#import "ObjCWhiteboard.h"

const NSString *kWBTypeBool = @"bool";
const NSString *kWBTypeInt = @"int";
const NSString *kWBTypeArray = @"array";
const NSString *kWBTypeFloat = @"float";
const NSString *kWBTypeString = @"string";
const NSString *kWBTypeBinary = @"binary";
const NSString *kWBTypeEmpty =  @"empty";

#ifdef GSW_IOS
extern "C"
{
#ifdef GSW_IOS_DEVICE
        const char *gsw_global_whiteboard_name;
#endif
        void init_ios_whiteboard_name(void)
        {
                if (gsw_global_whiteboard_name) return;
#ifdef GSW_IOS_DEVICE
                NSString *wbDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
#else
                NSString *wbDir = @"/tmp";
#endif
                NSString *wbname = [wbDir stringByAppendingPathComponent: @"guWhiteboard"];
                gsw_global_whiteboard_name = strdup([wbname UTF8String]);
        }

        const char *wbname_prefixed_with_path(const char *name)
        {
                if (strchr(name, '/')) return name;     // don't touch abs path

                NSString *docsDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
                NSString *wbname = [docsDir stringByAppendingPathComponent: [NSString stringWithUTF8String: name]];
                return [wbname UTF8String];             // autoreleased!
        }
}
#endif


using namespace guWhiteboard;
using namespace std;

#pragma mark - private properties

class ObjCWBCallback;

@interface ObjCWhiteboard ()
@property (nonatomic, assign) ObjCWBCallback *wbcallback;

#ifdef USE_OLD_WB
- (void) whiteboardMessageReceived: (const char *) msgType withContent: (WBMsg *) msgContent;
#else
- (void) whiteboardMessageReceived: (guWhiteboard::wb_types) msgType withContent: (gu_simple_message *) wbmsg;
#endif
@end

class ObjCWBCallback
{
        ObjCWhiteboard *self;
public:
#ifdef USE_OLD_WB
        ObjCWBCallback(ObjCWhiteboard *s, Whiteboard *wb, const char *msg = "*"): self(s) { if (wb) subscribe(wb, msg); }
        void subscribe(Whiteboard *wb, const char *msg = "*") { Whiteboard::WBResult r; wb->subscribeToMessage(msg, WB_BIND(ObjCWBCallback::callback), r); }
        void unsubscribe(Whiteboard *wb, const char *msg = "*") { Whiteboard::WBResult r; wb->unsubscribeToMessage(msg, r); }
        void callback(string type, WBMsg *msg) { [self whiteboardMessageReceived: type.c_str() withContent: msg]; }
#else
        ObjCWBCallback(ObjCWhiteboard *s, oc_watcher_t *watcher, const char *msg = "*"): self(s)
        {
                watcher->subscribe(createWBFunctor<ObjCWBCallback>(this, &ObjCWBCallback::callback, kwb_reserved_SubscribeToAllTypes_v));
        }
        void callback(guWhiteboard::WBTypes t, gu_simple_message *msg) { [self whiteboardMessageReceived: t withContent: msg]; }
#endif
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
#ifdef USE_OLD_WB
        if ([wbname length])
                gu_whiteboard = new Whiteboard([wbname UTF8String]);
        else
                gu_whiteboard = new Whiteboard();
#else
        if (wbname.length)
                gu_whiteboard = gsw_new_whiteboard(wbname.UTF8String);
        else
                gu_whiteboard = get_local_singleton_whiteboard();

        _watcher = new whiteboard_watcher(gu_whiteboard);
#endif
        wbcallback = new ObjCWBCallback(self, _watcher);

        return self;
}


- (id) initWithRobotWhiteboard: (NSInteger) n named: (NSString *) wbname
{
        if (!(self = [super init]))
                return nil;
#ifdef USE_OLD_WB
        if (!wbname || n < 0 || n >= RWBMachine::NUM_OF_MACHINES)
        {
                [self release];
                return nil;
        }
        
        gu_whiteboard = new RemoteWhiteboard([wbname UTF8String], RWBMachine(n));

        wbcallback = new ObjCWBCallback(self, gu_whiteboard);
#else
        if (wbname.length)
                gu_whiteboard = gsw_new_numbered_whiteboard(wbname.UTF8String, static_cast<int>(n));
        else if (n)
                gu_whiteboard = gswr_new_whiteboard(static_cast<int>(n));
        else
                gu_whiteboard = get_local_singleton_whiteboard();

        _watcher = new whiteboard_watcher(gu_whiteboard);
#endif
        wbcallback = new ObjCWBCallback(self, _watcher);

        return self;
}

- (id) init
{
#ifdef GSW_IOS_DEVICE
        NSString *docsDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
        return [self initWithWhiteboardNamed: [docsDir stringByAppendingPathComponent: @"guWhiteboard"]];
#else
        return [self initWithWhiteboardNamed: nil];
#endif
}

- (id) initWithRobotNumbered: (NSInteger) n
{
#ifdef USE_OLD_WB
        if (n <= 0 || n > RWBMachine::NUM_OF_MACHINES)
                return [self init];
        string name = nameForMachine(RWBMachine(--n));
        NSString *wbname = [NSString stringWithFormat: @"%s", name.c_str()];
#ifdef GSW_IOS_DEVICE
        NSString *docsDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
        wbname = [docsDir stringByAppendingPathComponent: wbname];
#endif
        return [self initWithRobotWhiteboard: n named: wbname];
#endif
        return nil;
}


- (void) dealloc
{
        if (gu_whiteboard) delete gu_whiteboard;
        gu_whiteboard = nullptr;
}


#pragma mark - access methods

#ifdef USE_OLD_WB
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
#endif


- (NSMutableDictionary *) knownWhiteboardMessages
{
        if (knownWhiteboardMessages) return knownWhiteboardMessages;
        
        self.knownWhiteboardMessages = [NSMutableDictionary dictionaryWithCapacity: GSW_TOTAL_MESSAGE_TYPES];

        /*
         * populate array of known whiteboard message types
         */
#ifdef USE_OLD_WB
        if (!gu_whiteboard) return knownWhiteboardMessages;

        gu_simple_whiteboard *wb = gu_whiteboard->_wbd->wb;

        for (int i = 0; i < wb->num_types; i++)
        {
                NSString *type = [NSString stringWithUTF8String: wb->typenames[i].hash.string];
                [knownWhiteboardMessages setObject: [self dataTypeForMessageType: type]
                                            forKey: type];
        }
#else
        for (enum wb_types i = kwb_reserved_SubscribeToAllTypes_v; i < GSW_NUM_TYPES_DEFINED; i = static_cast<enum wb_types>(i + 1))
                knownWhiteboardMessages[@(WBTypes_stringValues[i])] = @(i);
#endif

        return knownWhiteboardMessages;
}

- (NSArray *) knownWhiteboardMessagesSortedByName
{
        return [self.knownWhiteboardMessages.allKeys sortedArrayUsingSelector: @selector(compare:)];
}


#ifdef USE_OLD_WB
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
#else
- (void) whiteboardMessageReceived: (guWhiteboard::wb_types) msgType withContent: (gu_simple_message *) wbmsg
{
        @autoreleasepool
        {
                dispatch_async(dispatch_get_main_queue(),
                ^{
                        [self receivedMessage: wbmsg ofType: msgType];
                });
        }
}

- (void) receivedMessage: (gu_simple_message *) wbmsg ofType: (guWhiteboard::wb_types) msgType
{
        if ([delegate respondsToSelector: @selector(objcWhiteboard:receivedMessage:ofType:)])
                [delegate objcWhiteboard: self
                         receivedMessage: wbmsg
                                  ofType: msgType];
}


#endif

#pragma mark - Whiteboard interaction

#ifdef USE_OLD_WB
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
#endif

static NSArray *wbnames;

+ (NSArray *) whiteboardNames
{
        if (!wbnames) wbnames = @[@"local", @"Robot 1", @"Robot 2", @"Robot 3", @"Robot 4"];

        return wbnames;
}


static NSArray *wbtypes;

+ (NSArray *) whiteboardTypes
{
        if (!wbtypes) wbtypes = @[kWBTypeBool, kWBTypeInt, kWBTypeFloat, kWBTypeString, kWBTypeArray, kWBTypeBinary, kWBTypeEmpty];

        return wbtypes;
}

#ifdef USE_OLD_WB
- (NSString *) dataTypeForWBMsg: (const WBMsg *) msg
{
        NSArray *types = [ObjCWhiteboard whiteboardTypes];

        enum WBMsg::wb_type type = msg->getType();
        if (type < [types count])
                return [types objectAtIndex: type];
        
        return @"- unknown -";
}
#endif


- (NSString *) dataTypeForMessageType: (NSString *) msgType
{
        if (!msgType.length) return @"- empty -";
        if (!gu_whiteboard) return @"- nowb -";

#ifdef USE_OLD_WB
        Whiteboard::WBResult result;
        const WBMsg msg = gu_whiteboard->getMessage([msgType UTF8String], &result);
        
        if (result == Whiteboard::METHOD_FAIL)
                return @"- none -";
        
        return [self dataTypeForWBMsg: &msg];
#else
        NSUInteger i = msgType.integerValue;
        if (i > 0 && i < GSW_NUM_TYPES_DEFINED)
                return @(WBTypes_stringValues[i]);

        return self.knownWhiteboardMessages[msgType];
#endif
}


#ifdef USE_OLD_WB
- (NSString *) cachedDataTypeForMessageType: (NSString *) msgType
{
        NSString *result = [knownWhiteboardMessages objectForKey: msgType];
        
        if (!result) result = [self dataTypeForMessageType: msgType];
        
        return result;
}


- (WBMsg::WBType) wbTypeForType: (const NSString *) dataType
{
        NSUInteger i = [wbtypes indexOfObject: dataType];
        if (i == NSNotFound)
                return WBMsg::TypeEmpty;
        
        return (WBMsg::WBType) i;
}
#endif

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



#ifdef USE_OLD_WB
- (WBMsg) wbMsg: (const NSString *) msg
         ofType: (const NSString *) dataType
    withContent: (const NSString *) content
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

- (void) postWBMessage: (const NSString *) msg
               content: (const NSString *) content
              withType: (const NSString *) dataType
{
        if (!gu_whiteboard || !msg.length) return;

        WBMsg wbmsg = [self wbMsg: msg ofType: dataType withContent: content];
        gu_whiteboard->addMessage([msg UTF8String], wbmsg);
}


- (id) getWBMessage: (const NSString *) msg
{
        Whiteboard::WBResult result = Whiteboard::METHOD_FAIL;
        WBMsg wbmsg = gu_whiteboard->getMessage([msg UTF8String], &result);

        if (result == Whiteboard::METHOD_FAIL)
                return nil;

        switch (wbmsg.getType())
        {
                case WBMsg::TypeBool:
                        return [NSNumber numberWithBool: wbmsg.getBoolValue()];

                case WBMsg::TypeInt:
                        return [NSNumber numberWithInt: wbmsg.getIntValue()];

                case WBMsg::TypeFloat:
                        return [NSNumber numberWithFloat: wbmsg.getFloatValue()];

                case WBMsg::TypeString:
                        return [NSString stringWithUTF8String: wbmsg.getStringValue().c_str()];

                case WBMsg::TypeArray:
                {
                        const vector<int> vec = wbmsg.getArrayValue();
                        NSMutableArray *array = [NSMutableArray arrayWithCapacity: vec.size()];
                        for (int i: vec)
                                [array addObject: [NSNumber numberWithInt: i]];
                        return array;
                }

                case WBMsg::TypeBinary:
                        return [NSData dataWithBytes: wbmsg.getBinaryValue()
                                              length: wbmsg.getSizeInBytes()];
                default:
                        return [NSNull null];
        }
        /* NOTREACHED */
}


- (void) subscribeTo: (const NSString *) msg
{
        wbcallback->subscribe(gu_whiteboard, [msg UTF8String]);
}
#endif

@end
