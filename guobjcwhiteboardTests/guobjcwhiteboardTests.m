//
//  guobjcwhiteboardTests.m
//  guobjcwhiteboardTests
//
//  Created by René Hexel on 6/05/12.
//  Copyright (c) 2012, 2014 Rene Hexel. All rights reserved.
//
#import <XCTest/XCTest.h>
#import <gusimplewhiteboard.h>
#import "ObjCWhiteboard.h"
#import <guwhiteboardtypelist_c_generated.h>

@interface guobjcwhiteboardTests: XCTestCase

@property (nonatomic, strong) ObjCWhiteboard *whiteboard;

@end


@implementation guobjcwhiteboardTests

- (void)setUp
{
    [super setUp];

    self.whiteboard = [[ObjCWhiteboard alloc] init];
}

- (void)tearDown
{
    self.whiteboard = nil;

    [super tearDown];
}

- (void) testPost
{
    XCTAssertTrue([self.whiteboard postWBMessageOfType: kSpeech_v withContent: @"Hello"]);
}

- (void) testGet
{
    NSString *testString = NSStringFromSelector(_cmd);
    XCTAssertTrue([self.whiteboard postWBMessageOfType: kSpeech_v withContent: testString]);
    NSString *result = [self.whiteboard getMessageOfType: kSpeech_v];
    XCTAssertNotNil(result, @"Expected non-nil result for speech message");
    XCTAssertEqualObjects(result, testString, @"Expected wb get to yield post result");
}

@end
