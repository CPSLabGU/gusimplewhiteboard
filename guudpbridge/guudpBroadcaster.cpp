/*
 *  guudpBroadcaster.cpp
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */



#include "guudpBroadcaster.h"


#include "guudpUtil.h"
#include "guudpSerialize.h"

static int content_packet_count = 0;
void broadcastLoop(void *broadcaster)
{
        BridgeBroadcaster *c = (BridgeBroadcaster *)broadcaster;
        int sent = 0;
        if(c->sending_count == (get_udp_id()+1)) //is it my turn to send content (robot only)
        {
                //send injections, if space send passive replication (content and hash packets) CAN CAUSE STARVATION
                
                pthread_mutex_lock(c->_injection_mutex);
                while (c->messages_to_inject->size() != 0 && sent < PACKETS_PER_TS_INTERVAL)
                {
                        c->send_injection();
                        sent++;
                }
                pthread_mutex_unlock(c->_injection_mutex);
                

                while (sent < PACKETS_PER_TS_INTERVAL)
                {
                        if(content_packet_count < MESSAGES_TO_SEND_PER_HASH)
                        {
                                content_packet_count++;
                                c->send_content();
                        }
                        else
                        {
                                content_packet_count = 0;
                                if(c->msg_types_to_broadcast->size() > 0)
                                        c->send_hash();
                                else
                                        c->send_content();
                        }
                        sent++;                    
                }
        }
        
        
        if(get_udp_id() < 0) //Not a robot, may still wish to inject messages. This is not controlled at all currently
        {
                pthread_mutex_lock(c->_injection_mutex);
                while (c->messages_to_inject->size() != 0 && sent < PACKETS_PER_TS_INTERVAL)
                {
                        c->send_injection();
                        sent++;
                }
                pthread_mutex_unlock(c->_injection_mutex);                
        }
                
        c->sending_count > NUM_OF_BROADCASTERS ? c->sending_count = 0 : c->sending_count++;
}


void BridgeBroadcaster::send_hash()
{
        gsw_hash_message hashToSend;
        hashToSend.packetInfo = Hash;
        hashToSend.udpId = get_udp_id();
        
        for(int j = 0; j < HASHES_PER_PACKET; j++)
        {
                int currOff = gsw_offset_for_message_type(_wbd_broadcaster, (char *)msg_types_to_broadcast->at(hash_offset).c_str());

                hashToSend.offset[j] = currOff; //Sends the offset in the current wb and the type name, these are inserted directly into the hash table on the target machines. Can definiately cause issues with the hash lookup on the other machine if some of these go missing (NEEDS ATTENTION)

                hashToSend.typeName[j] = _wbd_broadcaster->wb->typenames[currOff];
                
                hash_offset++; //points to the next hash to send in the dynamic type broadcasting vector (msg_types_to_broadcast)
                hash_offset >= (int)msg_types_to_broadcast->size() ? hash_offset = 0 : hash_offset = hash_offset; //offset = offset is only because shorthand if requires an else statement
        }

        hash2buf(&buffer[0], &hashToSend); //serialize
        
        //Broadcast hash packet
        if ((numbytes=sendto(sockfd, buffer, sizeof(buffer), 0,
                             (struct sockaddr *)&mc_addr, sizeof(mc_addr))) == -1) {
                if(errno != 65) //ENETUNREACH - no route to host
                {
                        perror("sendto");
                        exit(1);
                }
        }
}

void BridgeBroadcaster::send_injection()
{
        if(!(messages_to_inject->size() > 0))
                return;
        
        gsw_injection_packet injectionPacket;
        
        injectionPacket.packetInfo = Injection;
        messages_to_inject->size() > INJECTIONS_PER_PACKET ? injectionPacket.numOfInjectionMsgs = INJECTIONS_PER_PACKET : injectionPacket.numOfInjectionMsgs = (int8_t)messages_to_inject->size();
        
        gsw_injection_message msg;
        
        
        for(int j = 0; j < INJECTIONS_PER_PACKET; j++)
        {
                if(messages_to_inject->size() > 0)
                {
                        msg = messages_to_inject->front(); //get msg off fifo injection queue
                        
                        //assign target, type info and content from the msg into the array of msgs contained in the packet to be sent
                        injectionPacket.targetMachineId[j] = msg.machineId;
                        injectionPacket.type[j] = msg.type;
                        injectionPacket.content[j] = msg.m;
                        
                        //remove msg from queue, doesn't need to be atomic, this is the only interaction with the queue other than adding messages to the end, which is done in the WhiteboardLayer
                        messages_to_inject->pop_front();
                }
        }
        
        inj2buf(&buffer[0], &injectionPacket); //serialize (must do this as structs can be stored differently on different OSs and would require some very platform dependant code to fix this issue)
        
        //broadcast injection packet
        if ((numbytes=sendto(sockfd, buffer, sizeof(buffer), 0,
                             (struct sockaddr *)&mc_addr, sizeof(mc_addr))) == -1) {
                if(errno != 65) //ENETUNREACH - no route to host
                {
                        perror("sendto");
                        exit(1);
                }
        }
}

