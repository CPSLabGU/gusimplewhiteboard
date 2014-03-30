//
//  get_test.cc
//  gusimplewhiteboard
//
//  Created by Rene Hexel on 30/03/2014.
//  Copyright (c) 2014 ICT. All rights reserved.
//

#include "get_test.h"

long get_test_value;

void get_test::run_test(long iterations)
{
    long val = 0L;

    for (long i = 0; i < iterations; i++)
        val += bool_value();

    get_test_value = val;
}
