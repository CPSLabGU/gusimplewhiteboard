/*
 *  guudpBroadcaster.h
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */

#ifndef guudpbroadcaster_h
#define guudpbroadcaster_h



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

#include "guudpConfig.h"
#include <Whiteboard.h>
#include <time.h>
#include <list>

static void broadcastLoop(void *broadcaster); 

class BridgeBroadcaster
{
public:    
    gu_simple_whiteboard_descriptor *_wbd_broadcaster;  /// underlying whiteboard
    std::vector<std::string> *msg_types_to_broadcast;
    std::list<gsw_injection_message> *messages_to_inject;
    pthread_mutex_t *_injection_mutex;
    dispatch_source_t broadcast_monitor;    
    int sockfd;
    struct sockaddr_in mc_addr; // connector's address information
    int numbytes;
    unsigned char mc_ttl;     /* time to live (hop count) */
    
#ifdef DEBUG
    long long lastStartTime;
#endif
    
#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    int uniqueId;
#else
    int uniqueId;
#endif
    PacketType currently_sending;
    
    int sent;
    int total_sent;
    long long startSendTime;
    long long endSendTime;
    long long avgSendTime;
    int iter;
    
    int padding;
    bool sending_currently;
    int sending_count;    
    
    int offset;    
    int msg_loops;  
    unsigned char buffer[MTU];

        
    void send_hash();
    void send_injection();
    void send_content();
    
    BridgeBroadcaster(gu_simple_whiteboard_descriptor *_wbd, std::vector<std::string> *types, std::list<gsw_injection_message> *injectionVec, pthread_mutex_t *injection_mutex, timeval currTime);
    
    ~BridgeBroadcaster();
};

#endif //guudpbroadcaster_h