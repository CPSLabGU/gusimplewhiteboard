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


#define JOINT_DEG_GETTER(t, n) public: t n##_degrees () { return (_##n * (180/M_PI)) ; }
#define JOINT_PROPERTY(type, name) PROPERTY_DECLARATION(type,name); PROPERTY_GETTER(type,name) JOINT_DEG_GETTER(type,name) PROPERTY_SETTER(type,name)


#include <string>
#include <sstream>

namespace guWhiteboard                                                  
{
        class SENSORS_TorsoJointSensors
        {
                JOINT_PROPERTY(float, HeadYaw);
                JOINT_PROPERTY(float, HeadPitch);
                JOINT_PROPERTY(float, LShoulderPitch);
                JOINT_PROPERTY(float, LShoulderRoll);
                JOINT_PROPERTY(float, LElbowYaw);
                JOINT_PROPERTY(float, LElbowRoll);
                JOINT_PROPERTY(float, LHipYawPitch);
                JOINT_PROPERTY(float, LHipRoll);
                JOINT_PROPERTY(float, LHipPitch);
                JOINT_PROPERTY(float, RHipRoll);
                JOINT_PROPERTY(float, RHipPitch);
                JOINT_PROPERTY(float, RShoulderPitch);
                JOINT_PROPERTY(float, RShoulderRoll);
                JOINT_PROPERTY(float, RElbowYaw);
                JOINT_PROPERTY(float, RElbowRoll);
                
        public:
                SENSORS_TorsoJointSensors()
                {

                }
                
                //temp method, testing only, will be removed soon - Carl.
                std::string description()
                {
                        std::stringstream ss;
                        ss << HeadYaw_degrees() << ", " << HeadPitch_degrees() << ", " << LShoulderPitch_degrees() << ", " << LShoulderRoll_degrees() << ", " << LElbowYaw_degrees() << ", " << LElbowRoll_degrees() << ", " << LHipYawPitch_degrees() << ", " << LHipRoll_degrees() << ", " << LHipPitch_degrees() << ", " << RHipRoll_degrees() << ", " << RHipPitch_degrees() << ", " << RShoulderPitch_degrees() << ", " << RShoulderRoll_degrees() << ", " << RElbowYaw_degrees() << ", " << RElbowRoll_degrees();
                        return ss.str();
                }
        };
}

#endif //SENSORS_TorsoJointSensors_DEFINED
