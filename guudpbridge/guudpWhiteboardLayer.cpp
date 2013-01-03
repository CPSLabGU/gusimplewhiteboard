/*
 *  guudpWhiteboardLayer.cpp
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */

#include "guudpWhiteboardLayer.h"
#include "guudpUtil.h"


WhiteboardLayer::WhiteboardLayer(guWhiteboard::Whiteboard *wbd, guWhiteboard::Whiteboard **_whiteboards): _wbds(_whiteboards)
{
        dynamic_msg_types_to_broadcast = std::vector<std::string>();
        dynamic_messages_to_inject = std::list<gsw_injection_message>();
        pthread_mutex_init(&injection_mutex, NULL);
        
        wb = wbd;
        guWhiteboard::Whiteboard::WBResult r;
        wb->subscribeToMessage(ADD_BROADCAST_TYPE_MSG_TYPE, WB_BIND(WhiteboardLayer::addBroadcastMsgType), r);
        
        _wbds[0]->subscribeToMessage("*", WB_BIND(WhiteboardLayer::monitorCallback1), r);
        _wbds[1]->subscribeToMessage("*", WB_BIND(WhiteboardLayer::monitorCallback2), r);
        _wbds[2]->subscribeToMessage("*", WB_BIND(WhiteboardLayer::monitorCallback3), r);
        _wbds[3]->subscribeToMessage("*", WB_BIND(WhiteboardLayer::monitorCallback4), r);
        
        for (int i = 1; i <= NUM_OF_BROADCASTERS; i++)
        {
                std::stringstream ss;
                ss << INJECTION_CONTENT << i;
                wb->subscribeToMessage(ss.str().c_str(), WB_BIND(WhiteboardLayer::addInjectionMessage), r);
        }
}


void WhiteboardLayer::monitorCallback(std::string type, WBMsg *value, int machineNum)
{
        int t = gsw_offset_for_message_type(_wbds[machineNum-1]->_wbd, type.c_str());
        
        if(recieved_generations[machineNum-1][t] == _wbds[machineNum-1]->_wbd->wb->indexes[t])
                return;
        
        gsw_injection_message msg;
        int machine = machineNum;
        msg.machineId = machine;
        
        strcpy(msg.type.hash.string, (char *)type.c_str());
        
        convWBMsgToSimpleMsg(value, &msg.m);
        //        fprintf(stderr, "Injection to machine: %d\nType %s\nContent %s\n\n", msg.machineId, msg.type.hash.string, (char *)msg.m.wbmsg.data);
        
        pthread_mutex_lock(&injection_mutex);
        //        if(type.compare(std::string(ADD_BROADCAST_TYPE_MSG_TYPE)) == 0)
        //        {
        //            std::list<std::pair<std::string, int> >::iterator it;
        //            for (it = dynamic_msg_types_to_listen_for.begin(); it != dynamic_msg_types_to_listen_for.end(); it++)
        //            {
        //                if(strncmp((*it).first.c_str(), value->getStringValue().c_str(), value->getStringValue().length()) == 0 && (*it).second == machine-1)
        //                   break;
        //            }
        //            if(it == dynamic_msg_types_to_listen_for.end())
        //            {
        //                dynamic_msg_types_to_listen_for.push_back(make_pair(value->getStringValue(), machine-1));
        //            }
        //        }
        dynamic_messages_to_inject.push_back(msg);
        pthread_mutex_unlock(&injection_mutex);
}

void WhiteboardLayer::addInjectionMessage(std::string dataName, WBMsg *value)
{
        
        //Not sure what is happening, I would suggest changing this to recieve the message type as the value
        
        if(value->getType() == WBMsg::TypeString)
        {
                gsw_injection_message msg;
                int machine = atoi(dataName.substr(dataName.length()-1, dataName.length()).c_str());  //Only works up to 9
                msg.machineId = machine;
                
                //Get Type
                std::stringstream ss;
                ss << INJECTION_TYPE << machine;
                WBMsg tmp = wb->getMessage((char *)ss.str().c_str());
                
                if(tmp.getType() != WBMsg::TypeString)
                        return;
                
                strcpy(msg.type.hash.string, (char *)tmp.getStringValue().c_str());
                
                
                convWBMsgToSimpleMsg(value, &msg.m);
                
                
                //fprintf(stderr, "Machine: %d\nType %s\nContent %s\n\n", msg.machineId, msg.type.hash.string, (char *)msg.m.wbmsg.data);
                
                pthread_mutex_lock(&injection_mutex);
                dynamic_messages_to_inject.push_back(msg); //fifo broadcast queue
                pthread_mutex_unlock(&injection_mutex);
        }
}

void WhiteboardLayer::addBroadcastMsgType(std::string dataName, WBMsg *value)
{
        if(value->getType() == WBMsg::TypeString)
        {
                dynamic_msg_types_to_broadcast.push_back(value->getStringValue());
        }
}

