/*
 *  SimpleWhiteboardTest.mm
 *  
 *  Created by René Hexel on 20/12/11.
 *  Copyright (c) 2011, 2014, 2015 Rene Hexel.
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
#import <errno.h>
#import <sys/stat.h>
#import "FSM_Control.h"
#import "SimpleWhiteboardTest.h"
#import "FilteredOneDimSonar.h"
#import "FilteredOneDimObject.h"
#import "FilteredArrayOneDimSonar.h"
#import "FilteredArrayOneDimObjects.h"
#import "FilteredArrayOneDimBall.h"

#import "FSMControlStatus.h"

#define WB_FNAME "guWhiteboard_SimpleWhiteboardTest"

using namespace guWhiteboard;
using namespace std;

/** subscription test class */
class WBSubscriber
{
        SimpleWhiteboardTest *self;
        whiteboard_watcher *watcher;
public:
	/**
	 * Test Constructor
	 */
        WBSubscriber(SimpleWhiteboardTest *t): self(t)
        {
                watcher = new whiteboard_watcher();
                watcher->subscribe(WB_TYPE_BIND(kPrint_v, WBSubscriber::sub));
                usleep(50000); //gives the monitor thread in the whiteboard a chance to get started.
        }

	/**
	 * Test Destructor
	 */
        ~WBSubscriber()
        {
                watcher->unsubscribe(kPrint_v);
                // delete watcher;
        }

