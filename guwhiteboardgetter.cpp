/**
 *  /file guwhiteboardgetter.cpp
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2018 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

/** Auto-generated, don't modify! */

#include <string>
#include <vector>
#include <cstdlib>
#include <gu_util.h>

#define WHITEBOARD_POSTER_STRING_CONVERSION

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
        return gu_strdup(getmsg(WBTypes(message_index), msg).c_str());
    }

    char *whiteboard_getmsg_from(gu_simple_whiteboard_descriptor *wbd, int message_index)
    {
        return gu_strdup(getmsg(WBTypes(message_index), NULLPTR, wbd).c_str());
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

    string getmsg(WBTypes message_index, gu_simple_message *msg, gu_simple_whiteboard_descriptor *wbd)
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
#ifdef GCGameState_DEFINED
                class GCGameState_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GCGameState_DEFINED
            }
            case kREMOVED1_v:
            {

                class REMOVED1_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kREMOVED2_v:
            {

                class REMOVED2_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kMOTION_Commands_v:
            {
#ifdef MOTION_Commands_DEFINED
                class MOTION_Commands_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MOTION_Commands_DEFINED
            }
            case kMOTION_Status_v:
            {
#ifdef MOTION_Status_DEFINED
                class MOTION_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //MOTION_Status_DEFINED
            }
            case kHAL_HeadTarget_v:
            {
#ifdef HAL_HeadTarget_DEFINED
                class HAL_HeadTarget_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_HeadTarget_DEFINED
            }
            case kSENSORSFootSensors_v:
            {
#ifdef SENSORSFootSensors_DEFINED
                class SENSORSFootSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSFootSensors_DEFINED
            }
            case kSENSORSBodySensors_v:
            {
#ifdef SENSORSBodySensors_DEFINED
                class SENSORSBodySensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSBodySensors_DEFINED
            }
            case kSENSORSLedsSensors_v:
            {
#ifdef SENSORSLedsSensors_DEFINED
                class SENSORSLedsSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLedsSensors_DEFINED
            }
            case kSENSORSLegJointTemps_v:
            {
#ifdef SENSORSLegJointTemps_DEFINED
                class SENSORSLegJointTemps_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLegJointTemps_DEFINED
            }
            case kSENSORSTorsoJointTemps_v:
            {
#ifdef SENSORSTorsoJointTemps_DEFINED
                class SENSORSTorsoJointTemps_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSTorsoJointTemps_DEFINED
            }
            case kSENSORSLegJointSensors_v:
            {
#ifdef SENSORSLegJointSensors_DEFINED
                class SENSORSLegJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSLegJointSensors_DEFINED
            }
            case kSENSORSTorsoJointSensors_v:
            {
#ifdef SENSORSTorsoJointSensors_DEFINED
                class SENSORSTorsoJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSTorsoJointSensors_DEFINED
            }
            case kSENSORSSonarSensors_v:
            {
#ifdef SENSORSSonarSensors_DEFINED
                class SENSORSSonarSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SENSORSSonarSensors_DEFINED
            }
            case kFSM_Control_v:
            {
#ifdef FSMControlStatus_DEFINED
                class FSM_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMControlStatus_DEFINED
            }
            case kFSM_Status_v:
            {
#ifdef FSMControlStatus_DEFINED
                class FSM_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMControlStatus_DEFINED
            }
            case kFSM_Names_v:
            {
#ifdef FSMNames_DEFINED
                class FSM_Names_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMNames_DEFINED
            }
            case kSoloTypeExample_v:
            {

                class SoloTypeExample_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kFilteredGoalSighting_v:
            {
#ifdef FilteredArrayOneDimObjects_DEFINED
                class FilteredGoalSighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FilteredArrayOneDimObjects_DEFINED
            }
            case kNAO_State_v:
            {
#ifdef NAO_State_DEFINED
                class NAO_State_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NAO_State_DEFINED
            }
            case kUDPRN_v:
            {
#ifdef GCGameState_DEFINED
                class UDPRN_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //GCGameState_DEFINED
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
            case kVision_Control_v:
            {
#ifdef VisionControlStatus_DEFINED
                class Vision_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionControlStatus_DEFINED
            }
            case kVision_Status_v:
            {
#ifdef VisionControlStatus_DEFINED
                class Vision_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionControlStatus_DEFINED
            }
            case kFFTStatus_v:
            {
#ifdef FFTStatus_DEFINED
                class FFTStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FFTStatus_DEFINED
            }
            case kFSOsighting_v:
            {
#ifdef FilteredArrayOneDimSonar_DEFINED
                class FSOsighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FilteredArrayOneDimSonar_DEFINED
            }
            case kTopParticles_v:
            {
#ifdef TopParticles_DEFINED
                class TopParticles_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TopParticles_DEFINED
            }
            case kFilteredBallSighting_v:
            {
#ifdef FilteredArrayBallSightings_DEFINED
                class FilteredBallSighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FilteredArrayBallSightings_DEFINED
            }
            case kPF_ControlStatus_Modes_v:
            {

                class PF_ControlStatus_Modes_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kWEBOTS_NXT_bridge_v:
            {
#ifdef WEBOTS_NXT_bridge_DEFINED
                class WEBOTS_NXT_bridge_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_bridge_DEFINED
            }
            case kWEBOTS_NXT_encoders_v:
            {
#ifdef WEBOTS_NXT_encoders_DEFINED
                class WEBOTS_NXT_encoders_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_encoders_DEFINED
            }
            case kWEBOTS_NXT_camera_v:
            {
#ifdef WEBOTS_NXT_camera_DEFINED
                class WEBOTS_NXT_camera_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_camera_DEFINED
            }
            case kWEBOTS_NXT_walk_isRunning_v:
            {
#ifdef WEBOTS_NXT_walk_isRunning_DEFINED
                class WEBOTS_NXT_walk_isRunning_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_walk_isRunning_DEFINED
            }
            case kWEBOTS_NXT_deadReakoning_walk_v:
            {
#ifdef WEBOTS_NXT_deadReakoning_walk_DEFINED
                class WEBOTS_NXT_deadReakoning_walk_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_deadReakoning_walk_DEFINED
            }
            case kWEBOTS_NXT_colorLine_walk_v:
            {
#ifdef WEBOTS_NXT_colorLine_walk_DEFINED
                class WEBOTS_NXT_colorLine_walk_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_colorLine_walk_DEFINED
            }
            case kWEBOTS_NXT_gridMotions_v:
            {
#ifdef WEBOTS_NXT_gridMotions_DEFINED
                class WEBOTS_NXT_gridMotions_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_gridMotions_DEFINED
            }
            case kVisionBall_v:
            {
#ifdef VisionBall_DEFINED
                class VisionBall_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionBall_DEFINED
            }
            case kVisionGoals_v:
            {
#ifdef VisionGoals_DEFINED
                class VisionGoals_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionGoals_DEFINED
            }
            case kWalkData_v:
            {
#ifdef WalkData_DEFINED
                class WalkData_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WalkData_DEFINED
            }
            case kTeleoperationControlStatus_v:
            {
#ifdef TeleoperationControlStatus_DEFINED
                class TeleoperationControlStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TeleoperationControlStatus_DEFINED
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
#ifdef WEBOTS_NXT_bumper_DEFINED
                class WEBOTS_NXT_bumper_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_bumper_DEFINED
            }
            case kWEBOTS_NXT_vector_bridge_v:
            {
#ifdef WEBOTS_NXT_vector_bridge_DEFINED
                class WEBOTS_NXT_vector_bridge_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //WEBOTS_NXT_vector_bridge_DEFINED
            }
            case kVisionLines_v:
            {
#ifdef VisionLines_DEFINED
                class VisionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionLines_DEFINED
            }
            case kDifferentialRobotStatus_v:
            {
#ifdef DifferentialRobotControlStatus_DEFINED
                class DifferentialRobotStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DifferentialRobotControlStatus_DEFINED
            }
            case kDifferentialRobotControl_v:
            {
#ifdef DifferentialRobotControlStatus_DEFINED
                class DifferentialRobotControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //DifferentialRobotControlStatus_DEFINED
            }
            case kXEyesPos_v:
            {
#ifdef Point2D_DEFINED
                class XEyesPos_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //Point2D_DEFINED
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
#ifdef FSMState_DEFINED
                class FSM_States_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FSMState_DEFINED
            }
            case kGiraff_Interface_Status_v:
            {
#ifdef Giraff_MainSerialInterface_DEFINED
                class Giraff_Interface_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //Giraff_MainSerialInterface_DEFINED
            }
            case kGiraff_Interface_Command_v:
            {
#ifdef Giraff_MainSerialInterface_DEFINED
                class Giraff_Interface_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //Giraff_MainSerialInterface_DEFINED
            }
            case kNXT_Status_v:
            {
#ifdef NXT_Interface_DEFINED
                class NXT_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_Interface_DEFINED
            }
            case kNXT_Command_v:
            {
#ifdef NXT_Interface_DEFINED
                class NXT_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_Interface_DEFINED
            }
            case kAPM_Status_v:
            {
#ifdef APM_Interface_DEFINED
                class APM_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //APM_Interface_DEFINED
            }
            case kAPM_Command_v:
            {
#ifdef APM_Interface_DEFINED
                class APM_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //APM_Interface_DEFINED
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
#ifdef OculusPrimeInterface_DEFINED
                class OculusPrime_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //OculusPrimeInterface_DEFINED
            }
            case kInput3D_v:
            {
#ifdef Input3D_DEFINED
                class Input3D_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //Input3D_DEFINED
            }
            case kOculus_Prime_Command_v:
            {
#ifdef Oculus_PrimeSerialInterface_DEFINED
                class Oculus_Prime_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //Oculus_PrimeSerialInterface_DEFINED
            }
            case kIOPins_v:
            {
#ifdef IOPins_DEFINED
                class IOPins_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //IOPins_DEFINED
            }
            case kNXT_Two_Touch_Status_v:
            {
#ifdef NXT_Two_Touch_Status_DEFINED
                class NXT_Two_Touch_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_Two_Touch_Status_DEFINED
            }
            case kNXT_Sound_Control_v:
            {
#ifdef NXT_Sound_Control_DEFINED
                class NXT_Sound_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_Sound_Control_DEFINED
            }
            case kNXT_Lights_Control_v:
            {
#ifdef NXT_Lights_Control_DEFINED
                class NXT_Lights_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NXT_Lights_Control_DEFINED
            }
            case kClocks_v:
            {
#ifdef Clocks_DEFINED
                class Clocks_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //Clocks_DEFINED
            }
            case kChannels_v:
            {
#ifdef Channels_DEFINED
                class Channels_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //Channels_DEFINED
            }
            case kSwitchSubsumption_v:
            {
#ifdef SwitchSubsumption_DEFINED
                class SwitchSubsumption_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SwitchSubsumption_DEFINED
            }
            case kTotoDoingMotion_v:
            {
#ifdef TotoDoingMotion_DEFINED
                class TotoDoingMotion_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TotoDoingMotion_DEFINED
            }
            case kCount_v:
            {
#ifdef wb_count_DEFINED
                class Count_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //wb_count_DEFINED
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
#ifdef SwitchSubsumptionTrafficLights_DEFINED
                class SwitchSubsumptionTrafficLights_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //SwitchSubsumptionTrafficLights_DEFINED
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
#ifdef HAL_ArmTarget_DEFINED
                class HAL_LArmTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_ArmTarget_DEFINED
            }
            case kHAL_LArmTarget_Stat_v:
            {
#ifdef HAL_ArmTarget_DEFINED
                class HAL_LArmTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_ArmTarget_DEFINED
            }
            case kHAL_LArmTarget_Tolr_v:
            {
#ifdef HAL_ArmTarget_DEFINED
                class HAL_LArmTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_ArmTarget_DEFINED
            }
            case kHAL_RArmTarget_Ctrl_v:
            {
#ifdef HAL_ArmTarget_DEFINED
                class HAL_RArmTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_ArmTarget_DEFINED
            }
            case kHAL_RArmTarget_Stat_v:
            {
#ifdef HAL_ArmTarget_DEFINED
                class HAL_RArmTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_ArmTarget_DEFINED
            }
            case kHAL_RArmTarget_Tolr_v:
            {
#ifdef HAL_ArmTarget_DEFINED
                class HAL_RArmTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_ArmTarget_DEFINED
            }
            case kVisionFieldFeatures_v:
            {
#ifdef VisionFieldFeatures_DEFINED
                class VisionFieldFeatures_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionFieldFeatures_DEFINED
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
#ifdef VisionRobots_DEFINED
                class VisionRobots_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionRobots_DEFINED
            }
            case kFieldHorizons_v:
            {
#ifdef FieldHorizons_DEFINED
                class FieldHorizons_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FieldHorizons_DEFINED
            }
            case kNaoWalkCommand_v:
            {
#ifdef NaoWalkCommand_DEFINED
                class NaoWalkCommand_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NaoWalkCommand_DEFINED
            }
            case kNaoWalkStatus_v:
            {
#ifdef NaoWalkStatus_DEFINED
                class NaoWalkStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //NaoWalkStatus_DEFINED
            }
            case kHAL_LLegTarget_Ctrl_v:
            {
#ifdef HAL_LegTarget_DEFINED
                class HAL_LLegTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_LegTarget_DEFINED
            }
            case kHAL_LLegTarget_Stat_v:
            {
#ifdef HAL_LegTarget_DEFINED
                class HAL_LLegTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_LegTarget_DEFINED
            }
            case kHAL_LLegTarget_Tolr_v:
            {
#ifdef HAL_LegTarget_DEFINED
                class HAL_LLegTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_LegTarget_DEFINED
            }
            case kHAL_RLegTarget_Ctrl_v:
            {
#ifdef HAL_LegTarget_DEFINED
                class HAL_RLegTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_LegTarget_DEFINED
            }
            case kHAL_RLegTarget_Stat_v:
            {
#ifdef HAL_LegTarget_DEFINED
                class HAL_RLegTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_LegTarget_DEFINED
            }
            case kHAL_RLegTarget_Tolr_v:
            {
#ifdef HAL_LegTarget_DEFINED
                class HAL_RLegTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //HAL_LegTarget_DEFINED
            }
            case kFieldGoals_v:
            {
#ifdef FieldGoals_DEFINED
                class FieldGoals_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FieldGoals_DEFINED
            }
            case kTeleoperationControl_v:
            {
#ifdef TeleoperationControl_DEFINED
                class TeleoperationControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TeleoperationControl_DEFINED
            }
            case kTeleoperationStatus_v:
            {
#ifdef TeleoperationStatus_DEFINED
                class TeleoperationStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //TeleoperationStatus_DEFINED
            }
            case kFieldBalls_v:
            {
#ifdef FieldBalls_DEFINED
                class FieldBalls_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //FieldBalls_DEFINED
            }
            case kVisionControl_v:
            {
#ifdef VisionStatusControl_DEFINED
                class VisionControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionStatusControl_DEFINED
            }
            case kVisionStatus_v:
            {
#ifdef VisionStatusControl_DEFINED
                class VisionStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //VisionStatusControl_DEFINED
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
