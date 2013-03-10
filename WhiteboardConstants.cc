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
	
	// LONG GONE: use MotorPower and an ARRAY
	//const char *kDifferentialMotorForward = "gudifferential_motorForward";
	//const char *kDifferentialMotorBackward = "gudifferential_motorBackward";
	//const char *kDifferentialMotorStop = "gudifferential_motorStop";

	/*!
         * This is the new message-type for controlling a motor
	 * content type is ALWAYS ARRAY
	 * the first value is the motor ID, 0=left, 1=right 2 third
	 * for MiPAL NXT wired robots, C=left adn B= right  THIRD is A in nxt.
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


	/**Differential Robot message to stop a touch sensor reporting
	 * Content (Int): Id of touch sensor for NXT(1, 2, 3 or 4)
	 * */
	const char *kDifferentialStopTouch = "gudifferential_stopTouchSensor";
	/**Differential Robot message to start a touch sensor reporting
	 * Content (Int): Id of touch sensor for NXT(1, 2, 3 or 4)
	 * */
	const char *kDifferentialStartTouch = "gudifferential_startTouchSensor";

	/**Differential Robot Whiteboard message reporting the value of a
	*  touch sensor, the message type is appended with an active
	* Id of touch sensor for NXT(1, 2, 3 or 4)
	* content is the value of sensor, 0 if released, 1 if pressed
        **/
	const char *kDifferentialTouchValue = "gudifferential_touchSensorValue";


	/**Differential Robot message to start a sonar sensor reporting
	 * Content (Int): Id of touch sensor for NXT(1, 2, 3 or 4)
	 * */
	const char *kDifferentialStartDistance = "gudifferential_startDistanceSensor";

	/**Differential Robot message to STOP a sonar sensor reporting
	 * Content (Int): Id of touch sensor for NXT(1, 2, 3 or 4)
	 * */
	const char *kDifferentialStopDistance = "gudifferential_stopDistanceSensor";

	/**Differential Robot Whiteboard message reporting the value of a
	*  sonar sensor, the message type is appended with an active
	* Id of touch sensor for NXT(1, 2, 3 or 4)
	* content is the value of sensor, in cm
        **/
	const char *kDifferentialDistanceValue = "gudifferential_distanceSensorValue";


	/**Differential Robot message to start a rotation sensor reporting
	 * Content (Int): Id of relevant motor
	 * Id of motor 0=left, 1=right 2 third
	 * for MiPAL NXT wired robots, C=left adn B= right
        **/
	const char *kDifferentialStartRotationSensor = "gudifferential_startRotationSensor";

	/**Differential Robot message to STOP a rotation sensor reporting
	 * Content (Int): Id of relevant motor
	 * Id of motor 0=left, 1=right 2 third
	 * for MiPAL NXT wired robots, C=left adn B= right
        **/
	const char *kDifferentialStopRotationSensor = "gudifferential_stopRotationSensor";

	/**Differential Robot Whiteboard message reporting the value of a
	*  rotation on a motor, the message type is appended with an active
	* Id of motor 0=left, 1=right 2 third
	* for MiPAL NXT wired robots, C=left adn B= right
	* content is the value of sensor, in laps
        **/
	const char *kDifferentialRotationValue = "gudifferential_rotationSensorValue";

	const char *kDifferentialStartLight = "gudifferential_startLightSensor";
	const char *kDifferentialStopLight = "gudifferential_stopLightSensor";
	const char *kDifferentialLightValue = "gudifferential_lightSensorValue";


	const char *kDifferentialLedOn = "gudifferential_ledOn";
	const char *kDifferentialLedOff = "gudifferential_ledOff";
	
}
