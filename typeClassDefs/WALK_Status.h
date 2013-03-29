/**                                                                     
 *  /file SENSORS_TorsoJointSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_TorsoJointSensors_DEFINED
#define SENSORS_TorsoJointSensors_DEFINED

#include <gu_util.h>
#include <string>
#include <sstream>

namespace guWhiteboard                                                  
{
        class SENSORS_TorsoJointSensors
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
                SENSORS_TorsoJointSensors()
                {

                }
                
                std::string description()
                {
                        std::stringstream ss;
                        ss << _HeadYaw << ", " << _HeadPitch << ", " << _LShoulderPitch << ", " << _LShoulderRoll << ", " << _LElbowYaw << ", " << _LElbowRoll << ", " << _LHipYawPitch << ", " << _LHipRoll << ", " << _LHipPitch << ", " << _RHipRoll << ", " << _RHipPitch << ", " << _RShoulderPitch << ", " << _RShoulderRoll << ", " << _RElbowYaw << ", " << _RElbowRoll;
                        return ss.str();
                }
        };
}

#endif //SENSORS_TorsoJointSensors_DEFINED