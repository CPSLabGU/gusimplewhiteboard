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

#ifndef GUWHITEBOARDDESERIALISER_C
#define GUWHITEBOARDDESERIALISER_C

#define WHITEBOARD_DESERIALISER

#define DECOMPRESSION_CALL(...) _from_network_serialised(__VA_ARGS__);
#define DECOMPRESSION_FUNC_(s, p) s ## p
#define DECOMPRESSION_FUNC(s, p) DECOMPRESSION_FUNC_(s, p)
#define DESERIALISE(_struct, ...) DECOMPRESSION_FUNC(_struct, DECOMPRESSION_CALL(__VA_ARGS__))

#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

int32_t deserialisemsg(WBTypes message_index, const void *serialised_in, void *message_out)
{
    switch (message_index)
    {

            case kwb_reserved_SubscribeToAllTypes_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kPrint_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kSay_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kSpeech_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kQSay_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kQSpeech_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kSpeechOutput_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kGCGameState_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSensorsHandSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSensorsHeadSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kMOTION_Commands_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kMOTION_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_HeadTarget_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSensorsFootSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSensorsBodySensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSENSORSLedsSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSENSORSLegJointTemps_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSENSORSTorsoJointTemps_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSENSORSLegJointSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSENSORSTorsoJointSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSENSORSSonarSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kFSM_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kFSM_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kFSM_Names_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSoloTypeExample_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kFilteredGoalSighting_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kNAO_State_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kUDPRN_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kPlayerNumber_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kManuallyPenalized_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kVisionControl_v:
            {
#ifdef VISION_CONTROL_STATUS_GENERATED
                return DESERIALISE(VISION_CONTROL_STATUS_C_STRUCT, serialised_in, (struct VISION_CONTROL_STATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_CONTROL_STATUS_GENERATED
                break;
            }
            case kVisionStatus_v:
            {
#ifdef VISION_CONTROL_STATUS_GENERATED
                return DESERIALISE(VISION_CONTROL_STATUS_C_STRUCT, serialised_in, (struct VISION_CONTROL_STATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_CONTROL_STATUS_GENERATED
                break;
            }
            case kFFTStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kFSOsighting_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kTopParticles_v:
            {
#ifdef TOPPARTICLES_GENERATED
                return DESERIALISE(TOPPARTICLES_C_STRUCT, serialised_in, (struct TOPPARTICLES_C_STRUCT *)message_out)
#else
                return -1;
#endif //TOPPARTICLES_GENERATED
                break;
            }
            case kFilteredBallSighting_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kPF_ControlStatus_Modes_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kWEBOTS_NXT_bridge_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kWEBOTS_NXT_encoders_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kWEBOTS_NXT_camera_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kWEBOTS_NXT_walk_isRunning_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kWEBOTS_NXT_deadReakoning_walk_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kWEBOTS_NXT_colorLine_walk_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kWEBOTS_NXT_gridMotions_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kVisionBall_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kVisionGoals_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kWalkData_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kTeleoperationControlStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kTeleoperationConnection_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kUDPWBNumber_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kWEBOTS_NXT_bumper_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kWEBOTS_NXT_vector_bridge_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kTopVisionLines_v:
            {
#ifdef VISION_LINES_GENERATED
                return DESERIALISE(VISION_LINES_C_STRUCT, serialised_in, (struct VISION_LINES_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_LINES_GENERATED
                break;
            }
            case kBottomVisionLines_v:
            {
#ifdef VISION_LINES_GENERATED
                return DESERIALISE(VISION_LINES_C_STRUCT, serialised_in, (struct VISION_LINES_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_LINES_GENERATED
                break;
            }
            case kDifferentialRobotStatus_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kDifferentialRobotControl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kXEyesPos_v:
            {
#ifdef POINT2D_GENERATED
                return DESERIALISE(POINT2D_C_STRUCT, serialised_in, (struct POINT2D_C_STRUCT *)message_out)
#else
                return -1;
#endif //POINT2D_GENERATED
                break;
            }
            case kVisionFace_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kDraw_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kFSM_States_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kGiraff_Interface_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kGiraff_Interface_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kNXT_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kNXT_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kAPM_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kAPM_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kREMOVED3_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kREMOVED4_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kCBall_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kOculusPrime_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kInput3D_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kOculus_Prime_Command_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kIOPins_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kNXT_Two_Touch_Status_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kNXT_Sound_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kNXT_Lights_Control_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kClocks_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kChannels_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSwitchSubsumption_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kTotoDoingMotion_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kCount_v:
            {
#ifdef COUNT_GENERATED
                return DESERIALISE(COUNT_C_STRUCT, serialised_in, (struct COUNT_C_STRUCT *)message_out)
#else
                return -1;
#endif //COUNT_GENERATED
                break;
            }
            case kGreenEWon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kWarnEW_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kTimeGTthirty_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kAmberEWon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kTurnRedEW_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kTimeGTfive_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kRedEWon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kGreenNSon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kWarnNS_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kAmberNSon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kTurnRedNS_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kRedNSon_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kTimerReset_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kSLOT_UNUSED_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kCarSensorPressed_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kSwitchSubsumptionTrafficLights_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kBall_Found_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kBall_Calibration_File_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kBall_Calibration_Num_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kBall_Color_Num_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kHAL_LArmTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_LArmTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_LArmTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_RArmTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_RArmTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_RArmTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kVisionFieldFeatures_v:
            {
#ifdef VISION_FIELD_FEATURES_GENERATED
                return DESERIALISE(VISION_FIELD_FEATURES_C_STRUCT, serialised_in, (struct VISION_FIELD_FEATURES_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_FIELD_FEATURES_GENERATED
                break;
            }
            case kWhistleBlown_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kVolumeControl_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kVisionRobots_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kVisionDetectionHorizons_v:
            {
#ifdef VISION_DETECTION_HORIZONS_GENERATED
                return DESERIALISE(VISION_DETECTION_HORIZONS_C_STRUCT, serialised_in, (struct VISION_DETECTION_HORIZONS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_DETECTION_HORIZONS_GENERATED
                break;
            }
            case kNaoWalkCommand_v:
            {
#ifdef NAOWALKCOMMAND_GENERATED
                return DESERIALISE(NAOWALKCOMMAND_C_STRUCT, serialised_in, (struct NAOWALKCOMMAND_C_STRUCT *)message_out)
#else
                return -1;
#endif //NAOWALKCOMMAND_GENERATED
                break;
            }
            case kNaoWalkStatus_v:
            {
#ifdef NAOWALKSTATUS_GENERATED
                return DESERIALISE(NAOWALKSTATUS_C_STRUCT, serialised_in, (struct NAOWALKSTATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //NAOWALKSTATUS_GENERATED
                break;
            }
            case kHAL_LLegTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_LLegTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_LLegTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_RLegTarget_Ctrl_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_RLegTarget_Stat_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kHAL_RLegTarget_Tolr_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kVisionDetectionGoals_v:
            {
#ifdef VISION_DETECTION_GOALS_GENERATED
                return DESERIALISE(VISION_DETECTION_GOALS_C_STRUCT, serialised_in, (struct VISION_DETECTION_GOALS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_DETECTION_GOALS_GENERATED
                break;
            }
            case kTeleoperationControl_v:
            {
#ifdef TELEOPERATIONCONTROL_GENERATED
                return DESERIALISE(TELEOPERATIONCONTROL_C_STRUCT, serialised_in, (struct TELEOPERATIONCONTROL_C_STRUCT *)message_out)
#else
                return -1;
#endif //TELEOPERATIONCONTROL_GENERATED
                break;
            }
            case kTeleoperationStatus_v:
            {
#ifdef TELEOPERATIONSTATUS_GENERATED
                return DESERIALISE(TELEOPERATIONSTATUS_C_STRUCT, serialised_in, (struct TELEOPERATIONSTATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //TELEOPERATIONSTATUS_GENERATED
                break;
            }
            case kVisionDetectionBalls_v:
            {
#ifdef VISION_DETECTION_BALLS_GENERATED
                return DESERIALISE(VISION_DETECTION_BALLS_C_STRUCT, serialised_in, (struct VISION_DETECTION_BALLS_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_DETECTION_BALLS_GENERATED
                break;
            }
            case kTeleoperationControlVR_v:
            {
#ifdef TELEOPERATIONCONTROLVR_GENERATED
                return DESERIALISE(TELEOPERATIONCONTROLVR_C_STRUCT, serialised_in, (struct TELEOPERATIONCONTROLVR_C_STRUCT *)message_out)
#else
                return -1;
#endif //TELEOPERATIONCONTROLVR_GENERATED
                break;
            }
            case kParticleOutputMap_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kParticleOutputMapControl_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kFFTControl_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kMachineFilteredNaoVision_v:
            {
#ifdef MACHINE_FILTERED_VISION_GENERATED
                return DESERIALISE(MACHINE_FILTERED_VISION_C_STRUCT, serialised_in, (struct MACHINE_FILTERED_VISION_C_STRUCT *)message_out)
#else
                return -1;
#endif //MACHINE_FILTERED_VISION_GENERATED
                break;
            }
            case kMicrowaveStatus_v:
            {
#ifdef MICROWAVE_STATUS_GENERATED
                return DESERIALISE(MICROWAVE_STATUS_C_STRUCT, serialised_in, (struct MICROWAVE_STATUS_C_STRUCT *)message_out)
#else
                return -1;
#endif //MICROWAVE_STATUS_GENERATED
                break;
            }
            case kButtons_v:
            {
#ifdef BUTTONS_GENERATED
                return DESERIALISE(BUTTONS_C_STRUCT, serialised_in, (struct BUTTONS_C_STRUCT *)message_out)
#else
                return -1;
#endif //BUTTONS_GENERATED
                break;
            }
            case kMachineFilteredLocalisationVision_v:
            {
#ifdef MACHINE_FILTERED_LOCALISATION_VISION_GENERATED
                return DESERIALISE(MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT, serialised_in, (struct MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT *)message_out)
#else
                return -1;
#endif //MACHINE_FILTERED_LOCALISATION_VISION_GENERATED
                break;
            }
            case kSensorsJointCurrent_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kDataLogger_v:
            {
#ifdef DATA_LOGGER_GENERATED
                return DESERIALISE(DATA_LOGGER_C_STRUCT, serialised_in, (struct DATA_LOGGER_C_STRUCT *)message_out)
#else
                return -1;
#endif //DATA_LOGGER_GENERATED
                break;
            }
            case kMachineFilteredLines_v:
            {
#ifdef MACHINE_FILTERED_LINES_GENERATED
                return DESERIALISE(MACHINE_FILTERED_LINES_C_STRUCT, serialised_in, (struct MACHINE_FILTERED_LINES_C_STRUCT *)message_out)
#else
                return -1;
#endif //MACHINE_FILTERED_LINES_GENERATED
                break;
            }
            case kBallLocation_v:
            {
#ifdef LOCATION_GENERATED
                return DESERIALISE(LOCATION_C_STRUCT, serialised_in, (struct LOCATION_C_STRUCT *)message_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kLeftGoalPostLocation_v:
            {
#ifdef LOCATION_GENERATED
                return DESERIALISE(LOCATION_C_STRUCT, serialised_in, (struct LOCATION_C_STRUCT *)message_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kRightGoalPostLocation_v:
            {
#ifdef LOCATION_GENERATED
                return DESERIALISE(LOCATION_C_STRUCT, serialised_in, (struct LOCATION_C_STRUCT *)message_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kGoalLocation_v:
            {
#ifdef LOCATION_GENERATED
                return DESERIALISE(LOCATION_C_STRUCT, serialised_in, (struct LOCATION_C_STRUCT *)message_out)
#else
                return -1;
#endif //LOCATION_GENERATED
                break;
            }
            case kNaoSonarProtectedWalkCommand_v:
            {
#ifdef NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED
                return DESERIALISE(NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT, serialised_in, (struct NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT *)message_out)
#else
                return -1;
#endif //NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED
                break;
            }
            case kNaoObstacleDirection_v:
            {
#ifdef NAO_OBSTACLE_DIRECTION_GENERATED
                return DESERIALISE(NAO_OBSTACLE_DIRECTION_C_STRUCT, serialised_in, (struct NAO_OBSTACLE_DIRECTION_C_STRUCT *)message_out)
#else
                return -1;
#endif //NAO_OBSTACLE_DIRECTION_GENERATED
                break;
            }
            case kDominantFrequencies_v:
            {
#ifdef DOMINANT_FREQUENCIES_GENERATED
                return DESERIALISE(DOMINANT_FREQUENCIES_C_STRUCT, serialised_in, (struct DOMINANT_FREQUENCIES_C_STRUCT *)message_out)
#else
                return -1;
#endif //DOMINANT_FREQUENCIES_GENERATED
                break;
            }
            case kMissionPriorityForObstacles_v:
            {
#ifdef MISSION_PRIORITY_FOR_OBSTACLES_GENERATED
                return DESERIALISE(MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT, serialised_in, (struct MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT *)message_out)
#else
                return -1;
#endif //MISSION_PRIORITY_FOR_OBSTACLES_GENERATED
                break;
            }
            case kWavLoad_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kWavPlay_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kReproduceWavNotSilent_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kFrequencyControl_v:
            {
#ifdef FREQUENCY_LIMITS_GENERATED
                return DESERIALISE(FREQUENCY_LIMITS_C_STRUCT, serialised_in, (struct FREQUENCY_LIMITS_C_STRUCT *)message_out)
#else
                return -1;
#endif //FREQUENCY_LIMITS_GENERATED
                break;
            }
            case kFrequencyStatus_v:
            {
#ifdef FREQUENCY_LIMITS_GENERATED
                return DESERIALISE(FREQUENCY_LIMITS_C_STRUCT, serialised_in, (struct FREQUENCY_LIMITS_C_STRUCT *)message_out)
#else
                return -1;
#endif //FREQUENCY_LIMITS_GENERATED
                break;
            }
            case kHeadJointSensors_v:
            {
#ifdef HEAD_JOINT_SENSORS_GENERATED
                return DESERIALISE(HEAD_JOINT_SENSORS_C_STRUCT, serialised_in, (struct HEAD_JOINT_SENSORS_C_STRUCT *)message_out)
#else
                return -1;
#endif //HEAD_JOINT_SENSORS_GENERATED
                break;
            }
            case kAdjustPositionConfidence_v:
            {
#ifdef ADJUST_POSITION_CONFIDENCE_GENERATED
                return DESERIALISE(ADJUST_POSITION_CONFIDENCE_C_STRUCT, serialised_in, (struct ADJUST_POSITION_CONFIDENCE_C_STRUCT *)message_out)
#else
                return -1;
#endif //ADJUST_POSITION_CONFIDENCE_GENERATED
                break;
            }
            case kGuVrTeleopVulkanControl_v:
            {
#ifdef GU_VR_TELEOP_VULKAN_CONTROL_GENERATED
                return DESERIALISE(GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT, serialised_in, (struct GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT *)message_out)
#else
                return -1;
#endif //GU_VR_TELEOP_VULKAN_CONTROL_GENERATED
                break;
            }
            case kTemperatureSensors_v:
            {
#ifdef TEMPERATURE_SENSORS_GENERATED
                return DESERIALISE(TEMPERATURE_SENSORS_C_STRUCT, serialised_in, (struct TEMPERATURE_SENSORS_C_STRUCT *)message_out)
#else
                return -1;
#endif //TEMPERATURE_SENSORS_GENERATED
                break;
            }
            case kOverheating_v:
            {
#ifdef OVERHEATING_GENERATED
                return DESERIALISE(OVERHEATING_C_STRUCT, serialised_in, (struct OVERHEATING_C_STRUCT *)message_out)
#else
                return -1;
#endif //OVERHEATING_GENERATED
                break;
            }
            case kbuttonPushed_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kdoorOpen_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case ktimeLeft_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kmotor_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case ksound_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case klight_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
    }
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
    /*(void) message_content;*/
    return -1;
#pragma clang diagnostic pop
}

#endif //GUWHITEBOARDDESERIALISER_C

#pragma clang diagnostic pop
