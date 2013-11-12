/*
 *  udp_sender.cpp
 *
 *  Created by Carl Lusty on 1/6/13.
 *  Copyright (c) 2013 Carl Lusty and Rene Hexel.
 *  All rights reserved.
 */

#include "udp_receiver.h"
#include "udp_util.h" //create_dispatch_timer

//#include "udp_serialise.h"

#include <arpa/inet.h> //PF_INET
#include <sys/time.h> //gettimeofday
#include <cmath> //floor
#include <cstdlib> //atoi
#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wshorten-64-to-32"

void Receiver::construct_packets_array()
{
        _packets = static_cast<gsw_udp_packet *>(calloc(_packets_in_schedule, sizeof(gsw_udp_packet)));

        for (int i = 0; i < _packets_in_schedule; i++)
        {
                gsw_udp_packet *packet = &_packets[i];
                packet->schedule_index = (u_int8_t)i;
                packet->num_of_types = _packet_data[i].num_of_types;

                packet->offset = static_cast<u_int16_t *>(calloc(packet->num_of_types, sizeof(u_int16_t)));

                for (int g = 0; g < packet->num_of_types; g++)
                        packet->offset[g] = _packet_data[i].offset[g];

//                if((int)_packet_data[i].sender == get_udp_id())
//                        continue; //don't bother allocating for types that we won't ever read

                packet->event_counter = static_cast<u_int16_t *>(calloc(packet->num_of_types, sizeof(u_int16_t)));
                packet->content = static_cast<gu_simple_message *>(calloc(packet->num_of_types, sizeof(gu_simple_message)));
        }
}


// get sockaddr, IPv4 or IPv6:
void *Receiver::get_in_addr(struct sockaddr_in *sa)
{
	if (sa->sin_family == AF_INET)
		return &(sa->sin_addr);

	return &reinterpret_cast<struct sockaddr_in6 *>(sa)->sin6_addr;
}

__attribute__((noreturn))  Receiver::Receiver(gsw_udp_packet_info *packet_data, int packets_in_schedule, int max_types_per_packet, int machines_in_the_network) :
                _packet_data(packet_data), _packets_in_schedule(packets_in_schedule), _machines_in_the_network(machines_in_the_network)
{
        //dispatch_queue_t stdout_queue = dispatch_queue_create("net.mipal.guudpwhiteboard.receiver.stdout", 0);

        remote_wbd = static_cast<gu_simple_whiteboard_descriptor **>(calloc(machines_in_the_network, sizeof(gu_simple_whiteboard_descriptor *)));

        for (int i = 0; i < machines_in_the_network; i++)
        {
                remote_wbd[i] = gswr_new_whiteboard(i+1);

                /*
                 * reset wb event counters (if the robot restarts then its event counters will be zero, aka less than the current counters on record)
                 */
                memset(&remote_wbd[i]->wb->event_counters, 0, sizeof remote_wbd[i]->wb->event_counters);
        }

        int max_packet_size = sizeof(u_int8_t) + (sizeof(u_int16_t)*max_types_per_packet) + (sizeof(gu_simple_message)*max_types_per_packet);
        _recv_buffer = (unsigned char *) malloc(max_packet_size);
        construct_packets_array();

//taken from http://www.beej.us/guide/bgnet/output/html/multipage/clientserver.html#datagram
        int sockfd = 0;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	ssize_t numbytes;
	struct sockaddr_storage their_addr;
	socklen_t addr_len;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo(NULL, PORT_STR, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		exit(1);
	}

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
                                     p->ai_protocol)) == -1) {
			perror("listener: socket");
			continue;
		}

                int yes = 1;
                if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
                {
                        perror("listener: setsockopt");
                        exit(1);
                }


		if (bind(sockfd, p->ai_addr, p->ai_addrlen) != -1)
                        break;  // found a place to bind, break loop

                close(sockfd);
                perror("listener: bind");
	}

	if (p == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
                exit(1);
	}

	freeaddrinfo(servinfo);

	printf("listener: waiting to recvfrom...\n");

	addr_len = sizeof their_addr;

        //__block bool got_timeout;
        __block unsigned packet_sequence = 0UL;
        while (true)
        {
                //unsigned current_packet = packet_sequence;
//                got_timeout = false;

//                dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, 1 * NSEC_PER_SEC);
//                dispatch_after(popTime, stdout_queue,
//                ^{
//                        if (current_packet == packet_sequence)
//                        {
//                                got_timeout = true;
//                                write(STDOUT_FILENO, "*", 1);
//                        }
//                });

                if ((numbytes = recvfrom(sockfd, _recv_buffer, max_packet_size , 0, (struct sockaddr *)&their_addr, &addr_len)
                     ) == -1) {
                        perror("recvfrom");
                        protected_msleep(10);
                        continue;
                }
                packet_sequence++;
//                if (got_timeout) dispatch_async(stdout_queue,
//                ^{
//                        write(STDOUT_FILENO, "\b \b", 3);
//                });
#ifdef DEBUG
//                dispatch_async(stdout_queue,
//                ^{
//                        char inetaddr_name[INET6_ADDRSTRLEN];
//                        printf("listener: got packet from %s\n",
//                               inet_ntop(their_addr.ss_family,
//                                         get_in_addr((struct sockaddr_in *)&their_addr),
//                                         inetaddr_name, sizeof inetaddr_name));
//                        printf("listener: packet is %d bytes long\n", (int)numbytes);
                        //printf("listener: packet contains \"%s\"\n", buf);
//                });
#endif
                u_int8_t index = _recv_buffer[0];

                buf2packet(&_packets[index], _recv_buffer, _packet_data[index].num_of_types);

                for (int i = 0; i < _packet_data[index].num_of_types; i++)
                {
                        u_int16_t t = _packet_data[index].offset[i];
                        u_int8_t s = _packet_data[index].sender - 1;
                        if(s < 0 || s >= machines_in_the_network)
                                continue;
                        u_int16_t new_e = _packets[index].event_counter[i];
                        
                        gu_simple_whiteboard *wb = remote_wbd[s]->wb;
                        u_int16_t old_e = wb->event_counters[t];

                        if(new_e > old_e || (new_e < old_e && new_e < 100)) //event counter in the packet is different to the one in the wb (for that type)
                        {                       //This is here because the event counter will eventually wrap around
                                gu_simple_message *m = gsw_next_message(wb, t);
                                gu_simple_message *wbobj = (gu_simple_message*)(m);

                                *wbobj = _packets[index].content[i];

                                gsw_increment(wb, t);
                                wb->event_counters[t] = new_e; //set event counter rather than increment it
                                if (wb->subscribed) gsw_signal_subscribers(wb); //notify_subscribers is always true for the udp whiteboard
                        }
//                        else if (new_e != old_e) dispatch_async(stdout_queue,
//                        ^{
//                                write(STDOUT_FILENO, ".", 1);
//                        });
                }
        }
}



Receiver::~Receiver()
{
        for (int i = 0; i < _machines_in_the_network; i++)
                if (remote_wbd[i]) gsw_free_whiteboard(remote_wbd[i]);

        shutdown(_recv_socket, SHUT_WR);
        close(_recv_socket);
}

//#pragma clang diagnostic pop
