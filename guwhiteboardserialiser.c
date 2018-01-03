/** Auto-generated, don't modify! */

#define WHITEBOARD_SERIALISER

#define COMPRESSION_CALL(...) _to_network_serialised(__VA_ARGS__);
#define COMPRESSION_FUNC_(s, p) s ## p
#define COMPRESSION_FUNC(s, p) COMPRESSION_FUNC_(s, p)
#define SERIALISE(_struct, ...) COMPRESSION_FUNC(_struct, COMPRESSION_CALL(__VA_ARGS__))

#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

size_t serialisemsg(WBTypes message_index, void *message_in, void *serialised_out)
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
#ifdef GCGAMESTATE_GENERATED
			return SERIALISE(GCGAMESTATE_C_STRUCT, (struct GCGAMESTATE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
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
#ifdef MOTION_COMMANDS_GENERATED
			return SERIALISE(MOTION_COMMANDS_C_STRUCT, (struct MOTION_COMMANDS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kMOTION_Status_v: {
#ifdef MOTION_STATUS_GENERATED
			return SERIALISE(MOTION_STATUS_C_STRUCT, (struct MOTION_STATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_HeadTarget_v: {
#ifdef HAL_HEADTARGET_GENERATED
			return SERIALISE(HAL_HEADTARGET_C_STRUCT, (struct HAL_HEADTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSFootSensors_v: {
#ifdef SENSORSFOOTSENSORS_GENERATED
			return SERIALISE(SENSORSFOOTSENSORS_C_STRUCT, (struct SENSORSFOOTSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSBodySensors_v: {
#ifdef SENSORSBODYSENSORS_GENERATED
			return SERIALISE(SENSORSBODYSENSORS_C_STRUCT, (struct SENSORSBODYSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSLedsSensors_v: {
#ifdef SENSORSLEDSSENSORS_GENERATED
			return SERIALISE(SENSORSLEDSSENSORS_C_STRUCT, (struct SENSORSLEDSSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSLegJointTemps_v: {
#ifdef SENSORSLEGJOINTTEMPS_GENERATED
			return SERIALISE(SENSORSLEGJOINTTEMPS_C_STRUCT, (struct SENSORSLEGJOINTTEMPS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSTorsoJointTemps_v: {
#ifdef SENSORSTORSOJOINTTEMPS_GENERATED
			return SERIALISE(SENSORSTORSOJOINTTEMPS_C_STRUCT, (struct SENSORSTORSOJOINTTEMPS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSLegJointSensors_v: {
#ifdef SENSORSLEGJOINTSENSORS_GENERATED
			return SERIALISE(SENSORSLEGJOINTSENSORS_C_STRUCT, (struct SENSORSLEGJOINTSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSTorsoJointSensors_v: {
#ifdef SENSORSTORSOJOINTSENSORS_GENERATED
			return SERIALISE(SENSORSTORSOJOINTSENSORS_C_STRUCT, (struct SENSORSTORSOJOINTSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSSonarSensors_v: {
#ifdef SENSORSSONARSENSORS_GENERATED
			return SERIALISE(SENSORSSONARSENSORS_C_STRUCT, (struct SENSORSSONARSENSORS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kFSM_Control_v: {
#ifdef FSMCONTROLSTATUS_GENERATED
			return SERIALISE(FSMCONTROLSTATUS_C_STRUCT, (struct FSMCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kFSM_Status_v: {
#ifdef FSMCONTROLSTATUS_GENERATED
			return SERIALISE(FSMCONTROLSTATUS_C_STRUCT, (struct FSMCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kFSM_Names_v: {
#ifdef FSMNAMES_GENERATED
			return SERIALISE(FSMNAMES_C_STRUCT, (struct FSMNAMES_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSoloTypeExample_v: {
			return -1;
			break;
		}
		case kFilteredGoalSighting_v: {
#ifdef FILTEREDARRAYONEDIMOBJECTS_GENERATED
			return SERIALISE(FILTEREDARRAYONEDIMOBJECTS_C_STRUCT, (struct FILTEREDARRAYONEDIMOBJECTS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kNAO_State_v: {
#ifdef NAO_STATE_GENERATED
			return SERIALISE(NAO_STATE_C_STRUCT, (struct NAO_STATE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kUDPRN_v: {
#ifdef GCGAMESTATE_GENERATED
			return SERIALISE(GCGAMESTATE_C_STRUCT, (struct GCGAMESTATE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
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
#ifdef VISIONCONTROLSTATUS_GENERATED
			return SERIALISE(VISIONCONTROLSTATUS_C_STRUCT, (struct VISIONCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kVision_Status_v: {
#ifdef VISIONCONTROLSTATUS_GENERATED
			return SERIALISE(VISIONCONTROLSTATUS_C_STRUCT, (struct VISIONCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kFFTStatus_v: {
#ifdef FFTSTATUS_GENERATED
			return SERIALISE(FFTSTATUS_C_STRUCT, (struct FFTSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kFSOsighting_v: {
#ifdef FILTEREDARRAYONEDIMSONAR_GENERATED
			return SERIALISE(FILTEREDARRAYONEDIMSONAR_C_STRUCT, (struct FILTEREDARRAYONEDIMSONAR_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kTopParticles_v: {
#ifdef TOPPARTICLES_GENERATED
			return SERIALISE(TOPPARTICLES_C_STRUCT, (struct TOPPARTICLES_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kFilteredBallSighting_v: {
#ifdef FILTEREDARRAYBALLSIGHTINGS_GENERATED
			return SERIALISE(FILTEREDARRAYBALLSIGHTINGS_C_STRUCT, (struct FILTEREDARRAYBALLSIGHTINGS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kPF_ControlStatus_Modes_v: {
			return -1; /*TODO, add support for POD types.*/
			break;
		}
		case kWEBOTS_NXT_bridge_v: {
#ifdef WEBOTS_NXT_BRIDGE_GENERATED
			return SERIALISE(WEBOTS_NXT_BRIDGE_C_STRUCT, (struct WEBOTS_NXT_BRIDGE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_encoders_v: {
#ifdef WEBOTS_NXT_ENCODERS_GENERATED
			return SERIALISE(WEBOTS_NXT_ENCODERS_C_STRUCT, (struct WEBOTS_NXT_ENCODERS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_camera_v: {
#ifdef WEBOTS_NXT_CAMERA_GENERATED
			return SERIALISE(WEBOTS_NXT_CAMERA_C_STRUCT, (struct WEBOTS_NXT_CAMERA_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_walk_isRunning_v: {
#ifdef WEBOTS_NXT_WALK_ISRUNNING_GENERATED
			return SERIALISE(WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT, (struct WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_deadReakoning_walk_v: {
#ifdef WEBOTS_NXT_DEADREAKONING_WALK_GENERATED
			return SERIALISE(WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT, (struct WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_colorLine_walk_v: {
#ifdef WEBOTS_NXT_COLORLINE_WALK_GENERATED
			return SERIALISE(WEBOTS_NXT_COLORLINE_WALK_C_STRUCT, (struct WEBOTS_NXT_COLORLINE_WALK_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_gridMotions_v: {
#ifdef WEBOTS_NXT_GRIDMOTIONS_GENERATED
			return SERIALISE(WEBOTS_NXT_GRIDMOTIONS_C_STRUCT, (struct WEBOTS_NXT_GRIDMOTIONS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kVisionBall_v: {
#ifdef VISIONBALL_GENERATED
			return SERIALISE(VISIONBALL_C_STRUCT, (struct VISIONBALL_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kVisionGoals_v: {
#ifdef VISIONGOALS_GENERATED
			return SERIALISE(VISIONGOALS_C_STRUCT, (struct VISIONGOALS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kWalkData_v: {
#ifdef WALKDATA_GENERATED
			return SERIALISE(WALKDATA_C_STRUCT, (struct WALKDATA_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kTeleoperationControlStatus_v: {
#ifdef TELEOPERATIONCONTROLSTATUS_GENERATED
			return SERIALISE(TELEOPERATIONCONTROLSTATUS_C_STRUCT, (struct TELEOPERATIONCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
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
#ifdef WEBOTS_NXT_BUMPER_GENERATED
			return SERIALISE(WEBOTS_NXT_BUMPER_C_STRUCT, (struct WEBOTS_NXT_BUMPER_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_vector_bridge_v: {
#ifdef WEBOTS_NXT_VECTOR_BRIDGE_GENERATED
			return SERIALISE(WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT, (struct WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kVisionLines_v: {
#ifdef VISIONLINES_GENERATED
			return SERIALISE(VISIONLINES_C_STRUCT, (struct VISIONLINES_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kDifferentialRobotStatus_v: {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_GENERATED
			return SERIALISE(DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT, (struct DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kDifferentialRobotControl_v: {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_GENERATED
			return SERIALISE(DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT, (struct DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kXEyesPos_v: {
#ifdef POINT2D_GENERATED
			return SERIALISE(POINT2D_C_STRUCT, (struct POINT2D_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
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
#ifdef FSMSTATE_GENERATED
			return SERIALISE(FSMSTATE_C_STRUCT, (struct FSMSTATE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kGiraff_Interface_Status_v: {
#ifdef GIRAFF_MAINSERIALINTERFACE_GENERATED
			return SERIALISE(GIRAFF_MAINSERIALINTERFACE_C_STRUCT, (struct GIRAFF_MAINSERIALINTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kGiraff_Interface_Command_v: {
#ifdef GIRAFF_MAINSERIALINTERFACE_GENERATED
			return SERIALISE(GIRAFF_MAINSERIALINTERFACE_C_STRUCT, (struct GIRAFF_MAINSERIALINTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Status_v: {
#ifdef NXT_INTERFACE_GENERATED
			return SERIALISE(NXT_INTERFACE_C_STRUCT, (struct NXT_INTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Command_v: {
#ifdef NXT_INTERFACE_GENERATED
			return SERIALISE(NXT_INTERFACE_C_STRUCT, (struct NXT_INTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kAPM_Status_v: {
#ifdef APM_INTERFACE_GENERATED
			return SERIALISE(APM_INTERFACE_C_STRUCT, (struct APM_INTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kAPM_Command_v: {
#ifdef APM_INTERFACE_GENERATED
			return SERIALISE(APM_INTERFACE_C_STRUCT, (struct APM_INTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
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
#ifdef OCULUSPRIMEINTERFACE_GENERATED
			return SERIALISE(OCULUSPRIMEINTERFACE_C_STRUCT, (struct OCULUSPRIMEINTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kInput3D_v: {
#ifdef INPUT3D_GENERATED
			return SERIALISE(INPUT3D_C_STRUCT, (struct INPUT3D_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kOculus_Prime_Command_v: {
#ifdef OCULUS_PRIMESERIALINTERFACE_GENERATED
			return SERIALISE(OCULUS_PRIMESERIALINTERFACE_C_STRUCT, (struct OCULUS_PRIMESERIALINTERFACE_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kIOPins_v: {
#ifdef IOPINS_GENERATED
			return SERIALISE(IOPINS_C_STRUCT, (struct IOPINS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Two_Touch_Status_v: {
#ifdef NXT_TWO_TOUCH_STATUS_GENERATED
			return SERIALISE(NXT_TWO_TOUCH_STATUS_C_STRUCT, (struct NXT_TWO_TOUCH_STATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Sound_Control_v: {
#ifdef NXT_SOUND_CONTROL_GENERATED
			return SERIALISE(NXT_SOUND_CONTROL_C_STRUCT, (struct NXT_SOUND_CONTROL_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Lights_Control_v: {
#ifdef NXT_LIGHTS_CONTROL_GENERATED
			return SERIALISE(NXT_LIGHTS_CONTROL_C_STRUCT, (struct NXT_LIGHTS_CONTROL_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kClocks_v: {
#ifdef CLOCKS_GENERATED
			return SERIALISE(CLOCKS_C_STRUCT, (struct CLOCKS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kChannels_v: {
#ifdef CHANNELS_GENERATED
			return SERIALISE(CHANNELS_C_STRUCT, (struct CHANNELS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kSwitchSubsumption_v: {
#ifdef SWITCHSUBSUMPTION_GENERATED
			return SERIALISE(SWITCHSUBSUMPTION_C_STRUCT, (struct SWITCHSUBSUMPTION_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kTotoDoingMotion_v: {
#ifdef TOTODOINGMOTION_GENERATED
			return SERIALISE(TOTODOINGMOTION_C_STRUCT, (struct TOTODOINGMOTION_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kCount_v: {
#ifdef WB_COUNT_GENERATED
			return SERIALISE(WB_COUNT_C_STRUCT, (struct WB_COUNT_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
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
#ifdef SWITCHSUBSUMPTIONTRAFFICLIGHTS_GENERATED
			return SERIALISE(SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT, (struct SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
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
#ifdef HAL_ARMTARGET_GENERATED
			return SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_LArmTarget_Stat_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_LArmTarget_Tolr_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_RArmTarget_Ctrl_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_RArmTarget_Stat_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_RArmTarget_Tolr_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return SERIALISE(HAL_ARMTARGET_C_STRUCT, (struct HAL_ARMTARGET_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kVisionFieldFeatures_v: {
#ifdef VISIONFIELDFEATURES_GENERATED
			return SERIALISE(VISIONFIELDFEATURES_C_STRUCT, (struct VISIONFIELDFEATURES_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
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
#ifdef VISIONROBOTS_GENERATED
			return SERIALISE(VISIONROBOTS_C_STRUCT, (struct VISIONROBOTS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kFieldHorizon_v: {
#ifdef FIELDHORIZON_GENERATED
			return SERIALISE(FIELDHORIZON_C_STRUCT, (struct FIELDHORIZON_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kNaoWalkCommand_v: {
#ifdef NAOWALKCOMMAND_GENERATED
			return SERIALISE(NAOWALKCOMMAND_C_STRUCT, (struct NAOWALKCOMMAND_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
		case kNaoWalkStatus_v: {
#ifdef NAOWALKSTATUS_GENERATED
			return SERIALISE(NAOWALKSTATUS_C_STRUCT, (struct NAOWALKSTATUS_C_STRUCT *)message_in, serialised_out)
#else
			return -1;
#endif
			break;
		}
	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
    /*(void) message_content;*/
    return -1;
#pragma clang diagnostic pop
}
