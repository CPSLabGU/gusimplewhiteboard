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
	char *whiteboard_get(const char *message_type, gu_simple_message *msg)
	{
		return whiteboard_getmsg(types_map[message_type], msg);
	}


	char *whiteboard_getmsg(int message_index, gu_simple_message *msg)
	{
		return gu_strdup(getmsg(WBTypes(message_index), msg).c_str());
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

string guWhiteboard::getmsg(string message_type, gu_simple_message *msg)
{
	return getmsg(types_map[message_type], msg);
}


string guWhiteboard::getmsg(WBTypes message_index, gu_simple_message *msg)
{
	switch (message_index)
	{
		case kwb_reserved_SubscribeToAllTypes_v:
			return "##unsupported##";

		case kPrint_v:
		{
			class Print_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSay_v:
		{
			class Say_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSpeech_v:
		{
			class Speech_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kQSay_v:
		{
			class QSay_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kQSpeech_v:
		{
			class QSpeech_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSpeechOutput_v:
		{
			class SpeechOutput_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kGCGameState_v:
#ifdef GCGameState_DEFINED
		{
			class GCGameState_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !GCGameState_DEFINED

		case kWALK_Command_v:
#ifdef WALK_ControlStatus_DEFINED
		{
			class WALK_Command_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WALK_ControlStatus_DEFINED

		case kWALK_Status_v:
#ifdef WALK_ControlStatus_DEFINED
		{
			class WALK_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WALK_ControlStatus_DEFINED

		case kMOTION_Commands_v:
#ifdef MOTION_Commands_DEFINED
		{
			class MOTION_Commands_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !MOTION_Commands_DEFINED

		case kMOTION_Status_v:
#ifdef MOTION_Status_DEFINED
		{
			class MOTION_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !MOTION_Status_DEFINED

		case kNaoWalk_v:
		{
			class NaoWalk_t m;
			return msg ? intvectostring(m.get_from(msg)) : intvectostring(m.get());
		}
		case kNaoWalkIsRunning_v:
		{
			class NaoWalkIsRunning_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kHeadStiffness_v:
		{
			class HeadStiffness_t m;
			return msg ? gu_dtos(m.get_from(msg)) : gu_dtos(m.get());
		}
		case kHoldingStiffness_v:
		{
			class HoldingStiffness_t m;
			return msg ? gu_dtos(m.get_from(msg)) : gu_dtos(m.get());
		}
		case kGenericAngleChange_v:
		{
			class GenericAngleChange_t m;
			return msg ? intvectostring(m.get_from(msg)) : intvectostring(m.get());
		}
		case kGenericAngleChangeIsRunning_v:
		{
			class GenericAngleChangeIsRunning_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kHAL_HeadTarget_v:
#ifdef HAL_HeadTarget_DEFINED
		{
			class HAL_HeadTarget_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !HAL_HeadTarget_DEFINED

		case kSENSORS_FootSensors_v:
#ifdef SENSORS_FootSensors_DEFINED
		{
			class SENSORS_FootSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_FootSensors_DEFINED

		case kSENSORS_BodySensors_v:
#ifdef SENSORS_BodySensors_DEFINED
		{
			class SENSORS_BodySensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_BodySensors_DEFINED

		case kSENSORS_LedsSensors_v:
#ifdef SENSORS_LedsSensors_DEFINED
		{
			class SENSORS_LedsSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_LedsSensors_DEFINED

		case kSENSORS_LegJointTemps_v:
#ifdef SENSORS_LegJointTemps_DEFINED
		{
			class SENSORS_LegJointTemps_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_LegJointTemps_DEFINED

		case kSENSORS_TorsoJointTemps_v:
#ifdef SENSORS_TorsoJointTemps_DEFINED
		{
			class SENSORS_TorsoJointTemps_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_TorsoJointTemps_DEFINED

		case kSENSORS_LegJointSensors_v:
#ifdef SENSORS_LegJointSensors_DEFINED
		{
			class SENSORS_LegJointSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_LegJointSensors_DEFINED

		case kSENSORS_TorsoJointSensors_v:
#ifdef SENSORS_TorsoJointSensors_DEFINED
		{
			class SENSORS_TorsoJointSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_TorsoJointSensors_DEFINED

		case kSENSORS_SonarSensors_v:
#ifdef SENSORS_SonarSensors_DEFINED
		{
			class SENSORS_SonarSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_SonarSensors_DEFINED

		case kFSM_Control_v:
#ifdef FSMControlStatus_DEFINED
		{
			class FSM_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMControlStatus_DEFINED

		case kFSM_Status_v:
#ifdef FSMControlStatus_DEFINED
		{
			class FSM_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMControlStatus_DEFINED

		case kFSM_Names_v:
#ifdef FSMNames_DEFINED
		{
			class FSM_Names_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMNames_DEFINED

		case kSoloTypeExample_v:
			return "##unsupported##";

		case kBallBelief_v:
#ifdef Point2D_DEFINED
		{
			class BallBelief_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Point2D_DEFINED

		case kFilteredGoalSighting_v:
#ifdef FilteredOneDimObjects_DEFINED
		{
			class FilteredGoalSighting_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FilteredOneDimObjects_DEFINED

		case kNAO_State_v:
#ifdef NAO_State_DEFINED
		{
			class NAO_State_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !NAO_State_DEFINED

		case kUDPRN_v:
#ifdef GCGameState_DEFINED
		{
			class UDPRN_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !GCGameState_DEFINED

		case kPlayerNumber_v:
		{
			class PlayerNumber_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kManuallyPenalized_v:
		{
			class ManuallyPenalized_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kVision_Control_v:
#ifdef VisionControlStatus_DEFINED
		{
			class Vision_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !VisionControlStatus_DEFINED

		case kVision_Status_v:
#ifdef VisionControlStatus_DEFINED
		{
			class Vision_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !VisionControlStatus_DEFINED

		case kVision_Objects_v:
#ifdef VisionObjects_DEFINED
		{
			class Vision_Objects_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !VisionObjects_DEFINED

		case kFSOsighting_v:
#ifdef FilteredSonarObjects_DEFINED
		{
			class FSOsighting_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FilteredSonarObjects_DEFINED

		case kTopParticles_v:
#ifdef TopParticles_DEFINED
		{
			class TopParticles_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !TopParticles_DEFINED

		case kFilteredBallSighting_v:
#ifdef FilteredVisionObject_DEFINED
		{
			class FilteredBallSighting_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FilteredVisionObject_DEFINED

		case kPF_ControlStatus_Modes_v:
		{
			class PF_ControlStatus_Modes_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"

	return "##unsupported##";
#pragma clang diagnostic pop
}

