#ifndef WBTELEOPERATION_
#define WBTELEOPERATION_

#include <sys/types.h>
#include <gu_util.h>

/** struct for the teleoperation class */
struct wb_teleoperation
{
	/** The forward speed */
	PROPERTY(int, fowardWalkSpeed)
	/** Turning speed */
	PROPERTY(float, turnWalkSpeed)
	/** Head pitch controller */
	PROPERTY(float, headPitch)
	/** Head yaw controller */
	PROPERTY(float, headYaw)
        /**Robot to control*/
        STRING_PROPERTY(controlRobot, 8)
    PROPERTY(int, controlNum)

#ifdef __cplusplus
	/** default constructor */
	wb_teleoperation() : _fowardWalkSpeed(0), _turnWalkSpeed(0), _headPitch(0), _headYaw(0), _controlRobot("") {}
#endif
};

#endif
