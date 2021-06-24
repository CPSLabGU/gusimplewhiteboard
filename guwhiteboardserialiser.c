/**
 *  /file guwhiteboardserialiser.c
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

/** Auto-generated, don't modify! */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wcast-qual"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wunreachable-code-break"

#ifndef WB_GUWHITEBOARDSERIALISER_C
#define WB_GUWHITEBOARDSERIALISER_C


#define WHITEBOARD_SERIALISER

#define COMPRESSION_CALL(...) _to_network_serialised(__VA_ARGS__);
#define COMPRESSION_FUNC_(s, p) s ## p
#define COMPRESSION_FUNC(s, p) COMPRESSION_FUNC_(s, p)
#define SERIALISE(_struct, ...) COMPRESSION_FUNC(_struct, COMPRESSION_CALL(__VA_ARGS__))

#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

int32_t serialisemsg(wb_types message_index, const void *message_in, void *serialised_out)
{
    switch (message_index)
    {

            case kwb_wb_reserved_SubscribeToAllTypes_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Print_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Say_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Speech_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_QSay_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_QSpeech_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_SpeechOutput_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_GCGameState_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsHandSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsHeadSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_MOTION_Commands_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_MOTION_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_HeadTarget_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsFootSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsBodySensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLedsSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLegJointTemps_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSTorsoJointTemps_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLegJointSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSTorsoJointSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSSonarSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Names_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SoloTypeExample_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_FilteredGoalSighting_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NAO_State_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_UDPRN_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_PlayerNumber_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_ManuallyPenalized_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_VisionControl_v:
            {
#ifdef VISION_CONTROL_STATUS_GENERATED
                return SERIALISE(VISION_CONTROL_STATUS_C_STRUCT, (struct VISION_CONTROL_STATUS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_VisionStatus_v:
            {
#ifdef VISION_CONTROL_STATUS_GENERATED
                return SERIALISE(VISION_CONTROL_STATUS_C_STRUCT, (struct VISION_CONTROL_STATUS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_FFTStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSOsighting_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TopParticles_v:
            {
#ifdef TOPPARTICLES_GENERATED
                return SERIALISE(TOPPARTICLES_C_STRUCT, (struct TOPPARTICLES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //TOPPARTICLES_GENERATED
                break;
            }
            case kwb_FilteredBallSighting_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_PF_ControlStatus_Modes_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_WEBOTS_NXT_bridge_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_encoders_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_camera_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_walk_isRunning_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_deadReakoning_walk_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_colorLine_walk_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_gridMotions_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionBall_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionGoals_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WalkData_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TeleoperationControlStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TeleoperationConnection_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_UDPWBNumber_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_WEBOTS_NXT_bumper_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_vector_bridge_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TopVisionLines_v:
            {
#ifdef VISION_LINES_GENERATED
                return SERIALISE(VISION_LINES_C_STRUCT, (struct VISION_LINES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_LINES_GENERATED
                break;
            }
            case kwb_BottomVisionLines_v:
            {
#ifdef VISION_LINES_GENERATED
                return SERIALISE(VISION_LINES_C_STRUCT, (struct VISION_LINES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_LINES_GENERATED
                break;
            }
            case kwb_DifferentialRobotStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_DifferentialRobotControl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_XEyesPos_v:
            {
#ifdef POINT2D_GENERATED
                return SERIALISE(POINT2D_C_STRUCT, (struct POINT2D_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //POINT2D_GENERATED
                break;
            }
            case kwb_VisionFace_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Draw_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_FSM_States_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Giraff_Interface_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Giraff_Interface_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_APM_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_APM_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_REMOVED3_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_REMOVED4_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_CBall_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_OculusPrime_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Input3D_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Oculus_Prime_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_IOPins_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Two_Touch_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Sound_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Lights_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Clocks_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Channels_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SwitchSubsumption_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TotoDoingMotion_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Count_v:
            {
#ifdef COUNT_GENERATED
                return SERIALISE(COUNT_C_STRUCT, (struct COUNT_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //COUNT_GENERATED
                break;
            }
            case kwb_GreenEWon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_WarnEW_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_TimeGTthirty_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_AmberEWon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_TurnRedEW_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_TimeGTfive_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_RedEWon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_GreenNSon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_WarnNS_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_AmberNSon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_TurnRedNS_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_RedNSon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_TimerReset_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_SLOT_UNUSED_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_CarSensorPressed_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_SwitchSubsumptionTrafficLights_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Ball_Found_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Ball_Calibration_File_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Ball_Calibration_Num_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Ball_Color_Num_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_HAL_LArmTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LArmTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LArmTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionFieldFeatures_v:
            {
#ifdef VISION_FIELD_FEATURES_GENERATED
                return SERIALISE(VISION_FIELD_FEATURES_C_STRUCT, (struct VISION_FIELD_FEATURES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_FIELD_FEATURES_GENERATED
                break;
            }
            case kwb_WhistleBlown_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_VolumeControl_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_VisionRobots_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionDetectionHorizons_v:
            {
#ifdef VISION_DETECTION_HORIZONS_GENERATED
                return SERIALISE(VISION_DETECTION_HORIZONS_C_STRUCT, (struct VISION_DETECTION_HORIZONS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_DETECTION_HORIZONS_GENERATED
                break;
            }
            case kwb_NaoWalkCommand_v:
            {
#ifdef NAOWALKCOMMAND_GENERATED
                return SERIALISE(NAOWALKCOMMAND_C_STRUCT, (struct NAOWALKCOMMAND_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //NAOWALKCOMMAND_GENERATED
                break;
            }
            case kwb_NaoWalkStatus_v:
            {
#ifdef NAOWALKSTATUS_GENERATED
                return SERIALISE(NAOWALKSTATUS_C_STRUCT, (struct NAOWALKSTATUS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //NAOWALKSTATUS_GENERATED
                break;
            }
            case kwb_HAL_LLegTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LLegTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LLegTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionDetectionGoals_v:
            {
#ifdef VISION_DETECTION_GOALS_GENERATED
                return SERIALISE(VISION_DETECTION_GOALS_C_STRUCT, (struct VISION_DETECTION_GOALS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_DETECTION_GOALS_GENERATED
                break;
            }
            case kwb_TeleoperationControl_v:
            {
#ifdef TELEOPERATIONCONTROL_GENERATED
                return SERIALISE(TELEOPERATIONCONTROL_C_STRUCT, (struct TELEOPERATIONCONTROL_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //TELEOPERATIONCONTROL_GENERATED
                break;
            }
            case kwb_TeleoperationStatus_v:
            {
#ifdef TELEOPERATIONSTATUS_GENERATED
                return SERIALISE(TELEOPERATIONSTATUS_C_STRUCT, (struct TELEOPERATIONSTATUS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //TELEOPERATIONSTATUS_GENERATED
                break;
            }
            case kwb_VisionDetectionBalls_v:
            {
#ifdef VISION_DETECTION_BALLS_GENERATED
                return SERIALISE(VISION_DETECTION_BALLS_C_STRUCT, (struct VISION_DETECTION_BALLS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_DETECTION_BALLS_GENERATED
                break;
            }
            case kwb_TeleoperationControlVR_v:
            {
#ifdef TELEOPERATIONCONTROLVR_GENERATED
                return SERIALISE(TELEOPERATIONCONTROLVR_C_STRUCT, (struct TELEOPERATIONCONTROLVR_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //TELEOPERATIONCONTROLVR_GENERATED
                break;
            }
            case kwb_ParticleOutputMap_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_ParticleOutputMapControl_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_FFTControl_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_MachineFilteredNaoVision_v:
            {
#ifdef MACHINE_FILTERED_VISION_GENERATED
                return SERIALISE(MACHINE_FILTERED_VISION_C_STRUCT, (struct MACHINE_FILTERED_VISION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //MACHINE_FILTERED_VISION_GENERATED
                break;
            }
            case kwb_MicrowaveStatus_v:
            {
#ifdef MICROWAVE_STATUS_GENERATED
                return SERIALISE(MICROWAVE_STATUS_C_STRUCT, (struct MICROWAVE_STATUS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //MICROWAVE_STATUS_GENERATED
                break;
            }
            case kwb_Buttons_v:
            {
#ifdef BUTTONS_GENERATED
                return SERIALISE(BUTTONS_C_STRUCT, (struct BUTTONS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //BUTTONS_GENERATED
                break;
            }
            case kwb_MachineFilteredLocalisationVision_v:
            {
#ifdef MACHINE_FILTERED_LOCALISATION_VISION_GENERATED
                return SERIALISE(MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT, (struct MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //MACHINE_FILTERED_LOCALISATION_VISION_GENERATED
                break;
            }
            case kwb_SensorsJointCurrent_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return SERIALISE(NotSupportedWithLegacyNaming, (struct NotSupportedWithLegacyNaming *)message_in, serialised_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_DataLogger_v:
            {
#ifdef DATA_LOGGER_GENERATED
                return SERIALISE(DATA_LOGGER_C_STRUCT, (struct DATA_LOGGER_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //DATA_LOGGER_GENERATED
                break;
            }
            case kwb_MachineFilteredLines_v:
            {
#ifdef MACHINE_FILTERED_LINES_GENERATED
                return SERIALISE(MACHINE_FILTERED_LINES_C_STRUCT, (struct MACHINE_FILTERED_LINES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //MACHINE_FILTERED_LINES_GENERATED
                break;
            }
            case kwb_BallLocation_v:
            {
#ifdef LOCATION_GENERATED
                return SERIALISE(LOCATION_C_STRUCT, (struct LOCATION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kwb_LeftGoalPostLocation_v:
            {
#ifdef LOCATION_GENERATED
                return SERIALISE(LOCATION_C_STRUCT, (struct LOCATION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kwb_RightGoalPostLocation_v:
            {
#ifdef LOCATION_GENERATED
                return SERIALISE(LOCATION_C_STRUCT, (struct LOCATION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kwb_GoalLocation_v:
            {
#ifdef LOCATION_GENERATED
                return SERIALISE(LOCATION_C_STRUCT, (struct LOCATION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kwb_NaoSonarProtectedWalkCommand_v:
            {
#ifdef NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED
                return SERIALISE(NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT, (struct NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED
                break;
            }
            case kwb_NaoObstacleDirection_v:
            {
#ifdef NAO_OBSTACLE_DIRECTION_GENERATED
                return SERIALISE(NAO_OBSTACLE_DIRECTION_C_STRUCT, (struct NAO_OBSTACLE_DIRECTION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //NAO_OBSTACLE_DIRECTION_GENERATED
                break;
            }
            case kwb_DominantFrequencies_v:
            {
#ifdef DOMINANT_FREQUENCIES_GENERATED
                return SERIALISE(DOMINANT_FREQUENCIES_C_STRUCT, (struct DOMINANT_FREQUENCIES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //DOMINANT_FREQUENCIES_GENERATED
                break;
            }
            case kwb_MissionPriorityForObstacles_v:
            {
#ifdef MISSION_PRIORITY_FOR_OBSTACLES_GENERATED
                return SERIALISE(MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT, (struct MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //MISSION_PRIORITY_FOR_OBSTACLES_GENERATED
                break;
            }
            case kwb_WavLoad_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_WavPlay_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_ReproduceWavNotSilent_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_FrequencyControl_v:
            {
#ifdef FREQUENCY_LIMITS_GENERATED
                return SERIALISE(FREQUENCY_LIMITS_C_STRUCT, (struct FREQUENCY_LIMITS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //FREQUENCY_LIMITS_GENERATED
                break;
            }
            case kwb_FrequencyStatus_v:
            {
#ifdef FREQUENCY_LIMITS_GENERATED
                return SERIALISE(FREQUENCY_LIMITS_C_STRUCT, (struct FREQUENCY_LIMITS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //FREQUENCY_LIMITS_GENERATED
                break;
            }
            case kwb_HeadJointSensors_v:
            {
#ifdef HEAD_JOINT_SENSORS_GENERATED
                return SERIALISE(HEAD_JOINT_SENSORS_C_STRUCT, (struct HEAD_JOINT_SENSORS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //HEAD_JOINT_SENSORS_GENERATED
                break;
            }
            case kwb_AdjustPositionConfidence_v:
            {
#ifdef ADJUST_POSITION_CONFIDENCE_GENERATED
                return SERIALISE(ADJUST_POSITION_CONFIDENCE_C_STRUCT, (struct ADJUST_POSITION_CONFIDENCE_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //ADJUST_POSITION_CONFIDENCE_GENERATED
                break;
            }
            case kwb_GuVrTeleopVulkanControl_v:
            {
#ifdef GU_VR_TELEOP_VULKAN_CONTROL_GENERATED
                return SERIALISE(GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT, (struct GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //GU_VR_TELEOP_VULKAN_CONTROL_GENERATED
                break;
            }
            case kwb_TemperatureSensors_v:
            {
#ifdef TEMPERATURE_SENSORS_GENERATED
                return SERIALISE(TEMPERATURE_SENSORS_C_STRUCT, (struct TEMPERATURE_SENSORS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //TEMPERATURE_SENSORS_GENERATED
                break;
            }
            case kwb_Overheating_v:
            {
#ifdef OVERHEATING_GENERATED
                return SERIALISE(OVERHEATING_C_STRUCT, (struct OVERHEATING_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //OVERHEATING_GENERATED
                break;
            }
            case kwb_buttonPushed_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_doorOpen_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_timeLeft_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_motor_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_sound_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_light_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino2Pin_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino2PinValue_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino3Pin_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino3PinValue_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino4Pin_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino4PinValue_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino5Pin_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino5PinValue_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino6Pin_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino6PinValue_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino7Pin_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino7PinValue_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino8Pin_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino8PinValue_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino9Pin_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_Arduino9PinValue_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_BallPosition_v:
            {
#ifdef BALL_POSITION_GENERATED
                return SERIALISE(BALL_POSITION_C_STRUCT, (struct BALL_POSITION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //BALL_POSITION_GENERATED
                break;
            }
            case kwb_MemoryImageControl_v:
            {
#ifdef MEMORY_IMAGE_CONTROL_STATUS_GENERATED
                return SERIALISE(MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT, (struct MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //MEMORY_IMAGE_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_MemoryImageStatus_v:
            {
#ifdef MEMORY_IMAGE_CONTROL_STATUS_GENERATED
                return SERIALISE(MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT, (struct MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //MEMORY_IMAGE_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_LHandGripper_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_RHandGripper_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kwb_MyPosition_v:
            {
#ifdef MY_POSITION_GENERATED
                return SERIALISE(MY_POSITION_C_STRUCT, (struct MY_POSITION_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //MY_POSITION_GENERATED
                break;
            }
            case kwb_VisionDetectionLines_v:
            {
#ifdef VISION_DETECTION_LINES_GENERATED
                return SERIALISE(VISION_DETECTION_LINES_C_STRUCT, (struct VISION_DETECTION_LINES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_DETECTION_LINES_GENERATED
                break;
            }
            case kwb_VisionDetectionFeatures_v:
            {
#ifdef VISION_DETECTION_FEATURES_GENERATED
                return SERIALISE(VISION_DETECTION_FEATURES_C_STRUCT, (struct VISION_DETECTION_FEATURES_C_STRUCT *)message_in, serialised_out)
#else
                return -1;
#endif //VISION_DETECTION_FEATURES_GENERATED
                break;
            }
    }
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
    /*(void) message_content;*/
    return -1;
#pragma clang diagnostic pop
}

#endif //WB_GUWHITEBOARDSERIALISER_C

#pragma clang diagnostic pop
