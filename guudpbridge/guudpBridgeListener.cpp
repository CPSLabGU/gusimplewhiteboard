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


#include "guudpBridgeListener.h"
#include <algorithm>

#ifdef DEBUG
static void listenMonitor(void *listener)
{
    BridgeListener *c = (BridgeListener *)listener;
#ifdef OUTPUT_LISTENER_IN_DEBUG    
    if(c->iter_listener > 0)
        fprintf(stderr, "got: %d  \ttotal got: %d\thash: %d  \tmsg: %d  \t Inj: %d\tavg read %llu\n", c->gotHashPackets+c->gotMessagePackets+c->gotInjectionPackets, c->total_recv, c->gotHashPackets, c->gotMessagePackets, c->gotInjectionPackets, (c->avgRecvTime/c->iter_listener));
#endif    
    c->gotHashPackets = 0;
    c->gotInjectionPackets = 0;
    c->lostPackets = 0;
    c->gotMessagePackets = 0;
}
#endif

void BridgeListener::listenSingleMethod()
{   
#ifdef DEBUG    
    startRecvTime = get_utime();    
    long long startTime = get_utime();    
#endif    
    fd_set socketReadSet;
    struct timeval msgSelectTimeout;

    /* setup select vars */    
    FD_ZERO(&socketReadSet);
    FD_SET(sock,&socketReadSet);
    msgSelectTimeout.tv_sec  = 0;
    msgSelectTimeout.tv_usec = READ_TIMEOUT;
    
        if (select(sock+1,&socketReadSet,0,0,&msgSelectTimeout) == -1) {
            if (errno != EINTR)            
            {
                perror("select() failed");
                return;
            }
        }
    
        /* receive a packet */
        if ((recv_len = recvfrom(sock, recv_buffer, MTU, 0, //Need to sort out the recv size later
                                 NULL, NULL)) < 0) 
        {
#ifdef DEBUG            
            //Lost packet
            lostPackets++;
#endif
        }
        else
        {
            
            //Needs moving into a method and calling after buffer reconstruction
#ifdef DETECT_AND_STOP_UDP_DUPLICATION            
            if(((gsw_hash_message *)recv_hash)->uniquePacketId == 0)
            {
                memset(&packetsAlreadyGotten,0,DETECTION_BUFFER_SIZE*sizeof(bool));
            }
            if(packetsAlreadyGotten[((gsw_hash_message *)recv_hash)->uniquePacketId] == true)            
            {
                fprintf(stderr, "Skip Dup Packet\n");
#ifdef DEBUG
                endRecvTime = get_utime();
                iter_listener++;
                avgRecvTime += (endRecvTime - startRecvTime);
                rawRecvTime = (endRecvTime - startRecvTime);
#endif
                return;
            }
            else
            {
                packetsAlreadyGotten[((gsw_hash_message *)recv_hash)->uniquePacketId] = true;
            }
#endif  
            if(recv_buffer[0] == Msg)
            {
                gsw_single_message msg;   
                buf2msg(&msg, (unsigned char *)&recv_buffer[0]);
                
                current_poster = msg.udpId;
#ifndef SEND_TO_SELF
                if(current_poster == get_udp_id()) //Ignore messages from self, generally only happens with broadcast
                {
#ifdef DEBUG
                    endRecvTime = get_utime();
                    iter_listener++;
                    avgRecvTime += (endRecvTime - startRecvTime);
                    rawRecvTime = (endRecvTime - startRecvTime);
#endif
                    return;
                }   
#endif
#ifdef DEBUG            
                gotMessagePackets++;
                total_recv++;            
#endif                
                gsw_procure(_wbd_listeners[current_poster]->sem, GSW_SEM_PUTMSG);
                for(int i = 0; i < MESSAGES_PER_PACKET; i++)
                {
                    int t;
                    if(msg.typeOffset[i] >= GSW_NUM_RESERVED)
                        t = indexLookup[msg.typeOffset[i]];
                    else
                        t = msg.typeOffset[i];
                    
                    _wbd_listeners[current_poster]->wb->indexes[t] = msg.current_generation[i];
                    recieved_generations[current_poster][t] = msg.current_generation[i];
#ifdef GENERATION_BROADCASTING                    
                    for (int g = 0; g < GU_SIMPLE_WHITEBOARD_GENERATIONS; g++)
                    {
                        _wbd_listeners[current_poster]->wb->messages[t][g] = msg.message_generations[i][g];
                    }
#else
                    _wbd_listeners[current_poster]->wb->messages[t][_wbd_listeners[current_poster]->wb->indexes[t]] = msg.message_generations[i];
#endif
                }
                gsw_vacate(_wbd_listeners[current_poster]->sem, GSW_SEM_PUTMSG);                
                gsw_signal_subscribers(_wbd_listeners[current_poster]->wb); //Done getting new messages, notify subs
            }
            else if(recv_buffer[0] == Hash)
            {
                gsw_hash_message hashToRecv;   
                buf2hash(&hashToRecv, (unsigned char *)&recv_buffer[0]);
                
                current_poster = hashToRecv.udpId;
#ifndef SEND_TO_SELF
                if(current_poster == get_udp_id()) //Ignore messages from self, generally only happens with broadcast
                {
#ifdef DEBUG
                    endRecvTime = get_utime();
                    iter_listener++;
                    avgRecvTime += (endRecvTime - startRecvTime);
                    rawRecvTime = (endRecvTime - startRecvTime);
#endif
                    return;
                }   
#endif
#ifdef DEBUG            
                gotHashPackets++;
                total_recv++;
#endif

                for(int j = 0; j < HASHES_PER_PACKET; j++)
                {
                    indexLookup[hashToRecv.offset[j]] = gsw_register_message_type(_wbd_listeners[current_poster], hashToRecv.typeName[j].hash.string);
                }
            }
            else if(recv_buffer[0] == Injection)
            {
#ifdef DEBUG            
                gotInjectionPackets++;
                total_recv++;
#endif
                gsw_injection_packet injToRecv;   
                buf2inj(&injToRecv, (unsigned char *)&recv_buffer[0]);
                
                int targetMachine = -1;
                for(int j = 0; j < injToRecv.numOfInjectionMsgs; j++)
                {
                    targetMachine = injToRecv.targetMachineId[j];
                    if((get_udp_id()+1) == targetMachine)
                    {
                        std::vector<std::string>::iterator it;                        
                        // iterator to vector element:
                        it = find (msg_types_to_broadcast->begin(), msg_types_to_broadcast->end(), std::string(injToRecv.type[j].hash.string));
                        if(it == msg_types_to_broadcast->end())
                        {
                            msg_types_to_broadcast->push_back(std::string(injToRecv.type[j].hash.string));
                        }
                           
                        int t = gsw_offset_for_message_type(_wbd_injection->_wbd, injToRecv.type[j].hash.string);
                        gsw_procure(_wbd_injection->_wbd->sem, GSW_SEM_PUTMSG);
                        
                        gu_simple_whiteboard *wb = _wbd_injection->_wbd->wb;
                        gu_simple_message *m = gsw_next_message(wb, t);
                        memcpy(m, &injToRecv.content[j], sizeof(gu_simple_message));
                        gsw_increment(wb, t);
                        gsw_vacate(_wbd_injection->_wbd->sem, GSW_SEM_PUTMSG);
                        if (wb->subscribed) gsw_signal_subscribers(wb);
                    }
                }
            }
            else
            {
                //DO NOTHING
            }
        }
#ifdef DEBUG
    endRecvTime = get_utime();
    iter_listener++;
    avgRecvTime += (endRecvTime - startRecvTime);
    rawRecvTime = (endRecvTime - startRecvTime);
#endif
}

