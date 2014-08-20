/**                                                                     
 *  /file wb_sensors_legs.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_sensors_legs_h
#define _wb_sensors_legs_h

#include <gu_util.h>

/**
 * joint sensors c struct
 */
struct wb_sensors_legs
{
                PROPERTY(float, LKneePitch) 	///< pitch of the knee joint (left)
                PROPERTY(float, LAnklePitch) 	///< pitch of the ankle joint (left)
                PROPERTY(float, LAnkleRoll) 	///< roll of the ankle joint (left)
                PROPERTY(float, RKneePitch) 	///< pitch of the knee joint (right)
                PROPERTY(float, RAnklePitch) 	///< pitch of the ankle joint (right)
                PROPERTY(float, RAnkleRoll) 	///< roll of the ankle joint (right)
                PROPERTY(float, LHipYawPitch) 	///< 'yaw/pitch' of the hip. LHipYawPitch and RHipYawPitch are the same on the Nao robots, it is a fused joint with a single motor for control.
                PROPERTY(float, LHipRoll) 	///< roll of the hip (left)
                PROPERTY(float, LHipPitch) 	///< pitch of the hip (left)
                PROPERTY(float, RHipYawPitch) 	///< 'yaw/pitch' of the hip. LHipYawPitch and RHipYawPitch are the same on the Nao robots, it is a fused joint with a single motor for control.
                PROPERTY(float, RHipRoll) 	///< roll of the hip (right)
                PROPERTY(float, RHipPitch) 	///< pitch of the hip (right)
};

#endif //_wb_sensors_legs_h
