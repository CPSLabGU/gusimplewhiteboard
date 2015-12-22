/** 
 * file wb_sensors_bodysensors.h 
 * 
 * This file was generated by classgenerator from SENSORS_BodySensors.txt. 
 * DO NOT CHANGE MANUALLY! 
 * 
 * Created by Carl Lusty at 16:25, 22/12/2015 
 * Copyright (c) 2015 Carl Lusty 
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


#ifndef wb_sensors_bodysensors_h 
#define wb_sensors_bodysensors_h 

#include "gu_util.h" 

#define SENSORS_BODYSENSORS_NUMBER_OF_VARIABLES 14 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION 
#define SENSORS_BODYSENSORS_DESC_BUFFER_SIZE 1018 
#define SENSORS_BODYSENSORS_TO_STRING_BUFFER_SIZE 747 
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION 


/** 
 * @brief Contains the current values of sensors located in the robots chest (designed for Nao) 
 * Examples 
 * -------- 
 * Get the state of the Chest Button 
 *     SENSORS_BodySensors s = SENSORS_BodySensors_t.get(); //get from the whiteboard 
 *     bool button_state = s.ChestBoard_Button(); //pull the variable out of the class 
 */ 
struct wb_sensors_bodysensors 
{ 
    /** accelerometer X value */ 
    PROPERTY(float, InertialSensor_AccX) 

    /** accelerometer Y value */ 
    PROPERTY(float, InertialSensor_AccY) 

    /** accelerometer Z value */ 
    PROPERTY(float, InertialSensor_AccZ) 

    /** gyro X value */ 
    PROPERTY(float, InertialSensor_GyrX) 

    /** gyro Y value */ 
    PROPERTY(float, InertialSensor_GyrY) 

    /** gyro ref value */ 
    PROPERTY(float, InertialSensor_GyrRef) 

    /** new acc values: AL_Docs 'Theses are direct acceleration values in m.s-2 (one g is approximately 9.81 m.s-2)' */ 
    PROPERTY(float, InertialSensor_AngleX) 

    /** new acc values: AL_Docs 'Theses are direct acceleration values in m.s-2 (one g is approximately 9.81 m.s-2)' */ 
    PROPERTY(float, InertialSensor_AngleY) 

    /** unsure, check naoqi docs! check if this is a float or not */ 
    PROPERTY(float, Battery_Charge        ) 

    /** unsure, check naoqi docs! check if this is a float or not */ 
    PROPERTY(float, Battery_Current       ) 

    /** unsure, check naoqi docs! Not sure about this type, might only be 1 byte */ 
    PROPERTY(float, US                    ) 

    /** state of the chest button, on / off. could use a 1 bit var here */ 
    PROPERTY(bool, ChestBoard_Button      ) 

    /** padding */ 
    PROPERTY(bool, pad1;) 

    /** padding */ 
    PROPERTY(int16_t, pad2;) 

}; 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION 
/** convert to a description string */  
const char* wb_sensors_bodysensors_description(const struct wb_sensors_bodysensors* self, char* descString, size_t bufferSize); 

/** convert to a string */  
const char* wb_sensors_bodysensors_to_string(const struct wb_sensors_bodysensors* self, char* toString, size_t bufferSize); 

/** convert from a string */  
struct wb_sensors_bodysensors* wb_sensors_bodysensors_from_string(struct wb_sensors_bodysensors* self, const char* str); 
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION 

#endif /// wb_sensors_bodysensors_h 
