//
//  ros_publish_test.h
//  gusimplewhiteboard
//
//  Created by Vladimir Estivill-Castro on 15/04/2014.
//  Copyright (c) 2014 ICT. All rights reserved.
//

#ifndef __gusimplewhiteboard__ros_publish_test__
#define __gusimplewhiteboard__ros_publish_test__

#include <ros/ros.h>
#include "perftest.h"

/** test ROS publishing */
class ros_publish_test: public perftest
{
    PROPERTY(ros::NodeHandle, node_handle)
    PROPERTY(ros::Publisher, publisher)
public:
    ros_publish_test();
    virtual void run_test(long iterations);
    virtual void print(long iterations) { std::cout << "ROSP: "; perftest::print(iterations); }
};


#endif /* defined(__gusimplewhiteboard__ros_publish_test__) */
