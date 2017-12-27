/** Auto-generated, don't modify! */

#define WHITEBOARD_SERIALISER

#define COMPRESSION_CALL(...) _to_network_compressed(__VA_ARGS__);
#define COMPRESSION_FUNC_(s, p) s ## p
#define COMPRESSION_FUNC(s, p) COMPRESSION_FUNC_(s, p)
#define SERIALISE(_struct, ...) COMPRESSION_FUNC(_struct, COMPRESSION_CALL(__VA_ARGS__))

#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

bool serialisemsg(WBTypes message_index, void *message_in, void *serialised_out)
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
#ifdef GCGAMESTATE_GENERATED
			SERIALISE(GCGAMESTATE_C_STRUCT, (struct GCGAMESTATE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
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
#ifdef MOTION_COMMANDS_GENERATED
			SERIALISE(MOTION_COMMANDS_C_STRUCT, (struct MOTION_COMMANDS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kMOTION_Status_v: {
#ifdef MOTION_STATUS_GENERATED
			SERIALISE(MOTION_STATUS_C_STRUCT, (struct MOTION_STATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kHAL_HeadTarget_v: {
#ifdef HAL_HEADTARGET_GENERATED
			SERIALISE(HAL_HEADTARGET_C_STRUCT, (struct HAL_HEADTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSENSORSFootSensors_v: {
#ifdef SENSORSFOOTSENSORS_GENERATED
			SERIALISE(SENSORSFOOTSENSORS_C_STRUCT, (struct SENSORSFOOTSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSENSORSBodySensors_v: {
#ifdef SENSORSBODYSENSORS_GENERATED
			SERIALISE(SENSORSBODYSENSORS_C_STRUCT, (struct SENSORSBODYSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSENSORSLedsSensors_v: {
#ifdef SENSORSLEDSSENSORS_GENERATED
			SERIALISE(SENSORSLEDSSENSORS_C_STRUCT, (struct SENSORSLEDSSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSENSORSLegJointTemps_v: {
#ifdef SENSORSLEGJOINTTEMPS_GENERATED
			SERIALISE(SENSORSLEGJOINTTEMPS_C_STRUCT, (struct SENSORSLEGJOINTTEMPS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSENSORSTorsoJointTemps_v: {
#ifdef SENSORSTORSOJOINTTEMPS_GENERATED
			SERIALISE(SENSORSTORSOJOINTTEMPS_C_STRUCT, (struct SENSORSTORSOJOINTTEMPS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSENSORSLegJointSensors_v: {
#ifdef SENSORSLEGJOINTSENSORS_GENERATED
			SERIALISE(SENSORSLEGJOINTSENSORS_C_STRUCT, (struct SENSORSLEGJOINTSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSENSORSTorsoJointSensors_v: {
#ifdef SENSORSTORSOJOINTSENSORS_GENERATED
			SERIALISE(SENSORSTORSOJOINTSENSORS_C_STRUCT, (struct SENSORSTORSOJOINTSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSENSORSSonarSensors_v: {
#ifdef SENSORSSONARSENSORS_GENERATED
			SERIALISE(SENSORSSONARSENSORS_C_STRUCT, (struct SENSORSSONARSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kFSM_Control_v: {
#ifdef FSMCONTROLSTATUS_GENERATED
			SERIALISE(FSMCONTROLSTATUS_C_STRUCT, (struct FSMCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kFSM_Status_v: {
#ifdef FSMCONTROLSTATUS_GENERATED
			SERIALISE(FSMCONTROLSTATUS_C_STRUCT, (struct FSMCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kFSM_Names_v: {
#ifdef FSMNAMES_GENERATED
			SERIALISE(FSMNAMES_C_STRUCT, (struct FSMNAMES_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSoloTypeExample_v: {
			return false;
			break;
		}
		case kFilteredGoalSighting_v: {
#ifdef FILTEREDARRAYONEDIMOBJECTS_GENERATED
			SERIALISE(FILTEREDARRAYONEDIMOBJECTS_C_STRUCT, (struct FILTEREDARRAYONEDIMOBJECTS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kNAO_State_v: {
#ifdef NAO_STATE_GENERATED
			SERIALISE(NAO_STATE_C_STRUCT, (struct NAO_STATE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kUDPRN_v: {
#ifdef GCGAMESTATE_GENERATED
			SERIALISE(GCGAMESTATE_C_STRUCT, (struct GCGAMESTATE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
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
#ifdef VISIONCONTROLSTATUS_GENERATED
			SERIALISE(VISIONCONTROLSTATUS_C_STRUCT, (struct VISIONCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kVision_Status_v: {
#ifdef VISIONCONTROLSTATUS_GENERATED
			SERIALISE(VISIONCONTROLSTATUS_C_STRUCT, (struct VISIONCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kFFTStatus_v: {
#ifdef FFTSTATUS_GENERATED
			SERIALISE(FFTSTATUS_C_STRUCT, (struct FFTSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kFSOsighting_v: {
#ifdef FILTEREDARRAYONEDIMSONAR_GENERATED
			SERIALISE(FILTEREDARRAYONEDIMSONAR_C_STRUCT, (struct FILTEREDARRAYONEDIMSONAR_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kTopParticles_v: {
#ifdef TOPPARTICLES_GENERATED
			SERIALISE(TOPPARTICLES_C_STRUCT, (struct TOPPARTICLES_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kFilteredBallSighting_v: {
#ifdef FILTEREDARRAYBALLSIGHTINGS_GENERATED
			SERIALISE(FILTEREDARRAYBALLSIGHTINGS_C_STRUCT, (struct FILTEREDARRAYBALLSIGHTINGS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kPF_ControlStatus_Modes_v: {
			return false; /*TODO, add support for POD types.*/
			break;
		}
		case kWEBOTS_NXT_bridge_v: {
#ifdef WEBOTS_NXT_BRIDGE_GENERATED
			SERIALISE(WEBOTS_NXT_BRIDGE_C_STRUCT, (struct WEBOTS_NXT_BRIDGE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kWEBOTS_NXT_encoders_v: {
#ifdef WEBOTS_NXT_ENCODERS_GENERATED
			SERIALISE(WEBOTS_NXT_ENCODERS_C_STRUCT, (struct WEBOTS_NXT_ENCODERS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kWEBOTS_NXT_camera_v: {
#ifdef WEBOTS_NXT_CAMERA_GENERATED
			SERIALISE(WEBOTS_NXT_CAMERA_C_STRUCT, (struct WEBOTS_NXT_CAMERA_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kWEBOTS_NXT_walk_isRunning_v: {
#ifdef WEBOTS_NXT_WALK_ISRUNNING_GENERATED
			SERIALISE(WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT, (struct WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kWEBOTS_NXT_deadReakoning_walk_v: {
#ifdef WEBOTS_NXT_DEADREAKONING_WALK_GENERATED
			SERIALISE(WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT, (struct WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kWEBOTS_NXT_colorLine_walk_v: {
#ifdef WEBOTS_NXT_COLORLINE_WALK_GENERATED
			SERIALISE(WEBOTS_NXT_COLORLINE_WALK_C_STRUCT, (struct WEBOTS_NXT_COLORLINE_WALK_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kWEBOTS_NXT_gridMotions_v: {
#ifdef WEBOTS_NXT_GRIDMOTIONS_GENERATED
			SERIALISE(WEBOTS_NXT_GRIDMOTIONS_C_STRUCT, (struct WEBOTS_NXT_GRIDMOTIONS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kVisionBall_v: {
#ifdef VISIONBALL_GENERATED
			SERIALISE(VISIONBALL_C_STRUCT, (struct VISIONBALL_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kVisionGoals_v: {
#ifdef VISIONGOALS_GENERATED
			SERIALISE(VISIONGOALS_C_STRUCT, (struct VISIONGOALS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kWalkData_v: {
#ifdef WALKDATA_GENERATED
			SERIALISE(WALKDATA_C_STRUCT, (struct WALKDATA_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kTeleoperationControlStatus_v: {
#ifdef TELEOPERATIONCONTROLSTATUS_GENERATED
			SERIALISE(TELEOPERATIONCONTROLSTATUS_C_STRUCT, (struct TELEOPERATIONCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
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
#ifdef WEBOTS_NXT_BUMPER_GENERATED
			SERIALISE(WEBOTS_NXT_BUMPER_C_STRUCT, (struct WEBOTS_NXT_BUMPER_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kWEBOTS_NXT_vector_bridge_v: {
#ifdef WEBOTS_NXT_VECTOR_BRIDGE_GENERATED
			SERIALISE(WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT, (struct WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kVisionLines_v: {
#ifdef VISIONLINES_GENERATED
			SERIALISE(VISIONLINES_C_STRUCT, (struct VISIONLINES_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kDifferentialRobotStatus_v: {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_GENERATED
			SERIALISE(DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT, (struct DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kDifferentialRobotControl_v: {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_GENERATED
			SERIALISE(DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT, (struct DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kXEyesPos_v: {
#ifdef POINT2D_GENERATED
			SERIALISE(POINT2D_C_STRUCT, (struct POINT2D_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
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
#ifdef FSMSTATE_GENERATED
			SERIALISE(FSMSTATE_C_STRUCT, (struct FSMSTATE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kGiraff_Interface_Status_v: {
#ifdef GIRAFF_MAINSERIALINTERFACE_GENERATED
			SERIALISE(GIRAFF_MAINSERIALINTERFACE_C_STRUCT, (struct GIRAFF_MAINSERIALINTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kGiraff_Interface_Command_v: {
#ifdef GIRAFF_MAINSERIALINTERFACE_GENERATED
			SERIALISE(GIRAFF_MAINSERIALINTERFACE_C_STRUCT, (struct GIRAFF_MAINSERIALINTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kNXT_Status_v: {
#ifdef NXT_INTERFACE_GENERATED
			SERIALISE(NXT_INTERFACE_C_STRUCT, (struct NXT_INTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kNXT_Command_v: {
#ifdef NXT_INTERFACE_GENERATED
			SERIALISE(NXT_INTERFACE_C_STRUCT, (struct NXT_INTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kAPM_Status_v: {
#ifdef APM_INTERFACE_GENERATED
			SERIALISE(APM_INTERFACE_C_STRUCT, (struct APM_INTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kAPM_Command_v: {
#ifdef APM_INTERFACE_GENERATED
			SERIALISE(APM_INTERFACE_C_STRUCT, (struct APM_INTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
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
#ifdef OCULUSPRIMEINTERFACE_GENERATED
			SERIALISE(OCULUSPRIMEINTERFACE_C_STRUCT, (struct OCULUSPRIMEINTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kInput3D_v: {
#ifdef INPUT3D_GENERATED
			SERIALISE(INPUT3D_C_STRUCT, (struct INPUT3D_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kOculus_Prime_Command_v: {
#ifdef OCULUS_PRIMESERIALINTERFACE_GENERATED
			SERIALISE(OCULUS_PRIMESERIALINTERFACE_C_STRUCT, (struct OCULUS_PRIMESERIALINTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kIOPins_v: {
#ifdef IOPINS_GENERATED
			SERIALISE(IOPINS_C_STRUCT, (struct IOPINS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kNXT_Two_Touch_Status_v: {
#ifdef NXT_TWO_TOUCH_STATUS_GENERATED
			SERIALISE(NXT_TWO_TOUCH_STATUS_C_STRUCT, (struct NXT_TWO_TOUCH_STATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kNXT_Sound_Control_v: {
#ifdef NXT_SOUND_CONTROL_GENERATED
			SERIALISE(NXT_SOUND_CONTROL_C_STRUCT, (struct NXT_SOUND_CONTROL_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kNXT_Lights_Control_v: {
#ifdef NXT_LIGHTS_CONTROL_GENERATED
			SERIALISE(NXT_LIGHTS_CONTROL_C_STRUCT, (struct NXT_LIGHTS_CONTROL_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kClocks_v: {
#ifdef CLOCKS_GENERATED
			SERIALISE(CLOCKS_C_STRUCT, (struct CLOCKS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kChannels_v: {
#ifdef CHANNELS_GENERATED
			SERIALISE(CHANNELS_C_STRUCT, (struct CHANNELS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kSwitchSubsumption_v: {
#ifdef SWITCHSUBSUMPTION_GENERATED
			SERIALISE(SWITCHSUBSUMPTION_C_STRUCT, (struct SWITCHSUBSUMPTION_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kTotoDoingMotion_v: {
#ifdef TOTODOINGMOTION_GENERATED
			SERIALISE(TOTODOINGMOTION_C_STRUCT, (struct TOTODOINGMOTION_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kCount_v: {
#ifdef WB_COUNT_GENERATED
			SERIALISE(WB_COUNT_C_STRUCT, (struct WB_COUNT_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
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
#ifdef SWITCHSUBSUMPTIONTRAFFICLIGHTS_GENERATED
			SERIALISE(SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT, (struct SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
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
#ifdef HAL_ARMTARGET_GENERATED
			SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kHAL_LArmTarget_Stat_v: {
#ifdef HAL_ARMTARGET_GENERATED
			SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kHAL_LArmTarget_Tolr_v: {
#ifdef HAL_ARMTARGET_GENERATED
			SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kHAL_RArmTarget_Ctrl_v: {
#ifdef HAL_ARMTARGET_GENERATED
			SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kHAL_RArmTarget_Stat_v: {
#ifdef HAL_ARMTARGET_GENERATED
			SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kHAL_RArmTarget_Tolr_v: {
#ifdef HAL_ARMTARGET_GENERATED
			SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kVisionFieldFeatures_v: {
#ifdef VISIONFIELDFEATURES_GENERATED
			SERIALISE(VISIONFIELDFEATURES_C_STRUCT, (struct VISIONFIELDFEATURES_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
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
#ifdef VISIONROBOTS_GENERATED
			SERIALISE(VISIONROBOTS_C_STRUCT, (struct VISIONROBOTS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kFieldHorizon_v: {
#ifdef FIELDHORIZON_GENERATED
			SERIALISE(FIELDHORIZON_C_STRUCT, (struct FIELDHORIZON_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kNaoWalkCommand_v: {
#ifdef NAOWALKCOMMAND_GENERATED
			SERIALISE(NAOWALKCOMMAND_C_STRUCT, (struct NAOWALKCOMMAND_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
		case kNaoWalkStatus_v: {
#ifdef NAOWALKSTATUS_GENERATED
			SERIALISE(NAOWALKSTATUS_C_STRUCT, (struct NAOWALKSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return false;
#endif
			break;
		}
	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
    /*(void) message_content;*/
    return true;
#pragma clang diagnostic pop
}
