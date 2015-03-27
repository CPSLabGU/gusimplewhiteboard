#ifndef _WBDIFFERENTIALROBOT_
#define _WBDIFFERENTIALROBOT_

#include <sys/types.h>
#include <gu_util.h>
#include "wb_motor.h"

struct wb_differential_robot {
	PROPERTY(struct wb_motor, left_motor)
	PROPERTY(struct wb_motor, right_motor)
#ifdef __cplusplus
	wb_differential_robot() : _left_motor(), _right_motor() {}
#endif
};

#endif
