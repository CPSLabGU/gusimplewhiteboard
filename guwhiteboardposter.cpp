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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"

static vector<int> strtointvec(string str)
{
	const char *sep = "|,";
	char *context = NULL;
	vector<int> array;
	for (char *element = strtok_r(const_cast<char *>(str.c_str()), sep, &context); element; element = strtok_r(NULL, sep, &context))
		array.push_back(atoi(element));
	return array;
}

#pragma clang diagnostic pop

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
/** WB Ptr Class: Print @brief Nil */ 
			class Print_t Print_msg;
			Print_msg.post(std::string(message_content));
			return true;
		}
		case kSay_v:
		{
/** WB Ptr Class: Say @brief Nil */ 
			class Say_t Say_msg;
			Say_msg.post(std::string(message_content));
			return true;
		}
		case kSpeech_v:
		{
/** WB Ptr Class: Speech @brief Nil */ 
			class Speech_t Speech_msg;
			Speech_msg.post(std::string(message_content));
			return true;
		}
		case kQSay_v:
		{
/** WB Ptr Class: QSay @brief Nil */ 
			class QSay_t QSay_msg;
			QSay_msg.post(std::string(message_content));
			return true;
		}
		case kQSpeech_v:
		{
/** WB Ptr Class: QSpeech @brief Nil */ 
			class QSpeech_t QSpeech_msg;
			QSpeech_msg.post(std::string(message_content));
			return true;
		}
		case kSpeechOutput_v:
		{
/** WB Ptr Class: SpeechOutput @brief Nil */ 
			class SpeechOutput_t SpeechOutput_msg;
			SpeechOutput_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kGCGameState_v:
#ifdef GCGameState_DEFINED
		{
/** WB Ptr Class: GCGameState @brief Nil */ 
			class GCGameState_t GCGameState_msg;
			GCGameState_msg.post(GCGameState(message_content));
			return true;
		}
#else
			return false;
#endif // !GCGameState_DEFINED

		case kWALK_Command_v:
#ifdef WALK_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK_Command @brief Nil */ 
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
/** WB Ptr Class: WALK_Status @brief Nil */ 
			class WALK_Status_t WALK_Status_msg;
			WALK_Status_msg.post(WALK_ControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !WALK_ControlStatus_DEFINED

		case kMOTION_Commands_v:
#ifdef MOTION_Commands_DEFINED
		{
/** WB Ptr Class: MOTION_Commands @brief Nil */ 
			class MOTION_Commands_t MOTION_Commands_msg;
			MOTION_Commands_msg.post(MOTION_Commands(message_content));
			return true;
		}
#else
			return false;
#endif // !MOTION_Commands_DEFINED

		case kMOTION_Status_v:
#ifdef MOTION_Status_DEFINED
		{
/** WB Ptr Class: MOTION_Status @brief Nil */ 
			class MOTION_Status_t MOTION_Status_msg;
			MOTION_Status_msg.post(MOTION_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !MOTION_Status_DEFINED

		case kHAL_HeadTarget_v:
#ifdef HAL_HeadTarget_DEFINED
		{
/** WB Ptr Class: HAL_HeadTarget @brief Nil */ 
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
/** WB Ptr Class: SENSORS_FootSensors @brief Nil */ 
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
/** WB Ptr Class: SENSORS_BodySensors @brief Nil */ 
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
/** WB Ptr Class: SENSORS_LedsSensors @brief Nil */ 
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
/** WB Ptr Class: SENSORS_LegJointTemps @brief Nil */ 
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
/** WB Ptr Class: SENSORS_TorsoJointTemps @brief Nil */ 
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
/** WB Ptr Class: SENSORS_LegJointSensors @brief Nil */ 
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
/** WB Ptr Class: SENSORS_TorsoJointSensors @brief Nil */ 
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
/** WB Ptr Class: SENSORS_SonarSensors @brief Nil */ 
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
/** WB Ptr Class: FSM_Control @brief Nil */ 
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
/** WB Ptr Class: FSM_Status @brief Nil */ 
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
/** WB Ptr Class: FSM_Names @brief Nil */ 
			class FSM_Names_t FSM_Names_msg;
			FSM_Names_msg.post(FSMNames(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMNames_DEFINED

		case kSoloTypeExample_v:
			return false;

		case kFilteredGoalSighting_v:
#ifdef FilteredArrayOneDimObjects_DEFINED
		{
/** WB Ptr Class: FilteredGoalSighting @brief Nil */ 
			class FilteredGoalSighting_t FilteredGoalSighting_msg;
			FilteredGoalSighting_msg.post(FilteredArrayOneDimObjects(message_content));
			return true;
		}
#else
			return false;
#endif // !FilteredArrayOneDimObjects_DEFINED

		case kNAO_State_v:
#ifdef NAO_State_DEFINED
		{
/** WB Ptr Class: NAO_State @brief Nil */ 
			class NAO_State_t NAO_State_msg;
			NAO_State_msg.post(NAO_State(message_content));
			return true;
		}
#else
			return false;
#endif // !NAO_State_DEFINED

		case kUDPRN_v:
#ifdef GCGameState_DEFINED
		{
/** WB Ptr Class: UDPRN @brief Nil */ 
			class UDPRN_t UDPRN_msg;
			UDPRN_msg.post(GCGameState(message_content));
			return true;
		}
#else
			return false;
#endif // !GCGameState_DEFINED

		case kPlayerNumber_v:
		{
/** WB Ptr Class: PlayerNumber @brief Nil */ 
			class PlayerNumber_t PlayerNumber_msg;
			PlayerNumber_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kManuallyPenalized_v:
		{
/** WB Ptr Class: ManuallyPenalized @brief Nil */ 
			class ManuallyPenalized_t ManuallyPenalized_msg;
			ManuallyPenalized_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kVision_Control_v:
#ifdef VisionControlStatus_DEFINED
		{
/** WB Ptr Class: Vision_Control @brief Nil */ 
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
/** WB Ptr Class: Vision_Status @brief Nil */ 
			class Vision_Status_t Vision_Status_msg;
			Vision_Status_msg.post(VisionControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !VisionControlStatus_DEFINED

		case kFFTStatus_v:
#ifdef FFTStatus_DEFINED
		{
/** WB Ptr Class: FFTStatus @brief Nil */ 
			class FFTStatus_t FFTStatus_msg;
			FFTStatus_msg.post(FFTStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !FFTStatus_DEFINED

		case kFSOsighting_v:
#ifdef FilteredArrayOneDimSonar_DEFINED
		{
/** WB Ptr Class: FSOsighting @brief Nil */ 
			class FSOsighting_t FSOsighting_msg;
			FSOsighting_msg.post(FilteredArrayOneDimSonar(message_content));
			return true;
		}
#else
			return false;
#endif // !FilteredArrayOneDimSonar_DEFINED

		case kTopParticles_v:
#ifdef TopParticles_DEFINED
		{
/** WB Ptr Class: TopParticles @brief Nil */ 
			class TopParticles_t TopParticles_msg;
			TopParticles_msg.post(TopParticles(message_content));
			return true;
		}
#else
			return false;
#endif // !TopParticles_DEFINED

		case kFilteredBallSighting_v:
#ifdef FilteredArrayOneDimBall_DEFINED
		{
/** WB Ptr Class: FilteredBallSighting @brief Nil */ 
			class FilteredBallSighting_t FilteredBallSighting_msg;
			FilteredBallSighting_msg.post(FilteredArrayOneDimBall(message_content));
			return true;
		}
#else
			return false;
#endif // !FilteredArrayOneDimBall_DEFINED

		case kPF_ControlStatus_Modes_v:
		{
/** WB Ptr Class: PF_ControlStatus_Modes @brief Nil */ 
			class PF_ControlStatus_Modes_t PF_ControlStatus_Modes_msg;
			PF_ControlStatus_Modes_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kWEBOTS_NXT_bridge_v:
#ifdef WEBOTS_NXT_bridge_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_bridge @brief Nil */ 
			class WEBOTS_NXT_bridge_t WEBOTS_NXT_bridge_msg;
			WEBOTS_NXT_bridge_msg.post(WEBOTS_NXT_bridge(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_bridge_DEFINED

		case kWEBOTS_NXT_encoders_v:
#ifdef WEBOTS_NXT_encoders_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_encoders @brief Nil */ 
			class WEBOTS_NXT_encoders_t WEBOTS_NXT_encoders_msg;
			WEBOTS_NXT_encoders_msg.post(WEBOTS_NXT_encoders(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_encoders_DEFINED

		case kWEBOTS_NXT_camera_v:
#ifdef WEBOTS_NXT_camera_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_camera @brief Nil */ 
			class WEBOTS_NXT_camera_t WEBOTS_NXT_camera_msg;
			WEBOTS_NXT_camera_msg.post(WEBOTS_NXT_camera(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_camera_DEFINED

		case kWEBOTS_NXT_walk_isRunning_v:
#ifdef WEBOTS_NXT_walk_isRunning_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_walk_isRunning @brief Nil */ 
			class WEBOTS_NXT_walk_isRunning_t WEBOTS_NXT_walk_isRunning_msg;
			WEBOTS_NXT_walk_isRunning_msg.post(WEBOTS_NXT_walk_isRunning(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_walk_isRunning_DEFINED

		case kWEBOTS_NXT_deadReakoning_walk_v:
#ifdef WEBOTS_NXT_deadReakoning_walk_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_deadReakoning_walk @brief Nil */ 
			class WEBOTS_NXT_deadReakoning_walk_t WEBOTS_NXT_deadReakoning_walk_msg;
			WEBOTS_NXT_deadReakoning_walk_msg.post(WEBOTS_NXT_deadReakoning_walk(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_deadReakoning_walk_DEFINED

		case kWEBOTS_NXT_colorLine_walk_v:
#ifdef WEBOTS_NXT_colorLine_walk_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_colorLine_walk @brief Nil */ 
			class WEBOTS_NXT_colorLine_walk_t WEBOTS_NXT_colorLine_walk_msg;
			WEBOTS_NXT_colorLine_walk_msg.post(WEBOTS_NXT_colorLine_walk(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_colorLine_walk_DEFINED

		case kWEBOTS_NXT_gridMotions_v:
#ifdef WEBOTS_NXT_gridMotions_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_gridMotions @brief Nil */ 
			class WEBOTS_NXT_gridMotions_t WEBOTS_NXT_gridMotions_msg;
			WEBOTS_NXT_gridMotions_msg.post(WEBOTS_NXT_gridMotions(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_gridMotions_DEFINED

		case kVisionBall_v:
#ifdef VisionBall_DEFINED
		{
/** WB Ptr Class: VisionBall @brief Nil */ 
			class VisionBall_t VisionBall_msg;
			VisionBall_msg.post(VisionBall(message_content));
			return true;
		}
#else
			return false;
#endif // !VisionBall_DEFINED

		case kVisionGoals_v:
#ifdef VisionGoals_DEFINED
		{
/** WB Ptr Class: VisionGoals @brief Nil */ 
			class VisionGoals_t VisionGoals_msg;
			VisionGoals_msg.post(VisionGoals(message_content));
			return true;
		}
#else
			return false;
#endif // !VisionGoals_DEFINED

		case kWalkData_v:
#ifdef WalkData_DEFINED
		{
/** WB Ptr Class: WalkData @brief Nil */ 
			class WalkData_t WalkData_msg;
			WalkData_msg.post(WalkData(message_content));
			return true;
		}
#else
			return false;
#endif // !WalkData_DEFINED

		case kTeleoperationControlStatus_v:
#ifdef TeleoperationControlStatus_DEFINED
		{
/** WB Ptr Class: TeleoperationControlStatus @brief Nil */ 
			class TeleoperationControlStatus_t TeleoperationControlStatus_msg;
			TeleoperationControlStatus_msg.post(TeleoperationControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !TeleoperationControlStatus_DEFINED

		case kTeleoperationConnection_v:
		{
/** WB Ptr Class: TeleoperationConnection @brief Nil */ 
			class TeleoperationConnection_t TeleoperationConnection_msg;
			TeleoperationConnection_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kUDPWBNumber_v:
		{
/** WB Ptr Class: UDPWBNumber @brief Nil */ 
			class UDPWBNumber_t UDPWBNumber_msg;
			UDPWBNumber_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kWEBOTS_NXT_bumper_v:
#ifdef WEBOTS_NXT_bumper_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_bumper @brief Nil */ 
			class WEBOTS_NXT_bumper_t WEBOTS_NXT_bumper_msg;
			WEBOTS_NXT_bumper_msg.post(WEBOTS_NXT_bumper(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_bumper_DEFINED

		case kWEBOTS_NXT_vector_bridge_v:
#ifdef WEBOTS_NXT_vector_bridge_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_vector_bridge @brief Nil */ 
			class WEBOTS_NXT_vector_bridge_t WEBOTS_NXT_vector_bridge_msg;
			WEBOTS_NXT_vector_bridge_msg.post(WEBOTS_NXT_vector_bridge(message_content));
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_vector_bridge_DEFINED

		case kVisionLines_v:
#ifdef VisionLines_DEFINED
		{
/** WB Ptr Class: VisionLines @brief Nil */ 
			class VisionLines_t VisionLines_msg;
			VisionLines_msg.post(VisionLines(message_content));
			return true;
		}
#else
			return false;
#endif // !VisionLines_DEFINED

		case kDifferentialRobotStatus_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotStatus @brief Nil */ 
			class DifferentialRobotStatus_t DifferentialRobotStatus_msg;
			DifferentialRobotStatus_msg.post(DifferentialRobotControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !DifferentialRobotControlStatus_DEFINED

		case kDifferentialRobotControl_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotControl @brief Nil */ 
			class DifferentialRobotControl_t DifferentialRobotControl_msg;
			DifferentialRobotControl_msg.post(DifferentialRobotControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !DifferentialRobotControlStatus_DEFINED

		case kXEyesPos_v:
#ifdef Point2D_DEFINED
		{
/** WB Ptr Class: XEyesPos @brief Nil */ 
			class XEyesPos_t XEyesPos_msg;
			XEyesPos_msg.post(Point2D(message_content));
			return true;
		}
#else
			return false;
#endif // !Point2D_DEFINED

		case kVisionFace_v:
		{
/** WB Ptr Class: VisionFace @brief Nil */ 
			class VisionFace_t VisionFace_msg(strtointvec(message_content));
			(void)VisionFace_msg;
			return true;
		}

		case kDraw_v:
		{
/** WB Ptr Class: Draw @brief Nil */ 
			class Draw_t Draw_msg;
			Draw_msg.post(std::string(message_content));
			return true;
		}
		case kFSM_States_v:
#ifdef FSMState_DEFINED
		{
/** WB Ptr Class: FSM_States @brief Nil */ 
			class FSM_States_t FSM_States_msg;
			FSM_States_msg.post(FSMState(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMState_DEFINED

		case kGiraff_Interface_Status_v:
#ifdef Giraff_MainSerialInterface_DEFINED
		{
/** WB Ptr Class: Giraff_Interface_Status @brief Nil */ 
			class Giraff_Interface_Status_t Giraff_Interface_Status_msg;
			Giraff_Interface_Status_msg.post(Giraff_MainSerialInterface(message_content));
			return true;
		}
#else
			return false;
#endif // !Giraff_MainSerialInterface_DEFINED

		case kGiraff_Interface_Command_v:
#ifdef Giraff_MainSerialInterface_DEFINED
		{
/** WB Ptr Class: Giraff_Interface_Command @brief Nil */ 
			class Giraff_Interface_Command_t Giraff_Interface_Command_msg;
			Giraff_Interface_Command_msg.post(Giraff_MainSerialInterface(message_content));
			return true;
		}
#else
			return false;
#endif // !Giraff_MainSerialInterface_DEFINED

		case kNXT_Status_v:
#ifdef NXT_Interface_DEFINED
		{
/** WB Ptr Class: NXT_Status @brief Nil */ 
			class NXT_Status_t NXT_Status_msg;
			NXT_Status_msg.post(NXT_Interface(message_content));
			return true;
		}
#else
			return false;
#endif // !NXT_Interface_DEFINED

		case kNXT_Command_v:
#ifdef NXT_Interface_DEFINED
		{
/** WB Ptr Class: NXT_Command @brief Nil */ 
			class NXT_Command_t NXT_Command_msg;
			NXT_Command_msg.post(NXT_Interface(message_content));
			return true;
		}
#else
			return false;
#endif // !NXT_Interface_DEFINED

	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"

	return false;
#pragma clang diagnostic pop
}

whiteboard_types_map::whiteboard_types_map(): map<string, WBTypes>()
{
	whiteboard_types_map &self = *this;
	// self.reserve(63);

	self["*"] = kwb_reserved_SubscribeToAllTypes_v;
	self["Print"] = kPrint_v;
	self["Say"] = kSay_v;
	self["Speech"] = kSpeech_v;
	self["QSay"] = kQSay_v;
	self["QSpeech"] = kQSpeech_v;
	self["SpeechOutput"] = kSpeechOutput_v;
	self["GCGameState"] = kGCGameState_v;
	self["WALK_Command"] = kWALK_Command_v;
	self["WALK_Status"] = kWALK_Status_v;
	self["MOTION_Commands"] = kMOTION_Commands_v;
	self["MOTION_Status"] = kMOTION_Status_v;
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
	self["FilteredGoalSighting"] = kFilteredGoalSighting_v;
	self["NAO_State"] = kNAO_State_v;
	self["UDPReceiverNotification"] = kUDPRN_v;
	self["PlayerNumber"] = kPlayerNumber_v;
	self["PlayerNumber"] = kManuallyPenalized_v;
	self["guvision_control"] = kVision_Control_v;
	self["guvision_status"] = kVision_Status_v;
	self["FFTStatus"] = kFFTStatus_v;
	self["FSOsighting"] = kFSOsighting_v;
	self["TopParticles"] = kTopParticles_v;
	self["FilteredBallSighting"] = kFilteredBallSighting_v;
	self["PF_ControlStatus_Modes"] = kPF_ControlStatus_Modes_v;
	self["WEBOTS_NXT_bridge"] = kWEBOTS_NXT_bridge_v;
	self["WEBOTS_NXT_encoders"] = kWEBOTS_NXT_encoders_v;
	self["WEBOTS_NXT_camera"] = kWEBOTS_NXT_camera_v;
	self["WEBOTS_NXT_walk_isRunning"] = kWEBOTS_NXT_walk_isRunning_v;
	self["WEBOTS_NXT_deadReakoning_walk"] = kWEBOTS_NXT_deadReakoning_walk_v;
	self["WEBOTS_NXT_colorLine_walk"] = kWEBOTS_NXT_colorLine_walk_v;
	self["WEBOTS_NXT_gridMotions"] = kWEBOTS_NXT_gridMotions_v;
	self["VisionBall"] = kVisionBall_v;
	self["VisionGoals"] = kVisionGoals_v;
	self["WalkData"] = kWalkData_v;
	self["TeleoperationControlStatus"] = kTeleoperationControlStatus_v;
	self["TeleoperationConnection"] = kTeleoperationConnection_v;
	self["UDPWBNumber"] = kUDPWBNumber_v;
	self["WEBOTS_NXT_bumper"] = kWEBOTS_NXT_bumper_v;
	self["WEBOTS_NXT_vector_bridge"] = kWEBOTS_NXT_vector_bridge_v;
	self["VisionLines"] = kVisionLines_v;
	self["DifferentialRobotStatus"] = kDifferentialRobotStatus_v;
	self["DifferentialRobotControl"] = kDifferentialRobotControl_v;
	self["XEyesPos"] = kXEyesPos_v;
	self["VisionFace"] = kVisionFace_v;
	self["Draw"] = kDraw_v;
	self["fsm_states"] = kFSM_States_v;
	self["Giraff_Interface_Status"] = kGiraff_Interface_Status_v;
	self["Giraff_Interface_Command"] = kGiraff_Interface_Command_v;
	self["NXT_Status"] = kNXT_Status_v;
	self["NXT_Command"] = kNXT_Command_v;
}

