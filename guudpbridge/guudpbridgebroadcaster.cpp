/*
** broadcaster.c -- test program, wb remote broadcaster
 BASED ON: http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html#broadcast
*/

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

#include "guudpbridgemanager.h"

gu_simple_whiteboard_descriptor *_wbd_broadcaster;  /// underlying whiteboard
std::vector<std::string> *msg_types_to_broadcast;

int sockfd;
struct sockaddr_in mc_addr; // connector's address information
int numbytes;
unsigned char mc_ttl=1;     /* time to live (hop count) */

#ifdef DEBUG
long long lastStartTime;
#endif

#ifdef DETECT_AND_STOP_UDP_DUPLICATION
int uniqueId = 0;
#else
int uniqueId = 0;
#endif

PacketType currently_sending = Hash;


int sent = 0;
int total_sent = 0;
long long startSendTime;
long long endSendTime;
long long avgSendTime = 0;
int iter = 0;

int padding = 0;
bool sending_currently = false;
int sending_count = 0;

void broadcastMonitor(void *para)
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


int offset = 0;    
int msg_loops = 0;  
unsigned char buffer[MTU];

void broadcastSingleMethod(void *para)
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

int setupbroadcaster(gu_simple_whiteboard_descriptor *_wbd, std::vector<std::string> *types)
{
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
    
	return 0;
}
