#ifndef _WBMOTOR_
#define _WBMOTOR_

#include <sys/types.h>
#include <gu_util.h>

/** Basic motor struct */
struct wb_motor {
	/** Speed setting -127 to 127 in cm/s */
	PROPERTY(int8_t, speed)  
	/** Acceleration setting 0 to 255 in cm/s */
	PROPERTY(uint8_t, accel) 
	/** Odometer used for storing distance travelled */
	PROPERTY(uint16_t, dist) 
#ifdef __cplusplus
	/** Default constructor */
	wb_motor() : _speed(100), _accel(127), _dist(0) {}
#endif
};

#endif
