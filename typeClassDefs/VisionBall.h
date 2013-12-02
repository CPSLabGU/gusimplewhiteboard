/* 
 * File:   VisionBall.h
 * Author: eugene
 *
 * Created on 25 November 2013, 6:03 PM
 */

#ifndef VisionBall_DEFINED
#define	VisionBall_DEFINED

#include "Vision_Objects.h"
#include <string>
namespace guWhiteboard {
class VisionBall {
private:
    std::bitset<2> objectMask;
    WbBallInfo _ball[2];
	unsigned long _frameNumber;
public:
    VisionBall() {
        memset(this, 0, sizeof(*this));
    }
	
	VisionBall(std::string s) {
		memset(this, 0, sizeof(*this));
		size_t n = -4;
		std::string command = "BALL";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+4);
			if (n!=std::string::npos) {
				std::string t = s.substr(n+command.length()+1);
				WbBallInfo ballInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;
				
				ballInfo.position = getPoint(&t);
				ballInfo.radius = u_int16_t(atoi(t.substr(1, t.substr(1, t.size()-2).find_first_not_of("-0123456789")).c_str()));
				setBall(ballInfo, cam);
			}
		}
	}
	void setBall(WbBallInfo ballInfo, VisionCamera camera) {
		_ball[camera] = ballInfo;
		objectMask[camera]  = 1;
	}
	
	const WbBallInfo **ball() const
	{
		static const WbBallInfo* ret[2];
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
			result << "TopBall:(" << ball()[Top]->position.x << "," << ball()[Top]->position.y << "," << ball()[Top]->radius << ") ";
		}
		if(objectMask[Bottom]) {
			result << "BottomBall:(" << ball()[Bottom]->position.x << "," << ball()[Bottom]->position.y << ")@" << ball()[Bottom]->radius;
		}
		return result.str();
	}
	
};
}

#endif	/* VisionBall_DEFINED */