void BridgeListener::set_nonblock(int socket)
{
    int flags;
    flags = fcntl(socket,F_GETFL,0);
    fcntl(socket, F_SETFL, flags | O_NONBLOCK);
} 

// get sockaddr, IPv4 or IPv6:
void *BridgeListener::get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

BridgeListener::BridgeListener(gu_simple_whiteboard_descriptor *_wbd[NUM_OF_BROADCASTERS], guWhiteboard::Whiteboard *_wbd_for_injections, u_int8_t (&recieved_generations_array)[NUM_OF_BROADCASTERS][GSW_TOTAL_MESSAGE_TYPES], timeval currTime, std::vector<std::string> *typesSent): recieved_generations(recieved_generations_array)
{
    //Default vars
    //------------------------------
    current_poster = 0;
    flag_on = 1;
#ifdef DEBUG    
    gotHashPackets = 0; //Num of hash gotten
    gotInjectionPackets = 0; //Num of injections gotten
    gotMessagePackets = 0; //Num of msg gotten
    lostPackets = 0; //Num of packets missed
    total_recv = 0;
    
    avgRecvTime = 0;
    iter_listener = 0;
    rawRecvTime = 0;
    
    //TEMP
    oldId = -1;
#endif
    msg_types_to_broadcast = typesSent;
    _wbd_injection = _wbd_for_injections;
    for (int i = 0; i < NUM_OF_BROADCASTERS; i++) {
        _wbd_listeners[i] = _wbd[i];
    }


    struct sockaddr_in mc_addr;   /* socket address structure */
    struct ip_mreq mc_req;        /* multicast request structure */
    char* mc_addr_str;            /* multicast IP address */
    unsigned short mc_port;       /* multicast port */
    struct sockaddr_in from_addr; /* packet source */
    unsigned int from_len;        /* source addr length */

#ifndef USE_BROADCAST
    mc_addr_str = (char *)MULTICASTADDRESS;     /* assign multicast ip address */
#endif    
    mc_port = SERVERPORT;               /* assign multicast port number */

    
    /* create socket to join multicast group on */
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket() failed");
        exit(1);
    }
  
    struct timeval tv;
    tv.tv_sec = 0;    
    tv.tv_usec = 2500;
    //setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO,(struct timeval *)&tv,sizeof(struct timeval));
      set_nonblock(sock);
    
    
