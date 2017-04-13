#ifndef WBTELEOPERATION_
#define WBTELEOPERATION_

#include <sys/types.h>
#include <gu_util.h>

/** struct for the teleoperation class */
struct wb_teleoperation
{
	unsigned initBit : 1; ///< Gross hacky way of detecting a connection
	/** The forward speed */
	PROPERTY(int, fowardWalkSpeed)
	/** Turning speed */
	PROPERTY(float, turnWalkSpeed)
	/** Head pitch controller */
	PROPERTY(float, headPitch)
	/** Head yaw controller */
	PROPERTY(float, headYaw)

#ifdef __cplusplus
	/** default constructor */
	wb_teleoperation() : initBit(0), _fowardWalkSpeed(0), _turnWalkSpeed(0), _headPitch(0), _headYaw(0){}
#endif
};

#endif
