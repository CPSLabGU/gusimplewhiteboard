/*
 *  udp_util.h
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */

#ifndef guudputil_h
#define guudputil_h

#include <sstream>
#include <stdio.h>
#include <string.h>
#include <list>
#include <time.h>
#include <errno.h>
#include <dispatch/dispatch.h>

#include "udp_config.h"

//Our stuff
#include "guwhiteboardtypelist_generated.h"
#include <gu_util.h>

int get_udp_id();
void set_udp_id(int udp_id);


dispatch_source_t CreateDispatchTimer(timespec *when,
                                      uint64_t interval,
                                      uint64_t leeway,
                                      dispatch_queue_t queue,
                                      void (*function)(void *),
                                      void *data);    

void pretty_print_packet_types(gsw_udp_packet_info *packets, int size);


std::vector<std::string> basic_parse(std::string string, char *tok);
int get_wb_offset_from_string(std::string type);

#endif //guudputil_h