/*
 *  WEBOTS_NXT_bridge.h
 *
 *  Created by Vald Estivill-Castro on 25/10/13.
 *  Copyright (c) 2013 Rene Hexel. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Rene Hexel.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */
#ifndef WEBOTS_NXT_bridge_DEFINED
#define WEBOTS_NXT_bridge_DEFINED
#define WEBOTS_NXT_encoders_DEFINED
#define WEBOTS_NXT_bumper_DEFINED
#define WEBOTS_NXT_camera_DEFINED
#define WEBOTS_NXT_deadReakoning_walk_DEFINED
#define WEBOTS_NXT_walk_isRunning_DEFINED
#define WEBOTS_NXT_colorLine_walk_DEFINED
#define WEBOTS_NXT_gridMotions_DEFINED
#define WEBOTS_NXT_vector_bridge_DEFINED

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

#include <cstdlib>
#include <sstream>
#include <gu_util.h>

const char OBJECT_SEPARATOR = '|';
const char FIELD_SERPARATOR = ',';
const char EQUALS = '=';

namespace guWhiteboard
{
        /** Enumerations of motor's in the NXT and E-Puck differential robots
        */
        enum DifferentialMotor {
                LEFT_MOTOR_DIFFERENTIAL = 0,
                RIGHT_MOTOR_DIFFERENTIAL = 1,
                NXT_MOTOR3 = 2 //constant for the third motor on nxt's
        };

        /** String Description of the motor's in the NXT and E-Puck robots
        */
        static const char* MotorStrings[] = {
                "LEFT_MOTOR",
                "RIGHT_MOTOR",
                "NXT_MOTOR3"
        };

        /** Enumeration of the Sound parameter settings
        */
        enum SoundDiscriminators {
                SOUND_DURATION = 0,
                SOUND_FREQUENCY = 1
        };

        /** String Description of the Sound settings
        */
        static const char* SoundStrings[] = {
                "SOUND_DURATION",
                "SOUND_FREQUENCY"
        };

        /** Enumeration of the Sonar Sensors in the NXT and E-Puck differential robots
        */
        enum SonarSensorID {
                LEFT_SONAR_SENSOR = 0,
                RIGHT_SONAR_SENSOR = 1
	};

        /** Enumeration of the Light Sensors in the NXT differential robot
        */
        enum LightSensorID {
                LEFT_LIGHT_SENSOR = 0,
                RIGHT_LIGHT_SENSOR = 1
	};

        /** Enumeration of the Touch Sensors in the NXT and E-Puck differential robots
        */
        enum TouchSensorID {
                LEFT_TOUCH_SENSOR = 0,
                RIGHT_TOUCH_SENSOR = 1,
                NXT_NUM_SENSORS_IN_BUMBER = 2 //constant for the total number of sensors in the  nxt's bumper
	};

        /** Enumeration of the Sensor ports available in the NXT differential robot
        */
        enum NXT_Sensor_Ports {
                NXT_PORT_1 = 0,
                NXT_PORT_2 = 1,
                NXT_PORT_3 = 2,
                NXT_PORT_4 = 3
        };

        /** Enumeration of the Colour Channels available in camera of the E-Puck differential robot
        */
	enum CAMERA_E_PUCK_CHANNELS {
		BLUE_CHANNEL = NXT_PORT_1,
		RED_CHANNEL = NXT_PORT_2,
		GREEN_CHANNEL = NXT_PORT_3,
		GREY_CHANNEL = NXT_PORT_4
	};

        /** Enumeration of the defined general instructions
        */
        enum DifferentialInstructions {
        // ACTUATORS
                MOVE_MOTORS = 0, // Sets the left and right motor speeds
                ONE_MOTOR_SETTING = 1, // Allows setting motor speed for a single motor
		PLAY_SOUND = 2,
		LIGHTUP_LED = 3,
        // SENSORS
                DISTANCE = 4,
		INTENSITY_LIGHT = 5,
		ROTATION_ENCODER = 6,
                CAMERA = 7, // Each colour channel can be turned On or Off individually, or the frame data read
		TOUCH = 8,
                NUMBER_WEBOTS_NXT_bridge_MESSAGES// no value assigned to allow for additional instructions later
        };

       /** Enumeration of the available strategies when following lines
        */
        enum ColorLineInstructions {
                FOLLOW_COLOR = 0,
		TURN_RIGHT_UNTIL_COLOR_FOUND = 1,
		TURN_LEFT_UNTIL_COLOR_FOUND = 2
        };
#if 0 // not used so far: compiler is complaining (put back in when actually used)
static const char* Commands[] = {"MOVE_MOTORS", "ONE_MOTOR_SETTING", "PLAY_SOUND", "LIGHTUP_LED",
	                       "START_DISTANCE", "START_INTENSITY_LIGHT", "START_ROTATION_ENCODER",
			       "START_CAMERA", "START_TOUCH", "Undefined"};
#endif


        /**
         * Class for demonstrating OO-messages in sequential arrangement of finite state machines
	 * using a full vector of status and commands
         */
        class WEBOTS_NXT_vector_bridge {
                public:

                /**
                * The robot this status is for.
                */
		PROPERTY(int16_t, theRobotID)
		/**
		* The current speed of the left motor.
		*/
		PROPERTY(int16_t, speedLeftMotor)
		/**
		* The current speed of the right motor
		*/
		PROPERTY(int16_t, speedRightMotor)
		/**
		* The current frequency for a sound we are playing
		*/
		PROPERTY(int16_t, soundFrequency)
		/**
		*  The current duration we are playing a sound for
		*/
		PROPERTY(int16_t, soundDuration)

		WEBOTS_NXT_vector_bridge() { memset(this, 0, sizeof(*this)); }  // setting everything empty in the constructor

                /** string constructor */
                WEBOTS_NXT_vector_bridge(const std::string &names) { from_string(names); }

                 /** copy constructor */
                WEBOTS_NXT_vector_bridge(const WEBOTS_NXT_vector_bridge &other):
                        _theRobotID(other._theRobotID),
                        _speedLeftMotor(other._speedLeftMotor),
                        _speedRightMotor(other._speedRightMotor),
                        _soundFrequency(other._soundFrequency),
                        _soundDuration(other._soundDuration) {}

