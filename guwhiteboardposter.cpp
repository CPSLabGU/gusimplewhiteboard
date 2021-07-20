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

case kwb_wb_reserved_SubscribeToAllTypes_v:
{

    class wb_reserved_SubscribeToAllTypes_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Print_v:
{

    class Print_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kwb_Say_v:
{

    class Say_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kwb_Speech_v:
{

    class Speech_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kwb_QSay_v:
{

    class QSay_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kwb_QSpeech_v:
{

    class QSpeech_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kwb_SpeechOutput_v:
{

    class SpeechOutput_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_GCGameState_v:
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
case kwb_SensorsHandSensors_v:
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
case kwb_SensorsHeadSensors_v:
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
case kwb_MOTION_Commands_v:
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
case kwb_MOTION_Status_v:
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
case kwb_HAL_HeadTarget_v:
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
case kwb_SensorsFootSensors_v:
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
case kwb_SensorsBodySensors_v:
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
case kwb_SENSORSLedsSensors_v:
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
case kwb_SENSORSLegJointTemps_v:
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
case kwb_SENSORSTorsoJointTemps_v:
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
case kwb_SENSORSLegJointSensors_v:
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
case kwb_SENSORSTorsoJointSensors_v:
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
case kwb_SENSORSSonarSensors_v:
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
case kwb_FSM_Control_v:
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
case kwb_FSM_Status_v:
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
case kwb_FSM_Names_v:
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
case kwb_SoloTypeExample_v:
{

    class SoloTypeExample_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_FilteredGoalSighting_v:
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
case kwb_NAO_State_v:
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
case kwb_UDPRN_v:
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
case kwb_PlayerNumber_v:
{

    class PlayerNumber_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_ManuallyPenalized_v:
{

    class ManuallyPenalized_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_VisionControl_v:
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
case kwb_VisionStatus_v:
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
case kwb_FFTStatus_v:
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
case kwb_FSOsighting_v:
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
case kwb_TopParticles_v:
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
case kwb_FilteredBallSighting_v:
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
case kwb_PF_ControlStatus_Modes_v:
{

    class PF_ControlStatus_Modes_t msg_ptr(wbd);
    int32_t v = static_cast<int32_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_WEBOTS_NXT_bridge_v:
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
case kwb_WEBOTS_NXT_encoders_v:
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
case kwb_WEBOTS_NXT_camera_v:
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
case kwb_WEBOTS_NXT_walk_isRunning_v:
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
case kwb_WEBOTS_NXT_deadReakoning_walk_v:
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
case kwb_WEBOTS_NXT_colorLine_walk_v:
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
case kwb_WEBOTS_NXT_gridMotions_v:
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
case kwb_VisionBall_v:
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
case kwb_VisionGoals_v:
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
case kwb_WalkData_v:
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
case kwb_TeleoperationControlStatus_v:
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
case kwb_TeleoperationConnection_v:
{

    class TeleoperationConnection_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_UDPWBNumber_v:
{

    class UDPWBNumber_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_WEBOTS_NXT_bumper_v:
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
case kwb_WEBOTS_NXT_vector_bridge_v:
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
case kwb_TopVisionLines_v:
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
case kwb_BottomVisionLines_v:
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
case kwb_DifferentialRobotStatus_v:
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
case kwb_DifferentialRobotControl_v:
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
case kwb_XEyesPos_v:
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
case kwb_VisionFace_v:
{

    class VisionFace_t msg_ptr(wbd);
    std::vector<int> v = strtointvec(message_content);
    msg_ptr.post(v);
    return true;

}
case kwb_Draw_v:
{

    class Draw_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kwb_FSM_States_v:
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
case kwb_Giraff_Interface_Status_v:
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
case kwb_Giraff_Interface_Command_v:
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
case kwb_NXT_Status_v:
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
case kwb_NXT_Command_v:
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
case kwb_APM_Status_v:
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
case kwb_APM_Command_v:
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
case kwb_REMOVED3_v:
{

    class REMOVED3_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_REMOVED4_v:
{

    class REMOVED4_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_CBall_v:
{

    class CBall_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_OculusPrime_Command_v:
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
case kwb_Input3D_v:
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
case kwb_Oculus_Prime_Command_v:
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
case kwb_IOPins_v:
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
case kwb_NXT_Two_Touch_Status_v:
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
case kwb_NXT_Sound_Control_v:
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
case kwb_NXT_Lights_Control_v:
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
case kwb_Clocks_v:
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
case kwb_Channels_v:
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
case kwb_SwitchSubsumption_v:
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
case kwb_TotoDoingMotion_v:
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
case kwb_Count_v:
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
case kwb_GreenEWon_v:
{

    class GreenEWon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_WarnEW_v:
{

    class WarnEW_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_TimeGTthirty_v:
{

    class TimeGTthirty_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_AmberEWon_v:
{

    class AmberEWon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_TurnRedEW_v:
{

    class TurnRedEW_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_TimeGTfive_v:
{

    class TimeGTfive_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_RedEWon_v:
{

    class RedEWon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_GreenNSon_v:
{

    class GreenNSon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_WarnNS_v:
{

    class WarnNS_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_AmberNSon_v:
{

    class AmberNSon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_TurnRedNS_v:
{

    class TurnRedNS_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_RedNSon_v:
{

    class RedNSon_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_TimerReset_v:
{

    class TimerReset_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_SLOT_UNUSED_v:
{

    class SLOT_UNUSED_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_CarSensorPressed_v:
{

    class CarSensorPressed_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_SwitchSubsumptionTrafficLights_v:
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
case kwb_Ball_Found_v:
{

    class Ball_Found_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Ball_Calibration_File_v:
{

    class Ball_Calibration_File_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kwb_Ball_Calibration_Num_v:
{

    class Ball_Calibration_Num_t msg_ptr(wbd);
    int32_t v = static_cast<int32_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Ball_Color_Num_v:
{

    class Ball_Color_Num_t msg_ptr(wbd);
    int32_t v = static_cast<int32_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_HAL_LArmTarget_Ctrl_v:
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
case kwb_HAL_LArmTarget_Stat_v:
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
case kwb_HAL_LArmTarget_Tolr_v:
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
case kwb_HAL_RArmTarget_Ctrl_v:
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
case kwb_HAL_RArmTarget_Stat_v:
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
case kwb_HAL_RArmTarget_Tolr_v:
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
case kwb_VisionFieldFeatures_v:
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
case kwb_WhistleBlown_v:
{

    class WhistleBlown_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_VolumeControl_v:
{

    class VolumeControl_t msg_ptr(wbd);
    uint8_t v = static_cast<uint8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_VisionRobots_v:
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
case kwb_VisionDetectionHorizons_v:
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
case kwb_NaoWalkCommand_v:
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
case kwb_NaoWalkStatus_v:
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
case kwb_HAL_LLegTarget_Ctrl_v:
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
case kwb_HAL_LLegTarget_Stat_v:
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
case kwb_HAL_LLegTarget_Tolr_v:
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
case kwb_HAL_RLegTarget_Ctrl_v:
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
case kwb_HAL_RLegTarget_Stat_v:
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
case kwb_HAL_RLegTarget_Tolr_v:
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
case kwb_VisionDetectionGoals_v:
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
case kwb_TeleoperationControl_v:
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
case kwb_TeleoperationStatus_v:
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
case kwb_VisionDetectionBalls_v:
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
case kwb_TeleoperationControlVR_v:
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
case kwb_ParticleOutputMap_v:
{

    class ParticleOutputMap_t msg_ptr(wbd);
    uint64_t v = static_cast<uint64_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_ParticleOutputMapControl_v:
{

    class ParticleOutputMapControl_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_FFTControl_v:
{

    class FFTControl_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_MachineFilteredNaoVision_v:
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
case kwb_MicrowaveStatus_v:
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
case kwb_Buttons_v:
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
case kwb_MachineFilteredLocalisationVision_v:
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
case kwb_SensorsJointCurrent_v:
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
case kwb_DataLogger_v:
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
case kwb_MachineFilteredLines_v:
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
case kwb_BallLocation_v:
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
case kwb_LeftGoalPostLocation_v:
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
case kwb_RightGoalPostLocation_v:
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
case kwb_GoalLocation_v:
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
case kwb_NaoSonarProtectedWalkCommand_v:
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
case kwb_NaoObstacleDirection_v:
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
case kwb_DominantFrequencies_v:
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
case kwb_MissionPriorityForObstacles_v:
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
case kwb_WavLoad_v:
{

    class WavLoad_t msg_ptr(wbd);
    std::string v = message_content;
    msg_ptr.post(v);
    return true;

}
case kwb_WavPlay_v:
{

    class WavPlay_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_ReproduceWavNotSilent_v:
{

    class ReproduceWavNotSilent_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_FrequencyControl_v:
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
case kwb_FrequencyStatus_v:
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
case kwb_HeadJointSensors_v:
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
case kwb_AdjustPositionConfidence_v:
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
case kwb_GuVrTeleopVulkanControl_v:
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
case kwb_TemperatureSensors_v:
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
case kwb_Overheating_v:
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
case kwb_buttonPushed_v:
{

    class buttonPushed_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_doorOpen_v:
{

    class doorOpen_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_timeLeft_v:
{

    class timeLeft_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_motor_v:
{

    class motor_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_sound_v:
{

    class sound_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_light_v:
{

    class light_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino2Pin_v:
{

    class Arduino2Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino2PinValue_v:
{

    class Arduino2PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino3Pin_v:
{

    class Arduino3Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino3PinValue_v:
{

    class Arduino3PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino4Pin_v:
{

    class Arduino4Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino4PinValue_v:
{

    class Arduino4PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino5Pin_v:
{

    class Arduino5Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino5PinValue_v:
{

    class Arduino5PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino6Pin_v:
{

    class Arduino6Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino6PinValue_v:
{

    class Arduino6PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino7Pin_v:
{

    class Arduino7Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino7PinValue_v:
{

    class Arduino7PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino8Pin_v:
{

    class Arduino8Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino8PinValue_v:
{

    class Arduino8PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino9Pin_v:
{

    class Arduino9Pin_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_Arduino9PinValue_v:
{

    class Arduino9PinValue_t msg_ptr(wbd);
    bool v = static_cast<bool>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_BallPosition_v:
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
case kwb_MemoryImageControl_v:
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
case kwb_MemoryImageStatus_v:
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
case kwb_LHandGripper_v:
{

    class LHandGripper_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_RHandGripper_v:
{

    class RHandGripper_t msg_ptr(wbd);
    int8_t v = static_cast<int8_t>(atoi(message_content.c_str()));
    msg_ptr.post(v);
    return true;

}
case kwb_MyPosition_v:
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
case kwb_VisionDetectionLines_v:
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
case kwb_VisionDetectionFeatures_v:
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

    self["wb_reserved_SubscribeToAllTypes"] = kwb_wb_reserved_SubscribeToAllTypes_v;
    self["Print"] = kwb_Print_v;
    self["Say"] = kwb_Say_v;
    self["Speech"] = kwb_Speech_v;
    self["QSay"] = kwb_QSay_v;
    self["QSpeech"] = kwb_QSpeech_v;
    self["SpeechOutput"] = kwb_SpeechOutput_v;
    self["GCGameState"] = kwb_GCGameState_v;
    self["SensorsHandSensors"] = kwb_SensorsHandSensors_v;
    self["SensorsHeadSensors"] = kwb_SensorsHeadSensors_v;
    self["MOTION_Commands"] = kwb_MOTION_Commands_v;
    self["MOTION_Status"] = kwb_MOTION_Status_v;
    self["HAL_HeadTarget"] = kwb_HAL_HeadTarget_v;
    self["SensorsFootSensors"] = kwb_SensorsFootSensors_v;
    self["SensorsBodySensors"] = kwb_SensorsBodySensors_v;
    self["SENSORSLedsSensors"] = kwb_SENSORSLedsSensors_v;
    self["SENSORSLegJointTemps"] = kwb_SENSORSLegJointTemps_v;
    self["SENSORSTorsoJointTemps"] = kwb_SENSORSTorsoJointTemps_v;
    self["SENSORSLegJointSensors"] = kwb_SENSORSLegJointSensors_v;
    self["SENSORSTorsoJointSensors"] = kwb_SENSORSTorsoJointSensors_v;
    self["SENSORSSonarSensors"] = kwb_SENSORSSonarSensors_v;
    self["FSM_Control"] = kwb_FSM_Control_v;
    self["FSM_Status"] = kwb_FSM_Status_v;
    self["FSM_Names"] = kwb_FSM_Names_v;
    self["SoloTypeExample"] = kwb_SoloTypeExample_v;
    self["FilteredGoalSighting"] = kwb_FilteredGoalSighting_v;
    self["NAO_State"] = kwb_NAO_State_v;
    self["UDPRN"] = kwb_UDPRN_v;
    self["PlayerNumber"] = kwb_PlayerNumber_v;
    self["ManuallyPenalized"] = kwb_ManuallyPenalized_v;
    self["VisionControl"] = kwb_VisionControl_v;
    self["VisionStatus"] = kwb_VisionStatus_v;
    self["FFTStatus"] = kwb_FFTStatus_v;
    self["FSOsighting"] = kwb_FSOsighting_v;
    self["TopParticles"] = kwb_TopParticles_v;
    self["FilteredBallSighting"] = kwb_FilteredBallSighting_v;
    self["PF_ControlStatus_Modes"] = kwb_PF_ControlStatus_Modes_v;
    self["WEBOTS_NXT_bridge"] = kwb_WEBOTS_NXT_bridge_v;
    self["WEBOTS_NXT_encoders"] = kwb_WEBOTS_NXT_encoders_v;
    self["WEBOTS_NXT_camera"] = kwb_WEBOTS_NXT_camera_v;
    self["WEBOTS_NXT_walk_isRunning"] = kwb_WEBOTS_NXT_walk_isRunning_v;
    self["WEBOTS_NXT_deadReakoning_walk"] = kwb_WEBOTS_NXT_deadReakoning_walk_v;
    self["WEBOTS_NXT_colorLine_walk"] = kwb_WEBOTS_NXT_colorLine_walk_v;
    self["WEBOTS_NXT_gridMotions"] = kwb_WEBOTS_NXT_gridMotions_v;
    self["VisionBall"] = kwb_VisionBall_v;
    self["VisionGoals"] = kwb_VisionGoals_v;
    self["WalkData"] = kwb_WalkData_v;
    self["TeleoperationControlStatus"] = kwb_TeleoperationControlStatus_v;
    self["TeleoperationConnection"] = kwb_TeleoperationConnection_v;
    self["UDPWBNumber"] = kwb_UDPWBNumber_v;
    self["WEBOTS_NXT_bumper"] = kwb_WEBOTS_NXT_bumper_v;
    self["WEBOTS_NXT_vector_bridge"] = kwb_WEBOTS_NXT_vector_bridge_v;
    self["TopVisionLines"] = kwb_TopVisionLines_v;
    self["BottomVisionLines"] = kwb_BottomVisionLines_v;
    self["DifferentialRobotStatus"] = kwb_DifferentialRobotStatus_v;
    self["DifferentialRobotControl"] = kwb_DifferentialRobotControl_v;
    self["XEyesPos"] = kwb_XEyesPos_v;
    self["VisionFace"] = kwb_VisionFace_v;
    self["Draw"] = kwb_Draw_v;
    self["FSM_States"] = kwb_FSM_States_v;
    self["Giraff_Interface_Status"] = kwb_Giraff_Interface_Status_v;
    self["Giraff_Interface_Command"] = kwb_Giraff_Interface_Command_v;
    self["NXT_Status"] = kwb_NXT_Status_v;
    self["NXT_Command"] = kwb_NXT_Command_v;
    self["APM_Status"] = kwb_APM_Status_v;
    self["APM_Command"] = kwb_APM_Command_v;
    self["REMOVED3"] = kwb_REMOVED3_v;
    self["REMOVED4"] = kwb_REMOVED4_v;
    self["CBall"] = kwb_CBall_v;
    self["OculusPrime_Command"] = kwb_OculusPrime_Command_v;
    self["Input3D"] = kwb_Input3D_v;
    self["Oculus_Prime_Command"] = kwb_Oculus_Prime_Command_v;
    self["IOPins"] = kwb_IOPins_v;
    self["NXT_Two_Touch_Status"] = kwb_NXT_Two_Touch_Status_v;
    self["NXT_Sound_Control"] = kwb_NXT_Sound_Control_v;
    self["NXT_Lights_Control"] = kwb_NXT_Lights_Control_v;
    self["Clocks"] = kwb_Clocks_v;
    self["Channels"] = kwb_Channels_v;
    self["SwitchSubsumption"] = kwb_SwitchSubsumption_v;
    self["TotoDoingMotion"] = kwb_TotoDoingMotion_v;
    self["Count"] = kwb_Count_v;
    self["GreenEWon"] = kwb_GreenEWon_v;
    self["WarnEW"] = kwb_WarnEW_v;
    self["TimeGTthirty"] = kwb_TimeGTthirty_v;
    self["AmberEWon"] = kwb_AmberEWon_v;
    self["TurnRedEW"] = kwb_TurnRedEW_v;
    self["TimeGTfive"] = kwb_TimeGTfive_v;
    self["RedEWon"] = kwb_RedEWon_v;
    self["GreenNSon"] = kwb_GreenNSon_v;
    self["WarnNS"] = kwb_WarnNS_v;
    self["AmberNSon"] = kwb_AmberNSon_v;
    self["TurnRedNS"] = kwb_TurnRedNS_v;
    self["RedNSon"] = kwb_RedNSon_v;
    self["TimerReset"] = kwb_TimerReset_v;
    self["SLOT_UNUSED"] = kwb_SLOT_UNUSED_v;
    self["CarSensorPressed"] = kwb_CarSensorPressed_v;
    self["SwitchSubsumptionTrafficLights"] = kwb_SwitchSubsumptionTrafficLights_v;
    self["Ball_Found"] = kwb_Ball_Found_v;
    self["Ball_Calibration_File"] = kwb_Ball_Calibration_File_v;
    self["Ball_Calibration_Num"] = kwb_Ball_Calibration_Num_v;
    self["Ball_Color_Num"] = kwb_Ball_Color_Num_v;
    self["HAL_LArmTarget_Ctrl"] = kwb_HAL_LArmTarget_Ctrl_v;
    self["HAL_LArmTarget_Stat"] = kwb_HAL_LArmTarget_Stat_v;
    self["HAL_LArmTarget_Tolr"] = kwb_HAL_LArmTarget_Tolr_v;
    self["HAL_RArmTarget_Ctrl"] = kwb_HAL_RArmTarget_Ctrl_v;
    self["HAL_RArmTarget_Stat"] = kwb_HAL_RArmTarget_Stat_v;
    self["HAL_RArmTarget_Tolr"] = kwb_HAL_RArmTarget_Tolr_v;
    self["VisionFieldFeatures"] = kwb_VisionFieldFeatures_v;
    self["WhistleBlown"] = kwb_WhistleBlown_v;
    self["VolumeControl"] = kwb_VolumeControl_v;
    self["VisionRobots"] = kwb_VisionRobots_v;
    self["VisionDetectionHorizons"] = kwb_VisionDetectionHorizons_v;
    self["NaoWalkCommand"] = kwb_NaoWalkCommand_v;
    self["NaoWalkStatus"] = kwb_NaoWalkStatus_v;
    self["HAL_LLegTarget_Ctrl"] = kwb_HAL_LLegTarget_Ctrl_v;
    self["HAL_LLegTarget_Stat"] = kwb_HAL_LLegTarget_Stat_v;
    self["HAL_LLegTarget_Tolr"] = kwb_HAL_LLegTarget_Tolr_v;
    self["HAL_RLegTarget_Ctrl"] = kwb_HAL_RLegTarget_Ctrl_v;
    self["HAL_RLegTarget_Stat"] = kwb_HAL_RLegTarget_Stat_v;
    self["HAL_RLegTarget_Tolr"] = kwb_HAL_RLegTarget_Tolr_v;
    self["VisionDetectionGoals"] = kwb_VisionDetectionGoals_v;
    self["TeleoperationControl"] = kwb_TeleoperationControl_v;
    self["TeleoperationStatus"] = kwb_TeleoperationStatus_v;
    self["VisionDetectionBalls"] = kwb_VisionDetectionBalls_v;
    self["TeleoperationControlVR"] = kwb_TeleoperationControlVR_v;
    self["ParticleOutputMap"] = kwb_ParticleOutputMap_v;
    self["ParticleOutputMapControl"] = kwb_ParticleOutputMapControl_v;
    self["FFTControl"] = kwb_FFTControl_v;
    self["MachineFilteredNaoVision"] = kwb_MachineFilteredNaoVision_v;
    self["MicrowaveStatus"] = kwb_MicrowaveStatus_v;
    self["Buttons"] = kwb_Buttons_v;
    self["MachineFilteredLocalisationVision"] = kwb_MachineFilteredLocalisationVision_v;
    self["SensorsJointCurrent"] = kwb_SensorsJointCurrent_v;
    self["DataLogger"] = kwb_DataLogger_v;
    self["MachineFilteredLines"] = kwb_MachineFilteredLines_v;
    self["BallLocation"] = kwb_BallLocation_v;
    self["LeftGoalPostLocation"] = kwb_LeftGoalPostLocation_v;
    self["RightGoalPostLocation"] = kwb_RightGoalPostLocation_v;
    self["GoalLocation"] = kwb_GoalLocation_v;
    self["NaoSonarProtectedWalkCommand"] = kwb_NaoSonarProtectedWalkCommand_v;
    self["NaoObstacleDirection"] = kwb_NaoObstacleDirection_v;
    self["DominantFrequencies"] = kwb_DominantFrequencies_v;
    self["MissionPriorityForObstacles"] = kwb_MissionPriorityForObstacles_v;
    self["WavLoad"] = kwb_WavLoad_v;
    self["WavPlay"] = kwb_WavPlay_v;
    self["ReproduceWavNotSilent"] = kwb_ReproduceWavNotSilent_v;
    self["FrequencyControl"] = kwb_FrequencyControl_v;
    self["FrequencyStatus"] = kwb_FrequencyStatus_v;
    self["HeadJointSensors"] = kwb_HeadJointSensors_v;
    self["AdjustPositionConfidence"] = kwb_AdjustPositionConfidence_v;
    self["GuVrTeleopVulkanControl"] = kwb_GuVrTeleopVulkanControl_v;
    self["TemperatureSensors"] = kwb_TemperatureSensors_v;
    self["Overheating"] = kwb_Overheating_v;
    self["buttonPushed"] = kwb_buttonPushed_v;
    self["doorOpen"] = kwb_doorOpen_v;
    self["timeLeft"] = kwb_timeLeft_v;
    self["motor"] = kwb_motor_v;
    self["sound"] = kwb_sound_v;
    self["light"] = kwb_light_v;
    self["Arduino2Pin"] = kwb_Arduino2Pin_v;
    self["Arduino2PinValue"] = kwb_Arduino2PinValue_v;
    self["Arduino3Pin"] = kwb_Arduino3Pin_v;
    self["Arduino3PinValue"] = kwb_Arduino3PinValue_v;
    self["Arduino4Pin"] = kwb_Arduino4Pin_v;
    self["Arduino4PinValue"] = kwb_Arduino4PinValue_v;
    self["Arduino5Pin"] = kwb_Arduino5Pin_v;
    self["Arduino5PinValue"] = kwb_Arduino5PinValue_v;
    self["Arduino6Pin"] = kwb_Arduino6Pin_v;
    self["Arduino6PinValue"] = kwb_Arduino6PinValue_v;
    self["Arduino7Pin"] = kwb_Arduino7Pin_v;
    self["Arduino7PinValue"] = kwb_Arduino7PinValue_v;
    self["Arduino8Pin"] = kwb_Arduino8Pin_v;
    self["Arduino8PinValue"] = kwb_Arduino8PinValue_v;
    self["Arduino9Pin"] = kwb_Arduino9Pin_v;
    self["Arduino9PinValue"] = kwb_Arduino9PinValue_v;
    self["BallPosition"] = kwb_BallPosition_v;
    self["MemoryImageControl"] = kwb_MemoryImageControl_v;
    self["MemoryImageStatus"] = kwb_MemoryImageStatus_v;
    self["LHandGripper"] = kwb_LHandGripper_v;
    self["RHandGripper"] = kwb_RHandGripper_v;
    self["MyPosition"] = kwb_MyPosition_v;
    self["VisionDetectionLines"] = kwb_VisionDetectionLines_v;
    self["VisionDetectionFeatures"] = kwb_VisionDetectionFeatures_v;

    (void) self;
} // guWhiteboard

