/**
 *  /file guwhiteboardposter.cpp
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

/** Auto-generated, don't modify! */

#include <string>
#include <vector>
#include <cstdlib>

#define WHITEBOARD_POSTER_STRING_CONVERSION

#include "guwhiteboardtypelist_generated.h"
#include "guwhiteboardposter.h"

using namespace std;
using namespace guWhiteboard;

extern "C"
{
    WBTypes whiteboard_type_for_message_named(const char *message_type)
    {
        return types_map[message_type];
    }

    bool whiteboard_post(const char *message_type, const char *message_content)
    {
        return whiteboard_postmsg(types_map[message_type], message_content);
    }

    bool whiteboard_post_to(gu_simple_whiteboard_descriptor *wbd, const char *message_type, const char *message_content)
    {
        return whiteboard_postmsg_to(wbd, types_map[message_type], message_content);
    }

    bool whiteboard_postmsg(int message_index, const char *message_content)
    {
        return postmsg(WBTypes(message_index), message_content);
    }

    bool whiteboard_postmsg_to(gu_simple_whiteboard_descriptor *wbd, int message_index, const char *message_content)
    {
        return postmsg(WBTypes(message_index), message_content, wbd);
    }
} // extern C

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"

static vector<int> strtointvec(string str)
{
    const char *sep = "|,";
    char *context = NULLPTR;
    vector<int> array;
    for (char *element = strtok_r(const_cast<char *>(str.c_str()), sep, &context); element; element = strtok_r(NULLPTR, sep, &context))
        array.push_back(atoi(element));
    return array;
}

#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wexit-time-destructors"

whiteboard_types_map guWhiteboard::types_map; ///< global types map

#pragma clang diagnostic pop

namespace guWhiteboard
{
    bool post(string message_type, string message_content, gu_simple_whiteboard_descriptor *wbd)
    {
        return postmsg(types_map[message_type], message_content, wbd);
    }


