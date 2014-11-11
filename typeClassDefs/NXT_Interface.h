/**                                                                     
 *  /file NXT_Interface.h
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                        
#ifndef NXT_Interface_DEFINED
#define NXT_Interface_DEFINED

#include "wb_nxt_interface.h" 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#endif

namespace guWhiteboard                                                  
{
        /**
 	* @brief Class for interacting with and reading the values of NXT sensors and motors
	*
	* Examples
	* --------
	*
	* Get the state of a touch sensor plugged into port 2 of the NXT
	*
	*     NXT_Interface i = NXT_Status_t.get();
	*     fprintf(stderr, "Button state: %d", i.objects(Port2).data().pressed());
	*
	* Tell motor B to go 75 percent of its maximum speed forwards
	*
	*     NXT_Interface i;
	*     i.set_objects(MotorB);  !!TODO: Fix this example
	*     fprintf(stderr, "Number of button presses: %d", i.but0());
	*
 	*/
        class NXT_Interface: public wb_nxt_interface
        {
        public:

        /** default constructor 
		 */
		NXT_Interface() { }


        /** comparison operator */
		inline bool operator == (const NXT_Interface &s) 
	    {
            for(int p = Port1; p < NUMBER_OF_NXT_PORTS; p++)
			{
				nxt_port_object o = this->objects(p);
				nxt_port_object n = s.objects(p);
                if(o.type() != n.type())
                    return false;
#define PORT "(" << p << ")"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"
				switch (o.type())
				{
				case Touch_Sensor:
					if(o.data().touch_sensor.pressed() != n.data().touch_sensor.pressed())
                        return false;
					break;
				case Sonar_Sensor:
					if(o.data().sonar_sensor.distance() != n.data().sonar_sensor.distance())
                        return false;
					break;
				case Active_Light_Sensor:
					if(o.data().active_light_sensor.value() != n.data().active_light_sensor.value())
                        return false;
					break;
				case Passive_Light_Sensor:
					if(o.data().passive_light_sensor.value() != n.data().passive_light_sensor.value())
                        return false;
					break;
				case Motor:
					if(o.data().motor.speed() != n.data().motor.speed() || o.data().motor.enc_ticks() != n.data().motor.enc_ticks() || o.data().motor.speed_mask() != n.data().motor.speed_mask() || o.data().motor.enc_ticks_mask() != n.data().motor.enc_ticks_mask())
                        return false;
					break;
				default:
					break;
				}
#pragma clang diagnostic pop
			}
    	    return true;
        }

		inline bool operator != (const NXT_Interface &s) 
        {
            return !(*this == s);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below)
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
		NXT_Interface(const std::string &str) { from_string(str); }

                /** parse class properties from a string
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
                void from_string(const std::string &str) 
		{
			//NYI
			fprintf(stderr, "NXT_Interface doesn't implement from_string yet, have it back %s\n", str.c_str());
		}

                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;
			for(int p = Port1; p < NUMBER_OF_NXT_PORTS; p++)
			{
				nxt_port_object o = objects(p);
#define PORT "(" << p << ")"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"
				switch (o.type())
				{
				case Touch_Sensor:
					ss << PORT << "Touch: " << o.data().touch_sensor.pressed() << ", ";
					break;
				case Sonar_Sensor:
					ss << PORT << "Sonar: " << static_cast<int>(o.data().sonar_sensor.distance()) << ", ";
					break;
				case Active_Light_Sensor:
					ss << PORT << "Active Light: " << o.data().active_light_sensor.value() << ", ";
					break;
				case Passive_Light_Sensor:
					ss << PORT << "Passive Light: " << o.data().passive_light_sensor.value() << ", ";
					break;
				case Motor:
					ss << PORT << "Motor: (s: " << o.data().motor.speed() << ", enc: " << o.data().motor.enc_ticks() << "), ";
					break;
				default:
					break;
				}
#pragma clang diagnostic pop
			}
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //NXT_Interface_DEFINED
