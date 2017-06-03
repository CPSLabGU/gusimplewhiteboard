/**
 *  /file guwhiteboardtypelist_c_typestrings_generated.c
 *
 *  Created by Carl Lusty in 2013.
 *  Copyright (c) 2013-2016 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

#include "gusimplewhiteboard.h"
#include "guwhiteboardtypelist_c_generated.h"

//Generated on: Fri Jun  2 17:24:25 2017
//Generated by user: nap

const char *WBTypes_stringValues[GSW_NUM_TYPES_DEFINED] = 
{
        "*",
        "Print",
        "Say",
        "Speech",
        "QSay",
        "QSpeech",
        "SpeechOutput",
        "GCGameState",
        "WALK_Command",
        "WALK_Status",
        "MOTION_Commands",
        "MOTION_Status",
        "HAL_HeadTarget",
        "SENSORSFootSensors",
        "SENSORSBodySensors",
        "SENSORSLedsSensors",
        "SENSORSLegJointTemps",
        "SENSORSTorsoJointTemps",
        "SENSORSLegJointSensors",
        "SENSORSTorsoJointSensors",
        "SENSORSSonarSensors",
        "fsm_control",
        "fsm_status",
        "fsm_names",
        "example_type",
        "FilteredGoalSighting",
        "NAO_State",
        "UDPReceiverNotification",
        "PlayerNumber",
        "PlayerNumber",
        "guvision_control",
        "guvision_status",
        "FFTStatus",
        "FSOsighting",
        "TopParticles",
        "FilteredBallSighting",
        "PF_ControlStatus_Modes",
        "WEBOTS_NXT_bridge",
        "WEBOTS_NXT_encoders",
        "WEBOTS_NXT_camera",
        "WEBOTS_NXT_walk_isRunning",
        "WEBOTS_NXT_deadReakoning_walk",
        "WEBOTS_NXT_colorLine_walk",
        "WEBOTS_NXT_gridMotions",
        "VisionBall",
        "VisionGoals",
        "WalkData",
        "TeleoperationControlStatus",
        "TeleoperationConnection",
        "UDPWBNumber",
        "WEBOTS_NXT_bumper",
        "WEBOTS_NXT_vector_bridge",
        "VisionLines",
        "DifferentialRobotStatus",
        "DifferentialRobotControl",
        "XEyesPos",
        "VisionFace",
        "Draw",
        "fsm_states",
        "Giraff_Interface_Status",
        "Giraff_Interface_Command",
        "NXT_Status",
        "NXT_Command",
        "APM_Status",
        "APM_Command",
        "WALK2014_Command",
        "WALK2014_Status",
        "CBall",
        "OculusPrime_Command",
        "Input3D",
        "Oculus_Prime_Command",
        "IOPins",
        "NXT_Two_Touch_Status",
        "NXT_Sound_Control",
        "NXT_Lights_Control",
        "Clocks",
        "Channels",
        "SwitchSubsumption",
        "TotoDoingMotion",
        "A Simple Integer",
        "GreenEWon",
        "WarnEW",
        "TimeGTthirty",
        "AmberEWon",
        "TurnRedEW",
        "TimeGTfive",
        "RedEWon",
        "GreenNSon",
        "WarnNS",
        "AmberNSon",
        "TurnRedNS",
        "RedNSon",
        "TimerReset",
        "SLOT_UNUSED",
        "CarSensorPressed",
        "SwitchSubsumptionTrafficLights",
        "Ball_Found",
        "Ball_Calibration_File",
        "Ball_Calibration_Num",
        "Ball_Color_Num",
        "HAL_LArmTarget_Ctrl",
        "HAL_LArmTarget_Stat",
        "HAL_LArmTarget_Tolr",
        "HAL_RArmTarget_Ctrl",
        "HAL_RArmTarget_Stat",
        "HAL_RArmTarget_Tolr"
};

const char *WBTypes_typeValues[GSW_NUM_TYPES_DEFINED] = 
{
        "",
        "std::string",
        "std::string",
        "std::string",
        "std::string",
        "std::string",
        "bool",
        "GCGameState",
        "WALK_ControlStatus",
        "WALK_ControlStatus",
        "MOTION_Commands",
        "MOTION_Status",
        "HAL_HeadTarget",
        "SENSORSFootSensors",
        "SENSORSBodySensors",
        "SENSORSLedsSensors",
        "SENSORSLegJointTemps",
        "SENSORSTorsoJointTemps",
        "SENSORSLegJointSensors",
        "SENSORSTorsoJointSensors",
        "SENSORSSonarSensors",
        "FSMControlStatus",
        "FSMControlStatus",
        "FSMNames",
        "",
        "FilteredArrayOneDimObjects",
        "NAO_State",
        "GCGameState",
        "int8_t",
        "int8_t",
        "VisionControlStatus",
        "VisionControlStatus",
        "FFTStatus",
        "FilteredArrayOneDimSonar",
        "TopParticles",
        "FilteredArrayOneDimBall",
        "int32_t",
        "WEBOTS_NXT_bridge",
        "WEBOTS_NXT_encoders",
        "WEBOTS_NXT_camera",
        "WEBOTS_NXT_walk_isRunning",
        "WEBOTS_NXT_deadReakoning_walk",
        "WEBOTS_NXT_colorLine_walk",
        "WEBOTS_NXT_gridMotions",
        "VisionBall",
        "VisionGoals",
        "WalkData",
        "TeleoperationControlStatus",
        "int8_t",
        "int8_t",
        "WEBOTS_NXT_bumper",
        "WEBOTS_NXT_vector_bridge",
        "VisionLines",
        "DifferentialRobotControlStatus",
        "DifferentialRobotControlStatus",
        "Point2D",
        "std::vector<int>",
        "std::string",
        "FSMState",
        "Giraff_MainSerialInterface",
        "Giraff_MainSerialInterface",
        "NXT_Interface",
        "NXT_Interface",
        "APM_Interface",
        "APM_Interface",
        "WALK2014_ControlStatus",
        "WALK2014_ControlStatus",
        "int8_t",
        "OculusPrimeInterface",
        "Input3D",
        "Oculus_PrimeSerialInterface",
        "IOPins",
        "NXT_Two_Touch_Status",
        "NXT_Sound_Control",
        "NXT_Lights_Control",
        "Clocks",
        "Channels",
        "SwitchSubsumption",
        "TotoDoingMotion",
        "wb_count",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "SwitchSubsumptionTrafficLights",
        "bool",
        "std::string",
        "int32_t",
        "int32_t",
        "HAL_ArmTarget",
        "HAL_ArmTarget",
        "HAL_ArmTarget",
        "HAL_ArmTarget",
        "HAL_ArmTarget",
        "HAL_ArmTarget"
};

