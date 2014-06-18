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
#include <cmath>


#include <string>
#include <sstream>

#include "wb_sensors_torso.h" 

namespace guWhiteboard                                                  
{
        class SENSORS_TorsoJointSensors : public wb_sensors_torso
        {

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
