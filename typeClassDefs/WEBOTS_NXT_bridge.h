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

#include <cstdlib>
#include <sstream>
#include <gu_util.h>

namespace guWhiteboard
{
       //ID's for motor's in differential robots
        enum DifferentialMotor {
                LEFT_MOTOR_DIFFERENTIAL = 0,
                RIGHT_MOTOR_DIFFERENTIAL = 1,
                NXT_MOTOR3 = 2 //constant for the third motor on nxt's
             };

	/**
	 * The MOVE_MOTORS instruction sets the sppeds of a Webots Differential Robot
	 * the FIRST parameter will be the LEFT motor
	 * the SECOND parameter will be the SECOND motor
	 * according to the Webots documentaiton, this is radians per second.
	 * but it does not seem tight.
	 * TODO: CHECK OR DETERMINE THE SPEED
	 */

       enum DifferentialInstructions {
                MOVE_MOTORS= 0,
		PLAY_SOUND= 1,
		LIGHTUP_LED = 2 //constant for the third motor on nxt's
             };

        /**
         * Class for for demonstrating OO-messages.
         */
        class WEBOTS_NXT_bridge
        {
            PROPERTY(DifferentialInstructions, theInstruction) ///<  The command
            PROPERTY(int16_t, firstParameter) ///<  the first parameter
            PROPERTY(int16_t, secondParameter) ///<  the first parameter

        public:
            /** designated constructor */
            WEBOTS_NXT_bridge(DifferentialInstructions  theInstruction = MOVE_MOTORS, int16_t firstParameter = 0, int16_t secondParameter=0): _theInstruction(theInstruction), _firstParameter(firstParameter), _secondParameter(secondParameter)  { /* better than set_x(x); set_y(y) */ }

            /** string constructor */
            WEBOTS_NXT_bridge(const std::string &names) { from_string(names); }

            /** copy constructor */
            WEBOTS_NXT_bridge(const WEBOTS_NXT_bridge &other): _theInstruction(other._theInstruction), _firstParameter(other._firstParameter), _secondParameter(other._secondParameter) {}

            /** convert to a string */
            std::string description()
            {
                std::ostringstream ss;
		switch(_theInstruction)
		{ case MOVE_MOTORS : ss << "MOVE_MOTORS" << "," << _firstParameter << "," << _secondParameter << "," ;
			               break;
		  case PLAY_SOUND : ss << "PLAY_SOUND" << "," << _firstParameter  << ",";
			               break;
		  case LIGHTUP_LED : ss << "LIGHTUP_LED" << _firstParameter << ",";
			               break;
		}
                return ss.str();
            }

            /** convert from a string */
            void from_string(const std::string &str)
            {
                std::istringstream iss(str);
                std::string token;
                if (getline(iss, token, ','))
                { set_firstParameter(0);
		    set_secondParameter(0);
		    switch (token[0])
		    { case 'M' :  // expect a MOVE_MOTORS
                                   if (getline(iss, token, ','))
                                     { set_firstParameter(int16_t(atoi(token.c_str())));
                                      }
                                   if (getline(iss, token, ','))
                                     { set_secondParameter(int16_t(atoi(token.c_str())));
                                      }
			    break;
		      case 'P' : // expect a PLAY_SOUND
                                   if (getline(iss, token, ','))
                                     { set_firstParameter(int16_t(atoi(token.c_str())));
                                      }
			    break;
		      case 'L' : // expect a LIGHTUP_LED
                                   if (getline(iss, token, ','))
                                     { set_firstParameter(int16_t(atoi(token.c_str())));
                                      }
			    break;
		    }
                }
            }
        };
}


#endif // WEBOTS_NXT_bridge_DEFINED
