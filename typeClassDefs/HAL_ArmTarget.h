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
#include <cmath>
#include <sstream>

#ifndef M_PIF
#define M_PIF static_cast<float>(M_PI)
#endif  // M_PIF

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
	* Examples of what to do with the class (note that HAL_ArmTarget needs to be assigned to desired arm)
	*
    *     //Move (left) arm down such that it is parallel to the body at an angle of 5 deg with elbow straight, inner-forearm and palm facing body over 1 second
	*     HAL_ArmTarget().GoToWithTime_Rad(1.5708, 0.0873, -0.0349, -1.5708, -1.5708, 10000);  // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
    *     HAL_ArmTarget().GoToWithTime_Deg(90, 5, -2, -90, -90, 10000);                        // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
    *
    *     //Move (right) arm down such that it is parallel to the body at an angle of 5 deg with elbow straight, inner-forearm and palm facing body over 1 second
    *     HAL_ArmTarget().GoToWithTime_Rad(1.5708, -0.0873, 0.0349, 1.5708, 1.5708, 10000);    // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
    *     HAL_ArmTarget().GoToWithTime_Deg(90, -5, 2, 90, 90, 10000);                          // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
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
            * Constructor, defaults to LEFT_ARM
            */
            HAL_ArmTarget(const uint8_t &target_arm = LEFT_ARM): wb_hal_armtarget(target_arm) {}
