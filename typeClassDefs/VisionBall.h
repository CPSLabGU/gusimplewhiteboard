/* 
 * File:   VisionBall.h
 * Author: eugene
 *
 * Created on 25 November 2013, 6:03 PM
 */

#ifndef VisionBall_DEFINED
#define	VisionBall_DEFINED

#include <string>
#include <cstdlib>

#include <SimpleShapes.h>
#include "Vision_Control.h"
#include <wb_ball.h>



namespace guWhiteboard {
class VisionBall {
private:
	unsigned long _frameNumber;
	wbBall topBall;
	wbBall bottomBall;
	bool _topVisible, _bottomVisible;
public:
    VisionBall() : _frameNumber(0), topBall(), bottomBall() {
    }
	
	VisionBall &operator=(const VisionBall& a) {
		_frameNumber = a.frameNumber();
		topBall = a.topBall;
		bottomBall = a.bottomBall;
		return *this;
	}
	
	VisionBall(const VisionBall &ball) {
		_frameNumber = ball.frameNumber();
		topBall = ball.topBall;
		bottomBall = ball.bottomBall;
	}
	
	/*DEPRICATED*/
	std::bitset<2> getMask() const {
		std::bitset<2> objectMask;
		objectMask[Top] = _topVisible;
		objectMask[Bottom] = _bottomVisible;
		return objectMask;
	}

	void setBall(SimpleCircle ballInfo, VisionCamera camera) {
		if(camera == Top) {
			topBall.x = ballInfo.GetCenter().x;
			topBall.y = ballInfo.GetCenter().y;
			topBall.radius  = ballInfo.GetRadius();
			_topVisible = true;
		}
		if(camera == Bottom) {
			bottomBall.x = ballInfo.GetCenter().x;
			bottomBall.y = ballInfo.GetCenter().y;
			bottomBall.radius  = ballInfo.GetRadius();
			_bottomVisible = true;
		}
	}
	
	void setBall(wbBall ballInfo, VisionCamera camera) {
		if(camera == Top) {
			topBall.x = ballInfo.x;
			topBall.y = ballInfo.y;
			topBall.radius  = ballInfo.radius;
			_topVisible = true;
		}
		if(camera == Bottom) {
			bottomBall.x = ballInfo.x;
			bottomBall.y = ballInfo.y;
			bottomBall.radius  = ballInfo.radius;
			_bottomVisible = true;
		}
	}

	
	int16_t topRadius() const { return topBall.radius; }
	int16_t topX() const { return topBall.x; }
	int16_t topY() const { return topBall.y; }
	bool topVisible() {return _topVisible;}
	int16_t bottomRadius() const { return bottomBall.radius; }
	int16_t bottomX() const { return bottomBall.x; }
	int16_t bottomY() const { return bottomBall.y; }
	bool bottomVisible() {return _bottomVisible;}
	bool visable() {return _topVisible || _bottomVisible; }
	int16_t radius() const { 
		if (_topVisible) 
			return topBall.radius;
		else if (_bottomVisible)
			return bottomBall.radius;
		else
			return 0;
	}
	int16_t x() const { 
		if (_topVisible) 
			return topBall.x;
		else if (_bottomVisible)
			return bottomBall.x;
		else
			return 0;
	}
	int16_t y() const { 
		if (_topVisible) 
			return topBall.y;
		else if (_bottomVisible)
			return bottomBall.y;
		else
			return 0;
	}
	
	
	
	void setFrameNumber(unsigned long fn) {
		_frameNumber = fn;
	}
	
	unsigned long frameNumber() const {
		return _frameNumber;
	}
        
	void Reset() {
		_topVisible = false;
		_bottomVisible = false;
	}

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        
        static const char SEPARATOR_IS_AT = '@';

        VisionBall(std::string s): VisionBall() {
                from_string(s);
        }

        VisionBall(const char *s): VisionBall() {
                from_string(std::string(s));
        }
        
	void from_string(std::string s) {
		std::string radiousDel (1,SEPARATOR_IS_AT);
		setFrameNumber(0);
		Reset();
		size_t n = -4;
		std::string command = "BALL";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+4);
			if (n!=std::string::npos && n>=3) {
				std::string t = s.substr(n+command.length()+1);
				SimpleCircle ballInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;
				
				ballInfo.setCenter(t.c_str());
                                 std::size_t found = t.find(SEPARATOR_IS_AT);
                                if (std::string::npos!=found )
                                { std::string strRadious=t.substr (found+1);
                                        ballInfo.setRadius(static_cast<u_int16_t>(::atoi(strRadious.c_str())));
                                }
				setBall(ballInfo, cam);
			}
		}
	}
	
	std::string description() {
		std::stringstream result;
		if(_topVisible) {
			result << "TopBall:(" << topBall.x << "," << topBall.y << ")"<< SEPARATOR_IS_AT << topBall.radius;
		}
		if(_bottomVisible) {
			result << "BottomBall:(" << bottomBall.x << "," << bottomBall.y << ")"<< SEPARATOR_IS_AT << bottomBall.radius;
		}
		return result.str();
	}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

};
}

#endif	/* VisionBall_DEFINED */

