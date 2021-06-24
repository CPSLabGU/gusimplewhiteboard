/**
 *  /file guwhiteboardgetter.cpp
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

/** Auto-generated, don't modify! */

#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <gu_util.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-macros"
#define WHITEBOARD_POSTER_STRING_CONVERSION
#pragma clang diagnostic pop

#include "guwhiteboardtypelist_generated.h"
#include "guwhiteboardgetter.h"

using namespace std;
using namespace guWhiteboard;


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
extern "C"
{
    char *whiteboard_get(const char *message_type, gu_simple_message *msg)
    {
        return whiteboard_getmsg(types_map[message_type], msg);
    }

    char *whiteboard_get_from(gu_simple_whiteboard_descriptor *wbd, const char *message_type)
    {
        return whiteboard_getmsg_from(wbd, types_map[message_type]);
    }

    char *whiteboard_getmsg(int message_index, gu_simple_message *msg)
    {
        return gu_strdup(getmsg(wb_types(message_index), msg).c_str());
    }

    char *whiteboard_getmsg_from(gu_simple_whiteboard_descriptor *wbd, int message_index)
    {
        return gu_strdup(getmsg(wb_types(message_index), NULLPTR, wbd).c_str());
    }
} // extern C

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
static string intvectostring(const vector<int> &vec)
{
    stringstream ss;
    
    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
    {
        if (it != vec.begin()) ss << ",";
        ss << *it;
    }

    return ss.str();
}
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunreachable-code"
namespace guWhiteboard
{
    string getmsg(string message_type, gu_simple_message *msg, gu_simple_whiteboard_descriptor *wbd)
    {
        return getmsg(types_map[message_type], msg, wbd);
    }

