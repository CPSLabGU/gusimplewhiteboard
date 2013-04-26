/**                                                                     
 *  /file HAL_HeadTarget.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef HAL_HeadTarget_DEFINED                                       
#define HAL_HeadTarget_DEFINED

#include <gu_util.h>

namespace guWhiteboard                                                  
{
        enum movement_type
        {
                MoveOverTime = 0,
                MoveWithSpeed
        };
        
        namespace HeadSpeed
        {
                enum head_speed
                {
                        One = 2, //2 is intentional
                        Two,
                        Three,
                        Four,
                        Five,
                        MaxSpeed
                };
        }
        
        class HAL_HeadTarget
        {
                //Angles are in degrees
                PROPERTY(int, target_pitchAngle) ///< not sure, look it up in the AL_Docs
                PROPERTY(int, target_yawAngle) ///< -90 to 90
                
                PROPERTY(movement_type, target_movement_type) ///< Move over time or with a percentage of max speed
                
                //One of these values will be ignored base on the movement_type selected
                PROPERTY(int, target_movement_time) ///< usec
                PROPERTY(int, target_movement_speed) ///< percentage of a predefined max speed (potentially slower than moving with time, but a good deal safer)
                PROPERTY(bool, head_stopped) ///< Will be true if the head is not moving, will also stop the head if set on the WB
                
                BITPROPERTY(head_cmd_mask)
        public:                
                HAL_HeadTarget(int target_pitchAngle = 0, int target_yawAngle = 0, movement_type target_movement_type = MoveOverTime, int target_movement_time = 1000000, int target_movement_speed = 50, bool head_stopped = true)
                {
                        set_target_pitchAngle(target_pitchAngle);
                        set_target_yawAngle(target_yawAngle);
                        set_target_movement_type(target_movement_type);
                        set_target_movement_time(target_movement_time);
                        set_target_movement_speed(target_movement_speed);
                        set_head_stopped(head_stopped);
                        set_head_cmd_mask(false);
                }
                
                void Stop()
                {
                        set_head_stopped(true);
                        set_head_cmd_mask(true);
                }
                
                void GoToWithTime(int yaw, int pitch, int time)
                {
                        set_target_pitchAngle(pitch);
                        set_target_yawAngle(yaw);
                        set_target_movement_time(time);
                        set_head_stopped(false);
                        set_target_movement_type(MoveOverTime);
                        set_head_cmd_mask(true);
                }
                
                void GoToWithSpeed(int yaw, int pitch, HeadSpeed::head_speed speed)
                {
                        set_target_pitchAngle(pitch);
                        set_target_yawAngle(yaw);
                        set_target_movement_speed((int)speed);
                        set_head_stopped(false);
                        set_target_movement_type(MoveWithSpeed);
                        set_head_cmd_mask(true);
                }
        };
}

#endif //HAL_HeadTarget_DEFINED
