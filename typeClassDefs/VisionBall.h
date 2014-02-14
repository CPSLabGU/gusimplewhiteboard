/* 
 * File:   VisionBall.h
 * Author: eugene
 *
 * Created on 25 November 2013, 6:03 PM
 */

#ifndef VisionBall_DEFINED
#define	VisionBall_DEFINED

#include "Vision_Objects.h"
#include "../../guvision/guvision_parameters.h"
#include <string>
namespace guWhiteboard {
class VisionBall {
private:
    std::bitset<2> objectMask;
    SimpleCircle _ball[2];
	unsigned long _frameNumber;
public:
    VisionBall() : _frameNumber(0) {
        objectMask.reset();
    }
	
	VisionBall &operator=(const VisionBall& a) {
		objectMask = a.getMask();
		_frameNumber = a.frameNumber();
		const SimpleCircle** b = a.ball();
		if(b[0]) {
			_ball[0].setCenter(b[0]->GetCenter());
			_ball[0].setRadius(b[0]->GetRadius());
		}
		if(b[1]) {
			_ball[1].setCenter(b[1]->GetCenter());
			_ball[1].setRadius(b[1]->GetRadius());
		}
		return *this;
	}
	
	VisionBall(const VisionBall &ball) {
		objectMask = ball.getMask();
		_frameNumber = ball.frameNumber();
		const SimpleCircle** b = ball.ball();
		if(b[0]) {
			_ball[0].setCenter(b[0]->GetCenter());
			_ball[0].setRadius(b[0]->GetRadius());
		}
		if(b[1]) {
			_ball[1].setCenter(b[1]->GetCenter());
			_ball[1].setRadius(b[1]->GetRadius());
		}
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
	}
	void setBall(SimpleCircle ballInfo, VisionCamera camera) {
		_ball[camera] = ballInfo;
		objectMask[camera]  = 1;
	}
	
	const SimpleCircle **ball() const
	{
		static const SimpleCircle* ret[2];
		if(objectMask[Top])
			ret[Top] = &(_ball[Top]);
		else
			ret[Top] = NULL;
		if(objectMask[Bottom])
			ret[Bottom] = &(_ball[Bottom]);
		else
			ret[Bottom] = NULL;
		return ret;
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

