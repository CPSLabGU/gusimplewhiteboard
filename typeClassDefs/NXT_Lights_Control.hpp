#ifndef NXT_Lights_Control_DEFINED
#define NXT_Lights_Control_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h" 
#include "wb_lights.h"

namespace guWhiteboard {
    /**
    *   Class for controlling differential robots
    *   Defines whiteboard message
    */
    class NXT_Lights_Control: public wb_lights {
        public:
            /** Designated constructor */
            NXT_Lights_Control(): wb_lights() {}
            
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            /** String constructor */
            NXT_Lights_Control(const std::string &name) { 
                from_string(name);
            }
            
            /** get message description */
            std::string description() {
		std::ostringstream ss;
		for (int b= 0 ; b <wb_lights_h_NUMBER_OF_LIGHTS; b++)
		      {  u_int8_t anIntenisty =lights(b); 
			 ss << static_cast<int>(anIntenisty) << ",";
		      }
                return ss.str();
            }

            /** string conversion */
            void from_string (std::string str) {
		std::istringstream iss(str);
	        std::string token;
		for (int i = 0; i < wb_lights_h_NUMBER_OF_LIGHTS && getline(iss, token, ','); i++) 
		{ const u_int8_t v = static_cast <u_int8_t>( ( atoi(token.c_str())  > 100 ) ?  
                                   100:
			        ( (atoi(token.c_str())   < 0) ? 0
				   : atoi(token.c_str()) 
				 ) ); 
		  set_lights(v, i); 
		}
            }
#endif
            /** override equality operator so we can compare instances */
            bool operator == (const NXT_Lights_Control &s) {
		bool temp = true;
                for (int b= 0 ; b <wb_lights_h_NUMBER_OF_LIGHTS; b++)
		{ u_int8_t anIntenisty =lights(b);
		  u_int8_t otherIntenisty =s.lights(b);
		  if (anIntenisty != otherIntenisty )
		        return false;
		}
                return temp;
            }

    };
}
#endif //NXT_Lights_Control_DEFINED
