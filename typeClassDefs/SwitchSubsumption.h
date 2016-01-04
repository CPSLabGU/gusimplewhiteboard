/*
 *  SwitchSubsumption.h
 *  gusimplewhiteboard
 *
 *  Created by Vlad Estivill-Castro on 20/11/2015.
 *  Copyright © 2015 Vlad Estivill-Castro. All rights reserved.
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

#ifndef SwitchSubsumption_DEFINED
#define SwitchSubsumption_DEFINED


#include "wb_switch_subsumption.h"
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

namespace guWhiteboard
{
    /**
    *  Subsumption SWITCH that select highest priority command
    *
    */
    class SwitchSubsumption: public wb_switch_subsumption
    {
    public:
       SwitchSubsumption() : wb_switch_subsumption() { }
   
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        SwitchSubsumption(const std::string &motion_command): wb_switch_subsumption() 
	    { from_string(motion_command); }

        /** convert to a string */
        std::string description() const
        {
	    std::ostringstream ss;
	    for (int i=0 ; i< SUBSUMPTION_LEVELS; i++)
	     switch (theMotions(i))
		{ case TOTO_NO_COMMAND : ss << "null, "; break;
		  case TOTO_STOP :  ss << "stop, "; break;
		  case TOTO_BACKWARDS :  ss << "back, "; break;
		  case TOTO_MOVE_FORWARD  :  ss << "forwards, "; break;
		  case TOTO_TURN_LEFT  :  ss << "left, "; break;
		  case TOTO_TURN_RIGHT  :  ss << "right, "; break;
		}
            return ss.str();
        }

        /** convert from a string */
        void from_string(const std::string &str)
        { std::istringstream iss(str);
	  std::string token;
	  for (int i = 0; i < SUBSUMPTION_LEVELS && getline(iss, token, ',') ; i++)
		{ const int n = atoi(token.c_str());
		  enum TotoMotionCommand &comamnd = theMotions(i);
		  if (n<=0) comamnd=TOTO_NO_COMMAND;
		  switch (n)
		  { case 1 : comamnd=TOTO_STOP; break;
		    case 2 : comamnd=TOTO_BACKWARDS; break;
		    case 3 : comamnd=TOTO_MOVE_FORWARD; break;
		    case 4 : comamnd=TOTO_TURN_LEFT; break;
		    case 5 : comamnd=TOTO_TURN_RIGHT; break;
		  }
		}
        }
#endif
    };

    /**
    *  TOTO motion of what is doing 
    *
    */
    class TotoDoingMotion: public wb_toto_doing_motion
    {
    public:
       TotoDoingMotion() : wb_toto_doing_motion() { }
   
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        TotoDoingMotion(const std::string &motion_command): wb_toto_doing_motion() 
	    { from_string(motion_command); }

        /** convert to a string */
        std::string description() const
        {
	    std::ostringstream ss;
	    switch (_motionCommand)
		{ case TOTO_NO_COMMAND : ss << "null, "; break;
		  case TOTO_STOP :  ss << "stop, "; break;
		  case TOTO_BACKWARDS :  ss << "back, "; break;
		  case TOTO_MOVE_FORWARD  :  ss << "forwards, "; break;
		  case TOTO_TURN_LEFT  :  ss << "left, "; break;
		  case TOTO_TURN_RIGHT  :  ss << "right, "; break;
		}
            return ss.str();
        }

        /** convert from a string */
        void from_string(const std::string &str)
        { std::istringstream iss(str);
	  std::string token;
	  for (int i = 0; i < 1 && getline(iss, token, ',') ; i++)
		{ const int n = atoi(token.c_str());
		  if (n<=0) _motionCommand=TOTO_NO_COMMAND;
		  switch (n)
		  { case 1 : _motionCommand=TOTO_STOP; break;
		    case 2 : _motionCommand=TOTO_BACKWARDS; break;
		    case 3 : _motionCommand=TOTO_MOVE_FORWARD; break;
		    case 4 : _motionCommand=TOTO_TURN_LEFT; break;
		    case 5 : _motionCommand=TOTO_TURN_RIGHT; break;
		  }
		}
        }
#endif
    };

}
#endif /* SwitchSubsumption_DEFINED */
