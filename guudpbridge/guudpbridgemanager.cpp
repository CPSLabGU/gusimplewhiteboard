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

int my_udp_id = -1;


int main(int argc, char *argv[])
{
    fprintf(stderr, "\n **** GU UDP WHITEBOARD BRIDGE ****\n (c) 2012 Carl Lusty\n\n");    
    
    if(getplayernumber() > 0)
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
        fprintf(stderr, " **** Running Bridge (Listener Only) ****\n");            


    
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
    set_udp_id(udp_id-1);
    
    //End cmd line arg parsing
    //----------------------------------------
    
    //Setup broadcast wb
    gu_simple_whiteboard_descriptor *_wbd;  /// underlying whiteboard to broadcast from

    if (!(_wbd = gsw_new_whiteboard("guWhiteboard")))
    {
        fprintf(stderr, "Unable to create whiteboard '%s'\n", (char *)"guWhiteboard");
        throw "Cannot create whiteboard";
    }

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
    
    //Setup sockets
    setupbroadcaster(_wbd);
    setuplistener(_wbds);    

    
    
    timeval tim;
    gettimeofday(&tim, NULL);
    
    long int min = tim.tv_sec / 60;
    long int target = min * 60; //removes seconds
    
    int secs = tim.tv_sec - target;
    
    //Start at next 10s mark
    target += ((secs/10)+1)*10;
    
    timespec when;
    when.tv_sec = target;
    when.tv_nsec = 0;
    
    
    
    timespec tmp = when;
    tmp.tv_nsec += (BROADCASTER_TS*get_udp_id()) * 1000ull;
    
    //Stop non robots from broadcasting
    if(!(udp_id < 0))
    {
        dispatch_source_t broadcast_monitor = CreateDispatchTimer(&tmp,
                                                                  (BROADCASTER_TS*1000ull),
                                                                  0ull,
                                                                  dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                                  broadcastMonitor);
#ifndef BURST_SEND
        //Run Broadcaster    
        dispatch_source_t broadcaster = CreateDispatchTimer(&when,
                                                            (MSG_INTERVAL_PER_BROADCAST*1000ull), 
                                                            0ull,
                                                            dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                            broadcastSingleMethod);        
#endif    
    }
    
    
    //Debug output methods
#ifdef DEBUG
    fprintf(stderr, "\t\t\t\t\t\t\t\tWait %ld seconds\n", (target-(min*60))-secs);
    
    dispatch_source_t listener_monitor = CreateDispatchTimer(&when,
                                                             (TS_INTERVAL*1000ull),
                                                             0ull,
                                                             dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                             listenMonitor);
#endif

    
    //Run Listener
#ifdef READ_LOOP
    while(true)
    {
        listenSingleMethod(NULL);
    }    
#else
    timespec when2 = when;
    when2.tv_nsec += RECV_NETWORK_DELAY * 1000ull;
    dispatch_source_t listener = CreateDispatchTimer(&when2,
                                                   (MSG_INTERVAL*1000ull), 
                                                   0ull,
                                                   dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                   listenSingleMethod);
#endif

    

    dispatch_main();                // run the dispatcher "forever"
    
	return 0;
}

int get_udp_id()
{
    return my_udp_id;
}

void set_udp_id(int udp_id)
{
    my_udp_id = udp_id;
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
            std::vector<int> *v = new std::vector<int>();
            for (int i = 0; i < m->wbmsg.len; i++)
                v->push_back(m->ivec[i]);
            return WBMsg(*v, true);
        }
        default:
            return WBMsg();
    }
    /* NOTREACHED */
}

static void printWBMsg(std::string dataName, WBMsg *value)
{
	std::ostringstream out;
	switch ((int)value->getType()) 
	{
		case WBMsg::TypeBool:
		{
			out << (int)value->getBoolValue();
			break;
		}
		case WBMsg::TypeInt:
		{
			out << value->getIntValue();
			break;
		}
		case WBMsg::TypeFloat:
		{
			out << value->getFloatValue();
			break;
		}
		case WBMsg::TypeString:
		{
			out << value->getStringValue();
			break;
		}
		case WBMsg::TypeArray:
        {
            const std::vector<int> &vec = value->getArrayValue();
            int n = vec.size();
            out << "( ";
            for (int i = 0; i < n; i++)
            {
                out << vec[i];
                if (i < n-1) out << ", ";
            }
            out << " )";
        }
		default:
		{
			break;
		}
	}
	printf("Type: \t%s\t\tValue:\t%s\n", (char *)dataName.c_str(), (char *)out.str().c_str());
}


