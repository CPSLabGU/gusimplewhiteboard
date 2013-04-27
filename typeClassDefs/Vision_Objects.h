/*
 * VisionObjects.h
 *
 *  Created on: 23/04/2013
 *      Author: eugene
 */

#include <bitset>
#include <gu_util.h>

#ifndef VisionObjects_DEFINED
#define VisionObjects_DEFINED

struct WbBallInfo {
	int radius;
	int x;
	int y;
};


namespace VisionObjectTypes {enum object {
	Ball = 0,
	NUM_VISION_OBJECTS
};}

namespace guWhiteboard
{
class VisionObjects {
private:
	std::bitset<VisionObjectTypes::NUM_VISION_OBJECTS> objectMask;
	WbBallInfo ball;
public:
	VisionObjects() {
		memset(this, 0, sizeof(*this));
	}
	void setBall(WbBallInfo ball) {
		this->ball = ball;
		objectMask[VisionObjectTypes::Ball]  = 1;
	}
	WbBallInfo Ball() {
		return ball;
	}
};
}



#endif /* VisionObjects_DEFINED */
