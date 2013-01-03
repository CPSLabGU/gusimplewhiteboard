/*
 *  guudpManager.cpp
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <unistd.h> //for getpid()
#include <gu_util.h>
#include <Whiteboard.h>
#include <WBMsg.h>


#include <sys/time.h> //gettimeofday
#include "guudpUtil.h"
#include "guudpBroadcaster.h"
#include "guudpListener.h"
#include "guudpWhiteboardLayer.h"

#include "guudpManager.h"

int setup_udp_with_id(int id)
{
    
        int udp_id;
        if(id != -1)
                udp_id = getplayernumber();
        else
                udp_id = id;
    
    if(udp_id > (NUM_OF_BROADCASTERS))
    {
        fprintf(stderr, "Bad UDP_ID passed in, exiting...\n\n");
        return EXIT_FAILURE;        
    }

    set_udp_id(udp_id-1);
    
    
        //get native wb
    guWhiteboard::Whiteboard *whiteboard = new guWhiteboard::Whiteboard();
    gu_simple_whiteboard_descriptor *_wbd = whiteboard->_wbd;  /// underlying whiteboard to broadcast from
    
    
    
    //Setup listener wbs    
    gu_simple_whiteboard_descriptor *_wbds[NUM_OF_BROADCASTERS];
    guWhiteboard::Whiteboard *_whiteboards[NUM_OF_BROADCASTERS];    
    
    for (int i = 0; i < NUM_OF_BROADCASTERS; i++) 
    {
        const char *base_wb_name = REMOTE_WHITEBOARD_BASENAME;
        std::stringstream ss;
        std::stringstream ss2;
        ss << base_wb_name << (i+1); //line the wb names up to the player names
        
        _whiteboards[i] = new guWhiteboard::Whiteboard(ss.str().c_str());
        if(_whiteboards[i])
            _wbds[i] = _whiteboards[i]->_wbd;
    }
    
    
    timeval tim;
    gettimeofday(&tim, NULL);
    
    
#ifdef DEBUG
//    fprintf(stderr, "\nMessage on the wb: %d\n\nMessages to a packet: %d\nPackets to send all messages: %d\nHashes to a packet: %d\nPackets to send all hashes: %d\nInjections to a packet: %d\n\nCYCLES_PER_SECOND: %d\nPACKETS_PER_TS_INTERVAL %d\n", _wbd->wb->num_types, MESSAGES_PER_PACKET, TOTAL_MESSAGE_PACKETS, HASHES_PER_PACKET, TOTAL_HASH_PACKETS, INJECTIONS_PER_PACKET, CYCLES_PER_SEC, PACKETS_PER_TS_INTERVAL);
//    
//    fprintf(stderr, "\nMessages sizes:\n\tgsw_single_message:\t%d\n\tgsw_hash_message:\t%d\n\n", (int)sizeof(gsw_single_message), (int)sizeof(gsw_hash_message));
#endif
    

    WhiteboardLayer *wl = new WhiteboardLayer(whiteboard, _whiteboards);
    BridgeBroadcaster *broadcaster = new BridgeBroadcaster(_wbd, &wl->dynamic_msg_types_to_broadcast, &wl->dynamic_messages_to_inject, &wl->injection_mutex, tim);
    BridgeListener *listener = new BridgeListener(_wbds, whiteboard, wl->recieved_generations, tim, &wl->dynamic_msg_types_to_broadcast, &wl->dynamic_msg_types_to_listen_for, &wl->injection_mutex);    //May not end if loop reading
    
    delete listener;
    delete broadcaster;
    delete wl;
    for (int i = 0; i < NUM_OF_BROADCASTERS; i++) 
    {
        delete _wbds[i];
    }
    delete whiteboard;
    
	return 0;
}
