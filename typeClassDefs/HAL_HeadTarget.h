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

#define YAW_LIMIT_POS 90
#define YAW_LIMIT_NEG -YAW_LIMIT_POS
#define PITCH_LIMIT_POS 28
#define PITCH_LIMIT_NEG -20

namespace guWhiteboard                                                  
{
        class HAL_HeadTarget
        {
                //Angles are in degrees
                PROPERTY(float, target_pitchAngle) ///< not sure, look it up in the AL_Docs
                PROPERTY(float, target_yawAngle) ///< 
            
                //One of these values will be ignored base on the movement_type selected
                PROPERTY(int, target_movement_time) ///< usec
                BITPROPERTY(head_stopped) ///< Will be true if the head is not moving, will also stop the head if set on the WB
                
                BITPROPERTY(head_cmd_mask)
        public:
            
                HAL_HeadTarget(float target_pitchAngle = 0, float target_yawAngle = 0, int target_movement_time = 1000000, bool head_stopped = true)
                {
                        set_target_pitchAngle(target_pitchAngle);
                        set_target_yawAngle(target_yawAngle);
                        set_target_movement_time(target_movement_time);
                        set_head_stopped(head_stopped);
                        set_head_cmd_mask(false);
                }
                
                void Stop()
                {
                        set_head_stopped(true);
                        set_head_cmd_mask(true);
                }

                void GoToWithTime(float yaw, float pitch, int time = 1000000)
                {
                    GoToWithTime_rad((float)DEG2RAD(yaw), (float)DEG2RAD(pitch), time);
                }
            
                void GoToWithTime_rad(float yaw, float pitch, int time = 1000000)
                {
                        if(yaw > float(DEG2RAD(YAW_LIMIT_POS)))
                                yaw = float(DEG2RAD(YAW_LIMIT_POS));
                        else if (yaw < float(DEG2RAD(YAW_LIMIT_NEG)))
                                yaw = float(DEG2RAD(YAW_LIMIT_NEG));
                        
                        if(pitch > float(DEG2RAD(PITCH_LIMIT_POS)))
                                pitch = float(DEG2RAD(PITCH_LIMIT_POS));
                        else if (pitch < float(DEG2RAD(PITCH_LIMIT_NEG)))
                                pitch = float(DEG2RAD(PITCH_LIMIT_NEG));
                        
                        set_target_pitchAngle(pitch);
                        set_target_yawAngle(yaw);
                        set_target_movement_time(time);
                        set_head_stopped(false);
                        set_head_cmd_mask(true);
                }
                
                
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /// string constructor (see from_string() below)
                HAL_HeadTarget(const std::string &str) { from_string(str); }
                
                void from_string(const std::string &/*str*/)
                {
                       //NYI, Good luck
                }
                
                std::string description() const
                {
                        std::stringstream ss;
                        ss << target_pitchAngle() << " P, " << target_yawAngle() << " Y, " << target_movement_time() << " T, " << head_stopped() << " S, " << head_cmd_mask() << " M";
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //HAL_HeadTarget_DEFINED
