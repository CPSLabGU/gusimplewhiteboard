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
namespace guWhiteboard {

    string getmsg(string message_type, gu_simple_message *msg, gu_simple_whiteboard_descriptor *wbd)
    {
        return getmsg(types_map[message_type], msg, wbd);
    }

    string getmsg(wb_types message_index, gu_simple_message *msg, gu_simple_whiteboard_descriptor *wbd)
    {
        switch (message_index)
        {

            case kwb_wb_reserved_SubscribeToAllTypes_v:
            {

                class wb_reserved_SubscribeToAllTypes_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Print_v:
            {

                class Print_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kwb_Say_v:
            {

                class Say_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kwb_Speech_v:
            {

                class Speech_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kwb_QSay_v:
            {

                class QSay_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kwb_QSpeech_v:
            {

                class QSpeech_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kwb_SpeechOutput_v:
            {

                class SpeechOutput_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_GCGameState_v:
            {
#ifdef guWhiteboard_GCGameState_DEFINED
                class GCGameState_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_GCGameState_DEFINED
            }
            case kwb_SensorsHandSensors_v:
            {
#ifdef guWhiteboard_SensorsHandSensors_DEFINED
                class SensorsHandSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SensorsHandSensors_DEFINED
            }
            case kwb_SensorsHeadSensors_v:
            {
#ifdef guWhiteboard_SensorsHeadSensors_DEFINED
                class SensorsHeadSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SensorsHeadSensors_DEFINED
            }
            case kwb_MOTION_Commands_v:
            {
#ifdef guWhiteboard_MOTIONCommands_DEFINED
                class MOTION_Commands_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MOTIONCommands_DEFINED
            }
            case kwb_MOTION_Status_v:
            {
#ifdef guWhiteboard_MOTIONStatus_DEFINED
                class MOTION_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MOTIONStatus_DEFINED
            }
            case kwb_HAL_HeadTarget_v:
            {
#ifdef guWhiteboard_HALHeadTarget_DEFINED
                class HAL_HeadTarget_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HALHeadTarget_DEFINED
            }
            case kwb_SensorsFootSensors_v:
            {
#ifdef guWhiteboard_SensorsFootSensors_DEFINED
                class SensorsFootSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SensorsFootSensors_DEFINED
            }
            case kwb_SensorsBodySensors_v:
            {
#ifdef guWhiteboard_SensorsBodySensors_DEFINED
                class SensorsBodySensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SensorsBodySensors_DEFINED
            }
            case kwb_SENSORSLedsSensors_v:
            {
#ifdef guWhiteboard_SENSORSLedsSensors_DEFINED
                class SENSORSLedsSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SENSORSLedsSensors_DEFINED
            }
            case kwb_SENSORSLegJointTemps_v:
            {
#ifdef guWhiteboard_SENSORSLegJointTemps_DEFINED
                class SENSORSLegJointTemps_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SENSORSLegJointTemps_DEFINED
            }
            case kwb_SENSORSTorsoJointTemps_v:
            {
#ifdef guWhiteboard_SENSORSTorsoJointTemps_DEFINED
                class SENSORSTorsoJointTemps_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SENSORSTorsoJointTemps_DEFINED
            }
            case kwb_SENSORSLegJointSensors_v:
            {
#ifdef guWhiteboard_SENSORSLegJointSensors_DEFINED
                class SENSORSLegJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SENSORSLegJointSensors_DEFINED
            }
            case kwb_SENSORSTorsoJointSensors_v:
            {
#ifdef guWhiteboard_SENSORSTorsoJointSensors_DEFINED
                class SENSORSTorsoJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SENSORSTorsoJointSensors_DEFINED
            }
            case kwb_SENSORSSonarSensors_v:
            {
#ifdef guWhiteboard_SENSORSSonarSensors_DEFINED
                class SENSORSSonarSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SENSORSSonarSensors_DEFINED
            }
            case kwb_FSM_Control_v:
            {
#ifdef guWhiteboard_FSMControlStatus_DEFINED
                class FSM_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FSMControlStatus_DEFINED
            }
            case kwb_FSM_Status_v:
            {
#ifdef guWhiteboard_FSMControlStatus_DEFINED
                class FSM_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FSMControlStatus_DEFINED
            }
            case kwb_FSM_Names_v:
            {
#ifdef guWhiteboard_FSMNames_DEFINED
                class FSM_Names_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FSMNames_DEFINED
            }
            case kwb_SoloTypeExample_v:
            {

                class SoloTypeExample_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_FilteredGoalSighting_v:
            {
#ifdef guWhiteboard_FilteredArrayOneDimObjects_DEFINED
                class FilteredGoalSighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FilteredArrayOneDimObjects_DEFINED
            }
            case kwb_NAO_State_v:
            {
#ifdef guWhiteboard_NAOState_DEFINED
                class NAO_State_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NAOState_DEFINED
            }
            case kwb_UDPRN_v:
            {
#ifdef guWhiteboard_GCGameState_DEFINED
                class UDPRN_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_GCGameState_DEFINED
            }
            case kwb_PlayerNumber_v:
            {

                class PlayerNumber_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_ManuallyPenalized_v:
            {

                class ManuallyPenalized_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_VisionControl_v:
            {
#ifdef guWhiteboard_VisionControlStatus_DEFINED
                class VisionControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionControlStatus_DEFINED
            }
            case kwb_VisionStatus_v:
            {
#ifdef guWhiteboard_VisionControlStatus_DEFINED
                class VisionStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionControlStatus_DEFINED
            }
            case kwb_FFTStatus_v:
            {
#ifdef guWhiteboard_FFTStatus_DEFINED
                class FFTStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FFTStatus_DEFINED
            }
            case kwb_FSOsighting_v:
            {
#ifdef guWhiteboard_FilteredArrayOneDimSonar_DEFINED
                class FSOsighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FilteredArrayOneDimSonar_DEFINED
            }
            case kwb_TopParticles_v:
            {
#ifdef guWhiteboard_TopParticles_DEFINED
                class TopParticles_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_TopParticles_DEFINED
            }
            case kwb_FilteredBallSighting_v:
            {
#ifdef guWhiteboard_FilteredArrayBallSightings_DEFINED
                class FilteredBallSighting_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FilteredArrayBallSightings_DEFINED
            }
            case kwb_PF_ControlStatus_Modes_v:
            {

                class PF_ControlStatus_Modes_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_WEBOTS_NXT_bridge_v:
            {
#ifdef guWhiteboard_WEBOTSNXTBridge_DEFINED
                class WEBOTS_NXT_bridge_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTBridge_DEFINED
            }
            case kwb_WEBOTS_NXT_encoders_v:
            {
#ifdef guWhiteboard_WEBOTSNXTEncoders_DEFINED
                class WEBOTS_NXT_encoders_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTEncoders_DEFINED
            }
            case kwb_WEBOTS_NXT_camera_v:
            {
#ifdef guWhiteboard_WEBOTSNXTCamera_DEFINED
                class WEBOTS_NXT_camera_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTCamera_DEFINED
            }
            case kwb_WEBOTS_NXT_walk_isRunning_v:
            {
#ifdef guWhiteboard_WEBOTSNXTWalkIsRunning_DEFINED
                class WEBOTS_NXT_walk_isRunning_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTWalkIsRunning_DEFINED
            }
            case kwb_WEBOTS_NXT_deadReakoning_walk_v:
            {
#ifdef guWhiteboard_WEBOTSNXTDeadReakoningWalk_DEFINED
                class WEBOTS_NXT_deadReakoning_walk_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTDeadReakoningWalk_DEFINED
            }
            case kwb_WEBOTS_NXT_colorLine_walk_v:
            {
#ifdef guWhiteboard_WEBOTSNXTColorLineWalk_DEFINED
                class WEBOTS_NXT_colorLine_walk_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTColorLineWalk_DEFINED
            }
            case kwb_WEBOTS_NXT_gridMotions_v:
            {
#ifdef guWhiteboard_WEBOTSNXTGridMotions_DEFINED
                class WEBOTS_NXT_gridMotions_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTGridMotions_DEFINED
            }
            case kwb_VisionBall_v:
            {
#ifdef guWhiteboard_VisionBall_DEFINED
                class VisionBall_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionBall_DEFINED
            }
            case kwb_VisionGoals_v:
            {
#ifdef guWhiteboard_VisionGoals_DEFINED
                class VisionGoals_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionGoals_DEFINED
            }
            case kwb_WalkData_v:
            {
#ifdef guWhiteboard_WalkData_DEFINED
                class WalkData_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WalkData_DEFINED
            }
            case kwb_TeleoperationControlStatus_v:
            {
#ifdef guWhiteboard_TeleoperationControlStatus_DEFINED
                class TeleoperationControlStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_TeleoperationControlStatus_DEFINED
            }
            case kwb_TeleoperationConnection_v:
            {

                class TeleoperationConnection_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_UDPWBNumber_v:
            {

                class UDPWBNumber_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_WEBOTS_NXT_bumper_v:
            {
#ifdef guWhiteboard_WEBOTSNXTBumper_DEFINED
                class WEBOTS_NXT_bumper_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTBumper_DEFINED
            }
            case kwb_WEBOTS_NXT_vector_bridge_v:
            {
#ifdef guWhiteboard_WEBOTSNXTVectorBridge_DEFINED
                class WEBOTS_NXT_vector_bridge_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_WEBOTSNXTVectorBridge_DEFINED
            }
            case kwb_TopVisionLines_v:
            {
#ifdef guWhiteboard_VisionLines_DEFINED
                class TopVisionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionLines_DEFINED
            }
            case kwb_BottomVisionLines_v:
            {
#ifdef guWhiteboard_VisionLines_DEFINED
                class BottomVisionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionLines_DEFINED
            }
            case kwb_DifferentialRobotStatus_v:
            {
#ifdef guWhiteboard_DifferentialRobotControlStatus_DEFINED
                class DifferentialRobotStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_DifferentialRobotControlStatus_DEFINED
            }
            case kwb_DifferentialRobotControl_v:
            {
#ifdef guWhiteboard_DifferentialRobotControlStatus_DEFINED
                class DifferentialRobotControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_DifferentialRobotControlStatus_DEFINED
            }
            case kwb_XEyesPos_v:
            {
#ifdef guWhiteboard_Point2D_DEFINED
                class XEyesPos_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Point2D_DEFINED
            }
            case kwb_VisionFace_v:
            {

                class VisionFace_t m(wbd);
                return msg ? intvectostring(m.get_from(msg)) : intvectostring(m.get());

            }
            case kwb_Draw_v:
            {

                class Draw_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kwb_FSM_States_v:
            {
#ifdef guWhiteboard_FSMState_DEFINED
                class FSM_States_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FSMState_DEFINED
            }
            case kwb_Giraff_Interface_Status_v:
            {
#ifdef guWhiteboard_GiraffMainSerialInterface_DEFINED
                class Giraff_Interface_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_GiraffMainSerialInterface_DEFINED
            }
            case kwb_Giraff_Interface_Command_v:
            {
#ifdef guWhiteboard_GiraffMainSerialInterface_DEFINED
                class Giraff_Interface_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_GiraffMainSerialInterface_DEFINED
            }
            case kwb_NXT_Status_v:
            {
#ifdef guWhiteboard_NXTInterface_DEFINED
                class NXT_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NXTInterface_DEFINED
            }
            case kwb_NXT_Command_v:
            {
#ifdef guWhiteboard_NXTInterface_DEFINED
                class NXT_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NXTInterface_DEFINED
            }
            case kwb_APM_Status_v:
            {
#ifdef guWhiteboard_APMInterface_DEFINED
                class APM_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_APMInterface_DEFINED
            }
            case kwb_APM_Command_v:
            {
#ifdef guWhiteboard_APMInterface_DEFINED
                class APM_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_APMInterface_DEFINED
            }
            case kwb_REMOVED3_v:
            {

                class REMOVED3_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_REMOVED4_v:
            {

                class REMOVED4_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_CBall_v:
            {

                class CBall_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_OculusPrime_Command_v:
            {
#ifdef guWhiteboard_OculusPrimeInterface_DEFINED
                class OculusPrime_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_OculusPrimeInterface_DEFINED
            }
            case kwb_Input3D_v:
            {
#ifdef guWhiteboard_Input3D_DEFINED
                class Input3D_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Input3D_DEFINED
            }
            case kwb_Oculus_Prime_Command_v:
            {
#ifdef guWhiteboard_OculusPrimeSerialInterface_DEFINED
                class Oculus_Prime_Command_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_OculusPrimeSerialInterface_DEFINED
            }
            case kwb_IOPins_v:
            {
#ifdef guWhiteboard_IOPins_DEFINED
                class IOPins_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_IOPins_DEFINED
            }
            case kwb_NXT_Two_Touch_Status_v:
            {
#ifdef guWhiteboard_NXTTwoTouchStatus_DEFINED
                class NXT_Two_Touch_Status_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NXTTwoTouchStatus_DEFINED
            }
            case kwb_NXT_Sound_Control_v:
            {
#ifdef guWhiteboard_NXTSoundControl_DEFINED
                class NXT_Sound_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NXTSoundControl_DEFINED
            }
            case kwb_NXT_Lights_Control_v:
            {
#ifdef guWhiteboard_NXTLightsControl_DEFINED
                class NXT_Lights_Control_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NXTLightsControl_DEFINED
            }
            case kwb_Clocks_v:
            {
#ifdef guWhiteboard_Clocks_DEFINED
                class Clocks_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Clocks_DEFINED
            }
            case kwb_Channels_v:
            {
#ifdef guWhiteboard_Channels_DEFINED
                class Channels_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Channels_DEFINED
            }
            case kwb_SwitchSubsumption_v:
            {
#ifdef guWhiteboard_SwitchSubsumption_DEFINED
                class SwitchSubsumption_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SwitchSubsumption_DEFINED
            }
            case kwb_TotoDoingMotion_v:
            {
#ifdef guWhiteboard_TotoDoingMotion_DEFINED
                class TotoDoingMotion_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_TotoDoingMotion_DEFINED
            }
            case kwb_Count_v:
            {
#ifdef guWhiteboard_Count_DEFINED
                class Count_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Count_DEFINED
            }
            case kwb_GreenEWon_v:
            {

                class GreenEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_WarnEW_v:
            {

                class WarnEW_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_TimeGTthirty_v:
            {

                class TimeGTthirty_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_AmberEWon_v:
            {

                class AmberEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_TurnRedEW_v:
            {

                class TurnRedEW_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_TimeGTfive_v:
            {

                class TimeGTfive_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_RedEWon_v:
            {

                class RedEWon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_GreenNSon_v:
            {

                class GreenNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_WarnNS_v:
            {

                class WarnNS_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_AmberNSon_v:
            {

                class AmberNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_TurnRedNS_v:
            {

                class TurnRedNS_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_RedNSon_v:
            {

                class RedNSon_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_TimerReset_v:
            {

                class TimerReset_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_SLOT_UNUSED_v:
            {

                class SLOT_UNUSED_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_CarSensorPressed_v:
            {

                class CarSensorPressed_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_SwitchSubsumptionTrafficLights_v:
            {
#ifdef guWhiteboard_SwitchSubsumptionTrafficLights_DEFINED
                class SwitchSubsumptionTrafficLights_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_SwitchSubsumptionTrafficLights_DEFINED
            }
            case kwb_Ball_Found_v:
            {

                class Ball_Found_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Ball_Calibration_File_v:
            {

                class Ball_Calibration_File_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kwb_Ball_Calibration_Num_v:
            {

                class Ball_Calibration_Num_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Ball_Color_Num_v:
            {

                class Ball_Color_Num_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_HAL_LArmTarget_Ctrl_v:
            {
#ifdef guWhiteboard_HalArmTarget_DEFINED
                class HAL_LArmTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalArmTarget_DEFINED
            }
            case kwb_HAL_LArmTarget_Stat_v:
            {
#ifdef guWhiteboard_HalArmTarget_DEFINED
                class HAL_LArmTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalArmTarget_DEFINED
            }
            case kwb_HAL_LArmTarget_Tolr_v:
            {
#ifdef guWhiteboard_HalArmTarget_DEFINED
                class HAL_LArmTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalArmTarget_DEFINED
            }
            case kwb_HAL_RArmTarget_Ctrl_v:
            {
#ifdef guWhiteboard_HalArmTarget_DEFINED
                class HAL_RArmTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalArmTarget_DEFINED
            }
            case kwb_HAL_RArmTarget_Stat_v:
            {
#ifdef guWhiteboard_HalArmTarget_DEFINED
                class HAL_RArmTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalArmTarget_DEFINED
            }
            case kwb_HAL_RArmTarget_Tolr_v:
            {
#ifdef guWhiteboard_HalArmTarget_DEFINED
                class HAL_RArmTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalArmTarget_DEFINED
            }
            case kwb_VisionFieldFeatures_v:
            {
#ifdef guWhiteboard_VisionFieldFeatures_DEFINED
                class VisionFieldFeatures_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionFieldFeatures_DEFINED
            }
            case kwb_WhistleBlown_v:
            {

                class WhistleBlown_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_VolumeControl_v:
            {

                class VolumeControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_VisionRobots_v:
            {
#ifdef guWhiteboard_VisionRobots_DEFINED
                class VisionRobots_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionRobots_DEFINED
            }
            case kwb_VisionDetectionHorizons_v:
            {
#ifdef guWhiteboard_VisionDetectionHorizons_DEFINED
                class VisionDetectionHorizons_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionDetectionHorizons_DEFINED
            }
            case kwb_NaoWalkCommand_v:
            {
#ifdef guWhiteboard_NaoWalkCommand_DEFINED
                class NaoWalkCommand_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NaoWalkCommand_DEFINED
            }
            case kwb_NaoWalkStatus_v:
            {
#ifdef guWhiteboard_NaoWalkStatus_DEFINED
                class NaoWalkStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NaoWalkStatus_DEFINED
            }
            case kwb_HAL_LLegTarget_Ctrl_v:
            {
#ifdef guWhiteboard_HalLegTarget_DEFINED
                class HAL_LLegTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalLegTarget_DEFINED
            }
            case kwb_HAL_LLegTarget_Stat_v:
            {
#ifdef guWhiteboard_HalLegTarget_DEFINED
                class HAL_LLegTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalLegTarget_DEFINED
            }
            case kwb_HAL_LLegTarget_Tolr_v:
            {
#ifdef guWhiteboard_HalLegTarget_DEFINED
                class HAL_LLegTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalLegTarget_DEFINED
            }
            case kwb_HAL_RLegTarget_Ctrl_v:
            {
#ifdef guWhiteboard_HalLegTarget_DEFINED
                class HAL_RLegTarget_Ctrl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalLegTarget_DEFINED
            }
            case kwb_HAL_RLegTarget_Stat_v:
            {
#ifdef guWhiteboard_HalLegTarget_DEFINED
                class HAL_RLegTarget_Stat_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalLegTarget_DEFINED
            }
            case kwb_HAL_RLegTarget_Tolr_v:
            {
#ifdef guWhiteboard_HalLegTarget_DEFINED
                class HAL_RLegTarget_Tolr_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HalLegTarget_DEFINED
            }
            case kwb_VisionDetectionGoals_v:
            {
#ifdef guWhiteboard_VisionDetectionGoals_DEFINED
                class VisionDetectionGoals_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionDetectionGoals_DEFINED
            }
            case kwb_TeleoperationControl_v:
            {
#ifdef guWhiteboard_TeleoperationControl_DEFINED
                class TeleoperationControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_TeleoperationControl_DEFINED
            }
            case kwb_TeleoperationStatus_v:
            {
#ifdef guWhiteboard_TeleoperationStatus_DEFINED
                class TeleoperationStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_TeleoperationStatus_DEFINED
            }
            case kwb_VisionDetectionBalls_v:
            {
#ifdef guWhiteboard_VisionDetectionBalls_DEFINED
                class VisionDetectionBalls_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionDetectionBalls_DEFINED
            }
            case kwb_TeleoperationControlVR_v:
            {
#ifdef guWhiteboard_TeleoperationControlVR_DEFINED
                class TeleoperationControlVR_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_TeleoperationControlVR_DEFINED
            }
            case kwb_ParticleOutputMap_v:
            {

                class ParticleOutputMap_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_ParticleOutputMapControl_v:
            {

                class ParticleOutputMapControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_FFTControl_v:
            {

                class FFTControl_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_MachineFilteredNaoVision_v:
            {
#ifdef guWhiteboard_MachineFilteredVision_DEFINED
                class MachineFilteredNaoVision_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MachineFilteredVision_DEFINED
            }
            case kwb_MicrowaveStatus_v:
            {
#ifdef guWhiteboard_MicrowaveStatus_DEFINED
                class MicrowaveStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MicrowaveStatus_DEFINED
            }
            case kwb_Buttons_v:
            {
#ifdef guWhiteboard_Buttons_DEFINED
                class Buttons_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Buttons_DEFINED
            }
            case kwb_MachineFilteredLocalisationVision_v:
            {
#ifdef guWhiteboard_MachineFilteredLocalisationVision_DEFINED
                class MachineFilteredLocalisationVision_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MachineFilteredLocalisationVision_DEFINED
            }
            case kwb_SensorsJointCurrent_v:
            {
#ifdef guWhiteboard_NaoJointListFloat_DEFINED
                class SensorsJointCurrent_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NaoJointListFloat_DEFINED
            }
            case kwb_DataLogger_v:
            {
#ifdef guWhiteboard_DataLogger_DEFINED
                class DataLogger_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_DataLogger_DEFINED
            }
            case kwb_MachineFilteredLines_v:
            {
#ifdef guWhiteboard_MachineFilteredLines_DEFINED
                class MachineFilteredLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MachineFilteredLines_DEFINED
            }
            case kwb_BallLocation_v:
            {
#ifdef guWhiteboard_Location_DEFINED
                class BallLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Location_DEFINED
            }
            case kwb_LeftGoalPostLocation_v:
            {
#ifdef guWhiteboard_Location_DEFINED
                class LeftGoalPostLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Location_DEFINED
            }
            case kwb_RightGoalPostLocation_v:
            {
#ifdef guWhiteboard_Location_DEFINED
                class RightGoalPostLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Location_DEFINED
            }
            case kwb_GoalLocation_v:
            {
#ifdef guWhiteboard_Location_DEFINED
                class GoalLocation_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Location_DEFINED
            }
            case kwb_NaoSonarProtectedWalkCommand_v:
            {
#ifdef guWhiteboard_NaoSonarProtectedWalkCommand_DEFINED
                class NaoSonarProtectedWalkCommand_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NaoSonarProtectedWalkCommand_DEFINED
            }
            case kwb_NaoObstacleDirection_v:
            {
#ifdef guWhiteboard_NaoObstacleDirection_DEFINED
                class NaoObstacleDirection_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_NaoObstacleDirection_DEFINED
            }
            case kwb_DominantFrequencies_v:
            {
#ifdef guWhiteboard_DominantFrequencies_DEFINED
                class DominantFrequencies_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_DominantFrequencies_DEFINED
            }
            case kwb_MissionPriorityForObstacles_v:
            {
#ifdef guWhiteboard_MissionPriorityForObstacles_DEFINED
                class MissionPriorityForObstacles_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MissionPriorityForObstacles_DEFINED
            }
            case kwb_WavLoad_v:
            {

                class WavLoad_t m(wbd);
                return msg ? m.get_from(msg) : m.get();

            }
            case kwb_WavPlay_v:
            {

                class WavPlay_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_ReproduceWavNotSilent_v:
            {

                class ReproduceWavNotSilent_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_FrequencyControl_v:
            {
#ifdef guWhiteboard_FrequencyLimits_DEFINED
                class FrequencyControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FrequencyLimits_DEFINED
            }
            case kwb_FrequencyStatus_v:
            {
#ifdef guWhiteboard_FrequencyLimits_DEFINED
                class FrequencyStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_FrequencyLimits_DEFINED
            }
            case kwb_HeadJointSensors_v:
            {
#ifdef guWhiteboard_HeadJointSensors_DEFINED
                class HeadJointSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_HeadJointSensors_DEFINED
            }
            case kwb_AdjustPositionConfidence_v:
            {
#ifdef guWhiteboard_AdjustPositionConfidence_DEFINED
                class AdjustPositionConfidence_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_AdjustPositionConfidence_DEFINED
            }
            case kwb_GuVrTeleopVulkanControl_v:
            {
#ifdef guWhiteboard_GuVrTeleopVulkanControl_DEFINED
                class GuVrTeleopVulkanControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_GuVrTeleopVulkanControl_DEFINED
            }
            case kwb_TemperatureSensors_v:
            {
#ifdef guWhiteboard_TemperatureSensors_DEFINED
                class TemperatureSensors_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_TemperatureSensors_DEFINED
            }
            case kwb_Overheating_v:
            {
#ifdef guWhiteboard_Overheating_DEFINED
                class Overheating_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_Overheating_DEFINED
            }
            case kwb_buttonPushed_v:
            {

                class buttonPushed_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_doorOpen_v:
            {

                class doorOpen_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_timeLeft_v:
            {

                class timeLeft_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_motor_v:
            {

                class motor_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_sound_v:
            {

                class sound_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_light_v:
            {

                class light_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino2Pin_v:
            {

                class Arduino2Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino2PinValue_v:
            {

                class Arduino2PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino3Pin_v:
            {

                class Arduino3Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino3PinValue_v:
            {

                class Arduino3PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino4Pin_v:
            {

                class Arduino4Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino4PinValue_v:
            {

                class Arduino4PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino5Pin_v:
            {

                class Arduino5Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino5PinValue_v:
            {

                class Arduino5PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino6Pin_v:
            {

                class Arduino6Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino6PinValue_v:
            {

                class Arduino6PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino7Pin_v:
            {

                class Arduino7Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino7PinValue_v:
            {

                class Arduino7PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino8Pin_v:
            {

                class Arduino8Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino8PinValue_v:
            {

                class Arduino8PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino9Pin_v:
            {

                class Arduino9Pin_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_Arduino9PinValue_v:
            {

                class Arduino9PinValue_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_BallPosition_v:
            {
#ifdef guWhiteboard_BallPosition_DEFINED
                class BallPosition_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_BallPosition_DEFINED
            }
            case kwb_MemoryImageControl_v:
            {
#ifdef guWhiteboard_MemoryImageControlStatus_DEFINED
                class MemoryImageControl_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MemoryImageControlStatus_DEFINED
            }
            case kwb_MemoryImageStatus_v:
            {
#ifdef guWhiteboard_MemoryImageControlStatus_DEFINED
                class MemoryImageStatus_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MemoryImageControlStatus_DEFINED
            }
            case kwb_LHandGripper_v:
            {

                class LHandGripper_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_RHandGripper_v:
            {

                class RHandGripper_t m(wbd);
                return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));

            }
            case kwb_MyPosition_v:
            {
#ifdef guWhiteboard_MyPosition_DEFINED
                class MyPosition_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_MyPosition_DEFINED
            }
            case kwb_VisionDetectionLines_v:
            {
#ifdef guWhiteboard_VisionDetectionLines_DEFINED
                class VisionDetectionLines_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionDetectionLines_DEFINED
            }
            case kwb_VisionDetectionFeatures_v:
            {
#ifdef guWhiteboard_VisionDetectionFeatures_DEFINED
                class VisionDetectionFeatures_t m(wbd);
                return msg ? m.get_from(msg).description() : m.get().description();
#else
                return "##unsupported##";
#endif //guWhiteboard_VisionDetectionFeatures_DEFINED
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
} // guWhiteboard

