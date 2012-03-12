/*
 *  guudpbridgemanager.h
 *  
 *  Created by Carl Lusty on 15/2/12.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Rene Hexel.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib> //for system()

#include "guudpbridgemanager.h"


class BridgeManager
{
public:
    std::vector<std::string> dynamic_msg_types_to_broadcast;
    std::list<gsw_injection_message> dynamic_messages_to_inject;
    pthread_mutex_t injection_mutex;

    
    guWhiteboard::Whiteboard *wb;
    BridgeManager(guWhiteboard::Whiteboard *wbd)
    {
        dynamic_msg_types_to_broadcast = std::vector<std::string>();
        dynamic_messages_to_inject = std::list<gsw_injection_message>();
        pthread_mutex_init(&injection_mutex, NULL);
        
        wb = wbd;
        guWhiteboard::Whiteboard::WBResult r;
        wb->subscribeToMessage(ADD_BROADCAST_TYPE_MSG_TYPE, WB_BIND(BridgeManager::addBroadcastMsgType), r);
        

        for (int i = 1; i <= NUM_OF_BROADCASTERS; i++) 
        {
            std::stringstream ss;
            ss << INJECTION_MSG_TYPE << i;
            wb->subscribeToMessage(ss.str().c_str(), WB_BIND(BridgeManager::addInjectionMessage), r);                    
        }
    }

    void convWBMsgToSimpleMsg(WBMsg *value, gsw_simple_message *m)
    {
        m->wbmsg.type = value->getType();
        switch (m->wbmsg.type)
        {
            case WBMsg::TypeEmpty:
                m->wbmsg.len = 0;
                break;
                
            case WBMsg::TypeBool:
                m->wbmsg.len = sizeof(int);
                m->sint = value->getBoolValue();
                break;
                
            case WBMsg::TypeInt:
                m->wbmsg.len = sizeof(int);
                m->sint = value->getIntValue();
                break;
                
            case WBMsg::TypeFloat:
                m->wbmsg.len = sizeof(float);
                m->sfloat = value->getFloatValue();
                break;
                
            case WBMsg::TypeString:
                gu_strlcpy(m->wbmsg.data, value->getStringValue().c_str(), sizeof(m->wbmsg.data));
                m->wbmsg.len = strlen(m->wbmsg.data) + 1;
                break;
                
            case WBMsg::TypeArray:
            {
                int k = 0;
                for (std::vector<int>::const_iterator i = value->getArrayValue().begin(); i < value->getArrayValue().end(); i++)
                    m->ivec[k++] = *i;
                m->wbmsg.len = k;
                break;
            }
            case WBMsg::TypeBinary:
            {
                int len = value->getSizeInBytes();
                if (len > sizeof(m->wbmsg.data)) len = sizeof(m->wbmsg.data);
                m->wbmsg.len = len;
                if (len) memcpy(m->wbmsg.data, value->getBinaryValue(), len);
                break;
            }
        }
    }
    
    void addInjectionMessage(std::string dataName, WBMsg *value)
    {
        if(value->getType() == WBMsg::TypeString)
        {        
            gsw_injection_message msg;
            
            strcpy(msg.type.hash.string, (char *)value->getStringValue().c_str());
            WBMsg tmp = wb->getMessage(msg.type.string);
            
            convWBMsgToSimpleMsg(&tmp, &msg.m);        
            
            msg.machineId = atoi(dataName.substr(dataName.length()-1, dataName.length()).c_str());
//            fprintf(stderr, "Machine: %d\nType %s\nContent %s\n\n", msg.machineId, msg.type.string, (char *)tmp.getStringValue().c_str());
  
            pthread_mutex_lock(&injection_mutex);
            dynamic_messages_to_inject.push_back(msg);
            pthread_mutex_unlock(&injection_mutex);            
        }
    }
    
    void addBroadcastMsgType(std::string dataName, WBMsg *value)
    {
        if(value->getType() == WBMsg::TypeString)
        {
            dynamic_msg_types_to_broadcast.push_back(value->getStringValue());
        }
    }
};


int main(int argc, char *argv[])
{
    fprintf(stderr, "\n **** GU UDP WHITEBOARD BRIDGE ****\n (c) 2012 Carl Lusty\n\n");    
    

    if(getplayernumber() > 0) //Use actual id to avoid running NTP on other machines, assumes it has its own clock sync
    {
        fprintf(stderr, " **** Running NTP ****\n");        
        if(system("ntpd -s") != 0)
        {
            fprintf(stderr, " **** Failed to Run NTP, Exiting . . . ****\n");                    
            exit(EXIT_FAILURE);
        }
        fprintf(stderr, " **** Done Running NTP ****\n\n\n");        
        fprintf(stderr, " **** Running Bridge ****\n");                    
    }
    else
    {
#ifdef FAKE_BROADCAST
        fprintf(stderr, " **** Running Bridge (FAKING ROBOT %d) ****\n", FAKE_BROADCAST);            
#else
        fprintf(stderr, " **** Running Bridge (Listener Only) ****\n");                    
#endif
    }
    
    int op; 
	char *specAddressOfWB = (char *)"";
	
	while((op = getopt(argc, argv, "w:")) != -1)
	{
		switch(op)
		{
			case 'w':
				specAddressOfWB = optarg;
				break;
			case '?':			
				fprintf(stderr, "\n\nUsage: guudpbridge [OPTION] UDP_ID \n");
				fprintf(stderr, "-w, The name of the Whiteboard to connect to.\n");
				return EXIT_FAILURE;
				break;
			default:
				break;
		}
	}	
    
    int udp_id = getplayernumber();    

    if(udp_id > (NUM_OF_BROADCASTERS))
    {
        fprintf(stderr, "Bad UDP_ID passed in, exiting...\n\n");
        return EXIT_FAILURE;        
    }
#ifdef FAKE_BROADCAST
    udp_id = FAKE_BROADCAST;
#endif
    
    set_udp_id(udp_id-1);
    
    //End cmd line arg parsing
    //----------------------------------------

    //Setup broadcast wb
    guWhiteboard::Whiteboard *whiteboard = new guWhiteboard::Whiteboard();
    gu_simple_whiteboard_descriptor *_wbd = whiteboard->_wbd;  /// underlying whiteboard to broadcast from


    //Setup listener wbs    
    gu_simple_whiteboard_descriptor *_wbds[NUM_OF_BROADCASTERS];
    
    for (int i = 0; i < NUM_OF_BROADCASTERS; i++) 
    {
        const char *base_wb_name = REMOTE_WHITEBOARD_BASENAME;
        std::stringstream ss;
        std::stringstream ss2;
        ss << base_wb_name << (i+1); //line the wb names up to the player names
        ss2 << "rm -f /tmp/" << ss.str().c_str();
        
        system(ss2.str().c_str()); //Don't care about return
            
        if((get_udp_id()+1) != (i+1))
        {
            if (!(_wbds[i] = gsw_new_whiteboard(ss.str().c_str())))
            {
                fprintf(stderr, "Unable to create whiteboard '%s'\n", (char *)"guWhiteboard");
                throw "Cannot create whiteboard";
            }
        }
        else
            _wbds[i] = _wbd;
    }

    
    timeval tim;
    gettimeofday(&tim, NULL);
    
        
#ifdef DEBUG
    fprintf(stderr, "\nMessage on the wb: %d\n\nMessages to a packet: %d\nPackets to send all messages: %d\nHashes to a packet: %d\nPackets to send all hashes: %d\nInjections to a packet: %d\n\nCYCLES_PER_SECOND: %d\nPACKETS_PER_TS_INTERVAL %d\n", _wbd->wb->num_types, MESSAGES_PER_PACKET, TOTAL_MESSAGE_PACKETS, HASHES_PER_PACKET, TOTAL_HASH_PACKETS, INJECTIONS_PER_PACKET, CYCLES_PER_SEC, PACKETS_PER_TS_INTERVAL);
    
    fprintf(stderr, "\nMessages sizes:\n\tgsw_single_message:\t%d\n\tgsw_hash_message:\t%d\n\n", (int)sizeof(gsw_single_message), (int)sizeof(gsw_hash_message));
#endif

    
    BridgeManager *bm = new BridgeManager(whiteboard);

    WBMsg *msg = new WBMsg("TestMsg");
    bm->addInjectionMessage(std::string("GSW_InjectMessageOnMachine1"), msg);

    
    BridgeBroadcaster *broadcaster = new BridgeBroadcaster(_wbd, &bm->dynamic_msg_types_to_broadcast, &bm->dynamic_messages_to_inject, &bm->injection_mutex, tim);
    BridgeListener *listener = new BridgeListener(_wbds, whiteboard, tim);    //May not end if loop reading

    

    dispatch_main();                // run the dispatcher "forever"
    
	return 0;
}
