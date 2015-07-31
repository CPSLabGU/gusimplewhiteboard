#ifndef wb_3dinput_h
#define wb_3dinput_h

#include <gu_util.h>

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

#ifdef __cplusplus
    /** constructor */
    wb_3dinput(int16_t yaw = 0, int16_t pitch = 0, int16_t roll = 0, int16_t power = 0): _yaw(yaw), _pitch(pitch), _roll(roll), _power(power) {}
#endif
};

#endif //wb_3dinput_h
