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
	
	//const char *kDifferentialMotorForward = "gudifferential_motorForward";
	//const char *kDifferentialMotorBackward = "gudifferential_motorBackward";
	//const char *kDifferentialMotorStop = "gudifferential_motorStop";
	/*!
         * This is the new message-type for controlling a motor
	 * content type is ALWAYS ARRAY
	 * the first value is the motor ID, 0=left, 1=right 2 third
	 * for MiPAL NXT wired robots, C=left adn B= right
	 * the second value is POWER
	 * The power shall be beteen [-100,100], abs(power) is a percentage
	 * Negative values means running backwards
	 * 0 is a stop
	 * positive forwards
	*/
	const char *kDifferentialMotorPower = "gudifferential_motorPower";

	/**Differential Robot Whiteboard message to start playing a sound
	 * Content (Int): Duration in milisecond
	 * */
	const char *kDifferentialPlaySound = "gudifferential_playSound";

	/**Differential Robot Whiteboard message to stop playing a sound
	 * Content (Int): Duration in milisecond
	 * */
	const char *kDifferentialStopSound = "gudifferential_stopSound";

	const char *kDifferentialStopTouch = "gudifferential_stopTouchSensor";
	const char *kDifferentialStartTouch = "gudifferential_startTouchSensor";
	const char *kDifferentialTouchValue = "gudifferential_touchSensorValue";
	const char *kDifferentialStartDistance = "gudifferential_startDistanceSensor";
	const char *kDifferentialStopDistance = "gudifferential_stopDistanceSensor";
	const char *kDifferentialDistanceValue = "gudifferential_distanceSensorValue";
	const char *kDifferentialStartLight = "gudifferential_startLightSensor";
	const char *kDifferentialStopLight = "gudifferential_stopLightSensor";
	const char *kDifferentialLightValue = "gudifferential_lightSensorValue";
	const char *kDifferentialLedOn = "gudifferential_ledOn";
	const char *kDifferentialLedOff = "gudifferential_ledOff";
	const char *kDifferentialStartRotationSensor = "gudifferential_startRotationSensor";
	const char *kDifferentialStopRotationSensor = "gudifferential_stopRotationSensor";
	const char *kDifferentialRotationValue = "gudifferential_rotationSensorValue";
	
}
