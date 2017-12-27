/** Auto-generated, don't modify! */

#define WHITEBOARD_DESERIALISER


#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

bool deserialisemsg(WBTypes message_index, void *serialised_in, void *message_out)
{
    switch (message_index)
    {
		case kwb_reserved_SubscribeToAllTypes_v:
			return false;
		case kPrint_v:
			return false; /*TODO, add support for POD types.*/
		case kSay_v:
			return false; /*TODO, add support for POD types.*/
		case kSpeech_v:
			return false; /*TODO, add support for POD types.*/
		case kQSay_v:
			return false; /*TODO, add support for POD types.*/
		case kQSpeech_v:
			return false; /*TODO, add support for POD types.*/
		case kSpeechOutput_v:
			return false; /*TODO, add support for POD types.*/
		case kGCGameState_v:
			return false;
		case kREMOVED1_v:
			return false; /*TODO, add support for POD types.*/
		case kREMOVED2_v:
			return false; /*TODO, add support for POD types.*/
		case kMOTION_Commands_v:
			return false;
		case kMOTION_Status_v:
			return false;
		case kHAL_HeadTarget_v:
			return false;
		case kSENSORSFootSensors_v:
			return false;
		case kSENSORSBodySensors_v:
			return false;
		case kSENSORSLedsSensors_v:
			return false;
		case kSENSORSLegJointTemps_v:
			return false;
		case kSENSORSTorsoJointTemps_v:
			return false;
		case kSENSORSLegJointSensors_v:
			return false;
		case kSENSORSTorsoJointSensors_v:
			return false;
		case kSENSORSSonarSensors_v:
			return false;
		case kFSM_Control_v:
			return false;
		case kFSM_Status_v:
			return false;
		case kFSM_Names_v:
			return false;
		case kSoloTypeExample_v:
			return false;
		case kFilteredGoalSighting_v:
			return false;
		case kNAO_State_v:
			return false;
		case kUDPRN_v:
			return false;
		case kPlayerNumber_v:
			return false; /*TODO, add support for POD types.*/
		case kManuallyPenalized_v:
			return false; /*TODO, add support for POD types.*/
		case kVision_Control_v:
			return false;
		case kVision_Status_v:
			return false;
		case kFFTStatus_v:
			return false;
		case kFSOsighting_v:
			return false;
		case kTopParticles_v:
			return false;
		case kFilteredBallSighting_v:
			return false;
		case kPF_ControlStatus_Modes_v:
			return false; /*TODO, add support for POD types.*/
		case kWEBOTS_NXT_bridge_v:
			return false;
		case kWEBOTS_NXT_encoders_v:
			return false;
		case kWEBOTS_NXT_camera_v:
			return false;
		case kWEBOTS_NXT_walk_isRunning_v:
			return false;
		case kWEBOTS_NXT_deadReakoning_walk_v:
			return false;
		case kWEBOTS_NXT_colorLine_walk_v:
			return false;
		case kWEBOTS_NXT_gridMotions_v:
			return false;
		case kVisionBall_v:
			return false;
		case kVisionGoals_v:
			return false;
		case kWalkData_v:
			return false;
		case kTeleoperationControlStatus_v:
			return false;
		case kTeleoperationConnection_v:
			return false; /*TODO, add support for POD types.*/
		case kUDPWBNumber_v:
			return false; /*TODO, add support for POD types.*/
		case kWEBOTS_NXT_bumper_v:
			return false;
		case kWEBOTS_NXT_vector_bridge_v:
			return false;
		case kVisionLines_v:
			return false;
		case kDifferentialRobotStatus_v:
			return false;
		case kDifferentialRobotControl_v:
			return false;
		case kXEyesPos_v:
			return false;
		case kVisionFace_v:
			return false; /*TODO, add support for POD types.*/
		case kDraw_v:
			return false; /*TODO, add support for POD types.*/
		case kFSM_States_v:
			return false;
		case kGiraff_Interface_Status_v:
			return false;
		case kGiraff_Interface_Command_v:
			return false;
		case kNXT_Status_v:
			return false;
		case kNXT_Command_v:
			return false;
		case kAPM_Status_v:
			return false;
		case kAPM_Command_v:
			return false;
		case kREMOVED3_v:
			return false; /*TODO, add support for POD types.*/
		case kREMOVED4_v:
			return false; /*TODO, add support for POD types.*/
		case kCBall_v:
			return false; /*TODO, add support for POD types.*/
		case kOculusPrime_Command_v:
			return false;
		case kInput3D_v:
			return false;
		case kOculus_Prime_Command_v:
			return false;
		case kIOPins_v:
			return false;
		case kNXT_Two_Touch_Status_v:
			return false;
		case kNXT_Sound_Control_v:
			return false;
		case kNXT_Lights_Control_v:
			return false;
		case kClocks_v:
			return false;
		case kChannels_v:
			return false;
		case kSwitchSubsumption_v:
			return false;
		case kTotoDoingMotion_v:
			return false;
		case kCount_v:
			return false;
		case kGreenEWon_v:
			return false; /*TODO, add support for POD types.*/
		case kWarnEW_v:
			return false; /*TODO, add support for POD types.*/
		case kTimeGTthirty_v:
			return false; /*TODO, add support for POD types.*/
		case kAmberEWon_v:
			return false; /*TODO, add support for POD types.*/
		case kTurnRedEW_v:
			return false; /*TODO, add support for POD types.*/
		case kTimeGTfive_v:
			return false; /*TODO, add support for POD types.*/
		case kRedEWon_v:
			return false; /*TODO, add support for POD types.*/
		case kGreenNSon_v:
			return false; /*TODO, add support for POD types.*/
		case kWarnNS_v:
			return false; /*TODO, add support for POD types.*/
		case kAmberNSon_v:
			return false; /*TODO, add support for POD types.*/
		case kTurnRedNS_v:
			return false; /*TODO, add support for POD types.*/
		case kRedNSon_v:
			return false; /*TODO, add support for POD types.*/
		case kTimerReset_v:
			return false; /*TODO, add support for POD types.*/
		case kSLOT_UNUSED_v:
			return false; /*TODO, add support for POD types.*/
		case kCarSensorPressed_v:
			return false; /*TODO, add support for POD types.*/
		case kSwitchSubsumptionTrafficLights_v:
			return false;
		case kBall_Found_v:
			return false; /*TODO, add support for POD types.*/
		case kBall_Calibration_File_v:
			return false; /*TODO, add support for POD types.*/
		case kBall_Calibration_Num_v:
			return false; /*TODO, add support for POD types.*/
		case kBall_Color_Num_v:
			return false; /*TODO, add support for POD types.*/
		case kHAL_LArmTarget_Ctrl_v:
			return false;
		case kHAL_LArmTarget_Stat_v:
			return false;
		case kHAL_LArmTarget_Tolr_v:
			return false;
		case kHAL_RArmTarget_Ctrl_v:
			return false;
		case kHAL_RArmTarget_Stat_v:
			return false;
		case kHAL_RArmTarget_Tolr_v:
			return false;
		case kVisionFieldFeatures_v:
			return false;
		case kWhistleBlown_v:
			return false; /*TODO, add support for POD types.*/
		case kVolumeControl_v:
			return false; /*TODO, add support for POD types.*/
		case kVisionRobots_v:
			return false;
		case kFieldHorizon_v:
			return false;
		case kNaoWalkCommand_v:
			return false;
		case kNaoWalkStatus_v:
			return false;
	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
    /*(void) message_content;*/
    return false;
#pragma clang diagnostic pop
}
