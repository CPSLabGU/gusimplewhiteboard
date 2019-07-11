/**
 *  /file guwhiteboardtypelist_generated.h
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2018 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

#ifndef GUWHITEBOARDTYPELIST_GENERATED_H
#define GUWHITEBOARDTYPELIST_GENERATED_H

#include "gugenericwhiteboardobject.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wc++98-compat"


namespace guWhiteboard
{
extern "C"
{
#include "guwhiteboardtypelist_c_generated.h"
}

    /** WB Ptr Class: wb_reserved_SubscribeToAllTypes_t @brief Global subscription type. Do not add content to this type, it is for global subscriptions only */ 
    class wb_reserved_SubscribeToAllTypes_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: wb_reserved_SubscribeToAllTypes_t */ 
        wb_reserved_SubscribeToAllTypes_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kwb_reserved_SubscribeToAllTypes_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: wb_reserved_SubscribeToAllTypes_t */ 
wb_reserved_SubscribeToAllTypes_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kwb_reserved_SubscribeToAllTypes_v, wbd, true) {} 
    };

    /** WB Ptr Class: Print_t @brief print to stdout */ 
    class Print_t: public generic_whiteboard_object<std::string > { 
        public: 
        /** Constructor: Print_t */ 
        Print_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(wbd, kPrint_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: Print_t */ 
Print_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(value, kPrint_v, wbd, true) {} 
    };

    /** WB Ptr Class: Say_t @brief speech output message */ 
    class Say_t: public generic_whiteboard_object<std::string > { 
        public: 
        /** Constructor: Say_t */ 
        Say_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(wbd, kSay_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: Say_t */ 
Say_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(value, kSay_v, wbd, true) {} 
    };

    /** WB Ptr Class: Speech_t @brief debug speech message */ 
    class Speech_t: public generic_whiteboard_object<std::string > { 
        public: 
        /** Constructor: Speech_t */ 
        Speech_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(wbd, kSpeech_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: Speech_t */ 
Speech_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(value, kSpeech_v, wbd, true) {} 
    };

    /** WB Ptr Class: QSay_t @brief speech output message (queued) */ 
    class QSay_t: public generic_whiteboard_object<std::string > { 
        public: 
        /** Constructor: QSay_t */ 
        QSay_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(wbd, kQSay_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: QSay_t */ 
QSay_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(value, kQSay_v, wbd, true) {} 
    };

    /** WB Ptr Class: QSpeech_t @brief debug speech message (queued) */ 
    class QSpeech_t: public generic_whiteboard_object<std::string > { 
        public: 
        /** Constructor: QSpeech_t */ 
        QSpeech_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(wbd, kQSpeech_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: QSpeech_t */ 
QSpeech_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(value, kQSpeech_v, wbd, true) {} 
    };

    /** WB Ptr Class: SpeechOutput_t @brief toggle, treat speech messages as silent output unless this is turned on */ 
    class SpeechOutput_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: SpeechOutput_t */ 
        SpeechOutput_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kSpeechOutput_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: SpeechOutput_t */ 
SpeechOutput_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kSpeechOutput_v, wbd, false) {} 
    };

    /** WB Ptr Class: GCGameState_t @brief game state as posted by the game controller state machine */ 
    class GCGameState_t: public generic_whiteboard_object<class GCGameState > { 
        public: 
        /** Constructor: GCGameState_t */ 
        GCGameState_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class GCGameState >(wbd, kGCGameState_v, false) {}
        
    };

    /** WB Ptr Class: SensorsHandSensors_t @brief Posts the sensor information for the hands via the DCM loop (read only) */ 
    class SensorsHandSensors_t: public generic_whiteboard_object<class SensorsHandSensors > { 
        public: 
        /** Constructor: SensorsHandSensors_t */ 
        SensorsHandSensors_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SensorsHandSensors >(wbd, kSensorsHandSensors_v, false) {}
        
    };

    /** WB Ptr Class: SensorsHeadSensors_t @brief Posts the sensor information for the head via the DCM loop (read only) */ 
    class SensorsHeadSensors_t: public generic_whiteboard_object<class SensorsHeadSensors > { 
        public: 
        /** Constructor: SensorsHeadSensors_t */ 
        SensorsHeadSensors_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SensorsHeadSensors >(wbd, kSensorsHeadSensors_v, false) {}
        
    };

    /** WB Ptr Class: MOTION_Commands_t @brief WB interface for sending motion commands */ 
    class MOTION_Commands_t: public generic_whiteboard_object<class MOTION_Commands > { 
        public: 
        /** Constructor: MOTION_Commands_t */ 
        MOTION_Commands_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class MOTION_Commands >(wbd, kMOTION_Commands_v, false) {}
        
    };

    /** WB Ptr Class: MOTION_Status_t @brief WB interface for checking the status of commands sent */ 
    class MOTION_Status_t: public generic_whiteboard_object<class MOTION_Status > { 
        public: 
        /** Constructor: MOTION_Status_t */ 
        MOTION_Status_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class MOTION_Status >(wbd, kMOTION_Status_v, false) {}
        
    };

    /** WB Ptr Class: HAL_HeadTarget_t @brief Used to alter the head position via the DCM */ 
    class HAL_HeadTarget_t: public generic_whiteboard_object<class HAL_HeadTarget > { 
        public: 
        /** Constructor: HAL_HeadTarget_t */ 
        HAL_HeadTarget_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HAL_HeadTarget >(wbd, kHAL_HeadTarget_v, false) {}
        
    };

    /** WB Ptr Class: SensorsFootSensors_t @brief Posts the sensor information for the feet via the DCM loop (read only) */ 
    class SensorsFootSensors_t: public generic_whiteboard_object<class SensorsFootSensors > { 
        public: 
        /** Constructor: SensorsFootSensors_t */ 
        SensorsFootSensors_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SensorsFootSensors >(wbd, kSensorsFootSensors_v, false) {}
        
    };

    /** WB Ptr Class: SensorsBodySensors_t @brief Posts the sensor information for the body via the DCM loop (read only) */ 
    class SensorsBodySensors_t: public generic_whiteboard_object<class SensorsBodySensors > { 
        public: 
        /** Constructor: SensorsBodySensors_t */ 
        SensorsBodySensors_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SensorsBodySensors >(wbd, kSensorsBodySensors_v, false) {}
        
    };

    /** WB Ptr Class: SENSORSLedsSensors_t @brief Posts the current LEDs info, can be modified. (read/write) */ 
    class SENSORSLedsSensors_t: public generic_whiteboard_object<class SENSORSLedsSensors > { 
        public: 
        /** Constructor: SENSORSLedsSensors_t */ 
        SENSORSLedsSensors_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SENSORSLedsSensors >(wbd, kSENSORSLedsSensors_v, false) {}
        
    };

    /** WB Ptr Class: SENSORSLegJointTemps_t @brief Posts the temperature of the leg joints via the DCM loop (read only) */ 
    class SENSORSLegJointTemps_t: public generic_whiteboard_object<class SENSORSLegJointTemps > { 
        public: 
        /** Constructor: SENSORSLegJointTemps_t */ 
        SENSORSLegJointTemps_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SENSORSLegJointTemps >(wbd, kSENSORSLegJointTemps_v, false) {}
        
    };

    /** WB Ptr Class: SENSORSTorsoJointTemps_t @brief Posts the temperature of the torso joints via the DCM loop (read only) */ 
    class SENSORSTorsoJointTemps_t: public generic_whiteboard_object<class SENSORSTorsoJointTemps > { 
        public: 
        /** Constructor: SENSORSTorsoJointTemps_t */ 
        SENSORSTorsoJointTemps_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SENSORSTorsoJointTemps >(wbd, kSENSORSTorsoJointTemps_v, false) {}
        
    };

    /** WB Ptr Class: SENSORSLegJointSensors_t @brief Posts the joint angles of the legs via the DCM loop (read only) */ 
    class SENSORSLegJointSensors_t: public generic_whiteboard_object<class SENSORSLegJointSensors > { 
        public: 
        /** Constructor: SENSORSLegJointSensors_t */ 
        SENSORSLegJointSensors_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SENSORSLegJointSensors >(wbd, kSENSORSLegJointSensors_v, false) {}
        
    };

    /** WB Ptr Class: SENSORSTorsoJointSensors_t @brief Posts the joint angles of the torso via the DCM loop (read only) */ 
    class SENSORSTorsoJointSensors_t: public generic_whiteboard_object<class SENSORSTorsoJointSensors > { 
        public: 
        /** Constructor: SENSORSTorsoJointSensors_t */ 
        SENSORSTorsoJointSensors_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SENSORSTorsoJointSensors >(wbd, kSENSORSTorsoJointSensors_v, false) {}
        
    };

    /** WB Ptr Class: SENSORSSonarSensors_t @brief Posts the sonar readings via the DCM loop (read only) */ 
    class SENSORSSonarSensors_t: public generic_whiteboard_object<class SENSORSSonarSensors > { 
        public: 
        /** Constructor: SENSORSSonarSensors_t */ 
        SENSORSSonarSensors_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SENSORSSonarSensors >(wbd, kSENSORSSonarSensors_v, false) {}
        
    };

    /** WB Ptr Class: FSM_Control_t @brief Suspend, Resume, or Restart a finite state machine (clfsm) */ 
    class FSM_Control_t: public generic_whiteboard_object<class FSMControlStatus > { 
        public: 
        /** Constructor: FSM_Control_t */ 
        FSM_Control_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FSMControlStatus >(wbd, kFSM_Control_v, true) {}
        
    };

    /** WB Ptr Class: FSM_Status_t @brief Current status indicating the suspended state of all FSMs.  The highest bit that is always set is the number of machines plus one. */ 
    class FSM_Status_t: public generic_whiteboard_object<class FSMControlStatus > { 
        public: 
        /** Constructor: FSM_Status_t */ 
        FSM_Status_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FSMControlStatus >(wbd, kFSM_Status_v, true) {}
        
    };

    /** WB Ptr Class: FSM_Names_t @brief Request or return the names of the currently loaded FSMs.  End of list is denoted by an empty string.  Requests need to put an empty string into the first FSM name; */ 
    class FSM_Names_t: public generic_whiteboard_object<class FSMNames > { 
        public: 
        /** Constructor: FSM_Names_t */ 
        FSM_Names_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FSMNames >(wbd, kFSM_Names_v, true) {}
        
    };

    /** WB Ptr Class: SoloTypeExample_t @brief This is an example of a type definition that does not generate anything other than a wb type */ 
    class SoloTypeExample_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: SoloTypeExample_t */ 
        SoloTypeExample_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kSoloTypeExample_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: SoloTypeExample_t */ 
SoloTypeExample_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kSoloTypeExample_v, wbd, false) {} 
    };

    /** WB Ptr Class: FilteredGoalSighting_t @brief Class that contains the Kalman filtered goal objects after sighting from vision */ 
    class FilteredGoalSighting_t: public generic_whiteboard_object<class FilteredArrayOneDimObjects > { 
        public: 
        /** Constructor: FilteredGoalSighting_t */ 
        FilteredGoalSighting_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FilteredArrayOneDimObjects >(wbd, kFilteredGoalSighting_v, false) {}
        
    };

    /** WB Ptr Class: NAO_State_t @brief Stores the orientation of the robot as well as the chest button status (more to come). */ 
    class NAO_State_t: public generic_whiteboard_object<class NAO_State > { 
        public: 
        /** Constructor: NAO_State_t */ 
        NAO_State_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NAO_State >(wbd, kNAO_State_v, false) {}
        
    };

    /** WB Ptr Class: UDPRN_t @brief game state notfication from the UDP receiver. */ 
    class UDPRN_t: public generic_whiteboard_object<class GCGameState > { 
        public: 
        /** Constructor: UDPRN_t */ 
        UDPRN_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class GCGameState >(wbd, kUDPRN_v, false) {}
        
    };

    /** WB Ptr Class: PlayerNumber_t @brief what player number is this robot wearing at RoboCup in its back, retrieved from data/playernumber and posted by the UDPreceiver */ 
    class PlayerNumber_t: public generic_whiteboard_object<int8_t > { 
        public: 
        /** Constructor: PlayerNumber_t */ 
        PlayerNumber_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(wbd, kPlayerNumber_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: PlayerNumber_t */ 
PlayerNumber_t(int8_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(value, kPlayerNumber_v, wbd, false) {} 
    };

    /** WB Ptr Class: ManuallyPenalized_t @brief what player number is this robot wearing at RoboCup in its back whn manually penalized, from GameController FSM sent to the UDPreceiver to forward to the JAVA referee */ 
    class ManuallyPenalized_t: public generic_whiteboard_object<int8_t > { 
        public: 
        /** Constructor: ManuallyPenalized_t */ 
        ManuallyPenalized_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(wbd, kManuallyPenalized_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: ManuallyPenalized_t */ 
ManuallyPenalized_t(int8_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(value, kManuallyPenalized_v, wbd, false) {} 
    };

    /** WB Ptr Class: VisionControl_t @brief Used to set various paramaters of guvision */ 
    class VisionControl_t: public generic_whiteboard_object<class VisionControlStatus > { 
        public: 
        /** Constructor: VisionControl_t */ 
        VisionControl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionControlStatus >(wbd, kVisionControl_v, false) {}
        
    };

    /** WB Ptr Class: VisionStatus_t @brief Posted by guvision once per pipeline iteration to report various paramaters */ 
    class VisionStatus_t: public generic_whiteboard_object<class VisionControlStatus > { 
        public: 
        /** Constructor: VisionStatus_t */ 
        VisionStatus_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionControlStatus >(wbd, kVisionStatus_v, false) {}
        
    };

    /** WB Ptr Class: FFTStatus_t @brief stereo channel RMS and list of dominant frequencies from FFT */ 
    class FFTStatus_t: public generic_whiteboard_object<class FFTStatus > { 
        public: 
        /** Constructor: FFTStatus_t */ 
        FFTStatus_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FFTStatus >(wbd, kFFTStatus_v, false) {}
        
    };

    /** WB Ptr Class: FSOsighting_t @brief Class that contains the Karman filtered  SONAR objects after a sighting */ 
    class FSOsighting_t: public generic_whiteboard_object<class FilteredArrayOneDimSonar > { 
        public: 
        /** Constructor: FSOsighting_t */ 
        FSOsighting_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FilteredArrayOneDimSonar >(wbd, kFSOsighting_v, false) {}
        
    };

    /** WB Ptr Class: TopParticles_t @brief Class that contains the top particles for possible robot positions */ 
    class TopParticles_t: public generic_whiteboard_object<class TopParticles > { 
        public: 
        /** Constructor: TopParticles_t */ 
        TopParticles_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class TopParticles >(wbd, kTopParticles_v, false) {}
        
    };

    /** WB Ptr Class: FilteredBallSighting_t @brief Class that contains the Kalman filtered top and bottom ball objects after sighting from vision */ 
    class FilteredBallSighting_t: public generic_whiteboard_object<class FilteredArrayBallSightings > { 
        public: 
        /** Constructor: FilteredBallSighting_t */ 
        FilteredBallSighting_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FilteredArrayBallSightings >(wbd, kFilteredBallSighting_v, false) {}
        
    };

    /** WB Ptr Class: PF_ControlStatus_Modes_t @brief what to post in the whiteboard to cause the Particle Filetr to reset, but running has no effect, it is the PF response */ 
    class PF_ControlStatus_Modes_t: public generic_whiteboard_object<int32_t > { 
        public: 
        /** Constructor: PF_ControlStatus_Modes_t */ 
        PF_ControlStatus_Modes_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int32_t >(wbd, kPF_ControlStatus_Modes_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: PF_ControlStatus_Modes_t */ 
PF_ControlStatus_Modes_t(int32_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int32_t >(value, kPF_ControlStatus_Modes_v, wbd, false) {} 
    };

    /** WB Ptr Class: WEBOTS_NXT_bridge_t @brief WIP Class that contains a command for WEBOTS or NXt trough a bridge */ 
    class WEBOTS_NXT_bridge_t: public generic_whiteboard_object<class WEBOTS_NXT_bridge > { 
        public: 
        /** Constructor: WEBOTS_NXT_bridge_t */ 
        WEBOTS_NXT_bridge_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_bridge >(wbd, kWEBOTS_NXT_bridge_v, false) {}
        
    };

    /** WB Ptr Class: WEBOTS_NXT_encoders_t @brief Class that contains data from encoders all for WEBOTS or NXt trough a bridge */ 
    class WEBOTS_NXT_encoders_t: public generic_whiteboard_object<class WEBOTS_NXT_encoders > { 
        public: 
        /** Constructor: WEBOTS_NXT_encoders_t */ 
        WEBOTS_NXT_encoders_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_encoders >(wbd, kWEBOTS_NXT_encoders_v, false) {}
        
    };

    /** WB Ptr Class: WEBOTS_NXT_camera_t @brief Class that contains data from cameta channels of  WEBOTS trough a bridge */ 
    class WEBOTS_NXT_camera_t: public generic_whiteboard_object<class WEBOTS_NXT_camera > { 
        public: 
        /** Constructor: WEBOTS_NXT_camera_t */ 
        WEBOTS_NXT_camera_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_camera >(wbd, kWEBOTS_NXT_camera_v, false) {}
        
    };

    /** WB Ptr Class: WEBOTS_NXT_walk_isRunning_t @brief Class that contains boolean for checking if motion walks is running in  WEBOTS trough a bridge */ 
    class WEBOTS_NXT_walk_isRunning_t: public generic_whiteboard_object<class WEBOTS_NXT_walk_isRunning > { 
        public: 
        /** Constructor: WEBOTS_NXT_walk_isRunning_t */ 
        WEBOTS_NXT_walk_isRunning_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_walk_isRunning >(wbd, kWEBOTS_NXT_walk_isRunning_v, false) {}
        
    };

    /** WB Ptr Class: WEBOTS_NXT_deadReakoning_walk_t @brief Class for dead reckoning walks in  WEBOTS trough a bridge */ 
    class WEBOTS_NXT_deadReakoning_walk_t: public generic_whiteboard_object<class WEBOTS_NXT_deadReakoning_walk > { 
        public: 
        /** Constructor: WEBOTS_NXT_deadReakoning_walk_t */ 
        WEBOTS_NXT_deadReakoning_walk_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_deadReakoning_walk >(wbd, kWEBOTS_NXT_deadReakoning_walk_v, false) {}
        
    };

    /** WB Ptr Class: WEBOTS_NXT_colorLine_walk_t @brief Class for commands followign a line in  WEBOTS trough a bridge */ 
    class WEBOTS_NXT_colorLine_walk_t: public generic_whiteboard_object<class WEBOTS_NXT_colorLine_walk > { 
        public: 
        /** Constructor: WEBOTS_NXT_colorLine_walk_t */ 
        WEBOTS_NXT_colorLine_walk_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_colorLine_walk >(wbd, kWEBOTS_NXT_colorLine_walk_v, false) {}
        
    };

    /** WB Ptr Class: WEBOTS_NXT_gridMotions_t @brief Class for walks on a grid of colored lines for WEBOTS trough a bridge */ 
    class WEBOTS_NXT_gridMotions_t: public generic_whiteboard_object<class WEBOTS_NXT_gridMotions > { 
        public: 
        /** Constructor: WEBOTS_NXT_gridMotions_t */ 
        WEBOTS_NXT_gridMotions_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_gridMotions >(wbd, kWEBOTS_NXT_gridMotions_v, false) {}
        
    };

    /** WB Ptr Class: VisionBall_t @brief Class that reports the ball that vision sees. */ 
    class VisionBall_t: public generic_whiteboard_object<class VisionBall > { 
        public: 
        /** Constructor: VisionBall_t */ 
        VisionBall_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionBall >(wbd, kVisionBall_v, false) {}
        
    };

    /** WB Ptr Class: VisionGoals_t @brief Class that reports the goals that vision sees. */ 
    class VisionGoals_t: public generic_whiteboard_object<class VisionGoals > { 
        public: 
        /** Constructor: VisionGoals_t */ 
        VisionGoals_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionGoals >(wbd, kVisionGoals_v, false) {}
        
    };

    /** WB Ptr Class: WalkData_t @brief Class to report Walk Data. */ 
    class WalkData_t: public generic_whiteboard_object<class WalkData > { 
        public: 
        /** Constructor: WalkData_t */ 
        WalkData_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WalkData >(wbd, kWalkData_v, false) {}
        
    };

    /** WB Ptr Class: TeleoperationControlStatus_t @brief Class for sending teleoperation commands */ 
    class TeleoperationControlStatus_t: public generic_whiteboard_object<class TeleoperationControlStatus > { 
        public: 
        /** Constructor: TeleoperationControlStatus_t */ 
        TeleoperationControlStatus_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class TeleoperationControlStatus >(wbd, kTeleoperationControlStatus_v, false) {}
        
    };

    /** WB Ptr Class: TeleoperationConnection_t @brief Integer indication which remote whiteboard teleoperation instructions are on */ 
    class TeleoperationConnection_t: public generic_whiteboard_object<int8_t > { 
        public: 
        /** Constructor: TeleoperationConnection_t */ 
        TeleoperationConnection_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(wbd, kTeleoperationConnection_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: TeleoperationConnection_t */ 
TeleoperationConnection_t(int8_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(value, kTeleoperationConnection_v, wbd, false) {} 
    };

    /** WB Ptr Class: UDPWBNumber_t @brief ID number being used to broadcast udp whiteboard */ 
    class UDPWBNumber_t: public generic_whiteboard_object<int8_t > { 
        public: 
        /** Constructor: UDPWBNumber_t */ 
        UDPWBNumber_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(wbd, kUDPWBNumber_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: UDPWBNumber_t */ 
UDPWBNumber_t(int8_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(value, kUDPWBNumber_v, wbd, false) {} 
    };

    /** WB Ptr Class: WEBOTS_NXT_bumper_t @brief Class that contains data from 2 rouch sensors in an NXT bumper by the bridge */ 
    class WEBOTS_NXT_bumper_t: public generic_whiteboard_object<class WEBOTS_NXT_bumper > { 
        public: 
        /** Constructor: WEBOTS_NXT_bumper_t */ 
        WEBOTS_NXT_bumper_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_bumper >(wbd, kWEBOTS_NXT_bumper_v, false) {}
        
    };

    /** WB Ptr Class: WEBOTS_NXT_vector_bridge_t @brief Class that will define actuators for the Diferential motor bridge */ 
    class WEBOTS_NXT_vector_bridge_t: public generic_whiteboard_object<class WEBOTS_NXT_vector_bridge > { 
        public: 
        /** Constructor: WEBOTS_NXT_vector_bridge_t */ 
        WEBOTS_NXT_vector_bridge_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class WEBOTS_NXT_vector_bridge >(wbd, kWEBOTS_NXT_vector_bridge_v, false) {}
        
    };

    /** WB Ptr Class: VisionLines_t @brief Class that reports the lines that vision sees. */ 
    class VisionLines_t: public generic_whiteboard_object<class VisionLines > { 
        public: 
        /** Constructor: VisionLines_t */ 
        VisionLines_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionLines >(wbd, kVisionLines_v, false) {}
        
    };

    /** WB Ptr Class: DifferentialRobotStatus_t @brief Class that reads differential robot status */ 
    class DifferentialRobotStatus_t: public generic_whiteboard_object<class DifferentialRobotControlStatus > { 
        public: 
        /** Constructor: DifferentialRobotStatus_t */ 
        DifferentialRobotStatus_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class DifferentialRobotControlStatus >(wbd, kDifferentialRobotStatus_v, false) {}
        
    };

    /** WB Ptr Class: DifferentialRobotControl_t @brief Class that sends commands to the robot from the whiteboard */ 
    class DifferentialRobotControl_t: public generic_whiteboard_object<class DifferentialRobotControlStatus > { 
        public: 
        /** Constructor: DifferentialRobotControl_t */ 
        DifferentialRobotControl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class DifferentialRobotControlStatus >(wbd, kDifferentialRobotControl_v, false) {}
        
    };

    /** WB Ptr Class: XEyesPos_t @brief Just a hook for an xeyes interface */ 
    class XEyesPos_t: public generic_whiteboard_object<class Point2D > { 
        public: 
        /** Constructor: XEyesPos_t */ 
        XEyesPos_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Point2D >(wbd, kXEyesPos_v, true) {}
        
    };

    /** WB Ptr Class: VisionFace_t @brief Face seen by Vision */ 
    class VisionFace_t: public generic_whiteboard_object<std::vector<int> > { 
        public: 
        /** Constructor: VisionFace_t */ 
        VisionFace_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::vector<int> >(wbd, kVisionFace_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: VisionFace_t */ 
VisionFace_t(std::vector<int> value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::vector<int> >(value, kVisionFace_v, wbd, true) {} 
    };

    /** WB Ptr Class: Draw_t @brief Used by the half made GUDraw module in posix */ 
    class Draw_t: public generic_whiteboard_object<std::string > { 
        public: 
        /** Constructor: Draw_t */ 
        Draw_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(wbd, kDraw_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: Draw_t */ 
Draw_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(value, kDraw_v, wbd, true) {} 
    };

    /** WB Ptr Class: FSM_States_t @brief Idempotent Message publicising the state -about to be executed- (0-254) of up-to the first 128 machines (0-127).  State -INVALDMACHINE- (255) is posted for MachineIDs that are not currently loaded. */ 
    class FSM_States_t: public generic_whiteboard_object<class FSMState > { 
        public: 
        /** Constructor: FSM_States_t */ 
        FSM_States_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FSMState >(wbd, kFSM_States_v, true) {}
        
    };

    /** WB Ptr Class: Giraff_Interface_Status_t @brief Serial interface for the main motor and sensor board of the giraff */ 
    class Giraff_Interface_Status_t: public generic_whiteboard_object<class Giraff_MainSerialInterface > { 
        public: 
        /** Constructor: Giraff_Interface_Status_t */ 
        Giraff_Interface_Status_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Giraff_MainSerialInterface >(wbd, kGiraff_Interface_Status_v, false) {}
        
    };

    /** WB Ptr Class: Giraff_Interface_Command_t @brief Serial interface for the main motor and sensor board of the giraff */ 
    class Giraff_Interface_Command_t: public generic_whiteboard_object<class Giraff_MainSerialInterface > { 
        public: 
        /** Constructor: Giraff_Interface_Command_t */ 
        Giraff_Interface_Command_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Giraff_MainSerialInterface >(wbd, kGiraff_Interface_Command_v, false) {}
        
    };

    /** WB Ptr Class: NXT_Status_t @brief Contains sensor data as well as motor encoder data from the objects attached to an NXT */ 
    class NXT_Status_t: public generic_whiteboard_object<class NXT_Interface > { 
        public: 
        /** Constructor: NXT_Status_t */ 
        NXT_Status_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NXT_Interface >(wbd, kNXT_Status_v, false) {}
        
    };

    /** WB Ptr Class: NXT_Command_t @brief Can issue commands to set the motors of an NXT and reset the encoders */ 
    class NXT_Command_t: public generic_whiteboard_object<class NXT_Interface > { 
        public: 
        /** Constructor: NXT_Command_t */ 
        NXT_Command_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NXT_Interface >(wbd, kNXT_Command_v, false) {}
        
    };

    /** WB Ptr Class: APM_Status_t @brief Contains sensor data from an APM */ 
    class APM_Status_t: public generic_whiteboard_object<class APM_Interface > { 
        public: 
        /** Constructor: APM_Status_t */ 
        APM_Status_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class APM_Interface >(wbd, kAPM_Status_v, false) {}
        
    };

    /** WB Ptr Class: APM_Command_t @brief Can issue commands to an APM */ 
    class APM_Command_t: public generic_whiteboard_object<class APM_Interface > { 
        public: 
        /** Constructor: APM_Command_t */ 
        APM_Command_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class APM_Interface >(wbd, kAPM_Command_v, false) {}
        
    };

    /** WB Ptr Class: REMOVED3_t @brief Old class, can be removed from tsl file during the next wb version bump */ 
    class REMOVED3_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: REMOVED3_t */ 
        REMOVED3_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kREMOVED3_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: REMOVED3_t */ 
REMOVED3_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kREMOVED3_v, wbd, false) {} 
    };

    /** WB Ptr Class: REMOVED4_t @brief Old class, can be removed from tsl file during the next wb version bump */ 
    class REMOVED4_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: REMOVED4_t */ 
        REMOVED4_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kREMOVED4_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: REMOVED4_t */ 
REMOVED4_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kREMOVED4_v, wbd, false) {} 
    };

    /** WB Ptr Class: CBall_t @brief Status Message for the color of the ball */ 
    class CBall_t: public generic_whiteboard_object<int8_t > { 
        public: 
        /** Constructor: CBall_t */ 
        CBall_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(wbd, kCBall_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: CBall_t */ 
CBall_t(int8_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int8_t >(value, kCBall_v, wbd, true) {} 
    };

    /** WB Ptr Class: OculusPrime_Command_t @brief Class used to control the Oculus Prime movements, controls etc. */ 
    class OculusPrime_Command_t: public generic_whiteboard_object<class OculusPrimeInterface > { 
        public: 
        /** Constructor: OculusPrime_Command_t */ 
        OculusPrime_Command_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class OculusPrimeInterface >(wbd, kOculusPrime_Command_v, false) {}
        
    };

    /** WB Ptr Class: Input3D_t @brief for 3d input devices such as the leap or a joystick */ 
    class Input3D_t: public generic_whiteboard_object<class Input3D > { 
        public: 
        /** Constructor: Input3D_t */ 
        Input3D_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Input3D >(wbd, kInput3D_v, false) {}
        
    };

    /** WB Ptr Class: Oculus_Prime_Command_t @brief Serial interface for the main motor and sensor board of the oculus prime */ 
    class Oculus_Prime_Command_t: public generic_whiteboard_object<class Oculus_PrimeSerialInterface > { 
        public: 
        /** Constructor: Oculus_Prime_Command_t */ 
        Oculus_Prime_Command_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Oculus_PrimeSerialInterface >(wbd, kOculus_Prime_Command_v, false) {}
        
    };

    /** WB Ptr Class: IOPins_t @brief Arduino-style I/O pins */ 
    class IOPins_t: public generic_whiteboard_object<class IOPins > { 
        public: 
        /** Constructor: IOPins_t */ 
        IOPins_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class IOPins >(wbd, kIOPins_v, false) {}
        
    };

    /** WB Ptr Class: NXT_Two_Touch_Status_t @brief Class that reads NXT's two buttons */ 
    class NXT_Two_Touch_Status_t: public generic_whiteboard_object<class NXT_Two_Touch_Status > { 
        public: 
        /** Constructor: NXT_Two_Touch_Status_t */ 
        NXT_Two_Touch_Status_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NXT_Two_Touch_Status >(wbd, kNXT_Two_Touch_Status_v, false) {}
        
    };

    /** WB Ptr Class: NXT_Sound_Control_t @brief Class that produces NXT's sounds */ 
    class NXT_Sound_Control_t: public generic_whiteboard_object<class NXT_Sound_Control > { 
        public: 
        /** Constructor: NXT_Sound_Control_t */ 
        NXT_Sound_Control_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NXT_Sound_Control >(wbd, kNXT_Sound_Control_v, false) {}
        
    };

    /** WB Ptr Class: NXT_Lights_Control_t @brief Class that places power in NXT's for lights */ 
    class NXT_Lights_Control_t: public generic_whiteboard_object<class NXT_Lights_Control > { 
        public: 
        /** Constructor: NXT_Lights_Control_t */ 
        NXT_Lights_Control_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NXT_Lights_Control >(wbd, kNXT_Lights_Control_v, false) {}
        
    };

    /** WB Ptr Class: Clocks_t @brief Class for keeping track of time */ 
    class Clocks_t: public generic_whiteboard_object<class Clocks > { 
        public: 
        /** Constructor: Clocks_t */ 
        Clocks_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Clocks >(wbd, kClocks_v, false) {}
        
    };

    /** WB Ptr Class: Channels_t @brief UPPAAL-Style synchronisation channels */ 
    class Channels_t: public generic_whiteboard_object<class Channels > { 
        public: 
        /** Constructor: Channels_t */ 
        Channels_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Channels >(wbd, kChannels_v, false) {}
        
    };

    /** WB Ptr Class: SwitchSubsumption_t @brief Uncommented */ 
    class SwitchSubsumption_t: public generic_whiteboard_object<class SwitchSubsumption > { 
        public: 
        /** Constructor: SwitchSubsumption_t */ 
        SwitchSubsumption_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SwitchSubsumption >(wbd, kSwitchSubsumption_v, false) {}
        
    };

    /** WB Ptr Class: TotoDoingMotion_t @brief Uncommented */ 
    class TotoDoingMotion_t: public generic_whiteboard_object<class TotoDoingMotion > { 
        public: 
        /** Constructor: TotoDoingMotion_t */ 
        TotoDoingMotion_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class TotoDoingMotion >(wbd, kTotoDoingMotion_v, false) {}
        
    };

    /** WB Ptr Class: Count_t @brief Uncommented */ 
    class Count_t: public generic_whiteboard_object<class Count > { 
        public: 
        /** Constructor: Count_t */ 
        Count_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Count >(wbd, kCount_v, false) {}
        
    };

    /** WB Ptr Class: GreenEWon_t @brief status of the EWgreen light */ 
    class GreenEWon_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: GreenEWon_t */ 
        GreenEWon_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kGreenEWon_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: GreenEWon_t */ 
GreenEWon_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kGreenEWon_v, wbd, false) {} 
    };

    /** WB Ptr Class: WarnEW_t @brief status of the recommendaiton of the EW light */ 
    class WarnEW_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: WarnEW_t */ 
        WarnEW_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kWarnEW_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: WarnEW_t */ 
WarnEW_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kWarnEW_v, wbd, false) {} 
    };

    /** WB Ptr Class: TimeGTthirty_t @brief status of the timer with respect to 30 */ 
    class TimeGTthirty_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: TimeGTthirty_t */ 
        TimeGTthirty_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kTimeGTthirty_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: TimeGTthirty_t */ 
TimeGTthirty_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kTimeGTthirty_v, wbd, false) {} 
    };

    /** WB Ptr Class: AmberEWon_t @brief status of the EWamber light */ 
    class AmberEWon_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: AmberEWon_t */ 
        AmberEWon_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kAmberEWon_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: AmberEWon_t */ 
AmberEWon_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kAmberEWon_v, wbd, false) {} 
    };

    /** WB Ptr Class: TurnRedEW_t @brief second status of the recommendaiton of the EW light */ 
    class TurnRedEW_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: TurnRedEW_t */ 
        TurnRedEW_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kTurnRedEW_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: TurnRedEW_t */ 
TurnRedEW_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kTurnRedEW_v, wbd, false) {} 
    };

    /** WB Ptr Class: TimeGTfive_t @brief status of the timer with respect to 5 */ 
    class TimeGTfive_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: TimeGTfive_t */ 
        TimeGTfive_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kTimeGTfive_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: TimeGTfive_t */ 
TimeGTfive_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kTimeGTfive_v, wbd, false) {} 
    };

    /** WB Ptr Class: RedEWon_t @brief status of the EWred light */ 
    class RedEWon_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: RedEWon_t */ 
        RedEWon_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kRedEWon_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: RedEWon_t */ 
