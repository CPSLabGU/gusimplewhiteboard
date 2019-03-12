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
//#include <cmath>
#include <sstream>

//#ifndef M_PIF
//#define M_PIF static_cast<float>(M_PI)
//#endif  // M_PIF

namespace guWhiteboard
{
	/**
 	 * @brief Class for moving a SINGLE robotic arm with up to 6 degrees of freedom using local coords of each joint.
     *        NAO Arm has upto 6 degrees of freedom with the axes being:
     *           'shoulder pitch, shoulder roll, elbow roll, elbow yaw, wrist yaw, gripper position'.
     *           (NOTE: The V3 does not have wrist yaw or gripper capabilites.  Naoqi Interface will automatically ignore
     *            wrist and hand settings if the robot does not have them.)
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
     *     Move (left) arm down such that it is parallel to the body at an angle of 5 deg with elbow straight,
     *     inner-forearm and palm facing body, gripper closed over 1 second
	 *     HAL_ArmTarget().GoToWithTime_Rad(1.5708, 0.0873, -0.0349, -1.5708, -1.5708, 0.0f 10000);
     *     HAL_ArmTarget().GoToWithTime_Deg(90, 5, -2, -90, -90, 0.0 10000);
     *          // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
     *
     *     Move (right) arm down such that it is parallel to the body at an angle of 5 deg with elbow straight,
     *     inner-forearm and palm facing body, gripper fully openned over 1 second
     *     HAL_ArmTarget().GoToWithTime_Rad(1.5708, -0.0873, 0.0349, 1.5708, 1.5708, 1.0, 10000);
     *     HAL_ArmTarget().GoToWithTime_Deg(90, -5, 2, 90, 90, 1.0, 10000);
     *          // Note the NAO elbow cannot actually move to a roll angle of 0 degrees.
     *
     *     HAL_ArmTarget().Active(); 	// Puts the arm into active mode, Naoqi DCM default.
     *     HAL_ArmTarget().Passive();   // Puts the arm into passive mode, allowing the arm to be manupulated by external forces.
	 *
	 * Class values need to be passed to the Whiteboard, using the handler, for them to take effect.
	 *
     *     HAL_ArmTarget_t.set(HAL_ArmTarget());
	 *     HAL_ArmTarget_t.set(HAL_ArmTarget().Passive());
	 *
 	 */
    class HAL_ArmTarget : public wb_hal_armtarget
    {

        public:
            /**
             *  Constructor, defaults to LEFT_ARM
             */
//            HAL_ArmTarget(const uint8_t &target_arm = LEFT_ARM): wb_hal_armtarget(target_arm) {}
        
