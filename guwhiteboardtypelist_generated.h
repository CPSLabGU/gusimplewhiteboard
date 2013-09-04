/**                                                                     
 *  /file guwhiteboardtypelist_generated.h                              
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                        
                                                                        
#ifndef _GUWHITEBOARD_TYPELIST_H_                                       
#define _GUWHITEBOARD_TYPELIST_H_                                       
                                                                        
#include "gugenericwhiteboardobject.h"                                
#include "gutcpinjectionwhiteboardobject.h"                           
                                                                        
#pragma clang diagnostic push                                           
#pragma clang diagnostic ignored "-Wpadded"                           
                                                                        
                                                                        
//Generated on: Fri Aug 16 14:51:33 2013
//Generated by user: brainerror404
                              
namespace guWhiteboard                                                  
{                                                                       
                                                                        
extern "C"                                                            
{                                                                       
#include "guwhiteboardtypelist_c_generated.h"                         
}                                                                       
                                                                        
	/// print to stdout
        class Print_t: public generic_whiteboard_object<std::string > { 
	public: 
		Print_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kPrint_v, true) {}
		Print_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kPrint_v, wbd, true) {} 
	};

	/// print to stdout
        class Print_iTCP: public injection_whiteboard_object<std::string > { 
	public: 
		Print_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(hostname, kPrint_v, is_async) {}
		Print_iTCP(std::string value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(value, hostname, kPrint_v, is_async) {} 
	};

	/// speech output message
        class Say_t: public generic_whiteboard_object<std::string > { 
	public: 
		Say_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kSay_v, true) {}
		Say_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kSay_v, wbd, true) {} 
	};

	/// speech output message
        class Say_iTCP: public injection_whiteboard_object<std::string > { 
	public: 
		Say_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(hostname, kSay_v, is_async) {}
		Say_iTCP(std::string value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(value, hostname, kSay_v, is_async) {} 
	};

	/// debug speech message
        class Speech_t: public generic_whiteboard_object<std::string > { 
	public: 
		Speech_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kSpeech_v, true) {}
		Speech_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kSpeech_v, wbd, true) {} 
	};

	/// debug speech message
        class Speech_iTCP: public injection_whiteboard_object<std::string > { 
	public: 
		Speech_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(hostname, kSpeech_v, is_async) {}
		Speech_iTCP(std::string value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(value, hostname, kSpeech_v, is_async) {} 
	};

	/// speech output message (queued)
        class QSay_t: public generic_whiteboard_object<std::string > { 
	public: 
		QSay_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kQSay_v, true) {}
		QSay_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kQSay_v, wbd, true) {} 
	};

	/// speech output message (queued)
        class QSay_iTCP: public injection_whiteboard_object<std::string > { 
	public: 
		QSay_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(hostname, kQSay_v, is_async) {}
		QSay_iTCP(std::string value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(value, hostname, kQSay_v, is_async) {} 
	};

	/// debug speech message (queued)
        class QSpeech_t: public generic_whiteboard_object<std::string > { 
	public: 
		QSpeech_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kQSpeech_v, true) {}
		QSpeech_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kQSpeech_v, wbd, true) {} 
	};

	/// debug speech message (queued)
        class QSpeech_iTCP: public injection_whiteboard_object<std::string > { 
	public: 
		QSpeech_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(hostname, kQSpeech_v, is_async) {}
		QSpeech_iTCP(std::string value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::string >(value, hostname, kQSpeech_v, is_async) {} 
	};

	/// toggle, treat speech messages as silent output unless this is turned on
        class SpeechOutput_t: public generic_whiteboard_object<bool > { 
	public: 
		SpeechOutput_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kSpeechOutput_v, false) {}
		SpeechOutput_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kSpeechOutput_v, wbd, false) {} 
	};

	/// toggle, treat speech messages as silent output unless this is turned on
        class SpeechOutput_iTCP: public injection_whiteboard_object<bool > { 
	public: 
		SpeechOutput_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<bool >(hostname, kSpeechOutput_v, is_async) {}
		SpeechOutput_iTCP(bool value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<bool >(value, hostname, kSpeechOutput_v, is_async) {} 
	};

	///game state as posted by the game controller state machine
        class GCGameState_t: public generic_whiteboard_object<class GCGameState > { 
	public: 
		GCGameState_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class GCGameState >(wbd, kGCGameState_v, false) {} 
	};

	///game state as posted by the game controller state machine
        class GCGameState_iTCP: public injection_whiteboard_object<class GCGameState > { 
	public: 
		GCGameState_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class GCGameState >(hostname, kGCGameState_v, is_async) {} 
	};

	///Class used to control the walk engine (UNSW)
        class WALK_Command_t: public generic_whiteboard_object<class WALK_ControlStatus > { 
	public: 
		WALK_Command_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class WALK_ControlStatus >(wbd, kWALK_Command_v, false) {} 
	};

	///Class used to control the walk engine (UNSW)
        class WALK_Command_iTCP: public injection_whiteboard_object<class WALK_ControlStatus > { 
	public: 
		WALK_Command_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class WALK_ControlStatus >(hostname, kWALK_Command_v, is_async) {} 
	};

	///Class used to check the status of the walk engine (UNSW)
        class WALK_Status_t: public generic_whiteboard_object<class WALK_ControlStatus > { 
	public: 
		WALK_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class WALK_ControlStatus >(wbd, kWALK_Status_v, false) {} 
	};

	///Class used to check the status of the walk engine (UNSW)
        class WALK_Status_iTCP: public injection_whiteboard_object<class WALK_ControlStatus > { 
	public: 
		WALK_Status_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class WALK_ControlStatus >(hostname, kWALK_Status_v, is_async) {} 
	};

	///WB interface for sending motion commands
        class MOTION_Commands_t: public generic_whiteboard_object<class MOTION_Commands > { 
	public: 
		MOTION_Commands_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class MOTION_Commands >(wbd, kMOTION_Commands_v, false) {} 
	};

	///WB interface for sending motion commands
        class MOTION_Commands_iTCP: public injection_whiteboard_object<class MOTION_Commands > { 
	public: 
		MOTION_Commands_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class MOTION_Commands >(hostname, kMOTION_Commands_v, is_async) {} 
	};

	///WB interface for checking the status of commands sent
        class MOTION_Status_t: public generic_whiteboard_object<class MOTION_Status > { 
	public: 
		MOTION_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class MOTION_Status >(wbd, kMOTION_Status_v, false) {} 
	};

	///WB interface for checking the status of commands sent
        class MOTION_Status_iTCP: public injection_whiteboard_object<class MOTION_Status > { 
	public: 
		MOTION_Status_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class MOTION_Status >(hostname, kMOTION_Status_v, is_async) {} 
	};

	/// *deprecated commented out of motion* Commands the slow walk that is built into the SDK
        class NaoWalk_t: public generic_whiteboard_object<std::vector<int> > { 
	public: 
		NaoWalk_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::vector<int> >(wbd, kNaoWalk_v, false) {}
		NaoWalk_t(std::vector<int> value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::vector<int> >(value, kNaoWalk_v, wbd, false) {} 
	};

	/// *deprecated commented out of motion* Commands the slow walk that is built into the SDK
        class NaoWalk_iTCP: public injection_whiteboard_object<std::vector<int> > { 
	public: 
		NaoWalk_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::vector<int> >(hostname, kNaoWalk_v, is_async) {}
		NaoWalk_iTCP(std::vector<int> value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::vector<int> >(value, hostname, kNaoWalk_v, is_async) {} 
	};

	/// *deprecated commented out of motion* State variable, is the slow SDK walk running (NaoWalk)
        class NaoWalkIsRunning_t: public generic_whiteboard_object<bool > { 
	public: 
		NaoWalkIsRunning_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kNaoWalkIsRunning_v, false) {}
		NaoWalkIsRunning_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kNaoWalkIsRunning_v, wbd, false) {} 
	};

	/// *deprecated commented out of motion* State variable, is the slow SDK walk running (NaoWalk)
        class NaoWalkIsRunning_iTCP: public injection_whiteboard_object<bool > { 
	public: 
		NaoWalkIsRunning_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<bool >(hostname, kNaoWalkIsRunning_v, is_async) {}
		NaoWalkIsRunning_iTCP(bool value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<bool >(value, hostname, kNaoWalkIsRunning_v, is_async) {} 
	};

	/// *deprecated use MOTION_SDK_Commands* Sets the head stiffness level, warning: this call may change and become part of the sensors / HAL module at a later date
        class HeadStiffness_t: public generic_whiteboard_object<float > { 
	public: 
		HeadStiffness_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<float >(wbd, kHeadStiffness_v, false) {}
		HeadStiffness_t(float value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<float >(value, kHeadStiffness_v, wbd, false) {} 
	};

	/// *deprecated use MOTION_SDK_Commands* Sets the head stiffness level, warning: this call may change and become part of the sensors / HAL module at a later date
        class HeadStiffness_iTCP: public injection_whiteboard_object<float > { 
	public: 
		HeadStiffness_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<float >(hostname, kHeadStiffness_v, is_async) {}
		HeadStiffness_iTCP(float value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<float >(value, hostname, kHeadStiffness_v, is_async) {} 
	};

	/// *deprecated use MOTION_SDK_Commands* Sets the body stiffness level, warning: this call may change and become part of the sensors / HAL module at a later date
        class HoldingStiffness_t: public generic_whiteboard_object<float > { 
	public: 
		HoldingStiffness_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<float >(wbd, kHoldingStiffness_v, false) {}
		HoldingStiffness_t(float value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<float >(value, kHoldingStiffness_v, wbd, false) {} 
	};

	/// *deprecated use MOTION_SDK_Commands* Sets the body stiffness level, warning: this call may change and become part of the sensors / HAL module at a later date
        class HoldingStiffness_iTCP: public injection_whiteboard_object<float > { 
	public: 
		HoldingStiffness_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<float >(hostname, kHoldingStiffness_v, is_async) {}
		HoldingStiffness_iTCP(float value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<float >(value, hostname, kHoldingStiffness_v, is_async) {} 
	};

	/// SDK wrapper function for moving any joint, be very careful
        class GenericAngleChange_t: public generic_whiteboard_object<std::vector<int> > { 
	public: 
		GenericAngleChange_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::vector<int> >(wbd, kGenericAngleChange_v, true) {}
		GenericAngleChange_t(std::vector<int> value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::vector<int> >(value, kGenericAngleChange_v, wbd, true) {} 
	};

	/// SDK wrapper function for moving any joint, be very careful
        class GenericAngleChange_iTCP: public injection_whiteboard_object<std::vector<int> > { 
	public: 
		GenericAngleChange_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::vector<int> >(hostname, kGenericAngleChange_v, is_async) {}
		GenericAngleChange_iTCP(std::vector<int> value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<std::vector<int> >(value, hostname, kGenericAngleChange_v, is_async) {} 
	};

	/// *deprecated use MOTION_SDK_Commands* State variable, is the joint SDK wrapper function running (kGenericAngleChange)
        class GenericAngleChangeIsRunning_t: public generic_whiteboard_object<bool > { 
	public: 
		GenericAngleChangeIsRunning_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kGenericAngleChangeIsRunning_v, false) {}
		GenericAngleChangeIsRunning_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kGenericAngleChangeIsRunning_v, wbd, false) {} 
	};

	/// *deprecated use MOTION_SDK_Commands* State variable, is the joint SDK wrapper function running (kGenericAngleChange)
        class GenericAngleChangeIsRunning_iTCP: public injection_whiteboard_object<bool > { 
	public: 
		GenericAngleChangeIsRunning_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<bool >(hostname, kGenericAngleChangeIsRunning_v, is_async) {}
		GenericAngleChangeIsRunning_iTCP(bool value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<bool >(value, hostname, kGenericAngleChangeIsRunning_v, is_async) {} 
	};

	///Used to alter the head position via the DCM
        class HAL_HeadTarget_t: public generic_whiteboard_object<class HAL_HeadTarget > { 
	public: 
		HAL_HeadTarget_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class HAL_HeadTarget >(wbd, kHAL_HeadTarget_v, false) {} 
	};

	///Used to alter the head position via the DCM
        class HAL_HeadTarget_iTCP: public injection_whiteboard_object<class HAL_HeadTarget > { 
	public: 
		HAL_HeadTarget_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class HAL_HeadTarget >(hostname, kHAL_HeadTarget_v, is_async) {} 
	};

	///Posts the sensor information for the feet via the DCM loop (read only)
        class SENSORS_FootSensors_t: public generic_whiteboard_object<class SENSORS_FootSensors > { 
	public: 
		SENSORS_FootSensors_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_FootSensors >(wbd, kSENSORS_FootSensors_v, false) {} 
	};

	///Posts the sensor information for the feet via the DCM loop (read only)
        class SENSORS_FootSensors_iTCP: public injection_whiteboard_object<class SENSORS_FootSensors > { 
	public: 
		SENSORS_FootSensors_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class SENSORS_FootSensors >(hostname, kSENSORS_FootSensors_v, is_async) {} 
	};

	///Posts the sensor information for the body via the DCM loop (read only)
        class SENSORS_BodySensors_t: public generic_whiteboard_object<class SENSORS_BodySensors > { 
	public: 
		SENSORS_BodySensors_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_BodySensors >(wbd, kSENSORS_BodySensors_v, false) {} 
	};

	///Posts the sensor information for the body via the DCM loop (read only)
        class SENSORS_BodySensors_iTCP: public injection_whiteboard_object<class SENSORS_BodySensors > { 
	public: 
		SENSORS_BodySensors_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class SENSORS_BodySensors >(hostname, kSENSORS_BodySensors_v, is_async) {} 
	};

	///Posts the current LEDs info, can be modified. (read/write)
        class SENSORS_LedsSensors_t: public generic_whiteboard_object<class SENSORS_LedsSensors > { 
	public: 
		SENSORS_LedsSensors_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_LedsSensors >(wbd, kSENSORS_LedsSensors_v, false) {} 
	};

	///Posts the current LEDs info, can be modified. (read/write)
        class SENSORS_LedsSensors_iTCP: public injection_whiteboard_object<class SENSORS_LedsSensors > { 
	public: 
		SENSORS_LedsSensors_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class SENSORS_LedsSensors >(hostname, kSENSORS_LedsSensors_v, is_async) {} 
	};

	///Posts the temperature of the leg joints via the DCM loop (read only)
        class SENSORS_LegJointTemps_t: public generic_whiteboard_object<class SENSORS_LegJointTemps > { 
	public: 
		SENSORS_LegJointTemps_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_LegJointTemps >(wbd, kSENSORS_LegJointTemps_v, false) {} 
	};

	///Posts the temperature of the leg joints via the DCM loop (read only)
        class SENSORS_LegJointTemps_iTCP: public injection_whiteboard_object<class SENSORS_LegJointTemps > { 
	public: 
		SENSORS_LegJointTemps_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class SENSORS_LegJointTemps >(hostname, kSENSORS_LegJointTemps_v, is_async) {} 
	};

	///Posts the temperature of the torso joints via the DCM loop (read only)
        class SENSORS_TorsoJointTemps_t: public generic_whiteboard_object<class SENSORS_TorsoJointTemps > { 
	public: 
		SENSORS_TorsoJointTemps_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_TorsoJointTemps >(wbd, kSENSORS_TorsoJointTemps_v, false) {} 
	};

	///Posts the temperature of the torso joints via the DCM loop (read only)
        class SENSORS_TorsoJointTemps_iTCP: public injection_whiteboard_object<class SENSORS_TorsoJointTemps > { 
	public: 
		SENSORS_TorsoJointTemps_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class SENSORS_TorsoJointTemps >(hostname, kSENSORS_TorsoJointTemps_v, is_async) {} 
	};

	///Posts the joint angles of the legs via the DCM loop (read only)
        class SENSORS_LegJointSensors_t: public generic_whiteboard_object<class SENSORS_LegJointSensors > { 
	public: 
		SENSORS_LegJointSensors_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_LegJointSensors >(wbd, kSENSORS_LegJointSensors_v, false) {} 
	};

	///Posts the joint angles of the legs via the DCM loop (read only)
        class SENSORS_LegJointSensors_iTCP: public injection_whiteboard_object<class SENSORS_LegJointSensors > { 
	public: 
		SENSORS_LegJointSensors_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class SENSORS_LegJointSensors >(hostname, kSENSORS_LegJointSensors_v, is_async) {} 
	};

	///Posts the joint angles of the torso via the DCM loop (read only)
        class SENSORS_TorsoJointSensors_t: public generic_whiteboard_object<class SENSORS_TorsoJointSensors > { 
	public: 
		SENSORS_TorsoJointSensors_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_TorsoJointSensors >(wbd, kSENSORS_TorsoJointSensors_v, false) {} 
	};

	///Posts the joint angles of the torso via the DCM loop (read only)
        class SENSORS_TorsoJointSensors_iTCP: public injection_whiteboard_object<class SENSORS_TorsoJointSensors > { 
	public: 
		SENSORS_TorsoJointSensors_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class SENSORS_TorsoJointSensors >(hostname, kSENSORS_TorsoJointSensors_v, is_async) {} 
	};

	///Posts the sonar readings via the DCM loop (read only)
        class SENSORS_SonarSensors_t: public generic_whiteboard_object<class SENSORS_SonarSensors > { 
	public: 
		SENSORS_SonarSensors_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_SonarSensors >(wbd, kSENSORS_SonarSensors_v, false) {} 
	};

	///Posts the sonar readings via the DCM loop (read only)
        class SENSORS_SonarSensors_iTCP: public injection_whiteboard_object<class SENSORS_SonarSensors > { 
	public: 
		SENSORS_SonarSensors_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class SENSORS_SonarSensors >(hostname, kSENSORS_SonarSensors_v, is_async) {} 
	};

	///Suspend, Resume, or Restart a finite state machine (clfsm)
        class FSM_Control_t: public generic_whiteboard_object<class FSMControlStatus > { 
	public: 
		FSM_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FSMControlStatus >(wbd, kFSM_Control_v, true) {} 
	};

	///Suspend, Resume, or Restart a finite state machine (clfsm)
        class FSM_Control_iTCP: public injection_whiteboard_object<class FSMControlStatus > { 
	public: 
		FSM_Control_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class FSMControlStatus >(hostname, kFSM_Control_v, is_async) {} 
	};

	///Current status indicating the suspended state of all FSMs.  The highest bit that is always set is the number of machines plus one.
        class FSM_Status_t: public generic_whiteboard_object<class FSMControlStatus > { 
	public: 
		FSM_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FSMControlStatus >(wbd, kFSM_Status_v, true) {} 
	};

	///Current status indicating the suspended state of all FSMs.  The highest bit that is always set is the number of machines plus one.
        class FSM_Status_iTCP: public injection_whiteboard_object<class FSMControlStatus > { 
	public: 
		FSM_Status_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class FSMControlStatus >(hostname, kFSM_Status_v, is_async) {} 
	};

	///Request or return the names of the currently loaded FSMs.  End of list is denoted by an empty string.  Requests need to put an empty string into the first FSM name;
        class FSM_Names_t: public generic_whiteboard_object<class FSMNames > { 
	public: 
		FSM_Names_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FSMNames >(wbd, kFSM_Names_v, true) {} 
	};

	///Request or return the names of the currently loaded FSMs.  End of list is denoted by an empty string.  Requests need to put an empty string into the first FSM name;
        class FSM_Names_iTCP: public injection_whiteboard_object<class FSMNames > { 
	public: 
		FSM_Names_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class FSMNames >(hostname, kFSM_Names_v, is_async) {} 
	};

	///WIP Class that contains the belief of the ball position from Localisation
        class BallBelief_t: public generic_whiteboard_object<class Point2D > { 
	public: 
		BallBelief_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Point2D >(wbd, kBallBelief_v, false) {} 
	};

	///WIP Class that contains the belief of the ball position from Localisation
        class BallBelief_iTCP: public injection_whiteboard_object<class Point2D > { 
	public: 
		BallBelief_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class Point2D >(hostname, kBallBelief_v, is_async) {} 
	};

	///Class that contains the Kalman filtered goal objects after sighting from vision
        class FilteredGoalSighting_t: public generic_whiteboard_object<class FilteredOneDimObjects > { 
	public: 
		FilteredGoalSighting_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FilteredOneDimObjects >(wbd, kFilteredGoalSighting_v, false) {} 
	};

	///Class that contains the Kalman filtered goal objects after sighting from vision
        class FilteredGoalSighting_iTCP: public injection_whiteboard_object<class FilteredOneDimObjects > { 
	public: 
		FilteredGoalSighting_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class FilteredOneDimObjects >(hostname, kFilteredGoalSighting_v, is_async) {} 
	};

	///Stores the orientation of the robot as well as the chest button status (more to come).
        class NAO_State_t: public generic_whiteboard_object<class NAO_State > { 
	public: 
		NAO_State_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class NAO_State >(wbd, kNAO_State_v, false) {} 
	};

	///Stores the orientation of the robot as well as the chest button status (more to come).
        class NAO_State_iTCP: public injection_whiteboard_object<class NAO_State > { 
	public: 
		NAO_State_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class NAO_State >(hostname, kNAO_State_v, is_async) {} 
	};

	///game state notfication from the UDP receiver.
        class UDPRN_t: public generic_whiteboard_object<class GCGameState > { 
	public: 
		UDPRN_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class GCGameState >(wbd, kUDPRN_v, false) {} 
	};

	///game state notfication from the UDP receiver.
        class UDPRN_iTCP: public injection_whiteboard_object<class GCGameState > { 
	public: 
		UDPRN_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class GCGameState >(hostname, kUDPRN_v, is_async) {} 
	};

	/// what player number is this robot wearing at RoboCup in its back, retrieved from data/playernumber and posted by the UDPreceiver
        class PlayerNumber_t: public generic_whiteboard_object<int > { 
	public: 
		PlayerNumber_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<int >(wbd, kPlayerNumber_v, false) {}
		PlayerNumber_t(int value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<int >(value, kPlayerNumber_v, wbd, false) {} 
	};

	/// what player number is this robot wearing at RoboCup in its back, retrieved from data/playernumber and posted by the UDPreceiver
        class PlayerNumber_iTCP: public injection_whiteboard_object<int > { 
	public: 
		PlayerNumber_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<int >(hostname, kPlayerNumber_v, is_async) {}
		PlayerNumber_iTCP(int value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<int >(value, hostname, kPlayerNumber_v, is_async) {} 
	};

	/// what player number is this robot wearing at RoboCup in its back whn manually penalized, from GameController FSM sent to the UDPreceiver to forward to the JAVA referee
        class ManuallyPenalized_t: public generic_whiteboard_object<int > { 
	public: 
		ManuallyPenalized_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<int >(wbd, kManuallyPenalized_v, false) {}
		ManuallyPenalized_t(int value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<int >(value, kManuallyPenalized_v, wbd, false) {} 
	};

	/// what player number is this robot wearing at RoboCup in its back whn manually penalized, from GameController FSM sent to the UDPreceiver to forward to the JAVA referee
        class ManuallyPenalized_iTCP: public injection_whiteboard_object<int > { 
	public: 
		ManuallyPenalized_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<int >(hostname, kManuallyPenalized_v, is_async) {}
		ManuallyPenalized_iTCP(int value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<int >(value, hostname, kManuallyPenalized_v, is_async) {} 
	};

	///control various attributes of the vision pipeline.
        class Vision_Control_t: public generic_whiteboard_object<class VisionControlStatus > { 
	public: 
		Vision_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class VisionControlStatus >(wbd, kVision_Control_v, false) {} 
	};

	///control various attributes of the vision pipeline.
        class Vision_Control_iTCP: public injection_whiteboard_object<class VisionControlStatus > { 
	public: 
		Vision_Control_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class VisionControlStatus >(hostname, kVision_Control_v, is_async) {} 
	};

	///message sent by vision that contains the current status of
        class Vision_Status_t: public generic_whiteboard_object<class VisionControlStatus > { 
	public: 
		Vision_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class VisionControlStatus >(wbd, kVision_Status_v, false) {} 
	};

	///message sent by vision that contains the current status of
        class Vision_Status_iTCP: public injection_whiteboard_object<class VisionControlStatus > { 
	public: 
		Vision_Status_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class VisionControlStatus >(hostname, kVision_Status_v, is_async) {} 
	};

	///message containing information about objects detected in last run of the pipeline
        class Vision_Objects_t: public generic_whiteboard_object<class VisionObjects > { 
	public: 
		Vision_Objects_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class VisionObjects >(wbd, kVision_Objects_v, true) {} 
	};

	///message containing information about objects detected in last run of the pipeline
        class Vision_Objects_iTCP: public injection_whiteboard_object<class VisionObjects > { 
	public: 
		Vision_Objects_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class VisionObjects >(hostname, kVision_Objects_v, is_async) {} 
	};

	///Class that contains the Karman filtered  iSONAR objects after a sighting
        class FSOsighting_t: public generic_whiteboard_object<class FilteredSonarObjects > { 
	public: 
		FSOsighting_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FilteredSonarObjects >(wbd, kFSOsighting_v, false) {} 
	};

	///Class that contains the Karman filtered  iSONAR objects after a sighting
        class FSOsighting_iTCP: public injection_whiteboard_object<class FilteredSonarObjects > { 
	public: 
		FSOsighting_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class FilteredSonarObjects >(hostname, kFSOsighting_v, is_async) {} 
	};

	///Class that contains the top particles for possible robot positions
        class TopParticles_t: public generic_whiteboard_object<class TopParticles > { 
	public: 
		TopParticles_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class TopParticles >(wbd, kTopParticles_v, false) {} 
	};

	///Class that contains the top particles for possible robot positions
        class TopParticles_iTCP: public injection_whiteboard_object<class TopParticles > { 
	public: 
		TopParticles_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class TopParticles >(hostname, kTopParticles_v, is_async) {} 
	};

	///Class that contains the Kalman filtered ball object after sighting from vision
        class FilteredBallSighting_t: public generic_whiteboard_object<class FilteredVisionObject > { 
	public: 
		FilteredBallSighting_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FilteredVisionObject >(wbd, kFilteredBallSighting_v, false) {} 
	};

	///Class that contains the Kalman filtered ball object after sighting from vision
        class FilteredBallSighting_iTCP: public injection_whiteboard_object<class FilteredVisionObject > { 
	public: 
		FilteredBallSighting_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true) : injection_whiteboard_object<class FilteredVisionObject >(hostname, kFilteredBallSighting_v, is_async) {} 
	};

	/// what to post in the whiteboard to cause the Particle Filetr to reset, but running has no effect, it is the PF response
        class PF_ControlStatus_Modes_t: public generic_whiteboard_object<int > { 
	public: 
		PF_ControlStatus_Modes_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<int >(wbd, kPF_ControlStatus_Modes_v, false) {}
		PF_ControlStatus_Modes_t(int value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<int >(value, kPF_ControlStatus_Modes_v, wbd, false) {} 
	};

	/// what to post in the whiteboard to cause the Particle Filetr to reset, but running has no effect, it is the PF response
        class PF_ControlStatus_Modes_iTCP: public injection_whiteboard_object<int > { 
	public: 
		PF_ControlStatus_Modes_iTCP(const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<int >(hostname, kPF_ControlStatus_Modes_v, is_async) {}
		PF_ControlStatus_Modes_iTCP(int value, const char *hostname = (const char *)"localhost", bool is_async = true): injection_whiteboard_object<int >(value, hostname, kPF_ControlStatus_Modes_v, is_async) {} 
	};

}

#pragma clang diagnostic pop

#endif                          
