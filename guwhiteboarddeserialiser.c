/** Auto-generated, don't modify! */

#define WHITEBOARD_DESERIALISER

#define DECOMPRESSION_CALL(...) _from_network_serialised(__VA_ARGS__);
#define DECOMPRESSION_FUNC_(s, p) s ## p
#define DECOMPRESSION_FUNC(s, p) DECOMPRESSION_FUNC_(s, p)
#define DESERIALISE(_struct, ...) DECOMPRESSION_FUNC(_struct, DECOMPRESSION_CALL(__VA_ARGS__))

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
#ifdef GCGAMESTATE_GENERATED
			return DESERIALISE(GCGAMESTATE_C_STRUCT, serialised_in, (struct GCGAMESTATE_C_STRUCT *)message_out)
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
			return DESERIALISE(MOTION_COMMANDS_C_STRUCT, serialised_in, (struct MOTION_COMMANDS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kMOTION_Status_v: {
#ifdef MOTION_STATUS_GENERATED
			return DESERIALISE(MOTION_STATUS_C_STRUCT, serialised_in, (struct MOTION_STATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_HeadTarget_v: {
#ifdef HAL_HEADTARGET_GENERATED
			return DESERIALISE(HAL_HEADTARGET_C_STRUCT, serialised_in, (struct HAL_HEADTARGET_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSFootSensors_v: {
#ifdef SENSORSFOOTSENSORS_GENERATED
			return DESERIALISE(SENSORSFOOTSENSORS_C_STRUCT, serialised_in, (struct SENSORSFOOTSENSORS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSBodySensors_v: {
#ifdef SENSORSBODYSENSORS_GENERATED
			return DESERIALISE(SENSORSBODYSENSORS_C_STRUCT, serialised_in, (struct SENSORSBODYSENSORS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSLedsSensors_v: {
#ifdef SENSORSLEDSSENSORS_GENERATED
			return DESERIALISE(SENSORSLEDSSENSORS_C_STRUCT, serialised_in, (struct SENSORSLEDSSENSORS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSLegJointTemps_v: {
#ifdef SENSORSLEGJOINTTEMPS_GENERATED
			return DESERIALISE(SENSORSLEGJOINTTEMPS_C_STRUCT, serialised_in, (struct SENSORSLEGJOINTTEMPS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSTorsoJointTemps_v: {
#ifdef SENSORSTORSOJOINTTEMPS_GENERATED
			return DESERIALISE(SENSORSTORSOJOINTTEMPS_C_STRUCT, serialised_in, (struct SENSORSTORSOJOINTTEMPS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSLegJointSensors_v: {
#ifdef SENSORSLEGJOINTSENSORS_GENERATED
			return DESERIALISE(SENSORSLEGJOINTSENSORS_C_STRUCT, serialised_in, (struct SENSORSLEGJOINTSENSORS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSTorsoJointSensors_v: {
#ifdef SENSORSTORSOJOINTSENSORS_GENERATED
			return DESERIALISE(SENSORSTORSOJOINTSENSORS_C_STRUCT, serialised_in, (struct SENSORSTORSOJOINTSENSORS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSENSORSSonarSensors_v: {
#ifdef SENSORSSONARSENSORS_GENERATED
			return DESERIALISE(SENSORSSONARSENSORS_C_STRUCT, serialised_in, (struct SENSORSSONARSENSORS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kFSM_Control_v: {
#ifdef FSMCONTROLSTATUS_GENERATED
			return DESERIALISE(FSMCONTROLSTATUS_C_STRUCT, serialised_in, (struct FSMCONTROLSTATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kFSM_Status_v: {
#ifdef FSMCONTROLSTATUS_GENERATED
			return DESERIALISE(FSMCONTROLSTATUS_C_STRUCT, serialised_in, (struct FSMCONTROLSTATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kFSM_Names_v: {
#ifdef FSMNAMES_GENERATED
			return DESERIALISE(FSMNAMES_C_STRUCT, serialised_in, (struct FSMNAMES_C_STRUCT *)message_out)
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
			return DESERIALISE(FILTEREDARRAYONEDIMOBJECTS_C_STRUCT, serialised_in, (struct FILTEREDARRAYONEDIMOBJECTS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kNAO_State_v: {
#ifdef NAO_STATE_GENERATED
			return DESERIALISE(NAO_STATE_C_STRUCT, serialised_in, (struct NAO_STATE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kUDPRN_v: {
#ifdef GCGAMESTATE_GENERATED
			return DESERIALISE(GCGAMESTATE_C_STRUCT, serialised_in, (struct GCGAMESTATE_C_STRUCT *)message_out)
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
			return DESERIALISE(VISIONCONTROLSTATUS_C_STRUCT, serialised_in, (struct VISIONCONTROLSTATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kVision_Status_v: {
#ifdef VISIONCONTROLSTATUS_GENERATED
			return DESERIALISE(VISIONCONTROLSTATUS_C_STRUCT, serialised_in, (struct VISIONCONTROLSTATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kFFTStatus_v: {
#ifdef FFTSTATUS_GENERATED
			return DESERIALISE(FFTSTATUS_C_STRUCT, serialised_in, (struct FFTSTATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kFSOsighting_v: {
#ifdef FILTEREDARRAYONEDIMSONAR_GENERATED
			return DESERIALISE(FILTEREDARRAYONEDIMSONAR_C_STRUCT, serialised_in, (struct FILTEREDARRAYONEDIMSONAR_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kTopParticles_v: {
#ifdef TOPPARTICLES_GENERATED
			return DESERIALISE(TOPPARTICLES_C_STRUCT, serialised_in, (struct TOPPARTICLES_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kFilteredBallSighting_v: {
#ifdef FILTEREDARRAYBALLSIGHTINGS_GENERATED
			return DESERIALISE(FILTEREDARRAYBALLSIGHTINGS_C_STRUCT, serialised_in, (struct FILTEREDARRAYBALLSIGHTINGS_C_STRUCT *)message_out)
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
			return DESERIALISE(WEBOTS_NXT_BRIDGE_C_STRUCT, serialised_in, (struct WEBOTS_NXT_BRIDGE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_encoders_v: {
#ifdef WEBOTS_NXT_ENCODERS_GENERATED
			return DESERIALISE(WEBOTS_NXT_ENCODERS_C_STRUCT, serialised_in, (struct WEBOTS_NXT_ENCODERS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_camera_v: {
#ifdef WEBOTS_NXT_CAMERA_GENERATED
			return DESERIALISE(WEBOTS_NXT_CAMERA_C_STRUCT, serialised_in, (struct WEBOTS_NXT_CAMERA_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_walk_isRunning_v: {
#ifdef WEBOTS_NXT_WALK_ISRUNNING_GENERATED
			return DESERIALISE(WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT, serialised_in, (struct WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_deadReakoning_walk_v: {
#ifdef WEBOTS_NXT_DEADREAKONING_WALK_GENERATED
			return DESERIALISE(WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT, serialised_in, (struct WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_colorLine_walk_v: {
#ifdef WEBOTS_NXT_COLORLINE_WALK_GENERATED
			return DESERIALISE(WEBOTS_NXT_COLORLINE_WALK_C_STRUCT, serialised_in, (struct WEBOTS_NXT_COLORLINE_WALK_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_gridMotions_v: {
#ifdef WEBOTS_NXT_GRIDMOTIONS_GENERATED
			return DESERIALISE(WEBOTS_NXT_GRIDMOTIONS_C_STRUCT, serialised_in, (struct WEBOTS_NXT_GRIDMOTIONS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kVisionBall_v: {
#ifdef VISIONBALL_GENERATED
			return DESERIALISE(VISIONBALL_C_STRUCT, serialised_in, (struct VISIONBALL_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kVisionGoals_v: {
#ifdef VISIONGOALS_GENERATED
			return DESERIALISE(VISIONGOALS_C_STRUCT, serialised_in, (struct VISIONGOALS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kWalkData_v: {
#ifdef WALKDATA_GENERATED
			return DESERIALISE(WALKDATA_C_STRUCT, serialised_in, (struct WALKDATA_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kTeleoperationControlStatus_v: {
#ifdef TELEOPERATIONCONTROLSTATUS_GENERATED
			return DESERIALISE(TELEOPERATIONCONTROLSTATUS_C_STRUCT, serialised_in, (struct TELEOPERATIONCONTROLSTATUS_C_STRUCT *)message_out)
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
			return DESERIALISE(WEBOTS_NXT_BUMPER_C_STRUCT, serialised_in, (struct WEBOTS_NXT_BUMPER_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kWEBOTS_NXT_vector_bridge_v: {
#ifdef WEBOTS_NXT_VECTOR_BRIDGE_GENERATED
			return DESERIALISE(WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT, serialised_in, (struct WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kVisionLines_v: {
#ifdef VISIONLINES_GENERATED
			return DESERIALISE(VISIONLINES_C_STRUCT, serialised_in, (struct VISIONLINES_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kDifferentialRobotStatus_v: {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_GENERATED
			return DESERIALISE(DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT, serialised_in, (struct DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kDifferentialRobotControl_v: {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_GENERATED
			return DESERIALISE(DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT, serialised_in, (struct DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kXEyesPos_v: {
#ifdef POINT2D_GENERATED
			return DESERIALISE(POINT2D_C_STRUCT, serialised_in, (struct POINT2D_C_STRUCT *)message_out)
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
			return DESERIALISE(FSMSTATE_C_STRUCT, serialised_in, (struct FSMSTATE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kGiraff_Interface_Status_v: {
#ifdef GIRAFF_MAINSERIALINTERFACE_GENERATED
			return DESERIALISE(GIRAFF_MAINSERIALINTERFACE_C_STRUCT, serialised_in, (struct GIRAFF_MAINSERIALINTERFACE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kGiraff_Interface_Command_v: {
#ifdef GIRAFF_MAINSERIALINTERFACE_GENERATED
			return DESERIALISE(GIRAFF_MAINSERIALINTERFACE_C_STRUCT, serialised_in, (struct GIRAFF_MAINSERIALINTERFACE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Status_v: {
#ifdef NXT_INTERFACE_GENERATED
			return DESERIALISE(NXT_INTERFACE_C_STRUCT, serialised_in, (struct NXT_INTERFACE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Command_v: {
#ifdef NXT_INTERFACE_GENERATED
			return DESERIALISE(NXT_INTERFACE_C_STRUCT, serialised_in, (struct NXT_INTERFACE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kAPM_Status_v: {
#ifdef APM_INTERFACE_GENERATED
			return DESERIALISE(APM_INTERFACE_C_STRUCT, serialised_in, (struct APM_INTERFACE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kAPM_Command_v: {
#ifdef APM_INTERFACE_GENERATED
			return DESERIALISE(APM_INTERFACE_C_STRUCT, serialised_in, (struct APM_INTERFACE_C_STRUCT *)message_out)
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
			return DESERIALISE(OCULUSPRIMEINTERFACE_C_STRUCT, serialised_in, (struct OCULUSPRIMEINTERFACE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kInput3D_v: {
#ifdef INPUT3D_GENERATED
			return DESERIALISE(INPUT3D_C_STRUCT, serialised_in, (struct INPUT3D_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kOculus_Prime_Command_v: {
#ifdef OCULUS_PRIMESERIALINTERFACE_GENERATED
			return DESERIALISE(OCULUS_PRIMESERIALINTERFACE_C_STRUCT, serialised_in, (struct OCULUS_PRIMESERIALINTERFACE_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kIOPins_v: {
#ifdef IOPINS_GENERATED
			return DESERIALISE(IOPINS_C_STRUCT, serialised_in, (struct IOPINS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Two_Touch_Status_v: {
#ifdef NXT_TWO_TOUCH_STATUS_GENERATED
			return DESERIALISE(NXT_TWO_TOUCH_STATUS_C_STRUCT, serialised_in, (struct NXT_TWO_TOUCH_STATUS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Sound_Control_v: {
#ifdef NXT_SOUND_CONTROL_GENERATED
			return DESERIALISE(NXT_SOUND_CONTROL_C_STRUCT, serialised_in, (struct NXT_SOUND_CONTROL_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kNXT_Lights_Control_v: {
#ifdef NXT_LIGHTS_CONTROL_GENERATED
			return DESERIALISE(NXT_LIGHTS_CONTROL_C_STRUCT, serialised_in, (struct NXT_LIGHTS_CONTROL_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kClocks_v: {
#ifdef CLOCKS_GENERATED
			return DESERIALISE(CLOCKS_C_STRUCT, serialised_in, (struct CLOCKS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kChannels_v: {
#ifdef CHANNELS_GENERATED
			return DESERIALISE(CHANNELS_C_STRUCT, serialised_in, (struct CHANNELS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kSwitchSubsumption_v: {
#ifdef SWITCHSUBSUMPTION_GENERATED
			return DESERIALISE(SWITCHSUBSUMPTION_C_STRUCT, serialised_in, (struct SWITCHSUBSUMPTION_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kTotoDoingMotion_v: {
#ifdef TOTODOINGMOTION_GENERATED
			return DESERIALISE(TOTODOINGMOTION_C_STRUCT, serialised_in, (struct TOTODOINGMOTION_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kCount_v: {
#ifdef WB_COUNT_GENERATED
			return DESERIALISE(WB_COUNT_C_STRUCT, serialised_in, (struct WB_COUNT_C_STRUCT *)message_out)
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
			return DESERIALISE(SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT, serialised_in, (struct SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT *)message_out)
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
			return DESERIALISE(HAL_ARMTARGET_C_STRUCT, serialised_in, (struct HAL_ARMTARGET_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_LArmTarget_Stat_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return DESERIALISE(HAL_ARMTARGET_C_STRUCT, serialised_in, (struct HAL_ARMTARGET_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_LArmTarget_Tolr_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return DESERIALISE(HAL_ARMTARGET_C_STRUCT, serialised_in, (struct HAL_ARMTARGET_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_RArmTarget_Ctrl_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return DESERIALISE(HAL_ARMTARGET_C_STRUCT, serialised_in, (struct HAL_ARMTARGET_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_RArmTarget_Stat_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return DESERIALISE(HAL_ARMTARGET_C_STRUCT, serialised_in, (struct HAL_ARMTARGET_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kHAL_RArmTarget_Tolr_v: {
#ifdef HAL_ARMTARGET_GENERATED
			return DESERIALISE(HAL_ARMTARGET_C_STRUCT, serialised_in, (struct HAL_ARMTARGET_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kVisionFieldFeatures_v: {
#ifdef VISIONFIELDFEATURES_GENERATED
			return DESERIALISE(VISIONFIELDFEATURES_C_STRUCT, serialised_in, (struct VISIONFIELDFEATURES_C_STRUCT *)message_out)
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
			return DESERIALISE(VISIONROBOTS_C_STRUCT, serialised_in, (struct VISIONROBOTS_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kFieldHorizon_v: {
#ifdef FIELDHORIZON_GENERATED
			return DESERIALISE(FIELDHORIZON_C_STRUCT, serialised_in, (struct FIELDHORIZON_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kNaoWalkCommand_v: {
#ifdef NAOWALKCOMMAND_GENERATED
			return DESERIALISE(NAOWALKCOMMAND_C_STRUCT, serialised_in, (struct NAOWALKCOMMAND_C_STRUCT *)message_out)
#else
			return -1;
#endif
			break;
		}
		case kNaoWalkStatus_v: {
#ifdef NAOWALKSTATUS_GENERATED
			return DESERIALISE(NAOWALKSTATUS_C_STRUCT, serialised_in, (struct NAOWALKSTATUS_C_STRUCT *)message_out)
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
