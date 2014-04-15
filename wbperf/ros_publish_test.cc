//
//  ros_publish_test.cpp
//  gusimplewhiteboard
//
//  Created by Vladimir Estivill-Castro on 15/04/2014.
//  Copyright (c) 2014 ICT. All rights reserved.
//
#include "ros_publish_test.h"
#include <std_msgs/Bool.h>

ros_publish_test::ros_publish_test(): perftest(), _node_handle(), _publisher(_node_handle.advertise<std_msgs::Bool>("wbperf", 4))
{
}


void ros_publish_test::run_test(long iterations)
{
    for (long i = 0; i < iterations; i++)
    {
        std_msgs::Bool msg;
        msg.data = static_cast<bool>(i & 1);
        publisher().publish(msg);
        ros::spinOnce();
    }
}
