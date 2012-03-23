/*
 *  iOSWhiteboard.cc
 *  
 *  Created by Carl Lusty on 21/12/11.
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
#include <cstring>
#include <cstdio>
#include <gu_util.h>
#include <sstream>
#include "iOSWhiteboard.h"

using namespace guWhiteboard;
using namespace std;


iOSWhiteboard::iOSWhiteboard()
{
    int udp_id = getplayernumber();    
    
    if(udp_id > (NUM_OF_BROADCASTERS))
    {
        fprintf(stderr, "Bad UDP_ID passed in, exiting...\n\n");
        exit(EXIT_FAILURE);
    }
#ifdef FAKE_BROADCAST
    udp_id = FAKE_BROADCAST;
#endif
    
    set_udp_id(udp_id-1);
    
    
    timeval tim;
    gettimeofday(&tim, NULL);
    
    
#ifdef DEBUG
    fprintf(stderr, "\n\nMessages to a packet: %d\nPackets to send all messages: %d\nHashes to a packet: %d\nPackets to send all hashes: %d\nInjections to a packet: %d\n\nCYCLES_PER_SECOND: %d\nPACKETS_PER_TS_INTERVAL %d\n", MESSAGES_PER_PACKET, TOTAL_MESSAGE_PACKETS, HASHES_PER_PACKET, TOTAL_HASH_PACKETS, INJECTIONS_PER_PACKET, CYCLES_PER_SEC, PACKETS_PER_TS_INTERVAL);
    
    fprintf(stderr, "\nMessages sizes:\n\tgsw_single_message:\t%d\n\tgsw_hash_message:\t%d\n\n", (int)sizeof(gsw_single_message), (int)sizeof(gsw_hash_message));
#endif
    
    
    
    
    BridgeBroadcaster *broadcaster = new BridgeBroadcaster(NULL, NULL, &dynamic_messages_to_inject, &injection_mutex, tim);
    
    //    WBMsg msg = WBMsg("StringValue");
    //    addInjectionMessage(std::string("TypeToInject"), &msg, 3);
}


iOSWhiteboard::~iOSWhiteboard()
{

}

void iOSWhiteboard::convWBMsgToSimpleMsg(WBMsg *value, gsw_simple_message *m)
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

static WBMsg getWBMsg(gu_simple_message *m)
{
        switch (m->wbmsg.type)
        {
                case WBMsg::TypeBool:
                        return WBMsg((bool)m->sint);
                        
                case WBMsg::TypeInt:
                        return WBMsg(m->sint);
                        
                case WBMsg::TypeFloat:
                        return WBMsg(m->sfloat);
                        
                case WBMsg::TypeString:
                        return WBMsg(m->wbmsg.data);
                        
                case WBMsg::TypeBinary:
                        return WBMsg(m->wbmsg.data, m->wbmsg.len);
                        
                case WBMsg::TypeArray:
                {
                        vector<int> *v = new vector<int>();
                        for (int i = 0; i < m->wbmsg.len; i++)
                                v->push_back(m->ivec[i]);
                        return WBMsg(*v, true);
                }
                default:
                        return WBMsg();
        }
        /* NOTREACHED */
}

void iOSWhiteboard::injectRemoteMessage(const std::string &type, const WBMsg &value, RWBMachine machine)
{      
    gsw_injection_message msg;
    msg.machineId = machine;
    
    strcpy(msg.type.hash.string, (char *)type.c_str());
    
    convWBMsgToSimpleMsg((WBMsg *)&value, &msg.m);        
    
    
    fprintf(stderr, "Machine: %d\nType %s\nContent %s\n\n", msg.machineId, msg.type.hash.string, (char *)msg.m.wbmsg.data);
    
    pthread_mutex_lock(&injection_mutex);
    dynamic_messages_to_inject.push_back(msg);
    pthread_mutex_unlock(&injection_mutex);            
}

void iOSWhiteboard::addReplicationType(const std::string &type, RWBMachine machine)
{
    //NOT YET SUPPORTED
}

WBMsg iOSWhiteboard::getMessage(string type, RWBMachine machine, WBResult *result)
{
    //NOT YET SUPPORTED
}

std::vector<std::string> iOSWhiteboard::getKnownTypesForMachine(RWBMachine machine)
{
    //NOT YET SUPPORTED
}
