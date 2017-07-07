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


	bool whiteboard_post_to(gu_simple_whiteboard_descriptor *wbd, const char *message_type, const char *message_content)
	{
		return whiteboard_postmsg_to(wbd, types_map[message_type], message_content);
	}


	bool whiteboard_postmsg(int message_index, const char *message_content)
	{
		return postmsg(WBTypes(message_index), message_content);
	}

	bool whiteboard_postmsg_to(gu_simple_whiteboard_descriptor *wbd, int message_index, const char *message_content)
	{
		return postmsg(WBTypes(message_index), message_content, wbd);
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

namespace guWhiteboard
{
    bool post(string message_type, string message_content, gu_simple_whiteboard_descriptor *wbd)
    {
    	return postmsg(types_map[message_type], message_content, wbd);
    }


    bool postmsg(WBTypes message_index, std::string message_content, gu_simple_whiteboard_descriptor *wbd)
    {
    	switch (message_index)
    	{
		case kwb_reserved_SubscribeToAllTypes_v:
			return false;

		case kPrint_v:
		{
/** WB Ptr Class: Print @brief Nil */ 
			class Print_t Print_msg(wbd);
			Print_msg.post(std::string(message_content));
			return true;
		}
		case kSay_v:
		{
/** WB Ptr Class: Say @brief Nil */ 
			class Say_t Say_msg(wbd);
			Say_msg.post(std::string(message_content));
			return true;
		}
		case kSpeech_v:
		{
/** WB Ptr Class: Speech @brief Nil */ 
			class Speech_t Speech_msg(wbd);
			Speech_msg.post(std::string(message_content));
			return true;
		}
		case kQSay_v:
		{
/** WB Ptr Class: QSay @brief Nil */ 
			class QSay_t QSay_msg(wbd);
			QSay_msg.post(std::string(message_content));
			return true;
		}
		case kQSpeech_v:
		{
/** WB Ptr Class: QSpeech @brief Nil */ 
			class QSpeech_t QSpeech_msg(wbd);
			QSpeech_msg.post(std::string(message_content));
			return true;
		}
		case kSpeechOutput_v:
		{
/** WB Ptr Class: SpeechOutput @brief Nil */ 
			class SpeechOutput_t SpeechOutput_msg(wbd);
			SpeechOutput_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kGCGameState_v:
#ifdef GCGameState_DEFINED
		{
/** WB Ptr Class: GCGameState @brief Nil */ 
			class GCGameState_t GCGameState_msg(wbd);
			GCGameState v = GCGameState_msg.get(); 
			v.from_string(message_content);
			GCGameState_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !GCGameState_DEFINED

		case kWALK_Command_v:
#ifdef WALK_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK_Command @brief Nil */ 
			class WALK_Command_t WALK_Command_msg(wbd);
			WALK_ControlStatus v = WALK_Command_msg.get(); 
			v.from_string(message_content);
			WALK_Command_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WALK_ControlStatus_DEFINED

		case kWALK_Status_v:
#ifdef WALK_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK_Status @brief Nil */ 
			class WALK_Status_t WALK_Status_msg(wbd);
			WALK_ControlStatus v = WALK_Status_msg.get(); 
			v.from_string(message_content);
			WALK_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WALK_ControlStatus_DEFINED

		case kMOTION_Commands_v:
#ifdef MOTION_Commands_DEFINED
		{
/** WB Ptr Class: MOTION_Commands @brief Nil */ 
			class MOTION_Commands_t MOTION_Commands_msg(wbd);
			MOTION_Commands v = MOTION_Commands_msg.get(); 
			v.from_string(message_content);
			MOTION_Commands_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !MOTION_Commands_DEFINED

		case kMOTION_Status_v:
#ifdef MOTION_Status_DEFINED
		{
/** WB Ptr Class: MOTION_Status @brief Nil */ 
			class MOTION_Status_t MOTION_Status_msg(wbd);
			MOTION_Status v = MOTION_Status_msg.get(); 
			v.from_string(message_content);
			MOTION_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !MOTION_Status_DEFINED

		case kHAL_HeadTarget_v:
#ifdef HAL_HeadTarget_DEFINED
		{
/** WB Ptr Class: HAL_HeadTarget @brief Nil */ 
			class HAL_HeadTarget_t HAL_HeadTarget_msg(wbd);
			HAL_HeadTarget v = HAL_HeadTarget_msg.get(); 
			v.from_string(message_content);
			HAL_HeadTarget_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !HAL_HeadTarget_DEFINED

		case kSENSORSFootSensors_v:
#ifdef SENSORSFootSensors_DEFINED
		{
/** WB Ptr Class: SENSORSFootSensors @brief Nil */ 
			class SENSORSFootSensors_t SENSORSFootSensors_msg(wbd);
			SENSORSFootSensors v = SENSORSFootSensors_msg.get(); 
			v.from_string(message_content);
			SENSORSFootSensors_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SENSORSFootSensors_DEFINED

		case kSENSORSBodySensors_v:
#ifdef SENSORSBodySensors_DEFINED
		{
/** WB Ptr Class: SENSORSBodySensors @brief Nil */ 
			class SENSORSBodySensors_t SENSORSBodySensors_msg(wbd);
			SENSORSBodySensors v = SENSORSBodySensors_msg.get(); 
			v.from_string(message_content);
			SENSORSBodySensors_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SENSORSBodySensors_DEFINED

		case kSENSORSLedsSensors_v:
#ifdef SENSORSLedsSensors_DEFINED
		{
/** WB Ptr Class: SENSORSLedsSensors @brief Nil */ 
			class SENSORSLedsSensors_t SENSORSLedsSensors_msg(wbd);
			SENSORSLedsSensors v = SENSORSLedsSensors_msg.get(); 
			v.from_string(message_content);
			SENSORSLedsSensors_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SENSORSLedsSensors_DEFINED

		case kSENSORSLegJointTemps_v:
#ifdef SENSORSLegJointTemps_DEFINED
		{
/** WB Ptr Class: SENSORSLegJointTemps @brief Nil */ 
			class SENSORSLegJointTemps_t SENSORSLegJointTemps_msg(wbd);
			SENSORSLegJointTemps v = SENSORSLegJointTemps_msg.get(); 
			v.from_string(message_content);
			SENSORSLegJointTemps_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SENSORSLegJointTemps_DEFINED

		case kSENSORSTorsoJointTemps_v:
#ifdef SENSORSTorsoJointTemps_DEFINED
		{
/** WB Ptr Class: SENSORSTorsoJointTemps @brief Nil */ 
			class SENSORSTorsoJointTemps_t SENSORSTorsoJointTemps_msg(wbd);
			SENSORSTorsoJointTemps v = SENSORSTorsoJointTemps_msg.get(); 
			v.from_string(message_content);
			SENSORSTorsoJointTemps_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SENSORSTorsoJointTemps_DEFINED

		case kSENSORSLegJointSensors_v:
#ifdef SENSORSLegJointSensors_DEFINED
		{
/** WB Ptr Class: SENSORSLegJointSensors @brief Nil */ 
			class SENSORSLegJointSensors_t SENSORSLegJointSensors_msg(wbd);
			SENSORSLegJointSensors v = SENSORSLegJointSensors_msg.get(); 
			v.from_string(message_content);
			SENSORSLegJointSensors_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SENSORSLegJointSensors_DEFINED

		case kSENSORSTorsoJointSensors_v:
#ifdef SENSORSTorsoJointSensors_DEFINED
		{
/** WB Ptr Class: SENSORSTorsoJointSensors @brief Nil */ 
			class SENSORSTorsoJointSensors_t SENSORSTorsoJointSensors_msg(wbd);
			SENSORSTorsoJointSensors v = SENSORSTorsoJointSensors_msg.get(); 
			v.from_string(message_content);
			SENSORSTorsoJointSensors_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SENSORSTorsoJointSensors_DEFINED

		case kSENSORSSonarSensors_v:
#ifdef SENSORSSonarSensors_DEFINED
		{
/** WB Ptr Class: SENSORSSonarSensors @brief Nil */ 
			class SENSORSSonarSensors_t SENSORSSonarSensors_msg(wbd);
			SENSORSSonarSensors v = SENSORSSonarSensors_msg.get(); 
			v.from_string(message_content);
			SENSORSSonarSensors_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SENSORSSonarSensors_DEFINED

		case kFSM_Control_v:
#ifdef FSMControlStatus_DEFINED
		{
/** WB Ptr Class: FSM_Control @brief Nil */ 
			class FSM_Control_t FSM_Control_msg(wbd);
			FSMControlStatus v = FSM_Control_msg.get(); 
			v.from_string(message_content);
			FSM_Control_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !FSMControlStatus_DEFINED

		case kFSM_Status_v:
#ifdef FSMControlStatus_DEFINED
		{
/** WB Ptr Class: FSM_Status @brief Nil */ 
			class FSM_Status_t FSM_Status_msg(wbd);
			FSMControlStatus v = FSM_Status_msg.get(); 
			v.from_string(message_content);
			FSM_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !FSMControlStatus_DEFINED

		case kFSM_Names_v:
#ifdef FSMNames_DEFINED
		{
/** WB Ptr Class: FSM_Names @brief Nil */ 
			class FSM_Names_t FSM_Names_msg(wbd);
			FSMNames v = FSM_Names_msg.get(); 
			v.from_string(message_content);
			FSM_Names_msg.post(v);
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
			class FilteredGoalSighting_t FilteredGoalSighting_msg(wbd);
			FilteredArrayOneDimObjects v = FilteredGoalSighting_msg.get(); 
			v.from_string(message_content);
			FilteredGoalSighting_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !FilteredArrayOneDimObjects_DEFINED

		case kNAO_State_v:
#ifdef NAO_State_DEFINED
		{
/** WB Ptr Class: NAO_State @brief Nil */ 
			class NAO_State_t NAO_State_msg(wbd);
			NAO_State v = NAO_State_msg.get(); 
			v.from_string(message_content);
			NAO_State_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !NAO_State_DEFINED

		case kUDPRN_v:
#ifdef GCGameState_DEFINED
		{
/** WB Ptr Class: UDPRN @brief Nil */ 
			class UDPRN_t UDPRN_msg(wbd);
			GCGameState v = UDPRN_msg.get(); 
			v.from_string(message_content);
			UDPRN_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !GCGameState_DEFINED

		case kPlayerNumber_v:
#ifdef int8_t_DEFINED
		{
/** WB Ptr Class: PlayerNumber @brief Nil */ 
			class PlayerNumber_t PlayerNumber_msg(wbd);
			int8_t v = PlayerNumber_msg.get(); 
			v.from_string(message_content);
			PlayerNumber_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !int8_t_DEFINED

		case kManuallyPenalized_v:
#ifdef int8_t_DEFINED
		{
/** WB Ptr Class: ManuallyPenalized @brief Nil */ 
			class ManuallyPenalized_t ManuallyPenalized_msg(wbd);
			int8_t v = ManuallyPenalized_msg.get(); 
			v.from_string(message_content);
			ManuallyPenalized_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !int8_t_DEFINED

		case kVision_Control_v:
#ifdef VisionControlStatus_DEFINED
		{
/** WB Ptr Class: Vision_Control @brief Nil */ 
			class Vision_Control_t Vision_Control_msg(wbd);
			VisionControlStatus v = Vision_Control_msg.get(); 
			v.from_string(message_content);
			Vision_Control_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !VisionControlStatus_DEFINED

		case kVision_Status_v:
#ifdef VisionControlStatus_DEFINED
		{
/** WB Ptr Class: Vision_Status @brief Nil */ 
			class Vision_Status_t Vision_Status_msg(wbd);
			VisionControlStatus v = Vision_Status_msg.get(); 
			v.from_string(message_content);
			Vision_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !VisionControlStatus_DEFINED

		case kFFTStatus_v:
#ifdef FFTStatus_DEFINED
		{
/** WB Ptr Class: FFTStatus @brief Nil */ 
			class FFTStatus_t FFTStatus_msg(wbd);
			FFTStatus v = FFTStatus_msg.get(); 
			v.from_string(message_content);
			FFTStatus_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !FFTStatus_DEFINED

		case kFSOsighting_v:
#ifdef FilteredArrayOneDimSonar_DEFINED
		{
/** WB Ptr Class: FSOsighting @brief Nil */ 
			class FSOsighting_t FSOsighting_msg(wbd);
			FilteredArrayOneDimSonar v = FSOsighting_msg.get(); 
			v.from_string(message_content);
			FSOsighting_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !FilteredArrayOneDimSonar_DEFINED

		case kTopParticles_v:
#ifdef TopParticles_DEFINED
		{
/** WB Ptr Class: TopParticles @brief Nil */ 
			class TopParticles_t TopParticles_msg(wbd);
			TopParticles v = TopParticles_msg.get(); 
			v.from_string(message_content);
			TopParticles_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !TopParticles_DEFINED

		case kFilteredBallSighting_v:
#ifdef FilteredArrayBallSightings_DEFINED
		{
/** WB Ptr Class: FilteredBallSighting @brief Nil */ 
			class FilteredBallSighting_t FilteredBallSighting_msg(wbd);
			FilteredArrayBallSightings v = FilteredBallSighting_msg.get(); 
			v.from_string(message_content);
			FilteredBallSighting_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !FilteredArrayBallSightings_DEFINED

		case kPF_ControlStatus_Modes_v:
#ifdef int32_t_DEFINED
		{
/** WB Ptr Class: PF_ControlStatus_Modes @brief Nil */ 
			class PF_ControlStatus_Modes_t PF_ControlStatus_Modes_msg(wbd);
			int32_t v = PF_ControlStatus_Modes_msg.get(); 
			v.from_string(message_content);
			PF_ControlStatus_Modes_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !int32_t_DEFINED

		case kWEBOTS_NXT_bridge_v:
#ifdef WEBOTS_NXT_bridge_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_bridge @brief Nil */ 
			class WEBOTS_NXT_bridge_t WEBOTS_NXT_bridge_msg(wbd);
			WEBOTS_NXT_bridge v = WEBOTS_NXT_bridge_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_bridge_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_bridge_DEFINED

		case kWEBOTS_NXT_encoders_v:
#ifdef WEBOTS_NXT_encoders_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_encoders @brief Nil */ 
			class WEBOTS_NXT_encoders_t WEBOTS_NXT_encoders_msg(wbd);
			WEBOTS_NXT_encoders v = WEBOTS_NXT_encoders_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_encoders_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_encoders_DEFINED

		case kWEBOTS_NXT_camera_v:
#ifdef WEBOTS_NXT_camera_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_camera @brief Nil */ 
			class WEBOTS_NXT_camera_t WEBOTS_NXT_camera_msg(wbd);
			WEBOTS_NXT_camera v = WEBOTS_NXT_camera_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_camera_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_camera_DEFINED

		case kWEBOTS_NXT_walk_isRunning_v:
#ifdef WEBOTS_NXT_walk_isRunning_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_walk_isRunning @brief Nil */ 
			class WEBOTS_NXT_walk_isRunning_t WEBOTS_NXT_walk_isRunning_msg(wbd);
			WEBOTS_NXT_walk_isRunning v = WEBOTS_NXT_walk_isRunning_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_walk_isRunning_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_walk_isRunning_DEFINED

		case kWEBOTS_NXT_deadReakoning_walk_v:
#ifdef WEBOTS_NXT_deadReakoning_walk_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_deadReakoning_walk @brief Nil */ 
			class WEBOTS_NXT_deadReakoning_walk_t WEBOTS_NXT_deadReakoning_walk_msg(wbd);
			WEBOTS_NXT_deadReakoning_walk v = WEBOTS_NXT_deadReakoning_walk_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_deadReakoning_walk_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_deadReakoning_walk_DEFINED

		case kWEBOTS_NXT_colorLine_walk_v:
#ifdef WEBOTS_NXT_colorLine_walk_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_colorLine_walk @brief Nil */ 
			class WEBOTS_NXT_colorLine_walk_t WEBOTS_NXT_colorLine_walk_msg(wbd);
			WEBOTS_NXT_colorLine_walk v = WEBOTS_NXT_colorLine_walk_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_colorLine_walk_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_colorLine_walk_DEFINED

		case kWEBOTS_NXT_gridMotions_v:
#ifdef WEBOTS_NXT_gridMotions_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_gridMotions @brief Nil */ 
			class WEBOTS_NXT_gridMotions_t WEBOTS_NXT_gridMotions_msg(wbd);
			WEBOTS_NXT_gridMotions v = WEBOTS_NXT_gridMotions_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_gridMotions_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_gridMotions_DEFINED

		case kVisionBall_v:
#ifdef VisionBall_DEFINED
		{
/** WB Ptr Class: VisionBall @brief Nil */ 
			class VisionBall_t VisionBall_msg(wbd);
			VisionBall v = VisionBall_msg.get(); 
			v.from_string(message_content);
			VisionBall_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !VisionBall_DEFINED

		case kVisionGoals_v:
#ifdef VisionGoals_DEFINED
		{
/** WB Ptr Class: VisionGoals @brief Nil */ 
			class VisionGoals_t VisionGoals_msg(wbd);
			VisionGoals v = VisionGoals_msg.get(); 
			v.from_string(message_content);
			VisionGoals_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !VisionGoals_DEFINED

		case kWalkData_v:
#ifdef WalkData_DEFINED
		{
/** WB Ptr Class: WalkData @brief Nil */ 
			class WalkData_t WalkData_msg(wbd);
			WalkData v = WalkData_msg.get(); 
			v.from_string(message_content);
			WalkData_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WalkData_DEFINED

		case kTeleoperationControlStatus_v:
#ifdef TeleoperationControlStatus_DEFINED
		{
/** WB Ptr Class: TeleoperationControlStatus @brief Nil */ 
			class TeleoperationControlStatus_t TeleoperationControlStatus_msg(wbd);
			TeleoperationControlStatus v = TeleoperationControlStatus_msg.get(); 
			v.from_string(message_content);
			TeleoperationControlStatus_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !TeleoperationControlStatus_DEFINED

		case kTeleoperationConnection_v:
#ifdef int8_t_DEFINED
		{
/** WB Ptr Class: TeleoperationConnection @brief Nil */ 
			class TeleoperationConnection_t TeleoperationConnection_msg(wbd);
			int8_t v = TeleoperationConnection_msg.get(); 
			v.from_string(message_content);
			TeleoperationConnection_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !int8_t_DEFINED

		case kUDPWBNumber_v:
#ifdef int8_t_DEFINED
		{
/** WB Ptr Class: UDPWBNumber @brief Nil */ 
			class UDPWBNumber_t UDPWBNumber_msg(wbd);
			int8_t v = UDPWBNumber_msg.get(); 
			v.from_string(message_content);
			UDPWBNumber_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !int8_t_DEFINED

		case kWEBOTS_NXT_bumper_v:
#ifdef WEBOTS_NXT_bumper_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_bumper @brief Nil */ 
			class WEBOTS_NXT_bumper_t WEBOTS_NXT_bumper_msg(wbd);
			WEBOTS_NXT_bumper v = WEBOTS_NXT_bumper_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_bumper_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_bumper_DEFINED

		case kWEBOTS_NXT_vector_bridge_v:
#ifdef WEBOTS_NXT_vector_bridge_DEFINED
		{
/** WB Ptr Class: WEBOTS_NXT_vector_bridge @brief Nil */ 
			class WEBOTS_NXT_vector_bridge_t WEBOTS_NXT_vector_bridge_msg(wbd);
			WEBOTS_NXT_vector_bridge v = WEBOTS_NXT_vector_bridge_msg.get(); 
			v.from_string(message_content);
			WEBOTS_NXT_vector_bridge_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WEBOTS_NXT_vector_bridge_DEFINED

		case kVisionLines_v:
#ifdef VisionLines_DEFINED
		{
/** WB Ptr Class: VisionLines @brief Nil */ 
			class VisionLines_t VisionLines_msg(wbd);
			VisionLines v = VisionLines_msg.get(); 
			v.from_string(message_content);
			VisionLines_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !VisionLines_DEFINED

		case kDifferentialRobotStatus_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotStatus @brief Nil */ 
			class DifferentialRobotStatus_t DifferentialRobotStatus_msg(wbd);
			DifferentialRobotControlStatus v = DifferentialRobotStatus_msg.get(); 
			v.from_string(message_content);
			DifferentialRobotStatus_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !DifferentialRobotControlStatus_DEFINED

		case kDifferentialRobotControl_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotControl @brief Nil */ 
			class DifferentialRobotControl_t DifferentialRobotControl_msg(wbd);
			DifferentialRobotControlStatus v = DifferentialRobotControl_msg.get(); 
			v.from_string(message_content);
			DifferentialRobotControl_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !DifferentialRobotControlStatus_DEFINED

		case kXEyesPos_v:
#ifdef Point2D_DEFINED
		{
/** WB Ptr Class: XEyesPos @brief Nil */ 
			class XEyesPos_t XEyesPos_msg(wbd);
			Point2D v = XEyesPos_msg.get(); 
			v.from_string(message_content);
			XEyesPos_msg.post(v);
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
			class Draw_t Draw_msg(wbd);
			Draw_msg.post(std::string(message_content));
			return true;
		}
		case kFSM_States_v:
#ifdef FSMState_DEFINED
		{
/** WB Ptr Class: FSM_States @brief Nil */ 
			class FSM_States_t FSM_States_msg(wbd);
			FSMState v = FSM_States_msg.get(); 
			v.from_string(message_content);
			FSM_States_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !FSMState_DEFINED

		case kGiraff_Interface_Status_v:
#ifdef Giraff_MainSerialInterface_DEFINED
		{
/** WB Ptr Class: Giraff_Interface_Status @brief Nil */ 
			class Giraff_Interface_Status_t Giraff_Interface_Status_msg(wbd);
			Giraff_MainSerialInterface v = Giraff_Interface_Status_msg.get(); 
			v.from_string(message_content);
			Giraff_Interface_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !Giraff_MainSerialInterface_DEFINED

		case kGiraff_Interface_Command_v:
#ifdef Giraff_MainSerialInterface_DEFINED
		{
/** WB Ptr Class: Giraff_Interface_Command @brief Nil */ 
			class Giraff_Interface_Command_t Giraff_Interface_Command_msg(wbd);
			Giraff_MainSerialInterface v = Giraff_Interface_Command_msg.get(); 
			v.from_string(message_content);
			Giraff_Interface_Command_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !Giraff_MainSerialInterface_DEFINED

		case kNXT_Status_v:
#ifdef NXT_Interface_DEFINED
		{
/** WB Ptr Class: NXT_Status @brief Nil */ 
			class NXT_Status_t NXT_Status_msg(wbd);
			NXT_Interface v = NXT_Status_msg.get(); 
			v.from_string(message_content);
			NXT_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !NXT_Interface_DEFINED

		case kNXT_Command_v:
#ifdef NXT_Interface_DEFINED
		{
/** WB Ptr Class: NXT_Command @brief Nil */ 
			class NXT_Command_t NXT_Command_msg(wbd);
			NXT_Interface v = NXT_Command_msg.get(); 
			v.from_string(message_content);
			NXT_Command_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !NXT_Interface_DEFINED

		case kAPM_Status_v:
#ifdef APM_Interface_DEFINED
		{
/** WB Ptr Class: APM_Status @brief Nil */ 
			class APM_Status_t APM_Status_msg(wbd);
			APM_Interface v = APM_Status_msg.get(); 
			v.from_string(message_content);
			APM_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !APM_Interface_DEFINED

		case kAPM_Command_v:
#ifdef APM_Interface_DEFINED
		{
/** WB Ptr Class: APM_Command @brief Nil */ 
			class APM_Command_t APM_Command_msg(wbd);
			APM_Interface v = APM_Command_msg.get(); 
			v.from_string(message_content);
			APM_Command_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !APM_Interface_DEFINED

		case kWALK2014_Command_v:
#ifdef WALK2014_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK2014_Command @brief Nil */ 
			class WALK2014_Command_t WALK2014_Command_msg(wbd);
			WALK2014_ControlStatus v = WALK2014_Command_msg.get(); 
			v.from_string(message_content);
			WALK2014_Command_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WALK2014_ControlStatus_DEFINED

		case kWALK2014_Status_v:
#ifdef WALK2014_ControlStatus_DEFINED
		{
/** WB Ptr Class: WALK2014_Status @brief Nil */ 
			class WALK2014_Status_t WALK2014_Status_msg(wbd);
			WALK2014_ControlStatus v = WALK2014_Status_msg.get(); 
			v.from_string(message_content);
			WALK2014_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !WALK2014_ControlStatus_DEFINED

		case kCBall_v:
#ifdef int8_t_DEFINED
		{
/** WB Ptr Class: CBall @brief Nil */ 
			class CBall_t CBall_msg(wbd);
			int8_t v = CBall_msg.get(); 
			v.from_string(message_content);
			CBall_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !int8_t_DEFINED

		case kOculusPrime_Command_v:
#ifdef OculusPrimeInterface_DEFINED
		{
/** WB Ptr Class: OculusPrime_Command @brief Nil */ 
			class OculusPrime_Command_t OculusPrime_Command_msg(wbd);
			OculusPrimeInterface v = OculusPrime_Command_msg.get(); 
			v.from_string(message_content);
			OculusPrime_Command_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !OculusPrimeInterface_DEFINED

		case kInput3D_v:
#ifdef Input3D_DEFINED
		{
/** WB Ptr Class: Input3D @brief Nil */ 
			class Input3D_t Input3D_msg(wbd);
			Input3D v = Input3D_msg.get(); 
			v.from_string(message_content);
			Input3D_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !Input3D_DEFINED

		case kOculus_Prime_Command_v:
#ifdef Oculus_PrimeSerialInterface_DEFINED
		{
/** WB Ptr Class: Oculus_Prime_Command @brief Nil */ 
			class Oculus_Prime_Command_t Oculus_Prime_Command_msg(wbd);
			Oculus_PrimeSerialInterface v = Oculus_Prime_Command_msg.get(); 
			v.from_string(message_content);
			Oculus_Prime_Command_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !Oculus_PrimeSerialInterface_DEFINED

		case kIOPins_v:
#ifdef IOPins_DEFINED
		{
/** WB Ptr Class: IOPins @brief Nil */ 
			class IOPins_t IOPins_msg(wbd);
			IOPins v = IOPins_msg.get(); 
			v.from_string(message_content);
			IOPins_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !IOPins_DEFINED

		case kNXT_Two_Touch_Status_v:
#ifdef NXT_Two_Touch_Status_DEFINED
		{
/** WB Ptr Class: NXT_Two_Touch_Status @brief Nil */ 
			class NXT_Two_Touch_Status_t NXT_Two_Touch_Status_msg(wbd);
			NXT_Two_Touch_Status v = NXT_Two_Touch_Status_msg.get(); 
			v.from_string(message_content);
			NXT_Two_Touch_Status_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !NXT_Two_Touch_Status_DEFINED

		case kNXT_Sound_Control_v:
#ifdef NXT_Sound_Control_DEFINED
		{
/** WB Ptr Class: NXT_Sound_Control @brief Nil */ 
			class NXT_Sound_Control_t NXT_Sound_Control_msg(wbd);
			NXT_Sound_Control v = NXT_Sound_Control_msg.get(); 
			v.from_string(message_content);
			NXT_Sound_Control_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !NXT_Sound_Control_DEFINED

		case kNXT_Lights_Control_v:
#ifdef NXT_Lights_Control_DEFINED
		{
/** WB Ptr Class: NXT_Lights_Control @brief Nil */ 
			class NXT_Lights_Control_t NXT_Lights_Control_msg(wbd);
			NXT_Lights_Control v = NXT_Lights_Control_msg.get(); 
			v.from_string(message_content);
			NXT_Lights_Control_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !NXT_Lights_Control_DEFINED

		case kClocks_v:
#ifdef Clocks_DEFINED
		{
/** WB Ptr Class: Clocks @brief Nil */ 
			class Clocks_t Clocks_msg(wbd);
			Clocks v = Clocks_msg.get(); 
			v.from_string(message_content);
			Clocks_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !Clocks_DEFINED

		case kChannels_v:
#ifdef Channels_DEFINED
		{
/** WB Ptr Class: Channels @brief Nil */ 
			class Channels_t Channels_msg(wbd);
			Channels v = Channels_msg.get(); 
			v.from_string(message_content);
			Channels_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !Channels_DEFINED

		case kSwitchSubsumption_v:
#ifdef SwitchSubsumption_DEFINED
		{
/** WB Ptr Class: SwitchSubsumption @brief Nil */ 
			class SwitchSubsumption_t SwitchSubsumption_msg(wbd);
			SwitchSubsumption v = SwitchSubsumption_msg.get(); 
			v.from_string(message_content);
			SwitchSubsumption_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SwitchSubsumption_DEFINED

		case kTotoDoingMotion_v:
#ifdef TotoDoingMotion_DEFINED
		{
/** WB Ptr Class: TotoDoingMotion @brief Nil */ 
			class TotoDoingMotion_t TotoDoingMotion_msg(wbd);
			TotoDoingMotion v = TotoDoingMotion_msg.get(); 
			v.from_string(message_content);
			TotoDoingMotion_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !TotoDoingMotion_DEFINED

		case kCount_v:
#ifdef wb_count_DEFINED
		{
/** WB Ptr Class: Count @brief Nil */ 
			class Count_t Count_msg(wbd);
			wb_count v = Count_msg.get(); 
			v.from_string(message_content);
			Count_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !wb_count_DEFINED

		case kGreenEWon_v:
		{
/** WB Ptr Class: GreenEWon @brief Nil */ 
			class GreenEWon_t GreenEWon_msg(wbd);
			GreenEWon_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kWarnEW_v:
		{
/** WB Ptr Class: WarnEW @brief Nil */ 
			class WarnEW_t WarnEW_msg(wbd);
			WarnEW_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kTimeGTthirty_v:
		{
/** WB Ptr Class: TimeGTthirty @brief Nil */ 
			class TimeGTthirty_t TimeGTthirty_msg(wbd);
			TimeGTthirty_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kAmberEWon_v:
		{
/** WB Ptr Class: AmberEWon @brief Nil */ 
			class AmberEWon_t AmberEWon_msg(wbd);
			AmberEWon_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kTurnRedEW_v:
		{
/** WB Ptr Class: TurnRedEW @brief Nil */ 
			class TurnRedEW_t TurnRedEW_msg(wbd);
			TurnRedEW_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kTimeGTfive_v:
		{
/** WB Ptr Class: TimeGTfive @brief Nil */ 
			class TimeGTfive_t TimeGTfive_msg(wbd);
			TimeGTfive_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kRedEWon_v:
		{
/** WB Ptr Class: RedEWon @brief Nil */ 
			class RedEWon_t RedEWon_msg(wbd);
			RedEWon_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kGreenNSon_v:
		{
/** WB Ptr Class: GreenNSon @brief Nil */ 
			class GreenNSon_t GreenNSon_msg(wbd);
			GreenNSon_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kWarnNS_v:
		{
/** WB Ptr Class: WarnNS @brief Nil */ 
			class WarnNS_t WarnNS_msg(wbd);
			WarnNS_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kAmberNSon_v:
		{
/** WB Ptr Class: AmberNSon @brief Nil */ 
			class AmberNSon_t AmberNSon_msg(wbd);
			AmberNSon_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kTurnRedNS_v:
		{
/** WB Ptr Class: TurnRedNS @brief Nil */ 
			class TurnRedNS_t TurnRedNS_msg(wbd);
			TurnRedNS_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kRedNSon_v:
		{
/** WB Ptr Class: RedNSon @brief Nil */ 
			class RedNSon_t RedNSon_msg(wbd);
			RedNSon_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kTimerReset_v:
		{
/** WB Ptr Class: TimerReset @brief Nil */ 
			class TimerReset_t TimerReset_msg(wbd);
			TimerReset_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kSLOT_UNUSED_v:
		{
/** WB Ptr Class: SLOT_UNUSED @brief Nil */ 
			class SLOT_UNUSED_t SLOT_UNUSED_msg(wbd);
			SLOT_UNUSED_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kCarSensorPressed_v:
		{
/** WB Ptr Class: CarSensorPressed @brief Nil */ 
			class CarSensorPressed_t CarSensorPressed_msg(wbd);
			CarSensorPressed_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kSwitchSubsumptionTrafficLights_v:
#ifdef SwitchSubsumptionTrafficLights_DEFINED
		{
/** WB Ptr Class: SwitchSubsumptionTrafficLights @brief Nil */ 
			class SwitchSubsumptionTrafficLights_t SwitchSubsumptionTrafficLights_msg(wbd);
			SwitchSubsumptionTrafficLights v = SwitchSubsumptionTrafficLights_msg.get(); 
			v.from_string(message_content);
			SwitchSubsumptionTrafficLights_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !SwitchSubsumptionTrafficLights_DEFINED

		case kBall_Found_v:
		{
/** WB Ptr Class: Ball_Found @brief Nil */ 
			class Ball_Found_t Ball_Found_msg(wbd);
			Ball_Found_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kBall_Calibration_File_v:
		{
/** WB Ptr Class: Ball_Calibration_File @brief Nil */ 
			class Ball_Calibration_File_t Ball_Calibration_File_msg(wbd);
			Ball_Calibration_File_msg.post(std::string(message_content));
			return true;
		}
		case kBall_Calibration_Num_v:
#ifdef int32_t_DEFINED
		{
/** WB Ptr Class: Ball_Calibration_Num @brief Nil */ 
			class Ball_Calibration_Num_t Ball_Calibration_Num_msg(wbd);
			int32_t v = Ball_Calibration_Num_msg.get(); 
			v.from_string(message_content);
			Ball_Calibration_Num_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !int32_t_DEFINED

		case kBall_Color_Num_v:
#ifdef int32_t_DEFINED
		{
/** WB Ptr Class: Ball_Color_Num @brief Nil */ 
			class Ball_Color_Num_t Ball_Color_Num_msg(wbd);
			int32_t v = Ball_Color_Num_msg.get(); 
			v.from_string(message_content);
			Ball_Color_Num_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !int32_t_DEFINED

		case kHAL_LArmTarget_Ctrl_v:
#ifdef HAL_ArmTarget_DEFINED
		{
/** WB Ptr Class: HAL_LArmTarget_Ctrl @brief Nil */ 
			class HAL_LArmTarget_Ctrl_t HAL_LArmTarget_Ctrl_msg(wbd);
			HAL_ArmTarget v = HAL_LArmTarget_Ctrl_msg.get(); 
			v.from_string(message_content);
			HAL_LArmTarget_Ctrl_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !HAL_ArmTarget_DEFINED

		case kHAL_LArmTarget_Stat_v:
#ifdef HAL_ArmTarget_DEFINED
		{
/** WB Ptr Class: HAL_LArmTarget_Stat @brief Nil */ 
			class HAL_LArmTarget_Stat_t HAL_LArmTarget_Stat_msg(wbd);
			HAL_ArmTarget v = HAL_LArmTarget_Stat_msg.get(); 
			v.from_string(message_content);
			HAL_LArmTarget_Stat_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !HAL_ArmTarget_DEFINED

		case kHAL_LArmTarget_Tolr_v:
#ifdef HAL_ArmTarget_DEFINED
		{
/** WB Ptr Class: HAL_LArmTarget_Tolr @brief Nil */ 
			class HAL_LArmTarget_Tolr_t HAL_LArmTarget_Tolr_msg(wbd);
			HAL_ArmTarget v = HAL_LArmTarget_Tolr_msg.get(); 
			v.from_string(message_content);
			HAL_LArmTarget_Tolr_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !HAL_ArmTarget_DEFINED

		case kHAL_RArmTarget_Ctrl_v:
#ifdef HAL_ArmTarget_DEFINED
		{
/** WB Ptr Class: HAL_RArmTarget_Ctrl @brief Nil */ 
			class HAL_RArmTarget_Ctrl_t HAL_RArmTarget_Ctrl_msg(wbd);
			HAL_ArmTarget v = HAL_RArmTarget_Ctrl_msg.get(); 
			v.from_string(message_content);
			HAL_RArmTarget_Ctrl_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !HAL_ArmTarget_DEFINED

		case kHAL_RArmTarget_Stat_v:
#ifdef HAL_ArmTarget_DEFINED
		{
/** WB Ptr Class: HAL_RArmTarget_Stat @brief Nil */ 
			class HAL_RArmTarget_Stat_t HAL_RArmTarget_Stat_msg(wbd);
			HAL_ArmTarget v = HAL_RArmTarget_Stat_msg.get(); 
			v.from_string(message_content);
			HAL_RArmTarget_Stat_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !HAL_ArmTarget_DEFINED

		case kHAL_RArmTarget_Tolr_v:
#ifdef HAL_ArmTarget_DEFINED
		{
/** WB Ptr Class: HAL_RArmTarget_Tolr @brief Nil */ 
			class HAL_RArmTarget_Tolr_t HAL_RArmTarget_Tolr_msg(wbd);
			HAL_ArmTarget v = HAL_RArmTarget_Tolr_msg.get(); 
			v.from_string(message_content);
			HAL_RArmTarget_Tolr_msg.post(v);
			return true;
		}
#else
			return false;
#endif // !HAL_ArmTarget_DEFINED

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
		(void) message_content;
	}

	return false;
#pragma clang diagnostic pop
    }
}

whiteboard_types_map::whiteboard_types_map(): map<string, WBTypes>()
{
	whiteboard_types_map &self = *this;
	// self.reserve(106);

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
	self["SENSORSFootSensors"] = kSENSORSFootSensors_v;
	self["SENSORSBodySensors"] = kSENSORSBodySensors_v;
	self["SENSORSLedsSensors"] = kSENSORSLedsSensors_v;
	self["SENSORSLegJointTemps"] = kSENSORSLegJointTemps_v;
	self["SENSORSTorsoJointTemps"] = kSENSORSTorsoJointTemps_v;
	self["SENSORSLegJointSensors"] = kSENSORSLegJointSensors_v;
	self["SENSORSTorsoJointSensors"] = kSENSORSTorsoJointSensors_v;
	self["SENSORSSonarSensors"] = kSENSORSSonarSensors_v;
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
	self["APM_Status"] = kAPM_Status_v;
	self["APM_Command"] = kAPM_Command_v;
	self["WALK2014_Command"] = kWALK2014_Command_v;
	self["WALK2014_Status"] = kWALK2014_Status_v;
	self["CBall"] = kCBall_v;
	self["OculusPrime_Command"] = kOculusPrime_Command_v;
	self["Input3D"] = kInput3D_v;
	self["Oculus_Prime_Command"] = kOculus_Prime_Command_v;
	self["IOPins"] = kIOPins_v;
	self["NXT_Two_Touch_Status"] = kNXT_Two_Touch_Status_v;
	self["NXT_Sound_Control"] = kNXT_Sound_Control_v;
	self["NXT_Lights_Control"] = kNXT_Lights_Control_v;
	self["Clocks"] = kClocks_v;
	self["Channels"] = kChannels_v;
	self["SwitchSubsumption"] = kSwitchSubsumption_v;
	self["TotoDoingMotion"] = kTotoDoingMotion_v;
	self["A Simple Integer"] = kCount_v;
	self["GreenEWon"] = kGreenEWon_v;
	self["WarnEW"] = kWarnEW_v;
	self["TimeGTthirty"] = kTimeGTthirty_v;
	self["AmberEWon"] = kAmberEWon_v;
	self["TurnRedEW"] = kTurnRedEW_v;
	self["TimeGTfive"] = kTimeGTfive_v;
	self["RedEWon"] = kRedEWon_v;
	self["GreenNSon"] = kGreenNSon_v;
	self["WarnNS"] = kWarnNS_v;
	self["AmberNSon"] = kAmberNSon_v;
	self["TurnRedNS"] = kTurnRedNS_v;
	self["RedNSon"] = kRedNSon_v;
	self["TimerReset"] = kTimerReset_v;
	self["SLOT_UNUSED"] = kSLOT_UNUSED_v;
	self["CarSensorPressed"] = kCarSensorPressed_v;
	self["SwitchSubsumptionTrafficLights"] = kSwitchSubsumptionTrafficLights_v;
	self["Ball_Found"] = kBall_Found_v;
	self["Ball_Calibration_File"] = kBall_Calibration_File_v;
	self["Ball_Calibration_Num"] = kBall_Calibration_Num_v;
	self["Ball_Color_Num"] = kBall_Color_Num_v;
	self["HAL_LArmTarget_Ctrl"] = kHAL_LArmTarget_Ctrl_v;
	self["HAL_LArmTarget_Stat"] = kHAL_LArmTarget_Stat_v;
	self["HAL_LArmTarget_Tolr"] = kHAL_LArmTarget_Tolr_v;
	self["HAL_RArmTarget_Ctrl"] = kHAL_RArmTarget_Ctrl_v;
	self["HAL_RArmTarget_Stat"] = kHAL_RArmTarget_Stat_v;
	self["HAL_RArmTarget_Tolr"] = kHAL_RArmTarget_Tolr_v;

	(void) self;
}

