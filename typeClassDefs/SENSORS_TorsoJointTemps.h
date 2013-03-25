/**                                                                     
 *  /file SENSORS_TorsoJointTemps.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_TorsoJointTemps_DEFINED
#define SENSORS_TorsoJointTemps_DEFINED

#include <gu_util.h>

namespace guWhiteboard                                                  
{
        class SENSORS_TorsoJointTemps
        {
                PROPERTY(float, HeadYaw);
                PROPERTY(float, HeadPitch);
                PROPERTY(float, LShoulderPitch);
                PROPERTY(float, LShoulderRoll);
                PROPERTY(float, LElbowYaw);
                PROPERTY(float, LElbowRoll);
                PROPERTY(float, LHipYawPitch);
                PROPERTY(float, LHipRoll);
                PROPERTY(float, LHipPitch);
                PROPERTY(float, RHipRoll);
                PROPERTY(float, RHipPitch);
                PROPERTY(float, RShoulderPitch);
                PROPERTY(float, RShoulderRoll);
                PROPERTY(float, RElbowYaw);
                PROPERTY(float, RElbowRoll);
                
        public:
                SENSORS_TorsoJointTemps()
                {

                }
        };
}

#endif //SENSORS_TorsoJointTemps_DEFINED