RedEWon_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kRedEWon_v, wbd, false) {} 
    };

    /** WB Ptr Class: GreenNSon_t @brief status of the NSgreen light */ 
    class GreenNSon_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: GreenNSon_t */ 
        GreenNSon_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kGreenNSon_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: GreenNSon_t */ 
GreenNSon_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kGreenNSon_v, wbd, false) {} 
    };

    /** WB Ptr Class: WarnNS_t @brief status of the recommendaiton of the NS light */ 
    class WarnNS_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: WarnNS_t */ 
        WarnNS_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kWarnNS_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: WarnNS_t */ 
WarnNS_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kWarnNS_v, wbd, false) {} 
    };

    /** WB Ptr Class: AmberNSon_t @brief status of the NSamber light */ 
    class AmberNSon_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: AmberNSon_t */ 
        AmberNSon_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kAmberNSon_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: AmberNSon_t */ 
AmberNSon_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kAmberNSon_v, wbd, false) {} 
    };

    /** WB Ptr Class: TurnRedNS_t @brief second status of the recommendaiton of the NS light */ 
    class TurnRedNS_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: TurnRedNS_t */ 
        TurnRedNS_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kTurnRedNS_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: TurnRedNS_t */ 
TurnRedNS_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kTurnRedNS_v, wbd, false) {} 
    };

    /** WB Ptr Class: RedNSon_t @brief status of the NSred light */ 
    class RedNSon_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: RedNSon_t */ 
        RedNSon_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kRedNSon_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: RedNSon_t */ 
