/*
 *  udp_receiver.h
 *
 *  Created by Carl Lusty on 1/6/13.
 *  Copyright (c) 2013 Carl Lusty.
 *  All rights reserved.
 */

#ifndef udp_receiver_h
#define udp_receiver_h

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



class Receiver
{
public:
        int _recv_socket;
        struct sockaddr_in _mc_addr; // address information
        unsigned char *_recv_buffer; //The address of the data to be sent

        fd_set _sock_read_fd_set;
        struct timeval _select_timeout;

        gsw_udp_packet_info *_packet_data;
        int _packets_in_schedule;
        gsw_udp_packet *_packets;


        
        Receiver(gsw_udp_packet_info *packet_data, int packets_in_schedule, int timer_delay, int max_types_per_packet);
        void construct_packets_array();
        void set_nonblock(int socket);
        // get sockaddr, IPv4 or IPv6:
        void *get_in_addr(struct sockaddr *sa);
        void get_packet(int max_packet_size);

        ~Receiver();
};

//#pragma clang diagnostic pop

#endif //udp_receiver_h