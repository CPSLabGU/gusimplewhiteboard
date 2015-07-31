#ifndef 3DInput_h
#define 3DInput_h

#include <wb_point.h>

/**
 * Simple 3 dimensional input class
 */
struct wb_3dinput
{
    /** 3d point vector of input device. */
    PROPERTY(wb_point3d, vector)
    /** power value, ie. high of leap hand or thrust of flight simulator */
    PROPERTY(int16_t, power)
};

#endif //3DInput_h
