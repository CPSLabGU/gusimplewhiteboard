/**
 *  /file guwhiteboarddeserialiser.c
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

#ifndef WB_GUWHITEBOARDDESERIALISER_C
#define WB_GUWHITEBOARDDESERIALISER_C

#define WHITEBOARD_DESERIALISER

#define DECOMPRESSION_CALL(...) _from_network_serialised(__VA_ARGS__);
#define DECOMPRESSION_FUNC_(s, p) s ## p
#define DECOMPRESSION_FUNC(s, p) DECOMPRESSION_FUNC_(s, p)
#define DESERIALISE(_struct, ...) DECOMPRESSION_FUNC(_struct, DECOMPRESSION_CALL(__VA_ARGS__))

#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

int32_t deserialisemsg(wb_types message_index, const void *serialised_in, void *message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsHandSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsHeadSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_MOTION_Commands_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_MOTION_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_HeadTarget_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsFootSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsBodySensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLedsSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLegJointTemps_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSTorsoJointTemps_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLegJointSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSTorsoJointSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSSonarSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Names_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NAO_State_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_UDPRN_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
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
                return DESERIALISE(VISION_CONTROL_STATUS_C_STRUCT, serialised_in, (struct VISION_CONTROL_STATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_VisionStatus_v:
            {
#ifdef VISION_CONTROL_STATUS_GENERATED
                return DESERIALISE(VISION_CONTROL_STATUS_C_STRUCT, serialised_in, (struct VISION_CONTROL_STATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_FFTStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSOsighting_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TopParticles_v:
            {
#ifdef TOPPARTICLES_GENERATED
                return DESERIALISE(TOPPARTICLES_C_STRUCT, serialised_in, (struct TOPPARTICLES_C_STRUCT *)message_out)
#else
                return -1;
#endif //TOPPARTICLES_GENERATED
                break;
            }
            case kwb_FilteredBallSighting_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_encoders_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_camera_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_walk_isRunning_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_deadReakoning_walk_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_colorLine_walk_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_gridMotions_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionBall_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionGoals_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WalkData_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TeleoperationControlStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_vector_bridge_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TopVisionLines_v:
            {
#ifdef VISION_LINES_GENERATED
                return DESERIALISE(VISION_LINES_C_STRUCT, serialised_in, (struct VISION_LINES_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_LINES_GENERATED
                break;
            }
            case kwb_BottomVisionLines_v:
            {
#ifdef VISION_LINES_GENERATED
                return DESERIALISE(VISION_LINES_C_STRUCT, serialised_in, (struct VISION_LINES_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_LINES_GENERATED
                break;
            }
            case kwb_DifferentialRobotStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_DifferentialRobotControl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_XEyesPos_v:
            {
#ifdef POINT2D_GENERATED
                return DESERIALISE(POINT2D_C_STRUCT, serialised_in, (struct POINT2D_C_STRUCT *)message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Giraff_Interface_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Giraff_Interface_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_APM_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_APM_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Input3D_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Oculus_Prime_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_IOPins_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Two_Touch_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Sound_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Lights_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Clocks_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Channels_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SwitchSubsumption_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TotoDoingMotion_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Count_v:
            {
#ifdef COUNT_GENERATED
                return DESERIALISE(COUNT_C_STRUCT, serialised_in, (struct COUNT_C_STRUCT *)message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LArmTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LArmTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionFieldFeatures_v:
            {
#ifdef VISION_FIELD_FEATURES_GENERATED
                return DESERIALISE(VISION_FIELD_FEATURES_C_STRUCT, serialised_in, (struct VISION_FIELD_FEATURES_C_STRUCT *)message_out)
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
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionDetectionHorizons_v:
            {
#ifdef VISION_DETECTION_HORIZONS_GENERATED
                return DESERIALISE(VISION_DETECTION_HORIZONS_C_STRUCT, serialised_in, (struct VISION_DETECTION_HORIZONS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_DETECTION_HORIZONS_GENERATED
                break;
            }
            case kwb_NaoWalkCommand_v:
            {
#ifdef NAOWALKCOMMAND_GENERATED
                return DESERIALISE(NAOWALKCOMMAND_C_STRUCT, serialised_in, (struct NAOWALKCOMMAND_C_STRUCT *)message_out)
#else
                return -1;
#endif //NAOWALKCOMMAND_GENERATED
                break;
            }
            case kwb_NaoWalkStatus_v:
            {
#ifdef NAOWALKSTATUS_GENERATED
                return DESERIALISE(NAOWALKSTATUS_C_STRUCT, serialised_in, (struct NAOWALKSTATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //NAOWALKSTATUS_GENERATED
                break;
            }
            case kwb_HAL_LLegTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LLegTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LLegTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionDetectionGoals_v:
            {
#ifdef VISION_DETECTION_GOALS_GENERATED
                return DESERIALISE(VISION_DETECTION_GOALS_C_STRUCT, serialised_in, (struct VISION_DETECTION_GOALS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_DETECTION_GOALS_GENERATED
                break;
            }
            case kwb_TeleoperationControl_v:
            {
#ifdef TELEOPERATIONCONTROL_GENERATED
                return DESERIALISE(TELEOPERATIONCONTROL_C_STRUCT, serialised_in, (struct TELEOPERATIONCONTROL_C_STRUCT *)message_out)
#else
                return -1;
#endif //TELEOPERATIONCONTROL_GENERATED
                break;
            }
            case kwb_TeleoperationStatus_v:
            {
#ifdef TELEOPERATIONSTATUS_GENERATED
                return DESERIALISE(TELEOPERATIONSTATUS_C_STRUCT, serialised_in, (struct TELEOPERATIONSTATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //TELEOPERATIONSTATUS_GENERATED
                break;
            }
            case kwb_VisionDetectionBalls_v:
            {
#ifdef VISION_DETECTION_BALLS_GENERATED
                return DESERIALISE(VISION_DETECTION_BALLS_C_STRUCT, serialised_in, (struct VISION_DETECTION_BALLS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_DETECTION_BALLS_GENERATED
                break;
            }
            case kwb_TeleoperationControlVR_v:
            {
#ifdef TELEOPERATIONCONTROLVR_GENERATED
                return DESERIALISE(TELEOPERATIONCONTROLVR_C_STRUCT, serialised_in, (struct TELEOPERATIONCONTROLVR_C_STRUCT *)message_out)
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
                return DESERIALISE(MACHINE_FILTERED_VISION_C_STRUCT, serialised_in, (struct MACHINE_FILTERED_VISION_C_STRUCT *)message_out)
#else
                return -1;
#endif //MACHINE_FILTERED_VISION_GENERATED
                break;
            }
            case kwb_MicrowaveStatus_v:
            {
#ifdef MICROWAVE_STATUS_GENERATED
                return DESERIALISE(MICROWAVE_STATUS_C_STRUCT, serialised_in, (struct MICROWAVE_STATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //MICROWAVE_STATUS_GENERATED
                break;
            }
            case kwb_Buttons_v:
            {
#ifdef BUTTONS_GENERATED
                return DESERIALISE(BUTTONS_C_STRUCT, serialised_in, (struct BUTTONS_C_STRUCT *)message_out)
#else
                return -1;
#endif //BUTTONS_GENERATED
                break;
            }
            case kwb_MachineFilteredLocalisationVision_v:
            {
#ifdef MACHINE_FILTERED_LOCALISATION_VISION_GENERATED
                return DESERIALISE(MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT, serialised_in, (struct MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT *)message_out)
#else
                return -1;
#endif //MACHINE_FILTERED_LOCALISATION_VISION_GENERATED
                break;
            }
            case kwb_SensorsJointCurrent_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_DataLogger_v:
            {
#ifdef DATA_LOGGER_GENERATED
                return DESERIALISE(DATA_LOGGER_C_STRUCT, serialised_in, (struct DATA_LOGGER_C_STRUCT *)message_out)
#else
                return -1;
#endif //DATA_LOGGER_GENERATED
                break;
            }
            case kwb_MachineFilteredLines_v:
            {
#ifdef MACHINE_FILTERED_LINES_GENERATED
                return DESERIALISE(MACHINE_FILTERED_LINES_C_STRUCT, serialised_in, (struct MACHINE_FILTERED_LINES_C_STRUCT *)message_out)
#else
                return -1;
#endif //MACHINE_FILTERED_LINES_GENERATED
                break;
            }
            case kwb_BallLocation_v:
            {
#ifdef LOCATION_GENERATED
                return DESERIALISE(LOCATION_C_STRUCT, serialised_in, (struct LOCATION_C_STRUCT *)message_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kwb_LeftGoalPostLocation_v:
            {
#ifdef LOCATION_GENERATED
                return DESERIALISE(LOCATION_C_STRUCT, serialised_in, (struct LOCATION_C_STRUCT *)message_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kwb_RightGoalPostLocation_v:
            {
#ifdef LOCATION_GENERATED
                return DESERIALISE(LOCATION_C_STRUCT, serialised_in, (struct LOCATION_C_STRUCT *)message_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kwb_GoalLocation_v:
            {
#ifdef LOCATION_GENERATED
                return DESERIALISE(LOCATION_C_STRUCT, serialised_in, (struct LOCATION_C_STRUCT *)message_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kwb_NaoSonarProtectedWalkCommand_v:
            {
#ifdef NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED
                return DESERIALISE(NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT, serialised_in, (struct NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT *)message_out)
#else
                return -1;
#endif //NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED
                break;
            }
            case kwb_NaoObstacleDirection_v:
            {
#ifdef NAO_OBSTACLE_DIRECTION_GENERATED
                return DESERIALISE(NAO_OBSTACLE_DIRECTION_C_STRUCT, serialised_in, (struct NAO_OBSTACLE_DIRECTION_C_STRUCT *)message_out)
#else
                return -1;
#endif //NAO_OBSTACLE_DIRECTION_GENERATED
                break;
            }
            case kwb_DominantFrequencies_v:
            {
#ifdef DOMINANT_FREQUENCIES_GENERATED
                return DESERIALISE(DOMINANT_FREQUENCIES_C_STRUCT, serialised_in, (struct DOMINANT_FREQUENCIES_C_STRUCT *)message_out)
#else
                return -1;
#endif //DOMINANT_FREQUENCIES_GENERATED
                break;
            }
            case kwb_MissionPriorityForObstacles_v:
            {
#ifdef MISSION_PRIORITY_FOR_OBSTACLES_GENERATED
                return DESERIALISE(MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT, serialised_in, (struct MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT *)message_out)
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
                return DESERIALISE(FREQUENCY_LIMITS_C_STRUCT, serialised_in, (struct FREQUENCY_LIMITS_C_STRUCT *)message_out)
#else
                return -1;
#endif //FREQUENCY_LIMITS_GENERATED
                break;
            }
            case kwb_FrequencyStatus_v:
            {
#ifdef FREQUENCY_LIMITS_GENERATED
                return DESERIALISE(FREQUENCY_LIMITS_C_STRUCT, serialised_in, (struct FREQUENCY_LIMITS_C_STRUCT *)message_out)
#else
                return -1;
#endif //FREQUENCY_LIMITS_GENERATED
                break;
            }
            case kwb_HeadJointSensors_v:
            {
#ifdef HEAD_JOINT_SENSORS_GENERATED
                return DESERIALISE(HEAD_JOINT_SENSORS_C_STRUCT, serialised_in, (struct HEAD_JOINT_SENSORS_C_STRUCT *)message_out)
#else
                return -1;
#endif //HEAD_JOINT_SENSORS_GENERATED
                break;
            }
            case kwb_AdjustPositionConfidence_v:
            {
#ifdef ADJUST_POSITION_CONFIDENCE_GENERATED
                return DESERIALISE(ADJUST_POSITION_CONFIDENCE_C_STRUCT, serialised_in, (struct ADJUST_POSITION_CONFIDENCE_C_STRUCT *)message_out)
#else
                return -1;
#endif //ADJUST_POSITION_CONFIDENCE_GENERATED
                break;
            }
            case kwb_GuVrTeleopVulkanControl_v:
            {
#ifdef GU_VR_TELEOP_VULKAN_CONTROL_GENERATED
                return DESERIALISE(GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT, serialised_in, (struct GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT *)message_out)
#else
                return -1;
#endif //GU_VR_TELEOP_VULKAN_CONTROL_GENERATED
                break;
            }
            case kwb_TemperatureSensors_v:
            {
#ifdef TEMPERATURE_SENSORS_GENERATED
                return DESERIALISE(TEMPERATURE_SENSORS_C_STRUCT, serialised_in, (struct TEMPERATURE_SENSORS_C_STRUCT *)message_out)
#else
                return -1;
#endif //TEMPERATURE_SENSORS_GENERATED
                break;
            }
            case kwb_Overheating_v:
            {
#ifdef OVERHEATING_GENERATED
                return DESERIALISE(OVERHEATING_C_STRUCT, serialised_in, (struct OVERHEATING_C_STRUCT *)message_out)
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
                return DESERIALISE(BALL_POSITION_C_STRUCT, serialised_in, (struct BALL_POSITION_C_STRUCT *)message_out)
#else
                return -1;
#endif //BALL_POSITION_GENERATED
                break;
            }
            case kwb_MemoryImageControl_v:
            {
#ifdef MEMORY_IMAGE_CONTROL_STATUS_GENERATED
                return DESERIALISE(MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT, serialised_in, (struct MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //MEMORY_IMAGE_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_MemoryImageStatus_v:
            {
#ifdef MEMORY_IMAGE_CONTROL_STATUS_GENERATED
                return DESERIALISE(MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT, serialised_in, (struct MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT *)message_out)
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
                return DESERIALISE(MY_POSITION_C_STRUCT, serialised_in, (struct MY_POSITION_C_STRUCT *)message_out)
#else
                return -1;
#endif //MY_POSITION_GENERATED
                break;
            }
            case kwb_VisionDetectionLines_v:
            {
#ifdef VISION_DETECTION_LINES_GENERATED
                return DESERIALISE(VISION_DETECTION_LINES_C_STRUCT, serialised_in, (struct VISION_DETECTION_LINES_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_DETECTION_LINES_GENERATED
                break;
            }
            case kwb_VisionDetectionFeatures_v:
            {
#ifdef VISION_DETECTION_FEATURES_GENERATED
                return DESERIALISE(VISION_DETECTION_FEATURES_C_STRUCT, serialised_in, (struct VISION_DETECTION_FEATURES_C_STRUCT *)message_out)
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

#endif //WB_GUWHITEBOARDDESERIALISER_C

#pragma clang diagnostic pop
