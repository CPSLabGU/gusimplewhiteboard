/**                                                                     
 *  /file APM_Interface.h
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                        
#ifndef APM_Interface_DEFINED
#define APM_Interface_DEFINED

#include "wb_apm_interface.h" 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#endif

namespace guWhiteboard                                                  
{
    /**
 	* @brief Class for interacting with and reading the values of APM sensors and motors
	*
	* Examples
	* --------
	*
	* get the yaw of a quad
	*
	*     APM_Interface i = APM_Status_t.get();
	*     fprintf(stderr, "yaw: %d", i.data().quad.yaw());
	*
 	*/
        class APM_Interface: public wb_apm_interface
        {
        public:

        /** default constructor 
		 */
		APM_Interface() { }


        /** comparison operator */
		inline bool operator == (const APM_Interface &s) 
	    {
           if(this->mode() != s.mode())
               return false;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"
			switch (this->mode())
			{
			case Quad:
#define QUAD(o, p) ( o ).data().quad. p ()
				if(QUAD(*this, thrust) != QUAD(s, thrust) || 
                    QUAD(*this, pitch) != QUAD(s, pitch) || 
                    QUAD(*this, roll) != QUAD(s, roll) || 
                    QUAD(*this, yaw) != QUAD(s, yaw))
                    return false;
				break;
			case Plane:
#define PLANE(o, p) ( o ).data().plane. p ()
				if(PLANE(*this, thrust) != PLANE(s, thrust))
                    return false;
				break;
			default:
				break;
			}
#pragma clang diagnostic pop
    	    return true;
        }

        /// return false if the two interfaces are the same
		inline bool operator != (const APM_Interface &s) 
        {
            return !(*this == s);
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
         /** string constructor (see from_string() below)
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
		APM_Interface(const std::string &str) { from_string(str); }

         /** parse class properties from a string
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
        void from_string(const std::string &str) 
		{
#define DELIMITER ','
            std::vector<std::string> v = components_of_string_separated(str, DELIMITER, true);
            if(!(v.size() > 0))
            {
			    fprintf(stderr, "APM_Interface couldn't parse this string, have it back %s\n", str.c_str());
                return;
            }
            apm_mode m = static_cast<apm_mode>(atoi(v.at(0).c_str()));
            this->set_mode(m);
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"
			switch (m)
            {
			case Quad:
                this->data().quad.set_thrust(static_cast<uint8_t>(atoi(v.at(1).c_str())));
                this->data().quad.set_pitch(static_cast<int16_t>(atoi(v.at(2).c_str())));
                this->data().quad.set_roll(static_cast<int16_t>(atoi(v.at(3).c_str())));
                this->data().quad.set_yaw(static_cast<int16_t>(atoi(v.at(4).c_str())));
				break;
			case Plane:
                this->data().plane.set_thrust(static_cast<uint8_t>(atoi(v.at(1).c_str())));
			    fprintf(stderr, "APM_Interface mode 'Plane' is NYI\n");
				break;
			default:
				break;
            }
#pragma clang diagnostic pop
		}

         /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
        std::string description() const
        {
            std::stringstream ss;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"
			switch (this->mode())
			{
			case Quad:
			    ss << "Thrust: "    << this->data().quad.thrust()    << ", ";
			    ss << "Pitch: "     << this->data().quad.pitch()     << ", ";
			    ss << "Roll: "      << this->data().quad.roll()      << ", ";
			    ss << "Yaw: "       << this->data().quad.yaw()       << "";
				break;
			case Plane:
			    ss << "Plane mode NYI";
				break;
			default:
				break;
			}
#pragma clang diagnostic pop
            return ss.str();
        }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
    };
}

#endif //APM_Interface_DEFINED
