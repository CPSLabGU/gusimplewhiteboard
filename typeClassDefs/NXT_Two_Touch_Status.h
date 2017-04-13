#ifndef NXT_Two_Touch_Status_DEFINED
#define NXT_Two_Touch_Status_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h" 
#include "wb_buttons_status.h"

namespace guWhiteboard {
    /**
    *   Class for controlling differential robots
    *   Defines whiteboard message
    */
    class NXT_Two_Touch_Status: public wb_buttons_status {
        public:
            /** Designated constructor */
            NXT_Two_Touch_Status(): wb_buttons_status() {}
            
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            /** String constructor */
            NXT_Two_Touch_Status(const std::string &name) { 
                from_string(name);
            }
            
            /** get message description */
            std::string description() {
		std::ostringstream ss;
		for (int b= LEFT_BUTTON ; b <NUMBER_OF_NXT_BUTTONS; b++)
		{  wb_button aButton =touch_sensors(b);
                    ss << static_cast<int>(aButton.is_pressed()) << ",";
		}
                return ss.str();
            }

            /** string conversion */
            void from_string (std::string str) {
                using namespace std;
		wb_button &l = touch_sensors(LEFT_BUTTON);
		wb_button &r = touch_sensors(RIGHT_BUTTON);
		l.set_is_pressed(false);
		r.set_is_pressed(false);
                vector<string> elements = components_of_string_separated(str, ',', true);

                if (elements.size() == 0) return; // nothin in the string ESCAPE

		// ONE ELEMNET
		if (0!=atoi(elements[0].c_str() )) l.set_is_pressed(true);
                if (elements.size() < 2) return; // only one lement in the string =>ESCAPE
		if (0!=atoi(elements[1].c_str() )) r.set_is_pressed(true);
            }
#endif
            /** override equality operator so we can compare instances */
            bool operator == (const NXT_Two_Touch_Status &s) {
		bool temp = true;
		for (int b= LEFT_BUTTON ; b <NUMBER_OF_NXT_BUTTONS; b++)
		{  wb_button aButton =touch_sensors(b);
		   wb_button otherButton =s.touch_sensors(b);
		   if (aButton.is_pressed()!= otherButton.is_pressed() )
		        return false;
		}
                return temp;
            }

    };
}
#endif //NXT_Two_Touch_Status_DEFINED
