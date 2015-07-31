/****************** I M P O R T A N T   */
/* is <class_name>_DEFINED              */
/***************************************/

#ifndef 3DInput_DEFINED
#define 3DInput_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <sstream>
#endif
#include <gu_util.h>
#include "wb_3dinput.h"

namespace guWhiteboard
{
        /**
         * Class for for demonstrating OO-messages.
         */
        class 3DInput: public wb_3dinput
        {
        public:
            /** designated constructor */
            3DInput(int16_t yaw = 0, int16_t pitch = 0, int16_t roll = 0, int16_t power = 0): wb_3dinput(yaw, pitch, roll, power) { }

            /** copy constructor */
            3DInput(const 3DInput &other): wb_3dinput(other.yaw(), other.pitch(), other.roll(), other.power()) {}

            /** copy assignment operator */
            3DInput &operator=(const 3DInput &other) { set_yaw(other.yaw()); set_pitch(other.pitch()); set_roll(other.roll()); set_power(other.power()); return *this; }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            /** string constructor */
            3DInput(const std::string &names) { from_string(names); }

            /** const char *constructor */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"
            3DInput(const char *names): 3DInput(std::string(names)) { }
#pragma clang diagnostic pop
            /** convert to a string */
            std::string description()
            {
                std::ostringstream ss;
                ss << yaw() << "," << pitch() << "," << roll() << "," << power();
                return ss.str();
            }

            /** convert from a string */
            void from_string(const std::string &str)
            {
               //NYI 
            }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}
#endif // 3DInput_DEFINED
