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

#include <cstdlib>
#include <string>
#include <sstream>

#include "wb_sensors_torso.h" 

namespace guWhiteboard                                                  
{
        /**
 	* @brief Contains the current joint angles for the robots upper half (designed for Nao)
	*
	* Examples
	* --------
	*
	* Get the pitch angle of the left shoulder in radians
	*
	*     SENSORS_TorsoJointSensors s = SENSORS_TorsoJointSensors_t.get(); //get from the whiteboard
	*     float angle = s.LShoulderPitch(); //pull the variable out of the class
	*
 	*/
        class SENSORS_TorsoJointSensors : public wb_sensors_torso
        {

        public:

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            
#define SEPARATOR_IS_COMMA ','
#define HEAD_YAW_ID 'Y'
#define HEAD_PITCH_ID 'P'
            
                /** string constructor (see from_string() below) 
		 *  @param str a serialised string containing properties to set in this class
		 */
                SENSORS_TorsoJointSensors(const std::string &str) { from_string(str); }
                
                /** parse class properties from a string - Only HEAD YAW and PICH implemented, Good luck 
		 *  @param str a serialised string containing properties to set in this class
		 */
                void from_string(const std::string &str)
                {
                    std::istringstream iss(str);
                    std::string token;
                    if (getline(iss, token, HEAD_YAW_ID))
                    {
                        double theYawVlaue = DEG2RAD( atof(token.c_str()));
                        set_HeadYaw(static_cast<float>(theYawVlaue));
                        
                        std::size_t found = str.find(SEPARATOR_IS_COMMA);
                        if (std::string::npos!=found )
                        { std::string strSecond=str.substr (found+1);
                          std::istringstream iss2(strSecond);
                            if (getline(iss2, token, HEAD_PITCH_ID))
                            {
                                double thePichVlaue = DEG2RAD( atof(token.c_str()));
                                set_HeadPitch(static_cast<float>(thePichVlaue));
                            }
                        }
                    }
                    
                }
                
                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;
                        ss << RAD2DEG(HeadYaw()) <<HEAD_YAW_ID<< SEPARATOR_IS_COMMA  << RAD2DEG(HeadPitch()) << HEAD_PITCH_ID << SEPARATOR_IS_COMMA << RAD2DEG(LShoulderPitch()) << " LSP, " << RAD2DEG(LShoulderRoll()) << " LSR, " << RAD2DEG(LElbowYaw()) << " LEY, " << RAD2DEG(LElbowRoll()) << " LER, " << RAD2DEG(RShoulderPitch()) << " rsp, " << RAD2DEG(RShoulderRoll()) << "rsr, " << RAD2DEG(RElbowYaw()) << " rey, " << RAD2DEG(RElbowRoll());
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //SENSORS_TorsoJointSensors_DEFINED