//            HAL_ArmTarget(const HAL_ArmTarget &other): wb_hal_armtarget(other) {}
        
        
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
             *  Set arm to be passive
             *  Manually moving the arm causes the arm to remain in the new position.
             *  Be careful using this with high stiffness settings (which vary per joint).
             *
             *  NOTE:  This is achieved by telling the DCM to move the arm to the displaced
             *         position.  Thus the DCM tracks the applied force.
             */
            void Passive()
            {
                set_arm_active(false);
            }
        
            /**
             *  Activate the arm
             *  The arm is active and manual movements will be resisted.
             *  Once the applied force is removed, the arm will return to its previous location.
             *  Be careful using this with high stiffness settings (which vary per joint).
             *
             *  NOTE:  This is the default DCM mode.
             */
            void Active()
            {
                set_arm_active(true);
            }

            /**
             *  Arm arrived at goal pose.
             *  Only set in the status message.
             */
            void IsAtGoal(bool goalReached)
            {
                set_arm_at_goal(goalReached);
            }

            /**
             *  Is the arm at the goal pose?
             *  Naoqi Interface sets this true when the arm reaches the goal
             *  pose asked for in the previous control message.
             */
            bool AtGoal()
            {
                return arm_at_goal();
            }

            /**
             *  Convenience function to set the stiffness
             *  of all the arm's joints to the maximum (1.0f).
             */
            void SetArmStiffnessMax()
            {
                set_shoulderpitchstiffness(1.0f);
                set_shoulderrollstiffness(1.0f);
                set_elbowrollstiffness(1.0f);
                set_elbowyawstiffness(1.0f);
                set_wristyawstiffness(1.0f);
            }

            /**
             *  Convenience function to set the stiffness
             *  of all the arm's joints to what Aldebaran
             *  considers 'normal' (0.6f).
             */
            void SetArmStiffnessNormal()
            {
                set_shoulderpitchstiffness(0.6f);
                set_shoulderrollstiffness(0.6f);
                set_elbowrollstiffness(0.6f);
                set_elbowyawstiffness(0.6f);
                set_wristyawstiffness(0.6f);
            }

            /**
             *  Convenience function to set uniform stiffness
             *  on all arm joints.
             *
             *  @param stiffness float Stiffness setting between 0.0 and 1.0 (float).
             */
            void SetArmStiffness(float stiffness)
            {
                if ((stiffness <= 1.0f) && (stiffness >=0.0f)) {
                    set_shoulderpitchstiffness(stiffness);
                    set_shoulderrollstiffness(stiffness);
                    set_elbowrollstiffness(stiffness);
                    set_elbowyawstiffness(stiffness);
                    set_wristyawstiffness(stiffness);
                }
            }

            /**
             *  Convenience function to turn off stiffness
             *  in all the arm's joints (0.0f).
             */
            void SetArmStiffnessOff()
            {
                set_shoulderpitchstiffness(0.0f);
                set_shoulderrollstiffness(0.0f);
                set_elbowrollstiffness(0.0f);
                set_elbowyawstiffness(0.0f);
                set_wristyawstiffness(0.0f);
            }

            void CopyStiffness(const HAL_ArmTarget &other)
            {
                target_shoulderpitchstiffness() = other.target_shoulderpitchstiffness();
                target_shoulderrollstiffness() = other.target_shoulderrollstiffness();
                target_elbowrollstiffness() = other.target_elbowrollstiffness();
                target_elbowyawstiffness() = other.target_elbowyawstiffness();
                target_wristyawstiffness() = other.target_wristyawstiffness();
            }
        
            /**
             * move to position in radians over a given time
             * @param shoulderpitch  down to up
             * @param shoulderroll   out to in
             * @param elbowroll      straight to bent
             * @param elbowyaw       rolled right to rolled left
             * @param wristyaw       rolled right to rolled left
             * @param time           time in mSec for the motion to take
             */
            void GoToWithTime_Rad(float shoulderpitch,
                                  float shoulderroll,
                                  float elbowroll,
                                  float elbowyaw,
                                  float wristyaw,
                                  int32_t time = INT_MAX)
            {
                SetPose_Rad(shoulderpitch, shoulderroll,
                            elbowroll, elbowyaw,
                            wristyaw);
                set_movement_time(time);
            }

            /**
             * move to position expressed in degrees over a given time
             * @param shoulderpitch down to up
             * @param shoulderroll  out to in
             * @param elbowroll     straight to bent
             * @param elbowyaw      rolled right to rolled left
             * @param wristyaw      rolled right to rolled left
             * @param time          time in mSec for the motion to take
             */
            void GoToWithTime_Deg(float shoulderpitch,
                                  float shoulderroll,
                                  float elbowroll,
                                  float elbowyaw,
                                  float wristyaw,
                                  int32_t time = INT_MAX)
            {
                SetPose_Deg(shoulderpitch, shoulderroll,
                            elbowroll, elbowyaw,
                            wristyaw);
                set_movement_time(time);
            }
        
            /**
             * Set Pose in radians
             * @param shoulderpitch  down to up
             * @param shoulderroll   out to in
             * @param elbowroll      straight to bent
             * @param elbowyaw       rolled right to rolled left
             * @param wristyaw       rolled right to rolled left
             */
            void SetPose_Rad(float shoulderpitch,
                             float shoulderroll,
                             float elbowroll,
                             float elbowyaw,
                             float wristyaw)
            {
                set_shoulderpitch_RAD(shoulderpitch);
                set_shoulderroll_RAD(shoulderroll);
                set_elbowroll_RAD(elbowroll);
                set_elbowyaw_RAD(elbowyaw);
                set_wristyaw_RAD(wristyaw);
            }
        
            /**
             * Set Pose in degrees
             * @param shoulderpitch down to up
             * @param shoulderroll  out to in
             * @param elbowroll     straight to bent
             * @param elbowyaw      rolled right to rolled left
             * @param wristyaw      rolled right to rolled left
             */
            void SetPose_Deg(float shoulderpitch,
                             float shoulderroll,
                             float elbowroll,
                             float elbowyaw,
                             float wristyaw)
            {
                set_shoulderpitch_DEG(shoulderpitch);
                set_shoulderroll_DEG(shoulderroll);
                set_elbowroll_DEG(elbowroll);
                set_elbowyaw_DEG(elbowyaw);
                set_wristyaw_DEG(wristyaw);
            }

            void MirrorArm(const HAL_ArmTarget &other)
            {
                // Roll angles need to be mirrored, others just copied.
                set_target_shoulderpitch(other.target_shoulderpitch());
                set_target_shoulderroll(-other.target_shoulderroll());
                set_target_elbowroll(-other.target_elbowroll());
                set_target_elbowyaw(other.target_elbowyaw());
                set_target_wristyaw(other.target_wristyaw());
                set_target_shoulderpitchstiffness(other.target_shoulderpitchstiffness());
                set_target_shoulderrollstiffness(other.target_shoulderrollstiffness());
                set_target_elbowrollstiffness(other.target_elbowrollstiffness());
                set_target_elbowyawstiffness(other.target_elbowyawstiffness());
                set_target_wristyawstiffness(other.target_wristyawstiffness());
                set_target_movement_time(other.target_movement_time());
                set_arm_active(other.arm_active());
            }

            void CopyPose(const HAL_ArmTarget &other)
            {
                set_target_shoulderpitch(other.target_shoulderpitch());
                set_target_shoulderroll(-other.target_shoulderroll());
                set_target_elbowroll(-other.target_elbowroll());
                set_target_elbowyaw(other.target_elbowyaw());
                set_target_wristyaw(other.target_wristyaw());
            }

            bool HasSamePose(const HAL_ArmTarget &other)
            {
                if (
                    target_shoulderpitch() == other.target_shoulderpitch()
                    && target_shoulderroll() == other.target_shoulderroll()
                    && target_elbowroll() == other.target_elbowroll()
                    && target_elbowyaw() == other.target_elbowyaw()
                    && target_wristyaw() == other.target_wristyaw()
                    )
                {
                    return  true;
                }
                return false;
            }

            bool HasSameStiffness(const HAL_ArmTarget &other)
            {
                if (
                    target_shoulderpitchstiffness() == other.target_shoulderpitchstiffness()
                    && target_shoulderrollstiffness() == other.target_shoulderrollstiffness()
                    && target_elbowrollstiffness() == other.target_elbowrollstiffness()
                    && target_elbowyawstiffness() == other.target_elbowyawstiffness()
                    && target_wristyawstiffness() == other.target_wristyawstiffness()
                   )
                {
                    return  true;
                }
                return false;
            }

