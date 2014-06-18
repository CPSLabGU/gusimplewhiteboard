/*
 *  SimpleWhiteboardTestPlainC.m
 *
 *  Created by Rene Hexel on 18/06/2014.
 *  Copyright (c) 2014 Rene Hexel.
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
#import <XCTest/XCTest.h>
#include "gusimplewhiteboard.h"
#include "guwhiteboardtypelist_c_generated.h"
#include "wb_point.h"
#include "wb_filteredsonarobject.h"
#include "wb_filteredvisionobject.h"

static const int16_t test_x = 1, test_y = 2, test_z = 42;

@interface SimpleWhiteboardTestPlainC: XCTestCase
@property (nonatomic, assign) gu_simple_whiteboard_descriptor *wbd;
@property (nonatomic, assign) gu_simple_whiteboard *wb;
@end

@implementation SimpleWhiteboardTestPlainC

- (void) setUp
{
    [super setUp];
    if ((_wbd = get_local_singleton_whiteboard()))
        _wb = _wbd->wb;
}

- (void) tearDown
{
    _wbd = NULL;
}


- (void) testWhiteboardIsNotNULL
{
    XCTAssertNotEqual(_wbd, NULL, @"Whoa, got a NULL singleton Whiteboard");
    XCTAssertNotEqual(_wb, NULL, @"Whoa, got a NULL underlying Whiteboard");
}


- (void) testPostPoint2D
{
    struct wb_point2d point = { test_x, test_y };
    gu_simple_message *m = gsw_next_message(_wb, 0); // using reserved type
    struct wb_point2d *wbpoint = (struct wb_point2d *) m;
    *wbpoint = point;
    gsw_increment(_wb, 0);
    gsw_increment_event_counter(_wb, 0);

    XCTAssertEqual(point._x, wbpoint->_x, @"Got differing x on wb");
    XCTAssertEqual(point._y, wbpoint->_y, @"Got differing y on wb");
}


- (void) testGetPoint2D
{
    [self testPostPoint2D];

    gu_simple_message *m = gsw_current_message(_wb, 0);
    struct wb_point2d *wbpoint = (struct wb_point2d *) m;

    XCTAssertEqual(test_x, wbpoint->_x, @"Got differing x from wb");
    XCTAssertEqual(test_y, wbpoint->_y, @"Got differing y from wb");
}


- (void) testPostPoint3D
{
    struct wb_point3d point = { test_x, test_y, test_z };
    gu_simple_message *m = gsw_next_message(_wb, 0); // using reserved type
    struct wb_point3d *wbpoint = (struct wb_point3d *) m;
    *wbpoint = point;
    gsw_increment(_wb, 0);
    gsw_increment_event_counter(_wb, 0);

    XCTAssertEqual(point._x, wbpoint->_x, @"Got differing x on wb");
    XCTAssertEqual(point._y, wbpoint->_y, @"Got differing y on wb");
    XCTAssertEqual(point._z, wbpoint->_z, @"Got differing z on wb");
}


- (void) testGetPoint3D
{
    [self testPostPoint3D];

    gu_simple_message *m = gsw_current_message(_wb, 0);
    struct wb_point3d *wbpoint = (struct wb_point3d *) m;

    XCTAssertEqual(test_x, wbpoint->_x, @"Got differing x from wb");
    XCTAssertEqual(test_y, wbpoint->_y, @"Got differing y from wb");
    XCTAssertEqual(test_z, wbpoint->_z, @"Got differing z from wb");
}

@end
