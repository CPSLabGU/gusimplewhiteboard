/**                                                                     
 *  /file SENSORS_FootSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_FootSensors_DEFINED
#define SENSORS_FootSensors_DEFINED

#include <gu_util.h>

namespace guWhiteboard                                                  
{
        class SENSORS_FootSensors
        {
                PROPERTY(float, LFoot_FSR_FrontLeft)
                PROPERTY(float, LFoot_FSR_FrontRight)
                PROPERTY(float, LFoot_FSR_RearLeft)
                PROPERTY(float, LFoot_FSR_RearRight)
                PROPERTY(float, LFoot_FSR_CenterOfPressure_X)
                PROPERTY(float, LFoot_FSR_CenterOfPressure_Y)
                
                PROPERTY(float, RFoot_FSR_FrontLeft)
                PROPERTY(float, RFoot_FSR_FrontRight)
                PROPERTY(float, RFoot_FSR_RearLeft)
                PROPERTY(float, RFoot_FSR_RearRight)
                PROPERTY(float, RFoot_FSR_CenterOfPressure_X)
                PROPERTY(float, RFoot_FSR_CenterOfPressure_Y)
                
                PROPERTY(bool, LFoot_Bumper_Left)
                PROPERTY(bool, LFoot_Bumper_Right)
                PROPERTY(bool, RFoot_Bumper_Left)
                PROPERTY(bool, RFoot_Bumper_Right)

        public:
//                SENSORS_FootSensors()
//                {
//
//                }
        };
}

#endif //SENSORS_FootSensors_DEFINED
