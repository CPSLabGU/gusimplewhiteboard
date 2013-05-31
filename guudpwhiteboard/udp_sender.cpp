/*
 *  udp_sender.cpp
 *
 *  Created by Carl Lusty on 1/6/13.
 *  Copyright (c) 2013 Carl Lusty.
 *  All rights reserved.
 */

#include "udp_sender.h"
#include "udp_util.h" //create_dispatch_timer

//#include "udp_serialise.h"

#include <arpa/inet.h> //PF_INET
#include <sys/time.h> //gettimeofday
#include <cmath> //floor

//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wshorten-64-to-32"

void sender_func(void *sender)
{
        Sender *s = (Sender *)sender;
        s->_sender_timer = NULL;
        //read  current index of send vector
        fprintf(stderr, ".");
}
/*
void Sender::send_content()
{
        //packet to send
        gsw_single_message messageToSend;
        messageToSend.packetInfo = Msg; //packet type info
        messageToSend.udpId = get_udp_id(); //senders id


        gsw_procure(_wbd_broadcaster->sem, GSW_SEM_PUTMSG); //reading whiteboards need to lock.

        for(int j = 0; j < MESSAGES_PER_PACKET; j++)
        {
                if(offset >= GSW_NUM_TYPES_DEFINED && offset <= GSW_NUM_RESERVED)
                {
                        //dynamic messages (not reserved message types)
                        offset = GSW_NUM_RESERVED; //move past the unused reserved types
                }
                if(offset >= GSW_NUM_RESERVED + (int)msg_types_to_broadcast->size())
                {
                        offset = 0;
                }
                int tmpOffset = offset;
                if (offset >= GSW_NUM_RESERVED) {
                        tmpOffset = gsw_offset_for_message_type(_wbd_broadcaster, (char *)msg_types_to_broadcast->at(offset-GSW_NUM_RESERVED).c_str());
                }

                messageToSend.typeOffset[j] = tmpOffset; //offset in hash table for content pointer
                messageToSend.current_generation[j] = _wbd_broadcaster->wb->indexes[tmpOffset]; //current generation pointer

                //just add the current generation of the message
                messageToSend.message_generations[j] =  _wbd_broadcaster->wb->messages[tmpOffset][_wbd_broadcaster->wb->indexes[tmpOffset]];

                offset++; //move to the next message in the queue
        }

        gsw_vacate(_wbd_broadcaster->sem, GSW_SEM_PUTMSG);

        msg2buf(&buffer[0], &messageToSend); //serialize

        //broadcast msg
        if ((numbytes=sendto(sockfd, buffer, sizeof(buffer), 0,
                             (struct sockaddr *)&mc_addr, sizeof(mc_addr))) == -1) {
                if(errno != 65) //ENETUNREACH - no route to host
                {
                        perror("sendto");
                        exit(1);
                }
        }
}
*/
Sender::Sender(gsw_udp_packet_info *packet_data, int packets_in_schedule, int timer_delay, int packet_size) :
                _packet_data(packet_data), _packets_in_schedule(packets_in_schedule)
{
        //Setup socket
	if ((_send_socket = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

        // this call is what allows broadcast packets to be sent:
        int broadcastOn = 1;
	if (setsockopt(_send_socket, SOL_SOCKET, SO_BROADCAST, &broadcastOn, sizeof(broadcastOn)) == -1)
        {
		perror("setsockopt (SO_BROADCAST)");
		exit(1);
	}

	// this call stops packets I send coming back to me
//        int  val=0;
//	if (setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_LOOP, (const char *)&val, sizeof(val)) == -1)
//        {
//		perror("setsockopt (IP_MULTICAST_LOOP)");
//		exit(1);
//	}

        /* construct address structure */
        memset(&_mc_addr, 0, sizeof(_mc_addr));
        _mc_addr.sin_family      = PF_INET;
        _mc_addr.sin_addr.s_addr = inet_addr(BROADCASTADDRESS);
        _mc_addr.sin_port        = htons(PORT);


        send_buffer = (void *) malloc(packet_size);
//        memset(send_buffer, 0, packet_size);

        int duration_of_schedule = timer_delay*packets_in_schedule;
        long long now = get_utime();
        long long start_of_next_round = now + (duration_of_schedule-(now%duration_of_schedule)); //usec


        timespec spec;
        spec.tv_sec = floor(start_of_next_round / USEC_PER_SEC);
        spec.tv_nsec = (start_of_next_round % USEC_PER_SEC) * NSEC_PER_USEC;

        _sender_timer = CreateDispatchTimer(&spec,
                                                (timer_delay*NSEC_PER_USEC),
                                                0ull,
                                                dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                *sender_func, this);
}

Sender::~Sender()
{
//        dispatch_source_cancel(_sender_timer);
//        dispatch_release(_sender_timer);

        shutdown(_send_socket, SHUT_WR);
        close(_send_socket);
}

//#pragma clang diagnostic pop
