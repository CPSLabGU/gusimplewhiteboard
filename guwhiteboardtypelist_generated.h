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
                                                                        
                                                                        
//Generated on: Sat Mar 23 19:15:59 2013
//Generated by user: rh
                              
namespace guWhiteboard                                                  
{                                                                       
                                                                        
extern "C"                                                            
{                                                                       
#include "guwhiteboardtypelist_c_generated.h"                         
}                                                                       
                                                                        
	/// print to stdout
        class Print_t: public generic_whiteboard_object<std::string > { public: Print_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kPrint_v) {}
		Print_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kPrint_v, wbd) {} };

	/// speech output message
        class Say_t: public generic_whiteboard_object<std::string > { public: Say_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kSay_v) {}
		Say_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kSay_v, wbd) {} };

	/// debug speech message
        class Speech_t: public generic_whiteboard_object<std::string > { public: Speech_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kSpeech_v) {}
		Speech_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kSpeech_v, wbd) {} };

	/// speech output message (queued)
        class QSay_t: public generic_whiteboard_object<std::string > { public: QSay_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kQSay_v) {}
		QSay_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kQSay_v, wbd) {} };

	/// debug speech message (queued)
        class QSpeech_t: public generic_whiteboard_object<std::string > { public: QSpeech_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kQSpeech_v) {}
		QSpeech_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kQSpeech_v, wbd) {} };

	/// toggle, treat speech messages as silent output unless this is turned on
        class SpeechOutput_t: public generic_whiteboard_object<bool > { public: SpeechOutput_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kSpeechOutput_v) {}
		SpeechOutput_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kSpeechOutput_v, wbd) {} };

	/// This is an example of a type definition that generates a basic type class for getters / setters
        class BoolExample_t: public generic_whiteboard_object<bool > { public: BoolExample_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kBoolExample_v) {}
		BoolExample_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kBoolExample_v, wbd) {} };

	///This is an example of a type definition that indicates that a custom accessor class will be defined later
        class CustomClassExample_t: public generic_whiteboard_object<class CustClass > { public: CustomClassExample_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class CustClass >(wbd, kCustomClassExample_v) {} };

	/// Used to play the motion files generated by Choregraphe
        class NaoMotionPlayer_t: public generic_whiteboard_object<std::string > { public: NaoMotionPlayer_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kNaoMotionPlayer_v) {}
		NaoMotionPlayer_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kNaoMotionPlayer_v, wbd) {} };

	/// State variable, is there a motion running currently (NaoMotionPlayer)
        class NaoMotionPlayerIsRunning_t: public generic_whiteboard_object<bool > { public: NaoMotionPlayerIsRunning_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kNaoMotionPlayerIsRunning_v) {}
		NaoMotionPlayerIsRunning_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kNaoMotionPlayerIsRunning_v, wbd) {} };

	/// Commands the slow walk that is built into the SDK
        class NaoWalk_t: public generic_whiteboard_object<std::vector<int> > { public: NaoWalk_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::vector<int> >(wbd, kNaoWalk_v) {}
		NaoWalk_t(std::vector<int> value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::vector<int> >(value, kNaoWalk_v, wbd) {} };

	/// State variable, is the slow SDK walk running (NaoWalk)
        class NaoWalkIsRunning_t: public generic_whiteboard_object<bool > { public: NaoWalkIsRunning_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kNaoWalkIsRunning_v) {}
		NaoWalkIsRunning_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kNaoWalkIsRunning_v, wbd) {} };

	/// Sets the head stiffness level, warning: this call may change and become part of the sensors / HAL module at a later date
        class HeadStiffness_t: public generic_whiteboard_object<float > { public: HeadStiffness_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<float >(wbd, kHeadStiffness_v) {}
		HeadStiffness_t(float value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<float >(value, kHeadStiffness_v, wbd) {} };

	/// Sets the body stiffness level, warning: this call may change and become part of the sensors / HAL module at a later date
        class HoldingStiffness_t: public generic_whiteboard_object<float > { public: HoldingStiffness_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<float >(wbd, kHoldingStiffness_v) {}
		HoldingStiffness_t(float value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<float >(value, kHoldingStiffness_v, wbd) {} };

	/// SDK wrapper function for moving any joint, be very careful
        class GenericAngleChange_t: public generic_whiteboard_object<std::vector<int> > { public: GenericAngleChange_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::vector<int> >(wbd, kGenericAngleChange_v) {}
		GenericAngleChange_t(std::vector<int> value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::vector<int> >(value, kGenericAngleChange_v, wbd) {} };

	/// State variable, is the joint SDK wrapper function running (kGenericAngleChange)
        class GenericAngleChangeIsRunning_t: public generic_whiteboard_object<bool > { public: GenericAngleChangeIsRunning_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kGenericAngleChangeIsRunning_v) {}
		GenericAngleChangeIsRunning_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kGenericAngleChangeIsRunning_v, wbd) {} };

	///Used to alter the head position via the DCM
        class HAL_HeadTarget_t: public generic_whiteboard_object<class HAL_HeadTarget > { public: HAL_HeadTarget_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class HAL_HeadTarget >(wbd, kHAL_HeadTarget_v) {} };

}

#endif                          
