//
//  ros_subscribe_test.cc
//  gusimplewhiteboard
//
//  Created by Rene Hexel on 15/04/2014.
//  Copyright (c) 2014 Rene Hexel. All rights reserved.
//
#include <dispatch/dispatch.h>
#include "ros_subscribe_test.h"
#include <std_msgs/Bool.h>

long number_of_messages;

void callback(const std_msgs::Bool::ConstPtr &msg)
{
    number_of_messages += msg->data;
}


ros_subscribe_test::ros_subscribe_test(): ros_publish_test(), _subscriber(node_handle().subscribe("wbperf", 4, callback))
{
    number_of_messages = 0UL;
}



void ros_subscribe_test::run_test(long iterations)
{
    dispatch_queue_t publish_queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0UL);
    dispatch_async(publish_queue,
    ^{
        long n;
        while ((n = iterations - number_of_messages) > 0)
        {
            dispatch_apply(n, publish_queue, ^(size_t i)
            {
                std_msgs::Bool msg;
                msg.data = 1;
                if (number_of_messages < iterations)
                    publisher().publish(msg);
            });
        }
    });

    for (number_of_messages = 0; number_of_messages < iterations;)
        ros::spinOnce();
}
