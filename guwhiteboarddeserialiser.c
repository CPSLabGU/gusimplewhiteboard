/** Auto-generated, don't modify! */

#define WHITEBOARD_DESERIALISER


#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

size_t deserialisemsg(WBTypes message_index, void *serialised_in, void *message_out)
{
    switch (message_index)
    {
		case kwb_reserved_SubscribeToAllTypes_v: {
			return -1;
			break;
		}
		case kPrint_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kSay_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kSpeech_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kQSay_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kQSpeech_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kSpeechOutput_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kGCGameState_v: {
			return -1;
			break;
		}
		case kREMOVED1_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kREMOVED2_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kMOTION_Commands_v: {
			return -1;
			break;
		}
		case kMOTION_Status_v: {
			return -1;
			break;
		}
		case kHAL_HeadTarget_v: {
			return -1;
			break;
		}
		case kSENSORSFootSensors_v: {
			return -1;
			break;
		}
		case kSENSORSBodySensors_v: {
			return -1;
			break;
		}
		case kSENSORSLedsSensors_v: {
			return -1;
			break;
		}
		case kSENSORSLegJointTemps_v: {
			return -1;
			break;
		}
		case kSENSORSTorsoJointTemps_v: {
			return -1;
			break;
		}
		case kSENSORSLegJointSensors_v: {
			return -1;
			break;
		}
		case kSENSORSTorsoJointSensors_v: {
			return -1;
			break;
		}
		case kSENSORSSonarSensors_v: {
			return -1;
			break;
		}
		case kFSM_Control_v: {
			return -1;
			break;
		}
		case kFSM_Status_v: {
			return -1;
			break;
		}
		case kFSM_Names_v: {
			return -1;
			break;
		}
		case kSoloTypeExample_v: {
			return -1;
			break;
		}
		case kFilteredGoalSighting_v: {
			return -1;
			break;
		}
		case kNAO_State_v: {
			return -1;
			break;
		}
		case kUDPRN_v: {
			return -1;
			break;
		}
		case kPlayerNumber_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kManuallyPenalized_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kVision_Control_v: {
			return -1;
			break;
		}
		case kVision_Status_v: {
			return -1;
			break;
		}
		case kFFTStatus_v: {
			return -1;
			break;
		}
		case kFSOsighting_v: {
			return -1;
			break;
		}
		case kTopParticles_v: {
			return -1;
			break;
		}
		case kFilteredBallSighting_v: {
			return -1;
			break;
		}
		case kPF_ControlStatus_Modes_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kWEBOTS_NXT_bridge_v: {
			return -1;
			break;
		}
		case kWEBOTS_NXT_encoders_v: {
			return -1;
			break;
		}
		case kWEBOTS_NXT_camera_v: {
			return -1;
			break;
		}
		case kWEBOTS_NXT_walk_isRunning_v: {
			return -1;
			break;
		}
		case kWEBOTS_NXT_deadReakoning_walk_v: {
			return -1;
			break;
		}
		case kWEBOTS_NXT_colorLine_walk_v: {
			return -1;
			break;
		}
		case kWEBOTS_NXT_gridMotions_v: {
			return -1;
			break;
		}
		case kVisionBall_v: {
			return -1;
			break;
		}
		case kVisionGoals_v: {
			return -1;
			break;
		}
		case kWalkData_v: {
			return -1;
			break;
		}
		case kTeleoperationControlStatus_v: {
			return -1;
			break;
		}
		case kTeleoperationConnection_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kUDPWBNumber_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kWEBOTS_NXT_bumper_v: {
			return -1;
			break;
		}
		case kWEBOTS_NXT_vector_bridge_v: {
			return -1;
			break;
		}
		case kVisionLines_v: {
			return -1;
			break;
		}
		case kDifferentialRobotStatus_v: {
			return -1;
			break;
		}
		case kDifferentialRobotControl_v: {
			return -1;
			break;
		}
		case kXEyesPos_v: {
			return -1;
			break;
		}
		case kVisionFace_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kDraw_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kFSM_States_v: {
			return -1;
			break;
		}
		case kGiraff_Interface_Status_v: {
			return -1;
			break;
		}
		case kGiraff_Interface_Command_v: {
			return -1;
			break;
		}
		case kNXT_Status_v: {
			return -1;
			break;
		}
		case kNXT_Command_v: {
			return -1;
			break;
		}
		case kAPM_Status_v: {
			return -1;
			break;
		}
		case kAPM_Command_v: {
			return -1;
			break;
		}
		case kREMOVED3_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kREMOVED4_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kCBall_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kOculusPrime_Command_v: {
			return -1;
			break;
		}
		case kInput3D_v: {
			return -1;
			break;
		}
		case kOculus_Prime_Command_v: {
			return -1;
			break;
		}
		case kIOPins_v: {
			return -1;
			break;
		}
		case kNXT_Two_Touch_Status_v: {
			return -1;
			break;
		}
		case kNXT_Sound_Control_v: {
			return -1;
			break;
		}
		case kNXT_Lights_Control_v: {
			return -1;
			break;
		}
		case kClocks_v: {
			return -1;
			break;
		}
		case kChannels_v: {
			return -1;
			break;
		}
		case kSwitchSubsumption_v: {
			return -1;
			break;
		}
		case kTotoDoingMotion_v: {
			return -1;
			break;
		}
		case kCount_v: {
			return -1;
			break;
		}
		case kGreenEWon_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kWarnEW_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kTimeGTthirty_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kAmberEWon_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kTurnRedEW_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kTimeGTfive_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kRedEWon_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kGreenNSon_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kWarnNS_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kAmberNSon_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kTurnRedNS_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kRedNSon_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kTimerReset_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kSLOT_UNUSED_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kCarSensorPressed_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kSwitchSubsumptionTrafficLights_v: {
			return -1;
			break;
		}
		case kBall_Found_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kBall_Calibration_File_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kBall_Calibration_Num_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kBall_Color_Num_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kHAL_LArmTarget_Ctrl_v: {
			return -1;
			break;
		}
		case kHAL_LArmTarget_Stat_v: {
			return -1;
			break;
		}
		case kHAL_LArmTarget_Tolr_v: {
			return -1;
			break;
		}
		case kHAL_RArmTarget_Ctrl_v: {
			return -1;
			break;
		}
		case kHAL_RArmTarget_Stat_v: {
			return -1;
			break;
		}
		case kHAL_RArmTarget_Tolr_v: {
			return -1;
			break;
		}
		case kVisionFieldFeatures_v: {
			return -1;
			break;
		}
		case kWhistleBlown_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kVolumeControl_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kVisionRobots_v: {
			return -1;
			break;
		}
		case kFieldHorizon_v: {
			return -1;
			break;
		}
		case kNaoWalkCommand_v: {
			return -1;
			break;
		}
		case kNaoWalkStatus_v: {
			return -1;
			break;
		}
	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
    /*(void) message_content;*/
    return true;
#pragma clang diagnostic pop
}
