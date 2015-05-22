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
#include <gugenericwhiteboardobject.h>
#include <guwhiteboardtypelist_generated.h>
#include <guwhiteboardtypelist_c_generated.h>
#include <guwhiteboardposter.h>
#include <guwhiteboardgetter.h>
#include <guwhiteboardwatcher.h>

#import "ObjCWhiteboard.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdirect-ivar-access"
#pragma clang diagnostic ignored "-Warc-repeated-use-of-weak"
#pragma clang diagnostic ignored "-Wreceiver-is-weak"
#pragma clang diagnostic ignored "-Wswitch-enum"
#pragma clang diagnostic ignored "-Wselector"

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
        const char *gsw_global_whiteboard_name;

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

- (void) whiteboardMessageReceived: (wbtypes_t) msgType withContent: (gu_simple_message *) wbmsg;

@end

class ObjCWBCallback
{
        ObjCWhiteboard *self;
public:
        ObjCWBCallback(ObjCWhiteboard *s, oc_watcher_t *watcher): self(s)
        {
                watcher->subscribe(createWBFunctor<ObjCWBCallback>(this, &ObjCWBCallback::callback, kwb_reserved_SubscribeToAllTypes_v));
        }
        void callback(guWhiteboard::WBTypes t, gu_simple_message *msg) { [self whiteboardMessageReceived: t withContent: msg]; }
};

#pragma mark - class implementation

@implementation ObjCWhiteboard
@synthesize delegate;
@synthesize gu_whiteboard;
@synthesize wbcallback;
@synthesize knownWhiteboardMessages;

/**
 *  Designated local whiteboard initialiser.
 *
 *  @param wbname       file name of the whiteboard to use or nil for default
 *  @return an objective C wrapper around the local whiteboard
 */
- (id) initWithWhiteboardNamed: (NSString *) wbname
{
        if (!(self = [super init]))
                return nil;

        if (wbname.length)
                gu_whiteboard = gsw_new_whiteboard(wbname.UTF8String);
        else
                gu_whiteboard = get_local_singleton_whiteboard();

        _watcher = new whiteboard_watcher(gu_whiteboard);

        wbcallback = new ObjCWBCallback(self, _watcher);

        return self;
}


/**
 * Robot whiteboard initialiser.
 *
 * @param n             robot whiteboard number
 * @param wbname        whiteboard file name to use
 * @return an initialised instance of the given remote whiteboard or nil
 */
extern void setup_udp_whiteboard_with_id(int id);

- (id) initWithRobotWhiteboard: (NSInteger) n named: (NSString *) wbname
{
        if (!(self = [super init]))
                return nil;

        if (wbname.length)
                gu_whiteboard = gsw_new_numbered_whiteboard(wbname.UTF8String, static_cast<int>(n));
        else if (n)
        {
                gu_whiteboard = gswr_new_whiteboard(static_cast<int>(n));
                dispatch_queue_t q = dispatch_queue_create("wb.udp", DISPATCH_QUEUE_CONCURRENT);
                dispatch_async(q, ^{
                        setup_udp_whiteboard_with_id(n);
                });

        }
        else
                gu_whiteboard = get_local_singleton_whiteboard();

        _watcher = new whiteboard_watcher(gu_whiteboard);

        wbcallback = new ObjCWBCallback(self, _watcher);

        return self;
}


/// convenience initialiser returning the default whiteboard
- (id) init
{
#ifdef GSW_IOS_DEVICE
        NSString *docsDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
        return [self initWithWhiteboardNamed: [docsDir stringByAppendingPathComponent: @"guWhiteboard"]];
#else
        return [self initWithWhiteboardNamed: nil];
#endif
}


/// robot whiteboard constructor (not yet implemented)
- (id) initWithRobotNumbered: (NSInteger) n
{
        return [self initWithRobotWhiteboard: n named: nil];
}


/// delete the whiteboard on release
- (void) dealloc
{
        gsw_free_whiteboard(gu_whiteboard);
        gu_whiteboard = nullptr;
}


#pragma mark - access methods

