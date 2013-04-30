/*
 * VisionObjects.h
 *
 *  Created on: 23/04/2013
 *      Author: eugene
 */

#include <bitset>
#include <gu_util.h>
#include <stdint.h>
#include <sstream>
#include <stdio.h>


#ifndef VisionObjects_DEFINED
#define VisionObjects_DEFINED

struct WbBallInfo {
	uint16_t radius;
	uint16_t x;
	uint16_t y;
};

struct WbGoalInfo {
	uint16_t rightX, rightY, leftX, leftY;
	uint16_t rightWidth, rightHeight, leftWidth, leftHeight;
};

struct WbLineInfo {
	uint16_t startX, startY, endX, endY;
};


namespace VisionObjectTypes {enum object {
	Ball = 0,
	Goal,
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
	WbLineInfo lines[5];
	WbBallInfo ball;
	WbGoalInfo goal;
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
		ball = ballInfo;
		objectMask[VisionObjectTypes::Ball]  = 1;
	}
	WbBallInfo* Ball() {
		if(objectMask[VisionObjectTypes::Ball])
			return &ball;
		return NULL;
	}
	void setGoal(WbGoalInfo goalInfo) {
		goal = goalInfo;
		objectMask[VisionObjectTypes::Goal]  = 1;
	}
	WbGoalInfo* Goal() {
		if(objectMask[VisionObjectTypes::Goal])
			return &goal;
		return NULL;
	}

	void addLine(WbLineInfo line) {
		for(int i = VisionObjectTypes::Line1; i<VisionObjectTypes::Line5; ++i) {
			if(objectMask[i] == 0) {
				lines[i-VisionObjectTypes::Line1] = line;
				objectMask[i] = 1;
				break;
			}
		}
	}

	WbLineInfo* Line(VisionObjectTypes::object line) {
		if(line >= VisionObjectTypes::Line1 && line <= VisionObjectTypes::Line5)
			if(objectMask[line])
				return &lines[line - VisionObjectTypes::Line1];
		return NULL;
	}


	void ClearMask() {
		objectMask.reset();
	}

	std::string description() {
		std::stringstream result;
		if(objectMask[VisionObjectTypes::Ball]) {
			result << "Ball:(" << ball.x << "," << ball.y << "," << ball.radius << ")\n";
		}
		if(objectMask[VisionObjectTypes::Goal])
			result << "Goal:(" << goal.leftX << "," << goal.leftY << ","
			<< goal.rightX << "," << goal.rightY << "," << goal.leftWidth << ","
			<< goal.leftHeight << "," << goal.rightWidth << "," << goal.rightHeight << ")\n";
		for(int i = VisionObjectTypes::Line1; i<=VisionObjectTypes::Line5; ++i)
			if(objectMask[i])
				result << "Line" << i << "(" << lines[i-VisionObjectTypes::Line1].startX
				<< "," << lines[i-VisionObjectTypes::Line1].startY
				<< "," << lines[i-VisionObjectTypes::Line1].endX
				<< "," << lines[i-VisionObjectTypes::Line1].endY << ")\n";
		return result.str();
	}
};
}



#endif /* VisionObjects_DEFINED */