            /**
             * Constructor using float parameters
             * This constructor should be used because the whiteboard
             * holds integer representations of the angles.
             *
             */
            HAL_ArmTarget(const uint8_t &target_arm = LEFT_ARM,
                         const float shoulderpitch = 0,
                         const float shoulderroll = 0,
                         const float elbowroll = 0,
                         const float elbowyaw = 0,
                         const float wristyaw = 0,
                         const float hand_PCT = 0,
                         const float shoulderpitchstiffness = 0,
                         const float shoulderrollstiffness = 0,
                         const float elbowrollstiffness = 0,
                         const float elbowyawstiffness = 0,
                         const float wristyawstiffness = 0,
                         const float handstiffness = 0,
                         const bool  shoulderpitch_active = true,
                         const bool  shoulderroll_active = true,
                         const bool  elbowroll_active = true,
                         const bool  elbowyaw_active = true,
                         const bool  wrist_active = true,
                         const bool  hand_active = true,
                         const int32_t movement_time = 1000000,
                         const uint8_t pliability = 10,
                         const bool  arm_stop = false,
                         const bool inRadians = false)
            : wb_hal_armtarget(target_arm)
            {
               if (inRadians) {
                   setPose_Rad(shoulderpitch, shoulderroll,
                               elbowroll, elbowyaw,
                               wristyaw, hand_PCT);
               } else {
                   setPose_Deg(shoulderpitch, shoulderroll,
                               elbowroll, elbowyaw,
                               wristyaw, hand_PCT);
               }
               set_target_movement_time(movement_time);
               set_target_arm_stop(arm_stop);
               set_shoulderpitchstiffness(shoulderpitchstiffness);
               set_shoulderrollstiffness(shoulderrollstiffness);
               set_elbowrollstiffness(elbowrollstiffness);
               set_elbowyawstiffness(elbowyawstiffness);
               set_wristyawstiffness(wristyawstiffness);
               set_handstiffness(handstiffness);
               setArmPliability(shoulderpitch_active, shoulderroll_active, elbowroll_active,
                                elbowyaw_active, wrist_active, hand_active);
               set_target_pliability(pliability);
            }

//            HAL_ArmTarget(const uint8_t &target_arm = LEFT_ARM,
//                          const float shoulderpitch_DEG = 0,
//                          const float shoulderroll_DEG = 0,
//                          const float elbowroll_DEG = 0,
//                          const float elbowyaw_DEG = 0,
//                          const float wristyaw_DEG = 0,
//                          const float hand_PCT = 0,
//                          const float shoulderpitchstiffness = 0,
//                          const float target_shoulderrollstiffness = 0,
//                          const float target_elbowrollstiffness = 0,
//                          const float target_elbowyawstiffness = 0,
//                          const float target_wristyawstiffness = 0,
//                          const bool  shoulderpitch_active = true,
//                          const bool  shoulderroll_active = true,
//                          const bool  elbowroll_active = true,
//                          const bool  elbowyaw_active = true,
//                          const bool  wrist_active = true,
//                          const bool  hand_active = true,
//                          const int32_t movement_time = 1000000,
//                          set_target_pliability(pliability);
//            : wb_hal_armtarget(target_arm)
//            {
//               setPose_Deg(shoulderpitch_DEG, shoulderroll_DEG,
//                           elbowroll_DEG, elbowyaw_DEG,
//                           wristyaw_DEG, hand_PCT);
//               set_target_movement_time(movement_time);
//               set_shoulderpitchstiffness(shoulderpitchstiffness);
//               set_shoulderrollstiffness(shoulderrollstiffness);
//               set_elbowrollstiffness(elbowrollstiffness);
//               set_elbowyawstiffness(elbowyawstiffness);
//               set_wristyawstiffness(wristyawstiffness);
//               set_handstiffness(handstiffness);
//               setArmPliability(shoulderpitch_active, shoulderroll_active, elbowroll_active,
//                                elbowyaw_active, wrist_active, hand_active);
//            }

//MARK: Arm - General
            /**
             *  Specify which arm this instance manages.
             *  Up to 256 arms are possible.
             *  Use prefedined macros LEFT_ARM and RIGHT_ARM for clarity.
             *
             *  @param  arm integer used to record which arm the object refers to.
             *
             */
            void tieToArm(uint8_t arm)
            {
                set_target_arm(arm);
            }

//MARK: Arm - Movements

            /**
             * move to position in radians over a given time
             * @param   shoulderpitch  down to up
             * @param   shoulderroll   out to in
             * @param   elbowroll      straight to bent
             * @param   elbowyaw       rolled right to rolled left
             * @param   wristyaw       rolled right to rolled left
             * @param   hand           closed to open
             * @param   time           elapsed time in mSec for the motion to complete.
             *
             */
            void goToWithTime_Rad(float shoulderpitch,
                                  float shoulderroll,
                                  float elbowroll,
                                  float elbowyaw,
                                  float wristyaw,
                                  float hand,
                                  int32_t time = INT_MAX)
            {
                setPose_Rad(shoulderpitch, shoulderroll,
                            elbowroll, elbowyaw,
                            wristyaw, hand);
                set_target_movement_time(time);
            }
            
