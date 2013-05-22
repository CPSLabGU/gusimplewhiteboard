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

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /// string constructor (see from_string() below)
                SENSORS_TorsoJointSensors(const std::string &str) { from_string(str); }
                
                void from_string(const std::string &str)
                {
                        //NYI, Good luck
                }
                
                std::string description() const
                {
                        std::stringstream ss;
                        ss << RAD2DEG(HeadYaw()) << ", " << RAD2DEG(HeadPitch()) << ", " << RAD2DEG(LShoulderPitch()) << ", " << RAD2DEG(LShoulderRoll()) << ", " << RAD2DEG(LElbowYaw()) << ", " << RAD2DEG(LElbowRoll()) << ", " << RAD2DEG(LHipYawPitch()) << ", " << RAD2DEG(LHipRoll()) << ", " << RAD2DEG(LHipPitch()) << ", " << RAD2DEG(RHipRoll()) << ", " << RAD2DEG(RHipPitch()) << ", " << RAD2DEG(RShoulderPitch()) << ", " << RAD2DEG(RShoulderRoll()) << ", " << RAD2DEG(RElbowYaw()) << ", " << RAD2DEG(RElbowRoll());
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
                
        };
}

#endif //SENSORS_TorsoJointSensors_DEFINED
