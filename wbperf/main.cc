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
#ifndef NO_ROS
#include "ros_publish_test.h"
#endif

int main(int argc, char **argv)
{
    post_test poster;
    get_test  getter;
#ifndef NO_ROS
    ros::init(argc, argv, "ros_publish_test");

    ros_publish_test ros_publisher;
#else
    (void) argc;
    (void) argv;
#endif

    getter.run();
    poster.run();
#ifndef NO_ROS
    ros_publisher.run();
#endif

    return EXIT_SUCCESS;
}

