/**                                                                     
 *  /file HAL_ArmTarget.h
 *                                                                      
 *  Created by Dimitri Joukoff 2016.
 *  Copyright (c) 2016 Dimitri Joukoff
 *  All rights reserved.                                                
 */                                                                     


                                                                        
#ifndef HAL_ArmTarget_DEFINED
#define HAL_ArmTarget_DEFINED

#include "wb_hal_armtarget.h"

namespace guWhiteboard                                                  
{
	/**
 	* @brief Class for moving a SINGLE robotic arm with up to 5 degrees of freedom using local coords of each joint.
    *        NAO Arm has 5 degrees of freedom with the axes being:
    *           'shoulder pitch, shoulder roll, elbow roll, elbow yaw, wrist yaw'.
    *           (NOTE: The V3 does not have wrist yaw capability.)
    *        The left and right arm are mirrored about the XZ plane as are the movement limits and ranges.
    *        (doc-release-1.14.5-public/doc-release-1.14-public/family/robots/links_robot.html)
	*
	* Move the robotic arm to the (local) coord provided in this class.
	*
	* Examples
	* --------
	*
	* Examples of what to do with the class 
	*
    *     //Move (left) arm down such that it is parallel to the body at an angle of 5 deg with elbow straight, inner-forearm and palm facing body over 1 second
	*     HAL_ArmTarget().GoToWithTime_Rad(1.5708, 0.0873, -0.0349, -1.5708, -1.5708, 1000000);  // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
    *     HAL_ArmTarget().GoToWithTime_Deg(90, 5, -2, -90, -90, 1000000);                        // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
    *
    *     //Move (right) arm down such that it is parallel to the body at an angle of 5 deg with elbow straight, inner-forearm and palm facing body over 1 second
    *     HAL_ArmTarget().GoToWithTime_Rad(1.5708, -0.0873, 0.0349, 1.5708, 1.5708, 1000000);    // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
    *     HAL_ArmTarget().GoToWithTime_Deg(90, -5, 2, 90, 90, 1000000);                          // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
    *
    *     HAL_ArmTarget().Stop(); 	//Stop moving the arm, can be issued mid-movement
	*     
	* Class values typically need to be passed to the Whiteboard for them to take effect 
	*     
	*     HAL_ArmTarget_t.set(HAL_ArmTarget().Stop());
	*
 	*/       
    class HAL_ArmTarget : public wb_hal_armtarget
    {
            
        public:
            /**
            * Constructor
            */       
            HAL_ArmTarget(const uint8_t &target_arm = LEFT_ARM): wb_hal_armtarget(target_arm) {}
            HAL_ArmTarget(): wb_hal_armtarget() {}
        
            /**
             * Specify which arm this instance manages.
             * Up to 256 arms are possible.
             * Use prefedined macros LEFT_ARM and RIGHT_ARM for clarity.
             */
            void tieToArm(uint8_t arm)
            {
                set_target_arm(arm);
            }
        
            /**
             * Set stopping vars
             */
            void Stop()
            {
                set_arm_stopped(true);
                set_arm_cmd_mask(true);
            }


            void SetArmStiffnessMax()
            {
                set_target_shoulderpitchstiffness(1.0f);
                set_target_shoulderrollstiffness(1.0f);
                set_target_elbowrollstiffness(1.0f);
                set_target_elbowyawstiffness(1.0f);
                set_target_wristyawstiffness(1.0f);
            }

            void SetArmStiffnessNormal()
            {
                set_target_shoulderpitchstiffness(0.6f);
                set_target_shoulderrollstiffness(0.6f);
                set_target_elbowrollstiffness(0.6f);
                set_target_elbowyawstiffness(0.6f);
                set_target_wristyawstiffness(0.6f);
            }

            void SetArmStiffnessOff()
            {
                set_target_shoulderpitchstiffness(0.0f);
                set_target_shoulderrollstiffness(0.0f);
                set_target_elbowrollstiffness(0.0f);
                set_target_elbowyawstiffness(0.0f);
                set_target_wristyawstiffness(0.0f);
            }

