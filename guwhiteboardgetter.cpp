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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
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
#pragma clang diagnostic pop

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
/** WB Ptr Class: Print @brief Nil */ 
			class Print_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSay_v:
		{
/** WB Ptr Class: Say @brief Nil */ 
			class Say_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSpeech_v:
		{
/** WB Ptr Class: Speech @brief Nil */ 
			class Speech_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kQSay_v:
		{
/** WB Ptr Class: QSay @brief Nil */ 
			class QSay_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kQSpeech_v:
		{
/** WB Ptr Class: QSpeech @brief Nil */ 
			class QSpeech_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSpeechOutput_v:
		{
/** WB Ptr Class: SpeechOutput @brief Nil */ 
			class SpeechOutput_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kGCGameState_v:
#ifdef GCGameState_DEFINED
		{
/** WB Ptr Class: GCGameState @brief Nil */ 
			class GCGameState_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !GCGameState_DEFINED

		case kWALK_Command_v:
#ifdef WALK_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK_Command @brief Nil */ 
			class WALK_Command_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WALK_ControlStatus_DEFINED

		case kWALK_Status_v:
#ifdef WALK_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK_Status @brief Nil */ 
			class WALK_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WALK_ControlStatus_DEFINED

		case kMOTION_Commands_v:
#ifdef MOTION_Commands_DEFINED
		{
/** WB Ptr Class: MOTION_Commands @brief Nil */ 
			class MOTION_Commands_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !MOTION_Commands_DEFINED

		case kMOTION_Status_v:
#ifdef MOTION_Status_DEFINED
		{
/** WB Ptr Class: MOTION_Status @brief Nil */ 
			class MOTION_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !MOTION_Status_DEFINED

		case kHAL_HeadTarget_v:
#ifdef HAL_HeadTarget_DEFINED
		{
/** WB Ptr Class: HAL_HeadTarget @brief Nil */ 
			class HAL_HeadTarget_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !HAL_HeadTarget_DEFINED

		case kSENSORSFootSensors_v:
#ifdef SENSORSFootSensors_DEFINED
		{
/** WB Ptr Class: SENSORSFootSensors @brief Nil */ 
			class SENSORSFootSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORSFootSensors_DEFINED

		case kSENSORSBodySensors_v:
#ifdef SENSORSBodySensors_DEFINED
		{
/** WB Ptr Class: SENSORSBodySensors @brief Nil */ 
			class SENSORSBodySensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORSBodySensors_DEFINED

		case kSENSORSLedsSensors_v:
#ifdef SENSORSLedsSensors_DEFINED
		{
/** WB Ptr Class: SENSORSLedsSensors @brief Nil */ 
			class SENSORSLedsSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORSLedsSensors_DEFINED

		case kSENSORSLegJointTemps_v:
#ifdef SENSORSLegJointTemps_DEFINED
		{
/** WB Ptr Class: SENSORSLegJointTemps @brief Nil */ 
			class SENSORSLegJointTemps_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORSLegJointTemps_DEFINED

		case kSENSORSTorsoJointTemps_v:
#ifdef SENSORSTorsoJointTemps_DEFINED
		{
/** WB Ptr Class: SENSORSTorsoJointTemps @brief Nil */ 
			class SENSORSTorsoJointTemps_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORSTorsoJointTemps_DEFINED

		case kSENSORSLegJointSensors_v:
#ifdef SENSORSLegJointSensors_DEFINED
		{
/** WB Ptr Class: SENSORSLegJointSensors @brief Nil */ 
			class SENSORSLegJointSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORSLegJointSensors_DEFINED

		case kSENSORSTorsoJointSensors_v:
#ifdef SENSORSTorsoJointSensors_DEFINED
		{
/** WB Ptr Class: SENSORSTorsoJointSensors @brief Nil */ 
			class SENSORSTorsoJointSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORSTorsoJointSensors_DEFINED

		case kSENSORSSonarSensors_v:
#ifdef SENSORSSonarSensors_DEFINED
		{
/** WB Ptr Class: SENSORSSonarSensors @brief Nil */ 
			class SENSORSSonarSensors_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORSSonarSensors_DEFINED

		case kFSM_Control_v:
#ifdef FSMControlStatus_DEFINED
		{
/** WB Ptr Class: FSM_Control @brief Nil */ 
			class FSM_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMControlStatus_DEFINED

		case kFSM_Status_v:
#ifdef FSMControlStatus_DEFINED
		{
/** WB Ptr Class: FSM_Status @brief Nil */ 
			class FSM_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMControlStatus_DEFINED

		case kFSM_Names_v:
#ifdef FSMNames_DEFINED
		{
/** WB Ptr Class: FSM_Names @brief Nil */ 
			class FSM_Names_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMNames_DEFINED

		case kSoloTypeExample_v:
			return "##unsupported##";

		case kFilteredGoalSighting_v:
#ifdef FilteredArrayOneDimObjects_DEFINED
		{
/** WB Ptr Class: FilteredGoalSighting @brief Nil */ 
			class FilteredGoalSighting_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FilteredArrayOneDimObjects_DEFINED

		case kNAO_State_v:
#ifdef NAO_State_DEFINED
		{
/** WB Ptr Class: NAO_State @brief Nil */ 
			class NAO_State_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !NAO_State_DEFINED

		case kUDPRN_v:
#ifdef GCGameState_DEFINED
		{
/** WB Ptr Class: UDPRN @brief Nil */ 
			class UDPRN_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !GCGameState_DEFINED

		case kPlayerNumber_v:
		{
/** WB Ptr Class: PlayerNumber @brief Nil */ 
			class PlayerNumber_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kManuallyPenalized_v:
		{
/** WB Ptr Class: ManuallyPenalized @brief Nil */ 
			class ManuallyPenalized_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kVision_Control_v:
#ifdef VisionControlStatus_DEFINED
		{
/** WB Ptr Class: Vision_Control @brief Nil */ 
			class Vision_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !VisionControlStatus_DEFINED

		case kVision_Status_v:
#ifdef VisionControlStatus_DEFINED
		{
/** WB Ptr Class: Vision_Status @brief Nil */ 
			class Vision_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !VisionControlStatus_DEFINED

		case kFFTStatus_v:
#ifdef FFTStatus_DEFINED
		{
/** WB Ptr Class: FFTStatus @brief Nil */ 
			class FFTStatus_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FFTStatus_DEFINED

		case kFSOsighting_v:
#ifdef FilteredArrayOneDimSonar_DEFINED
		{
/** WB Ptr Class: FSOsighting @brief Nil */ 
			class FSOsighting_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FilteredArrayOneDimSonar_DEFINED

		case kTopParticles_v:
#ifdef TopParticles_DEFINED
		{
/** WB Ptr Class: TopParticles @brief Nil */ 
			class TopParticles_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !TopParticles_DEFINED

		case kFilteredBallSighting_v:
#ifdef FilteredArrayOneDimBall_DEFINED
		{
/** WB Ptr Class: FilteredBallSighting @brief Nil */ 
			class FilteredBallSighting_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FilteredArrayOneDimBall_DEFINED

		case kPF_ControlStatus_Modes_v:
		{
/** WB Ptr Class: PF_ControlStatus_Modes @brief Nil */ 
			class PF_ControlStatus_Modes_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kWEBOTS_NXT_bridge_v:
#ifdef WEBOTS_NXT_bridge_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_bridge @brief Nil */ 
			class WEBOTS_NXT_bridge_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_bridge_DEFINED

		case kWEBOTS_NXT_encoders_v:
#ifdef WEBOTS_NXT_encoders_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_encoders @brief Nil */ 
			class WEBOTS_NXT_encoders_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_encoders_DEFINED

		case kWEBOTS_NXT_camera_v:
#ifdef WEBOTS_NXT_camera_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_camera @brief Nil */ 
			class WEBOTS_NXT_camera_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_camera_DEFINED

		case kWEBOTS_NXT_walk_isRunning_v:
#ifdef WEBOTS_NXT_walk_isRunning_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_walk_isRunning @brief Nil */ 
			class WEBOTS_NXT_walk_isRunning_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_walk_isRunning_DEFINED

		case kWEBOTS_NXT_deadReakoning_walk_v:
#ifdef WEBOTS_NXT_deadReakoning_walk_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_deadReakoning_walk @brief Nil */ 
			class WEBOTS_NXT_deadReakoning_walk_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_deadReakoning_walk_DEFINED

		case kWEBOTS_NXT_colorLine_walk_v:
#ifdef WEBOTS_NXT_colorLine_walk_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_colorLine_walk @brief Nil */ 
			class WEBOTS_NXT_colorLine_walk_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_colorLine_walk_DEFINED

		case kWEBOTS_NXT_gridMotions_v:
#ifdef WEBOTS_NXT_gridMotions_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_gridMotions @brief Nil */ 
			class WEBOTS_NXT_gridMotions_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_gridMotions_DEFINED

		case kVisionBall_v:
#ifdef VisionBall_DEFINED
		{
/** WB Ptr Class: VisionBall @brief Nil */ 
			class VisionBall_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !VisionBall_DEFINED

		case kVisionGoals_v:
#ifdef VisionGoals_DEFINED
		{
/** WB Ptr Class: VisionGoals @brief Nil */ 
			class VisionGoals_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !VisionGoals_DEFINED

		case kWalkData_v:
#ifdef WalkData_DEFINED
		{
/** WB Ptr Class: WalkData @brief Nil */ 
			class WalkData_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WalkData_DEFINED

		case kTeleoperationControlStatus_v:
#ifdef TeleoperationControlStatus_DEFINED
		{
/** WB Ptr Class: TeleoperationControlStatus @brief Nil */ 
			class TeleoperationControlStatus_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !TeleoperationControlStatus_DEFINED

		case kTeleoperationConnection_v:
		{
/** WB Ptr Class: TeleoperationConnection @brief Nil */ 
			class TeleoperationConnection_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kUDPWBNumber_v:
		{
/** WB Ptr Class: UDPWBNumber @brief Nil */ 
			class UDPWBNumber_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kWEBOTS_NXT_bumper_v:
#ifdef WEBOTS_NXT_bumper_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_bumper @brief Nil */ 
			class WEBOTS_NXT_bumper_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_bumper_DEFINED

		case kWEBOTS_NXT_vector_bridge_v:
#ifdef WEBOTS_NXT_vector_bridge_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_vector_bridge @brief Nil */ 
			class WEBOTS_NXT_vector_bridge_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WEBOTS_NXT_vector_bridge_DEFINED

		case kVisionLines_v:
#ifdef VisionLines_DEFINED
		{
/** WB Ptr Class: VisionLines @brief Nil */ 
			class VisionLines_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !VisionLines_DEFINED

		case kDifferentialRobotStatus_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotStatus @brief Nil */ 
			class DifferentialRobotStatus_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !DifferentialRobotControlStatus_DEFINED

		case kDifferentialRobotControl_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotControl @brief Nil */ 
			class DifferentialRobotControl_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !DifferentialRobotControlStatus_DEFINED

		case kXEyesPos_v:
#ifdef Point2D_DEFINED
		{
/** WB Ptr Class: XEyesPos @brief Nil */ 
			class XEyesPos_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Point2D_DEFINED

		case kVisionFace_v:
		{
/** WB Ptr Class: VisionFace @brief Nil */ 
			class VisionFace_t m;
			return msg ? intvectostring(m.get_from(msg)) : intvectostring(m.get());
		}
		case kDraw_v:
		{
/** WB Ptr Class: Draw @brief Nil */ 
			class Draw_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kFSM_States_v:
#ifdef FSMState_DEFINED
		{
/** WB Ptr Class: FSM_States @brief Nil */ 
			class FSM_States_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMState_DEFINED

		case kGiraff_Interface_Status_v:
#ifdef Giraff_MainSerialInterface_DEFINED
		{
/** WB Ptr Class: Giraff_Interface_Status @brief Nil */ 
			class Giraff_Interface_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Giraff_MainSerialInterface_DEFINED

		case kGiraff_Interface_Command_v:
#ifdef Giraff_MainSerialInterface_DEFINED
		{
/** WB Ptr Class: Giraff_Interface_Command @brief Nil */ 
			class Giraff_Interface_Command_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Giraff_MainSerialInterface_DEFINED

		case kNXT_Status_v:
#ifdef NXT_Interface_DEFINED
		{
/** WB Ptr Class: NXT_Status @brief Nil */ 
			class NXT_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !NXT_Interface_DEFINED

		case kNXT_Command_v:
#ifdef NXT_Interface_DEFINED
		{
/** WB Ptr Class: NXT_Command @brief Nil */ 
			class NXT_Command_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !NXT_Interface_DEFINED

		case kAPM_Status_v:
#ifdef APM_Interface_DEFINED
		{
/** WB Ptr Class: APM_Status @brief Nil */ 
			class APM_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !APM_Interface_DEFINED

		case kAPM_Command_v:
#ifdef APM_Interface_DEFINED
		{
/** WB Ptr Class: APM_Command @brief Nil */ 
			class APM_Command_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !APM_Interface_DEFINED

		case kWALK2014_Command_v:
#ifdef WALK2014_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK2014_Command @brief Nil */ 
			class WALK2014_Command_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WALK2014_ControlStatus_DEFINED

		case kWALK2014_Status_v:
#ifdef WALK2014_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK2014_Status @brief Nil */ 
			class WALK2014_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !WALK2014_ControlStatus_DEFINED

		case kCBall_v:
		{
/** WB Ptr Class: CBall @brief Nil */ 
			class CBall_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kOculusPrime_Command_v:
#ifdef OculusPrimeInterface_DEFINED
		{
/** WB Ptr Class: OculusPrime_Command @brief Nil */ 
			class OculusPrime_Command_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !OculusPrimeInterface_DEFINED

		case kInput3D_v:
#ifdef Input3D_DEFINED
		{
/** WB Ptr Class: Input3D @brief Nil */ 
			class Input3D_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Input3D_DEFINED

		case kOculus_Prime_Command_v:
#ifdef Oculus_PrimeSerialInterface_DEFINED
		{
/** WB Ptr Class: Oculus_Prime_Command @brief Nil */ 
			class Oculus_Prime_Command_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Oculus_PrimeSerialInterface_DEFINED

		case kIOPins_v:
#ifdef IOPins_DEFINED
		{
/** WB Ptr Class: IOPins @brief Nil */ 
			class IOPins_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !IOPins_DEFINED

		case kNXT_Two_Touch_Status_v:
#ifdef NXT_Two_Touch_Status_DEFINED
		{
/** WB Ptr Class: NXT_Two_Touch_Status @brief Nil */ 
			class NXT_Two_Touch_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !NXT_Two_Touch_Status_DEFINED

		case kNXT_Sound_Control_v:
#ifdef NXT_Sound_Control_DEFINED
		{
/** WB Ptr Class: NXT_Sound_Control @brief Nil */ 
			class NXT_Sound_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !NXT_Sound_Control_DEFINED

		case kNXT_Lights_Control_v:
#ifdef NXT_Lights_Control_DEFINED
		{
/** WB Ptr Class: NXT_Lights_Control @brief Nil */ 
			class NXT_Lights_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !NXT_Lights_Control_DEFINED

		case kClocks_v:
#ifdef Clocks_DEFINED
		{
/** WB Ptr Class: Clocks @brief Nil */ 
			class Clocks_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Clocks_DEFINED

		case kChannels_v:
#ifdef Channels_DEFINED
		{
/** WB Ptr Class: Channels @brief Nil */ 
			class Channels_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Channels_DEFINED

		case kSwitchSubsumption_v:
#ifdef SwitchSubsumption_DEFINED
		{
/** WB Ptr Class: SwitchSubsumption @brief Nil */ 
			class SwitchSubsumption_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SwitchSubsumption_DEFINED

		case kTotoDoingMotion_v:
#ifdef TotoDoingMotion_DEFINED
		{
/** WB Ptr Class: TotoDoingMotion @brief Nil */ 
			class TotoDoingMotion_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !TotoDoingMotion_DEFINED

		case kCount_v:
#ifdef wb_count_DEFINED
		{
/** WB Ptr Class: Count @brief Nil */ 
			class Count_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !wb_count_DEFINED

		case kGreenEWon_v:
		{
/** WB Ptr Class: GreenEWon @brief Nil */ 
			class GreenEWon_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kWarnEW_v:
		{
/** WB Ptr Class: WarnEW @brief Nil */ 
			class WarnEW_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kTimeGTthirty_v:
		{
/** WB Ptr Class: TimeGTthirty @brief Nil */ 
			class TimeGTthirty_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kAmberEWon_v:
		{
/** WB Ptr Class: AmberEWon @brief Nil */ 
			class AmberEWon_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kTurnRedEW_v:
		{
/** WB Ptr Class: TurnRedEW @brief Nil */ 
			class TurnRedEW_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kTimeGTfive_v:
		{
/** WB Ptr Class: TimeGTfive @brief Nil */ 
			class TimeGTfive_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kRedEWon_v:
		{
/** WB Ptr Class: RedEWon @brief Nil */ 
			class RedEWon_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kGreenNSon_v:
		{
/** WB Ptr Class: GreenNSon @brief Nil */ 
			class GreenNSon_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kWarnNS_v:
		{
/** WB Ptr Class: WarnNS @brief Nil */ 
			class WarnNS_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kAmberNSon_v:
		{
/** WB Ptr Class: AmberNSon @brief Nil */ 
			class AmberNSon_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kTurnRedNS_v:
		{
/** WB Ptr Class: TurnRedNS @brief Nil */ 
			class TurnRedNS_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kRedNSon_v:
		{
/** WB Ptr Class: RedNSon @brief Nil */ 
			class RedNSon_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kTimerReset_v:
		{
/** WB Ptr Class: TimerReset @brief Nil */ 
			class TimerReset_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kIoT_Control_v:
#ifdef IoT_Control_DEFINED
		{
/** WB Ptr Class: IoT_Control @brief Nil */ 
			class IoT_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !IoT_Control_DEFINED

		case kCarSensorPressed_v:
		{
/** WB Ptr Class: CarSensorPressed @brief Nil */ 
			class CarSensorPressed_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kSwitchSubsumptionTrafficLights_v:
#ifdef SwitchSubsumptionTrafficLights_DEFINED
		{
/** WB Ptr Class: SwitchSubsumptionTrafficLights @brief Nil */ 
			class SwitchSubsumptionTrafficLights_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SwitchSubsumptionTrafficLights_DEFINED

	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"

	return "##unsupported##";
#pragma clang diagnostic pop
}

