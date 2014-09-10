#ifndef _WBMOTOR_
#define _WBMOTOR_

#include <sys/types.h>
#include <gu_util.h>

struct wb_motor {
	PROPERTY(int8_t, speed)  //Speed setting -127 to 127 in cm/s
	PROPERTY(uint8_t, accel) //Acceleration setting 0 to 255 in cm/s
	PROPERTY(uint16_t, dist) //Odometer used for storing distance travelled
#ifdef __cplusplus
	wb_motor() : _speed(0), _accel(127), _dist(0) {}
#endif
};

#endif
