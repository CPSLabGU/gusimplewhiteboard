/**                                                                     
 *  /file HAL_HeadTarget.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef HAL_HeadTarget_DEFINED                                       
#define HAL_HeadTarget_DEFINED

#include <vector>

namespace guWhiteboard                                                  
{
        enum movement_type
        {
                MoveOverTime = 0,
                MoveWithSpeed
        };
        
        class HAL_HeadTarget
        {
        public:
                
                //Angles are in degrees
                int target_pitchAngle; //not sure, look it up in the AL_Docs
                int target_yawAngle; //-90 to 90
                
                movement_type target_movement_type; //Move over time or with a percentage of max speed
                
                //One of these values will be ignored base on the movement_type selected
                int target_movement_time; //usec
                int target_movement_speed; //percentage of a predefined max speed (potentially slower than moving with time, but a good deal safer)
                bool head_stopped; //Will be true if the head is not moving, will also stop the head if set on the WB
                
                HAL_HeadTarget(int target_pitchAngle = 0, int target_yawAngle = 0, movement_type target_movement_type = MoveOverTime, int target_movement_time = 1000000, int target_movement_speed = 50, bool head_stopped = true)
                {
                        this->target_pitchAngle = target_pitchAngle;
                        this->target_yawAngle = target_yawAngle;
                        this->target_movement_speed = (movement_type)target_movement_type;
                        this->target_movement_time = target_movement_time;
                        this->target_movement_speed = target_movement_speed;
                        this->head_stopped = head_stopped;
                }
        };
}

#endif //HAL_HeadTarget_DEFINED