            /**
             * move to position expressed in degrees over a given time
             * @param   shoulderpitch down to up
             * @param   shoulderroll  out to in
             * @param   elbowroll     straight to bent
             * @param   elbowyaw      rolled right to rolled left
             * @param   wristyaw      rolled right to rolled left
             * @param   hand          closed to open
             * @param   time          elapsed time in mSec for the motion to complete.
             *
             */
            void goToWithTime_Deg(float shoulderpitch,
                                  float shoulderroll,
                                  float elbowroll,
                                  float elbowyaw,
                                  float wristyaw,
                                  float hand,
                                  int32_t time = INT_MAX)
            {
                setPose_Deg(shoulderpitch, shoulderroll,
                            elbowroll, elbowyaw,
                            wristyaw, hand);
                set_target_movement_time(time);
            }
        
            /**
             * Command the arm to stop at its current
             * location and not act on motion commands
             * until ready() is called.
             *
             */
            void stop() {
                set_target_arm_stop(true);
            }

        
            /**
             * Set arm to ready state (Default)
             * The arm will act on motion commands.
             *
             */
            void ready() {
                set_target_arm_stop(false);
            }

        
            /**
             *  Arm at Goal Setter
             *      Clients/Machines should not use this method.
             *
             *  Arm arrived at goal pose.
             *  Only set in the status message by naoqiinterface when the arm has reached the goal pose.
             *
             *  @param  goalReached  the arm has reached the goal (true/false)
             *
             */
            void isAtGoal(bool goalReached)
            {
                set_target_arm_at_goal(goalReached);
            }
            
            /**
             *  Arm at Goal Getter
             *      Clients/Machines should use this getter to test if the DCM
             *      has reported that the arm has reached its goal pose.
             *
             *  Is the arm at the goal pose?
             *  Naoqi Interface sets this true when the arm reaches the goal
             *  pose asked for in the previous control message.
             *
             *  @return     bool    whether the arm is at the goal location or not.
             *
             */
            bool atGoal()
            {
                return target_arm_at_goal();
            }

            /**
             *  Client side test to determine if arm is at the target location, allowing for specified tolerances.
             *  The method tests if the pose 'status' is within 'tolerance' of 'this' target
             *  location, allowing for a specified tolerance.
             *
             *  'this' object contains the target pose settings.
             *
             *  @param  status      HAL_ArmTarget object which contains actual pose settings reported by the robot's sensors.
             *  @param  tolerance   HAL_ArmTarget object whose pose settings specify the tolerance for each joint/gripper
             *  @return bool        whether or not the status is within range of the target location.
             *
             */
            bool atTargetLocation(HAL_ArmTarget status, HAL_ArmTarget tolerance)
            {
                int16_t shoulderpitchMargin = static_cast<int16_t>(abs(target_shoulderpitch() - status.target_shoulderpitch()));
                int16_t shoulderrollMargin = static_cast<int16_t>(abs(target_shoulderroll() - status.target_shoulderroll()));
                int16_t elbowrollMargin = static_cast<int16_t>(abs(target_elbowroll() - status.target_elbowroll()));
                int16_t elbowyawMargin = static_cast<int16_t>(abs(target_elbowyaw() - status.target_elbowyaw()));
                //#ifdef NAO_V3
                //    int16_t wristyawMargin = static_cast<int16_t>(abs(target_wristyaw - status.target_wristyaw()));
                //    uint8_t handMargin = static_cast<uint8_t>(abs(target_hand() - status.target_hand()));
                if (   (shoulderpitchMargin <= tolerance.target_shoulderpitch())
                    && (shoulderrollMargin <= tolerance.target_shoulderroll())
                    && (elbowrollMargin <= tolerance.target_elbowroll())
                    && (elbowyawMargin <= tolerance.target_elbowyaw())
                    //#ifdef NAO_V3
                    //        && (wristyawMargin <= tolerance.target_wristyaw())
                    //        && (handMargin <= tolerance.target_hand())
                    )
                {
                    return true;
                }
                return false;
            }

//MARK: Arm - Pose

