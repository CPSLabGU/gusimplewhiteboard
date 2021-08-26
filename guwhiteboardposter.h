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
#include "GCGameState.hpp"
#include "SensorsHandSensors.hpp"
#include "SensorsHeadSensors.hpp"
#include "MOTION_Commands.hpp"
#include "MOTION_Status.hpp"
#include "HAL_HeadTarget.hpp"
#include "SensorsFootSensors.hpp"
#include "SensorsBodySensors.hpp"
#include "SENSORSLedsSensors.hpp"
#include "SENSORSLegJointTemps.hpp"
#include "SENSORSTorsoJointTemps.hpp"
#include "SENSORSLegJointSensors.hpp"
#include "SENSORSTorsoJointSensors.hpp"
#include "SENSORSSonarSensors.hpp"
#include "FSMControlStatus.hpp"
#include "FSMControlStatus.hpp"
#include "FSMNames.hpp"
#include "FilteredArrayOneDimObjects.hpp"
#include "NAO_State.hpp"
#include "GCGameState.hpp"
#include "VisionControlStatus.hpp"
#include "VisionControlStatus.hpp"
#include "FFTStatus.hpp"
#include "FilteredArrayOneDimSonar.hpp"
#include "TopParticles.hpp"
#include "FilteredArrayBallSightings.hpp"
#include "WEBOTS_NXT_bridge.hpp"
#include "WEBOTS_NXT_encoders.hpp"
#include "WEBOTS_NXT_camera.hpp"
#include "WEBOTS_NXT_walk_isRunning.hpp"
#include "WEBOTS_NXT_deadReakoning_walk.hpp"
#include "WEBOTS_NXT_colorLine_walk.hpp"
#include "WEBOTS_NXT_gridMotions.hpp"
#include "VisionBall.hpp"
#include "VisionGoals.hpp"
#include "WalkData.hpp"
#include "TeleoperationControlStatus.hpp"
#include "WEBOTS_NXT_bumper.hpp"
#include "WEBOTS_NXT_vector_bridge.hpp"
#include "VisionLines.hpp"
#include "VisionLines.hpp"
#include "DifferentialRobotControlStatus.hpp"
#include "DifferentialRobotControlStatus.hpp"
#include "Point2D.hpp"
#include "FSMState.hpp"
#include "Giraff_MainSerialInterface.hpp"
#include "Giraff_MainSerialInterface.hpp"
#include "NXT_Interface.hpp"
#include "NXT_Interface.hpp"
#include "APM_Interface.hpp"
#include "APM_Interface.hpp"
#include "OculusPrimeInterface.hpp"
#include "Input3D.hpp"
#include "Oculus_PrimeSerialInterface.hpp"
#include "IOPins.hpp"
#include "NXT_Two_Touch_Status.hpp"
#include "NXT_Sound_Control.hpp"
#include "NXT_Lights_Control.hpp"
#include "Clocks.hpp"
#include "Channels.hpp"
#include "SwitchSubsumption.hpp"
#include "TotoDoingMotion.hpp"
#include "Count.hpp"
#include "SwitchSubsumptionTrafficLights.hpp"
#include "HalArmTarget.hpp"
#include "HalArmTarget.hpp"
#include "HalArmTarget.hpp"
#include "HalArmTarget.hpp"
#include "HalArmTarget.hpp"
#include "HalArmTarget.hpp"
#include "VisionFieldFeatures.hpp"
#include "VisionRobots.hpp"
#include "VisionDetectionHorizons.hpp"
#include "NaoWalkCommand.hpp"
#include "NaoWalkStatus.hpp"
#include "HalLegTarget.hpp"
#include "HalLegTarget.hpp"
#include "HalLegTarget.hpp"
#include "HalLegTarget.hpp"
#include "HalLegTarget.hpp"
#include "HalLegTarget.hpp"
#include "VisionDetectionGoals.hpp"
#include "TeleoperationControl.hpp"
#include "TeleoperationStatus.hpp"
#include "VisionDetectionBalls.hpp"
#include "TeleoperationControlVR.hpp"
#include "MachineFilteredVision.hpp"
#include "MicrowaveStatus.hpp"
#include "Buttons.hpp"
#include "MachineFilteredLocalisationVision.hpp"
#include "NaoJointListFloat.hpp"
#include "DataLogger.hpp"
#include "MachineFilteredLines.hpp"
#include "Location.hpp"
#include "Location.hpp"
#include "Location.hpp"
#include "Location.hpp"
#include "NaoSonarProtectedWalkCommand.hpp"
#include "NaoObstacleDirection.hpp"
#include "DominantFrequencies.hpp"
#include "MissionPriorityForObstacles.hpp"
#include "FrequencyLimits.hpp"
#include "FrequencyLimits.hpp"
#include "HeadJointSensors.hpp"
#include "AdjustPositionConfidence.hpp"
#include "GuVrTeleopVulkanControl.hpp"
#include "TemperatureSensors.hpp"
#include "Overheating.hpp"
#include "BallPosition.hpp"
#include "MemoryImageControlStatus.hpp"
#include "MemoryImageControlStatus.hpp"
#include "MyPosition.hpp"
#include "VisionDetectionLines.hpp"
#include "VisionDetectionFeatures.hpp"

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
