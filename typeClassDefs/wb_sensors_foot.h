/**                                                                     
 *  /file wb_sensors_foot.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_sensors_foot_h
#define _wb_sensors_foot_h

#include <gu_util.h>

/**
 * Body sensors c struct
 */
struct wb_sensors_foot
{
                PROPERTY(float, LFoot_FSR_FrontLeft)		///< front left force sensor on the left foot
                PROPERTY(float, LFoot_FSR_FrontRight)		///< front right force sensor on the left foot
                PROPERTY(float, LFoot_FSR_RearLeft)		///< rear left force sensor on the left foot
                PROPERTY(float, LFoot_FSR_RearRight)		///< rear right force sensor on the left foot
                PROPERTY(float, LFoot_FSR_CenterOfPressure_X)	///< left foot center of pressure X
                PROPERTY(float, LFoot_FSR_CenterOfPressure_Y)	///< left foot center of pressure Y
                		
                PROPERTY(float, RFoot_FSR_FrontLeft)		///< front left force sensor on the right foot
                PROPERTY(float, RFoot_FSR_FrontRight)		///< front right force sensor on the right foot
                PROPERTY(float, RFoot_FSR_RearLeft)		///< rear left force sensor on the right foot
                PROPERTY(float, RFoot_FSR_RearRight)		///< rear right force sensor on the right foot
                PROPERTY(float, RFoot_FSR_CenterOfPressure_X)	///< right foot center of pressure X 
                PROPERTY(float, RFoot_FSR_CenterOfPressure_Y)	///< right foot center of pressure Y
                
                PROPERTY(bool, LFoot_Bumper_Left)		///< left bumper on the left foot (on / off)
                PROPERTY(bool, LFoot_Bumper_Right)		///< right bumper on the left foot (on / off)
                PROPERTY(bool, RFoot_Bumper_Left)		///< left bumper on the right foot (on / off)
                PROPERTY(bool, RFoot_Bumper_Right)		///< right bumper on the right foot (on / off)
};

#endif //_wb_sensors_foot_h
