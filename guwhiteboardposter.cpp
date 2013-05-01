/** Auto-generated, don't modify! */

#include <string>
#include <vector>
#include <cstdlib>

#define WHITEBOARD_POSTER_STRING_CONVERSION

#include "guwhiteboardtypelist_generated.h"
#include "guwhiteboardposter.h"

using namespace std;
using namespace guWhiteboard;

extern "C"
{
	WBTypes whiteboard_type_for_message_named(const char *message_type)
	{
		return types_map[message_type];
	}


	bool whiteboard_post(const char *message_type, const char *message_content)
	{
		return whiteboard_postmsg(types_map[message_type], message_content);
	}


	bool whiteboard_postmsg(int message_index, const char *message_content)
	{
		return postmsg(WBTypes(message_index), message_content);
	}
} // extern C

static vector<int> strtointvec(string str)
{
	const char *sep = "|,";
	char *context = NULL;
	vector<int> array;
	for (char *element = strtok_r((char *)str.c_str(), sep, &context); element; element = strtok_r(NULL, sep, &context))
		array.push_back(atoi(element));
	return array;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wexit-time-destructors"

whiteboard_types_map guWhiteboard::types_map; ///< global types map

#pragma clang diagnostic pop

bool guWhiteboard::post(string message_type, string message_content)
{
	return postmsg(types_map[message_type], message_content);
}


bool guWhiteboard::postmsg(WBTypes message_index, std::string message_content)
{
	switch (message_index)
	{
		case kwb_reserved_SubscribeToAllTypes_v:
			return false;

		case kPrint_v:
		{
			class Print_t Print_msg;
			Print_msg.post(std::string(message_content));
			return true;
		}
		case kSay_v:
		{
			class Say_t Say_msg;
			Say_msg.post(std::string(message_content));
			return true;
		}
		case kSpeech_v:
		{
			class Speech_t Speech_msg;
			Speech_msg.post(std::string(message_content));
			return true;
		}
		case kQSay_v:
		{
			class QSay_t QSay_msg;
			QSay_msg.post(std::string(message_content));
			return true;
		}
		case kQSpeech_v:
		{
			class QSpeech_t QSpeech_msg;
			QSpeech_msg.post(std::string(message_content));
			return true;
		}
		case kSpeechOutput_v:
		{
			class SpeechOutput_t SpeechOutput_msg;
			SpeechOutput_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kBoolExample_v:
		{
			class BoolExample_t BoolExample_msg;
			BoolExample_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kWALK_Command_v:
#ifdef WALK_ControlStatus_DEFINED
		{
			class WALK_Command_t WALK_Command_msg;
			WALK_Command_msg.post(WALK_ControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !WALK_ControlStatus_DEFINED

		case kWALK_Status_v:
#ifdef WALK_ControlStatus_DEFINED
		{
			class WALK_Status_t WALK_Status_msg;
			WALK_Status_msg.post(WALK_ControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !WALK_ControlStatus_DEFINED

		case kMOTION_SDK_Commands_v:
#ifdef MOTION_SDK_Interface_DEFINED
		{
			class MOTION_SDK_Commands_t MOTION_SDK_Commands_msg;
			MOTION_SDK_Commands_msg.post(MOTION_SDK_Interface(message_content));
			return true;
		}
#else
			return false;
#endif // !MOTION_SDK_Interface_DEFINED

		case kMOTION_SDK_Status_v:
#ifdef MOTION_SDK_Interface_DEFINED
		{
			class MOTION_SDK_Status_t MOTION_SDK_Status_msg;
			MOTION_SDK_Status_msg.post(MOTION_SDK_Interface(message_content));
			return true;
		}
#else
			return false;
#endif // !MOTION_SDK_Interface_DEFINED

		case kNaoWalk_v:
		{
			class NaoWalk_t NaoWalk_msg(strtointvec(message_content));
			(void)NaoWalk_msg;
			return true;
		}

		case kNaoWalkIsRunning_v:
		{
			class NaoWalkIsRunning_t NaoWalkIsRunning_msg;
			NaoWalkIsRunning_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kHeadStiffness_v:
		{
			class HeadStiffness_t HeadStiffness_msg;
			HeadStiffness_msg.post(float(atof(message_content.c_str())));
			return true;
		}

		case kHoldingStiffness_v:
		{
			class HoldingStiffness_t HoldingStiffness_msg;
			HoldingStiffness_msg.post(float(atof(message_content.c_str())));
			return true;
		}

		case kGenericAngleChange_v:
		{
			class GenericAngleChange_t GenericAngleChange_msg(strtointvec(message_content));
			(void)GenericAngleChange_msg;
			return true;
		}

		case kGenericAngleChangeIsRunning_v:
		{
			class GenericAngleChangeIsRunning_t GenericAngleChangeIsRunning_msg;
			GenericAngleChangeIsRunning_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kHAL_HeadTarget_v:
#ifdef HAL_HeadTarget_DEFINED
		{
			class HAL_HeadTarget_t HAL_HeadTarget_msg;
			HAL_HeadTarget_msg.post(HAL_HeadTarget(message_content));
			return true;
		}
#else
			return false;
#endif // !HAL_HeadTarget_DEFINED

		case kSENSORS_FootSensors_v:
#ifdef SENSORS_FootSensors_DEFINED
		{
			class SENSORS_FootSensors_t SENSORS_FootSensors_msg;
			SENSORS_FootSensors_msg.post(SENSORS_FootSensors(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_FootSensors_DEFINED

		case kSENSORS_BodySensors_v:
#ifdef SENSORS_BodySensors_DEFINED
		{
			class SENSORS_BodySensors_t SENSORS_BodySensors_msg;
			SENSORS_BodySensors_msg.post(SENSORS_BodySensors(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_BodySensors_DEFINED

		case kSENSORS_LedsSensors_v:
#ifdef SENSORS_LedsSensors_DEFINED
		{
			class SENSORS_LedsSensors_t SENSORS_LedsSensors_msg;
			SENSORS_LedsSensors_msg.post(SENSORS_LedsSensors(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_LedsSensors_DEFINED

		case kSENSORS_LegJointTemps_v:
#ifdef SENSORS_LegJointTemps_DEFINED
		{
			class SENSORS_LegJointTemps_t SENSORS_LegJointTemps_msg;
			SENSORS_LegJointTemps_msg.post(SENSORS_LegJointTemps(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_LegJointTemps_DEFINED

		case kSENSORS_TorsoJointTemps_v:
#ifdef SENSORS_TorsoJointTemps_DEFINED
		{
			class SENSORS_TorsoJointTemps_t SENSORS_TorsoJointTemps_msg;
			SENSORS_TorsoJointTemps_msg.post(SENSORS_TorsoJointTemps(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_TorsoJointTemps_DEFINED

		case kSENSORS_LegJointSensors_v:
#ifdef SENSORS_LegJointSensors_DEFINED
		{
			class SENSORS_LegJointSensors_t SENSORS_LegJointSensors_msg;
			SENSORS_LegJointSensors_msg.post(SENSORS_LegJointSensors(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_LegJointSensors_DEFINED

		case kSENSORS_TorsoJointSensors_v:
#ifdef SENSORS_TorsoJointSensors_DEFINED
		{
			class SENSORS_TorsoJointSensors_t SENSORS_TorsoJointSensors_msg;
			SENSORS_TorsoJointSensors_msg.post(SENSORS_TorsoJointSensors(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_TorsoJointSensors_DEFINED

		case kSENSORS_SonarSensors_v:
#ifdef SENSORS_SonarSensors_DEFINED
		{
			class SENSORS_SonarSensors_t SENSORS_SonarSensors_msg;
			SENSORS_SonarSensors_msg.post(SENSORS_SonarSensors(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_SonarSensors_DEFINED

		case kFSM_Control_v:
#ifdef FSMControlStatus_DEFINED
		{
			class FSM_Control_t FSM_Control_msg;
			FSM_Control_msg.post(FSMControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMControlStatus_DEFINED

		case kFSM_Status_v:
#ifdef FSMControlStatus_DEFINED
		{
			class FSM_Status_t FSM_Status_msg;
			FSM_Status_msg.post(FSMControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMControlStatus_DEFINED

		case kFSM_Names_v:
#ifdef FSMNames_DEFINED
		{
			class FSM_Names_t FSM_Names_msg;
			FSM_Names_msg.post(FSMNames(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMNames_DEFINED

		case kSoloTypeExample_v:
			return false;

		case kBallBelief_v:
#ifdef Point2D_DEFINED
		{
			class BallBelief_t BallBelief_msg;
			BallBelief_msg.post(Point2D(message_content));
			return true;
		}
#else
			return false;
#endif // !Point2D_DEFINED

		case kFVOsighting_v:
#ifdef FilteredVisionObject_DEFINED
		{
			class FVOsighting_t FVOsighting_msg;
			FVOsighting_msg.post(FilteredVisionObject(message_content));
			return true;
		}
#else
			return false;
#endif // !FilteredVisionObject_DEFINED

		case kNAO_State_v:
#ifdef NAO_State_DEFINED
		{
			class NAO_State_t NAO_State_msg;
			NAO_State_msg.post(NAO_State(message_content));
			return true;
		}
#else
			return false;
#endif // !NAO_State_DEFINED

		case kUDPRN_v:
#ifdef UDPReceiverNotification_DEFINED
		{
			class UDPRN_t UDPRN_msg;
			UDPRN_msg.post(UDPReceiverNotification(message_content));
			return true;
		}
#else
			return false;
#endif // !UDPReceiverNotification_DEFINED

		case kPlayerNumber_v:
		{
			class PlayerNumber_t PlayerNumber_msg;
			PlayerNumber_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kManuallyPenalized_v:
		{
			class ManuallyPenalized_t ManuallyPenalized_msg;
			ManuallyPenalized_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kVision_Control_v:
#ifdef VisionControlStatus_DEFINED
		{
			class Vision_Control_t Vision_Control_msg;
			Vision_Control_msg.post(VisionControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !VisionControlStatus_DEFINED

		case kVision_Status_v:
#ifdef VisionControlStatus_DEFINED
		{
			class Vision_Status_t Vision_Status_msg;
			Vision_Status_msg.post(VisionControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !VisionControlStatus_DEFINED

		case kVision_Objects_v:
#ifdef VisionObjects_DEFINED
		{
			class Vision_Objects_t Vision_Objects_msg;
			Vision_Objects_msg.post(VisionObjects(message_content));
			return true;
		}
#else
			return false;
#endif // !VisionObjects_DEFINED

	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"

	return false;
#pragma clang diagnostic pop
}

whiteboard_types_map::whiteboard_types_map(): map<string, WBTypes>()
{
	whiteboard_types_map &self = *this;
	// self.reserve(40);

	self["*"] = kwb_reserved_SubscribeToAllTypes_v;
	self["Print"] = kPrint_v;
	self["Say"] = kSay_v;
	self["Speech"] = kSpeech_v;
	self["QSay"] = kQSay_v;
	self["QSpeech"] = kQSpeech_v;
	self["SpeechOutput"] = kSpeechOutput_v;
	self["example_bool"] = kBoolExample_v;
	self["WALK_Command"] = kWALK_Command_v;
	self["WALK_Status"] = kWALK_Status_v;
	self["MOTION_SDK_Commands"] = kMOTION_SDK_Commands_v;
	self["MOTION_SDK_Status"] = kMOTION_SDK_Status_v;
	self["gunaomotion_naoWalk"] = kNaoWalk_v;
	self["gunaomotion_naoWalkIsRunning"] = kNaoWalkIsRunning_v;
	self["gunaomotion_headStiffness"] = kHeadStiffness_v;
	self["gunaomotion_holdingStiffness"] = kHoldingStiffness_v;
	self["gunaomotion_genericAngleChange"] = kGenericAngleChange_v;
	self["gunaomotion_genericAngleChangeIsRunning"] = kGenericAngleChangeIsRunning_v;
	self["HAL_HeadTarget"] = kHAL_HeadTarget_v;
	self["SENSORS_FootSensors"] = kSENSORS_FootSensors_v;
	self["SENSORS_BodySensors"] = kSENSORS_BodySensors_v;
	self["SENSORS_LedsSensors"] = kSENSORS_LedsSensors_v;
	self["SENSORS_LegJointTemps"] = kSENSORS_LegJointTemps_v;
	self["SENSORS_TorsoJointTemps"] = kSENSORS_TorsoJointTemps_v;
	self["SENSORS_LegJointSensors"] = kSENSORS_LegJointSensors_v;
	self["SENSORS_TorsoJointSensors"] = kSENSORS_TorsoJointSensors_v;
	self["SENSORS_SonarSensors"] = kSENSORS_SonarSensors_v;
	self["fsm_control"] = kFSM_Control_v;
	self["fsm_status"] = kFSM_Status_v;
	self["fsm_names"] = kFSM_Names_v;
	self["example_type"] = kSoloTypeExample_v;
	self["BallBelief"] = kBallBelief_v;
	self["FVOsighting"] = kFVOsighting_v;
	self["NAO_State"] = kNAO_State_v;
	self["UDPReceiverNotification"] = kUDPRN_v;
	self["PlayerNumber"] = kPlayerNumber_v;
	self["PlayerNumber"] = kManuallyPenalized_v;
	self["guvision_control"] = kVision_Control_v;
	self["guvision_status"] = kVision_Status_v;
	self["guvision_objects"] = kVision_Objects_v;
}

