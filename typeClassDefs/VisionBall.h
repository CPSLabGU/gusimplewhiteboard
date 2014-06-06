/* 
 * File:   VisionBall.h
 * Author: eugene
 *
 * Created on 25 November 2013, 6:03 PM
 */

#ifndef VisionBall_DEFINED
#define	VisionBall_DEFINED

#include "Vision_Objects.h"
#include <guvision_parameters.h>
#include <string>

struct wbBall {
	short x, y, radius;
};

namespace guWhiteboard {
class VisionBall {
private:
    std::bitset<2> objectMask;
    SimpleCircle _ball[2];
	SimpleCircle* ret[2];	
	unsigned long _frameNumber;
	wbBall topBall;
	wbBall bottomBall;
public:
    VisionBall() : _frameNumber(0) {
        objectMask.reset();
		_ball[Top] = SimpleCircle();
		_ball[Bottom] = SimpleCircle();
    }
	
	VisionBall &operator=(const VisionBall& a) {
		objectMask = a.getMask();
		_frameNumber = a.frameNumber();
		topBall = a.topBall;
		bottomBall = a.bottomBall;
		_ball[Top] = SimpleCircle();
		_ball[Bottom] = SimpleCircle();
		setRet();
		return *this;
	}
	
	VisionBall(const VisionBall &ball) {
		objectMask = ball.getMask();
		_frameNumber = ball.frameNumber();
		topBall = ball.topBall;
		bottomBall = ball.bottomBall;
		_ball[Top] = SimpleCircle();
		_ball[Bottom] = SimpleCircle();
		setRet();
	}
	
	std::bitset<2> getMask() const {
		return objectMask;
	}
	
	VisionBall(std::string s) : _frameNumber(0) {
		objectMask.reset();
		size_t n = -4;
		std::string command = "BALL";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+4);
			if (n!=std::string::npos) {
				std::string t = s.substr(n+command.length()+1);
				SimpleCircle ballInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;
				
				ballInfo.setCenter(getPoint(&t));
				ballInfo.setRadius(u_int16_t(atoi(t.substr(1, t.substr(1, t.size()-2).find_first_not_of("-0123456789")).c_str())));
				setBall(ballInfo, cam);
				objectMask[cam] = 1;
			}
		}
		_ball[Top] = SimpleCircle();
		_ball[Bottom] = SimpleCircle();
		setRet();
	}
	void setBall(SimpleCircle ballInfo, VisionCamera camera) {
		objectMask[camera]  = 1;
		if(camera == Top) {
			topBall.x = ballInfo.GetCenter().x;
			topBall.y = ballInfo.GetCenter().y;
			topBall.radius  = ballInfo.GetRadius();
		}
		if(camera == Bottom) {
			bottomBall.x = ballInfo.GetCenter().x;
			bottomBall.y = ballInfo.GetCenter().y;
			bottomBall.radius  = ballInfo.GetRadius();
		}
		setRet();
	}
	/*	
	const SimpleCircle *balls() const
	{
		return _balls;
	}

	const SimpleCircle *ball(VisionCamera camera) const
	{
		if(objectMask[camera])
			return &_balls[camera];

		return NULL;
	}
*/
	SimpleCircle*const* ball() const
	{
		return ret;
	}
	
	void setRet() {
		if(objectMask[Top]) {
			_ball[Top].setCenter(GUPoint<short>(topBall.x, topBall.y));
			_ball[Top].setRadius(topBall.radius);
			ret[Top] = &_ball[Top];
		}
		else
			ret[Top] = NULL;
		if(objectMask[Bottom]) {
			_ball[Bottom].setCenter(GUPoint<short>(bottomBall.x, bottomBall.y));
			_ball[Bottom].setRadius(bottomBall.radius);
			ret[Bottom] = &_ball[Bottom];
		}
		else
			ret[Bottom] = NULL;
	}
	
	void setFrameNumber(unsigned long fn) {
		_frameNumber = fn;
	}
	
	unsigned long frameNumber() const {
		return _frameNumber;
	}
    
	void Reset() {
		objectMask.reset();
	}
	
	std::string description() {
		std::stringstream result;
		if(objectMask[Top]) {
			result << "TopBall:(" << ball()[Top]->GetCenter().x << "," << ball()[Top]->GetCenter().y << ")@" << ball()[Top]->GetRadius();
		}
		if(objectMask[Bottom]) {
			result << "BottomBall:(" << ball()[Bottom]->GetCenter().x << "," << ball()[Bottom]->GetCenter().y << ")@" << ball()[Bottom]->GetRadius();
		}
		return result.str();
	}
	
};
}

#endif	/* VisionBall_DEFINED */

