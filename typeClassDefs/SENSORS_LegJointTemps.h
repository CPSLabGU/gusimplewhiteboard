/**                                                                     
 *  /file SENSORS_LegJointTemps.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_LegJointTemps_DEFINED
#define SENSORS_LegJointTemps_DEFINED

#include "wb_sensors_legtemps.h" 

namespace guWhiteboard                                                  
{
        /**
 	* @brief Contains the current temperature estimates in the robots legs (designed for Nao)
	*
	* Examples
	* --------
	*
	* Get the temperature of the pitch motor in the left knee
	*
	*     SENSORS_LegJointTemps s = SENSORS_LegJointTemps_t.get(); //get from the whiteboard
	*     float knee_temp = s.LKneePitch(); //pull the variable out of the class
	*
 	*/
        class SENSORS_LegJointTemps : public wb_sensors_legtemps
        {
               
        public:
                SENSORS_LegJointTemps()
                {

                }
        };
}

#endif //SENSORS_LegJointTemps_DEFINED
