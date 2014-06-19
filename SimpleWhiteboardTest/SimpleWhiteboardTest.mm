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
#import "FilteredOneDimSonar.h"
#import "FilteredOneDimObject.h"
#import "FilteredArrayOneDimSonar.h"

#import "FSMControlStatus.h"

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
                self.stringValue = [[NSString alloc] initWithUTF8String: str.c_str()];
                self.callbackCount++;
                dispatch_semaphore_signal(self.semaphore);
        }
};

@implementation SimpleWhiteboardTest
@synthesize whiteboard, callbackCount, semaphore, stringValue=_stringValue;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Wdirect-ivar-access"

- (void) setUp
{
        [super setUp];

        self.callbackCount = 0;
        self.semaphore = dispatch_semaphore_create(0);
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
        if (self.whiteboard)  delete static_cast<Whiteboard *>(self.whiteboard);
        if (self.semaphore) dispatch_release(self.semaphore);

        self.whiteboard = NULL;
        self.semaphore = NULL;

        [super tearDown];
}


- (void) testOldPutGet
{
        self.whiteboard->addMessage("test", WBMsg("testval"));
        WBMsg msg = self.whiteboard->getMessage("test");
        XCTAssertEqual(msg.getType(), WBMsg::TypeString, @"Message of type %d, but expected String", msg.getType());
        XCTAssertTrue(msg.getStringValue() == "testval", @"Message contains '%s', but expected 'testval'", msg.getStringValue().c_str());

        self.whiteboard->addMessage("test", WBMsg("testval2"));
        msg = self.whiteboard->getMessage("test");
        XCTAssertEqual(msg.getType(), WBMsg::TypeString, @"Message of type %d, but expected String", msg.getType());
        XCTAssertTrue(msg.getStringValue() == "testval2", @"Message contains '%s', but expected 'testval2'", msg.getStringValue().c_str());
}


- (void) testStringPutGet
{
        string testString("Testing the Whiteboard");
        Say_t wbSpeech(testString);     // put a message on the whiteboard
        string result = wbSpeech();     // try and get it back

        XCTAssertTrue(result == testString, @"Expected result to be '%s', but got '%s'", testString.c_str(), result.c_str());
}


- (void) testIntGetPutGetPut
{
        PlayerNumber_t playerNumber;
        int oldNumber = playerNumber(); // get what is currently on the wb
        int newNumber = 5;
        playerNumber = newNumber;       // set new number
        int result = playerNumber;      // get new number back out

        XCTAssertEqual(result, newNumber, @"Expected player '%d', but got '%d'", newNumber, result);

        playerNumber.set(oldNumber);
        result = playerNumber.get();

        XCTAssertEqual(result, oldNumber, @"Expected old player '%d', but got '%d'", oldNumber, result);
}

- (void) testFSMPutGet
{
        FSM_Status_t fsmStatus;
        FSMControlStatus oldStatus = fsmStatus();       // get old from wb
        FSMControlStatus newStatus = oldStatus;         // copy
        newStatus.clr(0);
        newStatus.set(1);
        newStatus.clr(2);
        newStatus.set(3);
        newStatus.set(4);
        fsmStatus.set(newStatus);                       // write to wb
        FSMControlStatus result = fsmStatus();          // get back out
        XCTAssertFalse(result.get(0), @"Expecting 0 to be unset");
        XCTAssertTrue(result.get(1), @"Expecting 1 to be set");
        XCTAssertFalse(result.get(2), @"Expecting 2 to be unset");
        XCTAssertTrue(result.get(3), @"Expecting 3 to be set");
        XCTAssertTrue(result.get(4), @"Expecting 4 to be set");
        fsmStatus.set(oldStatus);
        result = fsmStatus.get();
        XCTAssertTrue(result == oldStatus, @"Expecting old status to be restored");
}

