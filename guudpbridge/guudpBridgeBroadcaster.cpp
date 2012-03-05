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


#include "guudpBridgeBroadcaster.h"

void BridgeBroadcaster::broadcastMonitor(void *para)
{
    //toggle broadcasting
    if(sending_count == NUM_OF_BROADCASTERS-1)
    {
        sending_currently = true;
        sending_count = 0;
        
#ifdef BURST_SEND
        for (int i = 0; i < (PACKETS_PER_TS_INTERVAL/NUM_OF_BROADCASTERS); i++) 
        {
            broadcastSingleMethod(NULL);
        }
#endif
    }
    else
    {
#ifdef IGNORE_TT_ARCH
        sending_currently = true;        
#else
        sending_currently = false;
#endif        
        sending_count++;
    }
    
#ifdef DEBUG
    if(iter > 0)
        fprintf(stderr, "Sent %d   \tavg time %llu\t\ttotal sent %d\n", sent, (avgSendTime/iter), total_sent);
    sent = 0;
    return;
#endif
}

void BridgeBroadcaster::broadcastSingleMethod(void *para)
{    
//    if(uniqueId >= 1000)
//        sending_currently = false;
    
    if(sending_currently)
    {
        startSendTime = get_utime();
        
        if(msg_types_to_broadcast->size() == 0)
            currently_sending = Msg;
        
        if(currently_sending == Hash)
        {
            gsw_hash_message hashToSend;
            hashToSend.packetInfo = Hash;           
            hashToSend.udpId = get_udp_id();
#ifdef DETECT_AND_STOP_UDP_DUPLICATION        
            if(uniqueId >= DETECTION_BUFFER_SIZE)
                uniqueId = 0;
            else
                uniqueId++;
            hashToSend.uniquePacketId = uniqueId;
#else
            uniqueId++;            
#endif            
            for(int j = 0; j < HASHES_PER_PACKET; j++)
            {
                int currOff = gsw_offset_for_message_type(_wbd_broadcaster, (char *)msg_types_to_broadcast->at(offset).c_str());
                hashToSend.offset[j] = currOff;
                hashToSend.typeName[j] = _wbd_broadcaster->wb->typenames[currOff];
                offset++;
                if(offset >= msg_types_to_broadcast->size()) 
                {
                    currently_sending = Msg;
                    offset = 0;
                }
            }
            
            hash2buf(&buffer[0], &hashToSend);
            
            if ((numbytes=sendto(sockfd, buffer, sizeof(buffer), 0,
                                 (struct sockaddr *)&mc_addr, sizeof(mc_addr))) == -1) {
                if(errno != 65) //ENETUNREACH - no route to host
                {
                    perror("sendto");
                    exit(1);
                }
            }
            sent++;
            total_sent++;        
            if(currently_sending == Msg) //offset will have moved since the change to Msg while filling the last hash
                offset = 0;
        }
        else if (currently_sending == Msg)
        {        
            gsw_single_message messageToSend;
            messageToSend.packetInfo = Msg;
            messageToSend.udpId = get_udp_id();
#ifdef DETECT_AND_STOP_UDP_DUPLICATION        
            if(uniqueId >= DETECTION_BUFFER_SIZE)
                uniqueId = 0;
            else
                uniqueId++;
            messageToSend.uniquePacketId = uniqueId;
#else
            uniqueId++;
#endif                        
            
            for(int j = 0; j < MESSAGES_PER_PACKET; j++)
            {
                messageToSend.typeOffset[j] = offset;
#ifdef GENERATION_BROADCASTING
                u_int8_t h = _wbd_broadcaster->wb->indexes[offset];
                if (h >= GU_SIMPLE_WHITEBOARD_GENERATIONS) h = 0;
                
                messageToSend.current_generation[j] = h;
                
                for (int g = 0; g < GU_SIMPLE_WHITEBOARD_GENERATIONS; g++)
                {
                    messageToSend.message_generations[j][g] =  _wbd_broadcaster->wb->messages[offset][g];
                }
#else
                messageToSend.message_generations[j] =  _wbd_broadcaster->wb->messages[offset][_wbd_broadcaster->wb->indexes[offset]];
#endif
                offset++;
                if(offset >= GSW_NUM_RESERVED) 
                {
                    msg_loops++;
                    if(msg_loops >= MESSAGES_TO_SEND_PER_HASH)
                    {
                        currently_sending = Hash;
                        msg_loops = 0;
                    }
                    offset = 0;
                }
            }
                
            msg2buf(&buffer[0], &messageToSend);
            
            if ((numbytes=sendto(sockfd, buffer, sizeof(buffer), 0,
                                 (struct sockaddr *)&mc_addr, sizeof(mc_addr))) == -1) {
                if(errno != 65) //ENETUNREACH - no route to host
                {
                    perror("sendto");
                    exit(1);
                }
            }
            sent++;
            total_sent++;
            if(currently_sending == Hash) //offset will have moved since the change to Hash while filling the last msg
                offset = 0;
        }
        else
        {
            //NOTHING
        }
        endSendTime = get_utime();    
        iter++;
        avgSendTime += (endSendTime - startSendTime);
    }
}

