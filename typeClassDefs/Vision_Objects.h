/*
 * VisionObjects.h
 *
 *  Created on: 23/04/2013
 *      Author: eugene
 */

#include <bitset>
#include <gu_util.h>
#include <../guvision/SimpleShapes.h>
#include <stdint.h>
#include <sstream>
#include <stdio.h>


#ifndef VisionObjects_DEFINED
#define VisionObjects_DEFINED

struct WbBallInfo {
	uint16_t radius;
	GUPoint<uint16_t> position;
};

struct WbGoalPostInfo {
	GUPoint<uint16_t> outerBottom;
	GUPoint<uint16_t> outerTop;

	GUPoint<uint16_t> innerBottom;
	GUPoint<uint16_t> innerTop;
};

struct WbLineInfo {
	uint16_t startX, startY, endX, endY;
};


namespace VisionObjectTypes {enum object {
	Ball = 0,
	LeftGoalPost,
	RightGoalPost,
	Line1,
	Line2,
	Line3,
	Line4,
	Line5,
	NUM_VISION_OBJECTS
};}

namespace guWhiteboard
{
class VisionObjects {
private:
	std::bitset<VisionObjectTypes::NUM_VISION_OBJECTS> objectMask;
	WbLineInfo _lines[5];
	WbBallInfo _ball;
	WbGoalPostInfo _leftGoalPost;
	WbGoalPostInfo _rightGoalPost;
public:
	VisionObjects() {
		memset(this, 0, sizeof(*this));
	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
	VisionObjects(std::string) {
		fprintf(stderr, "Error VisionObject String constructor NYI\n");
		throw "NotImplemented";
	}
#pragma clang diagnostic pop
	void setBall(WbBallInfo ballInfo) {
		_ball = ballInfo;
		objectMask[VisionObjectTypes::Ball]  = 1;
	}
	WbBallInfo* ball() {
		if(objectMask[VisionObjectTypes::Ball])
			return &_ball;
		return NULL;
	}
	void setLeftGoalPost(WbGoalPostInfo postInfo) {
		_leftGoalPost = postInfo;
		objectMask[VisionObjectTypes::LeftGoalPost]  = 1;
	}
	WbGoalPostInfo* LeftGoalPost() {
		if(objectMask[VisionObjectTypes::LeftGoalPost])
			return &_leftGoalPost;
		return NULL;
	}

	void setRightGoalPost(WbGoalPostInfo postInfo) {
		_rightGoalPost = postInfo;
		objectMask[VisionObjectTypes::RightGoalPost]  = 1;
	}
	WbGoalPostInfo* RightGoalPost() {
		if(objectMask[VisionObjectTypes::RightGoalPost])
			return &_rightGoalPost;
		return NULL;
	}

	void addLine(WbLineInfo line) {
		for(int i = VisionObjectTypes::Line1; i<VisionObjectTypes::Line5; ++i) {
			if(objectMask[i] == 0) {
				_lines[i-VisionObjectTypes::Line1] = line;
				objectMask[i] = 1;
				break;
			}
		}
	}

	WbLineInfo* Line(VisionObjectTypes::object line) {
		if(line >= VisionObjectTypes::Line1 && line <= VisionObjectTypes::Line5)
			if(objectMask[line])
				return & _lines[line - VisionObjectTypes::Line1];
		return NULL;
	}


	void ClearMask() {
		objectMask.reset();
	}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
	std::string description() {
		std::stringstream result;
		if(objectMask[VisionObjectTypes::Ball]) {
			result << "Ball:(" << ball()->position.x << "," << ball()->position.y << "," << ball()->radius << ") ";
		}
		if(objectMask[VisionObjectTypes::LeftGoalPost])
			result << "LeftGoalPost:(" << _leftGoalPost.outerBottom.x << "," << _leftGoalPost.outerBottom.y << ","
			<< _leftGoalPost.outerTop.x << "," << _leftGoalPost.outerTop.y << ","
			<< _leftGoalPost.innerBottom.x << "," << _leftGoalPost.innerBottom.y << ","
			<< _leftGoalPost.innerBottom.x << "," << _leftGoalPost.innerBottom.y << ") ";
		if(objectMask[VisionObjectTypes::RightGoalPost])
			result << "RightGoalPost:(" << _rightGoalPost.outerBottom.x << "," << _rightGoalPost.outerBottom.y << ","
			<< _rightGoalPost.outerTop.x << "," << _rightGoalPost.outerTop.y << ","
			<< _rightGoalPost.innerBottom.x << "," << _rightGoalPost.innerBottom.y << ","
			<< _rightGoalPost.innerBottom.x << "," << _rightGoalPost.innerBottom.y << ") ";
		for(int i = VisionObjectTypes::Line1; i<=VisionObjectTypes::Line5; ++i)
			if(objectMask[i])
				result << "Line" << (i-VisionObjectTypes::Line1+1) << "(" << _lines[i-VisionObjectTypes::Line1].startX
				<< "," << _lines[i-VisionObjectTypes::Line1].startY
				<< "," << _lines[i-VisionObjectTypes::Line1].endX
				<< "," << _lines[i-VisionObjectTypes::Line1].endY << ") ";
		return result.str();
	}
#endif
};
}



#endif /* VisionObjects_DEFINED */
