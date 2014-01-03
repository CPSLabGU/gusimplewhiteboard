/* 
 * File:   VisionLines.h
 * Author: eugene
 *
 * Created on 1 December 2013, 8:02 PM
 */

#ifndef VisionLines_DEFINED
#define	VisionLines_DEFINED

#include "Vision_Objects.h"
#include <string>
namespace guWhiteboard {
class VisionLines {
private:
    std::bitset<10> objectMask;
    SimpleLine _lines[10];
public:
    VisionBall() {
		objectMask.reset();
    }
	
	VisionBall(std::string s) {
		objectMask.reset();
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
					cam = VisionCamera::Top;
				else
					cam = VisionCamera::Bottom;
				
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
		if(objectMask[VisionCamera::Top])
			ret[VisionCamera::Top] = &(_ball[VisionCamera::Top]);
		else
			ret[VisionCamera::Top] = NULL;
		if(objectMask[VisionCamera::Bottom])
			ret[VisionCamera::Bottom] = &(_ball[VisionCamera::Bottom]);
		else
			ret[VisionCamera::Bottom] = NULL;
		return ret;
	}
    
	void Reset() {
		objectMask.reset();
	}
	
	std::string description() {
		std::stringstream result;
		if(objectMask[VisionCamera::Top]) {
			result << "TopBall:(" << ball()[VisionCamera::Top]->position.x << "," << ball()[VisionCamera::Top]->position.y << "," << ball()[VisionCamera::Top]->radius << ") ";
		}
		if(objectMask[VisionCamera::Bottom]) {
			result << "BottomBall:(" << ball()[VisionCamera::Bottom]->position.x << "," << ball()[VisionCamera::Bottom]->position.y << ")@" << ball()[VisionCamera::Bottom]->radius;
		}
		return result.str();
	}
	
};
}

#endif	/* VisionBall_DEFINED */