BridgeBroadcaster::BridgeBroadcaster(gu_simple_whiteboard_descriptor *_wbd, std::vector<std::string> *types, timeval currTime)
{
    //Default vars
    //----------------------------------------    
    mc_ttl=1;
    uniqueId = 0;
    currently_sending = Hash;
    sent = 0;
    total_sent = 0;
    avgSendTime = 0;
    iter = 0;
    
    padding = 0;
    sending_currently = false;
    sending_count = 0;    
    
    offset = 0;    
    msg_loops = 0;  
    //----------------------------------------
    
    
    msg_types_to_broadcast = types;
    _wbd_broadcaster = _wbd;
    
    //Setup socket
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

#ifndef UNICAST    
	// this call is what allows broadcast packets to be sent:
	if (setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_TTL, (void*) &mc_ttl, sizeof(mc_ttl)) == -1)
    {
		perror("setsockopt (MULTICAST_TTL)");
		exit(1);
	}
    
#ifndef SEND_TO_SELF    
	// this call stops packets I send coming back to me
    int  val=0;
	if (setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_LOOP, (const char *)&val, sizeof(val)) == -1)
    {
		perror("setsockopt (IP_MULTICAST_LOOP)");
		exit(1);
	} 
#else
    fprintf(stderr, "WARNING: Sending all packets to self as well\n");
#endif
#endif

    /* construct address structure */
    memset(&mc_addr, 0, sizeof(mc_addr));
    mc_addr.sin_family      = PF_INET;
    mc_addr.sin_addr.s_addr = inet_addr(MULTICASTADDRESS);
    mc_addr.sin_port        = htons(SERVERPORT);
    
    memset(buffer, 0, sizeof(buffer));


#ifdef DEBUG
    fprintf(stderr, "\nMessage on the wb: %d\n\nMessages to a packet: %d\nPackets to send all messages: %d\nHashes to a packet: %d\nPackets to send all hashes: %d\n\nFinished sending all messages\n", _wbd_broadcaster->wb->num_types, MESSAGES_PER_PACKET, TOTAL_MESSAGE_PACKETS, HASHES_PER_PACKET, TOTAL_HASH_PACKETS);
    
    fprintf(stderr, "\nMessages sizes:\n\tgsw_single_message:\t%d\n\tgsw_hash_message:\t%d\n\n", (int)sizeof(gsw_single_message), (int)sizeof(gsw_hash_message));
#endif
    
    
    
    
    
    long int min = currTime.tv_sec / 60;
    long int target = min * 60; //removes seconds
    
    int secs = currTime.tv_sec - target;
    
    //Start at next 10s mark
    target += ((secs/10)+1)*10;
    
    
    timespec when;
    when.tv_sec = target;
    when.tv_nsec = 0;
    
    timespec tmp = when;
    tmp.tv_nsec += (BROADCASTER_TS*get_udp_id()) * 1000ull;
    
    //Stop non robots from broadcasting
    if(!(get_udp_id() < 0))
    {
        dispatch_source_t broadcast_monitor = CreateDispatchTimer(&tmp,
                                                                  (BROADCASTER_TS*1000ull),
                                                                  0ull,
                                                                  dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                                  *broadcastMonitor, this);
#ifndef BURST_SEND
        //Run Broadcaster    
        dispatch_source_t broadcaster = CreateDispatchTimer(&when,
                                                            (MSG_INTERVAL_PER_BROADCAST*1000ull), 
                                                            0ull,
                                                            dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                            *broadcastSingleMethod, this);        
#endif    
    }
}
