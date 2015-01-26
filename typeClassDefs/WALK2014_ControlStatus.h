/**                                                                     
 *  /file WALK2014_ControlStatus.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                         
#ifndef WALK2014_ControlStatus_DEFINED
#define WALK2014_ControlStatus_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <string>
#include <sstream>
#include <ctype.h>
#endif

#include <float.h>
#include "wb_walk2014_controlstatus.h"

namespace guWhiteboard
{
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        static const char *Walk2014Options_strings[] =
        {
                "DISCONNECT", "STAND", "WALK", "READY", "KICK", "RESET_ODOMETRY", "STANDUP", "CROUCH", "NONE", "NUMBER_OF_WALK_OPTIONS"
        };
        static const char *WalkState_strings[] =
        {
                "NOT_WALKING", "WALKING", "STARTING", "STOPPING", "NUMBER_OF_WALK_STATES"
        };
        static const char *KickingFoot_strings[] =
        {
                "LEFT", "RIGHT"
        };
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * Nao Walk control and status class
         */
        class WALK2014_ControlStatus : public wb_walk2014_controlstatus
        {
        public:
                /** designated constructor */
                WALK2014_ControlStatus(Walk2014Option option = DISCONNECT, float forward = 0, float left = 0, float turn = 0, float power = 0, KickingFoot foot): wb_walk2014_controlstatus(option, forward, left, turn, power, foot) {}

                /** copy constructor */
                WALK2014_ControlStatus(const WALK_ControlStatus &other) : wb_walk2014_controlstatus(other.walk_state(), other.forward(), other.left(), other.turn(), other.power(), other.foot) { }

                /** copy assignment operator */
                WALK2014_ControlStatus &operator=(const WALK_ControlStatus &other) { set_walk_state(other.walk_state()); set_forward(other.forward()); set_left(other.left()); set_turn(other.turn()); set_power(other.power()); set_foot(other.foot());return *this; }

                /** comparison operator */
		inline bool operator == (const WALK2014_ControlStatus &s) 
		{
    			return (fabs(forward() - s.forward()) < FLT_EPSILON &&
				fabs(left() - s.left()) < FLT_EPSILON &&
				fabs(turn() - s.turn()) < FLT_EPSILON &&
				fabs(power() - s.power()) < FLT_EPSILON &&
				fabs(foot() - s.foot()) < FLT_EPSILON &&
				walk_state()	== s.walk_state() &&
				walking_status()	== s.walking_status() &&
				odometry() 	== s.odometry());
		}

                /** inverse comparison operator */
		inline bool operator != (const WALK2014_ControlStatus &s) 
		{
			return !((*this) == s);
		}
		
            
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor */
                WALK2014_ControlStatus(const std::string &command) { from_string(command); }

                /** convert to a string */
                std::string description() const
                {
                        std::ostringstream ss;
                        ss << Walk2014Options_strings[walk_state()] << ", \t";
                        ss << WalkState_strings[walk_status()] << ", \t";
                        ss << "(" << forward() << "," << left() << "," << turn() << "," << power() << ") ";
			ss << "F: " << KickingFoot_strings[foot()] << ", ";
                        ss << " @(" << odometry().forward << "," << odometry().left << "," << odometry().turn << ")";

                        return ss.str();
                }

                /** convert from a string */
                void from_string(const std::string &command)
                {
			fprintf(stderr, "Looks like this is NYI, have it back %s\n", const_cast<char *>(command.c_str()));
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif // WALK2014_ControlStatus_DEFINED