            /**
             * Set Pose in radians
             * @param   shoulderpitch  down to up
             * @param   shoulderroll   out to in
             * @param   elbowroll      straight to bent
             * @param   elbowyaw       rolled right to rolled left
             * @param   wristyaw       rolled right to rolled left
             * @param   hand           closed to open.
             *
             */
            void setPose_Rad(float shoulderpitch,
                             float shoulderroll,
                             float elbowroll,
                             float elbowyaw,
                             float wristyaw,
                             float hand)
            {
                set_shoulderpitch_RAD(shoulderpitch);
                set_shoulderroll_RAD(shoulderroll);
                set_elbowroll_RAD(elbowroll);
                set_elbowyaw_RAD(elbowyaw);
                set_wristyaw_RAD(wristyaw);
                set_hand(hand);
            }
            
            /**
             * Set Pose in degrees
             * @param   shoulderpitch down to up
             * @param   shoulderroll  out to in
             * @param   elbowroll     straight to bent
             * @param   elbowyaw      rolled right to rolled left
             * @param   wristyaw      rolled right to rolled left
             * @param   hand          closed to open.
             *
             */
            void setPose_Deg(float shoulderpitch,
                             float shoulderroll,
                             float elbowroll,
                             float elbowyaw,
                             float wristyaw,
                             float hand)
            {
                set_shoulderpitch_DEG(shoulderpitch);
                set_shoulderroll_DEG(shoulderroll);
                set_elbowroll_DEG(elbowroll);
                set_elbowyaw_DEG(elbowyaw);
                set_wristyaw_DEG(wristyaw);
                set_hand(hand);
            }

            
            /**
             *  Convenience function to mirror arm settings about the XZ plane from one HAL_ArmTarget object to another.
             *
             *  @param  other    HAL_ArmTarget object to be mirrored.
             *
             */
            void mirrorArm(const HAL_ArmTarget &other)
            {
                // Roll and Yaw angles need to be mirrored, others just copied.
                set_target_shoulderpitch(other.target_shoulderpitch());
                set_target_shoulderroll(-other.target_shoulderroll());
                set_target_elbowroll(-other.target_elbowroll());
                set_target_elbowyaw(-other.target_elbowyaw());
                set_target_wristyaw(-other.target_wristyaw());
                set_target_hand(other.target_hand());
                set_target_shoulderpitchstiffness(other.target_shoulderpitchstiffness());
                set_target_shoulderrollstiffness(other.target_shoulderrollstiffness());
                set_target_elbowrollstiffness(other.target_elbowrollstiffness());
                set_target_elbowyawstiffness(other.target_elbowyawstiffness());
                set_target_wristyawstiffness(other.target_wristyawstiffness());
                set_target_handstiffness(other.target_handstiffness());
                set_target_shoulderpitch_active(other.target_shoulderpitch_active());
                set_target_shoulderroll_active(other.target_shoulderroll_active());
                set_target_elbowroll_active(other.target_elbowroll_active());
                set_target_elbowyaw_active(other.target_elbowyaw_active());
                set_target_wrist_active(other.target_wrist_active());
                set_target_hand_active(other.target_hand_active());
                set_target_movement_time(other.target_movement_time());
                set_target_pliability(other.target_pliability());
            }
            
            /**
             *  Convenience function to copy pose settings from one HAL_ArmTarget object to another.
             *
             *  @param  other    HAL_ArmTarget object from which to copy pose settings from.
             *
             */
            void copyPose(const HAL_ArmTarget &other)
            {
                set_target_shoulderpitch(other.target_shoulderpitch());
                set_target_shoulderroll(other.target_shoulderroll());
                set_target_elbowroll(other.target_elbowroll());
                set_target_elbowyaw(other.target_elbowyaw());
                set_target_wristyaw(other.target_wristyaw());
                set_target_hand(other.target_hand());
            }
            
            /**
             *  Convenience function to mirror pose settings about the XZ plane from one HAL_ArmTarget object to another.
             *
             *  @param  other    HAL_ArmTarget object whose pose settings are to be mirrored.
             *
             */
            void mirrorPose(const HAL_ArmTarget &other)
            {
                set_target_shoulderpitch(other.target_shoulderpitch());
                set_target_shoulderroll(-other.target_shoulderroll());
                set_target_elbowroll(-other.target_elbowroll());
                set_target_elbowyaw(-other.target_elbowyaw());
                set_target_wristyaw(-other.target_wristyaw());
                set_target_hand(other.target_hand());
            }
            
