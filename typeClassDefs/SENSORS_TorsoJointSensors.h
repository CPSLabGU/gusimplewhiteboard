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
                PROPERTY(float, RShoulderPitch)
                PROPERTY(float, RShoulderRoll)
                PROPERTY(float, RElbowYaw)
                PROPERTY(float, RElbowRoll)
        public:

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /// string constructor (see from_string() below)
                SENSORS_TorsoJointSensors(const std::string &str) { from_string(str); }
                
                void from_string(const std::string &/*str*/)
                {
                        //NYI, Good luck
                }
                
                std::string description() const
                {
                        std::stringstream ss;
                        ss << RAD2DEG(HeadYaw()) << " HY, " << RAD2DEG(HeadPitch()) << " HP, " << RAD2DEG(LShoulderPitch()) << " LSP, " << RAD2DEG(LShoulderRoll()) << " LSR, " << RAD2DEG(LElbowYaw()) << " LEY, " << RAD2DEG(LElbowRoll()) << " LER, " << RAD2DEG(RShoulderPitch()) << " rsp, " << RAD2DEG(RShoulderRoll()) << "rsr, " << RAD2DEG(RElbowYaw()) << " rey, " << RAD2DEG(RElbowRoll());
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //SENSORS_TorsoJointSensors_DEFINED
