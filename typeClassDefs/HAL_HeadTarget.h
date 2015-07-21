/**                                                                     
 *  /file HAL_HeadTarget.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     


                                                                        
#ifndef HAL_HeadTarget_DEFINED                                       
#define HAL_HeadTarget_DEFINED

#include "wb_hal_headtarget.h"

namespace guWhiteboard                                                  
{
	/**
 	* @brief Class for moving a robotic head in abs coords
	*
	* Move the robotics head to the abs coord provided in this class
	*
	* Examples
	* --------
	*
	* Examples of what to do with the class 
	*
	*     HAL_HeadTarget().GoToWithTime(0, 0, 1000000); 	//Move to 0 yaw and 0 pitch over 1 second
	*     HAL_HeadTarget().GoToWithTime(30, 10, 3000000); 	//Move to 30 degrees yaw and 10 degrees pitch over 3 second
	*     HAL_HeadTarget().GoToWithTime_rad(-0.5235, -0.1745, 3000000); 	//Move to -30 degrees yaw and -10 degrees pitch by passing radians values over 3 second
	*     HAL_HeadTarget().Stop(); 	//Stop moving the head, can be issued mid-movement
	*     
	* Class values typically need to be passed to the Whiteboard for them to take effect 
	*     
	*     HAL_HeadTarget_t.set(HAL_HeadTarget().Stop());
	*
 	*/       
        class HAL_HeadTarget : public wb_hal_headtarget
        {
        public:
		/**
 		* Constructor
 		*/       
                HAL_HeadTarget(): wb_hal_headtarget() {}
                
		/**
 		* Set stopping vars 
 		*/       
                void Stop()
                {
                        set_head_stopped(true);
                        set_head_cmd_mask(true);
                }

		/**
 		* move to position in degrees over a given time 
		* @param yaw horiz in abs degrees, see specific robot for limits 
		* @param pitch vert in abs degrees, see specific robot for limits 
		* @param time time in micro seconds for the motion to take
 		*/       
                void GoToWithTime(float yaw, float pitch, int time = 1000000)
                {
                    GoToWithTime_rad(static_cast<float>(DEG2RAD(yaw)), static_cast<float>(DEG2RAD(pitch)), time);
                }
            
		/**
 		* move to position in radians over a given time 
		* @param yaw horiz in abs degrees, see specific robot for limits 
		* @param pitch vert in abs degrees, see specific robot for limits 
		* @param time time in micro seconds for the motion to take
 		*/
                void GoToWithTime_rad(float yaw, float pitch, int time = 1000000)
                {
/*                        if(yaw > float(DEG2RAD(YAW_LIMIT_POS)))
                                yaw = float(DEG2RAD(YAW_LIMIT_POS));
                        else if (yaw < float(DEG2RAD(YAW_LIMIT_NEG)))
                                yaw = float(DEG2RAD(YAW_LIMIT_NEG));
                        
                        if(pitch > float(DEG2RAD(PITCH_LIMIT_POS)))
                                pitch = float(DEG2RAD(PITCH_LIMIT_POS));
                        else if (pitch < float(DEG2RAD(PITCH_LIMIT_NEG)))
                                pitch = float(DEG2RAD(PITCH_LIMIT_NEG));
  */                      
                        set_target_pitchAngle(pitch);
                        set_target_yawAngle(yaw);
                        set_target_movement_time(time);
                        set_head_stopped(false);
                        set_head_cmd_mask(true);
                }
                
                
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
       		/**
 		* String constructor (NYI)
		* @param str the string to parse and use to recreate the this object
		*/
                HAL_HeadTarget(const std::string &str) { from_string(str); }

                /**
 		* Parser for recreating this class (NYI) 
		* @param str the string to parse and use to recreate the this object
		*/
                void from_string(const std::string &str)
                {
			fprintf(stderr, "NYI - Have it back: %s\n", const_cast<char *>(str.c_str()));
                }
 
                /**
 		* Description method for pretty printing the values in this class
		* @return pretty printed string
		*/               
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