                /** copy assignment operator */
                WEBOTS_NXT_vector_bridge &operator=(const WEBOTS_NXT_vector_bridge &other) {
                        _theRobotID = other._theRobotID;
                        _speedLeftMotor = other._speedLeftMotor;
                        _speedRightMotor = other._speedRightMotor;
                        _soundFrequency = other._soundFrequency;
                        _soundDuration = other._soundDuration;
                        return *this;
                }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        ss<< _theRobotID << FIELD_SERPARATOR;
		        // attempt to make it that the order does not matter
		        ss <<  MotorStrings[LEFT_MOTOR_DIFFERENTIAL] << EQUALS << _speedLeftMotor << FIELD_SERPARATOR;
		        ss <<  MotorStrings[RIGHT_MOTOR_DIFFERENTIAL] << EQUALS << _speedRightMotor << FIELD_SERPARATOR;
		        ss <<  SoundStrings[SOUND_FREQUENCY] << EQUALS << _soundFrequency << FIELD_SERPARATOR;
		        ss <<  SoundStrings[SOUND_DURATION] << EQUALS << _soundDuration << FIELD_SERPARATOR;
                        return ss.str();
	        }

                /** convert from a string */
                void from_string(const std::string &strWithID) {
                        // can parse the input , set all default values
                        set_theRobotID(0);
                        set_speedLeftMotor(0);
                        set_speedRightMotor(0);
		        set_soundFrequency(0);
		        set_soundDuration(0);
                        std::istringstream iss(strWithID);
                        std::string token;
                        if (getline(iss, token, FIELD_SERPARATOR)) {
		                int16_t numberForID = int16_t ( atoi(token.c_str())) ; // Robots id are 0,1,2 .....
                                if (numberForID <0) set_theRobotID(-numberForID); else set_theRobotID(numberForID);
                                std::string comaDel (1,FIELD_SERPARATOR);
                                std::size_t found = strWithID.find(comaDel);
                                if (std::string::npos!=found ) {
                                        std::string str=strWithID.substr (found+comaDel.size());
                                        // string without the Robot ID
                                        std::istringstream second_iss(str);
                                        // lest find pairs where the token is  property=value,
                                        while (getline(second_iss, token, FIELD_SERPARATOR)) {
                                                std::size_t postionEQUALS= token.find(EQUALS);

                                                if ( (std::string::npos!=token.find(MotorStrings[LEFT_MOTOR_DIFFERENTIAL]) )
                                                        && (std::string::npos!=postionEQUALS) )
                                                {   std::string theValue = token.substr (postionEQUALS+1,token.size() );
                                                    set_speedLeftMotor( static_cast<int16_t>(atoi (theValue.c_str()) ));
                                                }

                                                if ( (std::string::npos!=token.find(MotorStrings[RIGHT_MOTOR_DIFFERENTIAL]) )
                                                        && (std::string::npos!=postionEQUALS) )
                                                {   std::string theValue = token.substr (postionEQUALS+1,token.size() );
                                                    set_speedRightMotor(static_cast<int16_t>(atoi (theValue.c_str()) ));
                                                }

                                                if ( (std::string::npos!=token.find(SoundStrings[SOUND_FREQUENCY]) )
                                                        && (std::string::npos!=postionEQUALS) )
                                                {   std::string theValue = token.substr (postionEQUALS+1,token.size() );
                                                    set_soundFrequency(static_cast<int16_t>( atoi (theValue.c_str()) ));
                                                }

                                                if ( (std::string::npos!=token.find(SoundStrings[SOUND_DURATION]) )
                                                        && (std::string::npos!=postionEQUALS) )
                                                {   std::string theValue = token.substr (postionEQUALS+1,token.size() );
                                                    set_soundDuration(static_cast<int16_t>( atoi (theValue.c_str()) ));
                                                }

                                                // find next comma in the string
                                                found = str.find(comaDel);
                                                if (std::string::npos!=found ) {  // a comma is found
                                                        std::string newstr=str.substr (found+comaDel.size());
                                                        second_iss.str(newstr);
                                                        //move the string along
                                                        str=str.substr (found+comaDel.size());
                                                }
                                        }
                                }
                        }
	        }

