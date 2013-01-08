/*
 *  WhiteboardConstants.cpp
 *  gucdlmodule
 *
 *  Created by Rene Hexel on 24/04/10.
 *  Copyright 2010 Rene Hexel. All rights reserved.
 *
 */

namespace guWhiteboard 
{
        /* generic whiteboard messages */
	const char *kHelloWBMsg = "HELLO_MESSAGE";	// hello world message
	const char *kSay = "Say";                       // speech message
	const char *kQSay = "QSay";                     // speech message (queuing)
	const char *kSpeechWBMsg = "Speech";		// speech message for debugging
	const char *kQSpeech = "QSpeech";		// speech message (queuing) for debugging
	const char *kSpeechOutput = "SpeechOutput";	// activate/deactivate Speech

        /* expert system whiteboard messages */
	const char *kUpdateAllProofs = "updateProofs";
	const char *kUpdateProof = "updateProofsForOutput";
	const char *kUpdateAllProofsForTheory = "updateProofsForTheory";

	/*!
	 * This variable is 1 if we are playng as RED and
	 * is 0 if we are playng as BLUE
	 */
	const char *kRobocup_ourTeam = "Robocup_ourTeam";

	/*!
	 * This variable is 1 if we it is our kickoff 
	 * is 0 if we are NOT having the kickoff.
	 * Regardless of what team we are playing kRobocup_ourTeam==kRobocup_kickOffTeam
	 * tests if we are kicking off
	 * 
	 */
	const char *kRobocup_kickOffTeam = "Robocup_kickOffTeam";
	
	const char *kOn = "On";
	const char *kOff = "Off";
	
	
}
