/*
 *  tcp_sender.cpp
 *
 *  Created by Carl Lusty on 1/6/13.
 *  Copyright (c) 2013 Carl Lusty and Rene Hexel.
 *  All rights reserved.
 */

#include "tcp_receiver.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "tcp_config.h"


#include <dispatch/dispatch.h>

#define CONN_QUEUE_SIZE 10

void *connection(void *args);
void addToWB(uint16_t t, gsw_simple_message *m);

TCPInjectionReceiver::TCPInjectionReceiver()
{
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
        hints.ai_socktype = SOCK_STREAM; /* Datagram socket */
        hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
        hints.ai_protocol = 0;          /* Any protocol */
        hints.ai_canonname = NULL;
        hints.ai_addr = NULL;
        hints.ai_next = NULL;

        s = getaddrinfo(NULL, TCP_PORT_STR, &hints, &result);
        if (s != 0) {
                fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
        }

        /* getaddrinfo() returns a list of address structures.
         Try each address until we successfully bind(2).
         If socket(2) (or bind(2)) fails, we (close the socket
         and) try the next address. */

        for (rp = result; rp != NULL; rp = rp->ai_next) {
                sfd = socket(rp->ai_family, rp->ai_socktype,
                             rp->ai_protocol);
                if (sfd == -1)
                        continue;

                int yes = 1;
                if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
                        perror("setsockopt");

                if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
                        break;                  /* Success */

                close(sfd);
        }

        if (rp == NULL) {               /* No address succeeded */
                fprintf(stderr, "Could not bind\n");
                exit(EXIT_FAILURE);
        }

        freeaddrinfo(result);           /* No longer needed */



        if (!(recv_queue = dispatch_queue_create(DISPATCH_QUEUE_NAME_WB, DISPATCH_QUEUE_SERIAL)))
        {
                std::cerr << "Unable to create dispatch queue" << std::endl;
                throw "TCP Whiteboard Receiver cannot create dispatch queue";
        }

        dispatch_queue_t sys_queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);

        dispatch_async(sys_queue, ^(void) __attribute__((noreturn)) {
                for (;;) {
                        listen(sfd, CONN_QUEUE_SIZE);

                        peer_addr_len = sizeof(struct sockaddr_storage);
                        int cfd = accept(sfd, (struct sockaddr *) &peer_addr, &peer_addr_len);

                        if (cfd == -1)
                                continue;               /* Ignore failed request */

                        create_connection_thread(&cfd);
#ifdef DEBUG
                        char host[NI_MAXHOST], service[NI_MAXSERV];
                        s = getnameinfo((struct sockaddr *) &peer_addr,
                                        peer_addr_len, host, NI_MAXHOST,
                                        service, NI_MAXSERV, NI_NUMERICSERV);
                        if (s == 0)
                                printf("Received %ld bytes from %s:%s\n",
                                       (long) n, host, service);
                        else
                                fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
#endif
                }
        });
}

TCPInjectionReceiver::~TCPInjectionReceiver()
{
        close(sfd);
}

void TCPInjectionReceiver::create_connection_thread(int *cfd)
{
        pthread_attr_t        attr;
        pthread_t             thread;
        int                   rc=0;

        rc = pthread_attr_init(&attr);
        if(rc)
                fprintf(stderr, "TCPInjectionReceiver: pthread_attr_init failed");

        rc = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
        if(rc)
                fprintf(stderr, "TCPInjectionReceiver: pthread_attr_setdetachstate failed");

        rc = pthread_create(&thread, &attr, connection, (void *)cfd);
        if(rc)
                fprintf(stderr, "TCPInjectionReceiver: pthread_create failed");

        rc = pthread_attr_destroy(&attr);
        if(rc)
                fprintf(stderr, "TCPInjectionReceiver: pthread_attr_destroy failed");
}

void *connection(void *args)
{
        int cfd = *(int *)args;

        fprintf(stderr, "Connected!\n");
        bool socket_open = true;
        while(socket_open)
        {
                gsw_message_packet buff;
                ssize_t n = 0;
                ssize_t r;
                do
                {
                        r = recv(cfd, &buff, sizeof(buff), 0);
                        n += r;
                        fprintf(stderr, "Reading... %d of %d\n", (int)n, (int)sizeof(buff));

                } while ((int)n < (int)sizeof(buff) && r > 0);

                fprintf(stderr, "Got Msg\n");
                if(r <= 0)
                        socket_open = false;
                else
                        addToWB((uint16_t)buff.t, &buff.m);
        }
        fprintf(stderr, "Disconnected!\n");

        return NULL;
}

void addToWB(uint16_t t, gsw_simple_message *m)
{
        gu_simple_whiteboard_descriptor *_wbd = get_local_singleton_whiteboard();
        gsw_procure(_wbd->sem, GSW_SEM_PUTMSG);

        gu_simple_whiteboard *wb = _wbd->wb;
        gu_simple_message *wb_m = gsw_next_message(wb, (int)t);
        gsw_simple_message *wbobj = (gsw_simple_message *)(wb_m);
        *wbobj = *m;

        gsw_increment(wb, (int)t);
        gsw_increment_event_counter(wb, (int)t);
        gsw_vacate(_wbd->sem, GSW_SEM_PUTMSG);
        gsw_signal_subscribers(wb);
}
