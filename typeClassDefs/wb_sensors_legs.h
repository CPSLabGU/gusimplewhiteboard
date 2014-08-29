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
    /** pitch of the knee joint (left) */
    PROPERTY(float, LKneePitch) 	

    /** pitch of the ankle joint (left) */
    PROPERTY(float, LAnklePitch) 	

    /** roll of the ankle joint (left) */
    PROPERTY(float, LAnkleRoll) 	

    /** pitch of the knee joint (right) */
    PROPERTY(float, RKneePitch) 	

    /** pitch of the ankle joint (right) */
    PROPERTY(float, RAnklePitch) 	

    /** roll of the ankle joint (right) */
    PROPERTY(float, RAnkleRoll) 	

    /** 'yaw/pitch' of the hip. LHipYawPitch and RHipYawPitch are the same on the Nao robots, it is a fused joint with a single motor for control. */
    PROPERTY(float, LHipYawPitch) 	

    /** roll of the hip (left) */
    PROPERTY(float, LHipRoll) 	

    /** pitch of the hip (left) */
    PROPERTY(float, LHipPitch) 	

    /** 'yaw/pitch' of the hip. LHipYawPitch and RHipYawPitch are the same on the Nao robots, it is a fused joint with a single motor for control. */
    PROPERTY(float, RHipYawPitch) 	

    /** roll of the hip (right) */
    PROPERTY(float, RHipRoll) 	

    /** pitch of the hip (right) */
    PROPERTY(float, RHipPitch) 	
};

#endif //_wb_sensors_legs_h
