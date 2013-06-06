/*
 *  udp_sender.cpp
 *
 *  Created by Carl Lusty on 1/6/13.
 *  Copyright (c) 2013 Carl Lusty.
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
        _packets = (gsw_udp_packet *)malloc(sizeof(gsw_udp_packet) * _packets_in_schedule);

        for (int i = 0; i < _packets_in_schedule; i++)
        {
                gsw_udp_packet *packet = &_packets[i];
                packet->schedule_index = (u_int8_t)i;
                packet->num_of_types = _packet_data[i].num_of_types;

                packet->offset = (u_int16_t *) malloc(sizeof(u_int16_t) * packet->num_of_types);

                for (int g = 0; g < packet->num_of_types; g++)
                        packet->offset[g] = _packet_data[i].offset[g];

//                if((int)_packet_data[i].sender == get_udp_id())
//                        continue; //don't bother allocating for types that we won't ever read

                packet->event_counter = (u_int16_t *) malloc(sizeof(u_int16_t) * packet->num_of_types);
                packet->content = (gu_simple_message *) malloc(sizeof(gu_simple_message) * packet->num_of_types);
        }
}


// get sockaddr, IPv4 or IPv6:
void *Receiver::get_in_addr(struct sockaddr_in *sa)
{
	if (sa->sin_family == AF_INET) {
		return &(sa->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

[[ noreturn ]] Receiver::Receiver(gsw_udp_packet_info *packet_data, int packets_in_schedule, int max_types_per_packet, int machines_in_the_network) :
                _packet_data(packet_data), _packets_in_schedule(packets_in_schedule)
{
        remote_wbd = (gu_simple_whiteboard_descriptor **)malloc(sizeof(gu_simple_whiteboard_descriptor *) * machines_in_the_network);

        for (int i = 0; i < machines_in_the_network; i++)
        {
                remote_wbd[i] = gswr_new_whiteboard(i);
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
	char a[INET6_ADDRSTRLEN];

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

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("listener: bind");
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
                exit(1);
	}

	freeaddrinfo(servinfo);

	printf("listener: waiting to recvfrom...\n");

	addr_len = sizeof their_addr;

        while (true)
        {
                if ((numbytes = recvfrom(sockfd, _recv_buffer, max_packet_size , 0,
                                         (struct sockaddr *)&their_addr, &addr_len)) == -1) {
                        perror("recvfrom");
                        exit(1);
                }

                printf("listener: got packet from %s\n",
                       inet_ntop(their_addr.ss_family,
                                 get_in_addr((struct sockaddr_in *)&their_addr),
                                 a, sizeof a));
                printf("listener: packet is %d bytes long\n", (int)numbytes);

                //printf("listener: packet contains \"%s\"\n", buf);


                u_int8_t index;
                memcpy((void*)&index, _recv_buffer, sizeof index);

                buf2packet(&_packets[index], _recv_buffer, _packet_data[index].num_of_types);

                for (int i = 0; i < _packet_data[index].num_of_types; i++)
                {
                        u_int16_t t = _packet_data[index].offset[i];
                        u_int8_t s = _packet_data[index].sender;
                        u_int16_t new_e = _packets[index].event_counter[i];
                        
                        gu_simple_whiteboard *wb = remote_wbd[s]->wb;
                        u_int16_t old_e = wb->event_counters[t];

                        if(new_e > old_e || (new_e < old_e && new_e < 1000)) //event counter in the packet is different to the one in the wb (for that type)
                        {                       //This is here because the event counter will eventually wrap around
                                gu_simple_message *m = gsw_next_message(wb, t);
                                gu_simple_message *wbobj = (gu_simple_message*)(m);

                                *wbobj = _packets[index].content[i];

                                gsw_increment(wb, t);
                                wb->event_counters[t] = new_e; //set event counter rather than increment it
                                if (wb->subscribed) gsw_signal_subscribers(wb); //notify_subscribers is always true for the udp whiteboard
                        }
                }
        }


	//close(sockfd);





/*



        if ((_recv_socket = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        {
                perror("socket() failed");
                exit(1);
        }

        //     set_nonblock(_recv_socket); //nessesary?

        int max_packet_size = sizeof(u_int8_t) + (sizeof(u_int16_t)*max_types_per_packet) + (sizeof(gu_simple_message)*max_types_per_packet);
        int buffsize = max_packet_size * MESSAGES_IN_READ_BUFFER;
        if ((setsockopt(_recv_socket, SOL_SOCKET, SO_RCVBUF, &buffsize, sizeof(buffsize))) < 0) {
                perror("setsockopt() failed changing SO_RCVBUF");
                exit(1);
        }


        int flag_on = 1;
        if ((setsockopt(_recv_socket, SOL_SOCKET, SO_REUSEADDR, &flag_on,
                        sizeof(flag_on))) < 0) {
                perror("setsockopt() failed");
                exit(1);
        }


        memset(&mc_addr, 0, sizeof(mc_addr));
        mc_addr.sin_family      = PF_INET;
        mc_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        mc_addr.sin_port        = htons(PORT);


        if ((bind(_recv_socket, (struct sockaddr *) &mc_addr,
                  sizeof(mc_addr))) < 0) {
                perror("bind() failed");
                return;
        }


        FD_ZERO(&_sock_read_fd_set);
        FD_SET(_recv_socket, &_sock_read_fd_set);
        _select_timeout.tv_sec  = 0;
        _select_timeout.tv_usec = READ_TIMEOUT;


        while(true)
        {
                get_packet(max_packet_size);
        }
*/



