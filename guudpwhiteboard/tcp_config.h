/*
 *  tcp_config.h
 *  
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
*/

#ifndef tcp_config_h
#define tcp_config_h

#include <gusimplewhiteboard.h>


#ifdef bool
#undef bool
#endif

#ifdef true
#undef true
#undef false
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"


/* Network config */
#define TCP_STATS

//#define READ_TIMEOUT 999999 //usec
//#define MESSAGES_IN_READ_BUFFER 10

#define ALLOW_TCP_FILE "/data/.send_tcp.true"

#define TCP_PORT 21045	// the port users will be connecting to
#define TCP_PORT_STR "21045"

#define BUF_SIZE GU_SIMPLE_WHITEBOARD_BUFSIZE+sizeof(uint16_t) //68 bytes




//#define MTU 1459 // - bytes - //1500 WiFi MTU (assumed) - 40 for IP Header & - 1 to keep us under the MTU
//#define KBIT_PER_SEC 500
//#define BROADCAST_TYPES_COUNT 10 //WORK OUT HOW MANY BROADCAST TYPES EXIST, USE THIS TO WORK OUT CYCLES PER SEC

//#define BIT_PER_SEC (KBIT_PER_SEC*1000)
//#define BITS_PER_BYTE 8
//#define PACKETS_PER_SEC (BIT_PER_SEC/(MTU*BITS_PER_BYTE)) //Relying on int division for the time being.




//#define ROBOTS 5
//#define LISTENERS (ROBOTS-1) //Does not listen to itself (four total)
//#define BROADCASTERS ROBOTS


//MTU = 1459, GU_SIMPLE_WHITEBOARD_BUFSIZE 64 == 22.796875 ----- ** .796875 packet data not used
//#define MAX_TYPES_PER_PACKET (MTU/GU_SIMPLE_WHITEBOARD_BUFSIZE) //Relying on int division for the time being. ** NOT including packet HEAD **

//schedule_index + num_of_types + type_offset[MAX_TYPES_PER_PACKET] + event_counter[MAX_TYPES_PER_PACKET]
//#define PACKET_HEAD (sizeof(int8_t) + sizeof(int8_t) + (sizeof(int16_t)*MAX_TYPES_PER_PACKET) + (sizeof(int8_t)*MAX_TYPES_PER_PACKET))
//#define REAL_TYPES_PER_PACKET ((MTU-PACKET_HEAD)/GU_SIMPLE_WHITEBOARD_BUFSIZE) //Relying on int division for the time being. ** INCLUDING packet HEAD **

//#define TYPES_PER_SEC (PACKETS_PER_SEC*REAL_TYPES_PER_PACKET)
//#define TYPES_PER_SEC_PER_ROBOT (TYPES_PER_SEC/BROADCASTERS)

//Just printed for statistics
//#define BROADCAST_HERTZ ((TYPES_PER_SEC_PER_ROBOT/BROADCAST_TYPES_COUNT)+(TYPES_PER_SEC_PER_ROBOT%BROADCAST_TYPES_COUNT)) //stupid int division, using mod to append the remainder
//#define REAL_BROADCAST_HERTZ (TYPES_PER_SEC_PER_ROBOT/BROADCAST_TYPES_COUNT)



typedef struct gsw_message_packet
{
        gsw_message_packet(uint16_t type, gsw_simple_message *message) : m(*message), t(type) { }
        gsw_message_packet() : m(), t() { }

        gsw_simple_message m;
        uint16_t t;
} gsw_message_packet;



#pragma clang diagnostic pop

#endif //tcp_config_h
