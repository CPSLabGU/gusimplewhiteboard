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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(GCGAMESTATE_GENERATED) // GCGAMESTATE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define GCGAMESTATE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define GCGAMESTATE_C_STRUCT_NAME_COMPAT GCGAMESTATE_C_STRUCT
#endif
                return SERIALISE(GCGAMESTATE_C_STRUCT_NAME_COMPAT, (struct GCGAMESTATE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef GCGAMESTATE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsHandSensors_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSHANDSENSORS_GENERATED) // SENSORSHANDSENSORS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSHANDSENSORS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSHANDSENSORS_C_STRUCT_NAME_COMPAT SENSORSHANDSENSORS_C_STRUCT
#endif
                return SERIALISE(SENSORSHANDSENSORS_C_STRUCT_NAME_COMPAT, (struct SENSORSHANDSENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSHANDSENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsHeadSensors_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSHEADSENSORS_GENERATED) // SENSORSHEADSENSORS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSHEADSENSORS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSHEADSENSORS_C_STRUCT_NAME_COMPAT SENSORSHEADSENSORS_C_STRUCT
#endif
                return SERIALISE(SENSORSHEADSENSORS_C_STRUCT_NAME_COMPAT, (struct SENSORSHEADSENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSHEADSENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_MOTION_Commands_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(MOTION_COMMANDS_GENERATED) // MOTION_COMMANDS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define MOTION_COMMANDS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define MOTION_COMMANDS_C_STRUCT_NAME_COMPAT MOTION_COMMANDS_C_STRUCT
#endif
                return SERIALISE(MOTION_COMMANDS_C_STRUCT_NAME_COMPAT, (struct MOTION_COMMANDS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MOTION_COMMANDS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_MOTION_Status_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(MOTION_STATUS_GENERATED) // MOTION_STATUS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define MOTION_STATUS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define MOTION_STATUS_C_STRUCT_NAME_COMPAT MOTION_STATUS_C_STRUCT
#endif
                return SERIALISE(MOTION_STATUS_C_STRUCT_NAME_COMPAT, (struct MOTION_STATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MOTION_STATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_HeadTarget_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HAL_HEADTARGET_GENERATED) // HAL_HEADTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HAL_HEADTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HAL_HEADTARGET_C_STRUCT_NAME_COMPAT HAL_HEADTARGET_C_STRUCT
#endif
                return SERIALISE(HAL_HEADTARGET_C_STRUCT_NAME_COMPAT, (struct HAL_HEADTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HAL_HEADTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsFootSensors_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSFOOTSENSORS_GENERATED) // SENSORSFOOTSENSORS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSFOOTSENSORS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSFOOTSENSORS_C_STRUCT_NAME_COMPAT SENSORSFOOTSENSORS_C_STRUCT
#endif
                return SERIALISE(SENSORSFOOTSENSORS_C_STRUCT_NAME_COMPAT, (struct SENSORSFOOTSENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSFOOTSENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SensorsBodySensors_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSBODYSENSORS_GENERATED) // SENSORSBODYSENSORS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSBODYSENSORS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSBODYSENSORS_C_STRUCT_NAME_COMPAT SENSORSBODYSENSORS_C_STRUCT
#endif
                return SERIALISE(SENSORSBODYSENSORS_C_STRUCT_NAME_COMPAT, (struct SENSORSBODYSENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSBODYSENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLedsSensors_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSLEDSSENSORS_GENERATED) // SENSORSLEDSSENSORS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSLEDSSENSORS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSLEDSSENSORS_C_STRUCT_NAME_COMPAT SENSORSLEDSSENSORS_C_STRUCT
#endif
                return SERIALISE(SENSORSLEDSSENSORS_C_STRUCT_NAME_COMPAT, (struct SENSORSLEDSSENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSLEDSSENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLegJointTemps_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSLEGJOINTTEMPS_GENERATED) // SENSORSLEGJOINTTEMPS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSLEGJOINTTEMPS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSLEGJOINTTEMPS_C_STRUCT_NAME_COMPAT SENSORSLEGJOINTTEMPS_C_STRUCT
#endif
                return SERIALISE(SENSORSLEGJOINTTEMPS_C_STRUCT_NAME_COMPAT, (struct SENSORSLEGJOINTTEMPS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSLEGJOINTTEMPS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSTorsoJointTemps_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSTORSOJOINTTEMPS_GENERATED) // SENSORSTORSOJOINTTEMPS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSTORSOJOINTTEMPS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSTORSOJOINTTEMPS_C_STRUCT_NAME_COMPAT SENSORSTORSOJOINTTEMPS_C_STRUCT
#endif
                return SERIALISE(SENSORSTORSOJOINTTEMPS_C_STRUCT_NAME_COMPAT, (struct SENSORSTORSOJOINTTEMPS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSTORSOJOINTTEMPS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSLegJointSensors_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSLEGJOINTSENSORS_GENERATED) // SENSORSLEGJOINTSENSORS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSLEGJOINTSENSORS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSLEGJOINTSENSORS_C_STRUCT_NAME_COMPAT SENSORSLEGJOINTSENSORS_C_STRUCT
#endif
                return SERIALISE(SENSORSLEGJOINTSENSORS_C_STRUCT_NAME_COMPAT, (struct SENSORSLEGJOINTSENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSLEGJOINTSENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSTorsoJointSensors_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSTORSOJOINTSENSORS_GENERATED) // SENSORSTORSOJOINTSENSORS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSTORSOJOINTSENSORS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSTORSOJOINTSENSORS_C_STRUCT_NAME_COMPAT SENSORSTORSOJOINTSENSORS_C_STRUCT
#endif
                return SERIALISE(SENSORSTORSOJOINTSENSORS_C_STRUCT_NAME_COMPAT, (struct SENSORSTORSOJOINTSENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSTORSOJOINTSENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SENSORSSonarSensors_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SENSORSSONARSENSORS_GENERATED) // SENSORSSONARSENSORS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SENSORSSONARSENSORS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SENSORSSONARSENSORS_C_STRUCT_NAME_COMPAT SENSORSSONARSENSORS_C_STRUCT
#endif
                return SERIALISE(SENSORSSONARSENSORS_C_STRUCT_NAME_COMPAT, (struct SENSORSSONARSENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SENSORSSONARSENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Control_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(FSMCONTROLSTATUS_GENERATED) // FSMCONTROLSTATUS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT FSMCONTROLSTATUS_C_STRUCT
#endif
                return SERIALISE(FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT, (struct FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Status_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(FSMCONTROLSTATUS_GENERATED) // FSMCONTROLSTATUS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT FSMCONTROLSTATUS_C_STRUCT
#endif
                return SERIALISE(FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT, (struct FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FSMCONTROLSTATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSM_Names_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(FSMNAMES_GENERATED) // FSMNAMES_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define FSMNAMES_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define FSMNAMES_C_STRUCT_NAME_COMPAT FSMNAMES_C_STRUCT
#endif
                return SERIALISE(FSMNAMES_C_STRUCT_NAME_COMPAT, (struct FSMNAMES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FSMNAMES_C_STRUCT_NAME_COMPAT
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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(FILTEREDARRAYONEDIMOBJECTS_GENERATED) // FILTEREDARRAYONEDIMOBJECTS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define FILTEREDARRAYONEDIMOBJECTS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define FILTEREDARRAYONEDIMOBJECTS_C_STRUCT_NAME_COMPAT FILTEREDARRAYONEDIMOBJECTS_C_STRUCT
#endif
                return SERIALISE(FILTEREDARRAYONEDIMOBJECTS_C_STRUCT_NAME_COMPAT, (struct FILTEREDARRAYONEDIMOBJECTS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FILTEREDARRAYONEDIMOBJECTS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NAO_State_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(NAO_STATE_GENERATED) // NAO_STATE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define NAO_STATE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define NAO_STATE_C_STRUCT_NAME_COMPAT NAO_STATE_C_STRUCT
#endif
                return SERIALISE(NAO_STATE_C_STRUCT_NAME_COMPAT, (struct NAO_STATE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NAO_STATE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_UDPRN_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(GCGAMESTATE_GENERATED) // GCGAMESTATE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define GCGAMESTATE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define GCGAMESTATE_C_STRUCT_NAME_COMPAT GCGAMESTATE_C_STRUCT
#endif
                return SERIALISE(GCGAMESTATE_C_STRUCT_NAME_COMPAT, (struct GCGAMESTATE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef GCGAMESTATE_C_STRUCT_NAME_COMPAT
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
#if defined(WB_VISION_CONTROL_STATUS_GENERATED)  || defined(VISION_CONTROL_STATUS_GENERATED) // VISION_CONTROL_STATUS_GENERATED is legacy, don't use
#ifdef WB_VISION_CONTROL_STATUS_C_STRUCT
#define VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT WB_VISION_CONTROL_STATUS_C_STRUCT
#else
#define VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT VISION_CONTROL_STATUS_C_STRUCT
#endif
                return SERIALISE(VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT, (struct VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_VisionStatus_v:
            {
#if defined(WB_VISION_CONTROL_STATUS_GENERATED)  || defined(VISION_CONTROL_STATUS_GENERATED) // VISION_CONTROL_STATUS_GENERATED is legacy, don't use
#ifdef WB_VISION_CONTROL_STATUS_C_STRUCT
#define VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT WB_VISION_CONTROL_STATUS_C_STRUCT
#else
#define VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT VISION_CONTROL_STATUS_C_STRUCT
#endif
                return SERIALISE(VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT, (struct VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_CONTROL_STATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_FFTStatus_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(FFTSTATUS_GENERATED) // FFTSTATUS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define FFTSTATUS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define FFTSTATUS_C_STRUCT_NAME_COMPAT FFTSTATUS_C_STRUCT
#endif
                return SERIALISE(FFTSTATUS_C_STRUCT_NAME_COMPAT, (struct FFTSTATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FFTSTATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_FSOsighting_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(FILTEREDARRAYONEDIMSONAR_GENERATED) // FILTEREDARRAYONEDIMSONAR_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define FILTEREDARRAYONEDIMSONAR_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define FILTEREDARRAYONEDIMSONAR_C_STRUCT_NAME_COMPAT FILTEREDARRAYONEDIMSONAR_C_STRUCT
#endif
                return SERIALISE(FILTEREDARRAYONEDIMSONAR_C_STRUCT_NAME_COMPAT, (struct FILTEREDARRAYONEDIMSONAR_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FILTEREDARRAYONEDIMSONAR_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TopParticles_v:
            {
#if defined(WB_TOPPARTICLES_GENERATED)  || defined(TOPPARTICLES_GENERATED) // TOPPARTICLES_GENERATED is legacy, don't use
#ifdef WB_TOPPARTICLES_C_STRUCT
#define TOPPARTICLES_C_STRUCT_NAME_COMPAT WB_TOPPARTICLES_C_STRUCT
#else
#define TOPPARTICLES_C_STRUCT_NAME_COMPAT TOPPARTICLES_C_STRUCT
#endif
                return SERIALISE(TOPPARTICLES_C_STRUCT_NAME_COMPAT, (struct TOPPARTICLES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef TOPPARTICLES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_TOPPARTICLES_GENERATED
                break;
            }
            case kwb_FilteredBallSighting_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(FILTEREDARRAYBALLSIGHTINGS_GENERATED) // FILTEREDARRAYBALLSIGHTINGS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define FILTEREDARRAYBALLSIGHTINGS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define FILTEREDARRAYBALLSIGHTINGS_C_STRUCT_NAME_COMPAT FILTEREDARRAYBALLSIGHTINGS_C_STRUCT
#endif
                return SERIALISE(FILTEREDARRAYBALLSIGHTINGS_C_STRUCT_NAME_COMPAT, (struct FILTEREDARRAYBALLSIGHTINGS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FILTEREDARRAYBALLSIGHTINGS_C_STRUCT_NAME_COMPAT
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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_BRIDGE_GENERATED) // WEBOTS_NXT_BRIDGE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_BRIDGE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_BRIDGE_C_STRUCT_NAME_COMPAT WEBOTS_NXT_BRIDGE_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_BRIDGE_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_BRIDGE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_BRIDGE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_encoders_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_ENCODERS_GENERATED) // WEBOTS_NXT_ENCODERS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_ENCODERS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_ENCODERS_C_STRUCT_NAME_COMPAT WEBOTS_NXT_ENCODERS_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_ENCODERS_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_ENCODERS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_ENCODERS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_camera_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_CAMERA_GENERATED) // WEBOTS_NXT_CAMERA_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_CAMERA_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_CAMERA_C_STRUCT_NAME_COMPAT WEBOTS_NXT_CAMERA_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_CAMERA_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_CAMERA_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_CAMERA_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_walk_isRunning_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_WALK_ISRUNNING_GENERATED) // WEBOTS_NXT_WALK_ISRUNNING_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT_NAME_COMPAT WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_WALK_ISRUNNING_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_deadReakoning_walk_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_DEADREAKONING_WALK_GENERATED) // WEBOTS_NXT_DEADREAKONING_WALK_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT_NAME_COMPAT WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_DEADREAKONING_WALK_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_colorLine_walk_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_COLORLINE_WALK_GENERATED) // WEBOTS_NXT_COLORLINE_WALK_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_COLORLINE_WALK_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_COLORLINE_WALK_C_STRUCT_NAME_COMPAT WEBOTS_NXT_COLORLINE_WALK_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_COLORLINE_WALK_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_COLORLINE_WALK_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_COLORLINE_WALK_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_gridMotions_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_GRIDMOTIONS_GENERATED) // WEBOTS_NXT_GRIDMOTIONS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_GRIDMOTIONS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_GRIDMOTIONS_C_STRUCT_NAME_COMPAT WEBOTS_NXT_GRIDMOTIONS_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_GRIDMOTIONS_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_GRIDMOTIONS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_GRIDMOTIONS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionBall_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(VISIONBALL_GENERATED) // VISIONBALL_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define VISIONBALL_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define VISIONBALL_C_STRUCT_NAME_COMPAT VISIONBALL_C_STRUCT
#endif
                return SERIALISE(VISIONBALL_C_STRUCT_NAME_COMPAT, (struct VISIONBALL_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISIONBALL_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionGoals_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(VISIONGOALS_GENERATED) // VISIONGOALS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define VISIONGOALS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define VISIONGOALS_C_STRUCT_NAME_COMPAT VISIONGOALS_C_STRUCT
#endif
                return SERIALISE(VISIONGOALS_C_STRUCT_NAME_COMPAT, (struct VISIONGOALS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISIONGOALS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WalkData_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WALKDATA_GENERATED) // WALKDATA_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WALKDATA_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WALKDATA_C_STRUCT_NAME_COMPAT WALKDATA_C_STRUCT
#endif
                return SERIALISE(WALKDATA_C_STRUCT_NAME_COMPAT, (struct WALKDATA_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WALKDATA_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TeleoperationControlStatus_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(TELEOPERATIONCONTROLSTATUS_GENERATED) // TELEOPERATIONCONTROLSTATUS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define TELEOPERATIONCONTROLSTATUS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define TELEOPERATIONCONTROLSTATUS_C_STRUCT_NAME_COMPAT TELEOPERATIONCONTROLSTATUS_C_STRUCT
#endif
                return SERIALISE(TELEOPERATIONCONTROLSTATUS_C_STRUCT_NAME_COMPAT, (struct TELEOPERATIONCONTROLSTATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef TELEOPERATIONCONTROLSTATUS_C_STRUCT_NAME_COMPAT
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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_BUMPER_GENERATED) // WEBOTS_NXT_BUMPER_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_BUMPER_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_BUMPER_C_STRUCT_NAME_COMPAT WEBOTS_NXT_BUMPER_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_BUMPER_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_BUMPER_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_BUMPER_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_WEBOTS_NXT_vector_bridge_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(WEBOTS_NXT_VECTOR_BRIDGE_GENERATED) // WEBOTS_NXT_VECTOR_BRIDGE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT_NAME_COMPAT WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT
#endif
                return SERIALISE(WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT_NAME_COMPAT, (struct WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef WEBOTS_NXT_VECTOR_BRIDGE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TopVisionLines_v:
            {
#if defined(WB_VISION_LINES_GENERATED)  || defined(VISION_LINES_GENERATED) // VISION_LINES_GENERATED is legacy, don't use
#ifdef WB_VISION_LINES_C_STRUCT
#define VISION_LINES_C_STRUCT_NAME_COMPAT WB_VISION_LINES_C_STRUCT
#else
#define VISION_LINES_C_STRUCT_NAME_COMPAT VISION_LINES_C_STRUCT
#endif
                return SERIALISE(VISION_LINES_C_STRUCT_NAME_COMPAT, (struct VISION_LINES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_LINES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_LINES_GENERATED
                break;
            }
            case kwb_BottomVisionLines_v:
            {
#if defined(WB_VISION_LINES_GENERATED)  || defined(VISION_LINES_GENERATED) // VISION_LINES_GENERATED is legacy, don't use
#ifdef WB_VISION_LINES_C_STRUCT
#define VISION_LINES_C_STRUCT_NAME_COMPAT WB_VISION_LINES_C_STRUCT
#else
#define VISION_LINES_C_STRUCT_NAME_COMPAT VISION_LINES_C_STRUCT
#endif
                return SERIALISE(VISION_LINES_C_STRUCT_NAME_COMPAT, (struct VISION_LINES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_LINES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_LINES_GENERATED
                break;
            }
            case kwb_DifferentialRobotStatus_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(DIFFERENTIALROBOTCONTROLSTATUS_GENERATED) // DIFFERENTIALROBOTCONTROLSTATUS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT
#endif
                return SERIALISE(DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT, (struct DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_DifferentialRobotControl_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(DIFFERENTIALROBOTCONTROLSTATUS_GENERATED) // DIFFERENTIALROBOTCONTROLSTATUS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT
#endif
                return SERIALISE(DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT, (struct DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef DIFFERENTIALROBOTCONTROLSTATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_XEyesPos_v:
            {
#if defined(WB_POINT2D_GENERATED)  || defined(POINT2D_GENERATED) // POINT2D_GENERATED is legacy, don't use
#ifdef WB_POINT2D_C_STRUCT
#define POINT2D_C_STRUCT_NAME_COMPAT WB_POINT2D_C_STRUCT
#else
#define POINT2D_C_STRUCT_NAME_COMPAT POINT2D_C_STRUCT
#endif
                return SERIALISE(POINT2D_C_STRUCT_NAME_COMPAT, (struct POINT2D_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef POINT2D_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_POINT2D_GENERATED
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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(FSMSTATE_GENERATED) // FSMSTATE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define FSMSTATE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define FSMSTATE_C_STRUCT_NAME_COMPAT FSMSTATE_C_STRUCT
#endif
                return SERIALISE(FSMSTATE_C_STRUCT_NAME_COMPAT, (struct FSMSTATE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FSMSTATE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Giraff_Interface_Status_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(GIRAFF_MAINSERIALINTERFACE_GENERATED) // GIRAFF_MAINSERIALINTERFACE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT GIRAFF_MAINSERIALINTERFACE_C_STRUCT
#endif
                return SERIALISE(GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT, (struct GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Giraff_Interface_Command_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(GIRAFF_MAINSERIALINTERFACE_GENERATED) // GIRAFF_MAINSERIALINTERFACE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT GIRAFF_MAINSERIALINTERFACE_C_STRUCT
#endif
                return SERIALISE(GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT, (struct GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef GIRAFF_MAINSERIALINTERFACE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Status_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(NXT_INTERFACE_GENERATED) // NXT_INTERFACE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define NXT_INTERFACE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define NXT_INTERFACE_C_STRUCT_NAME_COMPAT NXT_INTERFACE_C_STRUCT
#endif
                return SERIALISE(NXT_INTERFACE_C_STRUCT_NAME_COMPAT, (struct NXT_INTERFACE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NXT_INTERFACE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Command_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(NXT_INTERFACE_GENERATED) // NXT_INTERFACE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define NXT_INTERFACE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define NXT_INTERFACE_C_STRUCT_NAME_COMPAT NXT_INTERFACE_C_STRUCT
#endif
                return SERIALISE(NXT_INTERFACE_C_STRUCT_NAME_COMPAT, (struct NXT_INTERFACE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NXT_INTERFACE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_APM_Status_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(APM_INTERFACE_GENERATED) // APM_INTERFACE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define APM_INTERFACE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define APM_INTERFACE_C_STRUCT_NAME_COMPAT APM_INTERFACE_C_STRUCT
#endif
                return SERIALISE(APM_INTERFACE_C_STRUCT_NAME_COMPAT, (struct APM_INTERFACE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef APM_INTERFACE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_APM_Command_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(APM_INTERFACE_GENERATED) // APM_INTERFACE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define APM_INTERFACE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define APM_INTERFACE_C_STRUCT_NAME_COMPAT APM_INTERFACE_C_STRUCT
#endif
                return SERIALISE(APM_INTERFACE_C_STRUCT_NAME_COMPAT, (struct APM_INTERFACE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef APM_INTERFACE_C_STRUCT_NAME_COMPAT
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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(OCULUSPRIMEINTERFACE_GENERATED) // OCULUSPRIMEINTERFACE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define OCULUSPRIMEINTERFACE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define OCULUSPRIMEINTERFACE_C_STRUCT_NAME_COMPAT OCULUSPRIMEINTERFACE_C_STRUCT
#endif
                return SERIALISE(OCULUSPRIMEINTERFACE_C_STRUCT_NAME_COMPAT, (struct OCULUSPRIMEINTERFACE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef OCULUSPRIMEINTERFACE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Input3D_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(INPUT3D_GENERATED) // INPUT3D_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define INPUT3D_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define INPUT3D_C_STRUCT_NAME_COMPAT INPUT3D_C_STRUCT
#endif
                return SERIALISE(INPUT3D_C_STRUCT_NAME_COMPAT, (struct INPUT3D_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef INPUT3D_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Oculus_Prime_Command_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(OCULUS_PRIMESERIALINTERFACE_GENERATED) // OCULUS_PRIMESERIALINTERFACE_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define OCULUS_PRIMESERIALINTERFACE_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define OCULUS_PRIMESERIALINTERFACE_C_STRUCT_NAME_COMPAT OCULUS_PRIMESERIALINTERFACE_C_STRUCT
#endif
                return SERIALISE(OCULUS_PRIMESERIALINTERFACE_C_STRUCT_NAME_COMPAT, (struct OCULUS_PRIMESERIALINTERFACE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef OCULUS_PRIMESERIALINTERFACE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_IOPins_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(IOPINS_GENERATED) // IOPINS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define IOPINS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define IOPINS_C_STRUCT_NAME_COMPAT IOPINS_C_STRUCT
#endif
                return SERIALISE(IOPINS_C_STRUCT_NAME_COMPAT, (struct IOPINS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef IOPINS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Two_Touch_Status_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(NXT_TWO_TOUCH_STATUS_GENERATED) // NXT_TWO_TOUCH_STATUS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define NXT_TWO_TOUCH_STATUS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define NXT_TWO_TOUCH_STATUS_C_STRUCT_NAME_COMPAT NXT_TWO_TOUCH_STATUS_C_STRUCT
#endif
                return SERIALISE(NXT_TWO_TOUCH_STATUS_C_STRUCT_NAME_COMPAT, (struct NXT_TWO_TOUCH_STATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NXT_TWO_TOUCH_STATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Sound_Control_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(NXT_SOUND_CONTROL_GENERATED) // NXT_SOUND_CONTROL_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define NXT_SOUND_CONTROL_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define NXT_SOUND_CONTROL_C_STRUCT_NAME_COMPAT NXT_SOUND_CONTROL_C_STRUCT
#endif
                return SERIALISE(NXT_SOUND_CONTROL_C_STRUCT_NAME_COMPAT, (struct NXT_SOUND_CONTROL_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NXT_SOUND_CONTROL_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_NXT_Lights_Control_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(NXT_LIGHTS_CONTROL_GENERATED) // NXT_LIGHTS_CONTROL_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define NXT_LIGHTS_CONTROL_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define NXT_LIGHTS_CONTROL_C_STRUCT_NAME_COMPAT NXT_LIGHTS_CONTROL_C_STRUCT
#endif
                return SERIALISE(NXT_LIGHTS_CONTROL_C_STRUCT_NAME_COMPAT, (struct NXT_LIGHTS_CONTROL_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NXT_LIGHTS_CONTROL_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Clocks_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(CLOCKS_GENERATED) // CLOCKS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define CLOCKS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define CLOCKS_C_STRUCT_NAME_COMPAT CLOCKS_C_STRUCT
#endif
                return SERIALISE(CLOCKS_C_STRUCT_NAME_COMPAT, (struct CLOCKS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef CLOCKS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Channels_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(CHANNELS_GENERATED) // CHANNELS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define CHANNELS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define CHANNELS_C_STRUCT_NAME_COMPAT CHANNELS_C_STRUCT
#endif
                return SERIALISE(CHANNELS_C_STRUCT_NAME_COMPAT, (struct CHANNELS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef CHANNELS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_SwitchSubsumption_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SWITCHSUBSUMPTION_GENERATED) // SWITCHSUBSUMPTION_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SWITCHSUBSUMPTION_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SWITCHSUBSUMPTION_C_STRUCT_NAME_COMPAT SWITCHSUBSUMPTION_C_STRUCT
#endif
                return SERIALISE(SWITCHSUBSUMPTION_C_STRUCT_NAME_COMPAT, (struct SWITCHSUBSUMPTION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SWITCHSUBSUMPTION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_TotoDoingMotion_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(TOTODOINGMOTION_GENERATED) // TOTODOINGMOTION_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define TOTODOINGMOTION_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define TOTODOINGMOTION_C_STRUCT_NAME_COMPAT TOTODOINGMOTION_C_STRUCT
#endif
                return SERIALISE(TOTODOINGMOTION_C_STRUCT_NAME_COMPAT, (struct TOTODOINGMOTION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef TOTODOINGMOTION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_Count_v:
            {
#if defined(WB_COUNT_GENERATED)  || defined(COUNT_GENERATED) // COUNT_GENERATED is legacy, don't use
#ifdef WB_COUNT_C_STRUCT
#define COUNT_C_STRUCT_NAME_COMPAT WB_COUNT_C_STRUCT
#else
#define COUNT_C_STRUCT_NAME_COMPAT COUNT_C_STRUCT
#endif
                return SERIALISE(COUNT_C_STRUCT_NAME_COMPAT, (struct COUNT_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef COUNT_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_COUNT_GENERATED
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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(SWITCHSUBSUMPTIONTRAFFICLIGHTS_GENERATED) // SWITCHSUBSUMPTIONTRAFFICLIGHTS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT_NAME_COMPAT SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT
#endif
                return SERIALISE(SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT_NAME_COMPAT, (struct SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef SWITCHSUBSUMPTIONTRAFFICLIGHTS_C_STRUCT_NAME_COMPAT
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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALARMTARGET_GENERATED) // HALARMTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALARMTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALARMTARGET_C_STRUCT_NAME_COMPAT HALARMTARGET_C_STRUCT
#endif
                return SERIALISE(HALARMTARGET_C_STRUCT_NAME_COMPAT, (struct HALARMTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALARMTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LArmTarget_Stat_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALARMTARGET_GENERATED) // HALARMTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALARMTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALARMTARGET_C_STRUCT_NAME_COMPAT HALARMTARGET_C_STRUCT
#endif
                return SERIALISE(HALARMTARGET_C_STRUCT_NAME_COMPAT, (struct HALARMTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALARMTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LArmTarget_Tolr_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALARMTARGET_GENERATED) // HALARMTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALARMTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALARMTARGET_C_STRUCT_NAME_COMPAT HALARMTARGET_C_STRUCT
#endif
                return SERIALISE(HALARMTARGET_C_STRUCT_NAME_COMPAT, (struct HALARMTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALARMTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Ctrl_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALARMTARGET_GENERATED) // HALARMTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALARMTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALARMTARGET_C_STRUCT_NAME_COMPAT HALARMTARGET_C_STRUCT
#endif
                return SERIALISE(HALARMTARGET_C_STRUCT_NAME_COMPAT, (struct HALARMTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALARMTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Stat_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALARMTARGET_GENERATED) // HALARMTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALARMTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALARMTARGET_C_STRUCT_NAME_COMPAT HALARMTARGET_C_STRUCT
#endif
                return SERIALISE(HALARMTARGET_C_STRUCT_NAME_COMPAT, (struct HALARMTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALARMTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RArmTarget_Tolr_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALARMTARGET_GENERATED) // HALARMTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALARMTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALARMTARGET_C_STRUCT_NAME_COMPAT HALARMTARGET_C_STRUCT
#endif
                return SERIALISE(HALARMTARGET_C_STRUCT_NAME_COMPAT, (struct HALARMTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALARMTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionFieldFeatures_v:
            {
#if defined(WB_VISION_FIELD_FEATURES_GENERATED)  || defined(VISION_FIELD_FEATURES_GENERATED) // VISION_FIELD_FEATURES_GENERATED is legacy, don't use
#ifdef WB_VISION_FIELD_FEATURES_C_STRUCT
#define VISION_FIELD_FEATURES_C_STRUCT_NAME_COMPAT WB_VISION_FIELD_FEATURES_C_STRUCT
#else
#define VISION_FIELD_FEATURES_C_STRUCT_NAME_COMPAT VISION_FIELD_FEATURES_C_STRUCT
#endif
                return SERIALISE(VISION_FIELD_FEATURES_C_STRUCT_NAME_COMPAT, (struct VISION_FIELD_FEATURES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_FIELD_FEATURES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_FIELD_FEATURES_GENERATED
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
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(VISIONROBOTS_GENERATED) // VISIONROBOTS_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define VISIONROBOTS_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define VISIONROBOTS_C_STRUCT_NAME_COMPAT VISIONROBOTS_C_STRUCT
#endif
                return SERIALISE(VISIONROBOTS_C_STRUCT_NAME_COMPAT, (struct VISIONROBOTS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISIONROBOTS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionDetectionHorizons_v:
            {
#if defined(WB_VISION_DETECTION_HORIZONS_GENERATED)  || defined(VISION_DETECTION_HORIZONS_GENERATED) // VISION_DETECTION_HORIZONS_GENERATED is legacy, don't use
#ifdef WB_VISION_DETECTION_HORIZONS_C_STRUCT
#define VISION_DETECTION_HORIZONS_C_STRUCT_NAME_COMPAT WB_VISION_DETECTION_HORIZONS_C_STRUCT
#else
#define VISION_DETECTION_HORIZONS_C_STRUCT_NAME_COMPAT VISION_DETECTION_HORIZONS_C_STRUCT
#endif
                return SERIALISE(VISION_DETECTION_HORIZONS_C_STRUCT_NAME_COMPAT, (struct VISION_DETECTION_HORIZONS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_DETECTION_HORIZONS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_DETECTION_HORIZONS_GENERATED
                break;
            }
            case kwb_NaoWalkCommand_v:
            {
#if defined(WB_NAOWALKCOMMAND_GENERATED)  || defined(NAOWALKCOMMAND_GENERATED) // NAOWALKCOMMAND_GENERATED is legacy, don't use
#ifdef WB_NAOWALKCOMMAND_C_STRUCT
#define NAOWALKCOMMAND_C_STRUCT_NAME_COMPAT WB_NAOWALKCOMMAND_C_STRUCT
#else
#define NAOWALKCOMMAND_C_STRUCT_NAME_COMPAT NAOWALKCOMMAND_C_STRUCT
#endif
                return SERIALISE(NAOWALKCOMMAND_C_STRUCT_NAME_COMPAT, (struct NAOWALKCOMMAND_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NAOWALKCOMMAND_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_NAOWALKCOMMAND_GENERATED
                break;
            }
            case kwb_NaoWalkStatus_v:
            {
#if defined(WB_NAOWALKSTATUS_GENERATED)  || defined(NAOWALKSTATUS_GENERATED) // NAOWALKSTATUS_GENERATED is legacy, don't use
#ifdef WB_NAOWALKSTATUS_C_STRUCT
#define NAOWALKSTATUS_C_STRUCT_NAME_COMPAT WB_NAOWALKSTATUS_C_STRUCT
#else
#define NAOWALKSTATUS_C_STRUCT_NAME_COMPAT NAOWALKSTATUS_C_STRUCT
#endif
                return SERIALISE(NAOWALKSTATUS_C_STRUCT_NAME_COMPAT, (struct NAOWALKSTATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NAOWALKSTATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_NAOWALKSTATUS_GENERATED
                break;
            }
            case kwb_HAL_LLegTarget_Ctrl_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALLEGTARGET_GENERATED) // HALLEGTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT HALLEGTARGET_C_STRUCT
#endif
                return SERIALISE(HALLEGTARGET_C_STRUCT_NAME_COMPAT, (struct HALLEGTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALLEGTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LLegTarget_Stat_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALLEGTARGET_GENERATED) // HALLEGTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT HALLEGTARGET_C_STRUCT
#endif
                return SERIALISE(HALLEGTARGET_C_STRUCT_NAME_COMPAT, (struct HALLEGTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALLEGTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_LLegTarget_Tolr_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALLEGTARGET_GENERATED) // HALLEGTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT HALLEGTARGET_C_STRUCT
#endif
                return SERIALISE(HALLEGTARGET_C_STRUCT_NAME_COMPAT, (struct HALLEGTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALLEGTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Ctrl_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALLEGTARGET_GENERATED) // HALLEGTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT HALLEGTARGET_C_STRUCT
#endif
                return SERIALISE(HALLEGTARGET_C_STRUCT_NAME_COMPAT, (struct HALLEGTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALLEGTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Stat_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALLEGTARGET_GENERATED) // HALLEGTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT HALLEGTARGET_C_STRUCT
#endif
                return SERIALISE(HALLEGTARGET_C_STRUCT_NAME_COMPAT, (struct HALLEGTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALLEGTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_HAL_RLegTarget_Tolr_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(HALLEGTARGET_GENERATED) // HALLEGTARGET_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define HALLEGTARGET_C_STRUCT_NAME_COMPAT HALLEGTARGET_C_STRUCT
#endif
                return SERIALISE(HALLEGTARGET_C_STRUCT_NAME_COMPAT, (struct HALLEGTARGET_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HALLEGTARGET_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_VisionDetectionGoals_v:
            {
#if defined(WB_VISION_DETECTION_GOALS_GENERATED)  || defined(VISION_DETECTION_GOALS_GENERATED) // VISION_DETECTION_GOALS_GENERATED is legacy, don't use
#ifdef WB_VISION_DETECTION_GOALS_C_STRUCT
#define VISION_DETECTION_GOALS_C_STRUCT_NAME_COMPAT WB_VISION_DETECTION_GOALS_C_STRUCT
#else
#define VISION_DETECTION_GOALS_C_STRUCT_NAME_COMPAT VISION_DETECTION_GOALS_C_STRUCT
#endif
                return SERIALISE(VISION_DETECTION_GOALS_C_STRUCT_NAME_COMPAT, (struct VISION_DETECTION_GOALS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_DETECTION_GOALS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_DETECTION_GOALS_GENERATED
                break;
            }
            case kwb_TeleoperationControl_v:
            {
#if defined(WB_TELEOPERATIONCONTROL_GENERATED)  || defined(TELEOPERATIONCONTROL_GENERATED) // TELEOPERATIONCONTROL_GENERATED is legacy, don't use
#ifdef WB_TELEOPERATIONCONTROL_C_STRUCT
#define TELEOPERATIONCONTROL_C_STRUCT_NAME_COMPAT WB_TELEOPERATIONCONTROL_C_STRUCT
#else
#define TELEOPERATIONCONTROL_C_STRUCT_NAME_COMPAT TELEOPERATIONCONTROL_C_STRUCT
#endif
                return SERIALISE(TELEOPERATIONCONTROL_C_STRUCT_NAME_COMPAT, (struct TELEOPERATIONCONTROL_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef TELEOPERATIONCONTROL_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_TELEOPERATIONCONTROL_GENERATED
                break;
            }
            case kwb_TeleoperationStatus_v:
            {
#if defined(WB_TELEOPERATIONSTATUS_GENERATED)  || defined(TELEOPERATIONSTATUS_GENERATED) // TELEOPERATIONSTATUS_GENERATED is legacy, don't use
#ifdef WB_TELEOPERATIONSTATUS_C_STRUCT
#define TELEOPERATIONSTATUS_C_STRUCT_NAME_COMPAT WB_TELEOPERATIONSTATUS_C_STRUCT
#else
#define TELEOPERATIONSTATUS_C_STRUCT_NAME_COMPAT TELEOPERATIONSTATUS_C_STRUCT
#endif
                return SERIALISE(TELEOPERATIONSTATUS_C_STRUCT_NAME_COMPAT, (struct TELEOPERATIONSTATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef TELEOPERATIONSTATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_TELEOPERATIONSTATUS_GENERATED
                break;
            }
            case kwb_VisionDetectionBalls_v:
            {
#if defined(WB_VISION_DETECTION_BALLS_GENERATED)  || defined(VISION_DETECTION_BALLS_GENERATED) // VISION_DETECTION_BALLS_GENERATED is legacy, don't use
#ifdef WB_VISION_DETECTION_BALLS_C_STRUCT
#define VISION_DETECTION_BALLS_C_STRUCT_NAME_COMPAT WB_VISION_DETECTION_BALLS_C_STRUCT
#else
#define VISION_DETECTION_BALLS_C_STRUCT_NAME_COMPAT VISION_DETECTION_BALLS_C_STRUCT
#endif
                return SERIALISE(VISION_DETECTION_BALLS_C_STRUCT_NAME_COMPAT, (struct VISION_DETECTION_BALLS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_DETECTION_BALLS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_DETECTION_BALLS_GENERATED
                break;
            }
            case kwb_TeleoperationControlVR_v:
            {
#if defined(WB_TELEOPERATIONCONTROLVR_GENERATED)  || defined(TELEOPERATIONCONTROLVR_GENERATED) // TELEOPERATIONCONTROLVR_GENERATED is legacy, don't use
#ifdef WB_TELEOPERATIONCONTROLVR_C_STRUCT
#define TELEOPERATIONCONTROLVR_C_STRUCT_NAME_COMPAT WB_TELEOPERATIONCONTROLVR_C_STRUCT
#else
#define TELEOPERATIONCONTROLVR_C_STRUCT_NAME_COMPAT TELEOPERATIONCONTROLVR_C_STRUCT
#endif
                return SERIALISE(TELEOPERATIONCONTROLVR_C_STRUCT_NAME_COMPAT, (struct TELEOPERATIONCONTROLVR_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef TELEOPERATIONCONTROLVR_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_TELEOPERATIONCONTROLVR_GENERATED
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
#if defined(WB_MACHINE_FILTERED_VISION_GENERATED)  || defined(MACHINE_FILTERED_VISION_GENERATED) // MACHINE_FILTERED_VISION_GENERATED is legacy, don't use
#ifdef WB_MACHINE_FILTERED_VISION_C_STRUCT
#define MACHINE_FILTERED_VISION_C_STRUCT_NAME_COMPAT WB_MACHINE_FILTERED_VISION_C_STRUCT
#else
#define MACHINE_FILTERED_VISION_C_STRUCT_NAME_COMPAT MACHINE_FILTERED_VISION_C_STRUCT
#endif
                return SERIALISE(MACHINE_FILTERED_VISION_C_STRUCT_NAME_COMPAT, (struct MACHINE_FILTERED_VISION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MACHINE_FILTERED_VISION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_MACHINE_FILTERED_VISION_GENERATED
                break;
            }
            case kwb_MicrowaveStatus_v:
            {
#if defined(WB_MICROWAVE_STATUS_GENERATED)  || defined(MICROWAVE_STATUS_GENERATED) // MICROWAVE_STATUS_GENERATED is legacy, don't use
#ifdef WB_MICROWAVE_STATUS_C_STRUCT
#define MICROWAVE_STATUS_C_STRUCT_NAME_COMPAT WB_MICROWAVE_STATUS_C_STRUCT
#else
#define MICROWAVE_STATUS_C_STRUCT_NAME_COMPAT MICROWAVE_STATUS_C_STRUCT
#endif
                return SERIALISE(MICROWAVE_STATUS_C_STRUCT_NAME_COMPAT, (struct MICROWAVE_STATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MICROWAVE_STATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_MICROWAVE_STATUS_GENERATED
                break;
            }
            case kwb_Buttons_v:
            {
#if defined(WB_BUTTONS_GENERATED)  || defined(BUTTONS_GENERATED) // BUTTONS_GENERATED is legacy, don't use
#ifdef WB_BUTTONS_C_STRUCT
#define BUTTONS_C_STRUCT_NAME_COMPAT WB_BUTTONS_C_STRUCT
#else
#define BUTTONS_C_STRUCT_NAME_COMPAT BUTTONS_C_STRUCT
#endif
                return SERIALISE(BUTTONS_C_STRUCT_NAME_COMPAT, (struct BUTTONS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef BUTTONS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_BUTTONS_GENERATED
                break;
            }
            case kwb_MachineFilteredLocalisationVision_v:
            {
#if defined(WB_MACHINE_FILTERED_LOCALISATION_VISION_GENERATED)  || defined(MACHINE_FILTERED_LOCALISATION_VISION_GENERATED) // MACHINE_FILTERED_LOCALISATION_VISION_GENERATED is legacy, don't use
#ifdef WB_MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT
#define MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT_NAME_COMPAT WB_MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT
#else
#define MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT_NAME_COMPAT MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT
#endif
                return SERIALISE(MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT_NAME_COMPAT, (struct MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MACHINE_FILTERED_LOCALISATION_VISION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_MACHINE_FILTERED_LOCALISATION_VISION_GENERATED
                break;
            }
            case kwb_SensorsJointCurrent_v:
            {
#if defined(SerialisationNotSupportedWithLegacyNaming)  || defined(NAOJOINTLISTFLOAT_GENERATED) // NAOJOINTLISTFLOAT_GENERATED is legacy, don't use
#ifdef NotSupportedWithLegacyNaming
#define NAOJOINTLISTFLOAT_C_STRUCT_NAME_COMPAT NotSupportedWithLegacyNaming
#else
#define NAOJOINTLISTFLOAT_C_STRUCT_NAME_COMPAT NAOJOINTLISTFLOAT_C_STRUCT
#endif
                return SERIALISE(NAOJOINTLISTFLOAT_C_STRUCT_NAME_COMPAT, (struct NAOJOINTLISTFLOAT_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NAOJOINTLISTFLOAT_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //SerialisationNotSupportedWithLegacyNaming
                break;
            }
            case kwb_DataLogger_v:
            {
#if defined(WB_DATA_LOGGER_GENERATED)  || defined(DATA_LOGGER_GENERATED) // DATA_LOGGER_GENERATED is legacy, don't use
#ifdef WB_DATA_LOGGER_C_STRUCT
#define DATA_LOGGER_C_STRUCT_NAME_COMPAT WB_DATA_LOGGER_C_STRUCT
#else
#define DATA_LOGGER_C_STRUCT_NAME_COMPAT DATA_LOGGER_C_STRUCT
#endif
                return SERIALISE(DATA_LOGGER_C_STRUCT_NAME_COMPAT, (struct DATA_LOGGER_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef DATA_LOGGER_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_DATA_LOGGER_GENERATED
                break;
            }
            case kwb_MachineFilteredLines_v:
            {
#if defined(WB_MACHINE_FILTERED_LINES_GENERATED)  || defined(MACHINE_FILTERED_LINES_GENERATED) // MACHINE_FILTERED_LINES_GENERATED is legacy, don't use
#ifdef WB_MACHINE_FILTERED_LINES_C_STRUCT
#define MACHINE_FILTERED_LINES_C_STRUCT_NAME_COMPAT WB_MACHINE_FILTERED_LINES_C_STRUCT
#else
#define MACHINE_FILTERED_LINES_C_STRUCT_NAME_COMPAT MACHINE_FILTERED_LINES_C_STRUCT
#endif
                return SERIALISE(MACHINE_FILTERED_LINES_C_STRUCT_NAME_COMPAT, (struct MACHINE_FILTERED_LINES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MACHINE_FILTERED_LINES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_MACHINE_FILTERED_LINES_GENERATED
                break;
            }
            case kwb_BallLocation_v:
            {
#if defined(WB_LOCATION_GENERATED)  || defined(LOCATION_GENERATED) // LOCATION_GENERATED is legacy, don't use
#ifdef WB_LOCATION_C_STRUCT
#define LOCATION_C_STRUCT_NAME_COMPAT WB_LOCATION_C_STRUCT
#else
#define LOCATION_C_STRUCT_NAME_COMPAT LOCATION_C_STRUCT
#endif
                return SERIALISE(LOCATION_C_STRUCT_NAME_COMPAT, (struct LOCATION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef LOCATION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_LOCATION_GENERATED
                break;
            }
            case kwb_LeftGoalPostLocation_v:
            {
#if defined(WB_LOCATION_GENERATED)  || defined(LOCATION_GENERATED) // LOCATION_GENERATED is legacy, don't use
#ifdef WB_LOCATION_C_STRUCT
#define LOCATION_C_STRUCT_NAME_COMPAT WB_LOCATION_C_STRUCT
#else
#define LOCATION_C_STRUCT_NAME_COMPAT LOCATION_C_STRUCT
#endif
                return SERIALISE(LOCATION_C_STRUCT_NAME_COMPAT, (struct LOCATION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef LOCATION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_LOCATION_GENERATED
                break;
            }
            case kwb_RightGoalPostLocation_v:
            {
#if defined(WB_LOCATION_GENERATED)  || defined(LOCATION_GENERATED) // LOCATION_GENERATED is legacy, don't use
#ifdef WB_LOCATION_C_STRUCT
#define LOCATION_C_STRUCT_NAME_COMPAT WB_LOCATION_C_STRUCT
#else
#define LOCATION_C_STRUCT_NAME_COMPAT LOCATION_C_STRUCT
#endif
                return SERIALISE(LOCATION_C_STRUCT_NAME_COMPAT, (struct LOCATION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef LOCATION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_LOCATION_GENERATED
                break;
            }
            case kwb_GoalLocation_v:
            {
#if defined(WB_LOCATION_GENERATED)  || defined(LOCATION_GENERATED) // LOCATION_GENERATED is legacy, don't use
#ifdef WB_LOCATION_C_STRUCT
#define LOCATION_C_STRUCT_NAME_COMPAT WB_LOCATION_C_STRUCT
#else
#define LOCATION_C_STRUCT_NAME_COMPAT LOCATION_C_STRUCT
#endif
                return SERIALISE(LOCATION_C_STRUCT_NAME_COMPAT, (struct LOCATION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef LOCATION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_LOCATION_GENERATED
                break;
            }
            case kwb_NaoSonarProtectedWalkCommand_v:
            {
#if defined(WB_NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED)  || defined(NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED) // NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED is legacy, don't use
#ifdef WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT
#define NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT_NAME_COMPAT WB_NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT
#else
#define NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT_NAME_COMPAT NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT
#endif
                return SERIALISE(NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT_NAME_COMPAT, (struct NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NAO_SONAR_PROTECTED_WALK_COMMAND_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_NAO_SONAR_PROTECTED_WALK_COMMAND_GENERATED
                break;
            }
            case kwb_NaoObstacleDirection_v:
            {
#if defined(WB_NAO_OBSTACLE_DIRECTION_GENERATED)  || defined(NAO_OBSTACLE_DIRECTION_GENERATED) // NAO_OBSTACLE_DIRECTION_GENERATED is legacy, don't use
#ifdef WB_NAO_OBSTACLE_DIRECTION_C_STRUCT
#define NAO_OBSTACLE_DIRECTION_C_STRUCT_NAME_COMPAT WB_NAO_OBSTACLE_DIRECTION_C_STRUCT
#else
#define NAO_OBSTACLE_DIRECTION_C_STRUCT_NAME_COMPAT NAO_OBSTACLE_DIRECTION_C_STRUCT
#endif
                return SERIALISE(NAO_OBSTACLE_DIRECTION_C_STRUCT_NAME_COMPAT, (struct NAO_OBSTACLE_DIRECTION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef NAO_OBSTACLE_DIRECTION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_NAO_OBSTACLE_DIRECTION_GENERATED
                break;
            }
            case kwb_DominantFrequencies_v:
            {
#if defined(WB_DOMINANT_FREQUENCIES_GENERATED)  || defined(DOMINANT_FREQUENCIES_GENERATED) // DOMINANT_FREQUENCIES_GENERATED is legacy, don't use
#ifdef WB_DOMINANT_FREQUENCIES_C_STRUCT
#define DOMINANT_FREQUENCIES_C_STRUCT_NAME_COMPAT WB_DOMINANT_FREQUENCIES_C_STRUCT
#else
#define DOMINANT_FREQUENCIES_C_STRUCT_NAME_COMPAT DOMINANT_FREQUENCIES_C_STRUCT
#endif
                return SERIALISE(DOMINANT_FREQUENCIES_C_STRUCT_NAME_COMPAT, (struct DOMINANT_FREQUENCIES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef DOMINANT_FREQUENCIES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_DOMINANT_FREQUENCIES_GENERATED
                break;
            }
            case kwb_MissionPriorityForObstacles_v:
            {
#if defined(WB_MISSION_PRIORITY_FOR_OBSTACLES_GENERATED)  || defined(MISSION_PRIORITY_FOR_OBSTACLES_GENERATED) // MISSION_PRIORITY_FOR_OBSTACLES_GENERATED is legacy, don't use
#ifdef WB_MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT
#define MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT_NAME_COMPAT WB_MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT
#else
#define MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT_NAME_COMPAT MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT
#endif
                return SERIALISE(MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT_NAME_COMPAT, (struct MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MISSION_PRIORITY_FOR_OBSTACLES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_MISSION_PRIORITY_FOR_OBSTACLES_GENERATED
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
#if defined(WB_FREQUENCY_LIMITS_GENERATED)  || defined(FREQUENCY_LIMITS_GENERATED) // FREQUENCY_LIMITS_GENERATED is legacy, don't use
#ifdef WB_FREQUENCY_LIMITS_C_STRUCT
#define FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT WB_FREQUENCY_LIMITS_C_STRUCT
#else
#define FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT FREQUENCY_LIMITS_C_STRUCT
#endif
                return SERIALISE(FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT, (struct FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_FREQUENCY_LIMITS_GENERATED
                break;
            }
            case kwb_FrequencyStatus_v:
            {
#if defined(WB_FREQUENCY_LIMITS_GENERATED)  || defined(FREQUENCY_LIMITS_GENERATED) // FREQUENCY_LIMITS_GENERATED is legacy, don't use
#ifdef WB_FREQUENCY_LIMITS_C_STRUCT
#define FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT WB_FREQUENCY_LIMITS_C_STRUCT
#else
#define FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT FREQUENCY_LIMITS_C_STRUCT
#endif
                return SERIALISE(FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT, (struct FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef FREQUENCY_LIMITS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_FREQUENCY_LIMITS_GENERATED
                break;
            }
            case kwb_HeadJointSensors_v:
            {
#if defined(WB_HEAD_JOINT_SENSORS_GENERATED)  || defined(HEAD_JOINT_SENSORS_GENERATED) // HEAD_JOINT_SENSORS_GENERATED is legacy, don't use
#ifdef WB_HEAD_JOINT_SENSORS_C_STRUCT
#define HEAD_JOINT_SENSORS_C_STRUCT_NAME_COMPAT WB_HEAD_JOINT_SENSORS_C_STRUCT
#else
#define HEAD_JOINT_SENSORS_C_STRUCT_NAME_COMPAT HEAD_JOINT_SENSORS_C_STRUCT
#endif
                return SERIALISE(HEAD_JOINT_SENSORS_C_STRUCT_NAME_COMPAT, (struct HEAD_JOINT_SENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef HEAD_JOINT_SENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_HEAD_JOINT_SENSORS_GENERATED
                break;
            }
            case kwb_AdjustPositionConfidence_v:
            {
#if defined(WB_ADJUST_POSITION_CONFIDENCE_GENERATED)  || defined(ADJUST_POSITION_CONFIDENCE_GENERATED) // ADJUST_POSITION_CONFIDENCE_GENERATED is legacy, don't use
#ifdef WB_ADJUST_POSITION_CONFIDENCE_C_STRUCT
#define ADJUST_POSITION_CONFIDENCE_C_STRUCT_NAME_COMPAT WB_ADJUST_POSITION_CONFIDENCE_C_STRUCT
#else
#define ADJUST_POSITION_CONFIDENCE_C_STRUCT_NAME_COMPAT ADJUST_POSITION_CONFIDENCE_C_STRUCT
#endif
                return SERIALISE(ADJUST_POSITION_CONFIDENCE_C_STRUCT_NAME_COMPAT, (struct ADJUST_POSITION_CONFIDENCE_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef ADJUST_POSITION_CONFIDENCE_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_ADJUST_POSITION_CONFIDENCE_GENERATED
                break;
            }
            case kwb_GuVrTeleopVulkanControl_v:
            {
#if defined(WB_GU_VR_TELEOP_VULKAN_CONTROL_GENERATED)  || defined(GU_VR_TELEOP_VULKAN_CONTROL_GENERATED) // GU_VR_TELEOP_VULKAN_CONTROL_GENERATED is legacy, don't use
#ifdef WB_GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT
#define GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT_NAME_COMPAT WB_GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT
#else
#define GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT_NAME_COMPAT GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT
#endif
                return SERIALISE(GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT_NAME_COMPAT, (struct GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef GU_VR_TELEOP_VULKAN_CONTROL_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_GU_VR_TELEOP_VULKAN_CONTROL_GENERATED
                break;
            }
            case kwb_TemperatureSensors_v:
            {
#if defined(WB_TEMPERATURE_SENSORS_GENERATED)  || defined(TEMPERATURE_SENSORS_GENERATED) // TEMPERATURE_SENSORS_GENERATED is legacy, don't use
#ifdef WB_TEMPERATURE_SENSORS_C_STRUCT
#define TEMPERATURE_SENSORS_C_STRUCT_NAME_COMPAT WB_TEMPERATURE_SENSORS_C_STRUCT
#else
#define TEMPERATURE_SENSORS_C_STRUCT_NAME_COMPAT TEMPERATURE_SENSORS_C_STRUCT
#endif
                return SERIALISE(TEMPERATURE_SENSORS_C_STRUCT_NAME_COMPAT, (struct TEMPERATURE_SENSORS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef TEMPERATURE_SENSORS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_TEMPERATURE_SENSORS_GENERATED
                break;
            }
            case kwb_Overheating_v:
            {
#if defined(WB_OVERHEATING_GENERATED)  || defined(OVERHEATING_GENERATED) // OVERHEATING_GENERATED is legacy, don't use
#ifdef WB_OVERHEATING_C_STRUCT
#define OVERHEATING_C_STRUCT_NAME_COMPAT WB_OVERHEATING_C_STRUCT
#else
#define OVERHEATING_C_STRUCT_NAME_COMPAT OVERHEATING_C_STRUCT
#endif
                return SERIALISE(OVERHEATING_C_STRUCT_NAME_COMPAT, (struct OVERHEATING_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef OVERHEATING_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_OVERHEATING_GENERATED
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
#if defined(WB_BALL_POSITION_GENERATED)  || defined(BALL_POSITION_GENERATED) // BALL_POSITION_GENERATED is legacy, don't use
#ifdef WB_BALL_POSITION_C_STRUCT
#define BALL_POSITION_C_STRUCT_NAME_COMPAT WB_BALL_POSITION_C_STRUCT
#else
#define BALL_POSITION_C_STRUCT_NAME_COMPAT BALL_POSITION_C_STRUCT
#endif
                return SERIALISE(BALL_POSITION_C_STRUCT_NAME_COMPAT, (struct BALL_POSITION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef BALL_POSITION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_BALL_POSITION_GENERATED
                break;
            }
            case kwb_MemoryImageControl_v:
            {
#if defined(WB_MEMORY_IMAGE_CONTROL_STATUS_GENERATED)  || defined(MEMORY_IMAGE_CONTROL_STATUS_GENERATED) // MEMORY_IMAGE_CONTROL_STATUS_GENERATED is legacy, don't use
#ifdef WB_MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT
#define MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT WB_MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT
#else
#define MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT
#endif
                return SERIALISE(MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT, (struct MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_MEMORY_IMAGE_CONTROL_STATUS_GENERATED
                break;
            }
            case kwb_MemoryImageStatus_v:
            {
#if defined(WB_MEMORY_IMAGE_CONTROL_STATUS_GENERATED)  || defined(MEMORY_IMAGE_CONTROL_STATUS_GENERATED) // MEMORY_IMAGE_CONTROL_STATUS_GENERATED is legacy, don't use
#ifdef WB_MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT
#define MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT WB_MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT
#else
#define MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT
#endif
                return SERIALISE(MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT, (struct MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MEMORY_IMAGE_CONTROL_STATUS_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_MEMORY_IMAGE_CONTROL_STATUS_GENERATED
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
#if defined(WB_MY_POSITION_GENERATED)  || defined(MY_POSITION_GENERATED) // MY_POSITION_GENERATED is legacy, don't use
#ifdef WB_MY_POSITION_C_STRUCT
#define MY_POSITION_C_STRUCT_NAME_COMPAT WB_MY_POSITION_C_STRUCT
#else
#define MY_POSITION_C_STRUCT_NAME_COMPAT MY_POSITION_C_STRUCT
#endif
                return SERIALISE(MY_POSITION_C_STRUCT_NAME_COMPAT, (struct MY_POSITION_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef MY_POSITION_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_MY_POSITION_GENERATED
                break;
            }
            case kwb_VisionDetectionLines_v:
            {
#if defined(WB_VISION_DETECTION_LINES_GENERATED)  || defined(VISION_DETECTION_LINES_GENERATED) // VISION_DETECTION_LINES_GENERATED is legacy, don't use
#ifdef WB_VISION_DETECTION_LINES_C_STRUCT
#define VISION_DETECTION_LINES_C_STRUCT_NAME_COMPAT WB_VISION_DETECTION_LINES_C_STRUCT
#else
#define VISION_DETECTION_LINES_C_STRUCT_NAME_COMPAT VISION_DETECTION_LINES_C_STRUCT
#endif
                return SERIALISE(VISION_DETECTION_LINES_C_STRUCT_NAME_COMPAT, (struct VISION_DETECTION_LINES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_DETECTION_LINES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_DETECTION_LINES_GENERATED
                break;
            }
            case kwb_VisionDetectionFeatures_v:
            {
#if defined(WB_VISION_DETECTION_FEATURES_GENERATED)  || defined(VISION_DETECTION_FEATURES_GENERATED) // VISION_DETECTION_FEATURES_GENERATED is legacy, don't use
#ifdef WB_VISION_DETECTION_FEATURES_C_STRUCT
#define VISION_DETECTION_FEATURES_C_STRUCT_NAME_COMPAT WB_VISION_DETECTION_FEATURES_C_STRUCT
#else
#define VISION_DETECTION_FEATURES_C_STRUCT_NAME_COMPAT VISION_DETECTION_FEATURES_C_STRUCT
#endif
                return SERIALISE(VISION_DETECTION_FEATURES_C_STRUCT_NAME_COMPAT, (struct VISION_DETECTION_FEATURES_C_STRUCT_NAME_COMPAT *)message_in, serialised_out)
#undef VISION_DETECTION_FEATURES_C_STRUCT_NAME_COMPAT
#else
                return -1;
#endif //WB_VISION_DETECTION_FEATURES_GENERATED
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
