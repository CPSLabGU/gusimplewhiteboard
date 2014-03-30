//
//  wbPerfTests.m
//  wbPerfTests
//
//  Created by Rene Hexel on 30/03/2014.
//  Copyright (c) 2014 Rene Hexel. All rights reserved.
//
#import <SenTestingKit/SenTestingKit.h>
#import "post_test.h"
#import "get_test.h"

@interface wbPerfTests: SenTestCase

@end

@implementation wbPerfTests

- (void) setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void )tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void) testGet
{
    get_test getter;
    getter.run();
}


- (void) testPost
{
    post_test poster;
    poster.run(100000000);
}

@end
