/*
 *  guudpSerialize.c
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */

#include "guudpSerialize.h"


void hash2buf(unsigned char *dst, gsw_hash_message *src)
{
    unsigned char *off;
    
    off = dst;
    
    memcpy(off, (void*)&src->packetInfo, sizeof src->packetInfo);
    off += sizeof src->packetInfo;
    
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
    
    memcpy(off, (void*)&src->udpId, sizeof src->udpId);
    off += sizeof src->udpId;
    
    memcpy(off, (void*)&src->typeOffset, sizeof src->typeOffset);
    off += sizeof src->typeOffset;
    
    memcpy(off, (void*)&src->current_generation, sizeof src->current_generation);
    off += sizeof src->current_generation;    
    
#ifdef GENERATION_BROADCASTING
    //sub array might not copy, untested
    memcpy(off, (void*)&src->message_generations, sizeof src->message_generations);
    off += sizeof src->message_generations;
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
    
    memcpy((void*)&dst->udpId, off, sizeof dst->udpId);
    off += sizeof dst->udpId;
    
    memcpy((void*)&dst->typeOffset, off, sizeof dst->typeOffset);
    off += sizeof dst->typeOffset;
    
    memcpy((void*)&dst->current_generation, off, sizeof dst->current_generation);
    off += sizeof dst->current_generation;
    
#ifdef GENERATION_BROADCASTING
    //sub array might not copy, untested    
    memcpy((void*)&dst->message_generations, off, sizeof dst->message_generations);
    off += sizeof dst->message_generations;
#else 
    memcpy((void*)&dst->message_generations, off, sizeof dst->message_generations);
    off += sizeof dst->message_generations;    
#endif    
}

void buf2inj(gsw_injection_packet *dst, unsigned char *src)
{
    unsigned char *off;
    
    off = src;
    
    memcpy((void*)&dst->packetInfo, off, sizeof dst->packetInfo);
    off += sizeof dst->packetInfo;
    
    memcpy((void*)&dst->numOfInjectionMsgs, off, sizeof dst->numOfInjectionMsgs);
    off += sizeof dst->numOfInjectionMsgs;
    
    memcpy((void*)&dst->targetMachineId, off, sizeof dst->targetMachineId);
    off += sizeof dst->targetMachineId;    
    
    memcpy((void*)&dst->type, off, sizeof dst->type);
    off += sizeof dst->type;    
    
    memcpy((void*)&dst->content, off, sizeof dst->content);
    off += sizeof dst->content;        
}

void inj2buf(unsigned char *dst, gsw_injection_packet *src)
{
    unsigned char *off;
    
    off = dst;
    
    memcpy(off, (void*)&src->packetInfo, sizeof src->packetInfo);
    off += sizeof src->packetInfo;

    memcpy(off, (void*)&src->numOfInjectionMsgs, sizeof src->numOfInjectionMsgs);
    off += sizeof src->numOfInjectionMsgs;
    
    memcpy(off, (void*)&src->targetMachineId, sizeof src->targetMachineId);
    off += sizeof src->targetMachineId;
    
    memcpy(off, (void*)&src->type, sizeof src->type);
    off += sizeof src->type;
    
    memcpy(off, (void*)&src->content, sizeof src->content);
    off += sizeof src->content;    
}
