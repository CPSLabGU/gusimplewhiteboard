/**                                                                     
 *  /file wb_hal_headtarget.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_hal_headtarget_h
#define _wb_hal_headtarget_h

#include <gu_util.h>

#define YAW_LIMIT_POS 90
#define YAW_LIMIT_NEG -YAW_LIMIT_POS
#define PITCH_LIMIT_POS 28
#define PITCH_LIMIT_NEG -20

/**
 * HAL_HeadTarget c struct
 */
struct wb_hal_headtarget
{
        PROPERTY(float, target_pitchAngle) ///< target pitch angle in radians
        PROPERTY(float, target_yawAngle) ///< target yaw angle in radians
            
        PROPERTY(int, target_movement_time) ///< How long until the head should be at the target angles, stored in micro seconds
        BIT_PROPERTY(head_stopped) ///< Should the head be stopped (if setting) or is the head stopped (if a status message)
                
        BIT_PROPERTY(head_cmd_mask) ///< Should the command be processed again by the motion module. When changes are made this bit is set to true. Motion sets this back to false when the command has been processed.
        unsigned pad: 30; ///< padding

#ifdef __cplusplus
    /**
    * constructor for the stuct of HAL_HeadTarget. this is the data that is placed on the Whiteboard 
    * @param target_pitchAngle desired pitch
    * @param target_yawAngle desired yaw
    * @param target_movement_time time to take
    * @param head_stopped should the head stop
    */       
    wb_hal_headtarget(float target_pitchAngle = 0, float target_yawAngle = 0, int target_movement_time = 1000000, bool head_stopped = true)
 {
        set_target_pitchAngle(target_pitchAngle);
        set_target_yawAngle(target_yawAngle);
        set_target_movement_time(target_movement_time);
        set_head_stopped(head_stopped);
        set_head_cmd_mask(false);
}
#endif
};

#endif //_wb_hal_headtarget_h