static u_int32_t hash_of(const char *s)
{
    u_int32_t hash = *s;
    while (*s++)
    {
        u_int32_t stir = hash & 0xf8000000U;
        hash &= 0x07ffffffU;
        hash <<= 5;
        hash ^= stir >> 27;
        hash ^= *s;
    }
    return hash;
}


static u_int32_t alt_hash(const char *s)
{
    u_int32_t hash = *s;
    while (*s++)
    {
        hash &= 0x0fffffffU;
        hash <<= 4;
        hash += *s;
        u_int32_t stir = hash & 0xf0000000U;
        if (stir != 0)
        {
            hash ^= stir >> 24;
            hash ^= stir;
        }
    }
    hash |= 1;              // needs to be an odd number
    
    return hash;
}

int gsw_hash_for_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name)
{
    gu_simple_whiteboard *wb = wbd->wb;
    unsigned offs = hash_of(name) % GSW_TOTAL_MESSAGE_TYPES;
    gu_simple_message *type; // = &wb->hashes[offs];
    for (int i = 0; i < GSW_TOTAL_MESSAGE_TYPES; i++)
    {
        type = &wb->hashes[offs];
        if (!*type->hash.string)                        // new message type?
            return -1;
        if (strcmp(type->hash.string, name) == 0)
            return offs;
        /* hash collision, add to the offset */
        offs += alt_hash(name);
        offs %= GSW_TOTAL_MESSAGE_TYPES;
    }
    
    fprintf(stderr, "Cannot get offset for message type '%s': hash table full (%d entries)\n", name, wb->num_types);
    
    return -1;
}

int gsw_register_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name, int32_t msgIndex)
{
    gsw_procure(wbd->sem, GSW_SEM_MSGTYPE);
    
    //bool exists = false;
    gu_simple_whiteboard *wb = wbd->wb;
    unsigned offs = hash_of(name) % GSW_TOTAL_MESSAGE_TYPES;
    gu_simple_message *type = &wb->hashes[offs];
    
    while (wb->num_types < GSW_TOTAL_MESSAGE_TYPES)
    {
        type = &wb->hashes[offs];
        if (!*type->hash.string)
        {
            gu_strlcpy(type->hash.string, name, sizeof(type->hash.string));
            DBG(printf(" - registering wb message type #%d for '%s' at %d\n", wb->num_types, type->hash.string, offs));
            type->hash.value = msgIndex;
            wb->num_types++;
            wb->typenames[type->hash.value] = *type;
            break;
        }
        if (strcmp(type->hash.string, name) == 0)
        {
            //exists = true;
            break;
        }
        /* collision, add to the offset */
        DBG(printf("Hash collision at offset %u: %u == %u %% %d for:\n'%s' <> '%s'",
                   offs, hash_of(name), hash_of(type->hash.string), GSW_TOTAL_MESSAGE_TYPES,
                   name, type->hash.string));
        offs += alt_hash(name);
        offs %= GSW_TOTAL_MESSAGE_TYPES;
    }
    
    gsw_vacate(wbd->sem, GSW_SEM_MSGTYPE);
    
    if (wb->num_types < GSW_TOTAL_MESSAGE_TYPES)
        return type->hash.value;
    
    fprintf(stderr, "Cannot register whiteboard message type '%s': hash table capacity %d reached!\n", name, wb->num_types);
    
    return -1;
}

//https://developer.apple.com/library/mac/#documentation/General/Conceptual/ConcurrencyProgrammingGuide/GCDWorkQueues/GCDWorkQueues.html
dispatch_source_t CreateDispatchTimer(timespec *when,
                                      uint64_t interval,
                                      uint64_t leeway,
                                      dispatch_queue_t queue,
                                      void (*function)(void *))
{
    dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER,
                                                     0, 0, queue);
    if (timer)   
    {
        //        dispatch_source_set_timer(timer, dispatch_time(DISPATCH_TIME_NOW, secToWait * NSEC_PER_SEC), interval, leeway);
        dispatch_source_set_timer(timer, dispatch_walltime(when, 0), interval, leeway);
        dispatch_source_set_event_handler_f(timer, function);
        dispatch_resume(timer);
    }
    return timer;
}


