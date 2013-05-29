/*
 *  udp_util.h
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */

#ifndef guudputil_h
#define guudputil_h

#include <Whiteboard.h>
#include <WBMsg.h>
#include <gu_util.h>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <list>
#include <dispatch/dispatch.h>
#include <time.h>
#include <errno.h>

#include "udp_config.h"


int get_udp_id();
void set_udp_id(int udp_id);


dispatch_source_t CreateDispatchTimer(timespec *when,
                                      uint64_t interval,
                                      uint64_t leeway,
                                      dispatch_queue_t queue,
                                      void (*function)(void *),
                                      void *data);    



#endif //guudputil_h