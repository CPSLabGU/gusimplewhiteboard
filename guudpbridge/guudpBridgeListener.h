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
#ifndef guudpbridgelistener_h
#define guudpbridgelistener_h

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

#include "guudpbridgenetworkutil.h"

class BridgeListener
{
    gu_simple_whiteboard_descriptor *_wbd_listeners[NUM_OF_BROADCASTERS];  /// underlying whiteboard
    guWhiteboard::Whiteboard *_wbd_injection;  /// underlying whiteboard    
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
    
    long long startRecvTime;
    long long endRecvTime;
    long long avgRecvTime;
    int iter_listener;
    long long rawRecvTime;
    
    //TEMP
    int oldId;
    
#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    bool packetsAlreadyGotten[DETECTION_BUFFER_SIZE];
#endif
#endif
    //Would rather make this global to avoid malloc calls, only work without timers. ie. Loop read.    
    char recv_buffer[MTU];
        
public:
    
#ifdef DEBUG    
    void listenMonitor(void *para);
#endif
    
    void listenSingleMethod(void *para);

    void set_nonblock(int socket);

    // get sockaddr, IPv4 or IPv6:
    void *get_in_addr(struct sockaddr *sa);

    BridgeListener(gu_simple_whiteboard_descriptor *_wbd[NUM_OF_BROADCASTERS], guWhiteboard::Whiteboard *_wbd_for_injections, timeval currTime);

};


#endif //guudpbridgelistener_h