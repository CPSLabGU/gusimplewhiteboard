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

            case kwb_reserved_SubscribeToAllTypes_v:
            {

                class wb_reserved_SubscribeToAllTypes_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kPrint_v:
            {

                class Print_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kSay_v:
            {

                class Say_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kSpeech_v:
            {

                class Speech_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kQSay_v:
            {

                class QSay_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kQSpeech_v:
            {

                class QSpeech_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kSpeechOutput_v:
            {

                class SpeechOutput_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kGCGameState_v:
            {
#ifdef GCGAMESTATE_DEFINED
                class GCGameState_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GCGAMESTATE_DEFINED
            }
            case kSensorsHandSensors_v:
            {
#ifdef SENSORSHANDSENSORS_DEFINED
                class SensorsHandSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSHANDSENSORS_DEFINED
            }
            case kSensorsHeadSensors_v:
            {
#ifdef SENSORSHEADSENSORS_DEFINED
                class SensorsHeadSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSHEADSENSORS_DEFINED
            }
            case kMOTION_Commands_v:
            {
#ifdef MOTION_COMMANDS_DEFINED
                class MOTION_Commands_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MOTION_COMMANDS_DEFINED
            }
            case kMOTION_Status_v:
            {
#ifdef MOTION_STATUS_DEFINED
                class MOTION_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MOTION_STATUS_DEFINED
            }
            case kHAL_HeadTarget_v:
            {
#ifdef HAL_HEADTARGET_DEFINED
                class HAL_HeadTarget_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_HEADTARGET_DEFINED
            }
            case kSensorsFootSensors_v:
            {
#ifdef SENSORSFOOTSENSORS_DEFINED
                class SensorsFootSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSFOOTSENSORS_DEFINED
            }
            case kSensorsBodySensors_v:
            {
#ifdef SENSORSBODYSENSORS_DEFINED
                class SensorsBodySensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSBODYSENSORS_DEFINED
            }
            case kSENSORSLedsSensors_v:
            {
#ifdef SENSORSLEDSSENSORS_DEFINED
                class SENSORSLedsSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLEDSSENSORS_DEFINED
            }
            case kSENSORSLegJointTemps_v:
            {
#ifdef SENSORSLEGJOINTTEMPS_DEFINED
                class SENSORSLegJointTemps_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLEGJOINTTEMPS_DEFINED
            }
            case kSENSORSTorsoJointTemps_v:
            {
#ifdef SENSORSTORSOJOINTTEMPS_DEFINED
                class SENSORSTorsoJointTemps_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSTORSOJOINTTEMPS_DEFINED
            }
            case kSENSORSLegJointSensors_v:
            {
#ifdef SENSORSLEGJOINTSENSORS_DEFINED
                class SENSORSLegJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLEGJOINTSENSORS_DEFINED
            }
            case kSENSORSTorsoJointSensors_v:
            {
#ifdef SENSORSTORSOJOINTSENSORS_DEFINED
                class SENSORSTorsoJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSTORSOJOINTSENSORS_DEFINED
            }
            case kSENSORSSonarSensors_v:
            {
#ifdef SENSORSSONARSENSORS_DEFINED
                class SENSORSSonarSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSSONARSENSORS_DEFINED
            }
            case kFSM_Control_v:
            {
#ifdef FSMCONTROLSTATUS_DEFINED
                class FSM_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMCONTROLSTATUS_DEFINED
            }
            case kFSM_Status_v:
            {
#ifdef FSMCONTROLSTATUS_DEFINED
                class FSM_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMCONTROLSTATUS_DEFINED
            }
            case kFSM_Names_v:
            {
#ifdef FSMNAMES_DEFINED
                class FSM_Names_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMNAMES_DEFINED
            }
            case kSoloTypeExample_v:
            {

                class SoloTypeExample_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kFilteredGoalSighting_v:
            {
#ifdef FILTEREDARRAYONEDIMOBJECTS_DEFINED
                class FilteredGoalSighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FILTEREDARRAYONEDIMOBJECTS_DEFINED
            }
            case kNAO_State_v:
            {
#ifdef NAO_STATE_DEFINED
                class NAO_State_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAO_STATE_DEFINED
            }
            case kUDPRN_v:
            {
#ifdef GCGAMESTATE_DEFINED
                class UDPRN_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GCGAMESTATE_DEFINED
            }
            case kPlayerNumber_v:
            {

                class PlayerNumber_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kManuallyPenalized_v:
            {

                class ManuallyPenalized_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kVisionControl_v:
            {
#ifdef VISIONCONTROLSTATUS_DEFINED
                class VisionControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONCONTROLSTATUS_DEFINED
            }
            case kVisionStatus_v:
            {
#ifdef VISIONCONTROLSTATUS_DEFINED
                class VisionStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONCONTROLSTATUS_DEFINED
            }
            case kFFTStatus_v:
            {
#ifdef FFTSTATUS_DEFINED
                class FFTStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FFTSTATUS_DEFINED
            }
            case kFSOsighting_v:
            {
#ifdef FILTEREDARRAYONEDIMSONAR_DEFINED
                class FSOsighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FILTEREDARRAYONEDIMSONAR_DEFINED
            }
            case kTopParticles_v:
            {
#ifdef TOPPARTICLES_DEFINED
                class TopParticles_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TOPPARTICLES_DEFINED
            }
            case kFilteredBallSighting_v:
            {
#ifdef FILTEREDARRAYBALLSIGHTINGS_DEFINED
                class FilteredBallSighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FILTEREDARRAYBALLSIGHTINGS_DEFINED
            }
            case kPF_ControlStatus_Modes_v:
            {

                class PF_ControlStatus_Modes_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kWEBOTS_NXT_bridge_v:
            {
#ifdef WEBOTS_NXT_BRIDGE_DEFINED
                class WEBOTS_NXT_bridge_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_BRIDGE_DEFINED
            }
            case kWEBOTS_NXT_encoders_v:
            {
#ifdef WEBOTS_NXT_ENCODERS_DEFINED
                class WEBOTS_NXT_encoders_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_ENCODERS_DEFINED
            }
            case kWEBOTS_NXT_camera_v:
            {
#ifdef WEBOTS_NXT_CAMERA_DEFINED
                class WEBOTS_NXT_camera_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_CAMERA_DEFINED
            }
            case kWEBOTS_NXT_walk_isRunning_v:
            {
#ifdef WEBOTS_NXT_WALK_ISRUNNING_DEFINED
                class WEBOTS_NXT_walk_isRunning_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_WALK_ISRUNNING_DEFINED
            }
            case kWEBOTS_NXT_deadReakoning_walk_v:
            {
#ifdef WEBOTS_NXT_DEADREAKONING_WALK_DEFINED
                class WEBOTS_NXT_deadReakoning_walk_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_DEADREAKONING_WALK_DEFINED
            }
            case kWEBOTS_NXT_colorLine_walk_v:
            {
#ifdef WEBOTS_NXT_COLORLINE_WALK_DEFINED
                class WEBOTS_NXT_colorLine_walk_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_COLORLINE_WALK_DEFINED
            }
            case kWEBOTS_NXT_gridMotions_v:
            {
#ifdef WEBOTS_NXT_GRIDMOTIONS_DEFINED
                class WEBOTS_NXT_gridMotions_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_GRIDMOTIONS_DEFINED
            }
            case kVisionBall_v:
            {
#ifdef VISIONBALL_DEFINED
                class VisionBall_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONBALL_DEFINED
            }
            case kVisionGoals_v:
            {
#ifdef VISIONGOALS_DEFINED
                class VisionGoals_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONGOALS_DEFINED
            }
            case kWalkData_v:
            {
#ifdef WALKDATA_DEFINED
                class WalkData_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WALKDATA_DEFINED
            }
            case kTeleoperationControlStatus_v:
            {
#ifdef TELEOPERATIONCONTROLSTATUS_DEFINED
                class TeleoperationControlStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TELEOPERATIONCONTROLSTATUS_DEFINED
            }
            case kTeleoperationConnection_v:
            {

                class TeleoperationConnection_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kUDPWBNumber_v:
            {

                class UDPWBNumber_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kWEBOTS_NXT_bumper_v:
            {
#ifdef WEBOTS_NXT_BUMPER_DEFINED
                class WEBOTS_NXT_bumper_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_BUMPER_DEFINED
            }
            case kWEBOTS_NXT_vector_bridge_v:
            {
#ifdef WEBOTS_NXT_VECTOR_BRIDGE_DEFINED
                class WEBOTS_NXT_vector_bridge_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_VECTOR_BRIDGE_DEFINED
            }
            case kTopVisionLines_v:
            {
#ifdef VISIONLINES_DEFINED
                class TopVisionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONLINES_DEFINED
            }
            case kBottomVisionLines_v:
            {
#ifdef VISIONLINES_DEFINED
                class BottomVisionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONLINES_DEFINED
            }
            case kDifferentialRobotStatus_v:
            {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_DEFINED
                class DifferentialRobotStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DIFFERENTIALROBOTCONTROLSTATUS_DEFINED
            }
            case kDifferentialRobotControl_v:
            {
#ifdef DIFFERENTIALROBOTCONTROLSTATUS_DEFINED
                class DifferentialRobotControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DIFFERENTIALROBOTCONTROLSTATUS_DEFINED
            }
            case kXEyesPos_v:
            {
#ifdef POINT2D_DEFINED
                class XEyesPos_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //POINT2D_DEFINED
            }
            case kVisionFace_v:
            {

                class VisionFace_t m(wbd);
                return msg ? intvectostring(m.get_from(msg)) : intvectostring(m.get());

            }
            case kDraw_v:
            {

                class Draw_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kFSM_States_v:
            {
#ifdef FSMSTATE_DEFINED
                class FSM_States_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMSTATE_DEFINED
            }
            case kGiraff_Interface_Status_v:
            {
#ifdef GIRAFF_MAINSERIALINTERFACE_DEFINED
                class Giraff_Interface_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GIRAFF_MAINSERIALINTERFACE_DEFINED
            }
            case kGiraff_Interface_Command_v:
            {
#ifdef GIRAFF_MAINSERIALINTERFACE_DEFINED
                class Giraff_Interface_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GIRAFF_MAINSERIALINTERFACE_DEFINED
            }
            case kNXT_Status_v:
            {
#ifdef NXT_INTERFACE_DEFINED
                class NXT_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_INTERFACE_DEFINED
            }
            case kNXT_Command_v:
            {
#ifdef NXT_INTERFACE_DEFINED
                class NXT_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_INTERFACE_DEFINED
            }
            case kAPM_Status_v:
            {
#ifdef APM_INTERFACE_DEFINED
                class APM_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //APM_INTERFACE_DEFINED
            }
            case kAPM_Command_v:
            {
#ifdef APM_INTERFACE_DEFINED
                class APM_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //APM_INTERFACE_DEFINED
            }
            case kREMOVED3_v:
            {

                class REMOVED3_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kREMOVED4_v:
            {

                class REMOVED4_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kCBall_v:
            {

                class CBall_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kOculusPrime_Command_v:
            {
#ifdef OCULUSPRIMEINTERFACE_DEFINED
                class OculusPrime_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //OCULUSPRIMEINTERFACE_DEFINED
            }
            case kInput3D_v:
            {
#ifdef INPUT3D_DEFINED
                class Input3D_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //INPUT3D_DEFINED
            }
            case kOculus_Prime_Command_v:
            {
#ifdef OCULUS_PRIMESERIALINTERFACE_DEFINED
                class Oculus_Prime_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //OCULUS_PRIMESERIALINTERFACE_DEFINED
            }
            case kIOPins_v:
            {
#ifdef IOPINS_DEFINED
                class IOPins_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //IOPINS_DEFINED
            }
            case kNXT_Two_Touch_Status_v:
            {
#ifdef NXT_TWO_TOUCH_STATUS_DEFINED
                class NXT_Two_Touch_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_TWO_TOUCH_STATUS_DEFINED
            }
            case kNXT_Sound_Control_v:
            {
#ifdef NXT_SOUND_CONTROL_DEFINED
                class NXT_Sound_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_SOUND_CONTROL_DEFINED
            }
            case kNXT_Lights_Control_v:
            {
#ifdef NXT_LIGHTS_CONTROL_DEFINED
                class NXT_Lights_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_LIGHTS_CONTROL_DEFINED
            }
            case kClocks_v:
            {
#ifdef CLOCKS_DEFINED
                class Clocks_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //CLOCKS_DEFINED
            }
            case kChannels_v:
            {
#ifdef CHANNELS_DEFINED
                class Channels_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //CHANNELS_DEFINED
            }
            case kSwitchSubsumption_v:
            {
#ifdef SWITCHSUBSUMPTION_DEFINED
                class SwitchSubsumption_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SWITCHSUBSUMPTION_DEFINED
            }
            case kTotoDoingMotion_v:
            {
#ifdef TOTODOINGMOTION_DEFINED
                class TotoDoingMotion_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TOTODOINGMOTION_DEFINED
            }
            case kCount_v:
            {
#ifdef COUNT_DEFINED
                class Count_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //COUNT_DEFINED
            }
            case kGreenEWon_v:
            {

                class GreenEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kWarnEW_v:
            {

                class WarnEW_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kTimeGTthirty_v:
            {

                class TimeGTthirty_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kAmberEWon_v:
            {

                class AmberEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kTurnRedEW_v:
            {

                class TurnRedEW_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kTimeGTfive_v:
            {

                class TimeGTfive_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kRedEWon_v:
            {

                class RedEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kGreenNSon_v:
            {

                class GreenNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kWarnNS_v:
            {

                class WarnNS_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kAmberNSon_v:
            {

                class AmberNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kTurnRedNS_v:
            {

                class TurnRedNS_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kRedNSon_v:
            {

                class RedNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kTimerReset_v:
            {

                class TimerReset_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kSLOT_UNUSED_v:
            {

                class SLOT_UNUSED_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kCarSensorPressed_v:
            {

                class CarSensorPressed_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kSwitchSubsumptionTrafficLights_v:
            {
#ifdef SWITCHSUBSUMPTIONTRAFFICLIGHTS_DEFINED
                class SwitchSubsumptionTrafficLights_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SWITCHSUBSUMPTIONTRAFFICLIGHTS_DEFINED
            }
            case kBall_Found_v:
            {

                class Ball_Found_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kBall_Calibration_File_v:
            {

                class Ball_Calibration_File_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kBall_Calibration_Num_v:
            {

                class Ball_Calibration_Num_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kBall_Color_Num_v:
            {

                class Ball_Color_Num_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kHAL_LArmTarget_Ctrl_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_LArmTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case kHAL_LArmTarget_Stat_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_LArmTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case kHAL_LArmTarget_Tolr_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_LArmTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case kHAL_RArmTarget_Ctrl_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_RArmTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case kHAL_RArmTarget_Stat_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_RArmTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case kHAL_RArmTarget_Tolr_v:
            {
#ifdef HALARMTARGET_DEFINED
                class HAL_RArmTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALARMTARGET_DEFINED
            }
            case kVisionFieldFeatures_v:
            {
#ifdef VISIONFIELDFEATURES_DEFINED
                class VisionFieldFeatures_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONFIELDFEATURES_DEFINED
            }
            case kWhistleBlown_v:
            {

                class WhistleBlown_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kVolumeControl_v:
            {

                class VolumeControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kVisionRobots_v:
            {
#ifdef VISIONROBOTS_DEFINED
                class VisionRobots_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONROBOTS_DEFINED
            }
            case kVisionDetectionHorizons_v:
            {
#ifdef VISIONDETECTIONHORIZONS_DEFINED
                class VisionDetectionHorizons_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONHORIZONS_DEFINED
            }
            case kNaoWalkCommand_v:
            {
#ifdef NAOWALKCOMMAND_DEFINED
                class NaoWalkCommand_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOWALKCOMMAND_DEFINED
            }
            case kNaoWalkStatus_v:
            {
#ifdef NAOWALKSTATUS_DEFINED
                class NaoWalkStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOWALKSTATUS_DEFINED
            }
            case kHAL_LLegTarget_Ctrl_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_LLegTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case kHAL_LLegTarget_Stat_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_LLegTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case kHAL_LLegTarget_Tolr_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_LLegTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case kHAL_RLegTarget_Ctrl_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_RLegTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case kHAL_RLegTarget_Stat_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_RLegTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case kHAL_RLegTarget_Tolr_v:
            {
#ifdef HALLEGTARGET_DEFINED
                class HAL_RLegTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HALLEGTARGET_DEFINED
            }
            case kVisionDetectionGoals_v:
            {
#ifdef VISIONDETECTIONGOALS_DEFINED
                class VisionDetectionGoals_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONGOALS_DEFINED
            }
            case kTeleoperationControl_v:
            {
#ifdef TELEOPERATIONCONTROL_DEFINED
                class TeleoperationControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TELEOPERATIONCONTROL_DEFINED
            }
            case kTeleoperationStatus_v:
            {
#ifdef TELEOPERATIONSTATUS_DEFINED
                class TeleoperationStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TELEOPERATIONSTATUS_DEFINED
            }
            case kVisionDetectionBalls_v:
            {
#ifdef VISIONDETECTIONBALLS_DEFINED
                class VisionDetectionBalls_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONBALLS_DEFINED
            }
            case kTeleoperationControlVR_v:
            {
#ifdef TELEOPERATIONCONTROLVR_DEFINED
                class TeleoperationControlVR_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TELEOPERATIONCONTROLVR_DEFINED
            }
            case kParticleOutputMap_v:
            {

                class ParticleOutputMap_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kParticleOutputMapControl_v:
            {

                class ParticleOutputMapControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kFFTControl_v:
            {

                class FFTControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kMachineFilteredNaoVision_v:
            {
#ifdef MACHINEFILTEREDVISION_DEFINED
                class MachineFilteredNaoVision_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MACHINEFILTEREDVISION_DEFINED
            }
            case kMicrowaveStatus_v:
            {
#ifdef MICROWAVESTATUS_DEFINED
                class MicrowaveStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MICROWAVESTATUS_DEFINED
            }
            case kButtons_v:
            {
#ifdef BUTTONS_DEFINED
                class Buttons_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //BUTTONS_DEFINED
            }
            case kMachineFilteredLocalisationVision_v:
            {
#ifdef MACHINEFILTEREDLOCALISATIONVISION_DEFINED
                class MachineFilteredLocalisationVision_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MACHINEFILTEREDLOCALISATIONVISION_DEFINED
            }
            case kSensorsJointCurrent_v:
            {
#ifdef NAOJOINTLISTFLOAT_DEFINED
                class SensorsJointCurrent_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOJOINTLISTFLOAT_DEFINED
            }
            case kDataLogger_v:
            {
#ifdef DATALOGGER_DEFINED
                class DataLogger_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DATALOGGER_DEFINED
            }
            case kMachineFilteredLines_v:
            {
#ifdef MACHINEFILTEREDLINES_DEFINED
                class MachineFilteredLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MACHINEFILTEREDLINES_DEFINED
            }
            case kBallLocation_v:
            {
#ifdef LOCATION_DEFINED
                class BallLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //LOCATION_DEFINED
            }
            case kLeftGoalPostLocation_v:
            {
#ifdef LOCATION_DEFINED
                class LeftGoalPostLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //LOCATION_DEFINED
            }
            case kRightGoalPostLocation_v:
            {
#ifdef LOCATION_DEFINED
                class RightGoalPostLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //LOCATION_DEFINED
            }
            case kGoalLocation_v:
            {
#ifdef LOCATION_DEFINED
                class GoalLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //LOCATION_DEFINED
            }
            case kNaoSonarProtectedWalkCommand_v:
            {
#ifdef NAOSONARPROTECTEDWALKCOMMAND_DEFINED
                class NaoSonarProtectedWalkCommand_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOSONARPROTECTEDWALKCOMMAND_DEFINED
            }
            case kNaoObstacleDirection_v:
            {
#ifdef NAOOBSTACLEDIRECTION_DEFINED
                class NaoObstacleDirection_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAOOBSTACLEDIRECTION_DEFINED
            }
            case kDominantFrequencies_v:
            {
#ifdef DOMINANTFREQUENCIES_DEFINED
                class DominantFrequencies_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DOMINANTFREQUENCIES_DEFINED
            }
            case kMissionPriorityForObstacles_v:
            {
#ifdef MISSIONPRIORITYFOROBSTACLES_DEFINED
                class MissionPriorityForObstacles_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MISSIONPRIORITYFOROBSTACLES_DEFINED
            }
            case kWavLoad_v:
            {

                class WavLoad_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kWavPlay_v:
            {

                class WavPlay_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kReproduceWavNotSilent_v:
            {

                class ReproduceWavNotSilent_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kFrequencyControl_v:
            {
#ifdef FREQUENCYLIMITS_DEFINED
                class FrequencyControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FREQUENCYLIMITS_DEFINED
            }
            case kFrequencyStatus_v:
            {
#ifdef FREQUENCYLIMITS_DEFINED
                class FrequencyStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FREQUENCYLIMITS_DEFINED
            }
            case kHeadJointSensors_v:
            {
#ifdef HEADJOINTSENSORS_DEFINED
                class HeadJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HEADJOINTSENSORS_DEFINED
            }
            case kAdjustPositionConfidence_v:
            {
#ifdef ADJUSTPOSITIONCONFIDENCE_DEFINED
                class AdjustPositionConfidence_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //ADJUSTPOSITIONCONFIDENCE_DEFINED
            }
            case kGuVrTeleopVulkanControl_v:
            {
#ifdef GUVRTELEOPVULKANCONTROL_DEFINED
                class GuVrTeleopVulkanControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GUVRTELEOPVULKANCONTROL_DEFINED
            }
            case kTemperatureSensors_v:
            {
#ifdef TEMPERATURESENSORS_DEFINED
                class TemperatureSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TEMPERATURESENSORS_DEFINED
            }
            case kOverheating_v:
            {
#ifdef OVERHEATING_DEFINED
                class Overheating_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //OVERHEATING_DEFINED
            }
            case kbuttonPushed_v:
            {

                class buttonPushed_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kdoorOpen_v:
            {

                class doorOpen_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case ktimeLeft_v:
            {

                class timeLeft_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kmotor_v:
            {

                class motor_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case ksound_v:
            {

                class sound_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case klight_v:
            {

                class light_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino2Pin_v:
            {

                class Arduino2Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino2PinValue_v:
            {

                class Arduino2PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino3Pin_v:
            {

                class Arduino3Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino3PinValue_v:
            {

                class Arduino3PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino4Pin_v:
            {

                class Arduino4Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino4PinValue_v:
            {

                class Arduino4PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino5Pin_v:
            {

                class Arduino5Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino5PinValue_v:
            {

                class Arduino5PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino6Pin_v:
            {

                class Arduino6Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino6PinValue_v:
            {

                class Arduino6PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino7Pin_v:
            {

                class Arduino7Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino7PinValue_v:
            {

                class Arduino7PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino8Pin_v:
            {

                class Arduino8Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino8PinValue_v:
            {

                class Arduino8PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino9Pin_v:
            {

                class Arduino9Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kArduino9PinValue_v:
            {

                class Arduino9PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kBallPosition_v:
            {
#ifdef BALLPOSITION_DEFINED
                class BallPosition_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //BALLPOSITION_DEFINED
            }
            case kMemoryImageControl_v:
            {
#ifdef MEMORYIMAGECONTROLSTATUS_DEFINED
                class MemoryImageControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MEMORYIMAGECONTROLSTATUS_DEFINED
            }
            case kMemoryImageStatus_v:
            {
#ifdef MEMORYIMAGECONTROLSTATUS_DEFINED
                class MemoryImageStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MEMORYIMAGECONTROLSTATUS_DEFINED
            }
            case kLHandGripper_v:
            {

                class LHandGripper_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kRHandGripper_v:
            {

                class RHandGripper_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kMyPosition_v:
            {
#ifdef MYPOSITION_DEFINED
                class MyPosition_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MYPOSITION_DEFINED
            }
            case kVisionDetectionLines_v:
            {
#ifdef VISIONDETECTIONLINES_DEFINED
                class VisionDetectionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VISIONDETECTIONLINES_DEFINED
            }
            case kVisionDetectionFeatures_v:
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
