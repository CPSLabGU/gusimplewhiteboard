#ifndef NXT_Sound_Control_DEFINED
#define NXT_Sound_Control_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h" 
#include "wb_sound.h"

namespace guWhiteboard {
    /**
    *   Class for controlling differential robots
    *   Defines whiteboard message
    */
    class NXT_Sound_Control: public wb_sound {
        public:
            /** Designated constructor */
            NXT_Sound_Control(): wb_sound() {}
            
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            /** String constructor */
            NXT_Sound_Control(const std::string &name) { 
                from_string(name);
            }
            
            /** get message description */
            std::string description() {
		std::ostringstream ss;
                ss << static_cast<int>(frequency()) << ",";
                ss << static_cast<int>(duration()) << ",";
                return ss.str();
            }

            /** string conversion */
            void from_string (std::string str) {
                using namespace std;
		set_frequency(0);
		set_duration(false);
                vector<string> elements = components_of_string_separated(str, ',', true);

                if (elements.size() == 0) return; // nothin in the string ESCAPE

		// ONE ELEMNET
		set_frequency( static_cast<uint16_t>(atoi(elements[0].c_str()) ));
                if (elements.size() < 2) return; // only one lement in the string =>ESCAPE
		set_duration( static_cast<uint16_t>(atoi(elements[0].c_str()) ));
            }
#endif
            /** override equality operator so we can compare instances */
            bool operator == (const NXT_Sound_Control &s) {
		bool temp = true;
		if (frequency()!= s.frequency() )
		        return false;
		if (duration()!= s.duration() )
		        return false;
		
                return temp;
            }

    };
}
#endif //NXT_Sound_Control_DEFINED
