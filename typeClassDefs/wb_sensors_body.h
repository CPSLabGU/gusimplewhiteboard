/**                                                                     
 *  /file wb_sensors_body.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_sensors_body_h
#define _wb_sensors_body_h

#include <gu_util.h>

/**
 * Body sensors c struct
 */
struct wb_sensors_body
{
    PROPERTY(float, InertialSensor_AccX) 	///< accelerometer X value
    PROPERTY(float, InertialSensor_AccY) 	///< accelerometer Y value
    PROPERTY(float, InertialSensor_AccZ) 	///< accelerometer Z value
    PROPERTY(float, InertialSensor_GyrX)	///< gyro X value
    PROPERTY(float, InertialSensor_GyrY)	///< gyro Y value
    PROPERTY(float, InertialSensor_GyrRef)	///< gyro ref value
    PROPERTY(float, InertialSensor_AngleX)	///< new acc values: AL_Docs 'Theses are direct acceleration values in m.s-2 (one g is approximately 9.81 m.s-2)'
    PROPERTY(float, InertialSensor_AngleY)	///< new acc values: AL_Docs 'Theses are direct acceleration values in m.s-2 (one g is approximately 9.81 m.s-2)'
                
    PROPERTY(float, Battery_Charge)         	///< unsure, check naoqi docs! check if this is a float or not
    PROPERTY(float, Battery_Current)        	///< unsure, check naoqi docs! check if this is a float or not
    PROPERTY(float, US)                     	///< unsure, check naoqi docs! Not sure about this type, might only be 1 byte

    PROPERTY(bool, ChestBoard_Button)       	///< state of the chest button, on / off. could use a 1 bit var here
    bool pad1;					///< padding
    int16_t pad2;				///< padding
};

#endif //_wb_sensors_body_h
