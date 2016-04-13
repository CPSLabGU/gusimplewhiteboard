/** 
 * file wb_sensors_legjointtemps.c 
 * 
 * This file was generated by classgenerator from SENSORS_LegJointTemps.txt. 
 * DO NOT CHANGE MANUALLY! 
 * 
 * Created by Carl Lusty at 14:50, 13/4/2016 
 * Copyright (c) 2016 Carl Lusty 
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
 *    This product includes software developed by Carl Lusty. 
 * 
 * 4. Neither the name of the author nor the names of contributors 
 *    may be used to endorse or promote products derived from this 
 *    software without specific prior written permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * 'AS IS' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
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
 */ 


#include "wb_sensors_legjointtemps.h" 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

/** convert to a description string */  
const char* wb_sensors_legjointtemps_description(const struct wb_sensors_legjointtemps* self, char* descString, size_t bufferSize) 
{ 
    size_t len; 

    snprintf(descString+len, bufferSize-len, "LKneePitch =%f", self->LKneePitch ); 
    len = gu_strlcat(descString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(descString+len, bufferSize-len, "LAnklePitch=%f", self->LAnklePitch); 
    } 

    len = gu_strlcat(descString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(descString+len, bufferSize-len, "LAnkleRoll=%f", self->LAnkleRoll); 
    } 

    len = gu_strlcat(descString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(descString+len, bufferSize-len, "RKneePitch=%f", self->RKneePitch); 
    } 

    len = gu_strlcat(descString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(descString+len, bufferSize-len, "RAnklePitch=%f", self->RAnklePitch); 
    } 

    len = gu_strlcat(descString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(descString+len, bufferSize-len, "RAnkleRoll=%f", self->RAnkleRoll); 
    } 

	return descString; 
} 

/** convert to a string */  
const char* wb_sensors_legjointtemps_to_string(const struct wb_sensors_legjointtemps* self, char* toString, size_t bufferSize) 
{ 
    size_t len; 

    snprintf(toString+len, bufferSize-len, "%f", self->LKneePitch ); 
    len = gu_strlcat(toString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(toString+len, bufferSize-len, "%f", self->LAnklePitch); 
    } 

     len = gu_strlcat(toString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(toString+len, bufferSize-len, "%f", self->LAnkleRoll); 
    } 

     len = gu_strlcat(toString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(toString+len, bufferSize-len, "%f", self->RKneePitch); 
    } 

     len = gu_strlcat(toString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(toString+len, bufferSize-len, "%f", self->RAnklePitch); 
    } 

     len = gu_strlcat(toString, ", ", bufferSize); 

    if (len < bufferSize) 
    { 
        snprintf(toString+len, bufferSize-len, "%f", self->RAnkleRoll); 
    } 

     return toString; 
} 

/** convert from a string */  
struct wb_sensors_legjointtemps* wb_sensors_legjointtemps_from_string(struct wb_sensors_legjointtemps* self, const char* str) 
{ 
    char* strings[SENSORS_LEGJOINTTEMPS_NUMBER_OF_VARIABLES]; 
    memset(strings, 0, sizeof(strings)); 
    char* saveptr; 
    int count = 0; 

    char* str_copy = gu_strdup(str); 

    const char s[2] = ",";   /// delimeter 
    const char e = '=';      /// delimeter 
    char* tokenS, *tokenE; 

    tokenS = strtok_r(str_copy, s, &saveptr); 

    while (tokenS != NULL) 
    { 
        tokenE = strchr(tokenS, e); 

        if (tokenE == NULL) 
        { 
             tokenE = tokenS; 
        } 
        else 
        { 
             tokenE++; 
        } 

        strings[count] = gu_strtrim(tokenE); 

        count++; 
        tokenS = strtok_r(NULL, s, &saveptr); 
    } 

    if (strings[0] != NULL) 
       self->LKneePitch  = (float)atof(strings[0]); 

    if (strings[1] != NULL) 
       self->LAnklePitch = (float)atof(strings[1]); 

    if (strings[2] != NULL) 
       self->LAnkleRoll = (float)atof(strings[2]); 

    if (strings[3] != NULL) 
       self->RKneePitch = (float)atof(strings[3]); 

    if (strings[4] != NULL) 
       self->RAnklePitch = (float)atof(strings[4]); 

    if (strings[5] != NULL) 
       self->RAnkleRoll = (float)atof(strings[5]); 

    free(str_copy); 

    return self; 
}; 
