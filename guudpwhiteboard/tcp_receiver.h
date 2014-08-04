/*
 *  tcp_receiver.h
 *
 *  Created by Carl Lusty on 1/6/13.
 *  Copyright (c) 2013 Carl Lusty and Rene Hexel.
 *  All rights reserved.
 */

#ifndef tcp_receiver_h
#define tcp_receiver_h


#include "guwhiteboardtypelist_generated.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define DISPATCH_QUEUE_NAME_WB "guWhiteboard_tcp"

#ifndef DISPATCH_QUEUE_SERIAL
#define DISPATCH_QUEUE_SERIAL NULL
#endif


class TCPInjectionReceiver
{
        struct addrinfo hints;
        struct addrinfo *result, *rp;
        int sfd, s;
        struct sockaddr_storage peer_addr;
        socklen_t peer_addr_len;

        dispatch_queue_t                        recv_queue;

        void create_connection_thread(int *cfd);
public:

        
        TCPInjectionReceiver();

        ~TCPInjectionReceiver();
};


#endif //tcp_receiver_h
