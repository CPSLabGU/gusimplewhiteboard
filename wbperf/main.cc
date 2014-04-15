//
//  main.cpp
//  wbperf
//
//  Created by Rene Hexel on 30/03/2014.
//  Copyright (c) 2014 Rene Hexel. All rights reserved.
//
#include <cstdlib>
#include <iostream>

#include "post_test.h"
#include "get_test.h"

int main(int , const char * [])
{
    post_test poster;
    get_test  getter;

    getter.run();
    poster.run();

    return EXIT_SUCCESS;
}

