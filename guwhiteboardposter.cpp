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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-macros"
#define WHITEBOARD_POSTER_STRING_CONVERSION
#pragma clang diagnostic pop

#include "guwhiteboardtypelist_generated.h"
#include "guwhiteboardposter.h"

using namespace std;
using namespace guWhiteboard;

extern "C"
{
    wb_types whiteboard_type_for_message_named(const char *message_type)
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
        return postmsg(wb_types(message_index), message_content);
    }

    bool whiteboard_postmsg_to(gu_simple_whiteboard_descriptor *wbd, int message_index, const char *message_content)
    {
        return postmsg(wb_types(message_index), message_content, wbd);
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

namespace guWhiteboard {

    bool post(string message_type, string message_content, gu_simple_whiteboard_descriptor *wbd)
    {
        return postmsg(types_map[message_type], message_content, wbd);
    }


    bool postmsg(wb_types message_index, std::string message_content, gu_simple_whiteboard_descriptor *wbd)
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
#ifdef guWhiteboard_GCGameState_DEFINED
    class GCGameState_t msg_ptr(wbd);
    GCGameState v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_GCGameState_DEFINED
}
case kSensorsHandSensors_v:
{
#ifdef guWhiteboard_SensorsHandSensors_DEFINED
    class SensorsHandSensors_t msg_ptr(wbd);
    SensorsHandSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SensorsHandSensors_DEFINED
}
case kSensorsHeadSensors_v:
{
#ifdef guWhiteboard_SensorsHeadSensors_DEFINED
    class SensorsHeadSensors_t msg_ptr(wbd);
    SensorsHeadSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SensorsHeadSensors_DEFINED
}
case kMOTION_Commands_v:
{
#ifdef guWhiteboard_MOTIONCommands_DEFINED
    class MOTION_Commands_t msg_ptr(wbd);
    MOTION_Commands v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MOTIONCommands_DEFINED
}
case kMOTION_Status_v:
{
#ifdef guWhiteboard_MOTIONStatus_DEFINED
    class MOTION_Status_t msg_ptr(wbd);
    MOTION_Status v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MOTIONStatus_DEFINED
}
case kHAL_HeadTarget_v:
{
#ifdef guWhiteboard_HALHeadTarget_DEFINED
    class HAL_HeadTarget_t msg_ptr(wbd);
    HAL_HeadTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HALHeadTarget_DEFINED
}
case kSensorsFootSensors_v:
{
#ifdef guWhiteboard_SensorsFootSensors_DEFINED
    class SensorsFootSensors_t msg_ptr(wbd);
    SensorsFootSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SensorsFootSensors_DEFINED
}
case kSensorsBodySensors_v:
{
#ifdef guWhiteboard_SensorsBodySensors_DEFINED
    class SensorsBodySensors_t msg_ptr(wbd);
    SensorsBodySensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SensorsBodySensors_DEFINED
}
case kSENSORSLedsSensors_v:
{
#ifdef guWhiteboard_SENSORSLedsSensors_DEFINED
    class SENSORSLedsSensors_t msg_ptr(wbd);
    SENSORSLedsSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SENSORSLedsSensors_DEFINED
}
case kSENSORSLegJointTemps_v:
{
#ifdef guWhiteboard_SENSORSLegJointTemps_DEFINED
    class SENSORSLegJointTemps_t msg_ptr(wbd);
    SENSORSLegJointTemps v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SENSORSLegJointTemps_DEFINED
}
case kSENSORSTorsoJointTemps_v:
{
#ifdef guWhiteboard_SENSORSTorsoJointTemps_DEFINED
    class SENSORSTorsoJointTemps_t msg_ptr(wbd);
    SENSORSTorsoJointTemps v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SENSORSTorsoJointTemps_DEFINED
}
case kSENSORSLegJointSensors_v:
{
#ifdef guWhiteboard_SENSORSLegJointSensors_DEFINED
    class SENSORSLegJointSensors_t msg_ptr(wbd);
    SENSORSLegJointSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SENSORSLegJointSensors_DEFINED
}
case kSENSORSTorsoJointSensors_v:
{
#ifdef guWhiteboard_SENSORSTorsoJointSensors_DEFINED
    class SENSORSTorsoJointSensors_t msg_ptr(wbd);
    SENSORSTorsoJointSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SENSORSTorsoJointSensors_DEFINED
}
case kSENSORSSonarSensors_v:
{
#ifdef guWhiteboard_SENSORSSonarSensors_DEFINED
    class SENSORSSonarSensors_t msg_ptr(wbd);
    SENSORSSonarSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SENSORSSonarSensors_DEFINED
}
case kFSM_Control_v:
{
#ifdef guWhiteboard_FSMControlStatus_DEFINED
    class FSM_Control_t msg_ptr(wbd);
    FSMControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FSMControlStatus_DEFINED
}
case kFSM_Status_v:
{
#ifdef guWhiteboard_FSMControlStatus_DEFINED
    class FSM_Status_t msg_ptr(wbd);
    FSMControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FSMControlStatus_DEFINED
}
case kFSM_Names_v:
{
#ifdef guWhiteboard_FSMNames_DEFINED
    class FSM_Names_t msg_ptr(wbd);
    FSMNames v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FSMNames_DEFINED
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
#ifdef guWhiteboard_FilteredArrayOneDimObjects_DEFINED
    class FilteredGoalSighting_t msg_ptr(wbd);
    FilteredArrayOneDimObjects v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FilteredArrayOneDimObjects_DEFINED
}
case kNAO_State_v:
{
#ifdef guWhiteboard_NAOState_DEFINED
    class NAO_State_t msg_ptr(wbd);
    NAO_State v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NAOState_DEFINED
}
case kUDPRN_v:
{
#ifdef guWhiteboard_GCGameState_DEFINED
    class UDPRN_t msg_ptr(wbd);
    GCGameState v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_GCGameState_DEFINED
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
#ifdef guWhiteboard_VisionControlStatus_DEFINED
    class VisionControl_t msg_ptr(wbd);
    VisionControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionControlStatus_DEFINED
}
case kVisionStatus_v:
{
#ifdef guWhiteboard_VisionControlStatus_DEFINED
    class VisionStatus_t msg_ptr(wbd);
    VisionControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionControlStatus_DEFINED
}
case kFFTStatus_v:
{
#ifdef guWhiteboard_FFTStatus_DEFINED
    class FFTStatus_t msg_ptr(wbd);
    FFTStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FFTStatus_DEFINED
}
case kFSOsighting_v:
{
#ifdef guWhiteboard_FilteredArrayOneDimSonar_DEFINED
    class FSOsighting_t msg_ptr(wbd);
    FilteredArrayOneDimSonar v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FilteredArrayOneDimSonar_DEFINED
}
case kTopParticles_v:
{
#ifdef guWhiteboard_TopParticles_DEFINED
    class TopParticles_t msg_ptr(wbd);
    TopParticles v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_TopParticles_DEFINED
}
case kFilteredBallSighting_v:
{
#ifdef guWhiteboard_FilteredArrayBallSightings_DEFINED
    class FilteredBallSighting_t msg_ptr(wbd);
    FilteredArrayBallSightings v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FilteredArrayBallSightings_DEFINED
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
#ifdef guWhiteboard_WEBOTSNXTBridge_DEFINED
    class WEBOTS_NXT_bridge_t msg_ptr(wbd);
    WEBOTS_NXT_bridge v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTBridge_DEFINED
}
case kWEBOTS_NXT_encoders_v:
{
#ifdef guWhiteboard_WEBOTSNXTEncoders_DEFINED
    class WEBOTS_NXT_encoders_t msg_ptr(wbd);
    WEBOTS_NXT_encoders v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTEncoders_DEFINED
}
case kWEBOTS_NXT_camera_v:
{
#ifdef guWhiteboard_WEBOTSNXTCamera_DEFINED
    class WEBOTS_NXT_camera_t msg_ptr(wbd);
    WEBOTS_NXT_camera v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTCamera_DEFINED
}
case kWEBOTS_NXT_walk_isRunning_v:
{
#ifdef guWhiteboard_WEBOTSNXTWalkIsRunning_DEFINED
    class WEBOTS_NXT_walk_isRunning_t msg_ptr(wbd);
    WEBOTS_NXT_walk_isRunning v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTWalkIsRunning_DEFINED
}
case kWEBOTS_NXT_deadReakoning_walk_v:
{
#ifdef guWhiteboard_WEBOTSNXTDeadReakoningWalk_DEFINED
    class WEBOTS_NXT_deadReakoning_walk_t msg_ptr(wbd);
    WEBOTS_NXT_deadReakoning_walk v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTDeadReakoningWalk_DEFINED
}
case kWEBOTS_NXT_colorLine_walk_v:
{
#ifdef guWhiteboard_WEBOTSNXTColorLineWalk_DEFINED
    class WEBOTS_NXT_colorLine_walk_t msg_ptr(wbd);
    WEBOTS_NXT_colorLine_walk v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTColorLineWalk_DEFINED
}
case kWEBOTS_NXT_gridMotions_v:
{
#ifdef guWhiteboard_WEBOTSNXTGridMotions_DEFINED
    class WEBOTS_NXT_gridMotions_t msg_ptr(wbd);
    WEBOTS_NXT_gridMotions v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTGridMotions_DEFINED
}
case kVisionBall_v:
{
#ifdef guWhiteboard_VisionBall_DEFINED
    class VisionBall_t msg_ptr(wbd);
    VisionBall v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionBall_DEFINED
}
case kVisionGoals_v:
{
#ifdef guWhiteboard_VisionGoals_DEFINED
    class VisionGoals_t msg_ptr(wbd);
    VisionGoals v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionGoals_DEFINED
}
case kWalkData_v:
{
#ifdef guWhiteboard_WalkData_DEFINED
    class WalkData_t msg_ptr(wbd);
    WalkData v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WalkData_DEFINED
}
case kTeleoperationControlStatus_v:
{
#ifdef guWhiteboard_TeleoperationControlStatus_DEFINED
    class TeleoperationControlStatus_t msg_ptr(wbd);
    TeleoperationControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_TeleoperationControlStatus_DEFINED
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
#ifdef guWhiteboard_WEBOTSNXTBumper_DEFINED
    class WEBOTS_NXT_bumper_t msg_ptr(wbd);
    WEBOTS_NXT_bumper v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTBumper_DEFINED
}
case kWEBOTS_NXT_vector_bridge_v:
{
#ifdef guWhiteboard_WEBOTSNXTVectorBridge_DEFINED
    class WEBOTS_NXT_vector_bridge_t msg_ptr(wbd);
    WEBOTS_NXT_vector_bridge v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_WEBOTSNXTVectorBridge_DEFINED
}
case kTopVisionLines_v:
{
#ifdef guWhiteboard_VisionLines_DEFINED
    class TopVisionLines_t msg_ptr(wbd);
    VisionLines v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionLines_DEFINED
}
case kBottomVisionLines_v:
{
#ifdef guWhiteboard_VisionLines_DEFINED
    class BottomVisionLines_t msg_ptr(wbd);
    VisionLines v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionLines_DEFINED
}
case kDifferentialRobotStatus_v:
{
#ifdef guWhiteboard_DifferentialRobotControlStatus_DEFINED
    class DifferentialRobotStatus_t msg_ptr(wbd);
    DifferentialRobotControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_DifferentialRobotControlStatus_DEFINED
}
case kDifferentialRobotControl_v:
{
#ifdef guWhiteboard_DifferentialRobotControlStatus_DEFINED
    class DifferentialRobotControl_t msg_ptr(wbd);
    DifferentialRobotControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_DifferentialRobotControlStatus_DEFINED
}
case kXEyesPos_v:
{
#ifdef guWhiteboard_Point2D_DEFINED
    class XEyesPos_t msg_ptr(wbd);
    Point2D v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Point2D_DEFINED
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
#ifdef guWhiteboard_FSMState_DEFINED
    class FSM_States_t msg_ptr(wbd);
    FSMState v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FSMState_DEFINED
}
case kGiraff_Interface_Status_v:
{
#ifdef guWhiteboard_GiraffMainSerialInterface_DEFINED
    class Giraff_Interface_Status_t msg_ptr(wbd);
    Giraff_MainSerialInterface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_GiraffMainSerialInterface_DEFINED
}
case kGiraff_Interface_Command_v:
{
#ifdef guWhiteboard_GiraffMainSerialInterface_DEFINED
    class Giraff_Interface_Command_t msg_ptr(wbd);
    Giraff_MainSerialInterface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_GiraffMainSerialInterface_DEFINED
}
case kNXT_Status_v:
{
#ifdef guWhiteboard_NXTInterface_DEFINED
    class NXT_Status_t msg_ptr(wbd);
    NXT_Interface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NXTInterface_DEFINED
}
case kNXT_Command_v:
{
#ifdef guWhiteboard_NXTInterface_DEFINED
    class NXT_Command_t msg_ptr(wbd);
    NXT_Interface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NXTInterface_DEFINED
}
case kAPM_Status_v:
{
#ifdef guWhiteboard_APMInterface_DEFINED
    class APM_Status_t msg_ptr(wbd);
    APM_Interface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_APMInterface_DEFINED
}
case kAPM_Command_v:
{
#ifdef guWhiteboard_APMInterface_DEFINED
    class APM_Command_t msg_ptr(wbd);
    APM_Interface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_APMInterface_DEFINED
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
#ifdef guWhiteboard_OculusPrimeInterface_DEFINED
    class OculusPrime_Command_t msg_ptr(wbd);
    OculusPrimeInterface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_OculusPrimeInterface_DEFINED
}
case kInput3D_v:
{
#ifdef guWhiteboard_Input3D_DEFINED
    class Input3D_t msg_ptr(wbd);
    Input3D v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Input3D_DEFINED
}
case kOculus_Prime_Command_v:
{
#ifdef guWhiteboard_OculusPrimeSerialInterface_DEFINED
    class Oculus_Prime_Command_t msg_ptr(wbd);
    Oculus_PrimeSerialInterface v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_OculusPrimeSerialInterface_DEFINED
}
case kIOPins_v:
{
#ifdef guWhiteboard_IOPins_DEFINED
    class IOPins_t msg_ptr(wbd);
    IOPins v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_IOPins_DEFINED
}
case kNXT_Two_Touch_Status_v:
{
#ifdef guWhiteboard_NXTTwoTouchStatus_DEFINED
    class NXT_Two_Touch_Status_t msg_ptr(wbd);
    NXT_Two_Touch_Status v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NXTTwoTouchStatus_DEFINED
}
case kNXT_Sound_Control_v:
{
#ifdef guWhiteboard_NXTSoundControl_DEFINED
    class NXT_Sound_Control_t msg_ptr(wbd);
    NXT_Sound_Control v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NXTSoundControl_DEFINED
}
case kNXT_Lights_Control_v:
{
#ifdef guWhiteboard_NXTLightsControl_DEFINED
    class NXT_Lights_Control_t msg_ptr(wbd);
    NXT_Lights_Control v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NXTLightsControl_DEFINED
}
case kClocks_v:
{
#ifdef guWhiteboard_Clocks_DEFINED
    class Clocks_t msg_ptr(wbd);
    Clocks v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Clocks_DEFINED
}
case kChannels_v:
{
#ifdef guWhiteboard_Channels_DEFINED
    class Channels_t msg_ptr(wbd);
    Channels v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Channels_DEFINED
}
case kSwitchSubsumption_v:
{
#ifdef guWhiteboard_SwitchSubsumption_DEFINED
    class SwitchSubsumption_t msg_ptr(wbd);
    SwitchSubsumption v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SwitchSubsumption_DEFINED
}
case kTotoDoingMotion_v:
{
#ifdef guWhiteboard_TotoDoingMotion_DEFINED
    class TotoDoingMotion_t msg_ptr(wbd);
    TotoDoingMotion v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_TotoDoingMotion_DEFINED
}
case kCount_v:
{
#ifdef guWhiteboard_Count_DEFINED
    class Count_t msg_ptr(wbd);
    Count v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Count_DEFINED
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
#ifdef guWhiteboard_SwitchSubsumptionTrafficLights_DEFINED
    class SwitchSubsumptionTrafficLights_t msg_ptr(wbd);
    SwitchSubsumptionTrafficLights v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_SwitchSubsumptionTrafficLights_DEFINED
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
#ifdef guWhiteboard_HalArmTarget_DEFINED
    class HAL_LArmTarget_Ctrl_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalArmTarget_DEFINED
}
case kHAL_LArmTarget_Stat_v:
{
#ifdef guWhiteboard_HalArmTarget_DEFINED
    class HAL_LArmTarget_Stat_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalArmTarget_DEFINED
}
case kHAL_LArmTarget_Tolr_v:
{
#ifdef guWhiteboard_HalArmTarget_DEFINED
    class HAL_LArmTarget_Tolr_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalArmTarget_DEFINED
}
case kHAL_RArmTarget_Ctrl_v:
{
#ifdef guWhiteboard_HalArmTarget_DEFINED
    class HAL_RArmTarget_Ctrl_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalArmTarget_DEFINED
}
case kHAL_RArmTarget_Stat_v:
{
#ifdef guWhiteboard_HalArmTarget_DEFINED
    class HAL_RArmTarget_Stat_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalArmTarget_DEFINED
}
case kHAL_RArmTarget_Tolr_v:
{
#ifdef guWhiteboard_HalArmTarget_DEFINED
    class HAL_RArmTarget_Tolr_t msg_ptr(wbd);
    HalArmTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalArmTarget_DEFINED
}
case kVisionFieldFeatures_v:
{
#ifdef guWhiteboard_VisionFieldFeatures_DEFINED
    class VisionFieldFeatures_t msg_ptr(wbd);
    VisionFieldFeatures v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionFieldFeatures_DEFINED
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
#ifdef guWhiteboard_VisionRobots_DEFINED
    class VisionRobots_t msg_ptr(wbd);
    VisionRobots v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionRobots_DEFINED
}
case kVisionDetectionHorizons_v:
{
#ifdef guWhiteboard_VisionDetectionHorizons_DEFINED
    class VisionDetectionHorizons_t msg_ptr(wbd);
    VisionDetectionHorizons v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionDetectionHorizons_DEFINED
}
case kNaoWalkCommand_v:
{
#ifdef guWhiteboard_NaoWalkCommand_DEFINED
    class NaoWalkCommand_t msg_ptr(wbd);
    NaoWalkCommand v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NaoWalkCommand_DEFINED
}
case kNaoWalkStatus_v:
{
#ifdef guWhiteboard_NaoWalkStatus_DEFINED
    class NaoWalkStatus_t msg_ptr(wbd);
    NaoWalkStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NaoWalkStatus_DEFINED
}
case kHAL_LLegTarget_Ctrl_v:
{
#ifdef guWhiteboard_HalLegTarget_DEFINED
    class HAL_LLegTarget_Ctrl_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalLegTarget_DEFINED
}
case kHAL_LLegTarget_Stat_v:
{
#ifdef guWhiteboard_HalLegTarget_DEFINED
    class HAL_LLegTarget_Stat_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalLegTarget_DEFINED
}
case kHAL_LLegTarget_Tolr_v:
{
#ifdef guWhiteboard_HalLegTarget_DEFINED
    class HAL_LLegTarget_Tolr_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalLegTarget_DEFINED
}
case kHAL_RLegTarget_Ctrl_v:
{
#ifdef guWhiteboard_HalLegTarget_DEFINED
    class HAL_RLegTarget_Ctrl_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalLegTarget_DEFINED
}
case kHAL_RLegTarget_Stat_v:
{
#ifdef guWhiteboard_HalLegTarget_DEFINED
    class HAL_RLegTarget_Stat_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalLegTarget_DEFINED
}
case kHAL_RLegTarget_Tolr_v:
{
#ifdef guWhiteboard_HalLegTarget_DEFINED
    class HAL_RLegTarget_Tolr_t msg_ptr(wbd);
    HalLegTarget v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HalLegTarget_DEFINED
}
case kVisionDetectionGoals_v:
{
#ifdef guWhiteboard_VisionDetectionGoals_DEFINED
    class VisionDetectionGoals_t msg_ptr(wbd);
    VisionDetectionGoals v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionDetectionGoals_DEFINED
}
case kTeleoperationControl_v:
{
#ifdef guWhiteboard_TeleoperationControl_DEFINED
    class TeleoperationControl_t msg_ptr(wbd);
    TeleoperationControl v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_TeleoperationControl_DEFINED
}
case kTeleoperationStatus_v:
{
#ifdef guWhiteboard_TeleoperationStatus_DEFINED
    class TeleoperationStatus_t msg_ptr(wbd);
    TeleoperationStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_TeleoperationStatus_DEFINED
}
case kVisionDetectionBalls_v:
{
#ifdef guWhiteboard_VisionDetectionBalls_DEFINED
    class VisionDetectionBalls_t msg_ptr(wbd);
    VisionDetectionBalls v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionDetectionBalls_DEFINED
}
case kTeleoperationControlVR_v:
{
#ifdef guWhiteboard_TeleoperationControlVR_DEFINED
    class TeleoperationControlVR_t msg_ptr(wbd);
    TeleoperationControlVR v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_TeleoperationControlVR_DEFINED
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
#ifdef guWhiteboard_MachineFilteredVision_DEFINED
    class MachineFilteredNaoVision_t msg_ptr(wbd);
    MachineFilteredVision v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MachineFilteredVision_DEFINED
}
case kMicrowaveStatus_v:
{
#ifdef guWhiteboard_MicrowaveStatus_DEFINED
    class MicrowaveStatus_t msg_ptr(wbd);
    MicrowaveStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MicrowaveStatus_DEFINED
}
case kButtons_v:
{
#ifdef guWhiteboard_Buttons_DEFINED
    class Buttons_t msg_ptr(wbd);
    Buttons v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Buttons_DEFINED
}
case kMachineFilteredLocalisationVision_v:
{
#ifdef guWhiteboard_MachineFilteredLocalisationVision_DEFINED
    class MachineFilteredLocalisationVision_t msg_ptr(wbd);
    MachineFilteredLocalisationVision v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MachineFilteredLocalisationVision_DEFINED
}
case kSensorsJointCurrent_v:
{
#ifdef guWhiteboard_NaoJointListFloat_DEFINED
    class SensorsJointCurrent_t msg_ptr(wbd);
    NaoJointListFloat v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NaoJointListFloat_DEFINED
}
case kDataLogger_v:
{
#ifdef guWhiteboard_DataLogger_DEFINED
    class DataLogger_t msg_ptr(wbd);
    DataLogger v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_DataLogger_DEFINED
}
case kMachineFilteredLines_v:
{
#ifdef guWhiteboard_MachineFilteredLines_DEFINED
    class MachineFilteredLines_t msg_ptr(wbd);
    MachineFilteredLines v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MachineFilteredLines_DEFINED
}
case kBallLocation_v:
{
#ifdef guWhiteboard_Location_DEFINED
    class BallLocation_t msg_ptr(wbd);
    Location v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Location_DEFINED
}
case kLeftGoalPostLocation_v:
{
#ifdef guWhiteboard_Location_DEFINED
    class LeftGoalPostLocation_t msg_ptr(wbd);
    Location v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Location_DEFINED
}
case kRightGoalPostLocation_v:
{
#ifdef guWhiteboard_Location_DEFINED
    class RightGoalPostLocation_t msg_ptr(wbd);
    Location v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Location_DEFINED
}
case kGoalLocation_v:
{
#ifdef guWhiteboard_Location_DEFINED
    class GoalLocation_t msg_ptr(wbd);
    Location v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Location_DEFINED
}
case kNaoSonarProtectedWalkCommand_v:
{
#ifdef guWhiteboard_NaoSonarProtectedWalkCommand_DEFINED
    class NaoSonarProtectedWalkCommand_t msg_ptr(wbd);
    NaoSonarProtectedWalkCommand v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NaoSonarProtectedWalkCommand_DEFINED
}
case kNaoObstacleDirection_v:
{
#ifdef guWhiteboard_NaoObstacleDirection_DEFINED
    class NaoObstacleDirection_t msg_ptr(wbd);
    NaoObstacleDirection v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_NaoObstacleDirection_DEFINED
}
case kDominantFrequencies_v:
{
#ifdef guWhiteboard_DominantFrequencies_DEFINED
    class DominantFrequencies_t msg_ptr(wbd);
    DominantFrequencies v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_DominantFrequencies_DEFINED
}
case kMissionPriorityForObstacles_v:
{
#ifdef guWhiteboard_MissionPriorityForObstacles_DEFINED
    class MissionPriorityForObstacles_t msg_ptr(wbd);
    MissionPriorityForObstacles v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MissionPriorityForObstacles_DEFINED
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
#ifdef guWhiteboard_FrequencyLimits_DEFINED
    class FrequencyControl_t msg_ptr(wbd);
    FrequencyLimits v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FrequencyLimits_DEFINED
}
case kFrequencyStatus_v:
{
#ifdef guWhiteboard_FrequencyLimits_DEFINED
    class FrequencyStatus_t msg_ptr(wbd);
    FrequencyLimits v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_FrequencyLimits_DEFINED
}
case kHeadJointSensors_v:
{
#ifdef guWhiteboard_HeadJointSensors_DEFINED
    class HeadJointSensors_t msg_ptr(wbd);
    HeadJointSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_HeadJointSensors_DEFINED
}
case kAdjustPositionConfidence_v:
{
#ifdef guWhiteboard_AdjustPositionConfidence_DEFINED
    class AdjustPositionConfidence_t msg_ptr(wbd);
    AdjustPositionConfidence v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_AdjustPositionConfidence_DEFINED
}
case kGuVrTeleopVulkanControl_v:
{
#ifdef guWhiteboard_GuVrTeleopVulkanControl_DEFINED
    class GuVrTeleopVulkanControl_t msg_ptr(wbd);
    GuVrTeleopVulkanControl v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_GuVrTeleopVulkanControl_DEFINED
}
case kTemperatureSensors_v:
{
#ifdef guWhiteboard_TemperatureSensors_DEFINED
    class TemperatureSensors_t msg_ptr(wbd);
    TemperatureSensors v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_TemperatureSensors_DEFINED
}
case kOverheating_v:
{
#ifdef guWhiteboard_Overheating_DEFINED
    class Overheating_t msg_ptr(wbd);
    Overheating v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_Overheating_DEFINED
}
case kbuttonPushed_v:
{

    class buttonPushed_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kdoorOpen_v:
{

    class doorOpen_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case ktimeLeft_v:
{

    class timeLeft_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kmotor_v:
{

    class motor_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case ksound_v:
{

    class sound_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case klight_v:
{

    class light_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino2Pin_v:
{

    class Arduino2Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino2PinValue_v:
{

    class Arduino2PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino3Pin_v:
{

    class Arduino3Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino3PinValue_v:
{

    class Arduino3PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino4Pin_v:
{

    class Arduino4Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino4PinValue_v:
{

    class Arduino4PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino5Pin_v:
{

    class Arduino5Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino5PinValue_v:
{

    class Arduino5PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino6Pin_v:
{

    class Arduino6Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino6PinValue_v:
{

    class Arduino6PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino7Pin_v:
{

    class Arduino7Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino7PinValue_v:
{

    class Arduino7PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino8Pin_v:
{

    class Arduino8Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino8PinValue_v:
{

    class Arduino8PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino9Pin_v:
{

    class Arduino9Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kArduino9PinValue_v:
{

    class Arduino9PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kBallPosition_v:
{
#ifdef guWhiteboard_BallPosition_DEFINED
    class BallPosition_t msg_ptr(wbd);
    BallPosition v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_BallPosition_DEFINED
}
case kMemoryImageControl_v:
{
#ifdef guWhiteboard_MemoryImageControlStatus_DEFINED
    class MemoryImageControl_t msg_ptr(wbd);
    MemoryImageControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MemoryImageControlStatus_DEFINED
}
case kMemoryImageStatus_v:
{
#ifdef guWhiteboard_MemoryImageControlStatus_DEFINED
    class MemoryImageStatus_t msg_ptr(wbd);
    MemoryImageControlStatus v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MemoryImageControlStatus_DEFINED
}
case kLHandGripper_v:
{

    class LHandGripper_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kRHandGripper_v:
{

    class RHandGripper_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kMyPosition_v:
{
#ifdef guWhiteboard_MyPosition_DEFINED
    class MyPosition_t msg_ptr(wbd);
    MyPosition v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_MyPosition_DEFINED
}
case kVisionDetectionLines_v:
{
#ifdef guWhiteboard_VisionDetectionLines_DEFINED
    class VisionDetectionLines_t msg_ptr(wbd);
    VisionDetectionLines v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionDetectionLines_DEFINED
}
case kVisionDetectionFeatures_v:
{
#ifdef guWhiteboard_VisionDetectionFeatures_DEFINED
    class VisionDetectionFeatures_t msg_ptr(wbd);
    VisionDetectionFeatures v = msg_ptr.get();
v.from_string(message_content);
    msg_ptr.post(v);
    return true;
#else
    return false;
#endif //guWhiteboard_VisionDetectionFeatures_DEFINED
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
        (void) message_content;
    }

    return false;
#pragma clang diagnostic pop
    }
}

whiteboard_types_map::whiteboard_types_map(): map<string, wb_types>()
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
    self["TopVisionLines"] = kTopVisionLines_v;
    self["BottomVisionLines"] = kBottomVisionLines_v;
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
    self["GuVrTeleopVulkanControl"] = kGuVrTeleopVulkanControl_v;
    self["TemperatureSensors"] = kTemperatureSensors_v;
    self["Overheating"] = kOverheating_v;
    self["buttonPushed"] = kbuttonPushed_v;
    self["doorOpen"] = kdoorOpen_v;
    self["timeLeft"] = ktimeLeft_v;
    self["motor"] = kmotor_v;
    self["sound"] = ksound_v;
    self["light"] = klight_v;
    self["Arduino2Pin"] = kArduino2Pin_v;
    self["Arduino2PinValue"] = kArduino2PinValue_v;
    self["Arduino3Pin"] = kArduino3Pin_v;
    self["Arduino3PinValue"] = kArduino3PinValue_v;
    self["Arduino4Pin"] = kArduino4Pin_v;
    self["Arduino4PinValue"] = kArduino4PinValue_v;
    self["Arduino5Pin"] = kArduino5Pin_v;
    self["Arduino5PinValue"] = kArduino5PinValue_v;
    self["Arduino6Pin"] = kArduino6Pin_v;
    self["Arduino6PinValue"] = kArduino6PinValue_v;
    self["Arduino7Pin"] = kArduino7Pin_v;
    self["Arduino7PinValue"] = kArduino7PinValue_v;
    self["Arduino8Pin"] = kArduino8Pin_v;
    self["Arduino8PinValue"] = kArduino8PinValue_v;
    self["Arduino9Pin"] = kArduino9Pin_v;
    self["Arduino9PinValue"] = kArduino9PinValue_v;
    self["BallPosition"] = kBallPosition_v;
    self["MemoryImageControl"] = kMemoryImageControl_v;
    self["MemoryImageStatus"] = kMemoryImageStatus_v;
    self["LHandGripper"] = kLHandGripper_v;
    self["RHandGripper"] = kRHandGripper_v;
    self["MyPosition"] = kMyPosition_v;
    self["VisionDetectionLines"] = kVisionDetectionLines_v;
    self["VisionDetectionFeatures"] = kVisionDetectionFeatures_v;

    (void) self;
} // guWhiteboard

