/*
 *  udp_receiver.h
 *
 *  Created by Carl Lusty on 1/6/13.
 *  Copyright (c) 2013 Carl Lusty and Rene Hexel.
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


 /**
 * Class that gets messages for the distributed whiteboard
 */       
class Receiver
{
public:
        int _recv_socket;
        struct sockaddr_in _mc_addr; // address information
        uint8_t *_recv_buffer; //The address of the data to be sent

        fd_set _sock_read_fd_set;
        struct timeval _select_timeout;

        gsw_udp_packet_info *_packet_data;
        int _packets_in_schedule;
        gsw_udp_packet *_packets;

        gu_simple_whiteboard_descriptor **remote_wbd;
        int _machines_in_the_network;

	/**
 	* Setup the receiver object 
 	*/       
        Receiver(gsw_udp_packet_info *packet_data, int packets_in_schedule, int max_types_per_packet, int machines_in_the_network);

	/**
 	* make storage object
 	*/       
        void construct_packets_array();

	/**
 	* Set the socket to non-blocking
 	*/       
        void set_nonblock(int socket);

	/**
 	* get sockaddr, IPv4 or IPv6
 	*/       
        void *get_in_addr(struct sockaddr_in *sa);

	/**
 	* fetch packet
 	*/       
        void get_packet(int max_packet_size);

	/**
 	* delete objects
 	*/       
        ~Receiver();
};

//#pragma clang diagnostic pop

#endif //udp_receiver_h