//    int buffsize = 400000;
    int buffsize = (MTU+100)*MESSAGES_IN_READ_BUFFER;    
    if ((setsockopt(sock, SOL_SOCKET, SO_RCVBUF, &buffsize, sizeof(buffsize))) < 0) {
        perror("setsockopt() failed changing SO_RCVBUF");
        exit(1);
    }

    /* set reuse port to on to allow multiple binds per host */
    if ((setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag_on,
                    sizeof(flag_on))) < 0) {
        perror("setsockopt() failed");
        exit(1);
    }

    
    /* construct a multicast address structure */
    memset(&mc_addr, 0, sizeof(mc_addr));
    mc_addr.sin_family      = PF_INET;
    mc_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    mc_addr.sin_port        = htons(mc_port);
    
    /* bind to multicast address to socket */
    if ((bind(sock, (struct sockaddr *) &mc_addr, 
              sizeof(mc_addr))) < 0) {
        perror("bind() failed");        
        return;
    }
    fprintf(stderr, "UDP Bridge running . . .\n");
    
    
    //Add pid to whiteboard, used for checking if the bridge is running
    _wbd_for_injections->addMessage("UDP_BRIDGE_PID", WBMsg((int)getpid()));    
    
#ifndef USE_BROADCAST    
#ifndef UNICAST
    /* construct an IGMP join request structure */
    mc_req.imr_multiaddr.s_addr = inet_addr(mc_addr_str);
    mc_req.imr_interface.s_addr = htonl(INADDR_ANY);
    
    /* send an ADD MEMBERSHIP message via setsockopt */
    if ((setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, 
                    (void*) &mc_req, sizeof(mc_req))) < 0) {
        perror("setsockopt() failed");
        exit(1);
    }
#endif
#endif
    
    /* clear the receive buffers & structs */
    memset(recv_hash, 0, sizeof(recv_hash));
    memset(recv_data, 0, sizeof(recv_data));
    
    from_len = sizeof(from_addr);
    memset(&from_addr, 0, from_len);
    
    
    
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
    
    
    //Debug output methods
#ifdef DEBUG
    fprintf(stderr, "\t\t\t\t\t\t\t\tWait %ld seconds\n", (target-(min*60))-secs);
    
    dispatch_source_t listener_monitor = CreateDispatchTimer(&when,
                                                             (TS_INTERVAL*1000ull),
                                                             0ull,
                                                             dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                             *listenMonitor, this);
#endif
    
    
    //Run Listener
#ifdef READ_LOOP
    while(true)
    {
        listenSingleMethod();
    }    
#else
    timespec when2 = when;
    when2.tv_nsec += RECV_NETWORK_DELAY * 1000ull;
    dispatch_source_t listener = CreateDispatchTimer(&when2,
                                                     (MSG_INTERVAL*1000ull), 
                                                     0ull,
                                                     dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                     *listenSingleMethod, this);
#endif    
}

BridgeListener::~BridgeListener()
{
    shutdown(sock, SHUT_WR);
    close(sock);
}


