#ifndef _WBMOTOR_
#define _WBMOTOR_

#include <sys/types.h>
#include <gu_util.h>

/** Basic kinematic motor (i.e. motor to ground) struct */
struct wb_motor {
	/** Speed setting -32767 to 32767 in mm/s */
	PROPERTY(int16_t, speed)
	/** Acceleration setting -32767 to 32767 in mm/s/s */
	PROPERTY(uint16_t, accel)
	/** Odometer used for storing distance travelled in mm */
	PROPERTY(uint16_t, dist)
#ifdef __cplusplus
	/** Default constructor */
	wb_motor() : _speed(16), _accel(127), _dist(0) {}
#endif
};

#endif
