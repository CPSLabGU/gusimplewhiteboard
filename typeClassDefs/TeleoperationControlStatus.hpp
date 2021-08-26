/* 
 * File:   TeleoperationControlStatus.h
 * Author: eugene
 *
 * Created on 10 February 2014, 1:44 PM
 */

#ifndef TeleoperationControlStatus_DEFINED
#define	TeleoperationControlStatus_DEFINED

#include "MOTION_Interface.h"
#include "VisionControlStatus.h"
#include "wb_teleoperation.h"
#include <gu_util.h>
namespace guWhiteboard
{
/**
 * @brief Class to teleoperate a robot remotely. 
 * Used to send control messages as well retrieve current status
 * 
 * Examples
 * --------
 * 
 * Make the teleoperation controlled robot stand
 * 
 *		m_pTeleoperationCmd = new TeleoperationControlStatus_t();
 *		TeleoperationControlStatus_t TeleoperationControlStatus command;
 *		command.set_stance(Motions::Standing_stance);
 *		m_pTeleoperationCmd.set(command);
 *		
 */
class TeleoperationControlStatus : public wb_teleoperation {
public:
	/**Default Constructor*/
	TeleoperationControlStatus() {
		VERSION_PROPERTY_INITIALIZATION(action)
		VERSION_PROPERTY_INITIALIZATION(stance)
	}
	
	/**Reset the version numbers of the action and stance properties*/
	void resetVersions() {
		reset_action_version();
		reset_stance_version();
	}
    
    std::string description(){
        std::stringstream desc;
        desc << controlRobot();
        desc << controlNum();
        return desc.str();
    }
    
    void from_string(const std::string &/*str*/) {
        printf("NYI!\n");
    }
	
private:
	/**The action that should be performed*/
	VERSIONED_PROPERTY(guWhiteboard::Motions::action, action)
	/**The stance that should be performed*/
	VERSIONED_PROPERTY(guWhiteboard::Motions::stance, stance)
	/**The streaming type to set on the robot*/
	PROPERTY(StreamingType, streamType)
	/**The camera to stream images from*/
	PROPERTY(VisionCamera, selectedCamera)
};
}
#endif	/* TeleoperationControlStatus_DEFINED */

