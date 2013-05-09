/**                                                                     
 *  /file SENSORS_TorsoJointSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_TorsoJointSensors_DEFINED
#define SENSORS_TorsoJointSensors_DEFINED

#define _USE_MATH_DEFINES
#include <gu_util.h>
#include <cmath>


#include <string>
#include <sstream>

namespace guWhiteboard                                                  
{
        class SENSORS_TorsoJointSensors
        {
                PROPERTY(float, HeadYaw)
                PROPERTY(float, HeadPitch)
                PROPERTY(float, LShoulderPitch)
                PROPERTY(float, LShoulderRoll)
                PROPERTY(float, LElbowYaw)
                PROPERTY(float, LElbowRoll)
                PROPERTY(float, LHipYawPitch)
                PROPERTY(float, LHipRoll)
                PROPERTY(float, LHipPitch)
                PROPERTY(float, RHipRoll)
                PROPERTY(float, RHipPitch)
                PROPERTY(float, RShoulderPitch)
                PROPERTY(float, RShoulderRoll)
                PROPERTY(float, RElbowYaw)
                PROPERTY(float, RElbowRoll)
                
        public:
                SENSORS_TorsoJointSensors()
                {

                }
                
                //temp method, testing only, will be removed soon - Carl.
                std::string description()
                {
                        std::stringstream ss;
                    ss << HeadYaw() << ", " << HeadPitch() << ", " << LShoulderPitch() << ", " << LShoulderRoll() << ", " << LElbowYaw() << ", " << LElbowRoll() << ", " << LHipYawPitch() << ", " << LHipRoll() << ", " << LHipPitch() << ", " << RHipRoll() << ", " << RHipPitch() << ", " << RShoulderPitch() << ", " << RShoulderRoll() << ", " << RElbowYaw() << ", " << RElbowRoll();
                    return ss.str();
                }
        };
}

#endif //SENSORS_TorsoJointSensors_DEFINED
