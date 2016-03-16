/*
 *  SwitchSubsumptionTrafficLights.h
 *  gusimplewhiteboard
 *
 *  Created by Vlad Estivill-Castro on 16/03/2016.
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

#ifndef SwitchSubsumptionTrafficLights_DEFINED
#define SwitchSubsumptionTrafficLights_DEFINED


#include "wb_switch_subsumption_traffic_lights.h"
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
    class SwitchSubsumptionTrafficLights: public wb_switch_subsumption_traffic_lights
    {
    public:
       SwitchSubsumptionTrafficLights() : wb_switch_subsumption_traffic_lights() { }
   
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        SwitchSubsumptionTrafficLights(const std::string &light_configuration): wb_switch_subsumption_traffic_lights() 
	    { from_string(light_configuration); }

        /** convert to a string */
        std::string description() const
        {
	    std::ostringstream ss;
	    for (int i=0 ; i< TL_SUBSUMPTION_LEVELS; i++)
	     switch (theConfigurations(i))
		{ case LIGHT_NO_COMMAND : ss << "null, "; break;
		  case LIGHT_NS_GREEN :  ss << "ns_green, "; break;
		  case LIGHT_EW_GREEN :  ss << "ew_green, "; break;
		  case LIGHT_NS_AMBER  :  ss << "ns_amber, "; break;
		  case LIGHT_EW_AMBER  :  ss << "ew_amber, "; break;
		  case LIGHT_NS_RED  :  ss << "ns_red, "; break;
		  case LIGHT_EW_RED  :  ss << "ew_red, "; break;
		  case LIGHT_ALL_OFF  :  ss << "all_off, "; break;
		  case LIGHT_BOTH_AMBER  :  ss << "b_amber, "; break;
		}
            return ss.str();
        }

        /** convert from a string */
        void from_string(const std::string &str)
        { std::istringstream iss(str);
	  std::string token;
	  for (int i = 0; i < TL_SUBSUMPTION_LEVELS && getline(iss, token, ',') ; i++)
		{ const int n = atoi(token.c_str());
		  enum TrafficLightConfiguration &configuration = theConfigurations(i);
		  if (n<=0) configuration=LIGHT_NO_COMMAND;
		  switch (n)
		  { case 1 : configuration=LIGHT_NS_GREEN; break;
		    case 2 : configuration=LIGHT_EW_GREEN; break;
		    case 3 : configuration=LIGHT_NS_AMBER; break;
		    case 4 : configuration=LIGHT_EW_AMBER; break;
		    case 5 : configuration=LIGHT_NS_RED; break;
		    case 6 : configuration=LIGHT_EW_RED; break;
		    case 7 : configuration=LIGHT_ALL_OFF; break;
		    case 8 : configuration=LIGHT_BOTH_AMBER; break;
		  }
		}
        }
#endif
    };

    /**
    *
    */
    class TrafficLightConfiguration: public wb_traffic_light_configuration
    {
    public:
       TrafficLightConfiguration() : wb_traffic_light_configuration() { }
   
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        TrafficLightConfiguration(const std::string &light_configuration): wb_traffic_light_configuration() 
	    { from_string(light_configuration); }

        /** convert to a string */
        std::string description() const
        {
	    std::ostringstream ss;
	    switch (_lightConfiguration)
		{ case LIGHT_NO_COMMAND : ss << "null, "; break;
		  case LIGHT_NS_GREEN :  ss << "ns_green, "; break;
		  case LIGHT_EW_GREEN :  ss << "ew_green, "; break;
		  case LIGHT_NS_AMBER  :  ss << "ns_amber, "; break;
		  case LIGHT_EW_AMBER  :  ss << "ew_amber, "; break;
		  case LIGHT_NS_RED  :  ss << "ns_red, "; break;
		  case LIGHT_EW_RED  :  ss << "ew_red, "; break;
		  case LIGHT_ALL_OFF  :  ss << "all_off, "; break;
		  case LIGHT_BOTH_AMBER  :  ss << "b_amber, "; break;
		}
            return ss.str();
        }

        /** convert from a string */
        void from_string(const std::string &str)
        { std::istringstream iss(str);
	  std::string token;
	  for (int i = 0; i < 1 && getline(iss, token, ',') ; i++)
		{ const int n = atoi(token.c_str());
		  if (n<=0) _lightConfiguration=LIGHT_NO_COMMAND;
		  switch (n)
		  { case 1 : _lightConfiguration=LIGHT_NS_GREEN; break;
		    case 2 : _lightConfiguration=LIGHT_EW_GREEN; break;
		    case 3 : _lightConfiguration=LIGHT_NS_AMBER; break;
		    case 4 : _lightConfiguration=LIGHT_EW_AMBER; break;
		    case 5 : _lightConfiguration=LIGHT_NS_RED; break;
		    case 6 : _lightConfiguration=LIGHT_EW_RED; break;
		    case 7 : _lightConfiguration=LIGHT_ALL_OFF; break;
		    case 8 : _lightConfiguration=LIGHT_BOTH_AMBER; break;
		  }
		}
        }
#endif
    };

}
#endif /* SwitchSubsumptionTrafficLights_DEFINED */