- (void) testSerializaitonFilteredSonarObject
{
        FilteredOneDimSonar testA("");
        
        XCTAssertEqual(sizeof(testA), sizeof(wb_filteredsonarobject), @"Size %ld of testA does not match size %ld of wb_filteredsonarobject", sizeof(testA), sizeof(wb_filteredsonarobject));
        
       XCTAssertFalse(testA.isVisible(), @"Expected not visible");
        
        FilteredOneDimSonar testB("IsVisible,10,FRAME:100,");
        
        XCTAssertTrue(testB.isVisible(), @"Expected  visible");
        XCTAssertEqual(10, testB.distance(), @"Distance match");
        XCTAssertEqual(100, testB.frameCounter(), @"frameCounter match");
    
       string s = testB.description();
    
       FilteredOneDimSonar testC(s);
       XCTAssertTrue(testC.isVisible(), @"Expected  visible");
       XCTAssertEqual(testC.distance(), testB.distance(), @"Distance match");
       XCTAssertEqual(testC.frameCounter(), testB.frameCounter(), @"frameCounter match");
    

}

- (void) testSerializaitonFilteredOneDimObject
{
        FilteredOneDimObject testA("");

        XCTAssertEqual(sizeof(testA), sizeof(wb_filteredvisionobject), @"Size %ld of testA does not match size %ld of wb_filteredvisionobject", sizeof(testA), sizeof(wb_filteredvisionobject));

        XCTAssertFalse(testA.isVisible(), @"Expected not visible");
        
        FilteredOneDimObject testB("IsVisible,10,20,30,40,FRAME:100,");
        
        XCTAssertTrue(testB.isVisible(), @"Expected  visible");
        XCTAssertEqual(10, testB.distance(), @"distance match");
        XCTAssertEqual(20, testB.x(), @"'x' match");
        XCTAssertEqual(30, testB.y(), @"'y' match");
        XCTAssertEqual(40, testB.yaw(), @"yaw match");
        XCTAssertEqual(100, testB.frameCounter(), @"frameCounter match");
    
        string s = testB.description();
    
        FilteredOneDimObject testC(s);
        XCTAssertTrue(testC.isVisible(), @"Expected  visible");
        XCTAssertEqual(testC.distance(), testB.distance(), @"distance match");
        XCTAssertEqual(testC.x(), testB.x(), @"'x' match");
        XCTAssertEqual(testC.y(), testB.y(), @"'y' match");
        XCTAssertEqual(testC.yaw(), testB.yaw(), @"yaw match");
        XCTAssertEqual(testC.frameCounter(), testB.frameCounter(), @"frameCounter match");
    
}

