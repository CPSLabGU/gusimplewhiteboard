/** 
 * file wb_sensors_legjointtemps.h 
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


#ifndef wb_sensors_legjointtemps_h 
#define wb_sensors_legjointtemps_h 

#include "gu_util.h" 

#define SENSORS_LEGJOINTTEMPS_NUMBER_OF_VARIABLES 6 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION 
#define SENSORS_LEGJOINTTEMPS_DESC_BUFFER_SIZE 464 
#define SENSORS_LEGJOINTTEMPS_TO_STRING_BUFFER_SIZE 395 
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION 


/** 
 * @brief leg temps 
 *      
 */ 
struct wb_sensors_legjointtemps 
{ 
    /** left knee pitch temp  */ 
    PROPERTY(float, LKneePitch ) 

    /** left ankle pitch temp  */ 
    PROPERTY(float, LAnklePitch) 

    /** left ankle roll temp  */ 
    PROPERTY(float, LAnkleRoll) 

    /** right knee pitch temp  */ 
    PROPERTY(float, RKneePitch) 

    /** right ankle pitch temp  */ 
    PROPERTY(float, RAnklePitch) 

    /** right ankle roll temp  */ 
    PROPERTY(float, RAnkleRoll) 

}; 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION 
/** convert to a description string */  
const char* wb_sensors_legjointtemps_description(const struct wb_sensors_legjointtemps* self, char* descString, size_t bufferSize); 

/** convert to a string */  
const char* wb_sensors_legjointtemps_to_string(const struct wb_sensors_legjointtemps* self, char* toString, size_t bufferSize); 

/** convert from a string */  
struct wb_sensors_legjointtemps* wb_sensors_legjointtemps_from_string(struct wb_sensors_legjointtemps* self, const char* str); 
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION 

#endif /// wb_sensors_legjointtemps_h 
