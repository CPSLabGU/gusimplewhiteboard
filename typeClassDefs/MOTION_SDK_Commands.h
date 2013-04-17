/**                                                                     
 *  /file MOTION_SDK_Commands.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef MOTION_SDK_Commands_DEFINED
#define MOTION_SDK_Commands_DEFINED

#include <gu_util.h>

namespace guWhiteboard                                                  
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
                sit_form_front_lie_down,
                sit_from_back_lie_down,
                sit_from_kneel_or_stand,
                dcm_from_getup,
                OFF
        };
                
        class MOTION_SDK_Commands
        {
                BITPROPERTY(head_stiffness)
                BITPROPERTY(body_stiffness)
                PROPERTY(recorded_motions, motion_player)
                

        public:                
                MOTION_SDK_Commands(bool head_stiffness = false, bool body_stiffness = false, recorded_motions motion_player = OFF)
                {
                        _head_stiffness = head_stiffness;
                        _body_stiffness = body_stiffness;
                        _motion_player = motion_player;
                }
        };
}

#endif //MOTION_SDK_Commands_DEFINED
