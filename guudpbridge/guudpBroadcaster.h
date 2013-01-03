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
#ifndef guudpbridgebroadcaster_h
#define guudpbridgebroadcaster_h



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

#include "guudpbridgenetworkutil.h"

static void broadcastMonitor(void *broadcaster); 

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


    void broadcastSingleMethod();
    
    void broadcastInjection();
    
    BridgeBroadcaster(gu_simple_whiteboard_descriptor *_wbd, std::vector<std::string> *types, std::list<gsw_injection_message> *injectionVec, pthread_mutex_t *injection_mutex, timeval currTime);
    
    ~BridgeBroadcaster();
};

#endif //guudpbridgebroadcaster_h