void hash2buf(unsigned char *dst, gsw_hash_message *src)
{
    unsigned char *off;
    
    off = dst;
    
    memcpy(off, (void*)&src->packetInfo, sizeof src->packetInfo);
    off += sizeof src->packetInfo;
    
#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    memcpy(off, (void*)&src->uniquePacketId, sizeof src->uniquePacketId);
    off += sizeof src->uniquePacketId;
#endif
    
    memcpy(off, (void*)&src->udpId, sizeof src->udpId);
    off += sizeof src->udpId;
    
    memcpy(off, (void*)&src->offset, sizeof src->offset);
    off += sizeof src->offset;

    memcpy(off, (void*)&src->typeName, sizeof src->typeName);
    off += sizeof src->typeName;
}

void buf2hash(gsw_hash_message *dst, unsigned char *src)
{
    unsigned char *off;
    
    off = src;
    
    memcpy((void*)&dst->packetInfo, off, sizeof dst->packetInfo);
    off += sizeof dst->packetInfo;
    
#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    memcpy((void*)&dst->uniquePacketId, off, sizeof dst->uniquePacketId);
    off += sizeof dst->uniquePacketId;
#endif  
    
    memcpy((void*)&dst->udpId, off, sizeof dst->udpId);
    off += sizeof dst->udpId;
    
    memcpy((void*)&dst->offset, off, sizeof dst->offset);
    off += sizeof dst->offset;

    memcpy((void*)&dst->typeName, off, sizeof dst->typeName);
    off += sizeof dst->typeName;
}

void msg2buf(unsigned char *dst, gsw_single_message *src)
{
    unsigned char *off;
    
    off = dst;
    
    memcpy(off, (void*)&src->packetInfo, sizeof src->packetInfo);
    off += sizeof src->packetInfo;
    
#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    memcpy(off, (void*)&src->uniquePacketId, sizeof src->uniquePacketId);
    off += sizeof src->uniquePacketId;
#endif
    
    memcpy(off, (void*)&src->udpId, sizeof src->udpId);
    off += sizeof src->udpId;
    
    memcpy(off, (void*)&src->typeOffset, sizeof src->typeOffset);
    off += sizeof src->typeOffset;

#ifdef GENERATION_BROADCASTING
    //sub array might not copy, untested
    memcpy(off, (void*)&src->message_generations, sizeof src->message_generations);
    off += sizeof src->message_generations;
    
    memcpy(off, (void*)&src->current_generation, sizeof src->current_generation);
    off += sizeof src->current_generation;
#else 
    memcpy(off, (void*)&src->message_generations, sizeof src->message_generations);
    off += sizeof src->message_generations;    
#endif    
}

void buf2msg(gsw_single_message *dst, unsigned char *src)
{
    unsigned char *off;
    
    off = src;
    
    memcpy((void*)&dst->packetInfo, off, sizeof dst->packetInfo);
    off += sizeof dst->packetInfo;
    
#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    memcpy((void*)&dst->uniquePacketId, off, sizeof dst->uniquePacketId);
    off += sizeof dst->uniquePacketId;
#endif  
    
    memcpy((void*)&dst->udpId, off, sizeof dst->udpId);
    off += sizeof dst->udpId;

    memcpy((void*)&dst->typeOffset, off, sizeof dst->typeOffset);
    off += sizeof dst->typeOffset;
    
#ifdef GENERATION_BROADCASTING
    //sub array might not copy, untested    
    memcpy((void*)&dst->message_generations, off, sizeof dst->message_generations);
    off += sizeof dst->message_generations;
    
    memcpy((void*)&dst->current_generation, off, sizeof dst->current_generation);
    off += sizeof dst->current_generation;
#else 
    memcpy((void*)&dst->message_generations, off, sizeof dst->message_generations);
    off += sizeof dst->message_generations;    
#endif    
}

