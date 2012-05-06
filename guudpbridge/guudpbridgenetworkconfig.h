/*
 *  guudpbridgenetworkconfig.h
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
#ifndef guudpbridgenetworkconfig_h
#define guudpbridgenetworkconfig_h

#include <gusimplewhiteboard.h>


/* Network config */
#ifndef DEBUG
#define DEBUG
#endif
#define OUTPUT_LISTENER_IN_DEBUG
//#define OUTPUT_BROADCASTER_IN_DEBUG
//#define RUN_FAST_IN_DEBUG

#define USE_BROADCAST //Defaults to MULTICAST

//FAST SPEED
#define FAST_SPEED_PACKETS_PER_SECOND 1000
#define FAST_CYCLES_PER_SEC 25

//ROBOCUP SPEED
#define ROBOCUP_SPEED_PACKETS_PER_SECOND 44
#define ROBOCUP_CYCLES_PER_SEC 5


#define MESSAGES_IN_READ_BUFFER 10
#define READ_LOOP
//#define IGNORE_TT_ARCH
//#define FAKE_BROADCAST 1 //Uses the id given to pretend to be that robot

#ifndef IGNORE_TT_ARCH
    #define BURST_SEND
#endif
//#define SEND_TO_SELF    
//#define UNICAST

#define NUM_OF_LISTENERS 3 //Does not listen to itself (four total)
#define NUM_OF_BROADCASTERS (NUM_OF_LISTENERS+1)

#define READ_TIMEOUT 300
//#define GENERATION_BROADCASTING

#define MESSAGES_TO_SEND_PER_HASH 3 //3 works well

#define SERVERPORT 4242	// the port users will be connecting to
#define SERVERPORT2 "4242"	// the port users will be connecting to
#define MULTICASTADDRESS "224.42.42.42"	// the multicast address
#define BROADCASTADDRESS "255.255.255.255"

//Might want to look into MTU Path Descovery however for the moment assume MTU of 1500 (-100 for overhead) 1400
#define MTU 1459 //1500 WiFi MTU (assumed) - 40 for IP Header & - 1 to keep us under the MTU
#define REMOTE_WHITEBOARD_BASENAME "guudpwhiteboard"
#define ADD_BROADCAST_TYPE_MSG_TYPE "GSW_AddBroadcastType"
#define INJECTION_TYPE "GSW_InjectMessageOnMachineT"
#define INJECTION_CONTENT "GSW_InjectMessageOnMachineC"




/* Don't change */

//#define DETECT_AND_STOP_UDP_DUPLICATION
//#define DETECTION_BUFFER_SIZE 20000

#ifdef DEBUG
    #ifdef RUN_FAST_IN_DEBUG
        #define PACKETS_PER_SECOND FAST_SPEED_PACKETS_PER_SECOND
        #define CYCLES_PER_SEC FAST_CYCLES_PER_SEC
    #else
        #define PACKETS_PER_SECOND ROBOCUP_SPEED_PACKETS_PER_SECOND
        #define CYCLES_PER_SEC ROBOCUP_CYCLES_PER_SEC
    #endif
    #define PADDING_SLOTS 1
#else
    #define PADDING_SLOTS 0
    #define PACKETS_PER_SECOND ROBOCUP_SPEED_PACKETS_PER_SECOND
    #define CYCLES_PER_SEC ROBOCUP_CYCLES_PER_SEC
#endif

#ifndef IGNORE_TT_ARCH
    #define PACKETS_PER_TS_INTERVAL ((PACKETS_PER_SECOND/(NUM_OF_BROADCASTERS+PADDING_SLOTS))/CYCLES_PER_SEC)
#else
    #define PACKETS_PER_TS_INTERVAL (PACKETS_PER_SECOND/(NUM_OF_BROADCASTERS+PADDING_SLOTS))
#endif


#ifndef DETECT_AND_STOP_UDP_DUPLICATION
    #ifdef GENERATION_BROADCASTING
        #define MESSAGES_PER_PACKET (MTU/(int)(sizeof(gu_simple_message[GU_SIMPLE_WHITEBOARD_GENERATIONS])+sizeof(u_int8_t)+sizeof(u_int8_t)+sizeof(int32_t)+sizeof(int8_t)))
    #else
        #define MESSAGES_PER_PACKET (MTU/(int)(sizeof(gu_simple_message)+sizeof(u_int8_t)+sizeof(int32_t)+sizeof(int8_t)))
    #endif
    #define HASHES_PER_PACKET (MTU/(int)(sizeof(gu_simple_message)+sizeof(int32_t)+sizeof(int8_t)))