                /**
                *  Sets the WEBOTS_NXT_vector_bridge instance properties that represent actuator states
                *  based on the specified DifferentialInstruction
                *  @param theActuator The Actuator to be set
                *  @param firstParameter The first parameter for the actuator (presently unused)
                *  @param secondParameter The second parameter, which is used to set the Sound Duration and Frequency properties.
                */
                void set_actuator(DifferentialInstructions theActuator,int16_t firstParameter,int16_t secondParameter) {
                        SoundDiscriminators theInstructionModality =static_cast<SoundDiscriminators>( firstParameter);

                        switch (theActuator) {
                                case  MOVE_MOTORS :
                                        break;
                                case  ONE_MOTOR_SETTING:
                                        break;
                                case  PLAY_SOUND:
                                        switch (theInstructionModality) {
                                                case SOUND_DURATION: set_soundDuration(secondParameter );
                                                        break;
                                                case SOUND_FREQUENCY : set_soundFrequency(secondParameter );
                                                        break;
                                        }
                                        break;
                                case  LIGHTUP_LED:
                                        break;
                                case  DISTANCE:
                                        break;
                                case  INTENSITY_LIGHT:
                                        break;
                                case  ROTATION_ENCODER:
                                        break;
                                case  CAMERA:
                                        break;
                                case  TOUCH:
                                        break;
                                case NUMBER_WEBOTS_NXT_bridge_MESSAGES:
                                        break;
                        }
	        }
        };


        /**
         * This is the base class for the WEBOTS_NXT_bridge library.
         * It defines the lowest level structure of messages used in the library.
         * Other classes in this library refer to this class when constructing/interpreting messages.
         */
        class WEBOTS_NXT_bridge {
		/** Which robot are we talking to */
                PROPERTY(int16_t, theRobotID)
		/**  The command (when it is not data) */
                PROPERTY(DifferentialInstructions, theInstruction)
		/**  the first parameter */
                PROPERTY(int16_t, firstParameter)
		/**  the first parameter */
                PROPERTY(int16_t, secondParameter)
		/**  IT is data about a sensor */
                PROPERTY(bool, isSensorData)

                public:

                /** designated constructor */
                WEBOTS_NXT_bridge(int16_t theRobotID =0 ,DifferentialInstructions  theInstruction = MOVE_MOTORS, int16_t firstParameter = 0, int16_t secondParameter=0, bool isSensorData =false): _theRobotID(theRobotID),  _theInstruction(theInstruction), _firstParameter(firstParameter), _secondParameter(secondParameter), _isSensorData(isSensorData)  { /* better than set_x(x); set_y(y) */ }

                /** string constructor */
                WEBOTS_NXT_bridge(const std::string &names) { from_string(names); }

                /** copy constructor */
                WEBOTS_NXT_bridge(const WEBOTS_NXT_bridge &other): _theRobotID(other._theRobotID), _theInstruction(other._theInstruction), _firstParameter(other._firstParameter), _secondParameter(other._secondParameter), _isSensorData(other._isSensorData) {}

                /** copy assignment operator **/
                WEBOTS_NXT_bridge &operator=(const WEBOTS_NXT_bridge &other) { _theRobotID = other._theRobotID; _theInstruction = other._theInstruction; _firstParameter = other._firstParameter; _secondParameter = other._secondParameter;_isSensorData = other._isSensorData; return *this; }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        ss<< _theRobotID << FIELD_SERPARATOR;
                        if (_isSensorData) {
                             switch(_theInstruction) {
                                  case ROTATION_ENCODER :
                                        ss << "SENSOR"<<"ROTATION_ENCODER" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                        break;
                                  case INTENSITY_LIGHT :
                                        ss << "SENSOR"<<"INTENSITY_LIGHT" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                        break;
                                  case DISTANCE :
                                        ss << "SENSOR"<< "DISTANCE" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                        break;
                                        // as a sensor first parameter is total pixele sof color, second parameter is middle of the color
                                  case CAMERA :
                                        ss << "SENSOR"<< "CAMERA" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                        break;
                                  case TOUCH :
                                        ss << "SENSOR"<< "TOUCH" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                        break;
                                 case MOVE_MOTORS:
                                 case ONE_MOTOR_SETTING:
                                 case PLAY_SOUND:
                                 case LIGHTUP_LED: //std::cerr << "LOG-error ** This shoudl not hold data" << std::endl;
                                 case NUMBER_WEBOTS_NXT_bridge_MESSAGES:
                                        break;
                             }
                        } else {
                                switch(_theInstruction) {
                                        case MOVE_MOTORS :
                                                /*
                                                 * Apply power=_firstParameter to LEFT MOTOR
                                                 * Apply power=_secondParameter to RIGHT MOTOR
                                                 */
                                                ss << "MOVE_MOTORS" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                                break;
                                        case ONE_MOTOR_SETTING :
                                                /*
                                                 * Set the motor in  _firstParameter, to the power in the second parameter without
                                                 * affecting the other motors
                                                 */
                                                ss << "ONE_MOTOR_SETTING" << "," << _firstParameter  << "," << _secondParameter << OBJECT_SEPARATOR;
                                                break;
                                        case PLAY_SOUND :
                                                /*
                                                 * Play sound for as long as _firstParameter, use second parameter as NXT frequency
                                                 */
                                                ss << "PLAY_SOUND" << "," << _firstParameter  << "," << _secondParameter << OBJECT_SEPARATOR;
                                                break;
                                        case LIGHTUP_LED :
                                                /*
                                                 * LIGHTUP_LED if 0<> _firstParameter
                                                 */
                                                ss << "LIGHTUP_LED" << "," << ((0!=_firstParameter)? 1: 0) << OBJECT_SEPARATOR;
                                                break;
                                        case DISTANCE :
                                                /*
                                                 * Start posting Distance from SOnar in potrt _firstParameter if 0<> _secondParameter
                                                 * Stop posting Distance from SOnar in potrt _firstParameter if 0== _secondParameter
                                                 */
                                                ss << "DISTANCE" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                                break;
                                        case INTENSITY_LIGHT :
                                                /*
                                                 * Start posting light measurement from light sensor in port _firstParameter if 0<> _secondParameter
                                                 * Stop posting lisght measurement from light in port _firstParameter if 0== _secondParameter
                                                 */
                                                ss << "INTENSITY_LIGHT" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                                break;
                                        case ROTATION_ENCODER :
                                                /*
                                                 * Start posting rotations from encoder in port _firstParameter if 0<> _secondParameter
                                                 * Stop posting rotations from encoder in port _firstParameter if 0== _secondParameter
                                                 */
                                                ss << "ROTATION_ENCODER" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                                break;
                                        case CAMERA :
                                                /*
                                                 * Start posting from camera, the first paramer is the color channel
                                                 * the second aprameter is a threshold to comapre how many pixels have intensity abvoe the threshoold
                                                 * Stop posting for color channel in first aprameter if 0==_secondParameter
                                                 */
                                                ss << "CAMERA" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                                break;
                                        case TOUCH :
                                                /*
                                                 * Start posting wether the touch sensor in port _firstParameter is pressed, if  0<> _secondParameter
                                                 * Stop posting wether the touch sensor in port _firstParameter is pressed, if 0== _secondParameter
                                                 */
                                                ss << "TOUCH" << "," << _firstParameter << "," << _secondParameter << OBJECT_SEPARATOR ;
                                                break;
                                        case NUMBER_WEBOTS_NXT_bridge_MESSAGES:
                                                break;
                                }
                        }
                        return ss.str();
                }

                /** convert from a string */
                void from_string(const std::string &strWithID) {
                        std::istringstream iss(strWithID);
                        std::string token;
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                int16_t numberForID = int16_t ( atoi(token.c_str())) ;
                                // Robots id are 0,1,2 .....
                                if (numberForID <0) set_theRobotID(-numberForID); else set_theRobotID(numberForID);
                                std::string comaDel (",");
                                std::size_t found = strWithID.find(comaDel);
                                if (std::string::npos!=found ) {
                                        std::string str=strWithID.substr (found+comaDel.size());
                                        // string without the Robot ID
                                        std::istringstream second_iss(str);
                                        if (getline(second_iss, token, FIELD_SERPARATOR)) {
                                                set_firstParameter(0);
                                                set_secondParameter(0);
                                                set_isSensorData(false);
                                                std::string sensorStr ("SENSOR");
                                                switch (token[0]) {
                                                        case 'M' : // expect a MOVE_MOTORS
                                                        case 'm' :
                                                        case 'o' :
                                                        case 'O' : // expect a ONE_MOTOR_SETTING
                                                        case 'p' :
                                                        case 'P' : // expect a PLAY_SOUND
                                                        case 'l' :
                                                        case 'L' : // expect a LIGHTUP_LED
                                                        case 'd' :
                                                        case 'D' : // expect a DISTANCE
                                                        case 't' :
                                                        case 'T' : // expect a TOUCH sensor on/off instruction
                                                        case 'i' :
                                                        case 'I' : // expect a INTENSITY_LIGHT
                                                        case 'r' :
                                                        case 'R' : // expect a ROTATION_ENCODER
                                                        case 'c' :
                                                        case 'C' : // expect a ROTATION_ENCODER
                                                                instruction_from_string ( str );
                                                                break;
                                                        case 's' :
                                                        case 'S' : // expect SENSOR data
                                                                //std:: cerr<< "Sensor data detected " << std:: endl;
                                                                set_isSensorData(true);
                                                                // remove the prefix SENSOR
                                                                found = str.find(sensorStr);
                                                                if (std::string::npos!=found ) {
                                                                        std::string strWithoutPrefix =str.substr (found+sensorStr.size());
                                                                        measurement_from_string ( strWithoutPrefix );
                                                                }
                                                                break;
                                                }
                                        }
                                }
                        }
                }

	        private :
                /*
                * Extract the First parameter as an NXT in port
                * the second parameter as a binary {0,1} value
                */
        	void set_parameters2ndBinary ( const std::string &str  ) {
                        std::istringstream iss(str);
                        std::string token;
                        // advance the token
                        getline(iss, token, FIELD_SERPARATOR);
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                int16_t value = int16_t ( atoi(token.c_str())) ;
                                if (NXT_PORT_1 <= value && value <= NXT_PORT_4)
                                        set_firstParameter(value);
                                else
                                        set_firstParameter(NXT_PORT_1);
                        }
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                set_secondParameter(int16_t( (0== atoi(token.c_str())? 0 :1 ) ));
                        }
                }

	        void set_parameters2ndNum ( const std::string &str  ) {
                        std::istringstream iss(str);
                        std::string token;
                        // advance the token
                        getline(iss, token, FIELD_SERPARATOR);
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                int16_t value = int16_t ( atoi(token.c_str())) ;
                                if (NXT_PORT_1 <= value && value <= NXT_PORT_4)
                                        set_firstParameter(value);
                                else
                                        set_firstParameter(NXT_PORT_1);
                        }
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                set_secondParameter(int16_t( atoi(token.c_str()) ));
                        }
                }

	        void set_parametersCamera ( const std::string &str  ) {
		        std::istringstream iss(str);
		        std::string token;
		        // advance the token
		        getline(iss, token, FIELD_SERPARATOR);
		        if (getline(iss, token, FIELD_SERPARATOR)) {
			        int16_t value = int16_t ( atoi(token.c_str())) ;
			        set_firstParameter(value);
		        }
                        if (getline(iss, token, FIELD_SERPARATOR)) {
			        set_secondParameter(int16_t(atoi(token.c_str()) ));
		        }
	        }

	        /*
	        * Extract the effector type and its parameters
	        */
	        void instruction_from_string ( const std::string &str ) {
                        std::istringstream iss(str);
                        std::string token;
                        getline(iss, token, FIELD_SERPARATOR);
		        switch (token[0]) {
                                case 'M' :  // expect a MOVE_MOTORS
		                case 'm' :
                                        set_theInstruction(MOVE_MOTORS);
                                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                                set_firstParameter(int16_t(atoi(token.c_str())));
                                        }
                                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                                set_secondParameter(int16_t(atoi(token.c_str())));
                                        }
			                break;
		                case 'o' :  // expect a ONE_MOTOR_SETTING
		                case 'O' :
                                        set_theInstruction(ONE_MOTOR_SETTING);
                                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                                int16_t motorID= 0!= atoi(token.c_str()) ? RIGHT_MOTOR_DIFFERENTIAL  : LEFT_MOTOR_DIFFERENTIAL ;
                                                set_firstParameter(motorID);
                                        }
                                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                                set_secondParameter(int16_t(atoi(token.c_str())));
                                        }
			                break;
		                case 'p' :
		                case 'P' : // expect a PLAY_SOUND
		                        set_theInstruction(PLAY_SOUND);
				        set_firstParameter(0);
				        set_secondParameter(0);
                                        if (getline(iss, token, FIELD_SERPARATOR)) {  // duration
                                                // always positive
					        int16_t value= int16_t ( atoi(token.c_str()) );
					        value = value >=0 ? value : -1*value;
					        set_firstParameter(value);
                                                if (getline(iss, token, FIELD_SERPARATOR)) { //frequency
                                                        // always positive
					                int16_t frequency_value= int16_t ( atoi(token.c_str()) );
					                frequency_value = frequency_value >=0 ? frequency_value : -1*frequency_value;
					                set_secondParameter(frequency_value);
                                                }
					}
			                break;
		                case 'l' :
		                case 'L' : // expect a LIGHTUP_LED
                                        set_theInstruction(LIGHTUP_LED);
                                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                                set_firstParameter(int16_t((0== atoi(token.c_str())? 0 :1 ) ));
                                        }
			                break;
		                case 'd' :
		                case 'D' : // expect a DISTANCE
                                        set_theInstruction(DISTANCE);
				        set_parameters2ndBinary(str);
			                break;
		                case 't' :
		                case 'T' : // expect a TOUCH sensor command
		                        set_theInstruction(TOUCH);
				        set_parameters2ndBinary(str);
			                break;
		                case 'i' :
		                case 'I' : // expect a INTENSITY_LIGHT
		                        set_theInstruction(INTENSITY_LIGHT);
				        set_parameters2ndBinary(str);
			                break;
		                case 'r' :
		                case 'R' : // expect a ROTATION_ENCODER
		                        set_theInstruction(ROTATION_ENCODER);
				        set_parameters2ndBinary(str);
			                break;
		                case 'c' :
		                case 'C' : // expect a CAMERA
		                        set_theInstruction(CAMERA);
				        set_parameters2ndBinary(str);
			                break;
		        }//switch
	        }

	        /*
	        * Extract the sensor type and its parameters
	        */
	        void measurement_from_string ( const std::string &str ) {
                        std::istringstream iss(str);
                        std::string token;
                        getline(iss, token, FIELD_SERPARATOR);
		        switch (token[0]) {
		                case 'd' :
		                case 'D' : // expect a DISTANCE
		                        set_theInstruction(DISTANCE);
				        set_parameters2ndNum(str);
			                break;
		                case 'i' :
		                case 'I' : // expect a INTENSITY_LIGHT
		                        set_theInstruction(INTENSITY_LIGHT);
				        set_parameters2ndNum(str);
			                break;
		                case 'r' :
		                case 'R' : // expect a ROTATION_ENCODER
		                        set_theInstruction(ROTATION_ENCODER);
				        set_parameters2ndNum(str);
			                break;
		                case 'c' :
		                case 'C' : // expect a CAMERA
		                        set_theInstruction(CAMERA);
				        set_parametersCamera(str);
			                break;
		        }//switch
	        }

        };


        /**
         * This class reports the status of the ColorLine_Walk behaviour.
         */
        class WEBOTS_NXT_colorLine_walk {
                /**
                *  ID of the robot
                */
                PROPERTY(int16_t, robotID)
                /**
                *  Power of the motore as a %, 100 is full power, in reverse is negative, regulates speed
                */
                PROPERTY(int16_t, power)
                /**
                *   The command (when it is not data)
                */
                PROPERTY(ColorLineInstructions, theInstruction)
                /**
                *  The colour channel in use (Defaults to BLUE)
                */
                PROPERTY(CAMERA_E_PUCK_CHANNELS, color)
                /**
                *    Color threshold to count a pixel in the total
                */
                PROPERTY(int16_t, colorIntensityThreshold)
                /**
                *    Color count to consider line visible
                */
                PROPERTY(int16_t, visibilityCountThreshold)
                /**
                *   Limit of the turn in degrees or of the walk in cm
                */
                PROPERTY(int16_t, limit)

                /** designated constructor */
                WEBOTS_NXT_colorLine_walk(int16_t robotID = 0 , int16_t power = 0, ColorLineInstructions theInstruction = FOLLOW_COLOR, CAMERA_E_PUCK_CHANNELS color = BLUE_CHANNEL, int16_t colorIntensityThreshold = 100, int16_t  visibilityCountThreshold = 10, int16_t limit=90): _robotID(robotID),  _power(power), _theInstruction(theInstruction), _color(color), _colorIntensityThreshold(colorIntensityThreshold), _visibilityCountThreshold(visibilityCountThreshold),  _limit(limit)    { /* better than set_x(x); set_y(y) */ }

                /** string constructor */
                WEBOTS_NXT_colorLine_walk(const std::string &names) { from_string(names); }

                /** copy constructor */
                WEBOTS_NXT_colorLine_walk(const WEBOTS_NXT_colorLine_walk &other): _robotID(other._robotID), _power(other._power), _theInstruction(other._theInstruction), _color(other._color), _colorIntensityThreshold(other._colorIntensityThreshold), _visibilityCountThreshold(other._visibilityCountThreshold),  _limit(other._limit)  {}

                /** copy assignment oeprator */
                WEBOTS_NXT_colorLine_walk &operator=(const WEBOTS_NXT_colorLine_walk &other) { _robotID = other._robotID; _power = other._power; _theInstruction = other._theInstruction; _color = other._color; _colorIntensityThreshold = other._colorIntensityThreshold; _visibilityCountThreshold = other._visibilityCountThreshold;  _limit = other._limit; return *this; }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        ss<< _robotID << FIELD_SERPARATOR;
		        ss<< _power << FIELD_SERPARATOR;
		        switch(_theInstruction) {
                                case FOLLOW_COLOR :
                                        ss << "FOLLOW_COLOR" << FIELD_SERPARATOR; break;
		                case TURN_RIGHT_UNTIL_COLOR_FOUND :
                                        ss << "TURN_RIGHT_UNTIL_COLOR_FOUND" << FIELD_SERPARATOR; break;
		                case TURN_LEFT_UNTIL_COLOR_FOUND :
                                        ss << "TURN_LEFT_UNTIL_COLOR_FOUND" << FIELD_SERPARATOR; break;
		        }
		        switch(_color) {
                                case BLUE_CHANNEL :
                                        ss << "BLUE_CHANNEL" << FIELD_SERPARATOR; break;
		                case RED_CHANNEL :
                                        ss << "RED_CHANNEL" << FIELD_SERPARATOR; break;
		                case GREEN_CHANNEL :
                                        ss << "GREEN_CHANNEL" << FIELD_SERPARATOR; break;
		                case GREY_CHANNEL :
                                        ss << "GREY_CHANNEL" << FIELD_SERPARATOR; break;
		        }
		        ss<< _colorIntensityThreshold << FIELD_SERPARATOR;
		        ss<< _visibilityCountThreshold << FIELD_SERPARATOR;
		        ss<< _limit << FIELD_SERPARATOR;
                        return ss.str();
	        }

                /** convert from a string */
                void from_string(const std::string &str) {
                        std::istringstream iss(str);
                        std::string token;
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                _robotID = int16_t ( atoi(token.c_str())) ;
                                if (getline(iss, token, FIELD_SERPARATOR)) {
                                        _power = int16_t ( atoi(token.c_str())) ;
                                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                                _theInstruction = FOLLOW_COLOR;
			                        std::size_t found = token.find("RIGHT");
				                if (std::string::npos!=found) _theInstruction = TURN_RIGHT_UNTIL_COLOR_FOUND;
				                else {
                                                        found = token.find("LEFT");
				                        if (std::string::npos!=found) _theInstruction = TURN_LEFT_UNTIL_COLOR_FOUND;
				                }
                                                if (getline(iss, token, FIELD_SERPARATOR)) {
                                                        _color = BLUE_CHANNEL;
				                        found = token.find("RED");
				                        if (std::string::npos!=found) _color = RED_CHANNEL;
				                        else {
                                                                found = token.find("GREEN");
				                                if (std::string::npos!=found) _color = GREEN_CHANNEL;
				                                else {
                                                                        found = token.find("GREY");
                                                                        if (std::string::npos!=found) _color = GREY_CHANNEL;
				                                }
				                        }
			                        }
                                                if (getline(iss, token, FIELD_SERPARATOR)) {
                                                        _colorIntensityThreshold = int16_t ( atoi(token.c_str())) ;
                                                        if (getline(iss, token, FIELD_SERPARATOR)) {
					                        _visibilityCountThreshold = int16_t ( atoi(token.c_str())) ;
                                                                if (getline(iss, token, FIELD_SERPARATOR))  _limit = int16_t ( atoi(token.c_str()));
				                        }
			                        }
			                }
			        }
		      }
                } // from string

        }; // WEBOTS_NXT_colorLine_walk


        /**
         * This class reports the status of the Walk is running behaviour.
         */
        class WEBOTS_NXT_walk_isRunning {
                /**
                *  ID of the robot
                */
                PROPERTY(int16_t, robotID)
                /**
                *  The motion module is still executing a move
                */
                PROPERTY(bool, runningFlag)
                /**
                *   In the last move cmmand there were activ emotors for some time
                */
                PROPERTY(bool, successLastMove)

                /** designated constructor */
                WEBOTS_NXT_walk_isRunning(int16_t robotID =0 , bool runningFlag = false, bool successLastMove=false ): _robotID(robotID),  _runningFlag(runningFlag), _successLastMove(successLastMove) { /* better than set_x(x); set_y(y) */ }

                /** string constructor */
            	WEBOTS_NXT_walk_isRunning(const std::string &names) { from_string(names); }

                /** copy constructor */
                WEBOTS_NXT_walk_isRunning (const WEBOTS_NXT_walk_isRunning &other): _robotID(other._robotID), _runningFlag(other._runningFlag), _successLastMove(other._successLastMove)  {}

                /** copy assignment operator */
                WEBOTS_NXT_walk_isRunning operator=(const WEBOTS_NXT_walk_isRunning &other) { _robotID = other._robotID; _runningFlag = other._runningFlag; _successLastMove = other._successLastMove; return *this; }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        ss<< _robotID << FIELD_SERPARATOR;
		        ss<< (_runningFlag ? "1" :"0") << FIELD_SERPARATOR;
		        ss<< (_successLastMove ? "1" :"0") << FIELD_SERPARATOR;
                        return ss.str();
	        }

                /** convert from a string */
                void from_string(const std::string &str) {
                        std::istringstream iss(str);
                        std::string token;
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                _robotID = int16_t ( atoi(token.c_str())) ;
                                if (getline(iss, token, FIELD_SERPARATOR)) {
                                        _runningFlag = 0 != atoi(token.c_str());
                                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                                _successLastMove = 0 != atoi(token.c_str());
		                        }
		                }
		        }
	        }


	}; // class WEBOTS_NXT_walk_isRunning


        /**
         * This class reports the status of the Dead Reakoning Walk behaviour.
         */
        class WEBOTS_NXT_deadReakoning_walk {
                /**
                *  ID of the robot
                */
                PROPERTY(int16_t, robotID)
                /**
                *   Power of the motore as a %, 100 is full power, in reverse is negative, regulates speed
                */
                PROPERTY(int16_t, power)
                /** the robot does a spin and then a straight walk with ony odometry input
                *   spin of the robot, motors in oposite directions in degrees
                *   THETA positive is clockwise, negative is counter clockwise
                */
                PROPERTY(int16_t, spin)
                /** forward move of the robot, motors in same direction, in cm in Webots worlds
                *   X positive is forwards, X negative is backwards
                */
                PROPERTY(int16_t, forward)

                /** designated constructor */
                WEBOTS_NXT_deadReakoning_walk(int16_t robotID =0 , int16_t power = 0, int16_t spin=0, int16_t forward =0): _robotID(robotID),  _power(power), _spin(spin), _forward(forward)   { /* better than set_x(x); set_y(y) */ }

                /** string constructor */
                WEBOTS_NXT_deadReakoning_walk(const std::string &names) { from_string(names); }

                /** copy constructor */
                WEBOTS_NXT_deadReakoning_walk(const WEBOTS_NXT_deadReakoning_walk &other): _robotID(other._robotID), _power(other._power), _spin(other._spin), _forward(other._forward)  {}

                /** copy assignment operator */
                WEBOTS_NXT_deadReakoning_walk operator=(const WEBOTS_NXT_deadReakoning_walk &other) { _robotID = other._robotID; _power = other._power; _spin = other._spin; _forward = other._forward; return *this; }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        ss<< _robotID << FIELD_SERPARATOR;
		        ss<< _power << FIELD_SERPARATOR;
		        ss<< _spin << FIELD_SERPARATOR;
		        ss<< _forward << FIELD_SERPARATOR;
                        return ss.str();
	        }

                 /** convert from a string */
                void from_string(const std::string &str) {
                        std::istringstream iss(str);
                        std::string token;
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                _robotID = int16_t ( atoi(token.c_str())) ;
                                if (getline(iss, token, FIELD_SERPARATOR)) {
                                        _power = int16_t ( atoi(token.c_str())) ;
                                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                                _spin = int16_t ( atoi(token.c_str())) ;
                                                if (getline(iss, token, FIELD_SERPARATOR)) _forward = int16_t ( atoi(token.c_str())) ;
			                }
		                }
		        }

	        }
        }; // class WEBOTS_NXT_deadReakoning_walk


        /**
         * This class reports the status of the Bumper behaviour.
         */
        class WEBOTS_NXT_bumper {
		private:

                class WEBOTS_NXT_bridge _touchSensors[NXT_NUM_SENSORS_IN_BUMBER];

		public :

                WEBOTS_NXT_bumper() {
                        WEBOTS_NXT_bridge theLeft(0,TOUCH,LEFT_TOUCH_SENSOR,0,true);
                        _touchSensors[LEFT_TOUCH_SENSOR]= theLeft;
                        WEBOTS_NXT_bridge theRight(0,TOUCH,RIGHT_TOUCH_SENSOR,0,true);
                        _touchSensors[RIGHT_TOUCH_SENSOR]= theRight;
                }

                /** single touch sensor constructor
                *   LEFT_TOUCH_SENDOR is used because it is the first enumerator
                */
                WEBOTS_NXT_bumper(const class WEBOTS_NXT_bridge &obj, enum TouchSensorID sensorID  = LEFT_TOUCH_SENSOR) {
                        _touchSensors[sensorID]=obj;
                }

                /** string constructor */
                WEBOTS_NXT_bumper(const std::string &names) { from_string(names); }

                /** copy constructor */
                WEBOTS_NXT_bumper(const WEBOTS_NXT_bumper &other) { *this = other; }

                /** copy assignment operator */
                WEBOTS_NXT_bumper &operator=(const WEBOTS_NXT_bumper &other) {
                        memcpy(this, &other, sizeof(other));
                        return *this;
	        }

	        /** property getter */
	        class WEBOTS_NXT_bridge *touchSensors() { return _touchSensors; }

	        /** property setter */
                void set_touchSensors(const class WEBOTS_NXT_bridge *objects) {
		    memcpy(_touchSensors, objects, sizeof(_touchSensors));
	        }

	        /** single sensor object setter */
	        void set_a_sensor(const class WEBOTS_NXT_bridge &obj, enum TouchSensorID sensorID  = LEFT_TOUCH_SENSOR) {
		        _touchSensors[sensorID]=obj;
	        }

	        /** single sensor  object getter */
	        WEBOTS_NXT_bridge &get_object( enum TouchSensorID sensorID  = LEFT_TOUCH_SENSOR) {
		        return _touchSensors[sensorID];
	        }

                /** single sensor object getter */
                const WEBOTS_NXT_bridge &get_object( enum TouchSensorID sensorID  = LEFT_TOUCH_SENSOR) const {
		        return _touchSensors[sensorID];
                }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        for ( int i =LEFT_TOUCH_SENSOR; i< NXT_NUM_SENSORS_IN_BUMBER; i++ ) {
		                TouchSensorID sensorID = TouchSensorID(i);
		                ss <<  _touchSensors[sensorID].description();
		        } //for
                        return ss.str();
	        }

                /** convert from a string */
                void from_string(const std::string &str) {
                        std::istringstream iss(str);
                        std::string token;
                        for (int object = LEFT_TOUCH_SENSOR; object < NXT_NUM_SENSORS_IN_BUMBER; object++) {
                                //if (!getline(iss, token, '\t')) break;
                                if (!getline(iss, token, FIELD_SERPARATOR)) break;
                                _touchSensors[object].from_string( token );
                        }
                }

	}; // WEBOTS_NXT_bumper


        /**
         * This class reports the status of the Encoder Status.
         */
        class WEBOTS_NXT_encoders {
		private:

                /**
                *  PI*maxSpped radinas per second
                */
                PROPERTY(int16_t, maxSpeed)

                /**
                *  WEBOTS_NXT_bridge based array that passes encoder data
                */
                class WEBOTS_NXT_bridge _encoders[NXT_MOTOR3];

		public :

                WEBOTS_NXT_encoders() {
                        WEBOTS_NXT_bridge theLeft(0,ROTATION_ENCODER,LEFT_MOTOR_DIFFERENTIAL,0,true);
                        _encoders[LEFT_MOTOR_DIFFERENTIAL]= theLeft;
                        WEBOTS_NXT_bridge theRight(0,ROTATION_ENCODER,RIGHT_MOTOR_DIFFERENTIAL,0,true);
                        _encoders[RIGHT_MOTOR_DIFFERENTIAL]= theRight;
                        _maxSpeed=0;
                }

                /** single encoder constructor */
                WEBOTS_NXT_encoders(const class WEBOTS_NXT_bridge &obj, enum DifferentialMotor encoderID  = NXT_MOTOR3) {
                        _encoders[encoderID]=obj;
                        _maxSpeed=0;
                }

                /** string constructor */
                WEBOTS_NXT_encoders(const std::string &names) { from_string(names); }

                /** copy constructor */
                WEBOTS_NXT_encoders(const WEBOTS_NXT_encoders &other) { *this = other; }

                /** copy assignment operator */
                WEBOTS_NXT_encoders &operator=(const WEBOTS_NXT_encoders &other) {
                        memcpy(this, &other, sizeof(other));
                        return *this;
	        }

	        /** property getter */
	        class WEBOTS_NXT_bridge *encoders() { return _encoders; }

	        /** property setter */
	        void set_encoders(const class WEBOTS_NXT_bridge *objects) { memcpy(_encoders, objects, sizeof(_encoders)); }

	        /** single encoder object setter */
	        void set_encoder(const class WEBOTS_NXT_bridge &obj, enum DifferentialMotor encoderID  = NXT_MOTOR3) { _encoders[encoderID]=obj; }

                /** single encoder  object getter */
                WEBOTS_NXT_bridge &get_object( enum DifferentialMotor encoderID  = NXT_MOTOR3) { return _encoders[encoderID]; }

                /** single encoder object getter */
                const WEBOTS_NXT_bridge &get_object( enum DifferentialMotor encoderID  = NXT_MOTOR3) const { return _encoders[encoderID]; }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        for ( int i =LEFT_MOTOR_DIFFERENTIAL; i< NXT_MOTOR3; i++ ) {
		                DifferentialMotor encoderID = DifferentialMotor(i);
		                ss <<  _encoders[encoderID].description();
		        } //for
		        ss << _maxSpeed;
                        return ss.str();
	        }

                /** convert from a string */
                void from_string(const std::string &str) {
                        std::istringstream iss(str);
                        std::string token;
                        for (int object = LEFT_MOTOR_DIFFERENTIAL; object < NXT_MOTOR3; object++) {
                                //if (!getline(iss, token, '\t')) break;
                                if (!getline(iss, token, OBJECT_SEPARATOR)) break;
                                _encoders[object].from_string( token );
                        }
		        _maxSpeed=0;
                        if (getline(iss, token, FIELD_SERPARATOR))
		        _maxSpeed = int16_t ( atoi(token.c_str())) ;
                }

	}; // WEBOTS_NXT_encoders


        /**
         * This class reports the status of the Camera.
         */
        class WEBOTS_NXT_camera {
		private:

                /**
                *   PI*maxSpped radinas per second
                */
                PROPERTY(int16_t, width)

                 /**
                *  WEBOTS_NXT_bridge based array that passes camera data per channed
                */
               class WEBOTS_NXT_bridge _channels[GREY_CHANNEL+1];

		public :

                WEBOTS_NXT_camera() {  //first parameter is the total pixels, second parameter is the middle of the pixels
                        WEBOTS_NXT_bridge theBlueChannel(0,CAMERA,0,0,true);
                        _channels[BLUE_CHANNEL]= theBlueChannel;
                        WEBOTS_NXT_bridge theRedChannel(0,CAMERA,0,0,true);
                        _channels[RED_CHANNEL]= theRedChannel;
                        WEBOTS_NXT_bridge theGreenChannel(0,CAMERA,0,0,true);
                        _channels[GREEN_CHANNEL]= theGreenChannel;
                        WEBOTS_NXT_bridge theGreyChannel(0,CAMERA,0,0,true);
                        _channels[GREY_CHANNEL]= theGreyChannel;
                        _width= 0;
                }

                /** single channel with width  constructor */
                WEBOTS_NXT_camera(const class WEBOTS_NXT_bridge &obj, int16_t a_width,  enum CAMERA_E_PUCK_CHANNELS channelID  = GREY_CHANNEL) {
                        _channels[channelID]=obj;
                        _width=a_width;
                }

                /** string constructor */
                WEBOTS_NXT_camera(const std::string &names) { from_string(names); }

                /** copy constructor */
                WEBOTS_NXT_camera(const WEBOTS_NXT_camera &other) { *this = other; }

                /** copy assignment operator */
                WEBOTS_NXT_camera &operator=(const WEBOTS_NXT_camera &other) {
		    memcpy(this, &other, sizeof(other));
                    return *this;
	        }

	        /** property getter */
	        class WEBOTS_NXT_bridge *channels() { return _channels; }

	        /** property setter */
                void set_channels(const class WEBOTS_NXT_bridge *objects) { memcpy(_channels, objects, sizeof(_channels)); }

	        /** single channel with width  setter */
	        void set_encoder(const class WEBOTS_NXT_bridge &obj,  int16_t a_width,  enum CAMERA_E_PUCK_CHANNELS channelID  = GREY_CHANNEL) {
		        _channels[channelID]=obj;
	                _width=a_width;
	        }

	        /** single channel  object getter */
	        WEBOTS_NXT_bridge &get_channel( enum CAMERA_E_PUCK_CHANNELS channelID  = GREY_CHANNEL) { return _channels[channelID]; }

                /** single channel  object getter */
                const WEBOTS_NXT_bridge &get_object( enum CAMERA_E_PUCK_CHANNELS channelID  = GREY_CHANNEL) const { return _channels[channelID]; }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        for ( int i =BLUE_CHANNEL; i<= GREY_CHANNEL; i++ ) {
		                CAMERA_E_PUCK_CHANNELS channelID = CAMERA_E_PUCK_CHANNELS(i);
		                ss <<  _channels[channelID].description();
		        } //for
		        ss <<  _width;
                        return ss.str();
	        }

                /** convert from a string */
               void from_string(const std::string &str) {
                        std::istringstream iss(str);
                        std::string token;
                        for (int object = BLUE_CHANNEL; object <= GREY_CHANNEL; object++) {
                                //if (!getline(iss, token, '\t')) break;
                                if (!getline(iss, token, OBJECT_SEPARATOR)) break;
                                _channels[object].from_string( token );
                        }
		        _width=0;
                        if (getline(iss, token, FIELD_SERPARATOR)) _width = int16_t ( atoi(token.c_str())) ;
                }


	}; // WEBOTS_NXT_encoders


        /**
        * Enumeration of ID's for motions of the differential robot
        */
        enum GridStep {
                YELLOW_LINE_STRAIGHT_STEP= 0,
                MAGENTA_LINE_STRAIGHT_STEP= 1,
                PLAIN_LINE_STRAIGHT_STEP= 2,
                TURN_LEFT_STEP= 3,
                TURN_RIGHT_STEP= 4,
                COMPLETED= 5
        };

	/**
	 *  This class of messages are for the motion module for the miPal demo grid world
	 */
        class WEBOTS_NXT_gridMotions {
                /**
                *   Which robot are we talking to
                */
                PROPERTY(int16_t, theRobotID)
                /**
                *   The command on the grid
                */
                PROPERTY(GridStep, theInstruction)
                /**
                *   How many of these in sequence before we do another
                */
                PROPERTY(int16_t, howMany)

                public:

                /** designated constructor */
                WEBOTS_NXT_gridMotions(int16_t theRobotID =0 ,GridStep  theInstruction = PLAIN_LINE_STRAIGHT_STEP, int16_t howMany = 1): _theRobotID(theRobotID),  _theInstruction(theInstruction), _howMany(howMany)   { /* better than set_x(x); set_y(y) */ }

                /** string constructor */
                WEBOTS_NXT_gridMotions(const std::string &names) { from_string(names); }

                /** copy constructor */
                WEBOTS_NXT_gridMotions(const WEBOTS_NXT_gridMotions &other): _theRobotID(other._theRobotID), _theInstruction(other._theInstruction), _howMany(other._howMany)  {}

                /** copy assignment operator */
                WEBOTS_NXT_gridMotions &operator=(const WEBOTS_NXT_gridMotions &other) { _theRobotID = other._theRobotID; _theInstruction = other._theInstruction; _howMany = other._howMany; return *this; }

                /** convert to a string */
                std::string description() const {
                        std::ostringstream ss;
		        ss<< _theRobotID << FIELD_SERPARATOR;
		        switch(_theInstruction) {
		                case YELLOW_LINE_STRAIGHT_STEP :
                			/* Move forward ona yellow line ignored if no yellow line
		                	 */
                                        ss << "YELLOW_LINE_STRAIGHT_STEP" << FIELD_SERPARATOR << _howMany << FIELD_SERPARATOR;
                                        break;
		                case MAGENTA_LINE_STRAIGHT_STEP :
                                        ss << "MAGENTA_LINE_STRAIGHT_STEP" << FIELD_SERPARATOR << _howMany << FIELD_SERPARATOR;
                                        break;
		                case PLAIN_LINE_STRAIGHT_STEP :
                                        ss << "PLAIN_LINE_STRAIGHT_STEP" << FIELD_SERPARATOR << _howMany << FIELD_SERPARATOR;
                                        break;
		                case TURN_LEFT_STEP :
                                        ss << "TURN_LEFT_STEP" << FIELD_SERPARATOR << _howMany << FIELD_SERPARATOR;
                                        break;
		                case TURN_RIGHT_STEP :
                                        ss << "TURN_RIGHT_STEP" << FIELD_SERPARATOR << _howMany << FIELD_SERPARATOR;
                                        break;
		                case COMPLETED :
                                        ss << "COMPLETED" << FIELD_SERPARATOR << _howMany << FIELD_SERPARATOR;
                                        break;
		        }
                        return ss.str();
                }

                /** convert from a string */
                void from_string(const std::string &strWithID) {
		        set_theRobotID(0);
		        _theInstruction = PLAIN_LINE_STRAIGHT_STEP;
		        set_howMany(1);
                        std::istringstream iss(strWithID);
                        std::string token;
                        if (getline(iss, token, FIELD_SERPARATOR)) {
                                int16_t numberForID = int16_t ( atoi(token.c_str())) ;
			        // Robots id are 0,1,2 .....
		                if (numberForID <0) set_theRobotID(-numberForID); else set_theRobotID(numberForID);

		                // defaults

                                if (getline(iss, token, FIELD_SERPARATOR)) {
                                        std::size_t found = token.find("RIGHT");
                                        if (std::string::npos!=found)  _theInstruction = TURN_RIGHT_STEP;
                                        else {
                                                found = token.find("LEFT");
                                                if (std::string::npos!=found) _theInstruction = TURN_LEFT_STEP;
                                                else {
                                                        found = token.find("YELLOW");
                                                        if (std::string::npos!=found) _theInstruction = YELLOW_LINE_STRAIGHT_STEP;
                                                        else {
                                                                found = token.find("MAGENTA");
                                                                if (std::string::npos!=found) _theInstruction = MAGENTA_LINE_STRAIGHT_STEP;
                                                                else {
                                                                        found = token.find("COMPLETED");
                                                                        if (std::string::npos!=found) _theInstruction = COMPLETED;
                                                                }
                                                        }
                                                }
		                        }
		                }
                                if (getline(iss, token, FIELD_SERPARATOR)) {
		                        int16_t numberofTimes = int16_t ( atoi(token.c_str())) ;
		                        if (numberofTimes <0) set_howMany(-numberofTimes); else set_howMany(numberofTimes >0 ? numberofTimes : 1);
		                }

		        }
                }

	        private :

        };





}// namespace


#pragma clang diagnostic pop

#endif // WEBOTS_NXT_bridge_DEFINED
