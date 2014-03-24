/*
 *  SimpleWhiteboardTest.mm
 *  
 *  Created by René Hexel on 20/12/11.
 *  Copyright (c) 2011, 2014 Rene Hexel.
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
#import "FSM_Control.h"
#import "SimpleWhiteboardTest.h"

using namespace guWhiteboard;
using namespace std;

class WBSubscriber
{
        SimpleWhiteboardTest *self;
        whiteboard_watcher *watcher;
public:
        WBSubscriber(SimpleWhiteboardTest *t): self(t)
        {
                watcher = new whiteboard_watcher(self.whiteboard->_wbd);
                watcher->subscribe(WB_TYPE_BIND(kPrint_v, WBSubscriber::sub));
                usleep(50000); //gives the monitor thread in the whiteboard a chance to get started.
        }

        ~WBSubscriber()
        {
                watcher->unsubscribe(kPrint_v);
                // delete watcher;
        }

        void sub(WBTypes, gu_simple_message *m)
        {
                Print_t value;
                string str = value.get_from(m);
                self.stringValue = [NSString stringWithUTF8String: str.c_str()];
                self.callbackCount++;
                dispatch_semaphore_signal(self.semaphore);
        }
};

@implementation SimpleWhiteboardTest
@synthesize whiteboard, callbackCount, semaphore, stringValue=_stringValue;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Wdirect-ivar-access"

- (void) setStringValue: (NSString *) stringValue
{
        if (stringValue != _stringValue)
        {
                [_stringValue release];
                _stringValue = [stringValue retain];
        }
}


- (void) setSemaphore: (dispatch_semaphore_t) aSemaphore
{
        if (aSemaphore != semaphore)
        {
                dispatch_release(semaphore);
                if (aSemaphore) dispatch_retain(semaphore = aSemaphore);
        }
}

- (void) setUp
{
        [super setUp];

        self.callbackCount = 0;
        semaphore = dispatch_semaphore_create(0);
        self.whiteboard = new Whiteboard();
        
        
        //generic wb object testing

//        generic_whiteboard_object<gu_simple_message> *testInt = new generic_whiteboard_object<gu_simple_message>(self.whiteboard->_wbd, 20);

        
        
        
//        gu_simple_message m;
//        m.sint = 2300;
//        testInt->set(m);
//
//        fprintf(stderr, "Got %d\n", testInt->get()->sint);
//        

        
        
//        exit(0);
}

- (void) tearDown
{
        if (self.whiteboard)  delete (Whiteboard *) self.whiteboard;

        self.semaphore = NULL;
        self.whiteboard = NULL;
        self.semaphore = NULL;

        [super tearDown];
}


- (void) testOldPutGet
{
        self.whiteboard->addMessage("test", WBMsg("testval"));
        WBMsg msg = self.whiteboard->getMessage("test");
        STAssertEquals(msg.getType(), WBMsg::TypeString, @"Message of type %d, but expected String", msg.getType());
        STAssertTrue(msg.getStringValue() == "testval", @"Message contains '%s', but expected 'testval'", msg.getStringValue().c_str());

        self.whiteboard->addMessage("test", WBMsg("testval2"));
        msg = self.whiteboard->getMessage("test");
        STAssertEquals(msg.getType(), WBMsg::TypeString, @"Message of type %d, but expected String", msg.getType());
        STAssertTrue(msg.getStringValue() == "testval2", @"Message contains '%s', but expected 'testval2'", msg.getStringValue().c_str());
}


- (void) testStringPutGet
{
        string testString("Testing the Whiteboard");
        Say_t wbSpeech(testString);     // put a message on the whiteboard
        string result = wbSpeech();     // try and get it back

        STAssertTrue(result == testString, @"Expected result to be '%s', but got '%s'", testString.c_str(), result.c_str());
}


- (void) testIntGetPutGetPut
{
        PlayerNumber_t playerNumber;
        int oldNumber = playerNumber(); // get what is currently on the wb
        int newNumber = 5;
        playerNumber = newNumber;       // set new number
        int result = playerNumber;      // get new number back out

        STAssertEquals(result, newNumber, @"Expected player '%d', but got '%d'", newNumber, result);

        playerNumber.set(oldNumber);
        result = playerNumber.get();

        STAssertEquals(result, oldNumber, @"Expected old player '%d', but got '%d'", oldNumber, result);
}

- (void) testFSMPutGet
{
        FSM_Status_t fsmStatus;
        FSMControlStatus oldStatus = fsmStatus();       // get old from wb
        FSMControlStatus newStatus = oldStatus;         // copy
        newStatus.fsms().reset(0);
        newStatus.fsms().set(1);
        newStatus.fsms().reset(2);
        newStatus.fsms().set(3);
        newStatus.fsms().set(4);
        fsmStatus.set(newStatus);                       // write to wb
        FSMControlStatus result = fsmStatus();          // get back out
        STAssertFalse(result.fsms()[0], @"Expecting 0 to be unset");
        STAssertTrue(result.fsms()[1], @"Expecting 1 to be set");
        STAssertFalse(result.fsms()[2], @"Expecting 2 to be unset");
        STAssertTrue(result.fsms()[3], @"Expecting 3 to be set");
        STAssertTrue(result.fsms()[4], @"Expecting 4 to be set");
        fsmStatus.set(oldStatus);
        result = fsmStatus.get();
        STAssertTrue(result.fsms() == oldStatus.fsms(), @"Expecting old status to be restored");
}


- (void) testSubscribe
{
        WBSubscriber subscriber(self);

        STAssertEquals(callbackCount, 0, @"Expected zero callback count to begin with, but got %d", callbackCount);

        string testString("Testing Whiteboard subscription");
        Print_t print(testString);
        STAssertEquals(dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER), 0L, @"Expected callback within a second");
        STAssertEquals(callbackCount, 1, @"Expected callback count of 1, but got %d", callbackCount);
        STAssertTrue(testString == self.stringValue.UTF8String, @"Expected '%s' from callback, but got '%@'", testString.c_str(), self.stringValue);

        self.stringValue = nil;

        testString = [[[NSDate date] description] UTF8String];
        print(testString);
        STAssertEquals(dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER), 0L, @"Expected second callback within a second");
        STAssertEquals(callbackCount, 2, @"Expected callback count of 2, but got %d", callbackCount);
        STAssertTrue(testString == self.stringValue.UTF8String, @"Expected '%s' from callback, but got '%@'", testString.c_str(), self.stringValue);

        self.stringValue = nil;
}

#pragma clang diagnostic pop

@end
