/**
 *  /file guwhiteboardposter.h
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

#ifndef WB_GUWHITEBOARDPOSTER_H
#define WB_GUWHITEBOARDPOSTER_H

/** Auto-generated, don't modify! */


#ifdef __cplusplus
#include <string>
#include <map>
#include <stdbool.h>

/*
 * Include your classes below if they have description methods and
 * string constructors!
 */
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include "GCGameState.h"
#include "SensorsHandSensors.h"
#include "SensorsHeadSensors.h"
#include "MOTION_Commands.h"
#include "MOTION_Status.h"
#include "HAL_HeadTarget.h"
#include "SensorsFootSensors.h"
#include "SensorsBodySensors.h"
#include "SENSORSLedsSensors.h"
#include "SENSORSLegJointTemps.h"
#include "SENSORSTorsoJointTemps.h"
#include "SENSORSLegJointSensors.h"
#include "SENSORSTorsoJointSensors.h"
#include "SENSORSSonarSensors.h"
#include "FSMControlStatus.h"
#include "FSMControlStatus.h"
#include "FSMNames.h"
#include "FilteredArrayOneDimObjects.h"
#include "NAO_State.h"
#include "GCGameState.h"
#include "VisionControlStatus.h"
#include "VisionControlStatus.h"
#include "FFTStatus.h"
#include "FilteredArrayOneDimSonar.h"
#include "TopParticles.h"
#include "FilteredArrayBallSightings.h"
#include "WEBOTS_NXT_bridge.h"
#include "WEBOTS_NXT_encoders.h"
#include "WEBOTS_NXT_camera.h"
#include "WEBOTS_NXT_walk_isRunning.h"
#include "WEBOTS_NXT_deadReakoning_walk.h"
#include "WEBOTS_NXT_colorLine_walk.h"
#include "WEBOTS_NXT_gridMotions.h"
#include "VisionBall.h"
#include "VisionGoals.h"
#include "WalkData.h"
#include "TeleoperationControlStatus.h"
#include "WEBOTS_NXT_bumper.h"
#include "WEBOTS_NXT_vector_bridge.h"
#include "VisionLines.h"
#include "VisionLines.h"
#include "DifferentialRobotControlStatus.h"
#include "DifferentialRobotControlStatus.h"
#include "Point2D.h"
#include "FSMState.h"
#include "Giraff_MainSerialInterface.h"
#include "Giraff_MainSerialInterface.h"
#include "NXT_Interface.h"
#include "NXT_Interface.h"
#include "APM_Interface.h"
#include "APM_Interface.h"
#include "OculusPrimeInterface.h"
#include "Input3D.h"
#include "Oculus_PrimeSerialInterface.h"
#include "IOPins.h"
#include "NXT_Two_Touch_Status.h"
#include "NXT_Sound_Control.h"
#include "NXT_Lights_Control.h"
#include "Clocks.h"
#include "Channels.h"
#include "SwitchSubsumption.h"
#include "TotoDoingMotion.h"
#include "Count.h"
#include "SwitchSubsumptionTrafficLights.h"
#include "HalArmTarget.h"
#include "HalArmTarget.h"
#include "HalArmTarget.h"
#include "HalArmTarget.h"
#include "HalArmTarget.h"
#include "HalArmTarget.h"
#include "VisionFieldFeatures.h"
#include "VisionRobots.h"
#include "VisionDetectionHorizons.h"
#include "NaoWalkCommand.h"
#include "NaoWalkStatus.h"
#include "HalLegTarget.h"
#include "HalLegTarget.h"
#include "HalLegTarget.h"
#include "HalLegTarget.h"
#include "HalLegTarget.h"
#include "HalLegTarget.h"
#include "VisionDetectionGoals.h"
#include "TeleoperationControl.h"
#include "TeleoperationStatus.h"
#include "VisionDetectionBalls.h"
#include "TeleoperationControlVR.h"
#include "MachineFilteredVision.h"
#include "MicrowaveStatus.h"
#include "Buttons.h"
#include "MachineFilteredLocalisationVision.h"
#include "NaoJointListFloat.h"
#include "DataLogger.h"
#include "MachineFilteredLines.h"
#include "Location.h"
#include "Location.h"
#include "Location.h"
#include "Location.h"
#include "NaoSonarProtectedWalkCommand.h"
#include "NaoObstacleDirection.h"
#include "DominantFrequencies.h"
#include "MissionPriorityForObstacles.h"
#include "FrequencyLimits.h"
#include "FrequencyLimits.h"
#include "HeadJointSensors.h"
#include "AdjustPositionConfidence.h"
#include "GuVrTeleopVulkanControl.h"
#include "TemperatureSensors.h"
#include "Overheating.h"
#include "BallPosition.h"
#include "MemoryImageControlStatus.h"
#include "MemoryImageControlStatus.h"
#include "MyPosition.h"
#include "VisionDetectionLines.h"
#include "VisionDetectionFeatures.h"

#endif // WHITEBOARD_POSTER_STRING_CONVERSION

extern "C"
{
#else
#include <stdbool.h>
#endif // __cplusplus

#include "gusimplewhiteboard.h"
#include "guwhiteboardtypelist_c_generated.h"

/**
 * A generic C function that posts to the whiteboard.
 * Both the message type and the message content are strings.
 */
bool whiteboard_post(const char *message_type, const char *message_content);

/**
 * A generic C function that posts to a given whiteboard.
 * Both the message type and the message content are strings.
 */
bool whiteboard_post_to(gu_simple_whiteboard_descriptor *wbd, const char *message_type, const char *message_content);

/**
 * Generic C function that posts a message with a given message number
 * to the whiteboard.
 */
bool whiteboard_postmsg(int message_index, const char *message_content);

/**
 * Generic C function that posts a message with a given message number
 * to a given whiteboard.
 */
bool whiteboard_postmsg_to(gu_simple_whiteboard_descriptor *wbd, int message_index, const char *message_content);

/**
 * Generic C function that returns the type for a given message name
 */

#ifndef __cplusplus
int whiteboard_type_for_message_named(const char *message_type);
#else
guWhiteboard::wb_types whiteboard_type_for_message_named(const char *message_type);
}

namespace guWhiteboard {

        /**
         * A generic C++ function that posts to the whiteboard.
         * Both the message type and the message content are strings.
         * @param message_type the string version of the type
         * @param message_content the string data to pass to the types string constructor
         * @param wbd whiteboard descriptor (NULLPTR for the default whiteboard)
         * @return true if there is a string constructor for the passed in type
         */
        bool post(std::string message_type, std::string message_content, gu_simple_whiteboard_descriptor *wbd = NULLPTR);

        /**
         * Generic C++ function that posts a message with a given message number
         * to the whiteboard.
         * @param message_index the offset or enum value of the type to post
         * @param message_content the string data to pass to the types string constructor
         * @param wbd whiteboard descriptor (NULLPTR for the default whiteboard)
         * @return true if there is a string constructor for the passed in type
         */
        bool postmsg(guWhiteboard::wb_types message_index, std::string message_content, gu_simple_whiteboard_descriptor *wbd = NULLPTR);

        /**
         * Map structure from strings to message types
         */
        struct whiteboard_types_map: public std::map<std::string, guWhiteboard::wb_types>
        {
                whiteboard_types_map(); ///< default constructor
        };

        /**
         * Global map from names to message types
         */
        extern struct whiteboard_types_map types_map;
} // guWhiteboard

#endif // __cplusplus

#endif //WB_GUWHITEBOARDPOSTER_H
