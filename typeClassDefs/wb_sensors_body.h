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
    PROPERTY(float, Battery_Charge)         	

    /** unsure, check naoqi docs! check if this is a float or not */
    PROPERTY(float, Battery_Current)        	

    /** unsure, check naoqi docs! Not sure about this type, might only be 1 byte */
    PROPERTY(float, US)                     	


    /** state of the chest button, on / off. could use a 1 bit var here */
    PROPERTY(bool, ChestBoard_Button)       	

    /** padding */
    bool pad1;					

    /** padding */
    int16_t pad2;				
};

#endif //_wb_sensors_body_h
