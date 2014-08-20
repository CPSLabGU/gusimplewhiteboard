/**                                                                     
 *  /file wb_sensors_torso.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_sensors_torso_h
#define _wb_sensors_torso_h

#include <gu_util.h>

/**
 * Body joint positions c struct
 */
struct wb_sensors_torso
{
                PROPERTY(float, HeadYaw)  	///< Head pos in RAD
                PROPERTY(float, HeadPitch)  	///< Head pos in RAD
                PROPERTY(float, LShoulderPitch)	///< RAD
                PROPERTY(float, LShoulderRoll)	///< RAD
                PROPERTY(float, LElbowYaw)	///< RAD
                PROPERTY(float, LElbowRoll)	///< RAD
                PROPERTY(float, RShoulderPitch)	///< RAD
                PROPERTY(float, RShoulderRoll)	///< RAD
                PROPERTY(float, RElbowYaw)	///< RAD
                PROPERTY(float, RElbowRoll)	///< RAD
};

#endif //_wb_sensors_torso_h
