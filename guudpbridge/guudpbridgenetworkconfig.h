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

//#define DEBUG
//#define UNICAST
//#define MULTICASTADDRESS "192.168.0.194"	// the multicast address
#define READ_LOOP
//#define IGNORE_TT_ARCH

#ifndef IGNORE_TT_ARCH
    #define BURST_SEND
#endif
//#define SEND_TO_SELF    

#define NUM_OF_LISTENERS 3 //Does not listen to itself (four total)
#define NUM_OF_BROADCASTERS (NUM_OF_LISTENERS+1)

#define READ_TIMEOUT 300
//#define GENERATION_BROADCASTING
#define PACKETS_PER_SECOND 44//44 //Robocup limit

#ifndef IGNORE_TT_ARCH
    #define PACKETS_PER_TS_INTERVAL PACKETS_PER_SECOND
#else
    #define PACKETS_PER_TS_INTERVAL (PACKETS_PER_SECOND/NUM_OF_BROADCASTERS)
#endif

#define MESSAGES_TO_SEND_PER_HASH 3 //3 works well

#define SERVERPORT 4242	// the port users will be connecting to
#define SERVERPORT2 "4242"	// the port users will be connecting to
#define MULTICASTADDRESS "224.42.42.42"	// the multicast address

//Might want to look into MTU Path Descovery however for the moment assume MTU of 1500 (-100 for overhead) 1400
#define MTU 1400
#define REMOTE_WHITEBOARD_BASENAME "guudpwhiteboard"


/* Don't change */

//#define DETECT_AND_STOP_UDP_DUPLICATION
//#define DETECTION_BUFFER_SIZE 20000


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

#define TOTAL_MESSAGE_PACKETS (GSW_TOTAL_MESSAGE_TYPES+MESSAGES_PER_PACKET-1)/MESSAGES_PER_PACKET
#define TOTAL_HASH_PACKETS (GSW_TOTAL_MESSAGE_TYPES+HASHES_PER_PACKET-1)/HASHES_PER_PACKET

#define TS_INTERVAL 1000000 //Micro seconds

#define PADDING_SLOTS 0
//#define PADDING_PER_TS (TS_INTERVAL/(NUM_OF_BROADCASTERS+PADDING_SLOTS))
#define BROADCASTER_TS (TS_INTERVAL/(NUM_OF_BROADCASTERS+PADDING_SLOTS))
//#define PADDING_EACH_MSG_TS (PADDING_PER_TS/NUM_OF_BROADCASTERS)

#define MSG_INTERVAL ((TS_INTERVAL)/PACKETS_PER_TS_INTERVAL) //Micro seconds between sending packets
#define MSG_INTERVAL_PER_BROADCAST (MSG_INTERVAL)

//Not used
#define RECV_NETWORK_DELAY 4000 //usec //2ms roughly half ping time




enum PacketType {
    Hash = 0,
    Msg = 1,
    Dummy = 2
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



#endif //guudpbridgenetworkconfig_h