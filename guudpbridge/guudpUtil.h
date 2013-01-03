/*
 *  guudpbridgenetworkutil.h
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

#include "guudpConfig.h"


int get_udp_id();
void set_udp_id(int udp_id);

static u_int32_t alt_hash(const char *s);
static u_int32_t hash_of(const char *s);

static void printWBMsg(std::string dataName, WBMsg *value);
static WBMsg getWBMsg(gu_simple_message *m);    
void convWBMsgToSimpleMsg(WBMsg *value, gsw_simple_message *m);

int gsw_hash_for_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name);


dispatch_source_t CreateDispatchTimer(timespec *when,
                                      uint64_t interval,
                                      uint64_t leeway,
                                      dispatch_queue_t queue,
                                      void (*function)(void *),
                                      void *data);    



#endif //guudputil_h