    bool postmsg(WBTypes message_index, std::string message_content, gu_simple_whiteboard_descriptor *wbd)
    {
        switch (message_index)
        {

case kwb_reserved_SubscribeToAllTypes_v:
{

    class wb_reserved_SubscribeToAllTypes_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kPrint_v:
{

    class Print_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kSay_v:
{

    class Say_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kSpeech_v:
{

    class Speech_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kQSay_v:
{

    class QSay_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kQSpeech_v:
{

    class QSpeech_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kSpeechOutput_v:
{

    class SpeechOutput_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kGCGameState_v:
{
#ifdef GCGameState_DEFINED
    class GCGameState_t msg_ptr(wbd);
    GCGameState v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //GCGameState_DEFINED
}
case kSensorsHandSensors_v:
{
#ifdef SensorsHandSensors_DEFINED
    class SensorsHandSensors_t msg_ptr(wbd);
    SensorsHandSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SensorsHandSensors_DEFINED
}
case kSensorsHeadSensors_v:
{
#ifdef SensorsHeadSensors_DEFINED
    class SensorsHeadSensors_t msg_ptr(wbd);
    SensorsHeadSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SensorsHeadSensors_DEFINED
}
case kMOTION_Commands_v:
{
#ifdef MOTION_Commands_DEFINED
    class MOTION_Commands_t msg_ptr(wbd);
    MOTION_Commands v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //MOTION_Commands_DEFINED
}
case kMOTION_Status_v:
{
#ifdef MOTION_Status_DEFINED
    class MOTION_Status_t msg_ptr(wbd);
    MOTION_Status v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //MOTION_Status_DEFINED
}
case kHAL_HeadTarget_v:
{
#ifdef HAL_HeadTarget_DEFINED
    class HAL_HeadTarget_t msg_ptr(wbd);
    HAL_HeadTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HAL_HeadTarget_DEFINED
}
case kSensorsFootSensors_v:
{
#ifdef SensorsFootSensors_DEFINED
    class SensorsFootSensors_t msg_ptr(wbd);
    SensorsFootSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SensorsFootSensors_DEFINED
}
case kSensorsBodySensors_v:
{
#ifdef SensorsBodySensors_DEFINED
    class SensorsBodySensors_t msg_ptr(wbd);
    SensorsBodySensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SensorsBodySensors_DEFINED
}
case kSENSORSLedsSensors_v:
{
#ifdef SENSORSLedsSensors_DEFINED
    class SENSORSLedsSensors_t msg_ptr(wbd);
    SENSORSLedsSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SENSORSLedsSensors_DEFINED
}
case kSENSORSLegJointTemps_v:
{
#ifdef SENSORSLegJointTemps_DEFINED
    class SENSORSLegJointTemps_t msg_ptr(wbd);
    SENSORSLegJointTemps v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SENSORSLegJointTemps_DEFINED
}
case kSENSORSTorsoJointTemps_v:
{
#ifdef SENSORSTorsoJointTemps_DEFINED
    class SENSORSTorsoJointTemps_t msg_ptr(wbd);
    SENSORSTorsoJointTemps v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SENSORSTorsoJointTemps_DEFINED
}
case kSENSORSLegJointSensors_v:
{
#ifdef SENSORSLegJointSensors_DEFINED
    class SENSORSLegJointSensors_t msg_ptr(wbd);
    SENSORSLegJointSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SENSORSLegJointSensors_DEFINED
}
case kSENSORSTorsoJointSensors_v:
{
#ifdef SENSORSTorsoJointSensors_DEFINED
    class SENSORSTorsoJointSensors_t msg_ptr(wbd);
    SENSORSTorsoJointSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SENSORSTorsoJointSensors_DEFINED
}
case kSENSORSSonarSensors_v:
{
#ifdef SENSORSSonarSensors_DEFINED
    class SENSORSSonarSensors_t msg_ptr(wbd);
    SENSORSSonarSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SENSORSSonarSensors_DEFINED
}
case kFSM_Control_v:
{
#ifdef FSMControlStatus_DEFINED
    class FSM_Control_t msg_ptr(wbd);
    FSMControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FSMControlStatus_DEFINED
}
case kFSM_Status_v:
{
#ifdef FSMControlStatus_DEFINED
    class FSM_Status_t msg_ptr(wbd);
    FSMControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FSMControlStatus_DEFINED
}
case kFSM_Names_v:
{
#ifdef FSMNames_DEFINED
    class FSM_Names_t msg_ptr(wbd);
    FSMNames v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FSMNames_DEFINED
}
case kSoloTypeExample_v:
{

    class SoloTypeExample_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kFilteredGoalSighting_v:
{
#ifdef FilteredArrayOneDimObjects_DEFINED
    class FilteredGoalSighting_t msg_ptr(wbd);
    FilteredArrayOneDimObjects v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FilteredArrayOneDimObjects_DEFINED
}
case kNAO_State_v:
{
#ifdef NAO_State_DEFINED
    class NAO_State_t msg_ptr(wbd);
    NAO_State v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NAO_State_DEFINED
}
case kUDPRN_v:
{
#ifdef GCGameState_DEFINED
    class UDPRN_t msg_ptr(wbd);
    GCGameState v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //GCGameState_DEFINED
}
case kPlayerNumber_v:
{

    class PlayerNumber_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kManuallyPenalized_v:
{

    class ManuallyPenalized_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kVisionControl_v:
{
#ifdef VisionControlStatus_DEFINED
    class VisionControl_t msg_ptr(wbd);
    VisionControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionControlStatus_DEFINED
}
case kVisionStatus_v:
{
#ifdef VisionControlStatus_DEFINED
    class VisionStatus_t msg_ptr(wbd);
    VisionControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionControlStatus_DEFINED
}
case kFFTStatus_v:
{
#ifdef FFTStatus_DEFINED
    class FFTStatus_t msg_ptr(wbd);
    FFTStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FFTStatus_DEFINED
}
case kFSOsighting_v:
{
#ifdef FilteredArrayOneDimSonar_DEFINED
    class FSOsighting_t msg_ptr(wbd);
    FilteredArrayOneDimSonar v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FilteredArrayOneDimSonar_DEFINED
}
case kTopParticles_v:
{
#ifdef TopParticles_DEFINED
    class TopParticles_t msg_ptr(wbd);
    TopParticles v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //TopParticles_DEFINED
}
case kFilteredBallSighting_v:
{
#ifdef FilteredArrayBallSightings_DEFINED
    class FilteredBallSighting_t msg_ptr(wbd);
    FilteredArrayBallSightings v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FilteredArrayBallSightings_DEFINED
}
case kPF_ControlStatus_Modes_v:
{

    class PF_ControlStatus_Modes_t msg_ptr(wbd);
    int32_t v = static_cast<int32_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kWEBOTS_NXT_bridge_v:
{
#ifdef WEBOTS_NXT_bridge_DEFINED
    class WEBOTS_NXT_bridge_t msg_ptr(wbd);
    WEBOTS_NXT_bridge v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_bridge_DEFINED
}
case kWEBOTS_NXT_encoders_v:
{
#ifdef WEBOTS_NXT_encoders_DEFINED
    class WEBOTS_NXT_encoders_t msg_ptr(wbd);
    WEBOTS_NXT_encoders v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_encoders_DEFINED
}
case kWEBOTS_NXT_camera_v:
{
#ifdef WEBOTS_NXT_camera_DEFINED
    class WEBOTS_NXT_camera_t msg_ptr(wbd);
    WEBOTS_NXT_camera v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_camera_DEFINED
}
case kWEBOTS_NXT_walk_isRunning_v:
{
#ifdef WEBOTS_NXT_walk_isRunning_DEFINED
    class WEBOTS_NXT_walk_isRunning_t msg_ptr(wbd);
    WEBOTS_NXT_walk_isRunning v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_walk_isRunning_DEFINED
}
case kWEBOTS_NXT_deadReakoning_walk_v:
{
#ifdef WEBOTS_NXT_deadReakoning_walk_DEFINED
    class WEBOTS_NXT_deadReakoning_walk_t msg_ptr(wbd);
    WEBOTS_NXT_deadReakoning_walk v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_deadReakoning_walk_DEFINED
}
case kWEBOTS_NXT_colorLine_walk_v:
{
#ifdef WEBOTS_NXT_colorLine_walk_DEFINED
    class WEBOTS_NXT_colorLine_walk_t msg_ptr(wbd);
    WEBOTS_NXT_colorLine_walk v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_colorLine_walk_DEFINED
}
case kWEBOTS_NXT_gridMotions_v:
{
#ifdef WEBOTS_NXT_gridMotions_DEFINED
    class WEBOTS_NXT_gridMotions_t msg_ptr(wbd);
    WEBOTS_NXT_gridMotions v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_gridMotions_DEFINED
}
case kVisionBall_v:
{
#ifdef VisionBall_DEFINED
    class VisionBall_t msg_ptr(wbd);
    VisionBall v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionBall_DEFINED
}
case kVisionGoals_v:
{
#ifdef VisionGoals_DEFINED
    class VisionGoals_t msg_ptr(wbd);
    VisionGoals v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionGoals_DEFINED
}
case kWalkData_v:
{
#ifdef WalkData_DEFINED
    class WalkData_t msg_ptr(wbd);
    WalkData v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WalkData_DEFINED
}
case kTeleoperationControlStatus_v:
{
#ifdef TeleoperationControlStatus_DEFINED
    class TeleoperationControlStatus_t msg_ptr(wbd);
    TeleoperationControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //TeleoperationControlStatus_DEFINED
}
case kTeleoperationConnection_v:
{

    class TeleoperationConnection_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kUDPWBNumber_v:
{

    class UDPWBNumber_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kWEBOTS_NXT_bumper_v:
{
#ifdef WEBOTS_NXT_bumper_DEFINED
    class WEBOTS_NXT_bumper_t msg_ptr(wbd);
    WEBOTS_NXT_bumper v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_bumper_DEFINED
}
case kWEBOTS_NXT_vector_bridge_v:
{
#ifdef WEBOTS_NXT_vector_bridge_DEFINED
    class WEBOTS_NXT_vector_bridge_t msg_ptr(wbd);
    WEBOTS_NXT_vector_bridge v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //WEBOTS_NXT_vector_bridge_DEFINED
}
case kVisionLines_v:
{
#ifdef VisionLines_DEFINED
    class VisionLines_t msg_ptr(wbd);
    VisionLines v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionLines_DEFINED
}
case kDifferentialRobotStatus_v:
{
#ifdef DifferentialRobotControlStatus_DEFINED
    class DifferentialRobotStatus_t msg_ptr(wbd);
    DifferentialRobotControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //DifferentialRobotControlStatus_DEFINED
}
case kDifferentialRobotControl_v:
{
#ifdef DifferentialRobotControlStatus_DEFINED
    class DifferentialRobotControl_t msg_ptr(wbd);
    DifferentialRobotControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //DifferentialRobotControlStatus_DEFINED
}
case kXEyesPos_v:
{
#ifdef Point2D_DEFINED
    class XEyesPos_t msg_ptr(wbd);
    Point2D v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Point2D_DEFINED
}
case kVisionFace_v:
{

    class VisionFace_t msg_ptr(wbd);
    std::vector<int> v = strtointvec(message_content);
    msg_ptr.post(v);
    return true;

}
case kDraw_v:
{

    class Draw_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kFSM_States_v:
{
#ifdef FSMState_DEFINED
    class FSM_States_t msg_ptr(wbd);
    FSMState v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FSMState_DEFINED
}
case kGiraff_Interface_Status_v:
{
#ifdef Giraff_MainSerialInterface_DEFINED
    class Giraff_Interface_Status_t msg_ptr(wbd);
    Giraff_MainSerialInterface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Giraff_MainSerialInterface_DEFINED
}
case kGiraff_Interface_Command_v:
{
#ifdef Giraff_MainSerialInterface_DEFINED
    class Giraff_Interface_Command_t msg_ptr(wbd);
    Giraff_MainSerialInterface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Giraff_MainSerialInterface_DEFINED
}
case kNXT_Status_v:
{
#ifdef NXT_Interface_DEFINED
    class NXT_Status_t msg_ptr(wbd);
    NXT_Interface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NXT_Interface_DEFINED
}
case kNXT_Command_v:
{
#ifdef NXT_Interface_DEFINED
    class NXT_Command_t msg_ptr(wbd);
    NXT_Interface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NXT_Interface_DEFINED
}
case kAPM_Status_v:
{
#ifdef APM_Interface_DEFINED
    class APM_Status_t msg_ptr(wbd);
    APM_Interface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //APM_Interface_DEFINED
}
case kAPM_Command_v:
{
#ifdef APM_Interface_DEFINED
    class APM_Command_t msg_ptr(wbd);
    APM_Interface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //APM_Interface_DEFINED
}
case kREMOVED3_v:
{

    class REMOVED3_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kREMOVED4_v:
{

    class REMOVED4_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kCBall_v:
{

    class CBall_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kOculusPrime_Command_v:
{
#ifdef OculusPrimeInterface_DEFINED
    class OculusPrime_Command_t msg_ptr(wbd);
    OculusPrimeInterface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //OculusPrimeInterface_DEFINED
}
case kInput3D_v:
{
#ifdef Input3D_DEFINED
    class Input3D_t msg_ptr(wbd);
    Input3D v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Input3D_DEFINED
}
case kOculus_Prime_Command_v:
{
#ifdef Oculus_PrimeSerialInterface_DEFINED
    class Oculus_Prime_Command_t msg_ptr(wbd);
    Oculus_PrimeSerialInterface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Oculus_PrimeSerialInterface_DEFINED
}
case kIOPins_v:
{
#ifdef IOPins_DEFINED
    class IOPins_t msg_ptr(wbd);
    IOPins v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //IOPins_DEFINED
}
case kNXT_Two_Touch_Status_v:
{
#ifdef NXT_Two_Touch_Status_DEFINED
    class NXT_Two_Touch_Status_t msg_ptr(wbd);
    NXT_Two_Touch_Status v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NXT_Two_Touch_Status_DEFINED
}
case kNXT_Sound_Control_v:
{
#ifdef NXT_Sound_Control_DEFINED
    class NXT_Sound_Control_t msg_ptr(wbd);
    NXT_Sound_Control v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NXT_Sound_Control_DEFINED
}
case kNXT_Lights_Control_v:
{
#ifdef NXT_Lights_Control_DEFINED
    class NXT_Lights_Control_t msg_ptr(wbd);
    NXT_Lights_Control v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NXT_Lights_Control_DEFINED
}
case kClocks_v:
{
#ifdef Clocks_DEFINED
    class Clocks_t msg_ptr(wbd);
    Clocks v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Clocks_DEFINED
}
case kChannels_v:
{
#ifdef Channels_DEFINED
    class Channels_t msg_ptr(wbd);
    Channels v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Channels_DEFINED
}
case kSwitchSubsumption_v:
{
#ifdef SwitchSubsumption_DEFINED
    class SwitchSubsumption_t msg_ptr(wbd);
    SwitchSubsumption v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SwitchSubsumption_DEFINED
}
case kTotoDoingMotion_v:
{
#ifdef TotoDoingMotion_DEFINED
    class TotoDoingMotion_t msg_ptr(wbd);
    TotoDoingMotion v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //TotoDoingMotion_DEFINED
}
case kCount_v:
{
#ifdef Count_DEFINED
    class Count_t msg_ptr(wbd);
    Count v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Count_DEFINED
}
case kGreenEWon_v:
{

    class GreenEWon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kWarnEW_v:
{

    class WarnEW_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kTimeGTthirty_v:
{

    class TimeGTthirty_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kAmberEWon_v:
{

    class AmberEWon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kTurnRedEW_v:
{

    class TurnRedEW_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kTimeGTfive_v:
{

    class TimeGTfive_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kRedEWon_v:
{

    class RedEWon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kGreenNSon_v:
{

    class GreenNSon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kWarnNS_v:
{

    class WarnNS_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kAmberNSon_v:
{

    class AmberNSon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kTurnRedNS_v:
{

    class TurnRedNS_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kRedNSon_v:
{

    class RedNSon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kTimerReset_v:
{

    class TimerReset_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kSLOT_UNUSED_v:
{

    class SLOT_UNUSED_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kCarSensorPressed_v:
{

    class CarSensorPressed_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kSwitchSubsumptionTrafficLights_v:
{
#ifdef SwitchSubsumptionTrafficLights_DEFINED
    class SwitchSubsumptionTrafficLights_t msg_ptr(wbd);
    SwitchSubsumptionTrafficLights v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //SwitchSubsumptionTrafficLights_DEFINED
}
case kBall_Found_v:
{

    class Ball_Found_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kBall_Calibration_File_v:
{

    class Ball_Calibration_File_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kBall_Calibration_Num_v:
{

    class Ball_Calibration_Num_t msg_ptr(wbd);
    int32_t v = static_cast<int32_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kBall_Color_Num_v:
{

    class Ball_Color_Num_t msg_ptr(wbd);
    int32_t v = static_cast<int32_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kHAL_LArmTarget_Ctrl_v:
{
#ifdef HalArmTarget_DEFINED
    class HAL_LArmTarget_Ctrl_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalArmTarget_DEFINED
}
case kHAL_LArmTarget_Stat_v:
{
#ifdef HalArmTarget_DEFINED
    class HAL_LArmTarget_Stat_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalArmTarget_DEFINED
}
case kHAL_LArmTarget_Tolr_v:
{
#ifdef HalArmTarget_DEFINED
    class HAL_LArmTarget_Tolr_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalArmTarget_DEFINED
}
case kHAL_RArmTarget_Ctrl_v:
{
#ifdef HalArmTarget_DEFINED
    class HAL_RArmTarget_Ctrl_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalArmTarget_DEFINED
}
case kHAL_RArmTarget_Stat_v:
{
#ifdef HalArmTarget_DEFINED
    class HAL_RArmTarget_Stat_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalArmTarget_DEFINED
}
case kHAL_RArmTarget_Tolr_v:
{
#ifdef HalArmTarget_DEFINED
    class HAL_RArmTarget_Tolr_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalArmTarget_DEFINED
}
case kVisionFieldFeatures_v:
{
#ifdef VisionFieldFeatures_DEFINED
    class VisionFieldFeatures_t msg_ptr(wbd);
    VisionFieldFeatures v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionFieldFeatures_DEFINED
}
case kWhistleBlown_v:
{

    class WhistleBlown_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kVolumeControl_v:
{

    class VolumeControl_t msg_ptr(wbd);
    uint8_t v = static_cast<uint8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kVisionRobots_v:
{
#ifdef VisionRobots_DEFINED
    class VisionRobots_t msg_ptr(wbd);
    VisionRobots v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionRobots_DEFINED
}
case kVisionDetectionHorizons_v:
{
#ifdef VisionDetectionHorizons_DEFINED
    class VisionDetectionHorizons_t msg_ptr(wbd);
    VisionDetectionHorizons v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionDetectionHorizons_DEFINED
}
case kNaoWalkCommand_v:
{
#ifdef NaoWalkCommand_DEFINED
    class NaoWalkCommand_t msg_ptr(wbd);
    NaoWalkCommand v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NaoWalkCommand_DEFINED
}
case kNaoWalkStatus_v:
{
#ifdef NaoWalkStatus_DEFINED
    class NaoWalkStatus_t msg_ptr(wbd);
    NaoWalkStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NaoWalkStatus_DEFINED
}
case kHAL_LLegTarget_Ctrl_v:
{
#ifdef HalLegTarget_DEFINED
    class HAL_LLegTarget_Ctrl_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalLegTarget_DEFINED
}
case kHAL_LLegTarget_Stat_v:
{
#ifdef HalLegTarget_DEFINED
    class HAL_LLegTarget_Stat_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalLegTarget_DEFINED
}
case kHAL_LLegTarget_Tolr_v:
{
#ifdef HalLegTarget_DEFINED
    class HAL_LLegTarget_Tolr_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalLegTarget_DEFINED
}
case kHAL_RLegTarget_Ctrl_v:
{
#ifdef HalLegTarget_DEFINED
    class HAL_RLegTarget_Ctrl_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalLegTarget_DEFINED
}
case kHAL_RLegTarget_Stat_v:
{
#ifdef HalLegTarget_DEFINED
    class HAL_RLegTarget_Stat_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalLegTarget_DEFINED
}
case kHAL_RLegTarget_Tolr_v:
{
#ifdef HalLegTarget_DEFINED
    class HAL_RLegTarget_Tolr_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HalLegTarget_DEFINED
}
case kVisionDetectionGoals_v:
{
#ifdef VisionDetectionGoals_DEFINED
    class VisionDetectionGoals_t msg_ptr(wbd);
    VisionDetectionGoals v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionDetectionGoals_DEFINED
}
case kTeleoperationControl_v:
{
#ifdef TeleoperationControl_DEFINED
    class TeleoperationControl_t msg_ptr(wbd);
    TeleoperationControl v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //TeleoperationControl_DEFINED
}
case kTeleoperationStatus_v:
{
#ifdef TeleoperationStatus_DEFINED
    class TeleoperationStatus_t msg_ptr(wbd);
    TeleoperationStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //TeleoperationStatus_DEFINED
}
case kVisionDetectionBalls_v:
{
#ifdef VisionDetectionBalls_DEFINED
    class VisionDetectionBalls_t msg_ptr(wbd);
    VisionDetectionBalls v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //VisionDetectionBalls_DEFINED
}
case kTeleoperationControlVR_v:
{
#ifdef TeleoperationControlVR_DEFINED
    class TeleoperationControlVR_t msg_ptr(wbd);
    TeleoperationControlVR v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //TeleoperationControlVR_DEFINED
}
case kParticleOutputMap_v:
{

    class ParticleOutputMap_t msg_ptr(wbd);
    uint64_t v = static_cast<uint64_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kParticleOutputMapControl_v:
{

    class ParticleOutputMapControl_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kFFTControl_v:
{

    class FFTControl_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kMachineFilteredNaoVision_v:
{
#ifdef MachineFilteredVision_DEFINED
    class MachineFilteredNaoVision_t msg_ptr(wbd);
    MachineFilteredVision v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //MachineFilteredVision_DEFINED
}
case kMicrowaveStatus_v:
{
#ifdef MicrowaveStatus_DEFINED
    class MicrowaveStatus_t msg_ptr(wbd);
    MicrowaveStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //MicrowaveStatus_DEFINED
}
case kButtons_v:
{
#ifdef Buttons_DEFINED
    class Buttons_t msg_ptr(wbd);
    Buttons v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Buttons_DEFINED
}
case kMachineFilteredLocalisationVision_v:
{
#ifdef MachineFilteredLocalisationVision_DEFINED
    class MachineFilteredLocalisationVision_t msg_ptr(wbd);
    MachineFilteredLocalisationVision v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //MachineFilteredLocalisationVision_DEFINED
}
case kSensorsJointCurrent_v:
{
#ifdef NaoJointListFloat_DEFINED
    class SensorsJointCurrent_t msg_ptr(wbd);
    NaoJointListFloat v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NaoJointListFloat_DEFINED
}
case kDataLogger_v:
{
#ifdef DataLogger_DEFINED
    class DataLogger_t msg_ptr(wbd);
    DataLogger v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //DataLogger_DEFINED
}
case kMachineFilteredLines_v:
{
#ifdef MachineFilteredLines_DEFINED
    class MachineFilteredLines_t msg_ptr(wbd);
    MachineFilteredLines v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //MachineFilteredLines_DEFINED
}
case kBallLocation_v:
{
#ifdef Location_DEFINED
    class BallLocation_t msg_ptr(wbd);
    Location v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Location_DEFINED
}
case kLeftGoalPostLocation_v:
{
#ifdef Location_DEFINED
    class LeftGoalPostLocation_t msg_ptr(wbd);
    Location v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Location_DEFINED
}
case kRightGoalPostLocation_v:
{
#ifdef Location_DEFINED
    class RightGoalPostLocation_t msg_ptr(wbd);
    Location v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Location_DEFINED
}
case kGoalLocation_v:
{
#ifdef Location_DEFINED
    class GoalLocation_t msg_ptr(wbd);
    Location v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //Location_DEFINED
}
case kNaoSonarProtectedWalkCommand_v:
{
#ifdef NaoSonarProtectedWalkCommand_DEFINED
    class NaoSonarProtectedWalkCommand_t msg_ptr(wbd);
    NaoSonarProtectedWalkCommand v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NaoSonarProtectedWalkCommand_DEFINED
}
case kNaoObstacleDirection_v:
{
#ifdef NaoObstacleDirection_DEFINED
    class NaoObstacleDirection_t msg_ptr(wbd);
    NaoObstacleDirection v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //NaoObstacleDirection_DEFINED
}
case kDominantFrequencies_v:
{
#ifdef DominantFrequencies_DEFINED
    class DominantFrequencies_t msg_ptr(wbd);
    DominantFrequencies v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //DominantFrequencies_DEFINED
}
case kMissionPriorityForObstacles_v:
{
#ifdef MissionPriorityForObstacles_DEFINED
    class MissionPriorityForObstacles_t msg_ptr(wbd);
    MissionPriorityForObstacles v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //MissionPriorityForObstacles_DEFINED
}
case kWavLoad_v:
{

    class WavLoad_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kWavPlay_v:
{

    class WavPlay_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kReproduceWavNotSilent_v:
{

    class ReproduceWavNotSilent_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kFrequencyControl_v:
{
#ifdef FrequencyLimits_DEFINED
    class FrequencyControl_t msg_ptr(wbd);
    FrequencyLimits v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FrequencyLimits_DEFINED
}
case kFrequencyStatus_v:
{
#ifdef FrequencyLimits_DEFINED
    class FrequencyStatus_t msg_ptr(wbd);
    FrequencyLimits v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //FrequencyLimits_DEFINED
}
case kHeadJointSensors_v:
{
#ifdef HeadJointSensors_DEFINED
    class HeadJointSensors_t msg_ptr(wbd);
    HeadJointSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //HeadJointSensors_DEFINED
}
case kAdjustPositionConfidence_v:
{
#ifdef AdjustPositionConfidence_DEFINED
    class AdjustPositionConfidence_t msg_ptr(wbd);
    AdjustPositionConfidence v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //AdjustPositionConfidence_DEFINED
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
        (void) message_content;
    }

    return false;
#pragma clang diagnostic pop
    }
}

whiteboard_types_map::whiteboard_types_map(): map<string, WBTypes>()
{
    whiteboard_types_map &self = *this;

    self["wb_reserved_SubscribeToAllTypes"] = kwb_reserved_SubscribeToAllTypes_v;
    self["Print"] = kPrint_v;
    self["Say"] = kSay_v;
    self["Speech"] = kSpeech_v;
    self["QSay"] = kQSay_v;
    self["QSpeech"] = kQSpeech_v;
    self["SpeechOutput"] = kSpeechOutput_v;
    self["GCGameState"] = kGCGameState_v;
    self["SensorsHandSensors"] = kSensorsHandSensors_v;
    self["SensorsHeadSensors"] = kSensorsHeadSensors_v;
    self["MOTION_Commands"] = kMOTION_Commands_v;
    self["MOTION_Status"] = kMOTION_Status_v;
    self["HAL_HeadTarget"] = kHAL_HeadTarget_v;
    self["SensorsFootSensors"] = kSensorsFootSensors_v;
    self["SensorsBodySensors"] = kSensorsBodySensors_v;
    self["SENSORSLedsSensors"] = kSENSORSLedsSensors_v;
    self["SENSORSLegJointTemps"] = kSENSORSLegJointTemps_v;
    self["SENSORSTorsoJointTemps"] = kSENSORSTorsoJointTemps_v;
    self["SENSORSLegJointSensors"] = kSENSORSLegJointSensors_v;
    self["SENSORSTorsoJointSensors"] = kSENSORSTorsoJointSensors_v;
    self["SENSORSSonarSensors"] = kSENSORSSonarSensors_v;
    self["FSM_Control"] = kFSM_Control_v;
    self["FSM_Status"] = kFSM_Status_v;
    self["FSM_Names"] = kFSM_Names_v;
    self["SoloTypeExample"] = kSoloTypeExample_v;
    self["FilteredGoalSighting"] = kFilteredGoalSighting_v;
    self["NAO_State"] = kNAO_State_v;
    self["UDPRN"] = kUDPRN_v;
    self["PlayerNumber"] = kPlayerNumber_v;
    self["ManuallyPenalized"] = kManuallyPenalized_v;
    self["VisionControl"] = kVisionControl_v;
    self["VisionStatus"] = kVisionStatus_v;
    self["FFTStatus"] = kFFTStatus_v;
    self["FSOsighting"] = kFSOsighting_v;
    self["TopParticles"] = kTopParticles_v;
    self["FilteredBallSighting"] = kFilteredBallSighting_v;
    self["PF_ControlStatus_Modes"] = kPF_ControlStatus_Modes_v;
    self["WEBOTS_NXT_bridge"] = kWEBOTS_NXT_bridge_v;
    self["WEBOTS_NXT_encoders"] = kWEBOTS_NXT_encoders_v;
    self["WEBOTS_NXT_camera"] = kWEBOTS_NXT_camera_v;
    self["WEBOTS_NXT_walk_isRunning"] = kWEBOTS_NXT_walk_isRunning_v;
    self["WEBOTS_NXT_deadReakoning_walk"] = kWEBOTS_NXT_deadReakoning_walk_v;
    self["WEBOTS_NXT_colorLine_walk"] = kWEBOTS_NXT_colorLine_walk_v;
    self["WEBOTS_NXT_gridMotions"] = kWEBOTS_NXT_gridMotions_v;
    self["VisionBall"] = kVisionBall_v;
    self["VisionGoals"] = kVisionGoals_v;
    self["WalkData"] = kWalkData_v;
    self["TeleoperationControlStatus"] = kTeleoperationControlStatus_v;
    self["TeleoperationConnection"] = kTeleoperationConnection_v;
    self["UDPWBNumber"] = kUDPWBNumber_v;
    self["WEBOTS_NXT_bumper"] = kWEBOTS_NXT_bumper_v;
    self["WEBOTS_NXT_vector_bridge"] = kWEBOTS_NXT_vector_bridge_v;
    self["VisionLines"] = kVisionLines_v;
    self["DifferentialRobotStatus"] = kDifferentialRobotStatus_v;
    self["DifferentialRobotControl"] = kDifferentialRobotControl_v;
    self["XEyesPos"] = kXEyesPos_v;
    self["VisionFace"] = kVisionFace_v;
    self["Draw"] = kDraw_v;
    self["FSM_States"] = kFSM_States_v;
    self["Giraff_Interface_Status"] = kGiraff_Interface_Status_v;
    self["Giraff_Interface_Command"] = kGiraff_Interface_Command_v;
    self["NXT_Status"] = kNXT_Status_v;
    self["NXT_Command"] = kNXT_Command_v;
    self["APM_Status"] = kAPM_Status_v;
    self["APM_Command"] = kAPM_Command_v;
    self["REMOVED3"] = kREMOVED3_v;
    self["REMOVED4"] = kREMOVED4_v;
    self["CBall"] = kCBall_v;
    self["OculusPrime_Command"] = kOculusPrime_Command_v;
    self["Input3D"] = kInput3D_v;
    self["Oculus_Prime_Command"] = kOculus_Prime_Command_v;
    self["IOPins"] = kIOPins_v;
    self["NXT_Two_Touch_Status"] = kNXT_Two_Touch_Status_v;
    self["NXT_Sound_Control"] = kNXT_Sound_Control_v;
    self["NXT_Lights_Control"] = kNXT_Lights_Control_v;
    self["Clocks"] = kClocks_v;
    self["Channels"] = kChannels_v;
    self["SwitchSubsumption"] = kSwitchSubsumption_v;
    self["TotoDoingMotion"] = kTotoDoingMotion_v;
    self["Count"] = kCount_v;
    self["GreenEWon"] = kGreenEWon_v;
    self["WarnEW"] = kWarnEW_v;
    self["TimeGTthirty"] = kTimeGTthirty_v;
    self["AmberEWon"] = kAmberEWon_v;
    self["TurnRedEW"] = kTurnRedEW_v;
    self["TimeGTfive"] = kTimeGTfive_v;
    self["RedEWon"] = kRedEWon_v;
    self["GreenNSon"] = kGreenNSon_v;
    self["WarnNS"] = kWarnNS_v;
    self["AmberNSon"] = kAmberNSon_v;
    self["TurnRedNS"] = kTurnRedNS_v;
    self["RedNSon"] = kRedNSon_v;
    self["TimerReset"] = kTimerReset_v;
    self["SLOT_UNUSED"] = kSLOT_UNUSED_v;
    self["CarSensorPressed"] = kCarSensorPressed_v;
    self["SwitchSubsumptionTrafficLights"] = kSwitchSubsumptionTrafficLights_v;
    self["Ball_Found"] = kBall_Found_v;
    self["Ball_Calibration_File"] = kBall_Calibration_File_v;
    self["Ball_Calibration_Num"] = kBall_Calibration_Num_v;
    self["Ball_Color_Num"] = kBall_Color_Num_v;
    self["HAL_LArmTarget_Ctrl"] = kHAL_LArmTarget_Ctrl_v;
    self["HAL_LArmTarget_Stat"] = kHAL_LArmTarget_Stat_v;
    self["HAL_LArmTarget_Tolr"] = kHAL_LArmTarget_Tolr_v;
    self["HAL_RArmTarget_Ctrl"] = kHAL_RArmTarget_Ctrl_v;
    self["HAL_RArmTarget_Stat"] = kHAL_RArmTarget_Stat_v;
    self["HAL_RArmTarget_Tolr"] = kHAL_RArmTarget_Tolr_v;
    self["VisionFieldFeatures"] = kVisionFieldFeatures_v;
    self["WhistleBlown"] = kWhistleBlown_v;
    self["VolumeControl"] = kVolumeControl_v;
    self["VisionRobots"] = kVisionRobots_v;
    self["VisionDetectionHorizons"] = kVisionDetectionHorizons_v;
    self["NaoWalkCommand"] = kNaoWalkCommand_v;
    self["NaoWalkStatus"] = kNaoWalkStatus_v;
    self["HAL_LLegTarget_Ctrl"] = kHAL_LLegTarget_Ctrl_v;
    self["HAL_LLegTarget_Stat"] = kHAL_LLegTarget_Stat_v;
    self["HAL_LLegTarget_Tolr"] = kHAL_LLegTarget_Tolr_v;
    self["HAL_RLegTarget_Ctrl"] = kHAL_RLegTarget_Ctrl_v;
    self["HAL_RLegTarget_Stat"] = kHAL_RLegTarget_Stat_v;
    self["HAL_RLegTarget_Tolr"] = kHAL_RLegTarget_Tolr_v;
    self["VisionDetectionGoals"] = kVisionDetectionGoals_v;
    self["TeleoperationControl"] = kTeleoperationControl_v;
    self["TeleoperationStatus"] = kTeleoperationStatus_v;
    self["VisionDetectionBalls"] = kVisionDetectionBalls_v;
    self["TeleoperationControlVR"] = kTeleoperationControlVR_v;
    self["ParticleOutputMap"] = kParticleOutputMap_v;
    self["ParticleOutputMapControl"] = kParticleOutputMapControl_v;
    self["FFTControl"] = kFFTControl_v;
    self["MachineFilteredNaoVision"] = kMachineFilteredNaoVision_v;
    self["MicrowaveStatus"] = kMicrowaveStatus_v;
    self["Buttons"] = kButtons_v;
    self["MachineFilteredLocalisationVision"] = kMachineFilteredLocalisationVision_v;
    self["SensorsJointCurrent"] = kSensorsJointCurrent_v;
    self["DataLogger"] = kDataLogger_v;
    self["MachineFilteredLines"] = kMachineFilteredLines_v;
    self["BallLocation"] = kBallLocation_v;
    self["LeftGoalPostLocation"] = kLeftGoalPostLocation_v;
    self["RightGoalPostLocation"] = kRightGoalPostLocation_v;
    self["GoalLocation"] = kGoalLocation_v;
    self["NaoSonarProtectedWalkCommand"] = kNaoSonarProtectedWalkCommand_v;
    self["NaoObstacleDirection"] = kNaoObstacleDirection_v;
    self["DominantFrequencies"] = kDominantFrequencies_v;
    self["MissionPriorityForObstacles"] = kMissionPriorityForObstacles_v;
    self["WavLoad"] = kWavLoad_v;
    self["WavPlay"] = kWavPlay_v;
    self["ReproduceWavNotSilent"] = kReproduceWavNotSilent_v;
    self["FrequencyControl"] = kFrequencyControl_v;
    self["FrequencyStatus"] = kFrequencyStatus_v;
    self["HeadJointSensors"] = kHeadJointSensors_v;
    self["AdjustPositionConfidence"] = kAdjustPositionConfidence_v;

    (void) self;
}
