/**                                                                     
 *  /file SENSORS_BodySensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_BodySensors_DEFINED
#define SENSORS_BodySensors_DEFINED

#include "wb_sensors_body.h" 

namespace guWhiteboard                                                  
{
        /**
 	* @brief Contains the current values of sensors located in the robots chest (designed for Nao)
	*
	* Examples
	* --------
	*
	* Get the state of the Chest Button
	*
	*     SENSORS_BodySensors s = SENSORS_BodySensors_t.get(); //get from the whiteboard
	*     bool button_state = s.ChestBoard_Button(); //pull the variable out of the class
	*
 	*/
        class SENSORS_BodySensors : public wb_sensors_body
        {
        public:
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below) - NYI
		 *  @param str a serialised string containing properties to set in this class
		 */
		SENSORS_BodySensors(const std::string &str) { from_string(str); }

                /** parse class properties from a string - NYI
		 *  @param str a serialised string containing properties to set in this class
		 */
                void from_string(const std::string &str) { /*NYI, Good luck*/ }

                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;
                        ss << RAD2DEG(InertialSensor_AccX()) << " AccX, " << RAD2DEG(InertialSensor_AccY()) << " AccY, " << RAD2DEG(InertialSensor_AccZ()) << " AccZ, " << RAD2DEG(InertialSensor_GyrX()) << " GyrX, " << RAD2DEG(InertialSensor_GyrY()) << " GyrY, " << RAD2DEG(InertialSensor_GyrRef()) << " GyrRef, " << RAD2DEG(InertialSensor_AngleX()) << " X, " << RAD2DEG(InertialSensor_AngleY()) << " Y, " << ChestBoard_Button() << " Chest, " << Battery_Charge() << " Charge, " << Battery_Current() << " Current, " << US() << " US";
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //SENSORS_BodySensors_DEFINED
