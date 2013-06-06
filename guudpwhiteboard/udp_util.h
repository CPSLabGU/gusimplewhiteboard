/*
 *  udp_util.h
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */

#ifndef guudputil_h
#define guudputil_h


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-macros"
#undef __block
#define __block _xblock
#include <sstream>
#undef __block
#define __block __attribute__((__blocks__(byref)))
#pragma clang diagnostic pop

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

void buf2packet(gsw_udp_packet *dst, unsigned char *src, int num_of_types);
void packet2buf(unsigned char *dst, gsw_udp_packet *src);

#endif //guudputil_h