/**                                                                     
 *  /file MOTION_SDK_Interface.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef MOTION_SDK_Interface_DEFINED
#define MOTION_SDK_Interface_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cctype>
#include <cstdlib>
#include <string>
#include <sstream>
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

#include <gu_util.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

namespace guWhiteboard                                                  
{
        namespace Motions
        {
                enum recorded_motions
                {
                        right_goalie_block = 0,
                        finish_right_goalie_block,
                        left_goalie_block,
                        finish_left_goalie_block,
                        get_up_from_back_lie_down,
                        get_up_from_front_lie_down,
                        get_up_from_kneel,
                        get_up_from_sit,
                        goalie_stand_pose,
                        hip_turn_left_kick,
                        hip_turn_right_kick,
                        kneel,
                        left_kick,
                        left_ninja_kick,
                        pass_ball_left,
                        pass_ball_right,
                        right_kick,
                        right_ninja_kick,
                        side_to_lie_down,
                        sit_from_front_lie_down,
                        sit_from_back_lie_down,
                        sit_from_kneel_or_stand,
                        dcm_from_getup,
                        OFF
                };
        }
        
        class MOTION_SDK_Interface
        {
                PROPERTY(Motions::recorded_motions, motion_player)

                BITPROPERTY(head_stiffness)
                BITPROPERTY(body_stiffness)

                /* Control bits */
                BITPROPERTY(head_stiffness_mask)
                BITPROPERTY(body_stiffness_mask)
                BITPROPERTY(motion_player_mask)

        public:                
                MOTION_SDK_Interface(bool head_stiffness = false, bool body_stiffness = false, Motions::recorded_motions motion_player = Motions::OFF)
                {
                        _head_stiffness = head_stiffness;
                        _body_stiffness = body_stiffness;
                        _motion_player = motion_player;
                }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /// string constructor (see from_string() below)
                MOTION_SDK_Interface(const std::string &str) { from_string(str); }

                /**
                 * set head and/or body stiffness, and/or start a motion
                 * through a string of the form
                 *
                 * [0|1][,0|1][[,]motion_command]
                 */
                void from_string(const std::string &str)
                {
                        using namespace Motions;
                        const char *s = str.c_str();
                        bool want_head_stiffness = isdigit(*s);

                        if (want_head_stiffness)
                        {
                                set_head_stiffness_mask();
                                set_head_stiffness(unsigned(atoi(s)));
                                while (isdigit(*s)) s++;
                        }
                        if (*s == ',' && isdigit(*++s)) // check body stiffness?
                        {
                                set_body_stiffness_mask();
                                set_body_stiffness(unsigned(atoi(s)));
                                while (isdigit(*s)) s++;
                        }
                        set_motion_player_mask();
                        CHECK_ENUM(s, motion_player, right_goalie_block);
                        else CHECK_ENUM(s, motion_player, finish_right_goalie_block);
                        else CHECK_ENUM(s, motion_player, left_goalie_block);
                        else CHECK_ENUM(s, motion_player, finish_left_goalie_block);
                        else CHECK_ENUM(s, motion_player, get_up_from_back_lie_down);
                        else CHECK_ENUM(s, motion_player, get_up_from_kneel);
                        else CHECK_ENUM(s, motion_player, get_up_from_sit);
                        else CHECK_ENUM(s, motion_player, goalie_stand_pose);
                        else CHECK_ENUM(s, motion_player, hip_turn_left_kick);
                        else CHECK_ENUM(s, motion_player, hip_turn_right_kick);
                        else CHECK_ENUM(s, motion_player, kneel);
                        else CHECK_ENUM(s, motion_player, left_kick);
                        else CHECK_ENUM(s, motion_player, left_ninja_kick);
                        else CHECK_ENUM(s, motion_player, pass_ball_left);
                        else CHECK_ENUM(s, motion_player, pass_ball_right);
                        else CHECK_ENUM(s, motion_player, right_kick);
                        else CHECK_ENUM(s, motion_player, right_ninja_kick);
                        else CHECK_ENUM(s, motion_player, side_to_lie_down);
                        else CHECK_ENUM(s, motion_player, sit_from_front_lie_down);
                        else CHECK_ENUM(s, motion_player, sit_from_back_lie_down);
                        else CHECK_ENUM(s, motion_player, sit_from_kneel_or_stand);
                        else CHECK_ENUM(s, motion_player, dcm_from_getup);
                        else CHECK_ENUM(s, motion_player, OFF);
                        else set_motion_player_mask(false);
                }

#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wunreachable-code"

                /**
                 * return the head and body stiffness as a boolean
                 */
                std::string description() const
                {
                        using namespace Motions;
                        std::stringstream ss;
                        bool need_comma = false;
                        if (head_stiffness_mask())
                        {
                                ss << head_stiffness();
                                need_comma = true;
                        }
                        if (body_stiffness_mask())
                        {
                                ss << "," << body_stiffness();
                                need_comma = true;
                        }
                        if (motion_player_mask())
                        {
                                if (need_comma) ss << ",";
                                switch (motion_player())
                                {
                                        STREAM_ENUM_CASE(ss, right_goalie_block);
                                        STREAM_ENUM_CASE(ss, finish_right_goalie_block);
                                        STREAM_ENUM_CASE(ss, left_goalie_block);
                                        STREAM_ENUM_CASE(ss, finish_left_goalie_block);
                                        STREAM_ENUM_CASE(ss, get_up_from_back_lie_down);
                                        STREAM_ENUM_CASE(ss, get_up_from_front_lie_down);
                                        STREAM_ENUM_CASE(ss, get_up_from_kneel);
                                        STREAM_ENUM_CASE(ss, get_up_from_sit);
                                        STREAM_ENUM_CASE(ss, goalie_stand_pose);
                                        STREAM_ENUM_CASE(ss, hip_turn_left_kick);
                                        STREAM_ENUM_CASE(ss, hip_turn_right_kick);
                                        STREAM_ENUM_CASE(ss, kneel);
                                        STREAM_ENUM_CASE(ss, left_kick);
                                        STREAM_ENUM_CASE(ss, left_ninja_kick);
                                        STREAM_ENUM_CASE(ss, pass_ball_left);
                                        STREAM_ENUM_CASE(ss, pass_ball_right);
                                        STREAM_ENUM_CASE(ss, right_kick);
                                        STREAM_ENUM_CASE(ss, right_ninja_kick);
                                        STREAM_ENUM_CASE(ss, side_to_lie_down);
                                        STREAM_ENUM_CASE(ss, sit_from_front_lie_down);
                                        STREAM_ENUM_CASE(ss, sit_from_back_lie_down);
                                        STREAM_ENUM_CASE(ss, sit_from_kneel_or_stand);
                                        STREAM_ENUM_CASE(ss, dcm_from_getup);
                                        STREAM_ENUM_CASE(ss, OFF);
                                        default: break;
                                }
                        }
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
       };
}

#pragma clang diagnostic pop

#endif //MOTION_SDK_Commands_DEFINED