/// CUSTOM SETTERS
/// Movement Setters (Degrees)
            void set_shoulderpitch_DEG(float setting) {
                set_target_shoulderpitch(static_cast<int16_t>(setting * 10.0f));
            }
            
            void set_shoulderroll_DEG(float setting) {
                set_target_shoulderroll(static_cast<int16_t>(setting * 10.0f));
            }
        
            void set_elbowroll_DEG(float setting) {
                set_target_elbowroll(static_cast<int16_t>(setting * 10.0f));
            }
        
            void set_elbowyaw_DEG(float setting) {
                set_target_elbowyaw(static_cast<int16_t>(setting * 10.0f));
            }
            
            void set_wristyaw_DEG(float setting) {
                set_target_wristyaw(static_cast<int16_t>(setting * 10.0f));
            }

/// Movement Setters (Radians)
            void set_shoulderpitch_RAD(float setting) {
                set_target_shoulderpitch(static_cast<int16_t>(setting* (1800.0f / M_PIF)));
            }
            
            void set_shoulderroll_RAD(float setting) {
                set_target_shoulderroll(static_cast<int16_t>(setting * (1800.0f / M_PIF)));
            }
        
            void set_elbowroll_RAD(float setting) {
                set_target_elbowroll(static_cast<int16_t>(setting * (1800.0f / M_PIF)));
            }
        
            void set_elbowyaw_RAD(float setting) {
                set_target_elbowyaw(static_cast<int16_t>(setting * (1800.0f / M_PIF)));
            }
            
            void set_wristyaw_RAD(float setting) {
                set_target_wristyaw(static_cast<int16_t>(setting * (1800.0f / M_PIF)));
            }

