/** Auto-generated, don't modify! */

#define WHITEBOARD_DESERIALISER


#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

bool deserialisemsg(WBTypes message_index, void *serialised_in, void *message_out)
{
    switch (message_index)
    {
		case kwb_reserved_SubscribeToAllTypes_v: {
			return false;
			break;
		}
		case kPrint_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kSay_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kSpeech_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kQSay_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kQSpeech_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kSpeechOutput_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kGCGameState_v: {
			return false;
			break;
		}
		case kREMOVED1_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kREMOVED2_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kMOTION_Commands_v: {
			return false;
			break;
		}
		case kMOTION_Status_v: {
			return false;
			break;
		}
		case kHAL_HeadTarget_v: {
			return false;
			break;
		}
		case kSENSORSFootSensors_v: {
			return false;
			break;
		}
		case kSENSORSBodySensors_v: {
			return false;
			break;
		}
		case kSENSORSLedsSensors_v: {
			return false;
			break;
		}
		case kSENSORSLegJointTemps_v: {
			return false;
			break;
		}
		case kSENSORSTorsoJointTemps_v: {
			return false;
			break;
		}
		case kSENSORSLegJointSensors_v: {
			return false;
			break;
		}
		case kSENSORSTorsoJointSensors_v: {
			return false;
			break;
		}
		case kSENSORSSonarSensors_v: {
			return false;
			break;
		}
		case kFSM_Control_v: {
			return false;
			break;
		}
		case kFSM_Status_v: {
			return false;
			break;
		}
		case kFSM_Names_v: {
			return false;
			break;
		}
		case kSoloTypeExample_v: {
			return false;
			break;
		}
		case kFilteredGoalSighting_v: {
			return false;
			break;
		}
		case kNAO_State_v: {
			return false;
			break;
		}
		case kUDPRN_v: {
			return false;
			break;
		}
		case kPlayerNumber_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kManuallyPenalized_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kVision_Control_v: {
			return false;
			break;
		}
		case kVision_Status_v: {
			return false;
			break;
		}
		case kFFTStatus_v: {
			return false;
			break;
		}
		case kFSOsighting_v: {
			return false;
			break;
		}
		case kTopParticles_v: {
			return false;
			break;
		}
		case kFilteredBallSighting_v: {
			return false;
			break;
		}
		case kPF_ControlStatus_Modes_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kWEBOTS_NXT_bridge_v: {
			return false;
			break;
		}
		case kWEBOTS_NXT_encoders_v: {
			return false;
			break;
		}
		case kWEBOTS_NXT_camera_v: {
			return false;
			break;
		}
		case kWEBOTS_NXT_walk_isRunning_v: {
			return false;
			break;
		}
		case kWEBOTS_NXT_deadReakoning_walk_v: {
			return false;
			break;
		}
		case kWEBOTS_NXT_colorLine_walk_v: {
			return false;
			break;
		}
		case kWEBOTS_NXT_gridMotions_v: {
			return false;
			break;
		}
		case kVisionBall_v: {
			return false;
			break;
		}
		case kVisionGoals_v: {
			return false;
			break;
		}
		case kWalkData_v: {
			return false;
			break;
		}
		case kTeleoperationControlStatus_v: {
			return false;
			break;
		}
		case kTeleoperationConnection_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kUDPWBNumber_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kWEBOTS_NXT_bumper_v: {
			return false;
			break;
		}
		case kWEBOTS_NXT_vector_bridge_v: {
			return false;
			break;
		}
		case kVisionLines_v: {
			return false;
			break;
		}
		case kDifferentialRobotStatus_v: {
			return false;
			break;
		}
		case kDifferentialRobotControl_v: {
			return false;
			break;
		}
		case kXEyesPos_v: {
			return false;
			break;
		}
		case kVisionFace_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kDraw_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kFSM_States_v: {
			return false;
			break;
		}
		case kGiraff_Interface_Status_v: {
			return false;
			break;
		}
		case kGiraff_Interface_Command_v: {
			return false;
			break;
		}
		case kNXT_Status_v: {
			return false;
			break;
		}
		case kNXT_Command_v: {
			return false;
			break;
		}
		case kAPM_Status_v: {
			return false;
			break;
		}
		case kAPM_Command_v: {
			return false;
			break;
		}
		case kREMOVED3_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kREMOVED4_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kCBall_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kOculusPrime_Command_v: {
			return false;
			break;
		}
		case kInput3D_v: {
			return false;
			break;
		}
		case kOculus_Prime_Command_v: {
			return false;
			break;
		}
		case kIOPins_v: {
			return false;
			break;
		}
		case kNXT_Two_Touch_Status_v: {
			return false;
			break;
		}
		case kNXT_Sound_Control_v: {
			return false;
			break;
		}
		case kNXT_Lights_Control_v: {
			return false;
			break;
		}
		case kClocks_v: {
			return false;
			break;
		}
		case kChannels_v: {
			return false;
			break;
		}
		case kSwitchSubsumption_v: {
			return false;
			break;
		}
		case kTotoDoingMotion_v: {
			return false;
			break;
		}
		case kCount_v: {
			return false;
			break;
		}
		case kGreenEWon_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kWarnEW_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kTimeGTthirty_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kAmberEWon_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kTurnRedEW_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kTimeGTfive_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kRedEWon_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kGreenNSon_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kWarnNS_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kAmberNSon_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kTurnRedNS_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kRedNSon_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kTimerReset_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kSLOT_UNUSED_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kCarSensorPressed_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kSwitchSubsumptionTrafficLights_v: {
			return false;
			break;
		}
		case kBall_Found_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kBall_Calibration_File_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kBall_Calibration_Num_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kBall_Color_Num_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kHAL_LArmTarget_Ctrl_v: {
			return false;
			break;
		}
		case kHAL_LArmTarget_Stat_v: {
			return false;
			break;
		}
		case kHAL_LArmTarget_Tolr_v: {
			return false;
			break;
		}
		case kHAL_RArmTarget_Ctrl_v: {
			return false;
			break;
		}
		case kHAL_RArmTarget_Stat_v: {
			return false;
			break;
		}
		case kHAL_RArmTarget_Tolr_v: {
			return false;
			break;
		}
		case kVisionFieldFeatures_v: {
			return false;
			break;
		}
		case kWhistleBlown_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kVolumeControl_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kVisionRobots_v: {
			return false;
			break;
		}
		case kFieldHorizon_v: {
			return false;
			break;
		}
		case kNaoWalkCommand_v: {
			return false;
			break;
		}
		case kNaoWalkStatus_v: {
			return false;
			break;
		}
	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
    /*(void) message_content;*/
    return true;
#pragma clang diagnostic pop
}