	/**
	 * Trigger subscription test
	 */
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
@synthesize callbackCount, semaphore, stringValue=_stringValue;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Wdirect-ivar-access"

/**
 * Setup objects for testing
 */
- (void) setUp
{
        setenv(GSW_DEFAULT_ENV, WB_FNAME, 1);

        [super setUp];

        self.callbackCount = 0;
        self.semaphore = dispatch_semaphore_create(0);
        
        
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

/**
 * Destroy testing objects
 */
- (void) tearDown
{
	//fix compiler complaint about releasing when using ARC - Carl.
       //if (self.semaphore) dispatch_release(self.semaphore);

        self.semaphore = NULL;

        [super tearDown];
    
        unsetenv(GSW_DEFAULT_ENV);
}

/**
 * String Test function for 'simple' whiteboard setter and getter
 */
- (void) testStringPutGet
{
        string testString("Testing the Whiteboard");
        Say_t wbSpeech(testString);     // put a message on the whiteboard
        string result = wbSpeech();     // try and get it back

        XCTAssertTrue(result == testString, @"Expected result to be '%s', but got '%s'", testString.c_str(), result.c_str());
}

/**
 * Int Test function for 'simple' whiteboard setter and getter
 */
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


- (void) testSerializaitonSENSORS_TorsoJointSensors
{
    SENSORS_TorsoJointSensors testA("10Y,20P");
    XCTAssertEqualWithAccuracy(DEG2RAD(10), testA.HeadYaw  (), 0.01, @"Head Yaw match");
    XCTAssertEqualWithAccuracy(DEG2RAD(20), testA.HeadPitch(), 0.01, @"Head Pitch match");
   // XCTAssertFalse(true, @"Head Pitch match");
    
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

- (void) testSerializaitonFilteredArrayOneDimObjects
{
    FilteredOneDimObject testP("IsVisible,10,20,30,40,FRAME:100,");
    
    FilteredArrayOneDimObjects testArray(testP);
    
    FilteredOneDimObject testB=testArray.get_object(FVOGoalPostTop);
    
    XCTAssertTrue(testP.isVisible(), @"Expected  visible");
    XCTAssertTrue(testB.isVisible(), @"Expected  visible");
    XCTAssertEqual(testP.distance(), testB.distance(), @"distance match");
    XCTAssertEqual(testP.x(), testB.x(), @"'x' match");
    XCTAssertEqual(testP.y(), testB.y(), @"'y' match");
    XCTAssertEqual(testP.yaw(), testB.yaw(), @"yaw match");
    XCTAssertEqual(testP.frameCounter(), testB.frameCounter(), @"frameCounter match");
    
    FilteredOneDimObject testL("IsVisible,15,25,35,45,FRAME:105,");
    
    testArray.set_object(testL,FVOGoalPostLeftTop);
    
    FilteredOneDimObject testL1=testArray.get_object(FVOGoalPostLeftTop);
    
    XCTAssertTrue(testL.isVisible(), @"Expected  visible");
    XCTAssertTrue(testL1.isVisible(), @"Expected  visible");
    XCTAssertEqual(testL1.distance(), testL.distance(), @"distance match");
    XCTAssertEqual(testL1.x(), testL.x(), @"'x' match");
    XCTAssertEqual(testL1.y(), testL.y(), @"'y' match");
    XCTAssertEqual(testL1.yaw(), testL.yaw(), @"yaw match");
    XCTAssertEqual(testL1.frameCounter(), testL.frameCounter(), @"frameCounter match");
    
    FilteredOneDimObject testR("IsVisible,13,23,33,43,FRAME:108,");
    FilteredOneDimObject testC("IsVisible,12,22,32,42,FRAME:102,");
    
    testArray.set_object(testR,FVOGoalPostRightTop);
    testArray.set_object(testC,FVOGoalCrossBarTop);
    
    FilteredArrayOneDimObjects testArrayB(testArray);
   
    FilteredOneDimObject testPostLeft=testArrayB.get_object(FVOGoalPostLeftTop);
    FilteredOneDimObject testPostRight=testArrayB.get_object(FVOGoalPostRightTop);
    FilteredOneDimObject testCrossbar=testArrayB.get_object(FVOGoalCrossBarTop);
    XCTAssertTrue(testPostLeft.isVisible(), @"Expected  visible");
    XCTAssertEqual(testPostLeft.distance(), testL.distance(), @"distance match");
    XCTAssertEqual(testPostLeft.x(), testL.x(), @"'x' match");
    XCTAssertEqual(testPostLeft.y(), testL.y(), @"'y' match");
    XCTAssertEqual(testPostLeft.yaw(), testL.yaw(), @"yaw match");
    XCTAssertEqual(testPostLeft.frameCounter(), testL.frameCounter(), @"frameCounter match");
    XCTAssertTrue(testPostRight.isVisible(), @"Expected  visible");
    XCTAssertEqual(testPostRight.distance(), testR.distance(), @"distance match");
    XCTAssertEqual(testPostRight.x(), testR.x(), @"'x' match");
    XCTAssertEqual(testPostRight.y(), testR.y(), @"'y' match");
    XCTAssertEqual(testPostRight.yaw(), testR.yaw(), @"yaw match");
    XCTAssertEqual(testPostRight.frameCounter(), testR.frameCounter(), @"frameCounter match");
    
    XCTAssertTrue(testCrossbar.isVisible(), @"Expected  visible");
    XCTAssertEqual(testCrossbar.distance(), testC.distance(), @"distance match");
    XCTAssertEqual(testCrossbar.x(), testC.x(), @"'x' match");
    XCTAssertEqual(testCrossbar.y(), testC.y(), @"'y' match");
    XCTAssertEqual(testCrossbar.yaw(), testC.yaw(), @"yaw match");
    XCTAssertEqual(testCrossbar.frameCounter(), testC.frameCounter(), @"frameCounter match");
 
    string s =testArrayB.description();
    
    FilteredArrayOneDimObjects testArrayC(s);
    XCTAssertTrue(testArrayC.get_object(FVOGoalPostLeftTop).isVisible(), @"Expected  visible");
    XCTAssertTrue(testArrayC.get_object(FVOGoalPostRightTop).isVisible(), @"Expected  visible");
    XCTAssertEqual(testArrayC.get_object(FVOGoalPostLeftTop).distance(), testL.distance(), @"distance match");
    XCTAssertEqual(testArrayC.get_object(FVOGoalPostLeftTop).frameCounter(), testL.frameCounter(), @"frameCounter match");
    XCTAssertEqual(testArrayC.get_object(FVOGoalPostRightTop).distance(), testR.distance(), @"distance match");
    XCTAssertEqual(testArrayC.get_object(FVOGoalPostRightTop).frameCounter(), testR.frameCounter(), @"frameCounter match");
    
}

- (void) testSerializaitonFilteredArrayOneDimBall
{
    FilteredOneDimObject testT("IsVisible,10,20,30,40,FRAME:100,");
    
    FilteredArrayOneDimBall testArray(testT);
    
    FilteredOneDimObject testB=testArray.get_object(FVOBallTop);
    
    XCTAssertTrue(testT.isVisible(), @"Expected  visible");
    XCTAssertTrue(testB.isVisible(), @"Expected  visible");
    XCTAssertEqual(testT.distance(), testB.distance(), @"distance match");
    XCTAssertEqual(testT.x(), testB.x(), @"'x' match");
    XCTAssertEqual(testT.y(), testB.y(), @"'y' match");
    XCTAssertEqual(testT.yaw(), testB.yaw(), @"yaw match");
    XCTAssertEqual(testT.frameCounter(), testB.frameCounter(), @"frameCounter match");
    
    FilteredOneDimObject testBotom("IsVisible,15,25,35,45,FRAME:105,");
    
    testArray.set_object(testBotom,FVOBallBottom);
    
    FilteredOneDimObject testB1=testArray.get_object(FVOBallBottom);
    
    XCTAssertTrue(testBotom.isVisible(), @"Expected  visible");
    XCTAssertTrue(testB1.isVisible(), @"Expected  visible");
    XCTAssertEqual(testB1.distance(), testBotom.distance(), @"distance match");
    XCTAssertEqual(testB1.x(), testBotom.x(), @"'x' match");
    XCTAssertEqual(testB1.y(), testBotom.y(), @"'y' match");
    XCTAssertEqual(testB1.yaw(), testBotom.yaw(), @"yaw match");
    XCTAssertEqual(testB1.frameCounter(), testBotom.frameCounter(), @"frameCounter match");
    
    FilteredOneDimObject testOtherTop("IsVisible,13,23,33,43,FRAME:108,");
    FilteredOneDimObject testOtherbootm("IsVisible,12,22,32,42,FRAME:102,");
    
    testArray.set_object(testOtherTop,FVOBallTop);
    testArray.set_object(testOtherbootm,FVOBallBottom);
    
    FilteredArrayOneDimBall testArrayB(testArray);
    
    
    FilteredOneDimObject testOutTop=testArrayB.get_object(FVOBallTop);
    FilteredOneDimObject testOutBootm=testArrayB.get_object(FVOBallBottom);
    XCTAssertTrue(testOutTop.isVisible(), @"Expected  visible");
    XCTAssertEqual(testOutTop.distance(), testOtherTop.distance(), @"distance match");
    XCTAssertEqual(testOutTop.x(), testOtherTop.x(), @"'x' match");
    XCTAssertEqual(testOutTop.y(), testOtherTop.y(), @"'y' match");
    XCTAssertEqual(testOutTop.yaw(), testOtherTop.yaw(), @"yaw match");
    XCTAssertEqual(testOutTop.frameCounter(), testOtherTop.frameCounter(), @"frameCounter match");
    XCTAssertTrue(testOutBootm.isVisible(), @"Expected  visible");
    XCTAssertEqual(testOutBootm.distance(), testOtherbootm.distance(), @"distance match");
    XCTAssertEqual(testOutBootm.x(), testOtherbootm.x(), @"'x' match");
    XCTAssertEqual(testOutBootm.y(), testOtherbootm.y(), @"'y' match");
    XCTAssertEqual(testOutBootm.yaw(), testOtherbootm.yaw(), @"yaw match");
    XCTAssertEqual(testOutBootm.frameCounter(), testOtherbootm.frameCounter(), @"frameCounter match");
 
    
    string s =testArrayB.description();
        
        cerr << s << endl;
    
    FilteredArrayOneDimBall testArrayC(s);
    XCTAssertTrue(testArrayC.get_object(FVOBallTop).isVisible(), @"Expected  visible");
    XCTAssertTrue(testArrayC.get_object(FVOBallBottom).isVisible(), @"Expected  visible");
    XCTAssertEqual(testArrayC.get_object(FVOBallTop).distance(), testOtherTop.distance(), @"distance match");
    XCTAssertEqual(testArrayC.get_object(FVOBallTop).frameCounter(), testOtherTop.frameCounter(), @"frameCounter match");
    XCTAssertEqual(testArrayC.get_object(FVOBallBottom).distance(), testOtherbootm.distance(), @"distance match");
    XCTAssertEqual(testArrayC.get_object(FVOBallBottom).frameCounter(), testOtherbootm.frameCounter(), @"frameCounter match");
    
}

- (void) testFilteredArrayOneDimBallPutGet
{
        FilteredBallSighting_t sigthingHandler;
        
        FilteredOneDimObject testBall("IsVisible,10,20,30,40,FRAME:100,");
        FilteredArrayOneDimBall testArray(testBall);

        sigthingHandler.set(testArray);                       // write to wb
        FilteredArrayOneDimBall result = sigthingHandler(); // get back out
        FilteredOneDimObject topBallSighting = result.get_object(FVOBallTop);
        XCTAssertTrue(topBallSighting.isVisible() , @"Expecting visible");
        XCTAssertEqual(topBallSighting.distance(), testBall.distance(), @"distance match");
        XCTAssertEqual(topBallSighting.x(), testBall.x(), @"'x' match");
        XCTAssertEqual(topBallSighting.y(), testBall.y(), @"'y' match");
        XCTAssertEqual(topBallSighting.yaw(), testBall.yaw(), @"yaw match");
        XCTAssertEqual(topBallSighting.frameCounter(), testBall.frameCounter(), @"frameCounter match");
        
        FilteredOneDimObject bottomBallSighting = result.get_object(FVOBallBottom);
        XCTAssertFalse(bottomBallSighting.isVisible() , @"Expecting visible");
        XCTAssertEqual(bottomBallSighting.distance(),0, @"distance match");
        XCTAssertEqual(bottomBallSighting.x(), 0, @"'x' match");
        XCTAssertEqual(bottomBallSighting.y(), 0, @"'y' match");
        XCTAssertEqual(bottomBallSighting.yaw(), 0, @"yaw match");
        XCTAssertEqual(bottomBallSighting.frameCounter(), 0, @"frameCounter match");
     /*
        fsmStatus.set(oldStatus);
        result = fsmStatus.get();
        XCTAssertTrue(result == oldStatus, @"Expecting old status to be restored");
      */
}

- (void) testVisionBallPutGet
{
        VisionBall_t aBallHandler;
        
        VisionBall testBall("TopBall:(-42,45)@103");

        bool ballInTopIsVisible=testBall.topVisible();
        bool ballInBottomIsVisible=testBall.bottomVisible();
        int x = testBall.topX();
        int y = testBall.topY();
        int radious = testBall.topRadius();

        XCTAssertEqual(radious, 103, @"radious incorrect");

        aBallHandler.set(testBall);                       // write to wb
       
        VisionBall ballSighting = aBallHandler.get();
        
        ballInTopIsVisible=ballSighting.topVisible();
        ballInBottomIsVisible=ballSighting.bottomVisible();
        int myTopRadius=0; int centerTopX=0; int centerTopY=0;
        int myBottomRadius=0; int centerBottomX=0; int centerBottomY=0;

        XCTAssertTrue(ballInTopIsVisible, @"Expected top ball");
        if ( ballInTopIsVisible )
        {
                DBG( std::cout  << " Top ball radious  ("<< theBalls[Top]->GetRadius()   << ")" << std::endl; )
            myTopRadius = ballSighting.topRadius();
            centerTopX = ballSighting.topX();
            centerTopY = ballSighting.topY();
        }

        XCTAssertFalse(ballInBottomIsVisible, @"Expected no bottom ball");

        if ( ballInBottomIsVisible )
        {
                DBG( std::cout  << " Bottom ball radious  ("<< theBalls[Bottom]->GetRadius()   << ")" << std::endl; )
            myBottomRadius = ballSighting.bottomRadius();
            centerBottomX = ballSighting.bottomX();
            centerBottomY = ballSighting.bottomY();
        }

        XCTAssertEqual(x, centerTopX, @"'x' match");
        XCTAssertEqual(y, centerTopY, @"'y' match");
        XCTAssertEqual(radious, myTopRadius, @"radiousr match");
        XCTAssertEqual(ballSighting.frameNumber(), testBall.frameNumber(), @"frameCounter match");
        
  
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

static WBTypes nasty_wb_without_string_conversion[] = { kwb_reserved_SubscribeToAllTypes_v, kGCGameState_v, kSENSORS_FootSensors_v, kSENSORS_LedsSensors_v, kSENSORS_LegJointTemps_v, kSENSORS_TorsoJointTemps_v, kSoloTypeExample_v, kUDPRN_v, kTeleoperationControlStatus_v,
        // FIXME: vision below
    kVisionLines_v, kFSOsighting_v, kFilteredBallSighting_v, kFilteredGoalSighting_v }; // FIXME: vision

- (void) testStringPostings
{
    string testString("000");

    for (int wbtype = 1; wbtype < GSW_NUM_TYPES_DEFINED; wbtype++) try
    {
        bool result = guWhiteboard::postmsg(static_cast<WBTypes>(wbtype), testString);
        bool needStringConversion = true;
        for (size_t i = 0; i < sizeof(nasty_wb_without_string_conversion)/sizeof(nasty_wb_without_string_conversion[0]); i++)
        {
            if (wbtype == nasty_wb_without_string_conversion[i])
            {
                needStringConversion = false;
                break;
            }
        }
        XCTAssertTrue(!needStringConversion || result, @"Could not post wb message %d (%s):", wbtype, WBTypes_stringValues[wbtype]);
    }
    catch (...)
    {
        XCTAssertNoThrow(guWhiteboard::postmsg(static_cast<WBTypes>(wbtype), testString), @"Exception posting wb message %d (%s):", wbtype, WBTypes_stringValues[wbtype]);
    }
}


- (void) testEnvWhiteboardName
{
#ifndef GSW_IOS_DEVICE
    const char *wbenv = getenv(GSW_DEFAULT_ENV);
    XCTAssert(wbenv, @"Whiteboard environment variable '%s' not set", GSW_DEFAULT_ENV);
    XCTAssertTrue(strcmp(wbenv, WB_FNAME) == 0, @"Whiteboard environment '%s' instead of '%s'", wbenv, WB_FNAME);
    const char *fname = "/tmp/" WB_FNAME;
    struct stat buf;
    XCTAssertTrue(stat(fname, &buf) != -1, @"Could not open whiteboard '%s': %s", fname, strerror(errno));
    unlink(fname);
#endif
}

#pragma clang diagnostic pop

@end