/// Stiffness Setters
            void set_shoulderpitchstiffness(float setting) {
                set_target_shoulderpitchstiffness(static_cast<uint8_t>(setting * 100.0f));
            }
            
            void set_shoulderrollstiffness(float setting) {
                set_target_shoulderrollstiffness(static_cast<uint8_t>(setting * 100.0f));
            }
        
            void set_elbowrollstiffness(float setting) {
                set_target_elbowrollstiffness(static_cast<uint8_t>(setting * 100.0f));
            }
        
            void set_elbowyawstiffness(float setting) {
                set_target_elbowyawstiffness(static_cast<uint8_t>(setting * 100.0f));
            }
            
            void set_wristyawstiffness(float setting) {
                set_target_wristyawstiffness(static_cast<uint8_t>(setting * 100.0f));
            }

/// Duration Setter
            void set_movement_time(int32_t time) {
                set_target_movement_time(time);
            }

        
///CUSTOM GETTERS
/// Movement Getters (Degrees)
            float get_shoulderpitch_DEG() {
                return static_cast<float>(target_shoulderpitch() * 0.1f);
            }
            
            float get_shoulderroll_DEG() {
                return static_cast<float>(target_shoulderroll() * 0.1f);
            }
        
            float get_elbowroll_DEG() {
                return static_cast<float>(target_elbowroll() * 0.1f);
            }
        
            float get_elbowyaw_DEG() {
                return static_cast<float>(target_elbowyaw() * 0.1f);
            }
            
            float get_wristyaw_DEG() {
                return static_cast<float>(target_wristyaw() * 0.1f);
            }

/// Movement Getters (Radians)
            float get_shoulderpitch_RAD() {
                return static_cast<float>(target_shoulderpitch()) * M_PIF/ 1800.0f;
            }
            
            float get_shoulderroll_RAD() {
                return static_cast<float>(target_shoulderroll()) * M_PIF/ 1800.0f;
            }
        
            float get_elbowroll_RAD() {
                return static_cast<float>(target_elbowroll()) * M_PIF/ 1800.0f;
            }
        
            float get_elbowyaw_RAD() {
                return static_cast<float>(target_elbowyaw()) * M_PIF/ 1800.0f;
            }
            
            float get_wristyaw_RAD() {
                return static_cast<float>(target_wristyaw()) * M_PIF/ 1800.0f;
            }

/// Stiffness Getters
            float get_shoulderpitchstiffness() {
                return static_cast<float>(target_shoulderpitchstiffness()) * 0.01f;
            }
            
            float get_shoulderrollstiffness() {
                return static_cast<float>(target_shoulderrollstiffness()) * 0.01f;
            }
        
            float get_elbowrollstiffness() {
                return static_cast<float>(target_elbowrollstiffness()) * 0.01f;
            }
        
            float get_elbowyawstiffness() {
                return static_cast<float>(target_elbowyawstiffness()) * 0.01f;
            }
            
            float get_wristyawstiffness() {
                return static_cast<float>(target_wristyawstiffness()) * 0.01f;
            }

/// Duration Getter
             int32_t get_movement_time() {
                 return target_movement_time();
            }

            /**
             *  Description function
             */
            std::string description() const
            {
                std::stringstream ss;
                ss << static_cast<int>(target_shoulderpitch()) << "-|-"
                << static_cast<int>(target_shoulderroll()) << "-|-"
                << static_cast<int>(target_elbowroll()) << "-|-"
                << static_cast<int>(target_elbowyaw()) << "-|-"
                << static_cast<int>(target_wristyaw()) << "-|-"
                << static_cast<int>(target_shoulderpitchstiffness()) << "-|-"
                << static_cast<int>(target_shoulderrollstiffness()) << "-|-"
                << static_cast<int>(target_elbowrollstiffness()) << "-|-"
                << static_cast<int>(target_elbowyawstiffness()) << "-|-"
                << static_cast<int>(target_wristyawstiffness()) << "-|-"
                << static_cast<int>(target_movement_time()) << "-|-"
                << static_cast<int>(arm_active()); // << "-|-"
//                << arm_cmd_mask();
                return ss.str();
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
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //HAL_HeadTarget_DEFINED
