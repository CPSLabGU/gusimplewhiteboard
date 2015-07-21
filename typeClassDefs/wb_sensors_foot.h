/**                                                                     
 *  /file wb_sensors_foot.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_sensors_foot_h
#define wb_sensors_foot_h

#include <gu_util.h>

/**
 * Body sensors c struct
 */
struct wb_sensors_foot
{
    /** front left force sensor on the left foot */
    PROPERTY(float, LFoot_FSR_FrontLeft)		

    /** front right force sensor on the left foot */
    PROPERTY(float, LFoot_FSR_FrontRight)		

    /** rear left force sensor on the left foot */
    PROPERTY(float, LFoot_FSR_RearLeft)		

    /** rear right force sensor on the left foot */
    PROPERTY(float, LFoot_FSR_RearRight)		

    /** left foot center of pressure X */
    PROPERTY(float, LFoot_FSR_CenterOfPressure_X)	

    /** left foot center of pressure Y */
    PROPERTY(float, LFoot_FSR_CenterOfPressure_Y)	
                		

    /** front left force sensor on the right foot */
    PROPERTY(float, RFoot_FSR_FrontLeft)		

    /** front right force sensor on the right foot */
    PROPERTY(float, RFoot_FSR_FrontRight)		

    /** rear left force sensor on the right foot */
    PROPERTY(float, RFoot_FSR_RearLeft)		

    /** rear right force sensor on the right foot */
    PROPERTY(float, RFoot_FSR_RearRight)		

    /** right foot center of pressure X  */
    PROPERTY(float, RFoot_FSR_CenterOfPressure_X)	

    /** right foot center of pressure Y */
    PROPERTY(float, RFoot_FSR_CenterOfPressure_Y)	
                

    /** left bumper on the left foot (on / off) */
    PROPERTY(bool, LFoot_Bumper_Left)		

    /** right bumper on the left foot (on / off) */
    PROPERTY(bool, LFoot_Bumper_Right)		

    /** left bumper on the right foot (on / off) */
    PROPERTY(bool, RFoot_Bumper_Left)		

    /** right bumper on the right foot (on / off) */
    PROPERTY(bool, RFoot_Bumper_Right)		
};

#endif //wb_sensors_foot_h