/// return a mapping between message type names and type indexes
- (NSMutableDictionary *) knownWhiteboardMessages
{
        if (knownWhiteboardMessages) return knownWhiteboardMessages;
        
        self.knownWhiteboardMessages = [NSMutableDictionary dictionaryWithCapacity: GSW_TOTAL_MESSAGE_TYPES];

        /*
         * populate dictionary of known whiteboard message types
         */
        for (enum wb_types i = kwb_reserved_SubscribeToAllTypes_v; i < GSW_NUM_TYPES_DEFINED; i = static_cast<enum wb_types>(i + 1))
                knownWhiteboardMessages[@(WBTypes_stringValues[i])] = @(i);

        return knownWhiteboardMessages;
}

/// return an array of the known whiteboard names sorted alphabetically
- (NSArray *) knownWhiteboardMessagesSortedByName
{
        return [self.knownWhiteboardMessages.allKeys sortedArrayUsingSelector: @selector(compare:)];
}


/// subscription queue callback when a whiteboard message is received
- (void) whiteboardMessageReceived: (wbtypes_t) msgType withContent: (gu_simple_message *) wbmsg
{
        @autoreleasepool
        {
                dispatch_async(dispatch_get_main_queue(),
                ^{
                        [self receivedMessage: wbmsg ofType: msgType];
                });
        }
}

/// main thread callback for received message
- (void) receivedMessage: (gu_simple_message *) wbmsg ofType: (wbtypes_t) msgType
{
        if ([delegate respondsToSelector: @selector(objcWhiteboard:receivedMessage:ofType:)])
                [delegate objcWhiteboard: self
                         receivedMessage: wbmsg
                                  ofType: msgType];
}


#pragma mark - Whiteboard interaction

/**
 * Get a message with the given type index off the whiteboard.
 * This is deprecated as it uses string conversion, which
 * may only be useful for a generic whiteboard monitor.
 * Better to use the low level C or C++ types directly off the
 * ObjcWhiteboard's gu_whiteboard pointer.
 *
 * @param typeName      whiteboard type name to use
 * @return message content as a string or nil if unsupported
 */
- (NSString *) getMessageOfType: (wbtypes_t) msgType
{
        return [self contentForWBMsg: nullptr ofType: msgType];
}


/**
 * Get a message with the given type name off the whiteboard.
 * This is deprecated as it uses string conversion as well as
 * a type string instead of the more efficient type index.
 * This may only be useful for a generic whiteboard monitor.
 * Better to use the low level C or C++ types directly off the
 * ObjcWhiteboard's gu_whiteboard pointer.
 *
 * @param typeName      whiteboard type name to use
 * @return message content as a string or nil if unsupported
 */
- (NSString *) getMessageOfTypeNamed: (const NSString *) typeName
{
        NSNumber *typeNumber = self.knownWhiteboardMessages[typeName];
        wbtypes_t msgType = static_cast<wbtypes_t>(typeNumber.intValue);

        return [self contentForWBMsg: nullptr ofType: msgType];
}


/**
 * Use string conversion to return the content of the given whiteboard message
 * as an Objective-C string.
 *
 * @param msg   whiteboard message to convert (nil to perform a getmsg())
 * @param type  whiteboard message index (needed for string conversion semantics)
 * @return message content as a string or nil if unsupported
 */
- (NSString *) contentForWBMsg: (const gu_simple_message *) msg ofType: (wbtypes_t) type
{
        std::string content = guWhiteboard::getmsg(static_cast<guWhiteboard::WBTypes>(type), const_cast<gu_simple_message *>(msg));
        NSString *contentString = nil;
        if (content != "##unsupported##")
                contentString = @(content.c_str());

        return contentString;
}



static NSArray *wbnames;

/**
 * Return an array of names for whiteboards
 * @return array containing a readable name for all whiteboards
 */
+ (NSArray *) whiteboardNames
{
        if (!wbnames) wbnames = @[@"local", @"Robot 1", @"Robot 2", @"Robot 3", @"Robot 4", @"Robot 5"];

        return wbnames;
}


static NSArray *wbtypes;

/**
 * Return an array of known whiteboard type names
 * @return array containing all known whiteboard type names
 */
