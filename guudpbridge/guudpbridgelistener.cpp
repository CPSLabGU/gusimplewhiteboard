/*
** listener.c -- a datagram sockets "server" demo
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

#include "guudpbridgemanager.h"

gu_simple_whiteboard_descriptor *_wbd_listeners[NUM_OF_BROADCASTERS];  /// underlying whiteboard
int current_poster = 0;

int sock;                     /* socket descriptor */
int flag_on = 1;              /* socket option flag */
char recv_data[sizeof(gsw_single_message)];     /* buffer to receive message packet */
char recv_hash[sizeof(gsw_single_message)];       /* buffer to receive hash packet */
int recv_len;                 /* length of data received */



#ifdef DEBUG    
int gotHashPackets = 0; //Num of hash gotten
int gotMessagePackets = 0; //Num of msg gotten
int lostPackets = 0; //Num of packets missed
int total_recv = 0;

long long startRecvTime;
long long endRecvTime;
long long avgRecvTime = 0;
int iter_listener = 0;
long long rawRecvTime = 0;

//TEMP
int oldId = -1;

#ifdef DETECT_AND_STOP_UDP_DUPLICATION
bool packetsAlreadyGotten[DETECTION_BUFFER_SIZE];
#endif

void listenMonitor(void *para)
{
    if(iter_listener > 0)
        fprintf(stderr, "got: %d  \tlost: %d  \ttotal got: %d\thash: %d  \tmsg: %d  \tavg read %llu\traw %llu\n\n", gotHashPackets+gotMessagePackets, lostPackets, total_recv, gotHashPackets*HASHES_PER_PACKET, gotMessagePackets*MESSAGES_PER_PACKET, (avgRecvTime/iter_listener), rawRecvTime);
    gotHashPackets = 0;
    lostPackets = 0;
    gotMessagePackets = 0;
    
    return;
   
}
#endif

//Would rather make this global to avoid malloc calls, only work without timers. ie. Loop read.    
char recv_buffer[MTU];

void listenSingleMethod(void *para)
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
            fprintf(stderr, "Socket Error\n");
            return;
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
#ifdef DEBUG            
                gotMessagePackets++;
                total_recv++;            
#endif
                gsw_single_message msg;   
                buf2msg(&msg, (unsigned char *)&recv_buffer[0]);
                
                current_poster = msg.udpId;
                
                for(int i = 0; i < MESSAGES_PER_PACKET; i++)
                {
                    //Don't need sem, this is the only writer and readers don't need the sem either
                    int t = msg.typeOffset[i];
#ifdef GENERATION_BROADCASTING                    
                    _wbd_listeners[current_poster]->wb->indexes[t] = msg.current_generation[i];
                    
                    for (int g = 0; g < GU_SIMPLE_WHITEBOARD_GENERATIONS; g++)
                    {
                        _wbd_listeners[current_poster]->wb->messages[t][g] = msg.message_generations[i][g];
                    }
#else
                    u_int8_t j = _wbd_listeners[current_poster]->wb->indexes[t];
                    if (++j >= GU_SIMPLE_WHITEBOARD_GENERATIONS) j = 0;
                    _wbd_listeners[current_poster]->wb->messages[t][j] = msg.message_generations[i];
                    gsw_increment(_wbd_listeners[current_poster]->wb, t);
#endif
                }
            }
            else if(recv_buffer[0] == Hash)
            {
#ifdef DEBUG            
                gotHashPackets++;
                total_recv++;
#endif
                gsw_hash_message hashToRecv;   
                buf2hash(&hashToRecv, (unsigned char *)&recv_buffer[0]);
                
                current_poster = hashToRecv.udpId;
                
                for(int j = 0; j < HASHES_PER_PACKET; j++)
                {
                    gsw_register_message_type(_wbd_listeners[current_poster], hashToRecv.typeName[j].hash.string, hashToRecv.offset[j]);
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

void set_nonblock(int socket)
{
    int flags;
    flags = fcntl(socket,F_GETFL,0);
    fcntl(socket, F_SETFL, flags | O_NONBLOCK);
} 

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int setuplistener(gu_simple_whiteboard_descriptor *_wbd[NUM_OF_BROADCASTERS])
{
    for (int i = 0; i < NUM_OF_BROADCASTERS; i++) {
        _wbd_listeners[i] = _wbd[i];
    }


    struct sockaddr_in mc_addr;   /* socket address structure */
    struct ip_mreq mc_req;        /* multicast request structure */
    char* mc_addr_str;            /* multicast IP address */
    unsigned short mc_port;       /* multicast port */
    struct sockaddr_in from_addr; /* packet source */
    unsigned int from_len;        /* source addr length */

    
    
    mc_addr_str = (char *)MULTICASTADDRESS;     /* assign multicast ip address */
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
    int buffsize = MTU+100;    
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
        exit(1);
    }
    
    /* construct an IGMP join request structure */
    mc_req.imr_multiaddr.s_addr = inet_addr(mc_addr_str);
    mc_req.imr_interface.s_addr = htonl(INADDR_ANY);
    
#ifndef UNICAST
    /* send an ADD MEMBERSHIP message via setsockopt */
    if ((setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, 
                    (void*) &mc_req, sizeof(mc_req))) < 0) {
        perror("setsockopt() failed");
        exit(1);
    }
#endif
    
    /* clear the receive buffers & structs */
    memset(recv_hash, 0, sizeof(recv_hash));
    memset(recv_data, 0, sizeof(recv_data));
    
    from_len = sizeof(from_addr);
    memset(&from_addr, 0, from_len);
    
    
    /* send a DROP MEMBERSHIP message via setsockopt */
//    if ((setsockopt(sock, IPPROTO_IP, IP_DROP_MEMBERSHIP, 
//                    (void*) &mc_req, sizeof(mc_req))) < 0) {
//        perror("setsockopt() failed");
//        exit(1);
//    }
//    
//    close(sock);  

	return 0;
}