void BridgeBroadcaster::send_content()
{
        //packet to send
        gsw_single_message messageToSend;
        messageToSend.packetInfo = Msg; //packet type info
        messageToSend.udpId = get_udp_id(); //senders id
        
        
        gsw_procure(_wbd_broadcaster->sem, GSW_SEM_PUTMSG); //reading whiteboards need to lock.
        
        for(int j = 0; j < MESSAGES_PER_PACKET; j++)
        {
                if(offset >= GSW_NUM_TYPES_DEFINED && offset <= GSW_NUM_RESERVED)
                {
                        //dynamic messages (not reserved message types)
                        offset = GSW_NUM_RESERVED; //move past the unused reserved types
                }
                if(offset >= GSW_NUM_RESERVED + (int)msg_types_to_broadcast->size())
                {
                        offset = 0;
                }
                int tmpOffset = offset;
                if (offset >= GSW_NUM_RESERVED) {
                        tmpOffset = gsw_offset_for_message_type(_wbd_broadcaster, (char *)msg_types_to_broadcast->at(offset-GSW_NUM_RESERVED).c_str());
                }
                
                messageToSend.typeOffset[j] = tmpOffset; //offset in hash table for content pointer
                messageToSend.current_generation[j] = _wbd_broadcaster->wb->indexes[tmpOffset]; //current generation pointer
#ifdef GENERATION_BROADCASTING
                //Loop and add all generation of a message
                for (int g = 0; g < GU_SIMPLE_WHITEBOARD_GENERATIONS; g++)
                {
                        messageToSend.message_generations[j][g] =  _wbd_broadcaster->wb->messages[tmpOffset][g];
                }
#else
                //just add the current generation of the message
                messageToSend.message_generations[j] =  _wbd_broadcaster->wb->messages[tmpOffset][_wbd_broadcaster->wb->indexes[tmpOffset]];
#endif
                offset++; //move to the next message in the queue
        }
        
        gsw_vacate(_wbd_broadcaster->sem, GSW_SEM_PUTMSG);
        
        msg2buf(&buffer[0], &messageToSend); //serialize
        
        //broadcast msg
        if ((numbytes=sendto(sockfd, buffer, sizeof(buffer), 0,
                             (struct sockaddr *)&mc_addr, sizeof(mc_addr))) == -1) {
                if(errno != 65) //ENETUNREACH - no route to host
                {
                        perror("sendto");
                        exit(1);
                }
        }
}

BridgeBroadcaster::BridgeBroadcaster(gu_simple_whiteboard_descriptor *_wbd, std::vector<std::string> *types, std::list<gsw_injection_message> *injectionVec, pthread_mutex_t *injection_mutex, timeval currTime)
{
    //Default vars
    //----------------------------------------    
    mc_ttl=1;
    uniqueId = 0;
    currently_sending = Hash;
    sent = 0;
    total_sent = 0;
    avgSendTime = 0;
    iter = 0;
    
    padding = 0;
    sending_currently = false;
    sending_count = 1;    
    
    offset = 0;
    hash_offset = 0;
    msg_loops = 0;  
    //----------------------------------------
    
    
    msg_types_to_broadcast = types;
    messages_to_inject = injectionVec;
    _injection_mutex = injection_mutex;
    _wbd_broadcaster = _wbd;

    //Setup socket
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

#ifndef UNICAST
#ifdef USE_BROADCAST
    // this call is what allows broadcast packets to be sent:
    int broadcastOn = 1;    
	if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastOn, sizeof(broadcastOn)) == -1)
    {
		perror("setsockopt (SO_BROADCAST)");
		exit(1);
	}    
#else
	// this call is what allows multicast packets to be sent:
	if (setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_TTL, (void*) &mc_ttl, sizeof(mc_ttl)) == -1)
    {
		perror("setsockopt (MULTICAST_TTL)");
		exit(1);
	}
#endif    

#ifndef USE_BROADCAST
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
#endif


#ifdef USE_BROADCAST    
    /* construct address structure */
    memset(&mc_addr, 0, sizeof(mc_addr));
    mc_addr.sin_family      = PF_INET;
    mc_addr.sin_addr.s_addr = inet_addr(BROADCASTADDRESS);
    mc_addr.sin_port        = htons(SERVERPORT);
    
    memset(buffer, 0, sizeof(buffer));   	
#else
    /* construct address structure */
    memset(&mc_addr, 0, sizeof(mc_addr));
    mc_addr.sin_family      = PF_INET;
    mc_addr.sin_addr.s_addr = inet_addr(MULTICASTADDRESS);
    mc_addr.sin_port        = htons(SERVERPORT);
    
    memset(buffer, 0, sizeof(buffer));
#endif
    

    
    long int min = currTime.tv_sec / 60;
    long int target = min * 60; //removes seconds
    
    int secs = (int)currTime.tv_sec - target;
    
    //Start at next 10s mark
    target += secs+1;//((secs/10)+1)*10;

    
    timespec when;
    when.tv_sec = target;
    when.tv_nsec = 0;

    timespec tmp = when;
//    tmp.tv_nsec += (BROADCASTER_TS*get_udp_id()) * 1000ull;

    broadcast_monitor = CreateDispatchTimer(&tmp,
                                                              (BROADCASTER_TS*1000ull),
                                                              0ull,
                                                              dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                                                              *broadcastLoop, this);    
}

BridgeBroadcaster::~BridgeBroadcaster()
{
    dispatch_source_cancel(broadcast_monitor);
    dispatch_release(broadcast_monitor);
    
    shutdown(sockfd, SHUT_WR);
    close(sockfd);
}
