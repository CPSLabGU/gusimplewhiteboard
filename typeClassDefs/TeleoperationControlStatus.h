/* 
 * File:   TeleoperationControlStatus.h
 * Author: eugene
 *
 * Created on 10 February 2014, 1:44 PM
 */

#ifndef TeleoperationControlStatus_DEFINED
#define	TeleoperationControlStatus_DEFINED

#include "MOTION_Interface.h"
#include "Vision_Control.h"
#include <gu_util.h>
namespace guWhiteboard
{
class TeleoperationControlStatus {
public:
	TeleoperationControlStatus() {
		//set_action((Motions::action)-1);
		//set_stance((Motions::stance)-1);
		set_fowardWalkSpeed(0);
		set_headPitch(0.0f);
		set_headYaw(0.0f);
		set_turnWalkSpeed(0.0f);
		initBit = 0;
	}
	bool connected() {
		return initBit == 1;
	}
	
	void connect() {
		initBit = 1;
	}
	
	void disconnect() {
		initBit = 0;
	}
	
	void resetVersions() {
		reset_action_version();
		reset_stance_version();
	}
	
private:
	unsigned initBit : 1;
	PROPERTY(int, fowardWalkSpeed)
	PROPERTY(float, turnWalkSpeed)
	PROPERTY(float, headPitch)
	PROPERTY(float, headYaw)
	VERSIONED_PROPERTY(guWhiteboard::Motions::action, action)
	VERSIONED_PROPERTY(guWhiteboard::Motions::stance, stance)
	PROPERTY(StreamingType, streamType)
	PROPERTY(VisionCamera, selectedCamera)
};
}
#endif	/* TeleoperationControlStatus_DEFINED */