    string getmsg(wb_types message_index, gu_simple_message *msg, gu_simple_whiteboard_descriptor *wbd)
    {
        switch (message_index)
        {

            case k_wb_reserved_SubscribeToAllTypes_v:
            {

                class wb_reserved_SubscribeToAllTypes_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Print_v:
            {

                class Print_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case k_Say_v:
            {

                class Say_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case k_Speech_v:
            {

                class Speech_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case k_QSay_v:
            {

                class QSay_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case k_QSpeech_v:
            {

                class QSpeech_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case k_SpeechOutput_v:
            {

                class SpeechOutput_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_GCGameState_v:
            {
#ifdef GCGAMESTATE_DEFINED
                class GCGameState_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GCGAMESTATE_DEFINED
            }
            case k_SensorsHandSensors_v:
            {
#ifdef SENSORSHANDSENSORS_DEFINED
                class SensorsHandSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSHANDSENSORS_DEFINED
            }
            case k_SensorsHeadSensors_v:
            {
#ifdef SENSORSHEADSENSORS_DEFINED
                class SensorsHeadSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSHEADSENSORS_DEFINED
            }
            case k_MOTION_Commands_v:
            {
#ifdef MOTION_COMMANDS_DEFINED
                class MOTION_Commands_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MOTION_COMMANDS_DEFINED
            }
            case k_MOTION_Status_v:
            {
#ifdef MOTION_STATUS_DEFINED
                class MOTION_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MOTION_STATUS_DEFINED
            }
            case k_HAL_HeadTarget_v:
            {
#ifdef HAL_HEADTARGET_DEFINED
                class HAL_HeadTarget_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_HEADTARGET_DEFINED
            }
            case k_SensorsFootSensors_v:
            {
#ifdef SENSORSFOOTSENSORS_DEFINED
                class SensorsFootSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSFOOTSENSORS_DEFINED
            }
            case k_SensorsBodySensors_v:
            {
#ifdef SENSORSBODYSENSORS_DEFINED
                class SensorsBodySensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSBODYSENSORS_DEFINED
            }
            case k_SENSORSLedsSensors_v:
            {
#ifdef SENSORSLEDSSENSORS_DEFINED
                class SENSORSLedsSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLEDSSENSORS_DEFINED
            }
            case k_SENSORSLegJointTemps_v:
            {
#ifdef SENSORSLEGJOINTTEMPS_DEFINED
                class SENSORSLegJointTemps_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLEGJOINTTEMPS_DEFINED
            }
            case k_SENSORSTorsoJointTemps_v:
            {
#ifdef SENSORSTORSOJOINTTEMPS_DEFINED
                class SENSORSTorsoJointTemps_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSTORSOJOINTTEMPS_DEFINED
            }
            case k_SENSORSLegJointSensors_v:
            {
#ifdef SENSORSLEGJOINTSENSORS_DEFINED
                class SENSORSLegJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLEGJOINTSENSORS_DEFINED
            }
            case k_SENSORSTorsoJointSensors_v:
            {
#ifdef SENSORSTORSOJOINTSENSORS_DEFINED
                class SENSORSTorsoJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSTORSOJOINTSENSORS_DEFINED
            }
            case k_SENSORSSonarSensors_v:
            {
#ifdef SENSORSSONARSENSORS_DEFINED
                class SENSORSSonarSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSSONARSENSORS_DEFINED
            }
            case k_FSM_Control_v:
            {
#ifdef FSMCONTROLSTATUS_DEFINED
                class FSM_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMCONTROLSTATUS_DEFINED
            }
            case k_FSM_Status_v:
            {
#ifdef FSMCONTROLSTATUS_DEFINED
                class FSM_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMCONTROLSTATUS_DEFINED
            }
            case k_FSM_Names_v:
            {
#ifdef FSMNAMES_DEFINED
                class FSM_Names_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMNAMES_DEFINED
            }
            case k_SoloTypeExample_v:
            {

                class SoloTypeExample_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_FilteredGoalSighting_v:
            {
#ifdef FILTEREDARRAYONEDIMOBJECTS_DEFINED
                class FilteredGoalSighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FILTEREDARRAYONEDIMOBJECTS_DEFINED
            }
            case k_NAO_State_v:
            {
#ifdef NAO_STATE_DEFINED
                class NAO_State_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAO_STATE_DEFINED
            }
            case k_UDPRN_v:
            {
#ifdef GCGAMESTATE_DEFINED
                class UDPRN_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GCGAMESTATE_DEFINED
            }
            case k_PlayerNumber_v:
            {

                class PlayerNumber_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_ManuallyPenalized_v:
            {

                class ManuallyPenalized_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_VisionControl_v:
            {
#ifdef VISIONCONTROLSTATUS_DEFINED
                class VisionControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONCONTROLSTATUS_DEFINED
            }
            case k_VisionStatus_v:
            {
#ifdef VISIONCONTROLSTATUS_DEFINED
                class VisionStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONCONTROLSTATUS_DEFINED
            }
            case k_FFTStatus_v:
            {
#ifdef FFTSTATUS_DEFINED
                class FFTStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FFTSTATUS_DEFINED
            }
            case k_FSOsighting_v:
            {
#ifdef FILTEREDARRAYONEDIMSONAR_DEFINED
                class FSOsighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FILTEREDARRAYONEDIMSONAR_DEFINED
            }
            case k_TopParticles_v:
            {
#ifdef TOPPARTICLES_DEFINED
                class TopParticles_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TOPPARTICLES_DEFINED
            }
            case k_FilteredBallSighting_v:
            {
#ifdef FILTEREDARRAYBALLSIGHTINGS_DEFINED
                class FilteredBallSighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FILTEREDARRAYBALLSIGHTINGS_DEFINED
            }
            case k_PF_ControlStatus_Modes_v:
            {

                class PF_ControlStatus_Modes_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_WEBOTS_NXT_bridge_v:
            {
#ifdef WEBOTS_NXT_BRIDGE_DEFINED
                class WEBOTS_NXT_bridge_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_BRIDGE_DEFINED
            }
            case k_WEBOTS_NXT_encoders_v:
            {
#ifdef WEBOTS_NXT_ENCODERS_DEFINED
                class WEBOTS_NXT_encoders_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_ENCODERS_DEFINED
            }
            case k_WEBOTS_NXT_camera_v:
            {
#ifdef WEBOTS_NXT_CAMERA_DEFINED
                class WEBOTS_NXT_camera_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_CAMERA_DEFINED
            }
            case k_WEBOTS_NXT_walk_isRunning_v:
            {
#ifdef WEBOTS_NXT_WALK_ISRUNNING_DEFINED
                class WEBOTS_NXT_walk_isRunning_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_WALK_ISRUNNING_DEFINED
            }
            case k_WEBOTS_NXT_deadReakoning_walk_v:
            {
#ifdef WEBOTS_NXT_DEADREAKONING_WALK_DEFINED
                class WEBOTS_NXT_deadReakoning_walk_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_DEADREAKONING_WALK_DEFINED
            }
            case k_WEBOTS_NXT_colorLine_walk_v:
            {
#ifdef WEBOTS_NXT_COLORLINE_WALK_DEFINED
                class WEBOTS_NXT_colorLine_walk_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_COLORLINE_WALK_DEFINED
            }
            case k_WEBOTS_NXT_gridMotions_v:
            {
#ifdef WEBOTS_NXT_GRIDMOTIONS_DEFINED
                class WEBOTS_NXT_gridMotions_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_GRIDMOTIONS_DEFINED
            }
            case k_VisionBall_v:
            {
#ifdef VISIONBALL_DEFINED
                class VisionBall_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONBALL_DEFINED
            }
            case k_VisionGoals_v:
            {
#ifdef VISIONGOALS_DEFINED
                class VisionGoals_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONGOALS_DEFINED
            }
            case k_WalkData_v:
            {
#ifdef WALKDATA_DEFINED
                class WalkData_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WALKDATA_DEFINED
            }
            case k_TeleoperationControlStatus_v:
            {
#ifdef TELEOPERATIONCONTROLSTATUS_DEFINED
                class TeleoperationControlStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TELEOPERATIONCONTROLSTATUS_DEFINED
            }
            case k_TeleoperationConnection_v:
            {

                class TeleoperationConnection_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_UDPWBNumber_v:
            {

                class UDPWBNumber_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_WEBOTS_NXT_bumper_v:
            {
#ifdef WEBOTS_NXT_BUMPER_DEFINED
                class WEBOTS_NXT_bumper_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_BUMPER_DEFINED
            }
            case k_WEBOTS_NXT_vector_bridge_v:
            {
#ifdef WEBOTS_NXT_VECTOR_BRIDGE_DEFINED
                class WEBOTS_NXT_vector_bridge_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_VECTOR_BRIDGE_DEFINED
            }
            case k_TopVisionLines_v:
            {
#ifdef VISIONLINES_DEFINED
                class TopVisionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONLINES_DEFINED
            }
            case k_BottomVisionLines_v:
            {
#ifdef VISIONLINES_DEFINED
                class BottomVisionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONLINES_DEFINED
            }
            case k_DifferentialRobotStatus_v:
            {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_DEFINED
                class DifferentialRobotStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DIFFERENTIALROBOTCONTROLSTATUS_DEFINED
            }
            case k_DifferentialRobotControl_v:
            {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_DEFINED
                class DifferentialRobotControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DIFFERENTIALROBOTCONTROLSTATUS_DEFINED
            }
            case k_XEyesPos_v:
            {
#ifdef POINT2D_DEFINED
                class XEyesPos_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //POINT2D_DEFINED
            }
            case k_VisionFace_v:
            {

                class VisionFace_t m(wbd);
                return msg ? intvectostring(m.get_from(msg)) : intvectostring(m.get());

            }
            case k_Draw_v:
            {

                class Draw_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case k_FSM_States_v:
            {
#ifdef FSMSTATE_DEFINED
                class FSM_States_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMSTATE_DEFINED
            }
            case k_Giraff_Interface_Status_v:
            {
#ifdef GIRAFF_MAINSERIALINTERFACE_DEFINED
                class Giraff_Interface_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GIRAFF_MAINSERIALINTERFACE_DEFINED
            }
            case k_Giraff_Interface_Command_v:
            {
#ifdef GIRAFF_MAINSERIALINTERFACE_DEFINED
                class Giraff_Interface_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GIRAFF_MAINSERIALINTERFACE_DEFINED
            }
            case k_NXT_Status_v:
            {
#ifdef NXT_INTERFACE_DEFINED
                class NXT_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_INTERFACE_DEFINED
            }
            case k_NXT_Command_v:
            {
#ifdef NXT_INTERFACE_DEFINED
                class NXT_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_INTERFACE_DEFINED
            }
            case k_APM_Status_v:
            {
#ifdef APM_INTERFACE_DEFINED
                class APM_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //APM_INTERFACE_DEFINED
            }
            case k_APM_Command_v:
            {
#ifdef APM_INTERFACE_DEFINED
                class APM_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //APM_INTERFACE_DEFINED
            }
            case k_REMOVED3_v:
            {

                class REMOVED3_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_REMOVED4_v:
            {

                class REMOVED4_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_CBall_v:
            {

                class CBall_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_OculusPrime_Command_v:
            {
#ifdef OCULUSPRIMEINTERFACE_DEFINED
                class OculusPrime_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //OCULUSPRIMEINTERFACE_DEFINED
            }
            case k_Input3D_v:
            {
#ifdef INPUT3D_DEFINED
                class Input3D_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //INPUT3D_DEFINED
            }
            case k_Oculus_Prime_Command_v:
            {
#ifdef OCULUS_PRIMESERIALINTERFACE_DEFINED
                class Oculus_Prime_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //OCULUS_PRIMESERIALINTERFACE_DEFINED
            }
            case k_IOPins_v:
            {
#ifdef IOPINS_DEFINED
                class IOPins_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //IOPINS_DEFINED
            }
            case k_NXT_Two_Touch_Status_v:
            {
#ifdef NXT_TWO_TOUCH_STATUS_DEFINED
                class NXT_Two_Touch_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_TWO_TOUCH_STATUS_DEFINED
            }
            case k_NXT_Sound_Control_v:
            {
#ifdef NXT_SOUND_CONTROL_DEFINED
                class NXT_Sound_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_SOUND_CONTROL_DEFINED
            }
            case k_NXT_Lights_Control_v:
            {
#ifdef NXT_LIGHTS_CONTROL_DEFINED
                class NXT_Lights_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_LIGHTS_CONTROL_DEFINED
            }
            case k_Clocks_v:
            {
#ifdef CLOCKS_DEFINED
                class Clocks_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //CLOCKS_DEFINED
            }
            case k_Channels_v:
            {
#ifdef CHANNELS_DEFINED
                class Channels_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //CHANNELS_DEFINED
            }
            case k_SwitchSubsumption_v:
            {
#ifdef SWITCHSUBSUMPTION_DEFINED
                class SwitchSubsumption_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SWITCHSUBSUMPTION_DEFINED
            }
            case k_TotoDoingMotion_v:
            {
#ifdef TOTODOINGMOTION_DEFINED
                class TotoDoingMotion_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TOTODOINGMOTION_DEFINED
            }
            case k_Count_v:
            {
#ifdef COUNT_DEFINED
                class Count_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //COUNT_DEFINED
            }
            case k_GreenEWon_v:
            {

                class GreenEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_WarnEW_v:
            {

                class WarnEW_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_TimeGTthirty_v:
            {

                class TimeGTthirty_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_AmberEWon_v:
            {

                class AmberEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_TurnRedEW_v:
            {

                class TurnRedEW_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_TimeGTfive_v:
            {

                class TimeGTfive_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_RedEWon_v:
            {

                class RedEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_GreenNSon_v:
            {

                class GreenNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_WarnNS_v:
            {

                class WarnNS_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_AmberNSon_v:
            {

                class AmberNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_TurnRedNS_v:
            {

                class TurnRedNS_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_RedNSon_v:
            {

                class RedNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_TimerReset_v:
            {

                class TimerReset_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_SLOT_UNUSED_v:
            {

                class SLOT_UNUSED_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_CarSensorPressed_v:
            {

                class CarSensorPressed_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_SwitchSubsumptionTrafficLights_v:
            {
#ifdef SWITCHSUBSUMPTIONTRAFFICLIGHTS_DEFINED
                class SwitchSubsumptionTrafficLights_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SWITCHSUBSUMPTIONTRAFFICLIGHTS_DEFINED
            }
            case k_Ball_Found_v:
            {

                class Ball_Found_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Ball_Calibration_File_v:
            {

                class Ball_Calibration_File_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case k_Ball_Calibration_Num_v:
            {

                class Ball_Calibration_Num_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Ball_Color_Num_v:
            {

                class Ball_Color_Num_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_HAL_LArmTarget_Ctrl_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_LArmTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case k_HAL_LArmTarget_Stat_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_LArmTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case k_HAL_LArmTarget_Tolr_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_LArmTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case k_HAL_RArmTarget_Ctrl_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_RArmTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case k_HAL_RArmTarget_Stat_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_RArmTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case k_HAL_RArmTarget_Tolr_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_RArmTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case k_VisionFieldFeatures_v:
            {
#ifdef VISIONFIELDFEATURES_DEFINED
                class VisionFieldFeatures_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONFIELDFEATURES_DEFINED
            }
            case k_WhistleBlown_v:
            {

                class WhistleBlown_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_VolumeControl_v:
            {

                class VolumeControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_VisionRobots_v:
            {
#ifdef VISIONROBOTS_DEFINED
                class VisionRobots_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONROBOTS_DEFINED
            }
            case k_VisionDetectionHorizons_v:
            {
#ifdef VISIONDETECTIONHORIZONS_DEFINED
                class VisionDetectionHorizons_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONHORIZONS_DEFINED
            }
            case k_NaoWalkCommand_v:
            {
#ifdef NAOWALKCOMMAND_DEFINED
                class NaoWalkCommand_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOWALKCOMMAND_DEFINED
            }
            case k_NaoWalkStatus_v:
            {
#ifdef NAOWALKSTATUS_DEFINED
                class NaoWalkStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOWALKSTATUS_DEFINED
            }
            case k_HAL_LLegTarget_Ctrl_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_LLegTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case k_HAL_LLegTarget_Stat_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_LLegTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case k_HAL_LLegTarget_Tolr_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_LLegTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case k_HAL_RLegTarget_Ctrl_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_RLegTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case k_HAL_RLegTarget_Stat_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_RLegTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case k_HAL_RLegTarget_Tolr_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_RLegTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case k_VisionDetectionGoals_v:
            {
#ifdef VISIONDETECTIONGOALS_DEFINED
                class VisionDetectionGoals_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONGOALS_DEFINED
            }
            case k_TeleoperationControl_v:
            {
#ifdef TELEOPERATIONCONTROL_DEFINED
                class TeleoperationControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TELEOPERATIONCONTROL_DEFINED
            }
            case k_TeleoperationStatus_v:
            {
#ifdef TELEOPERATIONSTATUS_DEFINED
                class TeleoperationStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TELEOPERATIONSTATUS_DEFINED
            }
            case k_VisionDetectionBalls_v:
            {
#ifdef VISIONDETECTIONBALLS_DEFINED
                class VisionDetectionBalls_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONBALLS_DEFINED
            }
            case k_TeleoperationControlVR_v:
            {
#ifdef TELEOPERATIONCONTROLVR_DEFINED
                class TeleoperationControlVR_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TELEOPERATIONCONTROLVR_DEFINED
            }
            case k_ParticleOutputMap_v:
            {

                class ParticleOutputMap_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_ParticleOutputMapControl_v:
            {

                class ParticleOutputMapControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_FFTControl_v:
            {

                class FFTControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_MachineFilteredNaoVision_v:
            {
#ifdef MACHINEFILTEREDVISION_DEFINED
                class MachineFilteredNaoVision_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MACHINEFILTEREDVISION_DEFINED
            }
            case k_MicrowaveStatus_v:
            {
#ifdef MICROWAVESTATUS_DEFINED
                class MicrowaveStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MICROWAVESTATUS_DEFINED
            }
            case k_Buttons_v:
            {
#ifdef BUTTONS_DEFINED
                class Buttons_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //BUTTONS_DEFINED
            }
            case k_MachineFilteredLocalisationVision_v:
            {
#ifdef MACHINEFILTEREDLOCALISATIONVISION_DEFINED
                class MachineFilteredLocalisationVision_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MACHINEFILTEREDLOCALISATIONVISION_DEFINED
            }
            case k_SensorsJointCurrent_v:
            {
#ifdef NAOJOINTLISTFLOAT_DEFINED
                class SensorsJointCurrent_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOJOINTLISTFLOAT_DEFINED
            }
            case k_DataLogger_v:
            {
#ifdef DATALOGGER_DEFINED
                class DataLogger_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DATALOGGER_DEFINED
            }
            case k_MachineFilteredLines_v:
            {
#ifdef MACHINEFILTEREDLINES_DEFINED
                class MachineFilteredLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MACHINEFILTEREDLINES_DEFINED
            }
            case k_BallLocation_v:
            {
#ifdef LOCATION_DEFINED
                class BallLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //LOCATION_DEFINED
            }
            case k_LeftGoalPostLocation_v:
            {
#ifdef LOCATION_DEFINED
                class LeftGoalPostLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //LOCATION_DEFINED
            }
            case k_RightGoalPostLocation_v:
            {
#ifdef LOCATION_DEFINED
                class RightGoalPostLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //LOCATION_DEFINED
            }
            case k_GoalLocation_v:
            {
#ifdef LOCATION_DEFINED
                class GoalLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //LOCATION_DEFINED
            }
            case k_NaoSonarProtectedWalkCommand_v:
            {
#ifdef NAOSONARPROTECTEDWALKCOMMAND_DEFINED
                class NaoSonarProtectedWalkCommand_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOSONARPROTECTEDWALKCOMMAND_DEFINED
            }
            case k_NaoObstacleDirection_v:
            {
#ifdef NAOOBSTACLEDIRECTION_DEFINED
                class NaoObstacleDirection_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOOBSTACLEDIRECTION_DEFINED
            }
            case k_DominantFrequencies_v:
            {
#ifdef DOMINANTFREQUENCIES_DEFINED
                class DominantFrequencies_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DOMINANTFREQUENCIES_DEFINED
            }
            case k_MissionPriorityForObstacles_v:
            {
#ifdef MISSIONPRIORITYFOROBSTACLES_DEFINED
                class MissionPriorityForObstacles_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MISSIONPRIORITYFOROBSTACLES_DEFINED
            }
            case k_WavLoad_v:
            {

                class WavLoad_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case k_WavPlay_v:
            {

                class WavPlay_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_ReproduceWavNotSilent_v:
            {

                class ReproduceWavNotSilent_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_FrequencyControl_v:
            {
#ifdef FREQUENCYLIMITS_DEFINED
                class FrequencyControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FREQUENCYLIMITS_DEFINED
            }
            case k_FrequencyStatus_v:
            {
#ifdef FREQUENCYLIMITS_DEFINED
                class FrequencyStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FREQUENCYLIMITS_DEFINED
            }
            case k_HeadJointSensors_v:
            {
#ifdef HEADJOINTSENSORS_DEFINED
                class HeadJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HEADJOINTSENSORS_DEFINED
            }
            case k_AdjustPositionConfidence_v:
            {
#ifdef ADJUSTPOSITIONCONFIDENCE_DEFINED
                class AdjustPositionConfidence_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //ADJUSTPOSITIONCONFIDENCE_DEFINED
            }
            case k_GuVrTeleopVulkanControl_v:
            {
#ifdef GUVRTELEOPVULKANCONTROL_DEFINED
                class GuVrTeleopVulkanControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GUVRTELEOPVULKANCONTROL_DEFINED
            }
            case k_TemperatureSensors_v:
            {
#ifdef TEMPERATURESENSORS_DEFINED
                class TemperatureSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TEMPERATURESENSORS_DEFINED
            }
            case k_Overheating_v:
            {
#ifdef OVERHEATING_DEFINED
                class Overheating_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //OVERHEATING_DEFINED
            }
            case k_buttonPushed_v:
            {

                class buttonPushed_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_doorOpen_v:
            {

                class doorOpen_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_timeLeft_v:
            {

                class timeLeft_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_motor_v:
            {

                class motor_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_sound_v:
            {

                class sound_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_light_v:
            {

                class light_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino2Pin_v:
            {

                class Arduino2Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino2PinValue_v:
            {

                class Arduino2PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino3Pin_v:
            {

                class Arduino3Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino3PinValue_v:
            {

                class Arduino3PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino4Pin_v:
            {

                class Arduino4Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino4PinValue_v:
            {

                class Arduino4PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino5Pin_v:
            {

                class Arduino5Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino5PinValue_v:
            {

                class Arduino5PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino6Pin_v:
            {

                class Arduino6Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino6PinValue_v:
            {

                class Arduino6PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino7Pin_v:
            {

                class Arduino7Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino7PinValue_v:
            {

                class Arduino7PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino8Pin_v:
            {

                class Arduino8Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino8PinValue_v:
            {

                class Arduino8PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino9Pin_v:
            {

                class Arduino9Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_Arduino9PinValue_v:
            {

                class Arduino9PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_BallPosition_v:
            {
#ifdef BALLPOSITION_DEFINED
                class BallPosition_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //BALLPOSITION_DEFINED
            }
            case k_MemoryImageControl_v:
            {
#ifdef MEMORYIMAGECONTROLSTATUS_DEFINED
                class MemoryImageControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MEMORYIMAGECONTROLSTATUS_DEFINED
            }
            case k_MemoryImageStatus_v:
            {
#ifdef MEMORYIMAGECONTROLSTATUS_DEFINED
                class MemoryImageStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MEMORYIMAGECONTROLSTATUS_DEFINED
            }
            case k_LHandGripper_v:
            {

                class LHandGripper_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_RHandGripper_v:
            {

                class RHandGripper_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case k_MyPosition_v:
            {
#ifdef MYPOSITION_DEFINED
                class MyPosition_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MYPOSITION_DEFINED
            }
            case k_VisionDetectionLines_v:
            {
#ifdef VISIONDETECTIONLINES_DEFINED
                class VisionDetectionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONLINES_DEFINED
            }
            case k_VisionDetectionFeatures_v:
            {
#ifdef VISIONDETECTIONFEATURES_DEFINED
                class VisionDetectionFeatures_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONFEATURES_DEFINED
            }
        }
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
        (void) msg;
        return "##unsupported##";
#pragma clang diagnostic pop
    }
#pragma clang diagnostic pop
#pragma clang diagnostic pop
}
