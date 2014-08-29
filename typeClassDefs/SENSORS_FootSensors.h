/**                                                                     
 *  /file SENSORS_FootSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_FootSensors_DEFINED
#define SENSORS_FootSensors_DEFINED

#include "wb_sensors_foot.h" 


namespace guWhiteboard                                                  
{
        /**
 	* @brief Contains the current values of sensors located in the robots feet (designed for Nao)
	*
	* Examples
	* --------
	*
	* Get the value of the top left force sensor on the robots left foot
	*
	*     SENSORS_FootSensors s = SENSORS_FootSensors_t.get(); //get from the whiteboard
	*     float fsr_value = s.LFoot_FSR_FrontLeft(); //pull the variable out of the class
	*
 	*/
        class SENSORS_FootSensors : public wb_sensors_foot
        {
        public:

        };
}

#endif //SENSORS_FootSensors_DEFINED
