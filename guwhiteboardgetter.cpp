/** Auto-generated, don't modify! */

#include <string>
#include <vector>
#include <cstdlib>

#define WHITEBOARD_POSTER_STRING_CONVERSION

#include "guwhiteboardtypelist_generated.h"
#include "guwhiteboardgetter.h"

using namespace std;
using namespace guWhiteboard;

extern "C"
{
	char *whiteboard_get(const char *message_type)
	{
		return whiteboard_getmsg(types_map[message_type]);
	}


	char *whiteboard_getmsg(int message_index)
	{
		return gu_strdup(getmsg(WBTypes(message_index)).c_str());
	}
} // extern C

static string intvectostring(const vector<int> &vec)
{
	stringstream ss;
	
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it != vec.begin()) ss << ",";
		ss << *it;
	}

	return ss.str();
}

string guWhiteboard::getmsg(string message_type)
{
	return getmsg(types_map[message_type]);
}


string guWhiteboard::getmsg(WBTypes message_index)
{
	switch (message_index)
	{
		case kwb_reserved_SubscribeToAllTypes_v:
			throw "noclass";

		case kPrint_v:
		{
			class Print_t msg;
			return msg.get();
		}
		case kSay_v:
		{
			class Say_t msg;
			return msg.get();
		}
		case kSpeech_v:
		{
			class Speech_t msg;
			return msg.get();
		}
		case kQSay_v:
		{
			class QSay_t msg;
			return msg.get();
		}
		case kQSpeech_v:
		{
			class QSpeech_t msg;
			return msg.get();
		}
		case kSpeechOutput_v:
		{
			class SpeechOutput_t msg;
			return gu_ltos(long(msg.get()));
		}
		case kBoolExample_v:
		{
			class BoolExample_t msg;
			return gu_ltos(long(msg.get()));
		}
		case kCustomClassExample_v:
#ifdef CustClass_DEFINED
		{
			class CustomClassExample_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !CustClass_DEFINED

		case kSoloTypeExample_v:
			throw "noclass";

		case kMOTION_SDK_Commands_v:
#ifdef MOTION_SDK_Interface_DEFINED
		{
			class MOTION_SDK_Commands_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !MOTION_SDK_Interface_DEFINED

		case kMOTION_SDK_Status_v:
#ifdef MOTION_SDK_Interface_DEFINED
		{
			class MOTION_SDK_Status_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !MOTION_SDK_Interface_DEFINED

		case kNaoWalk_v:
		{
			class NaoWalk_t msg;
			return intvectostring(msg.get());
		}
		case kNaoWalkIsRunning_v:
		{
			class NaoWalkIsRunning_t msg;
			return gu_ltos(long(msg.get()));
		}
		case kHeadStiffness_v:
		{
			class HeadStiffness_t msg;
			return gu_dtos(msg.get());
		}
		case kHoldingStiffness_v:
		{
			class HoldingStiffness_t msg;
			return gu_dtos(msg.get());
		}
		case kGenericAngleChange_v:
		{
			class GenericAngleChange_t msg;
			return intvectostring(msg.get());
		}
		case kGenericAngleChangeIsRunning_v:
		{
			class GenericAngleChangeIsRunning_t msg;
			return gu_ltos(long(msg.get()));
		}
		case kHAL_HeadTarget_v:
#ifdef HAL_HeadTarget_DEFINED
		{
			class HAL_HeadTarget_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !HAL_HeadTarget_DEFINED

		case kSENSORS_FootSensors_v:
#ifdef SENSORS_FootSensors_DEFINED
		{
			class SENSORS_FootSensors_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !SENSORS_FootSensors_DEFINED

		case kSENSORS_BodySensors_v:
#ifdef SENSORS_BodySensors_DEFINED
		{
			class SENSORS_BodySensors_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !SENSORS_BodySensors_DEFINED

		case kSENSORS_LedsSensors_v:
#ifdef SENSORS_LedsSensors_DEFINED
		{
			class SENSORS_LedsSensors_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !SENSORS_LedsSensors_DEFINED

		case kSENSORS_LegJointTemps_v:
#ifdef SENSORS_LegJointTemps_DEFINED
		{
			class SENSORS_LegJointTemps_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !SENSORS_LegJointTemps_DEFINED

		case kSENSORS_TorsoJointTemps_v:
#ifdef SENSORS_TorsoJointTemps_DEFINED
		{
			class SENSORS_TorsoJointTemps_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !SENSORS_TorsoJointTemps_DEFINED

		case kSENSORS_LegJointSensors_v:
#ifdef SENSORS_LegJointSensors_DEFINED
		{
			class SENSORS_LegJointSensors_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !SENSORS_LegJointSensors_DEFINED

		case kSENSORS_TorsoJointSensors_v:
#ifdef SENSORS_TorsoJointSensors_DEFINED
		{
			class SENSORS_TorsoJointSensors_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !SENSORS_TorsoJointSensors_DEFINED

		case kSENSORS_SonarSensors_v:
#ifdef SENSORS_SonarSensors_DEFINED
		{
			class SENSORS_SonarSensors_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !SENSORS_SonarSensors_DEFINED

		case kFSM_Control_v:
#ifdef FSMControlStatus_DEFINED
		{
			class FSM_Control_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !FSMControlStatus_DEFINED

		case kFSM_Status_v:
#ifdef FSMControlStatus_DEFINED
		{
			class FSM_Status_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !FSMControlStatus_DEFINED

		case kFSM_Names_v:
#ifdef FSMNames_DEFINED
		{
			class FSM_Names_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !FSMNames_DEFINED

		case kWALK_Status_v:
#ifdef WALK_Status_DEFINED
		{
			class WALK_Status_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !WALK_Status_DEFINED

		case kBallBelief_v:
#ifdef Point2D_DEFINED
		{
			class BallBelief_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !Point2D_DEFINED

		case kFVOsighting_v:
#ifdef FilteredVisionObject_DEFINED
		{
			class FVOsighting_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !FilteredVisionObject_DEFINED

		case kNAO_State_v:
#ifdef NAO_State_DEFINED
		{
			class NAO_State_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !NAO_State_DEFINED

		case kUDPRN_v:
#ifdef UDPReceiverNotification_DEFINED
		{
			class UDPRN_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !UDPReceiverNotification_DEFINED

		case kPlayerNumber_v:
		{
			class PlayerNumber_t msg;
			return gu_ltos(long(msg.get()));
		}
		case kManuallyPenalized_v:
		{
			class ManuallyPenalized_t msg;
			return gu_ltos(long(msg.get()));
		}
		case kVision_Control_v:
#ifdef VisionControlStatus_DEFINED
		{
			class Vision_Control_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !VisionControlStatus_DEFINED

		case kVision_Status_v:
#ifdef VisionControlStatus_DEFINED
		{
			class Vision_Status_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !VisionControlStatus_DEFINED

		case kVision_Objects_v:
#ifdef VisionObjects_DEFINED
		{
			class Vision_Objects_t msg;
			return msg.get().description();
		}
#else
			throw "noclass";

#endif // !VisionObjects_DEFINED

	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"

	throw "noclass";
#pragma clang diagnostic pop
}

