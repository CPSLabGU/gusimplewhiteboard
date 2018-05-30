/**
 *  /file guwhiteboarddeserialiser.c
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2018 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

#ifndef GUWHITEBOARDDESERIALISER_C
#define GUWHITEBOARDDESERIALISER_C

/** Auto-generated, don't modify! */

#define WHITEBOARD_DESERIALISER

#define DECOMPRESSION_CALL(...) _from_network_serialised(__VA_ARGS__);
#define DECOMPRESSION_FUNC_(s, p) s ## p
#define DECOMPRESSION_FUNC(s, p) DECOMPRESSION_FUNC_(s, p)
#define DESERIALISE(_struct, ...) DECOMPRESSION_FUNC(_struct, DECOMPRESSION_CALL(__VA_ARGS__))

#include "guwhiteboardserialisation.h"
#include "guwhiteboard_c_types.h"

size_t deserialisemsg(WBTypes message_index, const void *serialised_in, void *message_out)
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
            case kREMOVED1_v:
            {
                return -1; /*TODO, add support for POD types.*/
                break;
            }
            case kREMOVED2_v:
            {
                return -1; /*TODO, add support for POD types.*/
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
            case kSENSORSFootSensors_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kSENSORSBodySensors_v:
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
            case kVisionLines_v:
            {
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
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
#ifdef SerialisationNotSupportedWithLegacyNaming
                return DESERIALISE(NotSupportedWithLegacyNaming, serialised_in, (struct NotSupportedWithLegacyNaming *)message_out)
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
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
#ifdef VISION_FIELDFEATURES_GENERATED
                return DESERIALISE(VISION_FIELDFEATURES_C_STRUCT, serialised_in, (struct VISION_FIELDFEATURES_C_STRUCT *)message_out)
#else
                return -1;
#endif //VISION_FIELDFEATURES_GENERATED
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
#ifdef PARTICLE_OUTPUT_MAP_GENERATED
                return DESERIALISE(PARTICLE_OUTPUT_MAP_C_STRUCT, serialised_in, (struct PARTICLE_OUTPUT_MAP_C_STRUCT *)message_out)
#else
                return -1;
#endif //PARTICLE_OUTPUT_MAP_GENERATED
                break;
            }
            case kParticleOutputMapControl_v:
            {
#ifdef PARTICLE_OUTPUT_MAP_GENERATED
                return DESERIALISE(PARTICLE_OUTPUT_MAP_C_STRUCT, serialised_in, (struct PARTICLE_OUTPUT_MAP_C_STRUCT *)message_out)
#else
                return -1;
#endif //PARTICLE_OUTPUT_MAP_GENERATED
                break;
            }
            case kFFTControl_v:
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
