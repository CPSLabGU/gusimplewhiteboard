/*
 *  guudpSerialize.h
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */

#ifndef guudpserialize_h
#define guudpserialize_h

#include <string.h>
#include "guudpConfig.h"

#ifdef __cplusplus
extern "C"
{
#endif

void buf2hash(gsw_hash_message *dst, unsigned char *src);
void hash2buf(unsigned char *dst, gsw_hash_message *src);
void buf2msg(gsw_single_message *dst, unsigned char *src);
void msg2buf(unsigned char *dst, gsw_single_message *src);    
void buf2inj(gsw_injection_packet *dst, unsigned char *src);
void inj2buf(unsigned char *dst, gsw_injection_packet *src);

        
#ifdef __cplusplus
}
#endif
        
        
        
#endif //guudpserialize_h