            /**
             *  Tests if this HAL_ArmTarget object has the same pose settings as the other HAL_ArmTarget object.
             *      NOTE this does not take into account mirroring about the XZ plane.
             *
             *  @param  other   HAL_ArmTarget object whose pose settings are being compared.
             *  @return bool    whether the two objects have the same pose or not.
             *
             */
            bool hasSamePose(const HAL_ArmTarget &other)
            {
                if (
                    target_shoulderpitch() == other.target_shoulderpitch()
                    && target_shoulderroll() == other.target_shoulderroll()
                    && target_elbowroll() == other.target_elbowroll()
                    && target_elbowyaw() == other.target_elbowyaw()
                    && target_wristyaw() == other.target_wristyaw()
                    && target_hand() == other.target_hand()
                    )
                {
                    return  true;
                }
                return false;
            }
            
            /**
             *  Tests if this HAL_ArmTarget object has the same mirrored pose settings as the other HAL_ArmTarget object.
             *      NOTE this method takes into account mirroring about the XZ plane.
             *
             *  @param  other   HAL_ArmTarget object whose pose settings are being compared.
             *  @return bool    whether the two objects have the same pose or not.
             *
             */
            bool hasSameMirroredPose(const HAL_ArmTarget &other)
            {
                if (
                    target_shoulderpitch() == other.target_shoulderpitch()
                    && target_shoulderroll() == -other.target_shoulderroll()
                    && target_elbowroll() == -other.target_elbowroll()
                    && target_elbowyaw() == -other.target_elbowyaw()
                    && target_wristyaw() == -other.target_wristyaw()
                    && target_hand() == other.target_hand()
                    )
                {
                    return  true;
                }
                return false;
            }

//MARK: Arm - Stiffness

            /**
             *  Convenience function to set the stiffness
             *  of all the arm's joints to the maximum (1.0f).
             *
             */
            void setArmStiffnessMax()
            {
                set_shoulderpitchstiffness(1.0f);
                set_shoulderrollstiffness(1.0f);
                set_elbowrollstiffness(1.0f);
                set_elbowyawstiffness(1.0f);
                set_wristyawstiffness(1.0f);
                set_handstiffness(1.0f);
            }

            /**
             *  Convenience function to set the stiffness
             *  of all the arm's joints to what Aldebaran
             *  considers 'normal' (0.6f).
             *
             */
            void setArmStiffnessNormal()
            {
                set_shoulderpitchstiffness(0.6f);
                set_shoulderrollstiffness(0.6f);
                set_elbowrollstiffness(0.6f);
                set_elbowyawstiffness(0.6f);
                set_wristyawstiffness(0.6f);
                set_handstiffness(0.6f);
            }

            /**
             *  Convenience function to set uniform stiffness
             *  on all arm joints to a custom value.
             *
             *  @param stiffness float Stiffness setting between 0.0 and 1.0 (float).
             *
             */
            void setArmStiffness(float stiffness)
            {
                if ((stiffness <= 1.0f) && (stiffness >=0.0f)) {
                    set_shoulderpitchstiffness(stiffness);
                    set_shoulderrollstiffness(stiffness);
                    set_elbowrollstiffness(stiffness);
                    set_elbowyawstiffness(stiffness);
                    set_wristyawstiffness(stiffness);
                    set_handstiffness(stiffness);
                }
            }

