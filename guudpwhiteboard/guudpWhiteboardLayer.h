/*
 *  guudpWhiteboardLayer.h
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */


#ifndef guudpwhiteboardlayer_h
#define guudpwhiteboardlayer_h

#include <Whiteboard.h>
#include <WBMsg.h>
#include <dispatch/dispatch.h>
#include "guudpConfig.h"
#include <list>

class WhiteboardLayer
{
public:
        std::vector<std::string>            dynamic_msg_types_to_broadcast;
        std::list<std::pair<std::string, int> >            dynamic_msg_types_to_listen_for;
        std::list<gsw_injection_message>    dynamic_messages_to_inject;
        pthread_mutex_t                     injection_mutex;
        u_int8_t                            recieved_generations[NUM_OF_BROADCASTERS][GSW_TOTAL_MESSAGE_TYPES];
        guWhiteboard::Whiteboard                          **_wbds;
        
        guWhiteboard::Whiteboard *wb;
        
        //constructor
        WhiteboardLayer(guWhiteboard::Whiteboard *wbd, guWhiteboard::Whiteboard **_whiteboards);
        
        //main listener to changes made to remote whiteboards that need replicating
        void monitorCallback(std::string type, WBMsg *value, int machineNum);
        
        void monitorCallback1(std::string dataName, WBMsg *value) { monitorCallback(dataName, value, 1); }
        void monitorCallback2(std::string dataName, WBMsg *value) { monitorCallback(dataName, value, 2); }
        void monitorCallback3(std::string dataName, WBMsg *value) { monitorCallback(dataName, value, 3); }
        void monitorCallback4(std::string dataName, WBMsg *value) { monitorCallback(dataName, value, 4); }
        
        
        void addInjectionMessage(std::string dataName, WBMsg *value);
        
        //callback registered with the native wb, adds the type passed in to the broadcast list (main dynamic message type mechanic)
        void addBroadcastMsgType(std::string dataName, WBMsg *value);
};


#endif //guudpwhiteboardlayer_h
