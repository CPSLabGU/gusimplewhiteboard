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
	/**
	 * @brief Check whether the client has connected. Need a better way of doing this.
     * @return true if connected
     */
	bool connected() {
		return initBit == 1;
	}
	
	/**
	 * @brief set the init bit to connect to a teleoperational robot. Need a better way of doing this.
     */
	void connect() {
		initBit = 1;
	}
	
	/**
	 * @brief Disconnect a teleoperation client
     */
	void disconnect() {
		initBit = 0;
	}
	
	/**Reset the version numbers of the action and stance properties*/
	void resetVersions() {
		reset_action_version();
		reset_stance_version();
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

