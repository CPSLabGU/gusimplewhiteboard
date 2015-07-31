#ifndef 3DInput_h
#define 3DInput_h

#include <wb_point.h>

/**
 * Simple 3 dimensional input class
 */
struct wb_3dinput
{
    /** 3d point vector of input device. - yaw */
    PROPERTY(int16_t, yaw)
    /** 3d point vector of input device. - pitch */
    PROPERTY(int16_t, pitch)
    /** 3d point vector of input device. - roll */
    PROPERTY(int16_t, roll)
    /** power value, ie. high of leap hand or thrust of flight simulator */
    PROPERTY(int16_t, power)
};

#endif //3DInput_h
