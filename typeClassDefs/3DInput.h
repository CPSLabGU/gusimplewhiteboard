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
            3DInput(int16_t x = 0, int16_t y = 0, int16_t z = 0, int16_t power = 0): wb_3dinput(x, y, z, power) { }

            /** copy constructor */
            3DInput(const 3DInput &other): wb_3dinput(other.vector.x(), other.vector.y(), other.vector.z(), other.power()) {}

            /** copy assignment operator */
            3DInput &operator=(const 3DInput &other) { set_vector(wb_point3d(other.vector.x(), other.vector.y(), other.vector.z())); set_power(other.power()); return *this; }

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
                ss << vector.x() << "," << vector.y() << "," << vector.z() << "," << power();
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