            /**
             *  Convenience function to turn off stiffness
             *  in all the arm's joints (0.0f).
             *
             */
            void setArmStiffnessOff()
            {
                set_shoulderpitchstiffness(0.0f);
                set_shoulderrollstiffness(0.0f);
                set_elbowrollstiffness(0.0f);
                set_elbowyawstiffness(0.0f);
                set_wristyawstiffness(0.0f);
                set_handstiffness(0.0f);
            }

        
            /**
             *  Convenience function to copy stiffness settings from one HAL_ArmTarget object to another.
             *
             *  @param  other    HAL_ArmTarget object from which to copy stiffness settings.
             *
             */
            void copyStiffness(const HAL_ArmTarget &other)
            {
                target_shoulderpitchstiffness() = other.target_shoulderpitchstiffness();
                target_shoulderrollstiffness() = other.target_shoulderrollstiffness();
                target_elbowrollstiffness() = other.target_elbowrollstiffness();
                target_elbowyawstiffness() = other.target_elbowyawstiffness();
                target_wristyawstiffness() = other.target_wristyawstiffness();
                target_handstiffness() = other.target_handstiffness();
            }
        


            /**
             *  Tests if this HAL_ArmTarget object has the same stiffness settings as the other HAL_ArmTarget object.
             *
             *  @param  other   HAL_ArmTarget object whose stiffness settings are being compared.
             *  @return bool    whether the two objects have the same stiffness or not.
             *
             */
            bool hasSameStiffness(const HAL_ArmTarget &other)
            {
                if (
                    target_shoulderpitchstiffness() == other.target_shoulderpitchstiffness()
                    && target_shoulderrollstiffness() == other.target_shoulderrollstiffness()
                    && target_elbowrollstiffness() == other.target_elbowrollstiffness()
                    && target_elbowyawstiffness() == other.target_elbowyawstiffness()
                    && target_wristyawstiffness() == other.target_wristyawstiffness()
                    && target_handstiffness() == other.target_handstiffness()
                   )
                {
                    return  true;
                }
                return false;
            }

//MARK: Arm - Pliability
                
            /**
             *  Set arm to be Active (DEDAULT DCM state)
             *  The arm is active and manual movements will be resisted, be careful when the stiffness is set high.
             *  Once the applied force is removed, the arm will return to its previous location.
             *  Be careful using this with high stiffness settings (which vary per joint), as the gears will be stripped.
             *
             *  NOTE:  This is the default DCM mode.
             *
             */
            void setArmActive()
            {
                set_target_shoulderpitch_active(true);
                set_target_shoulderroll_active(true);
                set_target_elbowroll_active(true);
                set_target_elbowyaw_active(true);
                set_target_wrist_active(true);
                set_target_hand_active(true);
            }

            /**
             *  Set arm to be Passive
             *  Manually moving the arm causes the arm to remain in the new position.
             *  Be careful using this with high stiffness and pliability settings (which vary per joint).
             *
             *  NOTE:  This is achieved by telling the DCM to move the arm to the displaced
             *         position each DCM cyle.  Thus the arm tracks the applied force.
             *         The 'pliability' setting reduces the update rate, thus making the arm stiffer. At
             *         higher pliability settings, the movement will become noticably stepped.
             *
             */
            void setArmPassive()
            {
                set_target_shoulderpitch_active(false);
                set_target_shoulderroll_active(false);
                set_target_elbowroll_active(false);
                set_target_elbowyaw_active(false);
                set_target_wrist_active(false);
                set_target_hand_active(false);
            }
            
            
            /**
             *  Individually set the active/passive state of each joint.
             *  See Arm_Active() and Arm_Passive() methods for an explanation of the Active/Passive effect.
             *
             */
            void setArmPliability(bool shoulderpitch, bool shoulderroll, bool elbowroll,
                                bool elbowyaw, bool wristyaw, bool hand)
            {
                set_target_shoulderpitch_active(shoulderpitch);
                set_target_shoulderroll_active(shoulderroll);
                set_target_elbowroll_active(elbowroll);
                set_target_elbowyaw_active(elbowyaw);
                set_target_wrist_active(wristyaw);
                set_target_hand_active(hand);
            }

            /**
             *  Are any of the arm's joints set to passive
             *
             */
            bool isArmPassive() {
                return !target_shoulderpitch_active() || !target_shoulderroll_active() || !target_elbowroll_active() || !target_elbowyaw_active() || !target_wrist_active() || !target_hand_active();
            }

