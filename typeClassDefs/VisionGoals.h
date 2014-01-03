/* 
 * File:   VisionGoals.h
 * Author: eugene
 *
 * Created on 1 December 2013, 8:02 PM
 */

#ifndef VisionGoals_DEFINED
#define	VisionGoals_DEFINED

#include "Vision_Objects.h"
#include <string>
namespace guWhiteboard {
class VisionGoals {
private:
    std::bitset<4> objectMask;
    WbGoalPostInfo _leftPost[2];
	WbGoalPostInfo _rightPost[2];
	unsigned long _frameNumber;
public:
    VisionGoals() : _frameNumber(0) {
        objectMask.reset();
    }
	
	VisionGoals(std::string s) : _frameNumber(0) {
		objectMask.reset();
		
		size_t n = -8;
		std::string command = "LEFTPOST";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+8);
			if (n!=std::string::npos) {
				std::string t = s.substr(n+command.length()+1);
				WbGoalPostInfo postInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;
				
				postInfo.outerBottom = getPoint(&t);
				postInfo.outerTop = getPoint(&t);
				postInfo.innerBottom = getPoint(&t);
				postInfo.innerTop = getPoint(&t);
				setLeftGoalPost(postInfo, cam);
			}
		}
		
		n = -8;
		command = "RIGHTPOST";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+8);
			if (n!=std::string::npos) {
				std::string t = s.substr(n+command.length()+1);
				WbGoalPostInfo postInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;
				
				postInfo.outerBottom = getPoint(&t);
				postInfo.outerTop = getPoint(&t);
				postInfo.innerBottom = getPoint(&t);
				postInfo.innerTop = getPoint(&t);
				setRightGoalPost(postInfo, cam);
			}
		}
	}
	void setLeftGoalPost(WbGoalPostInfo postInfo, VisionCamera camera) {
		_leftPost[camera] = postInfo;
		objectMask[camera]  = 1;
	}
	
	void setRightGoalPost(WbGoalPostInfo postInfo, VisionCamera camera) {
		_rightPost[camera] = postInfo;
		objectMask[2+camera]  = 1;
	}
	
	const WbGoalPostInfo **LeftPost() const
	{
		static const WbGoalPostInfo* ret[2];
		if(objectMask[Top])
			ret[Top] = &(_leftPost[Top]);
		else
			ret[Top] = NULL;
		if(objectMask[Bottom])
			ret[Bottom] = &(_leftPost[Bottom]);
		else
			ret[Bottom] = NULL;
		return ret;
	}
	
	const WbGoalPostInfo **RightPost() const
	{
		static const WbGoalPostInfo* ret[2];
		if(objectMask[Top])
			ret[Top] = &(_rightPost[Top]);
		else
			ret[Top] = NULL;
		if(objectMask[Bottom])
			ret[Bottom] = &(_rightPost[Bottom]);
		else
			ret[Bottom] = NULL;
		return ret;
	}
    
	void Reset() {
		objectMask.reset();
	}
	
	void setFrameNumber(unsigned long fn) {
		_frameNumber = fn;
	}
	
	unsigned long frameNumber() const {
		return _frameNumber;
	}
	
	std::string description() {
		std::stringstream result;
		
		if(objectMask[Bottom])
			result << "BottomLeftPost:(" << _leftPost[Bottom].outerBottom.x << "," << _leftPost[Bottom].outerBottom.y << ")("
			<< _leftPost[Bottom].outerTop.x << "," << _leftPost[Bottom].outerTop.y << ")("
			<< _leftPost[Bottom].innerBottom.x << "," << _leftPost[Bottom].innerBottom.y << ")("
			<< _leftPost[Bottom].innerTop.x << "," << _leftPost[Bottom].innerTop.y << ") ";
		if(objectMask[Top])
			result << "TopLeftPost:(" << _leftPost[Top].outerBottom.x << "," << _leftPost[Top].outerBottom.y << ")("
			<< _leftPost[Top].outerTop.x << "," << _leftPost[Top].outerTop.y << ")("
			<< _leftPost[Top].innerBottom.x << "," << _leftPost[Top].innerBottom.y << ")("
			<< _leftPost[Top].innerTop.x << "," << _leftPost[Top].innerTop.y << ") ";
		if(objectMask[2+Bottom])
			result << "BottomRightPost:(" << _rightPost[Bottom].outerBottom.x << "," << _rightPost[Bottom].outerBottom.y << ")("
			<< _rightPost[Bottom].outerTop.x << "," << _rightPost[Bottom].outerTop.y << ")("
			<< _rightPost[Bottom].innerBottom.x << "," << _rightPost[Bottom].innerBottom.y << ")("
			<< _rightPost[Bottom].innerTop.x << "," << _rightPost[Bottom].innerTop.y << ") ";
		if(objectMask[2+Top])
			result << "TopRightPost:(" << _rightPost[Top].outerBottom.x << "," << _rightPost[Top].outerBottom.y << ")("
			<< _rightPost[Top].outerTop.x << "," << _rightPost[Top].outerTop.y << ")("
			<< _rightPost[Top].innerBottom.x << "," << _rightPost[Top].innerBottom.y << ")("
			<< _rightPost[Top].innerTop.x << "," << _rightPost[Top].innerTop.y << ") ";
		return result.str();
	}
	
};
}

#endif	/* VisionGoals_DEFINED */

