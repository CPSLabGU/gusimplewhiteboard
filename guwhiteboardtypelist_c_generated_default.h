/**
 *  /file guwhiteboardtypelist_c_generated.h
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

#ifndef WB_GUWHITEBOARDTYPELIST_C_GENERATED_H
#define WB_GUWHITEBOARDTYPELIST_C_GENERATED_H

#undef WANT_WB_STRINGS
#define WANT_WB_STRINGS

#include "gusimplewhiteboard.h" //GSW_NUM_RESERVED

#define WB_NUM_TYPES_DEFINED_DEFAULT 183

#if WB_NUM_TYPES_DEFINED_DEFAULT > GSW_NUM_RESERVED
#error *** Error: gusimplewhiteboard: The number of defined types exceeds the total number of reserved types allowed. Increase GSW_NUM_RESERVED to solve this.
#endif

/** All the message 'types' for the class based whiteboard */
typedef enum wb_types_default
{
    kwb_wb_reserved_SubscribeToAllTypes_v = 0, 		///< Global subscription type. Do not add content to this type, it is for global subscriptions only
    kwb_Print_v = 1, 		///< print to stdout
    kwb_Say_v = 2, 		///< speech output message
    kwb_Speech_v = 3, 		///< debug speech message
    kwb_QSay_v = 4, 		///< speech output message (queued)
    kwb_QSpeech_v = 5, 		///< debug speech message (queued)
    kwb_SpeechOutput_v = 6, 		///< toggle, treat speech messages as silent output unless this is turned on
    kwb_GCGameState_v = 7, 		///< game state as posted by the game controller state machine
    kwb_SensorsHandSensors_v = 8, 		///< Posts the sensor information for the hands via the DCM loop (read only)
    kwb_SensorsHeadSensors_v = 9, 		///< Posts the sensor information for the head via the DCM loop (read only)
    kwb_MOTION_Commands_v = 10, 		///< WB interface for sending motion commands
    kwb_MOTION_Status_v = 11, 		///< WB interface for checking the status of commands sent
    kwb_HAL_HeadTarget_v = 12, 		///< Used to alter the head position via the DCM
    kwb_SensorsFootSensors_v = 13, 		///< Posts the sensor information for the feet via the DCM loop (read only)
    kwb_SensorsBodySensors_v = 14, 		///< Posts the sensor information for the body via the DCM loop (read only)
    kwb_SENSORSLedsSensors_v = 15, 		///< Posts the current LEDs info, can be modified. (read/write)
    kwb_SENSORSLegJointTemps_v = 16, 		///< Posts the temperature of the leg joints via the DCM loop (read only)
    kwb_SENSORSTorsoJointTemps_v = 17, 		///< Posts the temperature of the torso joints via the DCM loop (read only)
    kwb_SENSORSLegJointSensors_v = 18, 		///< Posts the joint angles of the legs via the DCM loop (read only)
    kwb_SENSORSTorsoJointSensors_v = 19, 		///< Posts the joint angles of the torso via the DCM loop (read only)
    kwb_SENSORSSonarSensors_v = 20, 		///< Posts the sonar readings via the DCM loop (read only)
    kwb_FSM_Control_v = 21, 		///< Suspend, Resume, or Restart a finite state machine (clfsm)
    kwb_FSM_Status_v = 22, 		///< Current status indicating the suspended state of all FSMs.  The highest bit that is always set is the number of machines plus one.
    kwb_FSM_Names_v = 23, 		///< Request or return the names of the currently loaded FSMs.  End of list is denoted by an empty string.  Requests need to put an empty string into the first FSM name;
    kwb_SoloTypeExample_v = 24, 		///< This is an example of a type definition that does not generate anything other than a wb type
    kwb_FilteredGoalSighting_v = 25, 		///< Class that contains the Kalman filtered goal objects after sighting from vision
    kwb_NAO_State_v = 26, 		///< Stores the orientation of the robot as well as the chest button status (more to come).
    kwb_UDPRN_v = 27, 		///< game state notfication from the UDP receiver.
    kwb_PlayerNumber_v = 28, 		///< what player number is this robot wearing at RoboCup in its back, retrieved from data/playernumber and posted by the UDPreceiver
    kwb_ManuallyPenalized_v = 29, 		///< what player number is this robot wearing at RoboCup in its back whn manually penalized, from GameController FSM sent to the UDPreceiver to forward to the JAVA referee
    kwb_VisionControl_v = 30, 		///< Used to set various paramaters of guvision
    kwb_VisionStatus_v = 31, 		///< Posted by guvision once per pipeline iteration to report various paramaters
    kwb_FFTStatus_v = 32, 		///< stereo channel RMS and list of dominant frequencies from FFT
    kwb_FSOsighting_v = 33, 		///< Class that contains the Karman filtered  SONAR objects after a sighting
    kwb_TopParticles_v = 34, 		///< Class that contains the top particles for possible robot positions
    kwb_FilteredBallSighting_v = 35, 		///< Class that contains the Kalman filtered top and bottom ball objects after sighting from vision
    kwb_PF_ControlStatus_Modes_v = 36, 		///< what to post in the whiteboard to cause the Particle Filetr to reset, but running has no effect, it is the PF response
    kwb_WEBOTS_NXT_bridge_v = 37, 		///< WIP Class that contains a command for WEBOTS or NXt trough a bridge
    kwb_WEBOTS_NXT_encoders_v = 38, 		///< Class that contains data from encoders all for WEBOTS or NXt trough a bridge
    kwb_WEBOTS_NXT_camera_v = 39, 		///< Class that contains data from cameta channels of  WEBOTS trough a bridge
    kwb_WEBOTS_NXT_walk_isRunning_v = 40, 		///< Class that contains boolean for checking if motion walks is running in  WEBOTS trough a bridge
    kwb_WEBOTS_NXT_deadReakoning_walk_v = 41, 		///< Class for dead reckoning walks in  WEBOTS trough a bridge
    kwb_WEBOTS_NXT_colorLine_walk_v = 42, 		///< Class for commands followign a line in  WEBOTS trough a bridge
    kwb_WEBOTS_NXT_gridMotions_v = 43, 		///< Class for walks on a grid of colored lines for WEBOTS trough a bridge
    kwb_VisionBall_v = 44, 		///< Class that reports the ball that vision sees.
    kwb_VisionGoals_v = 45, 		///< Class that reports the goals that vision sees.
    kwb_WalkData_v = 46, 		///< Class to report Walk Data.
    kwb_TeleoperationControlStatus_v = 47, 		///< Class for sending teleoperation commands
    kwb_TeleoperationConnection_v = 48, 		///< Integer indication which remote whiteboard teleoperation instructions are on
    kwb_UDPWBNumber_v = 49, 		///< ID number being used to broadcast udp whiteboard
    kwb_WEBOTS_NXT_bumper_v = 50, 		///< Class that contains data from 2 rouch sensors in an NXT bumper by the bridge
    kwb_WEBOTS_NXT_vector_bridge_v = 51, 		///< Class that will define actuators for the Diferential motor bridge
    kwb_TopVisionLines_v = 52, 		///< Class that reports the lines that vision sees in the top camera.
    kwb_BottomVisionLines_v = 53, 		///< Class that reports the lines that vision sees in the bottom camera.
    kwb_DifferentialRobotStatus_v = 54, 		///< Class that reads differential robot status
    kwb_DifferentialRobotControl_v = 55, 		///< Class that sends commands to the robot from the whiteboard
    kwb_XEyesPos_v = 56, 		///< Just a hook for an xeyes interface
    kwb_VisionFace_v = 57, 		///< Face seen by Vision
    kwb_Draw_v = 58, 		///< Used by the half made GUDraw module in posix
    kwb_FSM_States_v = 59, 		///< Idempotent Message publicising the state -about to be executed- (0-254) of up-to the first 128 machines (0-127).  State -INVALDMACHINE- (255) is posted for MachineIDs that are not currently loaded.
    kwb_Giraff_Interface_Status_v = 60, 		///< Serial interface for the main motor and sensor board of the giraff
    kwb_Giraff_Interface_Command_v = 61, 		///< Serial interface for the main motor and sensor board of the giraff
    kwb_NXT_Status_v = 62, 		///< Contains sensor data as well as motor encoder data from the objects attached to an NXT
    kwb_NXT_Command_v = 63, 		///< Can issue commands to set the motors of an NXT and reset the encoders
    kwb_APM_Status_v = 64, 		///< Contains sensor data from an APM
    kwb_APM_Command_v = 65, 		///< Can issue commands to an APM
    kwb_REMOVED3_v = 66, 		///< Old class, can be removed from tsl file during the next wb version bump
    kwb_REMOVED4_v = 67, 		///< Old class, can be removed from tsl file during the next wb version bump
    kwb_CBall_v = 68, 		///< Status Message for the color of the ball
    kwb_OculusPrime_Command_v = 69, 		///< Class used to control the Oculus Prime movements, controls etc.
    kwb_Input3D_v = 70, 		///< for 3d input devices such as the leap or a joystick
    kwb_Oculus_Prime_Command_v = 71, 		///< Serial interface for the main motor and sensor board of the oculus prime
    kwb_IOPins_v = 72, 		///< Arduino-style I/O pins
    kwb_NXT_Two_Touch_Status_v = 73, 		///< Class that reads NXT's two buttons
    kwb_NXT_Sound_Control_v = 74, 		///< Class that produces NXT's sounds
    kwb_NXT_Lights_Control_v = 75, 		///< Class that places power in NXT's for lights
    kwb_Clocks_v = 76, 		///< Class for keeping track of time
    kwb_Channels_v = 77, 		///< UPPAAL-Style synchronisation channels
    kwb_SwitchSubsumption_v = 78, 		///< Uncommented
    kwb_TotoDoingMotion_v = 79, 		///< Uncommented
    kwb_Count_v = 80, 		///< Uncommented
    kwb_GreenEWon_v = 81, 		///< status of the EWgreen light
    kwb_WarnEW_v = 82, 		///< status of the recommendaiton of the EW light
    kwb_TimeGTthirty_v = 83, 		///< status of the timer with respect to 30
    kwb_AmberEWon_v = 84, 		///< status of the EWamber light
    kwb_TurnRedEW_v = 85, 		///< second status of the recommendaiton of the EW light
    kwb_TimeGTfive_v = 86, 		///< status of the timer with respect to 5
    kwb_RedEWon_v = 87, 		///< status of the EWred light
    kwb_GreenNSon_v = 88, 		///< status of the NSgreen light
    kwb_WarnNS_v = 89, 		///< status of the recommendaiton of the NS light
    kwb_AmberNSon_v = 90, 		///< status of the NSamber light
    kwb_TurnRedNS_v = 91, 		///< second status of the recommendaiton of the NS light
    kwb_RedNSon_v = 92, 		///< status of the NSred light
    kwb_TimerReset_v = 93, 		///< flag to reset timer
    kwb_SLOT_UNUSED_v = 94, 		///< IoT message removed, feel free to use this slot
    kwb_CarSensorPressed_v = 95, 		///< flag to indicate status of sensor for cars
    kwb_SwitchSubsumptionTrafficLights_v = 96, 		///< no comment entered
    kwb_Ball_Found_v = 97, 		///< whether ball is detected in STEM6 DetectBallColor
    kwb_Ball_Calibration_File_v = 98, 		///< name of DLC file to load for STEM6 DetectBallColor
    kwb_Ball_Calibration_Num_v = 99, 		///< number (size_t) to load with DLC file for STEM6 DetectBallColor
    kwb_Ball_Color_Num_v = 100, 		///< number for each ball color as defined in STEM6Master
    kwb_HAL_LArmTarget_Ctrl_v = 101, 		///< Used to control the left arm via DCM
    kwb_HAL_LArmTarget_Stat_v = 102, 		///< Used to report DCM status of the left arm
    kwb_HAL_LArmTarget_Tolr_v = 103, 		///< Used to set the joing angle tolerance for motion completion detection.
    kwb_HAL_RArmTarget_Ctrl_v = 104, 		///< Used to control the right arm via DCM
    kwb_HAL_RArmTarget_Stat_v = 105, 		///< Used to report DCM status of the right arm
    kwb_HAL_RArmTarget_Tolr_v = 106, 		///< Used to set the joing angle tolerance for motion completion detection.
    kwb_VisionFieldFeatures_v = 107, 		///< Posts information from vision about field corners and intersections
    kwb_WhistleBlown_v = 108, 		///< Whistle blown flag
    kwb_VolumeControl_v = 109, 		///< Variable used by SMVolumeController to control the volume via pulse audio commands
    kwb_VisionRobots_v = 110, 		///< Class that reports the robots that vision sees.
    kwb_VisionDetectionHorizons_v = 111, 		///< Class that reports the edge of an SPL field (the edge of the green bit). Array of two values, one for each camera.
    kwb_NaoWalkCommand_v = 112, 		///< Class that controls the latest version of the UNSW 2014 walk engine.
    kwb_NaoWalkStatus_v = 113, 		///< Status class for the latest version of the UNSW 2014 walk engine.
    kwb_HAL_LLegTarget_Ctrl_v = 114, 		///< Used to control the left leg via DCM
    kwb_HAL_LLegTarget_Stat_v = 115, 		///< Used to report DCM status of the left leg
    kwb_HAL_LLegTarget_Tolr_v = 116, 		///< Used to set the joing angle tolerance for motion completion detection.
    kwb_HAL_RLegTarget_Ctrl_v = 117, 		///< Used to control the right leg via DCM
    kwb_HAL_RLegTarget_Stat_v = 118, 		///< Used to report DCM status of the right leg
    kwb_HAL_RLegTarget_Tolr_v = 119, 		///< Used to set the joing angle tolerance for motion completion detection.
    kwb_VisionDetectionGoals_v = 120, 		///< Reports robocup spl goals found with guvision and GoalRayTracer.
    kwb_TeleoperationControl_v = 121, 		///< Control message for teleop VR app
    kwb_TeleoperationStatus_v = 122, 		///< Status message for teleop VR app
    kwb_VisionDetectionBalls_v = 123, 		///< Reports robocup spl ball found with guvision and BallRayTracer.
    kwb_TeleoperationControlVR_v = 124, 		///< Virtual Reality extended class
    kwb_ParticleOutputMap_v = 125, 		///< Contains a path to a file containing the list of particles posted by the particle filter.
    kwb_ParticleOutputMapControl_v = 126, 		///< Posted by readers of the particles list to notify the filter to swap buffers.
    kwb_FFTControl_v = 127, 		///< Turn on or off the FFT module
    kwb_MachineFilteredNaoVision_v = 128, 		///< Vision filtering and distance estimates.
    kwb_MicrowaveStatus_v = 129, 		///< External Variables for the One Minute Microwave.
    kwb_Buttons_v = 130, 		///< External Variables for the Incrementing LLFSM.
    kwb_MachineFilteredLocalisationVision_v = 131, 		///< Vision filtering and distance estimates for landmarks: goal, lines and horizon.
    kwb_SensorsJointCurrent_v = 132, 		///< Posts the current flowing through each joint via the DCM loop (read only)
    kwb_DataLogger_v = 133, 		///< Controls the data logging within Naoqi Interface
    kwb_MachineFilteredLines_v = 134, 		///< Vision filtering and distance estimates for lines.
    kwb_BallLocation_v = 135, 		///< Location of the ball.
    kwb_LeftGoalPostLocation_v = 136, 		///< Location of the left goal post.
    kwb_RightGoalPostLocation_v = 137, 		///< Location of the right goal post.
    kwb_GoalLocation_v = 138, 		///< Location of the goal.
    kwb_NaoSonarProtectedWalkCommand_v = 139, 		///< Send walk protected by sonar.
    kwb_NaoObstacleDirection_v = 140, 		///< Send general direction if obstacle.
    kwb_DominantFrequencies_v = 141, 		///< Dominant frequencies and RMS levels for the four microphones
    kwb_MissionPriorityForObstacles_v = 142, 		///< notify trough the whiteboard the priority of the mission, high for chasing the ball, low for getting to a place in the field.
    kwb_WavLoad_v = 143, 		///< request to load a wav file
    kwb_WavPlay_v = 144, 		///< forced, treat request to play wav file as forced output and sound will come out even if reproduce on is silent
    kwb_ReproduceWavNotSilent_v = 145, 		///< toggle, treat request to play wav file as silent output unless this is turned on but can be overwritten by forced in WavPlay
    kwb_FrequencyControl_v = 146, 		///< Frequency limits control message for FFT analysis
    kwb_FrequencyStatus_v = 147, 		///< Current Frequency limits (status) for FFT analysis
    kwb_HeadJointSensors_v = 148, 		///< Status of the head sensors in degrees.
    kwb_AdjustPositionConfidence_v = 149, 		///< Changes the confidence of objects being tracked.
    kwb_GuVrTeleopVulkanControl_v = 150, 		///< Control message for commands from the Vulkan VR teleop app
    kwb_TemperatureSensors_v = 151, 		///< The fake status of the temperature sensors in the nao legs - FOR RESEARCH ONLY.
    kwb_Overheating_v = 152, 		///< The fake combined status of the temperature sensors in the nao legs - FOR RESEARCH ONLY.
    kwb_buttonPushed_v = 153, 		///< The time remaining in the microwave - swiftfsm.
    kwb_doorOpen_v = 154, 		///< The time remaining in the microwave - swiftfsm.
    kwb_timeLeft_v = 155, 		///< The time remaining in the microwave - swiftfsm.
    kwb_motor_v = 156, 		///< The motor actuator for the microwave - swiftfsm.
    kwb_sound_v = 157, 		///< The alarm actuator for the microwave - swiftfsm.
    kwb_light_v = 158, 		///< The light actuator for the microwave - swiftfsm.
    kwb_Arduino2Pin_v = 159, 		///< The status of the 2 pin for the arduino.
    kwb_Arduino2PinValue_v = 160, 		///< The value of the 2 pin for the arduino.
    kwb_Arduino3Pin_v = 161, 		///< The status of the 3 pin for the arduino.
    kwb_Arduino3PinValue_v = 162, 		///< The value of the 3 pin for the arduino.
    kwb_Arduino4Pin_v = 163, 		///< The status of the 4 pin for the arduino.
    kwb_Arduino4PinValue_v = 164, 		///< The value of the 4 pin for the arduino.
    kwb_Arduino5Pin_v = 165, 		///< The status of the 5 pin for the arduino.
    kwb_Arduino5PinValue_v = 166, 		///< The value of the 5 pin for the arduino.
    kwb_Arduino6Pin_v = 167, 		///< The status of the 6 pin for the arduino.
    kwb_Arduino6PinValue_v = 168, 		///< The value of the 6 pin for the arduino.
    kwb_Arduino7Pin_v = 169, 		///< The status of the 7 pin for the arduino.
    kwb_Arduino7PinValue_v = 170, 		///< The value of the 7 pin for the arduino.
    kwb_Arduino8Pin_v = 171, 		///< The status of the 8 pin for the arduino.
    kwb_Arduino8PinValue_v = 172, 		///< The value of the 8 pin for the arduino.
    kwb_Arduino9Pin_v = 173, 		///< The status of the 9 pin for the arduino.
    kwb_Arduino9PinValue_v = 174, 		///< The value of the 9 pin for the arduino.
    kwb_BallPosition_v = 175, 		///< The position and orientation of the ball on the soccer field.
    kwb_MemoryImageControl_v = 176, 		///< Control at what resolution and format memory images need to be posted as.
    kwb_MemoryImageStatus_v = 177, 		///< Status of what resolution and format memory images are being posted as.
    kwb_LHandGripper_v = 178, 		///< 0 is closed 100 is fully open (left hand).
    kwb_RHandGripper_v = 179, 		///< 0 is closed 100 is fully open (right hand).
    kwb_MyPosition_v = 180, 		///< Location of the robot relative to where it started.
    kwb_VisionDetectionLines_v = 181, 		///< Reports robocup field lines found with guvision and LineRayTracer.

    kwb_VisionDetectionFeatures_v = 182 		///< Reports robocup field features found with guvision and FeatureDetector.


} wb_types_default; ///< All the message 'types' for the class based whiteboard 
#ifndef WBTypes_DEFINED
#define WBTypes_DEFINED
typedef wb_types_default WBTypes;
#endif

extern const char *wb_types_stringValues_default[WB_NUM_TYPES_DEFINED_DEFAULT];
extern const char *wb_types_typeValues_default[WB_NUM_TYPES_DEFINED_DEFAULT];

#endif //WB_GUWHITEBOARDTYPELIST_C_GENERATED_H
