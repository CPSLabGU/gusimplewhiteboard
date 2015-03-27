#ifndef _WBMOTOR_
#define _WBMOTOR_

#include <sys/types.h>
#include <gu_util.h>

#define DEFAULT_KINEMATIC_ACCELERATION  0

/** Basic kinematic motor (i.e. motor to ground) struct */
struct wb_kinematic_motor {
	/** Speed setting -32767 to 32767 in mm/s */
	PROPERTY(int16_t, speed)
	/** Acceleration setting -32767 to 32767 in mm/s/s
            (zero means default acceleration) */
	PROPERTY(uint16_t, accel)
	/** Odometer used for storing odometry in mm (to ground) */
	PROPERTY(uint16_t, odo)
        /** padding to shut up the compiler on 64 bit systems */
        PROPERTY(uint16_t, padding)
#ifdef __cplusplus
	/** Default constructor */
	wb_motor() : _speed(16), _accel(DEFAULT_KINEMATIC_ACCELERATION), _dist(0), _padding(0) {}
#endif
};

#endif