RedNSon_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kRedNSon_v, wbd, false) {} 
    };

    /** WB Ptr Class: TimerReset_t @brief flag to reset timer */ 
    class TimerReset_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: TimerReset_t */ 
        TimerReset_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kTimerReset_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: TimerReset_t */ 
TimerReset_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kTimerReset_v, wbd, false) {} 
    };

    /** WB Ptr Class: SLOT_UNUSED_t @brief IoT message removed, feel free to use this slot */ 
    class SLOT_UNUSED_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: SLOT_UNUSED_t */ 
        SLOT_UNUSED_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kSLOT_UNUSED_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: SLOT_UNUSED_t */ 
SLOT_UNUSED_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kSLOT_UNUSED_v, wbd, false) {} 
    };

    /** WB Ptr Class: CarSensorPressed_t @brief flag to indicate status of sensor for cars */ 
    class CarSensorPressed_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: CarSensorPressed_t */ 
        CarSensorPressed_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kCarSensorPressed_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: CarSensorPressed_t */ 
CarSensorPressed_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kCarSensorPressed_v, wbd, false) {} 
    };

    /** WB Ptr Class: SwitchSubsumptionTrafficLights_t @brief no comment entered */ 
    class SwitchSubsumptionTrafficLights_t: public generic_whiteboard_object<class SwitchSubsumptionTrafficLights > { 
        public: 
        /** Constructor: SwitchSubsumptionTrafficLights_t */ 
        SwitchSubsumptionTrafficLights_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class SwitchSubsumptionTrafficLights >(wbd, kSwitchSubsumptionTrafficLights_v, false) {}
        
    };

    /** WB Ptr Class: Ball_Found_t @brief whether ball is detected in STEM6 DetectBallColor */ 
    class Ball_Found_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: Ball_Found_t */ 
        Ball_Found_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kBall_Found_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: Ball_Found_t */ 
