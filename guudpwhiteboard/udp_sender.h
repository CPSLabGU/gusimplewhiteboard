/*
 *  udp_sender.h
 *
 *  Created by Carl Lusty on 1/6/13.
 *  Copyright (c) 2013 Carl Lusty.
 *  All rights reserved.
 */

#ifndef udp_sender_h
#define udp_sender_h

//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <errno.h>
//#include <string.h>
//#include <sys/types.h>
//#include <sys/socket.h>

//#include <netdb.h>
//#include <string.h>

#include "udp_config.h"

#include "guwhiteboardtypelist_generated.h"

#include <netinet/in.h> //sockaddr_in

//#ifdef bool
//#undef bool
//#endif
//
//#ifdef true
//#undef true
//#undef false
//#endif

//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wpadded"



class Sender
{
public:
        int _send_socket;
        struct sockaddr_in _mc_addr; // address information
        unsigned char *_send_buffer; //The address of the data to be sent

        gsw_udp_packet_info *_packet_data;
        int _packets_in_schedule;
        gsw_udp_packet *_packets;

        int _current_sender_index;
        dispatch_source_t _sender_timer;

        Sender(gsw_udp_packet_info *packet_data, int packets_in_schedule, int timer_delay);
        void construct_packets_array();

        ~Sender();
};

//#pragma clang diagnostic pop

#endif //udp_sender_h
