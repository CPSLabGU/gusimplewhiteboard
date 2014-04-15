//
//  ros_subscribe_test.h
//  gusimplewhiteboard
//
//  Created by Rene Hexel on 15/04/2014.
//  Copyright (c) 2014 Rene Hexel. All rights reserved.
//

#ifndef __gusimplewhiteboard__ros_subscribe_test__
#define __gusimplewhiteboard__ros_subscribe_test__

#include "ros_publish_test.h"

class ros_subscribe_test: public ros_publish_test
{
    PROPERTY(ros::Subscriber, subscriber)
public:
    ros_subscribe_test();
    virtual void run_test(long iterations);
    virtual void print(long iterations) { std::cout << "ROSS: "; perftest::print(iterations); }
};


#endif /* defined(__gusimplewhiteboard__ros_subscribe_test__) */
