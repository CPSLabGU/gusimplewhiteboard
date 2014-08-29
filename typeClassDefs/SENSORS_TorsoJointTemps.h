/**                                                                     
 *  /file SENSORS_TorsoJointTemps.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_TorsoJointTemps_DEFINED
#define SENSORS_TorsoJointTemps_DEFINED

#include "wb_sensors_torsotemps.h" 

namespace guWhiteboard                                                  
{
        /**
 	* @brief Contains the current temperature estimates in the robots upper half (designed for Nao)
	*
	* Examples
	* --------
	*
	* Get the temperature of the pitch motor in the head
	*
	*     SENSORS_TorsoJointTemps s = SENSORS_TorsoJointTemps_t.get(); //get from the whiteboard
	*     float head_pitch_temp = s.HeadPitch(); //pull the variable out of the class
	*
 	*/
        class SENSORS_TorsoJointTemps : public wb_sensors_torsotemps
        {
               
        public:
                SENSORS_TorsoJointTemps()
                {

                }
        };
}

#endif //SENSORS_TorsoJointTemps_DEFINED