Ball_Found_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kBall_Found_v, wbd, false) {} 
    };

    /** WB Ptr Class: Ball_Calibration_File_t @brief name of DLC file to load for STEM6 DetectBallColor */ 
    class Ball_Calibration_File_t: public generic_whiteboard_object<std::string > { 
        public: 
        /** Constructor: Ball_Calibration_File_t */ 
        Ball_Calibration_File_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(wbd, kBall_Calibration_File_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: Ball_Calibration_File_t */ 
Ball_Calibration_File_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(value, kBall_Calibration_File_v, wbd, false) {} 
    };

    /** WB Ptr Class: Ball_Calibration_Num_t @brief number (size_t) to load with DLC file for STEM6 DetectBallColor */ 
    class Ball_Calibration_Num_t: public generic_whiteboard_object<int32_t > { 
        public: 
        /** Constructor: Ball_Calibration_Num_t */ 
        Ball_Calibration_Num_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int32_t >(wbd, kBall_Calibration_Num_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: Ball_Calibration_Num_t */ 
Ball_Calibration_Num_t(int32_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int32_t >(value, kBall_Calibration_Num_v, wbd, false) {} 
    };

    /** WB Ptr Class: Ball_Color_Num_t @brief number for each ball color as defined in STEM6Master */ 
    class Ball_Color_Num_t: public generic_whiteboard_object<int32_t > { 
        public: 
        /** Constructor: Ball_Color_Num_t */ 
        Ball_Color_Num_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int32_t >(wbd, kBall_Color_Num_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: Ball_Color_Num_t */ 
Ball_Color_Num_t(int32_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<int32_t >(value, kBall_Color_Num_v, wbd, false) {} 
    };

    /** WB Ptr Class: HAL_LArmTarget_Ctrl_t @brief Used to control the left arm via DCM */ 
    class HAL_LArmTarget_Ctrl_t: public generic_whiteboard_object<class HalArmTarget > { 
        public: 
        /** Constructor: HAL_LArmTarget_Ctrl_t */ 
        HAL_LArmTarget_Ctrl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalArmTarget >(wbd, kHAL_LArmTarget_Ctrl_v, false) {}
        
    };

    /** WB Ptr Class: HAL_LArmTarget_Stat_t @brief Used to report DCM status of the left arm */ 
    class HAL_LArmTarget_Stat_t: public generic_whiteboard_object<class HalArmTarget > { 
        public: 
        /** Constructor: HAL_LArmTarget_Stat_t */ 
        HAL_LArmTarget_Stat_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalArmTarget >(wbd, kHAL_LArmTarget_Stat_v, false) {}
        
    };

    /** WB Ptr Class: HAL_LArmTarget_Tolr_t @brief Used to set the joing angle tolerance for motion completion detection. */ 
    class HAL_LArmTarget_Tolr_t: public generic_whiteboard_object<class HalArmTarget > { 
        public: 
        /** Constructor: HAL_LArmTarget_Tolr_t */ 
        HAL_LArmTarget_Tolr_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalArmTarget >(wbd, kHAL_LArmTarget_Tolr_v, false) {}
        
    };

    /** WB Ptr Class: HAL_RArmTarget_Ctrl_t @brief Used to control the right arm via DCM */ 
    class HAL_RArmTarget_Ctrl_t: public generic_whiteboard_object<class HalArmTarget > { 
        public: 
        /** Constructor: HAL_RArmTarget_Ctrl_t */ 
        HAL_RArmTarget_Ctrl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalArmTarget >(wbd, kHAL_RArmTarget_Ctrl_v, false) {}
        
    };

    /** WB Ptr Class: HAL_RArmTarget_Stat_t @brief Used to report DCM status of the right arm */ 
    class HAL_RArmTarget_Stat_t: public generic_whiteboard_object<class HalArmTarget > { 
        public: 
        /** Constructor: HAL_RArmTarget_Stat_t */ 
        HAL_RArmTarget_Stat_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalArmTarget >(wbd, kHAL_RArmTarget_Stat_v, false) {}
        
    };

    /** WB Ptr Class: HAL_RArmTarget_Tolr_t @brief Used to set the joing angle tolerance for motion completion detection. */ 
    class HAL_RArmTarget_Tolr_t: public generic_whiteboard_object<class HalArmTarget > { 
        public: 
        /** Constructor: HAL_RArmTarget_Tolr_t */ 
        HAL_RArmTarget_Tolr_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalArmTarget >(wbd, kHAL_RArmTarget_Tolr_v, false) {}
        
    };

    /** WB Ptr Class: VisionFieldFeatures_t @brief Posts information from vision about field corners and intersections */ 
    class VisionFieldFeatures_t: public generic_whiteboard_object<class VisionFieldFeatures > { 
        public: 
        /** Constructor: VisionFieldFeatures_t */ 
        VisionFieldFeatures_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionFieldFeatures >(wbd, kVisionFieldFeatures_v, false) {}
        
    };

    /** WB Ptr Class: WhistleBlown_t @brief Whistle blown flag */ 
    class WhistleBlown_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: WhistleBlown_t */ 
        WhistleBlown_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kWhistleBlown_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: WhistleBlown_t */ 
WhistleBlown_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kWhistleBlown_v, wbd, false) {} 
    };

    /** WB Ptr Class: VolumeControl_t @brief Variable used by SMVolumeController to control the volume via pulse audio commands */ 
    class VolumeControl_t: public generic_whiteboard_object<uint8_t > { 
        public: 
        /** Constructor: VolumeControl_t */ 
        VolumeControl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<uint8_t >(wbd, kVolumeControl_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: VolumeControl_t */ 
VolumeControl_t(uint8_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<uint8_t >(value, kVolumeControl_v, wbd, false) {} 
    };

    /** WB Ptr Class: VisionRobots_t @brief Class that reports the robots that vision sees. */ 
    class VisionRobots_t: public generic_whiteboard_object<class VisionRobots > { 
        public: 
        /** Constructor: VisionRobots_t */ 
        VisionRobots_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionRobots >(wbd, kVisionRobots_v, false) {}
        
    };

    /** WB Ptr Class: VisionDetectionHorizons_t @brief Class that reports the edge of an SPL field (the edge of the green bit). Array of two values, one for each camera. */ 
    class VisionDetectionHorizons_t: public generic_whiteboard_object<class VisionDetectionHorizons > { 
        public: 
        /** Constructor: VisionDetectionHorizons_t */ 
        VisionDetectionHorizons_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionDetectionHorizons >(wbd, kVisionDetectionHorizons_v, false) {}
        
    };

    /** WB Ptr Class: NaoWalkCommand_t @brief Class that controls the latest version of the UNSW 2014 walk engine. */ 
    class NaoWalkCommand_t: public generic_whiteboard_object<class NaoWalkCommand > { 
        public: 
        /** Constructor: NaoWalkCommand_t */ 
        NaoWalkCommand_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NaoWalkCommand >(wbd, kNaoWalkCommand_v, false) {}
        
    };

    /** WB Ptr Class: NaoWalkStatus_t @brief Status class for the latest version of the UNSW 2014 walk engine. */ 
    class NaoWalkStatus_t: public generic_whiteboard_object<class NaoWalkStatus > { 
        public: 
        /** Constructor: NaoWalkStatus_t */ 
        NaoWalkStatus_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NaoWalkStatus >(wbd, kNaoWalkStatus_v, false) {}
        
    };

    /** WB Ptr Class: HAL_LLegTarget_Ctrl_t @brief Used to control the left leg via DCM */ 
    class HAL_LLegTarget_Ctrl_t: public generic_whiteboard_object<class HalLegTarget > { 
        public: 
        /** Constructor: HAL_LLegTarget_Ctrl_t */ 
        HAL_LLegTarget_Ctrl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalLegTarget >(wbd, kHAL_LLegTarget_Ctrl_v, false) {}
        
    };

    /** WB Ptr Class: HAL_LLegTarget_Stat_t @brief Used to report DCM status of the left leg */ 
    class HAL_LLegTarget_Stat_t: public generic_whiteboard_object<class HalLegTarget > { 
        public: 
        /** Constructor: HAL_LLegTarget_Stat_t */ 
        HAL_LLegTarget_Stat_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalLegTarget >(wbd, kHAL_LLegTarget_Stat_v, false) {}
        
    };

    /** WB Ptr Class: HAL_LLegTarget_Tolr_t @brief Used to set the joing angle tolerance for motion completion detection. */ 
    class HAL_LLegTarget_Tolr_t: public generic_whiteboard_object<class HalLegTarget > { 
        public: 
        /** Constructor: HAL_LLegTarget_Tolr_t */ 
        HAL_LLegTarget_Tolr_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalLegTarget >(wbd, kHAL_LLegTarget_Tolr_v, false) {}
        
    };

    /** WB Ptr Class: HAL_RLegTarget_Ctrl_t @brief Used to control the right leg via DCM */ 
    class HAL_RLegTarget_Ctrl_t: public generic_whiteboard_object<class HalLegTarget > { 
        public: 
        /** Constructor: HAL_RLegTarget_Ctrl_t */ 
        HAL_RLegTarget_Ctrl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalLegTarget >(wbd, kHAL_RLegTarget_Ctrl_v, false) {}
        
    };

    /** WB Ptr Class: HAL_RLegTarget_Stat_t @brief Used to report DCM status of the right leg */ 
    class HAL_RLegTarget_Stat_t: public generic_whiteboard_object<class HalLegTarget > { 
        public: 
        /** Constructor: HAL_RLegTarget_Stat_t */ 
        HAL_RLegTarget_Stat_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalLegTarget >(wbd, kHAL_RLegTarget_Stat_v, false) {}
        
    };

    /** WB Ptr Class: HAL_RLegTarget_Tolr_t @brief Used to set the joing angle tolerance for motion completion detection. */ 
    class HAL_RLegTarget_Tolr_t: public generic_whiteboard_object<class HalLegTarget > { 
        public: 
        /** Constructor: HAL_RLegTarget_Tolr_t */ 
        HAL_RLegTarget_Tolr_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class HalLegTarget >(wbd, kHAL_RLegTarget_Tolr_v, false) {}
        
    };

    /** WB Ptr Class: VisionDetectionGoals_t @brief Reports robocup spl goals found with guvision and GoalRayTracer. */ 
    class VisionDetectionGoals_t: public generic_whiteboard_object<class VisionDetectionGoals > { 
        public: 
        /** Constructor: VisionDetectionGoals_t */ 
        VisionDetectionGoals_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionDetectionGoals >(wbd, kVisionDetectionGoals_v, false) {}
        
    };

    /** WB Ptr Class: TeleoperationControl_t @brief Control message for teleop VR app */ 
    class TeleoperationControl_t: public generic_whiteboard_object<class TeleoperationControl > { 
        public: 
        /** Constructor: TeleoperationControl_t */ 
        TeleoperationControl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class TeleoperationControl >(wbd, kTeleoperationControl_v, false) {}
        
    };

    /** WB Ptr Class: TeleoperationStatus_t @brief Status message for teleop VR app */ 
    class TeleoperationStatus_t: public generic_whiteboard_object<class TeleoperationStatus > { 
        public: 
        /** Constructor: TeleoperationStatus_t */ 
        TeleoperationStatus_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class TeleoperationStatus >(wbd, kTeleoperationStatus_v, false) {}
        
    };

    /** WB Ptr Class: VisionDetectionBalls_t @brief Reports robocup spl ball found with guvision and BallRayTracer. */ 
    class VisionDetectionBalls_t: public generic_whiteboard_object<class VisionDetectionBalls > { 
        public: 
        /** Constructor: VisionDetectionBalls_t */ 
        VisionDetectionBalls_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class VisionDetectionBalls >(wbd, kVisionDetectionBalls_v, false) {}
        
    };

    /** WB Ptr Class: TeleoperationControlVR_t @brief Virtual Reality extended class */ 
    class TeleoperationControlVR_t: public generic_whiteboard_object<class TeleoperationControlVR > { 
        public: 
        /** Constructor: TeleoperationControlVR_t */ 
        TeleoperationControlVR_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class TeleoperationControlVR >(wbd, kTeleoperationControlVR_v, false) {}
        
    };

    /** WB Ptr Class: ParticleOutputMap_t @brief Contains a path to a file containing the list of particles posted by the particle filter. */ 
    class ParticleOutputMap_t: public generic_whiteboard_object<uint64_t > { 
        public: 
        /** Constructor: ParticleOutputMap_t */ 
        ParticleOutputMap_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<uint64_t >(wbd, kParticleOutputMap_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: ParticleOutputMap_t */ 
ParticleOutputMap_t(uint64_t value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<uint64_t >(value, kParticleOutputMap_v, wbd, false) {} 
    };

    /** WB Ptr Class: ParticleOutputMapControl_t @brief Posted by readers of the particles list to notify the filter to swap buffers. */ 
    class ParticleOutputMapControl_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: ParticleOutputMapControl_t */ 
        ParticleOutputMapControl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kParticleOutputMapControl_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: ParticleOutputMapControl_t */ 
ParticleOutputMapControl_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kParticleOutputMapControl_v, wbd, false) {} 
    };

    /** WB Ptr Class: FFTControl_t @brief Turn on or off the FFT module */ 
    class FFTControl_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: FFTControl_t */ 
        FFTControl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kFFTControl_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: FFTControl_t */ 
FFTControl_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kFFTControl_v, wbd, false) {} 
    };

    /** WB Ptr Class: MachineFilteredNaoVision_t @brief Vision filtering and distance estimates. */ 
    class MachineFilteredNaoVision_t: public generic_whiteboard_object<class MachineFilteredVision > { 
        public: 
        /** Constructor: MachineFilteredNaoVision_t */ 
        MachineFilteredNaoVision_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class MachineFilteredVision >(wbd, kMachineFilteredNaoVision_v, false) {}
        
    };

    /** WB Ptr Class: MicrowaveStatus_t @brief External Variables for the One Minute Microwave. */ 
    class MicrowaveStatus_t: public generic_whiteboard_object<class MicrowaveStatus > { 
        public: 
        /** Constructor: MicrowaveStatus_t */ 
        MicrowaveStatus_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class MicrowaveStatus >(wbd, kMicrowaveStatus_v, false) {}
        
    };

    /** WB Ptr Class: Buttons_t @brief External Variables for the Incrementing LLFSM. */ 
    class Buttons_t: public generic_whiteboard_object<class Buttons > { 
        public: 
        /** Constructor: Buttons_t */ 
        Buttons_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Buttons >(wbd, kButtons_v, false) {}
        
    };

    /** WB Ptr Class: MachineFilteredLocalisationVision_t @brief Vision filtering and distance estimates for landmarks: goal, lines and horizon. */ 
    class MachineFilteredLocalisationVision_t: public generic_whiteboard_object<class MachineFilteredLocalisationVision > { 
        public: 
        /** Constructor: MachineFilteredLocalisationVision_t */ 
        MachineFilteredLocalisationVision_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class MachineFilteredLocalisationVision >(wbd, kMachineFilteredLocalisationVision_v, false) {}
        
    };

    /** WB Ptr Class: SensorsJointCurrent_t @brief Posts the current flowing through each joint via the DCM loop (read only) */ 
    class SensorsJointCurrent_t: public generic_whiteboard_object<class NaoJointListFloat > { 
        public: 
        /** Constructor: SensorsJointCurrent_t */ 
        SensorsJointCurrent_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NaoJointListFloat >(wbd, kSensorsJointCurrent_v, false) {}
        
    };

    /** WB Ptr Class: DataLogger_t @brief Controls the data logging within Naoqi Interface */ 
    class DataLogger_t: public generic_whiteboard_object<class DataLogger > { 
        public: 
        /** Constructor: DataLogger_t */ 
        DataLogger_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class DataLogger >(wbd, kDataLogger_v, false) {}
        
    };

    /** WB Ptr Class: MachineFilteredLines_t @brief Vision filtering and distance estimates for lines. */ 
    class MachineFilteredLines_t: public generic_whiteboard_object<class MachineFilteredLines > { 
        public: 
        /** Constructor: MachineFilteredLines_t */ 
        MachineFilteredLines_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class MachineFilteredLines >(wbd, kMachineFilteredLines_v, false) {}
        
    };

    /** WB Ptr Class: BallLocation_t @brief Location of the ball. */ 
    class BallLocation_t: public generic_whiteboard_object<class Location > { 
        public: 
        /** Constructor: BallLocation_t */ 
        BallLocation_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Location >(wbd, kBallLocation_v, false) {}
        
    };

    /** WB Ptr Class: LeftGoalPostLocation_t @brief Location of the left goal post. */ 
    class LeftGoalPostLocation_t: public generic_whiteboard_object<class Location > { 
        public: 
        /** Constructor: LeftGoalPostLocation_t */ 
        LeftGoalPostLocation_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Location >(wbd, kLeftGoalPostLocation_v, false) {}
        
    };

    /** WB Ptr Class: RightGoalPostLocation_t @brief Location of the right goal post. */ 
    class RightGoalPostLocation_t: public generic_whiteboard_object<class Location > { 
        public: 
        /** Constructor: RightGoalPostLocation_t */ 
        RightGoalPostLocation_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Location >(wbd, kRightGoalPostLocation_v, false) {}
        
    };

    /** WB Ptr Class: GoalLocation_t @brief Location of the goal. */ 
    class GoalLocation_t: public generic_whiteboard_object<class Location > { 
        public: 
        /** Constructor: GoalLocation_t */ 
        GoalLocation_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class Location >(wbd, kGoalLocation_v, false) {}
        
    };

    /** WB Ptr Class: NaoSonarProtectedWalkCommand_t @brief Send walk protected by sonar. */ 
    class NaoSonarProtectedWalkCommand_t: public generic_whiteboard_object<class NaoSonarProtectedWalkCommand > { 
        public: 
        /** Constructor: NaoSonarProtectedWalkCommand_t */ 
        NaoSonarProtectedWalkCommand_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NaoSonarProtectedWalkCommand >(wbd, kNaoSonarProtectedWalkCommand_v, false) {}
        
    };

    /** WB Ptr Class: NaoObstacleDirection_t @brief Send general direction if obstacle. */ 
    class NaoObstacleDirection_t: public generic_whiteboard_object<class NaoObstacleDirection > { 
        public: 
        /** Constructor: NaoObstacleDirection_t */ 
        NaoObstacleDirection_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class NaoObstacleDirection >(wbd, kNaoObstacleDirection_v, false) {}
        
    };

    /** WB Ptr Class: DominantFrequencies_t @brief Dominant frequencies and RMS levels for the four microphones */ 
    class DominantFrequencies_t: public generic_whiteboard_object<class DominantFrequencies > { 
        public: 
        /** Constructor: DominantFrequencies_t */ 
        DominantFrequencies_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class DominantFrequencies >(wbd, kDominantFrequencies_v, false) {}
        
    };

    /** WB Ptr Class: MissionPriorityForObstacles_t @brief notify trough the whiteboard the priority of the mission, high for chasing the ball, low for getting to a place in the field. */ 
    class MissionPriorityForObstacles_t: public generic_whiteboard_object<class MissionPriorityForObstacles > { 
        public: 
        /** Constructor: MissionPriorityForObstacles_t */ 
        MissionPriorityForObstacles_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class MissionPriorityForObstacles >(wbd, kMissionPriorityForObstacles_v, false) {}
        
    };

    /** WB Ptr Class: WavLoad_t @brief request to load a wav file */ 
    class WavLoad_t: public generic_whiteboard_object<std::string > { 
        public: 
        /** Constructor: WavLoad_t */ 
        WavLoad_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(wbd, kWavLoad_v, true) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: WavLoad_t */ 
WavLoad_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<std::string >(value, kWavLoad_v, wbd, true) {} 
    };

    /** WB Ptr Class: WavPlay_t @brief forced, treat request to play wav file as forced output and sound will come out even if reproduce on is silent */ 
    class WavPlay_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: WavPlay_t */ 
        WavPlay_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kWavPlay_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: WavPlay_t */ 
WavPlay_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kWavPlay_v, wbd, false) {} 
    };

    /** WB Ptr Class: ReproduceWavNotSilent_t @brief toggle, treat request to play wav file as silent output unless this is turned on but can be overwritten by forced in WavPlay */ 
    class ReproduceWavNotSilent_t: public generic_whiteboard_object<bool > { 
        public: 
        /** Constructor: ReproduceWavNotSilent_t */ 
        ReproduceWavNotSilent_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(wbd, kReproduceWavNotSilent_v, false) {}
        /** Convenience constructor for non-class types. Pass a value and it'll be set in the Whiteboard: ReproduceWavNotSilent_t */ 
ReproduceWavNotSilent_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<bool >(value, kReproduceWavNotSilent_v, wbd, false) {} 
    };

    /** WB Ptr Class: FrequencyControl_t @brief Frequency limits control message for FFT analysis */ 
    class FrequencyControl_t: public generic_whiteboard_object<class FrequencyLimits > { 
        public: 
        /** Constructor: FrequencyControl_t */ 
        FrequencyControl_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FrequencyLimits >(wbd, kFrequencyControl_v, false) {}
        
    };

    /** WB Ptr Class: FrequencyStatus_t @brief Current Frequency limits (status) for FFT analysis */ 
    class FrequencyStatus_t: public generic_whiteboard_object<class FrequencyLimits > { 
        public: 
        /** Constructor: FrequencyStatus_t */ 
        FrequencyStatus_t(gu_simple_whiteboard_descriptor *wbd = NULLPTR): generic_whiteboard_object<class FrequencyLimits >(wbd, kFrequencyStatus_v, false) {}
        
    };


}

#pragma clang diagnostic pop

#endif //GUWHITEBOARDTYPELIST_GENERATED_H
