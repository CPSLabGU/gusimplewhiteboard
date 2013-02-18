/*
 *  SimpleWhiteboardTest.mm
 *  
 *  Created by René Hexel on 20/12/11.
 *  Copyright (c) 2011 Rene Hexel.
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
#import <SenTestingKit/SenTestingKit.h>
#import "SimpleWhiteboardTest.h"

using namespace guWhiteboard;
using namespace std;

class WBSubscriber
{
        SimpleWhiteboardTest *self;
public:
        WBSubscriber(Whiteboard *w, SimpleWhiteboardTest *t): self(t)
        {
                whiteboard_watcher *watcher = new whiteboard_watcher(self.whiteboard->_wbd);
//                watcher->subscribe(WB_BIND(WBSubscriber::sub));
//                watcher->subscribe(WB_TYPE_BIND(WBTypes::kNaoIsReadyToRun, WBSubscriber::sub));
                usleep(1000000); //gives the monitor thread in the whiteboard a chance to get started.
                
//                Whiteboard::WBResult r;
//                w->subscribeToMessage("subtest", WB_BIND(WBSubscriber::sub), r);
//                STAssertEquals(r, Whiteboard::METHOD_OK, @"Subscription 'subtest' failed");
        }

        void sub(std::string str, WBMsg *m)
        {
                
        }
        
        void sub(WBTypes t, gu_simple_message *m)
        {
                self.callbackCount++;
//                fprintf(stdout, "Type: %s\tm: %d\n", (char *)WBTypes_stringValues[type_map[t]].c_str(), m->sint);
//                STAssertTrue(type == "subtest", @"Message of type '%s', but expected 'subtest'", type.c_str());
//                STAssertEquals(m->getIntValue(), 42, @"Message '%s' with incorrect value", type.c_str());
                dispatch_semaphore_signal(self.semaphore);
        }
};

@implementation SimpleWhiteboardTest
@synthesize whiteboard, callbackCount, semaphore;


- (void) setUp
{
        [super setUp];

        
        
        self.semaphore = dispatch_semaphore_create(0);
        self.whiteboard = new Whiteboard();
        
        
        //generic wb object testing

        generic_whiteboard_object<gu_simple_message> *testInt = new generic_whiteboard_object<gu_simple_message>(self.whiteboard->_wbd, 20);
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
    
        [super tearDown];
}

- (void) testPutGet
{
//        self.whiteboard->addMessage("test", WBMsg("testval"));
//        WBMsg msg = self.whiteboard->getMessage("test");
//        STAssertEquals(msg.getType(), WBMsg::TypeString, @"Message of type %d, but expected String", msg.getType());
//        STAssertTrue(msg.getStringValue() == "testval", @"Message contains '%s', but expected 'testval'", msg.getStringValue().c_str());
//
//        self.whiteboard->addMessage("test", WBMsg("testval2"));
//        msg = self.whiteboard->getMessage("test");
//        STAssertEquals(msg.getType(), WBMsg::TypeString, @"Message of type %d, but expected String", msg.getType());
//        STAssertTrue(msg.getStringValue() == "testval2", @"Message contains '%s', but expected 'testval'", msg.getStringValue().c_str());
}


- (void) testCallback
{
        WBSubscriber subscriber(self.whiteboard, self);
//                generic_whiteboard_object<int> testInt(self.whiteboard->_wbd, WBTypes::kNaoIsReadyToRun);
                int m;
//        for (int i = 0; i<1000; i++) {
//                usleep(10000);
                m = 42;
//                testInt = m;
//        }
        
	guWhiteboard::kRunVisionPipelineTest_t runVision;
//	guWhiteboard::kRunVisionPipeline *runVision = new guWhiteboard::kRunVisionPipeline();
	bool on = true;
	runVision.set(on);
	
//        self.whiteboard->addMessage("subtest", WBMsg(42));
        dispatch_time_t t = dispatch_time(DISPATCH_TIME_NOW, 20 * NSEC_PER_SEC);
        dispatch_semaphore_wait(self.semaphore, t);
        STAssertEquals(self.callbackCount, 1, @"Invalid callback count");
}

@end
