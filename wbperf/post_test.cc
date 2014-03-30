//
//  post_test.cc
//  gusimplewhiteboard
//
//  Created by Rene Hexel on 30/03/2014.
//  Copyright (c) 2014 Rene Hexel. All rights reserved.
//

#include "post_test.h"

void post_test::run_test(long iterations)
{
    for (long i = 0; i < iterations; i++)
        set_bool_value(i & 1);
}
