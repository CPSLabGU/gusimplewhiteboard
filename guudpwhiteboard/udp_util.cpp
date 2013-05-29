/*
 *  udp_util.cpp
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */
#define _FROM_WHITEBOARD_CC_


#include "udp_util.h"



int my_udp_id = -1;

int get_udp_id()
{
    return my_udp_id;
}

void set_udp_id(int udp_id)
{
    my_udp_id = udp_id;
}


//https://developer.apple.com/library/mac/#documentation/General/Conceptual/ConcurrencyProgrammingGuide/GCDWorkQueues/GCDWorkQueues.html
dispatch_source_t CreateDispatchTimer(timespec *when,
                                      uint64_t interval,
                                      uint64_t leeway,
                                      dispatch_queue_t queue,
                                      void (*function)(void *),
                                      void *data)
{
    dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER,
                                                     0, 0, queue);
    if (timer)   
    {
        dispatch_set_context(timer, data);
        //        dispatch_source_set_timer(timer, dispatch_time(DISPATCH_TIME_NOW, secToWait * NSEC_PER_SEC), interval, leeway);
        dispatch_source_set_timer(timer, dispatch_walltime(when, 0), interval, leeway);
        dispatch_source_set_event_handler_f(timer, function);
        dispatch_resume(timer);
    }
    return timer;
}
