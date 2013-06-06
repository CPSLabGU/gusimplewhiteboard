/*
 *  udp_util.cpp
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty and Rene Hexel.
 *  All rights reserved.
 */

#include <cstdlib> //exit
#include "udp_util.h"

using namespace std;

static int my_udp_id = -1;

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

void pretty_print_packet_types(gsw_udp_packet_info *packets, int size)
{
        for (int i = 0; i < size; i++)
        {
                fprintf(stderr, "Packet:\n\tsender:\t%d\n", (int)packets[i].sender);

                for (int g = 0; g < (int)packets[i].num_of_types; g++)
                {
                        fprintf(stderr, "\t%s", guWhiteboard::WBTypes_stringValues[packets[i].offset[g]]);
                }
                fprintf(stderr, "\n");
        }
}


//Only for new types (generated not dynamic)
int get_wb_offset_from_string(string type)
{
        for(int i = 0; i < GSW_NUM_TYPES_DEFINED; i++)
        {
                if (type.compare(guWhiteboard::WBTypes_stringValues[i]) == 0)
                        return i;
        }
        fprintf(stderr, "Type unknown %s\nexiting...\n", (char *)type.c_str());
        exit(1);
}


void packet2buf(uint8_t *dst, gsw_udp_packet *src)
{
        uint8_t *off = dst;

        memcpy(off, (void*)&src->schedule_index, sizeof src->schedule_index);
        off += sizeof src->schedule_index;

        memcpy(off, (void*)&src->event_counter[0], sizeof(src->event_counter[0]) * src->num_of_types);
        off += sizeof(src->event_counter[0]) * src->num_of_types;

        memcpy(off, (void*)&src->content[0], sizeof(src->content[0]) * src->num_of_types);
        off += sizeof(src->content[0]) * src->num_of_types;
}

void buf2packet(gsw_udp_packet *dst, uint8_t *src, int num_of_types)
{
        uint8_t *off = src;

        memcpy((void*)&dst->schedule_index, off, sizeof dst->schedule_index);
        off += sizeof dst->schedule_index;

        memcpy((void*)&dst->event_counter[0], off, sizeof(u_int16_t) * num_of_types);
        off += sizeof(u_int16_t) * num_of_types;

        memcpy((void*)&dst->content[0], off, sizeof(gu_simple_message) * num_of_types);
        off += sizeof(gu_simple_message) * num_of_types;
}