            /**
             *  Are all of the arm's joints set to passive
             *
             */
            bool isArmAllPassive() {
                return !target_shoulderpitch_active() && !target_shoulderroll_active() && !target_elbowroll_active() && !target_elbowyaw_active() && !target_wrist_active() && !target_hand_active();
            }
        
            /**
             *  Are all of the arm's joints set to active
             *
             */
            bool isArmAllActive() {
                return target_shoulderpitch_active() && target_shoulderroll_active() && target_elbowroll_active() && target_elbowyaw_active() && target_wrist_active() && target_hand_active();
            }
        
//MARK: CUSTOM SETTERS (Converting floats into Integer representations)
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
                set_target_shoulderpitch(static_cast<int16_t>(setting* DEG_OVER_RAD_10));
            }
            
            void set_shoulderroll_RAD(float setting) {
                set_target_shoulderroll(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }
        
            void set_elbowroll_RAD(float setting) {
                set_target_elbowroll(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }
        
            void set_elbowyaw_RAD(float setting) {
                set_target_elbowyaw(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }
            
            void set_wristyaw_RAD(float setting) {
                set_target_wristyaw(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }
        
/// Hand Movement Setter
            void set_hand(float setting) {
                set_target_hand(static_cast<uint8_t>(setting * 100.0f));
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

            void set_handstiffness(float setting) {
                set_target_handstiffness(static_cast<uint8_t>(setting * 100.0f));
            }


///// Duration Setter
//            void set_movement_time(int32_t time) {
//                set_target_movement_time(time);
//            }
        
//MARK: CUSTOM GETTERS (Converting Integer representations back to floats)
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
                return static_cast<float>(target_shoulderpitch()) * RAD_OVER_DEG_10;
            }
            
            float get_shoulderroll_RAD() {
                return static_cast<float>(target_shoulderroll()) * RAD_OVER_DEG_10;
            }
        
            float get_elbowroll_RAD() {
                return static_cast<float>(target_elbowroll()) * RAD_OVER_DEG_10;
            }
        
            float get_elbowyaw_RAD() {
                return static_cast<float>(target_elbowyaw()) * RAD_OVER_DEG_10;
            }
            
            float get_wristyaw_RAD() {
                return static_cast<float>(target_wristyaw()) * RAD_OVER_DEG_10;
            }

/// Hand Movement Getter
            float get_hand() {
                return static_cast<float>(target_hand()) * 0.01f;
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

            float get_handstiffness() {
                return static_cast<float>(target_handstiffness()) * 0.01f;
            }

//MARK: WHITEBOAR POSTER STRING CONVERSION & Description
        
            /**
             *  Description function
             */
            std::string description() const
            {
                std::stringstream ss;
                ss << static_cast<int>(target_shoulderpitch()) << " | "
                << static_cast<int>(target_shoulderroll()) << " | "
                << static_cast<int>(target_elbowroll()) << " | "
                << static_cast<int>(target_elbowyaw()) << " | "
                << static_cast<int>(target_wristyaw()) << " | "
                << static_cast<int>(target_hand()) << " | "
                << static_cast<int>(target_shoulderpitchstiffness()) << " | "
                << static_cast<int>(target_shoulderrollstiffness()) << " | "
                << static_cast<int>(target_elbowrollstiffness()) << " | "
                << static_cast<int>(target_elbowyawstiffness()) << " | "
                << static_cast<int>(target_wristyawstiffness()) << " | "
                << static_cast<int>(target_handstiffness()) << " | "
                << static_cast<int>(target_shoulderpitch_active()) << " | "
                << static_cast<int>(target_shoulderroll_active()) << " | "
                << static_cast<int>(target_elbowroll_active()) << " | "
                << static_cast<int>(target_elbowyaw_active()) << " | "
                << static_cast<int>(target_wrist_active()) << " | "
                << static_cast<int>(target_hand_active()) << " | "
                << static_cast<int>(target_movement_time()) << " | "
                << static_cast<int>(target_pliability()) << " | "
                << static_cast<int>(target_arm_at_goal()) << " | "
                << static_cast<int>(target_arm_stop());
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