#else
    #ifdef GENERATION_BROADCASTING
        #define MESSAGES_PER_PACKET (MTU/(int)(sizeof(gu_simple_message[GU_SIMPLE_WHITEBOARD_GENERATIONS])+sizeof(u_int8_t)+sizeof(u_int8_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int8_t)))
    #else
        #define MESSAGES_PER_PACKET (MTU/(int)(sizeof(gu_simple_message)+sizeof(u_int8_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int8_t)))
    #endif
    #define HASHES_PER_PACKET (MTU/(int)(sizeof(gu_simple_message)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int8_t)))
#endif

#define INJECTIONS_PER_PACKET ((int)((MTU - sizeof(int16_t))/(int)(sizeof(int8_t)+sizeof(gu_simple_message)+(sizeof(gu_simple_message)))))


#define TOTAL_MESSAGE_PACKETS (GSW_TOTAL_MESSAGE_TYPES+MESSAGES_PER_PACKET-1)/MESSAGES_PER_PACKET
#define TOTAL_HASH_PACKETS (GSW_TOTAL_MESSAGE_TYPES+HASHES_PER_PACKET-1)/HASHES_PER_PACKET

#define TS_INTERVAL 1000000 //Micro seconds


//#define PADDING_PER_TS (TS_INTERVAL/(NUM_OF_BROADCASTERS+PADDING_SLOTS))
#define BROADCASTER_TS (TS_INTERVAL/((NUM_OF_BROADCASTERS+PADDING_SLOTS)*CYCLES_PER_SEC))
//#define PADDING_EACH_MSG_TS (PADDING_PER_TS/NUM_OF_BROADCASTERS)

#define MSG_INTERVAL ((TS_INTERVAL)/PACKETS_PER_TS_INTERVAL) //Micro seconds between sending packets
#define MSG_INTERVAL_PER_BROADCAST (MSG_INTERVAL)

//Not used
#define RECV_NETWORK_DELAY 4000 //usec //2ms roughly half ping time




enum PacketType {
    Hash = 0,
    Msg = 1,
    Injection = 2
    };

typedef struct gsw_simple_whiteboard_hash_message
{   
    /**
     * message type, ie. Hash or Message
     */    
    int8_t packetInfo;

#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    /**
     * ID for detecting duplicated packets
     */    
    int32_t uniquePacketId;    
#endif    
    
    /**
     * broadcaster id, used for timing and error checking
     */            
    int8_t udpId;
    
    /**
     * message offset
     */
    int32_t       offset[HASHES_PER_PACKET];

    /**
     * message type pointed to by the hash
     */
    gu_simple_message       typeName[HASHES_PER_PACKET];
    
} gsw_hash_message;

typedef struct gsw_simple_whiteboard_single_message
{
    /**
     * message type, ie. Hash or Message
     */        
    int8_t packetInfo;
    
#ifdef DETECT_AND_STOP_UDP_DUPLICATION
    /**
     * ID for detecting duplicated packets
     */    
    int32_t uniquePacketId;    
#endif    

    /**
     * broadcaster id, used for timing and error checking
     */            
    int8_t udpId;
    
    /**
     * type name offset information
     */    
    int32_t typeOffset[MESSAGES_PER_PACKET];
    
#ifdef GENERATION_BROADCASTING
    /**
     * the actual messages stored in the whiteboard
     */    
    gu_simple_message       message_generations[MESSAGES_PER_PACKET][GU_SIMPLE_WHITEBOARD_GENERATIONS];
    
    /**
     * message generation
     */
    u_int8_t                current_generation[MESSAGES_PER_PACKET];
#else
    /**
     * the actual messages stored in the whiteboard
     */    
    gu_simple_message       message_generations[MESSAGES_PER_PACKET];    
#endif    
    
} gsw_single_message;

typedef struct gsw_simple_whiteboard_injection_packet
{
    /**
     * message type, ie. Hash or Message
     */        
    int8_t packetInfo;
    
    /**
     * num of messages in packet
     */            
    int8_t numOfInjectionMsgs;    

    /**
     * target id, all others ignore
     */            
    int8_t                  targetMachineId[INJECTIONS_PER_PACKET];
    
    /**
     * message type for injection
     */
    gu_simple_message       type[INJECTIONS_PER_PACKET];    
    
    /**
     * message content to be injected
     */
    gu_simple_message       content[INJECTIONS_PER_PACKET];    

} gsw_injection_packet;

class gsw_injection_message {
public:
    u_int8_t machineId;
    gu_simple_message type;
    gu_simple_message m;    //content
};
//}; gsw_remote_injection_message
//{
//    u_int8_t machineId;
//    gu_simple_message type;
//    gu_simple_message m;    //content
//} gsw_injection_message;


#endif //guudpbridgenetworkconfig_h