- (void) testSerializaitonFilteredArrayOneDimSonar
{
    FilteredOneDimSonar testA("IsVisible,10,FRAME:100,");
    
    FilteredArrayOneDimSonar testArray(testA);
    
    FilteredOneDimSonar testB=testArray.get_object(FSLeft);
    
    XCTAssertTrue(testA.isVisible(), @"Expected  visible");
    XCTAssertTrue(testB.isVisible(), @"Expected  visible");
    XCTAssertEqual(testA.distance(), testB.distance(), @"distance match");
    XCTAssertEqual(testA.frameCounter(), testB.frameCounter(), @"frameCounter match");
    
    FilteredOneDimSonar testC("IsVisible,20,FRAME:200,");
    
    testArray.set_object(testC,FSRight);
    
    FilteredOneDimSonar testD=testArray.get_object(FSRight);
    
    XCTAssertTrue(testC.isVisible(), @"Expected  visible");
    XCTAssertTrue(testD.isVisible(), @"Expected  visible");
    XCTAssertEqual(testC.distance(), testD.distance(), @"distance match");
    XCTAssertEqual(testC.frameCounter(), testD.frameCounter(), @"frameCounter match");
    
    
    FilteredArrayOneDimSonar testArrayB(testArray);
    FilteredOneDimSonar testE=testArrayB.get_object(FSLeft);
    FilteredOneDimSonar testF=testArrayB.get_object(FSRight);
    XCTAssertTrue(testE.isVisible(), @"Expected  visible");
    XCTAssertTrue(testF.isVisible(), @"Expected  visible");
    XCTAssertEqual(testE.distance(), testB.distance(), @"distance match");
    XCTAssertEqual(testE.frameCounter(), testB.frameCounter(), @"frameCounter match");
    XCTAssertEqual(testF.distance(), testC.distance(), @"distance match");
    XCTAssertEqual(testF.frameCounter(), testC.frameCounter(), @"frameCounter match");
    
    string s =testArrayB.description();
    
    FilteredArrayOneDimSonar testArrayC(s);
    XCTAssertTrue(testArrayC.get_object(FSLeft).isVisible(), @"Expected  visible");
    XCTAssertTrue(testArrayC.get_object(FSRight).isVisible(), @"Expected  visible");
    XCTAssertEqual(testArrayC.get_object(FSLeft).distance(), testB.distance(), @"distance match");
    XCTAssertEqual(testArrayC.get_object(FSLeft).frameCounter(), testB.frameCounter(), @"frameCounter match");
    XCTAssertEqual(testArrayC.get_object(FSRight).distance(), testC.distance(), @"distance match");
    XCTAssertEqual(testArrayC.get_object(FSRight).frameCounter(), testC.frameCounter(), @"frameCounter match");
 
    
}

- (void) testSubscribe
{
        WBSubscriber subscriber(self);

        XCTAssertEqual(callbackCount, 0, @"Expected zero callback count to begin with, but got %d", callbackCount);

        string testString("Testing Whiteboard subscription");
        Print_t print(testString);
        XCTAssertEqual(dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER), 0L, @"Expected callback within a second");
        XCTAssertEqual(callbackCount, 1, @"Expected callback count of 1, but got %d", callbackCount);
        XCTAssertTrue(testString == self.stringValue.UTF8String, @"Expected '%s' from callback, but got '%@'", testString.c_str(), self.stringValue);

        testString = [[[NSDate date] description] UTF8String];
        print(testString);
        XCTAssertEqual(dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER), 0L, @"Expected second callback within a second");
        XCTAssertEqual(callbackCount, 2, @"Expected callback count of 2, but got %d", callbackCount);
        XCTAssertTrue(testString == self.stringValue.UTF8String, @"Expected '%s' from callback, but got '%@'", testString.c_str(), self.stringValue);
}

static WBTypes nasty_wb_without_string_conversion[] = { kwb_reserved_SubscribeToAllTypes_v, kGCGameState_v, kSENSORS_FootSensors_v, kSENSORS_LedsSensors_v, kSENSORS_LegJointTemps_v, kSENSORS_TorsoJointTemps_v, kFSM_Names_v, kSoloTypeExample_v, kUDPRN_v, kTeleoperationControlStatus_v,
        // FIXME: vision below
        kFSOsighting_v, kFilteredBallSighting_v, kFilteredGoalSighting_v }; // FIXME: vision

- (void) testStringPostings
{
    string testString("000");

    for (int wbtype = 1; wbtype < GSW_NUM_TYPES_DEFINED; wbtype++)
    {
        bool result = guWhiteboard::postmsg(static_cast<WBTypes>(wbtype), testString);
        bool needStringConversion = true;
        for (int i = 0; i < sizeof(nasty_wb_without_string_conversion)/sizeof(nasty_wb_without_string_conversion[0]); i++)
        {
            if (wbtype == nasty_wb_without_string_conversion[i])
            {
                needStringConversion = false;
                break;
            }
        }
        XCTAssertTrue(!needStringConversion || result, @"Could not post wb message %d (%s):", wbtype, WBTypes_stringValues[wbtype]);
    }
}

#pragma clang diagnostic pop

@end
