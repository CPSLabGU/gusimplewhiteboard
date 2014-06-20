#ifndef _WBBALL_
#define _WBBALL_

struct wbBall {
	int16_t x, y, radius;
#ifdef __cplusplus
	wbBall() : x(0), y(0), radius(0) {}
#endif
};

#endif
