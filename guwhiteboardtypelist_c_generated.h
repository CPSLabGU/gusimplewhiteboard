/**
 *  /file guwhiteboardtypelist_c_generated.h
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

#ifndef GUWHITEBOARDTYPELIST_C_GENERATED_H
#define GUWHITEBOARDTYPELIST_C_GENERATED_H

#define WANT_WB_STRINGS

#include "gusimplewhiteboard.h" //GSW_NUM_RESERVED

#define GSW_NUM_TYPES_DEFINED 175

#if GSW_NUM_TYPES_DEFINED > GSW_NUM_RESERVED
#error *** Error: gusimplewhiteboard: The number of defined types exceeds the total number of reserved types allowed. Increase GSW_NUM_RESERVED to solve this.
#endif

/** All the message 'types' for the class based whiteboard */
typedef enum wb_types
{
    kwb_reserved_SubscribeToAllTypes_v = 0, 		///< Global subscription type. Do not add content to this type, it is for global subscriptions only
    kPrint_v = 1, 		///< print to stdout
    kSay_v = 2, 		///< speech output message
    kSpeech_v = 3, 		///< debug speech message
    kQSay_v = 4, 		///< speech output message (queued)
    kQSpeech_v = 5, 		///< debug speech message (queued)
    kSpeechOutput_v = 6, 		///< toggle, treat speech messages as silent output unless this is turned on
    kGCGameState_v = 7, 		///< game state as posted by the game controller state machine
    kSensorsHandSensors_v = 8, 		///< Posts the sensor information for the hands via the DCM loop (read only)
    kSensorsHeadSensors_v = 9, 		///< Posts the sensor information for the head via the DCM loop (read only)
    kMOTION_Commands_v = 10, 		///< WB interface for sending motion commands
    kMOTION_Status_v = 11, 		///< WB interface for checking the status of commands sent
    kHAL_HeadTarget_v = 12, 		///< Used to alter the head position via the DCM
    kSensorsFootSensors_v = 13, 		///< Posts the sensor information for the feet via the DCM loop (read only)
    kSensorsBodySensors_v = 14, 		///< Posts the sensor information for the body via the DCM loop (read only)
    kSENSORSLedsSensors_v = 15, 		///< Posts the current LEDs info, can be modified. (read/write)
    kSENSORSLegJointTemps_v = 16, 		///< Posts the temperature of the leg joints via the DCM loop (read only)
    kSENSORSTorsoJointTemps_v = 17, 		///< Posts the temperature of the torso joints via the DCM loop (read only)
    kSENSORSLegJointSensors_v = 18, 		///< Posts the joint angles of the legs via the DCM loop (read only)
    kSENSORSTorsoJointSensors_v = 19, 		///< Posts the joint angles of the torso via the DCM loop (read only)
    kSENSORSSonarSensors_v = 20, 		///< Posts the sonar readings via the DCM loop (read only)
    kFSM_Control_v = 21, 		///< Suspend, Resume, or Restart a finite state machine (clfsm)
    kFSM_Status_v = 22, 		///< Current status indicating the suspended state of all FSMs.  The highest bit that is always set is the number of machines plus one.
    kFSM_Names_v = 23, 		///< Request or return the names of the currently loaded FSMs.  End of list is denoted by an empty string.  Requests need to put an empty string into the first FSM name;
    kSoloTypeExample_v = 24, 		///< This is an example of a type definition that does not generate anything other than a wb type
    kFilteredGoalSighting_v = 25, 		///< Class that contains the Kalman filtered goal objects after sighting from vision
    kNAO_State_v = 26, 		///< Stores the orientation of the robot as well as the chest button status (more to come).
    kUDPRN_v = 27, 		///< game state notfication from the UDP receiver.
    kPlayerNumber_v = 28, 		///< what player number is this robot wearing at RoboCup in its back, retrieved from data/playernumber and posted by the UDPreceiver
    kManuallyPenalized_v = 29, 		///< what player number is this robot wearing at RoboCup in its back whn manually penalized, from GameController FSM sent to the UDPreceiver to forward to the JAVA referee
    kVisionControl_v = 30, 		///< Used to set various paramaters of guvision
    kVisionStatus_v = 31, 		///< Posted by guvision once per pipeline iteration to report various paramaters
    kFFTStatus_v = 32, 		///< stereo channel RMS and list of dominant frequencies from FFT
    kFSOsighting_v = 33, 		///< Class that contains the Karman filtered  SONAR objects after a sighting
    kTopParticles_v = 34, 		///< Class that contains the top particles for possible robot positions
    kFilteredBallSighting_v = 35, 		///< Class that contains the Kalman filtered top and bottom ball objects after sighting from vision
    kPF_ControlStatus_Modes_v = 36, 		///< what to post in the whiteboard to cause the Particle Filetr to reset, but running has no effect, it is the PF response
    kWEBOTS_NXT_bridge_v = 37, 		///< WIP Class that contains a command for WEBOTS or NXt trough a bridge
    kWEBOTS_NXT_encoders_v = 38, 		///< Class that contains data from encoders all for WEBOTS or NXt trough a bridge
    kWEBOTS_NXT_camera_v = 39, 		///< Class that contains data from cameta channels of  WEBOTS trough a bridge
    kWEBOTS_NXT_walk_isRunning_v = 40, 		///< Class that contains boolean for checking if motion walks is running in  WEBOTS trough a bridge
    kWEBOTS_NXT_deadReakoning_walk_v = 41, 		///< Class for dead reckoning walks in  WEBOTS trough a bridge
    kWEBOTS_NXT_colorLine_walk_v = 42, 		///< Class for commands followign a line in  WEBOTS trough a bridge
    kWEBOTS_NXT_gridMotions_v = 43, 		///< Class for walks on a grid of colored lines for WEBOTS trough a bridge
    kVisionBall_v = 44, 		///< Class that reports the ball that vision sees.
    kVisionGoals_v = 45, 		///< Class that reports the goals that vision sees.
    kWalkData_v = 46, 		///< Class to report Walk Data.
    kTeleoperationControlStatus_v = 47, 		///< Class for sending teleoperation commands
    kTeleoperationConnection_v = 48, 		///< Integer indication which remote whiteboard teleoperation instructions are on
    kUDPWBNumber_v = 49, 		///< ID number being used to broadcast udp whiteboard
    kWEBOTS_NXT_bumper_v = 50, 		///< Class that contains data from 2 rouch sensors in an NXT bumper by the bridge
    kWEBOTS_NXT_vector_bridge_v = 51, 		///< Class that will define actuators for the Diferential motor bridge
    kTopVisionLines_v = 52, 		///< Class that reports the lines that vision sees in the top camera.
    kBottomVisionLines_v = 53, 		///< Class that reports the lines that vision sees in the bottom camera.
    kDifferentialRobotStatus_v = 54, 		///< Class that reads differential robot status
    kDifferentialRobotControl_v = 55, 		///< Class that sends commands to the robot from the whiteboard
    kXEyesPos_v = 56, 		///< Just a hook for an xeyes interface
    kVisionFace_v = 57, 		///< Face seen by Vision
    kDraw_v = 58, 		///< Used by the half made GUDraw module in posix
    kFSM_States_v = 59, 		///< Idempotent Message publicising the state -about to be executed- (0-254) of up-to the first 128 machines (0-127).  State -INVALDMACHINE- (255) is posted for MachineIDs that are not currently loaded.
    kGiraff_Interface_Status_v = 60, 		///< Serial interface for the main motor and sensor board of the giraff
    kGiraff_Interface_Command_v = 61, 		///< Serial interface for the main motor and sensor board of the giraff
    kNXT_Status_v = 62, 		///< Contains sensor data as well as motor encoder data from the objects attached to an NXT
    kNXT_Command_v = 63, 		///< Can issue commands to set the motors of an NXT and reset the encoders
    kAPM_Status_v = 64, 		///< Contains sensor data from an APM
    kAPM_Command_v = 65, 		///< Can issue commands to an APM
    kREMOVED3_v = 66, 		///< Old class, can be removed from tsl file during the next wb version bump
    kREMOVED4_v = 67, 		///< Old class, can be removed from tsl file during the next wb version bump
    kCBall_v = 68, 		///< Status Message for the color of the ball
    kOculusPrime_Command_v = 69, 		///< Class used to control the Oculus Prime movements, controls etc.
    kInput3D_v = 70, 		///< for 3d input devices such as the leap or a joystick
    kOculus_Prime_Command_v = 71, 		///< Serial interface for the main motor and sensor board of the oculus prime
    kIOPins_v = 72, 		///< Arduino-style I/O pins
    kNXT_Two_Touch_Status_v = 73, 		///< Class that reads NXT's two buttons
    kNXT_Sound_Control_v = 74, 		///< Class that produces NXT's sounds
    kNXT_Lights_Control_v = 75, 		///< Class that places power in NXT's for lights
    kClocks_v = 76, 		///< Class for keeping track of time
    kChannels_v = 77, 		///< UPPAAL-Style synchronisation channels
    kSwitchSubsumption_v = 78, 		///< Uncommented
    kTotoDoingMotion_v = 79, 		///< Uncommented
    kCount_v = 80, 		///< Uncommented
    kGreenEWon_v = 81, 		///< status of the EWgreen light
    kWarnEW_v = 82, 		///< status of the recommendaiton of the EW light
    kTimeGTthirty_v = 83, 		///< status of the timer with respect to 30
    kAmberEWon_v = 84, 		///< status of the EWamber light
    kTurnRedEW_v = 85, 		///< second status of the recommendaiton of the EW light
    kTimeGTfive_v = 86, 		///< status of the timer with respect to 5
    kRedEWon_v = 87, 		///< status of the EWred light
    kGreenNSon_v = 88, 		///< status of the NSgreen light
    kWarnNS_v = 89, 		///< status of the recommendaiton of the NS light
    kAmberNSon_v = 90, 		///< status of the NSamber light
    kTurnRedNS_v = 91, 		///< second status of the recommendaiton of the NS light
    kRedNSon_v = 92, 		///< status of the NSred light
    kTimerReset_v = 93, 		///< flag to reset timer
    kSLOT_UNUSED_v = 94, 		///< IoT message removed, feel free to use this slot
    kCarSensorPressed_v = 95, 		///< flag to indicate status of sensor for cars
    kSwitchSubsumptionTrafficLights_v = 96, 		///< no comment entered
    kBall_Found_v = 97, 		///< whether ball is detected in STEM6 DetectBallColor
    kBall_Calibration_File_v = 98, 		///< name of DLC file to load for STEM6 DetectBallColor
    kBall_Calibration_Num_v = 99, 		///< number (size_t) to load with DLC file for STEM6 DetectBallColor
    kBall_Color_Num_v = 100, 		///< number for each ball color as defined in STEM6Master
    kHAL_LArmTarget_Ctrl_v = 101, 		///< Used to control the left arm via DCM
    kHAL_LArmTarget_Stat_v = 102, 		///< Used to report DCM status of the left arm
    kHAL_LArmTarget_Tolr_v = 103, 		///< Used to set the joing angle tolerance for motion completion detection.
    kHAL_RArmTarget_Ctrl_v = 104, 		///< Used to control the right arm via DCM
    kHAL_RArmTarget_Stat_v = 105, 		///< Used to report DCM status of the right arm
    kHAL_RArmTarget_Tolr_v = 106, 		///< Used to set the joing angle tolerance for motion completion detection.
    kVisionFieldFeatures_v = 107, 		///< Posts information from vision about field corners and intersections
    kWhistleBlown_v = 108, 		///< Whistle blown flag
    kVolumeControl_v = 109, 		///< Variable used by SMVolumeController to control the volume via pulse audio commands
    kVisionRobots_v = 110, 		///< Class that reports the robots that vision sees.
    kVisionDetectionHorizons_v = 111, 		///< Class that reports the edge of an SPL field (the edge of the green bit). Array of two values, one for each camera.
    kNaoWalkCommand_v = 112, 		///< Class that controls the latest version of the UNSW 2014 walk engine.
    kNaoWalkStatus_v = 113, 		///< Status class for the latest version of the UNSW 2014 walk engine.
    kHAL_LLegTarget_Ctrl_v = 114, 		///< Used to control the left leg via DCM
    kHAL_LLegTarget_Stat_v = 115, 		///< Used to report DCM status of the left leg
    kHAL_LLegTarget_Tolr_v = 116, 		///< Used to set the joing angle tolerance for motion completion detection.
    kHAL_RLegTarget_Ctrl_v = 117, 		///< Used to control the right leg via DCM
    kHAL_RLegTarget_Stat_v = 118, 		///< Used to report DCM status of the right leg
    kHAL_RLegTarget_Tolr_v = 119, 		///< Used to set the joing angle tolerance for motion completion detection.
    kVisionDetectionGoals_v = 120, 		///< Reports robocup spl goals found with guvision and GoalRayTracer.
    kTeleoperationControl_v = 121, 		///< Control message for teleop VR app
    kTeleoperationStatus_v = 122, 		///< Status message for teleop VR app
    kVisionDetectionBalls_v = 123, 		///< Reports robocup spl ball found with guvision and BallRayTracer.
    kTeleoperationControlVR_v = 124, 		///< Virtual Reality extended class
    kParticleOutputMap_v = 125, 		///< Contains a path to a file containing the list of particles posted by the particle filter.
    kParticleOutputMapControl_v = 126, 		///< Posted by readers of the particles list to notify the filter to swap buffers.
    kFFTControl_v = 127, 		///< Turn on or off the FFT module
    kMachineFilteredNaoVision_v = 128, 		///< Vision filtering and distance estimates.
    kMicrowaveStatus_v = 129, 		///< External Variables for the One Minute Microwave.
    kButtons_v = 130, 		///< External Variables for the Incrementing LLFSM.
    kMachineFilteredLocalisationVision_v = 131, 		///< Vision filtering and distance estimates for landmarks: goal, lines and horizon.
    kSensorsJointCurrent_v = 132, 		///< Posts the current flowing through each joint via the DCM loop (read only)
    kDataLogger_v = 133, 		///< Controls the data logging within Naoqi Interface
    kMachineFilteredLines_v = 134, 		///< Vision filtering and distance estimates for lines.
    kBallLocation_v = 135, 		///< Location of the ball.
    kLeftGoalPostLocation_v = 136, 		///< Location of the left goal post.
    kRightGoalPostLocation_v = 137, 		///< Location of the right goal post.
    kGoalLocation_v = 138, 		///< Location of the goal.
    kNaoSonarProtectedWalkCommand_v = 139, 		///< Send walk protected by sonar.
    kNaoObstacleDirection_v = 140, 		///< Send general direction if obstacle.
    kDominantFrequencies_v = 141, 		///< Dominant frequencies and RMS levels for the four microphones
    kMissionPriorityForObstacles_v = 142, 		///< notify trough the whiteboard the priority of the mission, high for chasing the ball, low for getting to a place in the field.
    kWavLoad_v = 143, 		///< request to load a wav file
    kWavPlay_v = 144, 		///< forced, treat request to play wav file as forced output and sound will come out even if reproduce on is silent
    kReproduceWavNotSilent_v = 145, 		///< toggle, treat request to play wav file as silent output unless this is turned on but can be overwritten by forced in WavPlay
    kFrequencyControl_v = 146, 		///< Frequency limits control message for FFT analysis
    kFrequencyStatus_v = 147, 		///< Current Frequency limits (status) for FFT analysis
    kHeadJointSensors_v = 148, 		///< Status of the head sensors in degrees.
    kAdjustPositionConfidence_v = 149, 		///< Changes the confidence of objects being tracked.
    kGuVrTeleopVulkanControl_v = 150, 		///< Control message for commands from the Vulkan VR teleop app
    kTemperatureSensors_v = 151, 		///< The fake status of the temperature sensors in the nao legs - FOR RESEARCH ONLY.
    kOverheating_v = 152, 		///< The fake combined status of the temperature sensors in the nao legs - FOR RESEARCH ONLY.
    kbuttonPushed_v = 153, 		///< The time remaining in the microwave - swiftfsm.
    kdoorOpen_v = 154, 		///< The time remaining in the microwave - swiftfsm.
    ktimeLeft_v = 155, 		///< The time remaining in the microwave - swiftfsm.
    kmotor_v = 156, 		///< The motor actuator for the microwave - swiftfsm.
    ksound_v = 157, 		///< The alarm actuator for the microwave - swiftfsm.
    klight_v = 158, 		///< The light actuator for the microwave - swiftfsm.
    kArduino2Pin_v = 159, 		///< The status of the 2 pin for the arduino.
    kArduino2PinValue_v = 160, 		///< The value of the 2 pin for the arduino.
    kArduino3Pin_v = 161, 		///< The status of the 3 pin for the arduino.
    kArduino3PinValue_v = 162, 		///< The value of the 3 pin for the arduino.
    kArduino4Pin_v = 163, 		///< The status of the 4 pin for the arduino.
    kArduino4PinValue_v = 164, 		///< The value of the 4 pin for the arduino.
    kArduino5Pin_v = 165, 		///< The status of the 5 pin for the arduino.
    kArduino5PinValue_v = 166, 		///< The value of the 5 pin for the arduino.
    kArduino6Pin_v = 167, 		///< The status of the 6 pin for the arduino.
    kArduino6PinValue_v = 168, 		///< The value of the 6 pin for the arduino.
    kArduino7Pin_v = 169, 		///< The status of the 7 pin for the arduino.
    kArduino7PinValue_v = 170, 		///< The value of the 7 pin for the arduino.
    kArduino8Pin_v = 171, 		///< The status of the 8 pin for the arduino.
    kArduino8PinValue_v = 172, 		///< The value of the 8 pin for the arduino.
    kArduino9Pin_v = 173, 		///< The status of the 9 pin for the arduino.

    kArduino9PinValue_v = 174 		///< The value of the 9 pin for the arduino.


} WBTypes; ///< All the message 'types' for the class based whiteboard 

extern const char *WBTypes_stringValues[GSW_NUM_TYPES_DEFINED];
extern const char *WBTypes_typeValues[GSW_NUM_TYPES_DEFINED];

#endif //GUWHITEBOARDTYPELIST_C_GENERATED_H
