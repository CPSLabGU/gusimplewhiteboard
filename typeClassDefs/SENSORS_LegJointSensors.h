/**                                                                     
 *  /file SENSORS_LegJointSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_LegJointSensors_DEFINED
#define SENSORS_LegJointSensors_DEFINED

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>

#include "wb_sensors_legs.h" 

namespace guWhiteboard
{
        /**
 	* @brief Contains the current joint angles for the robots lower half (designed for Nao)
	*
	* Examples
	* --------
	*
	* Get the pitch angle of the left knee in radians
	*
	*     SENSORS_LegJointSensors s = SENSORS_LegJointSensors_t.get(); //get from the whiteboard
	*     float knee = s.LKneePitch(); //pull the variable out of the class
	*
 	*/
         class SENSORS_LegJointSensors : public wb_sensors_legs
        {

        public:

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below) - NYI
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
                SENSORS_LegJointSensors(const std::string &str) { from_string(str); }

                /** parse class properties from a string - NYI 
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
                void from_string(const std::string &str)
                {
			fprintf(stderr, "NYI - Have it back: %s\n", const_cast<char *>(str.c_str()));
                }

                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;
                        ss << LKneePitch() << " LK, " << LAnklePitch() << " AP, " << LAnkleRoll() << " AR, " << RKneePitch() << " rk, " << RAnklePitch() << " ap, " << RAnkleRoll() << " ar, " << LHipYawPitch() << " LHY, " << LHipRoll() << " LHR, " << LHipPitch() << " LHP, " << RHipYawPitch() << " rhy, " << RHipRoll() << " rhr, " << RHipPitch() << "rhp";
//                        ss << RAD2DEG(LKneePitch()) << " LK, " << RAD2DEG(LAnklePitch()) << " AP, " << RAD2DEG(LAnkleRoll()) << " AR, " << RAD2DEG(RKneePitch()) << " rk, " << RAD2DEG(RAnklePitch()) << " ap, " << RAD2DEG(RAnkleRoll()) << " ar, " << RAD2DEG(LHipYawPitch()) << " LHY, " << RAD2DEG(LHipRoll()) << " LHR, " << RAD2DEG(LHipPitch()) << " LHP, " << RAD2DEG(RHipYawPitch()) << " rhy, " << RAD2DEG(RHipRoll()) << " rhr, " << RAD2DEG(RHipPitch()) << "rhp";
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#pragma clang diagnostic pop

#endif //SENSORS_LegJointSensors_DEFINED
