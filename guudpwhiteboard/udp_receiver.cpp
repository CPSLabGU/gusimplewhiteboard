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

//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wshorten-64-to-32"

void Receiver::construct_packets_array()
{
//        _packets = (gsw_udp_packet *)malloc(sizeof(gsw_udp_packet) * _packets_in_schedule);
//
//        for (int i = 0; i < _packets_in_schedule; i++)
//        {
//                gsw_udp_packet *packet = &_packets[i];
//                packet->schedule_index = (u_int8_t)i;
//                packet->num_of_types = _packet_data[i].num_of_types;
//
//                packet->offset = (u_int16_t *) malloc(sizeof(u_int16_t) * packet->num_of_types);
//
//                for (int g = 0; g < packet->num_of_types; g++)
//                        packet->offset[g] = _packet_data[i].offset[g];
//
//                if((int)_packet_data[i].sender != get_udp_id())
//                        continue; //don't bother allocating for types that we won't ever send
//
//                packet->event_counter = (u_int16_t *) malloc(sizeof(u_int16_t) * packet->num_of_types);
//                packet->content = (gu_simple_message *) malloc(sizeof(gu_simple_message) * packet->num_of_types);
//        }
}


void Receiver::set_nonblock(int socket)
{
        int flags;
        flags = fcntl(socket,F_GETFL,0);
        fcntl(socket, F_SETFL, flags | O_NONBLOCK);
}

// get sockaddr, IPv4 or IPv6:
void *Receiver::get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void Receiver::get_packet(int max_packet_size)
{
        if (select(_recv_socket+1, &_sock_read_fd_set, 0, 0, &_select_timeout) == -1)
        {
                //Put this back if we start using signals again
//                if (errno != EINTR)
//                {
                        perror("select() failed");
                        return;
//                }
        }

        /* receive a packet */
        ssize_t got_bytes = 0;
        got_bytes = recvfrom(_recv_socket, _recv_buffer, max_packet_size, 0, NULL, NULL);
        if (got_bytes < 0)
        {
                perror("recvfrom() failed");
                return;
        }
        else
        {
                fprintf(stderr, "data\tbytes: %d\n", (int)got_bytes);
        }

}

Receiver::Receiver(gsw_udp_packet_info *packet_data, int packets_in_schedule, int timer_delay, int max_types_per_packet) :
                _packet_data(packet_data), _packets_in_schedule(packets_in_schedule)
{
        struct sockaddr_in mc_addr;   /* socket address structure */

        /* create socket to join multicast group on */
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

        /* set reuse port to on to allow multiple binds per host */
        int flag_on = 1;
        if ((setsockopt(_recv_socket, SOL_SOCKET, SO_REUSEADDR, &flag_on,
                        sizeof(flag_on))) < 0) {
                perror("setsockopt() failed");
                exit(1);
        }

        /* construct a multicast address structure */
        memset(&mc_addr, 0, sizeof(mc_addr));
        mc_addr.sin_family      = PF_INET;
        mc_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        mc_addr.sin_port        = htons(PORT);

        /* bind to multicast address to socket */
        if ((bind(_recv_socket, (struct sockaddr *) &mc_addr,
                  sizeof(mc_addr))) < 0) {
                perror("bind() failed");        
                return;
        }

        /* setup select vars */
        FD_ZERO(&_sock_read_fd_set);
        FD_SET(_recv_socket, &_sock_read_fd_set);
        _select_timeout.tv_sec  = 0;
        _select_timeout.tv_usec = READ_TIMEOUT;


        while(true)
        {
                get_packet(max_packet_size);
        }












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