            /**
             * move to position expressed in degrees over a given time
             * @param shoulderpitch (down to up)
             * @param shoulderroll  (out to in)
             * @param elbowroll     (straight to bent)
             * @param elbowyaw      (rolled right to rolled left)
             * @param wristyaw      (rolled right to rolled left)

             * @param time time in micro seconds for the motion to take
             */
            void GoToWithTime_Deg(float shoulderpitch, float shoulderroll, float elbowroll, float elbowyaw, float wristyaw, int time = 1000000)
            {
                GoToWithTime_Rad(static_cast<float>(DEG2RAD(shoulderpitch)),
                                 static_cast<float>(DEG2RAD(shoulderroll)),
                                 static_cast<float>(DEG2RAD(elbowroll)),
                                 static_cast<float>(DEG2RAD(elbowyaw)),
                                 static_cast<float>(DEG2RAD(wristyaw)),
                                 time);
            }
        
            /**
             * move to position in radians over a given time
             * @param shoulderpitch (down to up)
             * @param shoulderroll  (out to in)
             * @param elbowroll     (straight to bent)
             * @param elbowyaw      (rolled right to rolled left)
             * @param wristyaw      (rolled right to rolled left)
             * @param time time in micro seconds for the motion to take
             */
            void GoToWithTime_Rad(float shoulderpitch, float shoulderroll, float elbowroll, float elbowyaw, float wristyaw, int time = 1000000)
            {
                if (shoulderpitch < SHOULDER_PITCH_LIMIT_DOWN_RAD && shoulderpitch > SHOULDER_PITCH_LIMIT_UP_RAD) {
                    set_target_shoulderpitch(shoulderpitch);
                }
                if (elbowyaw < LEFT_ELBOW_YAW_RIGHT_RAD && elbowyaw > LEFT_ELBOW_YAW_LEFT_RAD) { // LEFT and RIGHT are same for this axis.
                    set_target_elbowyaw(elbowyaw);
                }
                if (wristyaw < LEFT_WRIST_YAW_RIGHT_RAD && wristyaw > LEFT_WRIST_YAW_LEFT_RAD) { // LEFT and RIGHT are same for this axis.
                    set_target_wristyaw(wristyaw);
                }
                
                if (_target_arm == LEFT_ARM) {
                    if (shoulderroll < LEFT_SHOULDER_ROLL_OUT_RAD && shoulderroll > LEFT_SHOULDER_ROLL_IN_RAD) {
                        set_target_shoulderroll(shoulderroll);
                    }
                    if (elbowroll < LEFT_ELBOW_ROLL_STRAIGHT_RAD && elbowroll > LEFT_ELBOW_ROLL_BENT_RAD) {
                        set_target_elbowroll(elbowroll);
                    }
                } else if (_target_arm == RIGHT_ARM) {
                    if (shoulderroll > RIGHT_SHOULDER_ROLL_OUT_RAD && shoulderroll < RIGHT_SHOULDER_ROLL_IN_RAD) {
                        set_target_shoulderroll(shoulderroll);
                    }
                    if (elbowroll > RIGHT_ELBOW_ROLL_STRAIGHT_RAD && elbowroll < RIGHT_ELBOW_ROLL_BENT_RAD) {
                        set_target_elbowroll(elbowroll);
                    }
                }
                set_target_movement_time(time);
                set_arm_stopped(false);
                set_arm_cmd_mask(true);
            }
        
            void MirrorArm(const HAL_ArmTarget &other)
            {
                set_target_shoulderpitch(other.target_shoulderpitch());
                set_target_shoulderroll(other.target_shoulderroll());
                set_target_elbowroll(other.target_elbowroll());
                set_target_elbowyaw(other.target_elbowyaw());
                set_target_wristyaw(other.target_wristyaw());
                set_target_shoulderpitchstiffness(other.target_shoulderpitchstiffness());
                set_target_shoulderrollstiffness(other.target_shoulderrollstiffness());
                set_target_elbowrollstiffness(other.target_elbowrollstiffness());
                set_target_elbowyawstiffness(other.target_elbowyawstiffness());
                set_target_wristyawstiffness(other.target_wristyawstiffness());
                set_target_movement_time(other.target_movement_time());
                set_arm_stopped(other.arm_stopped());
                set_arm_cmd_mask(other.arm_cmd_mask());
            }
            
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            /**
             * String constructor (NYI)
             * @param str the string to parse and use to recreate the this object
             */
            HAL_ArmTarget(const std::string &str) { from_string(str); }

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
//                ss << target_pitchAngle() << " P, " << target_yawAngle() << " Y, " << target_movement_time() << " T, " << head_stopped() << " S, " << head_cmd_mask() << " M";
                return ss.str();
            }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //HAL_HeadTarget_DEFINED
