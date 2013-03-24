/*
 *  guudpListener.h
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */


#ifndef guudplistener_h
#define guudplistener_h

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
#include <string.h>
#include <fcntl.h>


#include "guudpConfig.h"
#include <Whiteboard.h>
#include <time.h>
#include <list>

#ifdef bool
#undef bool
#endif

#ifdef true
#undef true
#undef false
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"

#ifdef DEBUG    
void listenMonitor(void *listener);
#endif


class BridgeListener
{
public:    
    int16_t                indexLookup[NUM_OF_BROADCASTERS][GSW_TOTAL_MESSAGE_TYPES];
    gu_simple_whiteboard_descriptor *_wbd_listeners[NUM_OF_BROADCASTERS];  /// underlying whiteboard
    guWhiteboard::Whiteboard *_wbd_injection;  /// underlying whiteboard    
    pthread_mutex_t *_injection_mutex;    
    std::vector<std::string> *msg_types_to_broadcast;    
    std::list<std::pair<std::string, int> > *msg_types_to_listen_for;    
    u_int8_t (&recieved_generations)[NUM_OF_BROADCASTERS][GSW_TOTAL_MESSAGE_TYPES];
    int current_poster;
    
    int sock;                     /* socket descriptor */
    int flag_on;              /* socket option flag */
    char recv_data[sizeof(gsw_single_message)];     /* buffer to receive message packet */
    char recv_hash[sizeof(gsw_single_message)];       /* buffer to receive hash packet */
    int recv_len;                 /* length of data received */
    
#ifdef DEBUG    
    int gotHashPackets; //Num of hash gotten
    int gotInjectionPackets; //Num of injections gotten
    int gotMessagePackets; //Num of msg gotten
    int lostPackets; //Num of packets missed
    int total_recv;

    int iter_listener;
    long long startRecvTime;
    long long endRecvTime;
    long long avgRecvTime;
    long long rawRecvTime;
    
    //TEMP
    int oldId;
    
#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    bool packetsAlreadyGotten[DETECTION_BUFFER_SIZE];
#endif
#endif
    //Would rather make this global to avoid malloc calls, only work without timers. ie. Loop read.    
    char recv_buffer[MTU];
       
    
    void listenSingleMethod();

    void set_nonblock(int socket);

    // get sockaddr, IPv4 or IPv6:
    void *get_in_addr(struct sockaddr *sa);

    BridgeListener(gu_simple_whiteboard_descriptor *_wbd[NUM_OF_BROADCASTERS], guWhiteboard::Whiteboard *_wbd_for_injections, u_int8_t (&recieved_generations_array)[NUM_OF_BROADCASTERS][GSW_TOTAL_MESSAGE_TYPES], timeval currTime, std::vector<std::string> *typesSent, std::list<std::pair<std::string, int> > *listen_for_types, pthread_mutex_t *injection_mutex);
    virtual ~BridgeListener();
};

#pragma clang diagnostic pop

#endif //guudplistener_h