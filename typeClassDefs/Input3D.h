/****************** I M P O R T A N T   */
/* is <class_name>_DEFINED              */
/***************************************/

#ifndef Input3D_DEFINED
#define Input3D_DEFINED

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
        class Input3D: public wb_3dinput
        {
        public:
            /** designated constructor */
            Input3D(int16_t yaw = 0, int16_t pitch = 0, int16_t roll = 0, int16_t power = 0): wb_3dinput(yaw, pitch, roll, power) { }

            /** copy constructor */
            Input3D(const Input3D &other): wb_3dinput(other.yaw(), other.pitch(), other.roll(), other.power()) {}

            /** copy assignment operator */
            Input3D &operator=(const Input3D &other) { set_yaw(other.yaw()); set_pitch(other.pitch()); set_roll(other.roll()); set_power(other.power()); return *this; }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            /** string constructor */
            Input3D(const std::string &names) { from_string(names); }

            /** const char *constructor */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"
            Input3D(const char *names): Input3D(std::string(names)) { }
#pragma clang diagnostic pop
            /** convert to a string */
            std::string description()
            {
                std::ostringstream ss;
                ss << yaw() << ",\t" << pitch() << ",\t" << roll() << ",\t" << power();
                return ss.str();
            }

            /** convert from a string */
            void from_string(const std::string &)
            {
               //NYI 
            }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}
#endif // Input3D_DEFINED