+ (NSArray *) whiteboardTypes
{
        if (wbtypes) return wbtypes;

        NSMutableArray *types = [NSMutableArray arrayWithCapacity: GSW_NUM_TYPES_DEFINED];
        for (NSInteger i = kwb_reserved_SubscribeToAllTypes_v; i < GSW_NUM_TYPES_DEFINED; i++)
                types[i] = @(WBTypes_stringValues[i]);

        wbtypes = types.copy;

        return wbtypes;
}


/**
 * get the type name for the given whiteboard message type
 * @param msgType       whiteboard type index
 * @return name of the whiteboard message at the index
 */
- (NSString *) typeNameForMessageType: (wbtypes_t) msgType
{
        if (!gu_whiteboard) return @"- nowb -";

        NSUInteger i = static_cast<NSUInteger>(msgType);
        if (i > 0 && i < GSW_NUM_TYPES_DEFINED)
                return @(WBTypes_stringValues[i]);

        return self.knownWhiteboardMessages[@(msgType)] ?: @"- none -";
}


/**
 * Return the whiteboard type index for the given type name string
 * @param dataType      whiteboard type name
 * @return whiteboard type index (or 0 if not found)
 */
- (wbtypes_t) wbTypeForTypeNamed: (const NSString *) dataType
{
        NSNumber *typeNumber = self.knownWhiteboardMessages[dataType];
        wbtypes_t type = static_cast<wbtypes_t>(typeNumber.intValue);

        return type;
}


 /**
 * Post a message with a given type and a given string content to the whiteboard.
 * Using this method is deprecated as it uses string conversion for the message
 * content.  (This may be useful only if you are implementing a generic
 * whiteboard poster.)
 * Better to use the low level C++ message on the ObjcWhiteboard instance's
 * gu_whiteboard pointer.
 */
- (BOOL) postWBMessageOfType: (wbtypes_t) msgType withContent: (const NSString *) content
{
        std::string message_content = std::string(content.UTF8String);

    return guWhiteboard::postmsg(static_cast<guWhiteboard::WBTypes>(msgType), message_content) != false;
}


/**
 * Post a message with a given type name and a given string content to the
 * whiteboard.
 * Using this method is deprecated as it uses string conversion for both
 * the whiteboard type name and the message content.  (This may be useful
 * only if you are implementing a generic whiteboard poster.)
 * Better to use the low level C++ message on the ObjcWhiteboard instance's
 * gu_whiteboard pointer.
 */
- (BOOL) postWBMessageOfTypeNamed: (const NSString *) msg withContent: (const NSString *) content
{
        wbtypes_t index = [self wbTypeForTypeNamed: msg];
        std::string message_content = std::string(content.UTF8String);

        return guWhiteboard::postmsg(static_cast<guWhiteboard::WBTypes>(index), message_content) != false;
}


/**
 * Get a message from the whiteboard and convert to an Objective-C type.
 * Mostly, this will just return the string representation of that message.
 * Using this method is deprecated and only useful for generic whiteboard
 * monitoring tools.  Better to use the C++ message on the ObjcWhiteboard
 * instance's gu_whiteboard pointer.
 * @param msg   name of the whiteboard message to get
 * @return Objective C representation of the message or @"##unsupported##"
 */
- (id) getWBMessage: (const NSString *) msg
{
        NSNumber *typeNumber = self.knownWhiteboardMessages[msg];
        wbtypes_t msgType = static_cast<wbtypes_t>(typeNumber.intValue);

        switch (msgType)
        {
                case kPlayerNumber_v:
                {
                        PlayerNumber_t player(gu_whiteboard);
                        return @(player.get());
                }
#if 0
                case kXEyesPos_v:
                {
                        XEyesPos_t eyes(gu_whiteboard);
                        Point2D eyePos = eyes.get();
                        NSPoint eyePoint = { static_cast<CGFloat>(eyePos.x()), static_cast<CGFloat>(eyePos.y()) };
                        return [NSValue valueWithPoint: eyePoint];
                }
#endif
                default:
                        return [self getMessageOfTypeNamed: msg];
        }
        /* NOTREACHED */
}

@end

#pragma clang diagnostic pop
