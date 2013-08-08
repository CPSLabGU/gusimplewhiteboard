/*
 *  udp_config.h
 *  
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
*/

#ifndef udp_config_h
#define udp_config_h

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
#define UDP_STATS

#define READ_TIMEOUT 999999 //usec
#define MESSAGES_IN_READ_BUFFER 10

#define SCHEDULE_FILE "/data/udp_schedule"
#define WARNINGS_FILE "/tmp/guudpwhiteboard.warnings"
#define LOCK_FILE "data/.guudpwhiteboard.lock-"

#define BROADCASTADDRESS "255.255.255.255"
#define PORT 21035	// the port users will be connecting to
#define PORT_STR "21035"

#define MAX_NODES 1024


#define MTU 1459 // - bytes - //1500 WiFi MTU (assumed) - 40 for IP Header & - 1 to keep us under the MTU
#define KBIT_PER_SEC 500
#define BROADCAST_TYPES_COUNT 10 //WORK OUT HOW MANY BROADCAST TYPES EXIST, USE THIS TO WORK OUT CYCLES PER SEC

#define BIT_PER_SEC (KBIT_PER_SEC*1000)
#define BITS_PER_BYTE 8
#define PACKETS_PER_SEC (BIT_PER_SEC/(MTU*BITS_PER_BYTE)) //Relying on int division for the time being.




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




typedef struct gsw_udp_packet_info
{
        /**
         * broadcaster id, used for timing and error checking
         */
        u_int8_t            sender; //could be a smaller bitset or something

        /**
         * number of types in this packet
         */
        u_int8_t            num_of_types;

        /**
         * type offset information
         */
        u_int16_t           *offset;

} gsw_udp_packet_info;

typedef struct gsw_udp_packet
{
        /**
         * broadcaster id, used for timing and error checking
         */
        u_int8_t            schedule_index; //could be a smaller bitset or something

        /**
         * number of types in this packet
         */
        u_int8_t            num_of_types;

        /**
         * type offset information
         */
        u_int16_t           *offset;

        /**
         * event counter
         */
        u_int16_t           *event_counter;

        /**
         * the actual messages stored in the whiteboard
         */
        gu_simple_message   *content;
        
} gsw_udp_packet;


#pragma clang diagnostic pop

#endif //udp_config_h
