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
#ifndef guudpbridgemanager_h
#define guudpbridgemanager_h


#include <Whiteboard.h>
#include <WBMsg.h>
#include <gu_util.h>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <dispatch/dispatch.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>

//Socket flag change to non blocking
#include <unistd.h>
#include <fcntl.h>


#include "guudpbridgenetworkconfig.h"


int main(int argc, char *argv[]);

int get_udp_id();
void set_udp_id(int udp_id);

static u_int32_t alt_hash(const char *s);
static u_int32_t hash_of(const char *s);

static void printWBMsg(std::string dataName, WBMsg *value);
static WBMsg getWBMsg(gu_simple_message *m);    
    
int gsw_register_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name, int32_t msgIndex);
int gsw_hash_for_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name);

dispatch_source_t CreateDispatchTimer(timespec *when,
                                      uint64_t interval,
                                      uint64_t leeway,
                                      dispatch_queue_t queue,
                                      void (*function)(void *));    
    
void addBroadcastMsgType(std::string dataName, WBMsg *value);

//Not needed, using known msg types from wb instead
std::vector<std::string> readMessageTypesFile();

void buf2hash(gsw_hash_message *dst, unsigned char *src);
void hash2buf(unsigned char *dst, gsw_hash_message *src);
void buf2msg(gsw_single_message *dst, unsigned char *src);
void msg2buf(unsigned char *dst, gsw_single_message *src);    

//Listener Methods
void listenMonitor(void *para);
void listenSingleMethod(void *para);
int setuplistener(gu_simple_whiteboard_descriptor *_wbd[NUM_OF_BROADCASTERS]);

//Broadcaster Methods
void broadcastMonitor(void *para);
void broadcastSingleMethod(void *para);
int setupbroadcaster(gu_simple_whiteboard_descriptor *_wbd, std::vector<std::string> *types);

#endif //guudpbridgemanager_h
