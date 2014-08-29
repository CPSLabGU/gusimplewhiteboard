#ifndef _WBBALL_
#define _WBBALL_

#include <sys/types.h>
#include <gu_util.h>

struct wb_ball
{
	/** the balls x coordinate in pixels (relative to the center of the image) */
	PROPERTY(int16_t, x)
	/** the balls y coordinate in pixels (relative to the center of the image) */
        PROPERTY(int16_t, y)
	/** the balls radius in pixels */
        PROPERTY(int16_t, radius)

#ifdef __cplusplus
	/** default constructor */
	wb_ball() : _x(0), _y(0), _radius(0) {}
#endif
};

#endif