//        
//        construct_packets_array();
//        int packet_size = 0;
//        for (int i = 0; i < _packets_in_schedule; i++)
//                packet_size += sizeof(u_int8_t) + (sizeof(u_int16_t)*_packet_data[i].num_of_types) + (sizeof(gu_simple_message)*_packet_data[i].num_of_types);
//
//
//
//        _send_buffer = (unsigned char *) malloc(packet_size);
//
//        int duration_of_schedule = timer_delay*packets_in_schedule;
//        long long now = get_utime();
//        long long start_of_next_round = now + (duration_of_schedule-(now%duration_of_schedule)); //usec
//
//
//        timespec spec;
//        spec.tv_sec = (long)floor(start_of_next_round / USEC_PER_SEC);
//        spec.tv_nsec = (start_of_next_round % USEC_PER_SEC) * NSEC_PER_USEC;
//
//
//        gu_simple_whiteboard_descriptor *wbd = get_local_singleton_whiteboard();
//
//        
//        dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0));
//        if (timer)
//        {
//                dispatch_source_set_timer(timer, dispatch_walltime(&spec, 0), (timer_delay*NSEC_PER_USEC), 0ull);
//                dispatch_source_set_event_handler(timer, ^{
//
//                        gsw_udp_packet_info *packet_info = &packet_data[_current_sender_index];
//                        if((int)packet_info->sender == get_udp_id())
//                        {
//                                gsw_udp_packet *packet = &_packets[_current_sender_index];
//                                for (int i = 0; i < packet->num_of_types; i++)
//                                {
//                                        u_int16_t offset = packet->offset[i];
//                                        packet->event_counter[i] = wbd->wb->event_counters[offset];
//                                        packet->content[i] = wbd->wb->messages[offset][wbd->wb->indexes[offset]];
//                                }
//
//                                packet2buf(_send_buffer, &_packets[_current_sender_index]);
//
//                                int this_packet_size = sizeof(u_int8_t) + (sizeof(u_int16_t)*_packet_data[_current_sender_index].num_of_types) + (sizeof(gu_simple_message)*_packet_data[_current_sender_index].num_of_types);
//                                ssize_t bytes_sent = sendto(_send_socket, _send_buffer, this_packet_size, 0, (struct sockaddr *)&_mc_addr, sizeof(_mc_addr));
//                                if(bytes_sent == -1)
//                                {
//                                        fprintf(stderr, "!Sent index %d\n", _current_sender_index+1);
//                                        if(errno != 65) //ENETUNREACH - no route to host
//                                        {
//                                                perror("sendto");
//                                                exit(1);
//                                        }
//                                }
//                                else
//                                        fprintf(stderr, "Sent index %d\tbytes %d\n", _current_sender_index+1, (int)bytes_sent);
//                        }
//                        _current_sender_index++;
//                        if(_current_sender_index == packets_in_schedule)
//                                _current_sender_index = 0;
//                });
//                dispatch_resume(timer);
//        }
}



Receiver::~Receiver()
{
        shutdown(_recv_socket, SHUT_WR);
        close(_recv_socket);
}

//#pragma clang diagnostic pop
