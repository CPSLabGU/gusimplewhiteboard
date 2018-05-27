/**
 *  /file HAL_LegTarget.h
 *
 *  Created by Dimitri Joukoff 2016.
 *  Copyright (c) 2016 Dimitri Joukoff
 *  All rights reserved.
 */



#ifndef HAL_LegTarget_DEFINED
#define HAL_LegTarget_DEFINED

#include "wb_hal_legtarget.h"
//#include <cmath>
#include <sstream>

//#ifndef M_PIF
//#define M_PIF static_cast<float>(M_PI)
//#endif  // M_PIF

namespace guWhiteboard
{
	/**
 	 * @brief Class for moving a SINGLE robotic leg with up to 6 degrees of freedom using local coords of each joint.
     *        NAO Leg has upto 6 degrees of freedom with the axes being:
     *           'hipyawpitch, hip roll, hip pitch, knee pitch, ankle pitch, ankle roll'.
     *        The left and right legs are mirrored about the XZ plane as are (most of) the movement limits and ranges.
     *        (Aldebaran Docs ./family/robots/links_robot.html)
	 *
	 * Move the robotic leg to the (local) coord provided in this class.
	 *
	 * Examples
	 * --------
	 *
	 * Examples of what to do with the class
	 *
     *     Move (left) leg such that the thigh is almost parallel to the ground pointing directly in front of the robot,
     *     and the knee is bent right angle with the foot horizontal in the pitch and roll axis, in one second.
     *     myLegTarget = new HAL_LegTarget(LEFT_LEG);
     *     myLegTarget.GoToWithTime_Deg(0, 0, -88, 90, 0, 0, 1000);
	 *     HAL_LegTarget().GoToWithTime_Rad(...) provides a method to control the leg using radian based units.
     *
     *
     *     HAL_LegTarget().setLegActive(); 	 // Puts the leg into active mode, Naoqi DCM default.
     *     HAL_LegTarget().setLegPassive();  // Puts the leg into passive mode, allowing the leg to be manupulated by external forces.
	 *
	 * Class values need to be passed to the Whiteboard, using the handler, for them to take effect.
	 *
     *     HAL_LegTarget_t.set(HAL_LegTarget());
	 *     HAL_LegTarget_t.set(HAL_LegTarget().setLegPassive());
	 *
 	 */
    class HAL_LegTarget : public wb_hal_legtarget
    {

        public:
            /**
             *  Constructor, defaults to LEFT_LEG
             */
//            HAL_LegTarget(const uint8_t &target_leg = LEFT_LEG): wb_hal_legtarget(target_leg) {}
        
            /**
             * Constructor using float parameters
             * This constructor should be used because the whiteboard
             * holds integer representations of the angles.
             *
             */
            HAL_LegTarget(const uint8_t &target_leg = LEFT_LEG,
                         const float hipyawpitch = 0,
                         const float hiproll = 0,
                         const float hippitch = 0,
                         const float kneepitch = 0,
                         const float anklepitch = 0,
                         const float ankleroll = 0,
                         const float hipyawpitchstiffness = 0,
                         const float hiprollstiffness = 0,
                         const float hippitchstiffness = 0,
                         const float kneepitchstiffness = 0,
                         const float anklepitchstiffness = 0,
                         const float anklerollstiffness = 0,
                         const bool  hipyawpitch_active = true,
                         const bool  hiproll_active = true,
                         const bool  hippitch_active = true,
                         const bool  kneepitch_active = true,
                         const bool  anklepitch_active = true,
                         const bool  ankleroll_active = true,
                         const int32_t movement_time = 1000000,
                         const uint8_t pliability = 10,
                         const bool  leg_stop = false,
                         const bool inRadians = false)
            : wb_hal_legtarget(target_leg)
            {
               if (inRadians) {
                   setPose_Rad(hipyawpitch, hiproll,
                               hippitch, kneepitch,
                               anklepitch, ankleroll);
               } else {
                   setPose_Deg(hipyawpitch, hiproll,
                               hippitch, kneepitch,
                               anklepitch, ankleroll);
               }
               set_target_movement_time(movement_time);
               set_target_leg_stop(leg_stop);
               set_hipyawpitchstiffness(hipyawpitchstiffness);
               set_hiprollstiffness(hiprollstiffness);
               set_hippitchstiffness(hippitchstiffness);
               set_kneepitchstiffness(kneepitchstiffness);
               set_anklepitchstiffness(anklepitchstiffness);
               set_anklerollstiffness(anklerollstiffness);
               setLegPliability(hipyawpitch_active, hiproll_active, hippitch_active,
                                kneepitch_active, anklepitch_active, ankleroll_active);
               set_target_pliability(pliability);
            }


//MARK: Leg - General
            /**
             *  Specify which leg this instance manages.
             *  Up to 256 legs are possible.
             *  Use prefedined macros LEFT_LEG and RIGHT_LEG for clarity.
             *
             *  @param  leg integer used to record which leg the object refers to.
             *
             */
            void tieToLeg(uint8_t leg)
            {
                set_target_leg(leg);
            }

//MARK: Leg - Movements

            /**
             * move to position in radians over a given time
             * @param   hipyawpitch    down to up
             * @param   hiproll        out to in
             * @param   hippitch       swing thigh forward/back
             * @param   kneepitch      swig calf out/back
             * @param   anklepitch     raise/lower toes
             * @param   ankleroll      roll ankle out to in
             * @param   time           elapsed time in mSec for the motion to complete.
             *
             */
            void goToWithTime_Rad(float hipyawpitch,
                                  float hiproll,
                                  float hippitch,
                                  float kneepitch,
                                  float anklepitch,
                                  float ankleroll,
                                  int32_t time = INT_MAX)
            {
                setPose_Rad(hipyawpitch, hiproll,
                            hippitch, kneepitch,
                            anklepitch, ankleroll);
                set_target_movement_time(time);
            }
            
            /**
             * move to position in degrees over a given time
             * @param   hipyawpitch    down to up
             * @param   hiproll        out to in
             * @param   hippitch       swing thigh forward/back
             * @param   kneepitch      swig calf out/back
             * @param   anklepitch     raise/lower toes
             * @param   ankleroll      roll ankle out to in
             * @param   time           elapsed time in mSec for the motion to complete.
             *
             */
            void goToWithTime_Deg(float hipyawpitch,
                                  float hiproll,
                                  float hippitch,
                                  float kneepitch,
                                  float anklepitch,
                                  float ankleroll,
                                  int32_t time = INT_MAX)
            {
                setPose_Deg(hipyawpitch, hiproll,
                            hippitch, kneepitch,
                            anklepitch, ankleroll);
                set_target_movement_time(time);
            }
        
            /**
             * Command the leg to stop at its current
             * location and not act on motion commands
             * until ready() is called.
             *
             */
            void stop() {
                set_target_leg_stop(true);
            }

        
            /**
             * Set leg to ready state (Default)
             * The leg will act on motion commands.
             *
             */
            void ready() {
                set_target_leg_stop(false);
            }

        
            /**
             *  Leg at Goal Setter
             *      Clients/Machines should not use this method.
             *
             *  Leg arrived at goal pose.
             *  Only set in the status message by gunaoqiinterface when the leg has reached the goal pose.
             *
             *  @param  goalReached  the leg has reached the goal (true/false)
             *
             */
            void isAtGoal(bool goalReached)
            {
                set_target_leg_at_goal(goalReached);
            }
            
            /**
             *  Leg at Goal Getter
             *      Clients/Machines should use this getter to test if the DCM
             *      has reported that the leg has reached its goal pose.
             *
             *  Is the leg at the goal pose?
             *  gunaoqiinterface sets this true when the leg reaches the goal
             *  pose asked for in the previous control message.
             *
             *  @return     bool    whether the leg is at the goal location or not.
             *
             */
            bool atGoal()
            {
                return target_leg_at_goal();
            }

            /**
             *  Client side test to determine if leg is at the target location, allowing for specified tolerances.
             *  The method tests if the pose 'status' is within 'tolerance' of 'this' target
             *  location, allowing for a specified tolerance.
             *
             *  'this' object contains the target pose settings.
             *
             *  @param  status      HAL_LegTarget object which contains actual pose settings reported by the robot's sensors.
             *  @param  tolerance   HAL_LegTarget object whose pose settings specify the tolerance for each joint
             *  @return bool        whether or not the status is within range of the target location.
             *
             */
            bool atTargetLocation(HAL_LegTarget status, HAL_LegTarget tolerance)
            {
                int16_t hipyawpitchMargin = static_cast<int16_t>(abs(target_hipyawpitch() - status.target_hipyawpitch()));
                int16_t hiprollMargin = static_cast<int16_t>(abs(target_hiproll() - status.target_hiproll()));
                int16_t hippitchMargin = static_cast<int16_t>(abs(target_hippitch() - status.target_hippitch()));
                int16_t kneepitchMargin = static_cast<int16_t>(abs(target_kneepitch() - status.target_kneepitch()));
                int16_t anklepitchMargin = static_cast<int16_t>(abs(target_anklepitch() - status.target_anklepitch()));
                int16_t anklerollMargin = static_cast<int16_t>(abs(target_ankleroll() - status.target_ankleroll()));
                if (   (hipyawpitchMargin <= tolerance.target_hipyawpitch())
                    && (hiprollMargin <= tolerance.target_hiproll())
                    && (hippitchMargin <= tolerance.target_hippitch())
                    && (kneepitchMargin <= tolerance.target_kneepitch())
                    && (anklepitchMargin <= tolerance.target_anklepitch())
                    && (anklerollMargin <= tolerance.target_ankleroll())
                    )
                {
                    return true;
                }
                return false;
            }

//MARK: Leg - Pose

            /**
             * Set Pose in radians
             * @param   hipyawpitch    down to up
             * @param   hiproll        out to in
             * @param   hippitch       swing thigh forward/back
             * @param   kneepitch      swig calf out/back
             * @param   anklepitch     raise/lower toes
             * @param   ankleroll      roll ankle out to in
             *
             */
            void setPose_Rad(float hipyawpitch,
                             float hiproll,
                             float hippitch,
                             float kneepitch,
                             float anklepitch,
                             float ankleroll)
            {
                set_hipyawpitch_RAD(hipyawpitch);
                set_hiproll_RAD(hiproll);
                set_hippitch_RAD(hippitch);
                set_kneepitch_RAD(kneepitch);
                set_anklepitch_RAD(anklepitch);
                set_ankleroll_RAD(ankleroll);
            }
            
            /**
             * Set Pose in degrees
             * @param   hipyawpitch    down to up
             * @param   hiproll        out to in
             * @param   hippitch       swing thigh forward/back
             * @param   kneepitch      swig calf out/back
             * @param   anklepitch     raise/lower toes
             * @param   ankleroll      roll ankle out to in
             *
             */
            void setPose_Deg(float hipyawpitch,
                             float hiproll,
                             float hippitch,
                             float kneepitch,
                             float anklepitch,
                             float ankleroll)
            {
                set_hipyawpitch_DEG(hipyawpitch);
                set_hiproll_DEG(hiproll);
                set_hippitch_DEG(hippitch);
                set_kneepitch_DEG(kneepitch);
                set_anklepitch_DEG(anklepitch);
                set_ankleroll_DEG(ankleroll);
            }

            
            /**
             *  Convenience function to mirror leg settings about the XZ plane from one HAL_LegTarget object to another.
             *
             *  @param  other    HAL_LegTarget object to be mirrored.
             *
             */
            void mirrorLeg(const HAL_LegTarget &other)
            {
                // Roll and Yaw angles need to be mirrored, others just copied.
                set_target_hipyawpitch(other.target_hipyawpitch());
                set_target_hiproll(-other.target_hiproll());
                set_target_hippitch(other.target_hippitch());
                set_target_kneepitch(other.target_kneepitch());
                set_target_anklepitch(other.target_anklepitch());
                set_target_ankleroll(-other.target_ankleroll());
                set_target_hipyawpitchstiffness(other.target_hipyawpitchstiffness());
                set_target_hiprollstiffness(other.target_hiprollstiffness());
                set_target_hippitchstiffness(other.target_hippitchstiffness());
                set_target_kneepitchstiffness(other.target_kneepitchstiffness());
                set_target_anklepitchstiffness(other.target_anklepitchstiffness());
                set_target_anklerollstiffness(other.target_anklerollstiffness());
                set_target_hipyawpitch_active(other.target_hipyawpitch_active());
                set_target_hiproll_active(other.target_hiproll_active());
                set_target_hippitch_active(other.target_hippitch_active());
                set_target_kneepitch_active(other.target_kneepitch_active());
                set_target_anklepitch_active(other.target_anklepitch_active());
                set_target_ankleroll_active(other.target_ankleroll_active());
                set_target_movement_time(other.target_movement_time());
                set_target_pliability(other.target_pliability());
            }
            
            /**
             *  Convenience function to copy pose settings from one HAL_LegTarget object to another.
             *
             *  @param  other    HAL_LegTarget object from which to copy pose settings from.
             *
             */
            void copyPose(const HAL_LegTarget &other)
            {
                set_target_hipyawpitch(other.target_hipyawpitch());
                set_target_hiproll(other.target_hiproll());
                set_target_hippitch(other.target_hippitch());
                set_target_kneepitch(other.target_kneepitch());
                set_target_anklepitch(other.target_anklepitch());
                set_target_ankleroll(other.target_ankleroll());
            }
            
            /**
             *  Convenience function to mirror pose settings about the XZ plane from one HAL_LegTarget object to another.
             *
             *  @param  other    HAL_LegTarget object whose pose settings are to be mirrored.
             *
             */
            void mirrorPose(const HAL_LegTarget &other)
            {
                // Roll and Yaw angles need to be mirrored, others just copied.
                set_target_hipyawpitch(other.target_hipyawpitch());
                set_target_hiproll(-other.target_hiproll());
                set_target_hippitch(other.target_hippitch());
                set_target_kneepitch(other.target_kneepitch());
                set_target_anklepitch(other.target_anklepitch());
                set_target_ankleroll(-other.target_ankleroll());
            }
            
            /**
             *  Tests if this HAL_LegTarget object has the same pose settings as the other HAL_LegTarget object.
             *      NOTE this DOES NOT take into account mirroring about the XZ plane.
             *
             *  @param  other   HAL_LegTarget object whose pose settings are being compared.
             *  @return bool    whether the two objects have the same pose or not.
             *
             */
            bool hasSamePose(const HAL_LegTarget &other)
            {
                if (
                    target_hipyawpitch() == other.target_hipyawpitch()
                    && target_hiproll() == other.target_hiproll()
                    && target_hippitch() == other.target_hippitch()
                    && target_kneepitch() == other.target_kneepitch()
                    && target_anklepitch() == other.target_anklepitch()
                    && target_ankleroll() == other.target_ankleroll()
                    )
                {
                    return  true;
                }
                return false;
            }
            
            /**
             *  Tests if this HAL_LegTarget object has the same mirrored pose settings as the other HAL_LegTarget object.
             *      NOTE this method DOES take into account mirroring about the XZ plane.
             *
             *  @param  other   HAL_LegTarget object whose pose settings are being compared.
             *  @return bool    whether the two objects have the same pose or not.
             *
             */
            bool hasSameMirroredPose(const HAL_LegTarget &other)
            {
                if (
                    target_hipyawpitch() == other.target_hipyawpitch()
                    && target_hiproll() == -other.target_hiproll()
                    && target_hippitch() == other.target_hippitch()
                    && target_kneepitch() == other.target_kneepitch()
                    && target_anklepitch() == other.target_anklepitch()
                    && target_ankleroll() == -other.target_ankleroll()
                    )
                {
                    return  true;
                }
                return false;
            }

//MARK: Leg - Stiffness

            /**
             *  Convenience function to set the stiffness
             *  of all the leg's joints to the maximum (1.0f).
             *
             */
            void setLegStiffnessMax()
            {
                set_hipyawpitchstiffness(1.0f);
                set_hiprollstiffness(1.0f);
                set_hippitchstiffness(1.0f);
                set_kneepitchstiffness(1.0f);
                set_anklepitchstiffness(1.0f);
                set_anklerollstiffness(1.0f);
            }

            /**
             *  Convenience function to set the stiffness
             *  of all the leg's joints to what Aldebaran
             *  considers 'normal' (0.6f).
             *
             */
            void setLegStiffnessNormal()
            {
                set_hipyawpitchstiffness(0.6f);
                set_hiprollstiffness(0.6f);
                set_hippitchstiffness(0.6f);
                set_kneepitchstiffness(0.6f);
                set_anklepitchstiffness(0.6f);
                set_anklerollstiffness(0.6f);
            }

            /**
             *  Convenience function to set uniform stiffness
             *  on all leg joints to a custom value.
             *
             *  @param stiffness float Stiffness setting between 0.0 and 1.0 (float).
             *
             */
            void setLegStiffness(float stiffness)
            {
                if ((stiffness <= 1.0f) && (stiffness >=0.0f)) {
                    set_hipyawpitchstiffness(stiffness);
                    set_hiprollstiffness(stiffness);
                    set_hippitchstiffness(stiffness);
                    set_kneepitchstiffness(stiffness);
                    set_anklepitchstiffness(stiffness);
                    set_anklerollstiffness(stiffness);
                }
            }

            /**
             *  Convenience function to turn off stiffness
             *  in all the leg's joints (0.0f).
             *
             */
            void setLegStiffnessOff()
            {
                set_hipyawpitchstiffness(0.0f);
                set_hiprollstiffness(0.0f);
                set_hippitchstiffness(0.0f);
                set_kneepitchstiffness(0.0f);
                set_anklepitchstiffness(0.0f);
                set_anklerollstiffness(0.0f);
            }

        
            /**
             *  Convenience function to copy stiffness settings from one HAL_LegTarget object to another.
             *
             *  @param  other    HAL_LegTarget object from which to copy stiffness settings.
             *
             */
            void copyStiffness(const HAL_LegTarget &other)
            {
                target_hipyawpitchstiffness() = other.target_hipyawpitchstiffness();
                target_hiprollstiffness() = other.target_hiprollstiffness();
                target_hippitchstiffness() = other.target_hippitchstiffness();
                target_kneepitchstiffness() = other.target_kneepitchstiffness();
                target_anklepitchstiffness() = other.target_anklepitchstiffness();
                target_anklerollstiffness() = other.target_anklerollstiffness();
            }
        


            /**
             *  Tests if this HAL_LegTarget object has the same stiffness settings as the other HAL_LegTarget object.
             *
             *  @param  other   HAL_LegTarget object whose stiffness settings are being compared.
             *  @return bool    whether the two objects have the same stiffness or not.
             *
             */
            bool hasSameStiffness(const HAL_LegTarget &other)
            {
                if (
                    target_hipyawpitchstiffness() == other.target_hipyawpitchstiffness()
                    && target_hiprollstiffness() == other.target_hiprollstiffness()
                    && target_hippitchstiffness() == other.target_hippitchstiffness()
                    && target_kneepitchstiffness() == other.target_kneepitchstiffness()
                    && target_anklepitchstiffness() == other.target_anklepitchstiffness()
                    && target_anklerollstiffness() == other.target_anklerollstiffness()
                   )
                {
                    return  true;
                }
                return false;
            }

//MARK: Leg - Pliability
                
            /**
             *  Set leg to be Active (DEDAULT DCM state)
             *  The leg is active and manual movements will be resisted, be careful when the stiffness is set high.
             *  Once the applied force is removed, the leg will return to its previous location.
             *  Be careful using this with high stiffness settings (which vary per joint), as the gears will be stripped.
             *
             *  NOTE:  This is the default DCM mode.
             *
             */
            void setLegActive()
            {
                set_target_hipyawpitch_active(true);
                set_target_hiproll_active(true);
                set_target_hippitch_active(true);
                set_target_kneepitch_active(true);
                set_target_anklepitch_active(true);
                set_target_ankleroll_active(true);
            }

            /**
             *  Set leg to be Passive
             *  Manually moving the leg causes the leg to stay in the new position.
             *  Be careful using this with high stiffness and pliability settings (which vary per joint).
             *  The robot may/will collapse under its own weight.
             *
             *  NOTE:  This is achieved by telling the DCM to move the leg joints to the displaced
             *         position each DCM cyle.  Thus the leg tracks the applied force.
             *         The 'pliability' setting reduces the update rate, thus making the leg stiffer. At
             *         higher pliability settings, the movement will become noticably stepped.
             *
             */
            void setLegPassive()
            {
                set_target_hipyawpitch_active(false);
                set_target_hiproll_active(false);
                set_target_hippitch_active(false);
                set_target_kneepitch_active(false);
                set_target_anklepitch_active(false);
                set_target_ankleroll_active(false);
            }
            
            
            /**
             *  Individually set the active/passive state of each joint.
             *  See setLegActive() and setLegPassive() methods for an explanation of the Active/Passive effect.
             *
             */
            void setLegPliability(bool hipyawpitch, bool hiproll, bool hippitch,
                                bool kneepitch, bool anklepitch, bool ankleroll)
            {
                set_target_hipyawpitch_active(hipyawpitch);
                set_target_hiproll_active(hiproll);
                set_target_hippitch_active(hippitch);
                set_target_kneepitch_active(kneepitch);
                set_target_anklepitch_active(anklepitch);
                set_target_ankleroll_active(ankleroll);
            }

            /**
             *  Are any of the leg's joints set to passive
             *
             */
            bool isLegPassive() {
                return !target_hipyawpitch_active() || !target_hiproll_active() || !target_hippitch_active() || !target_kneepitch_active() || !target_anklepitch_active() || !target_ankleroll_active();
            }

            /**
             *  Are all of the legs's joints set to passive
             *
             */
            bool isLegAllPassive() {
                return !target_hipyawpitch_active() && !target_hiproll_active() && !target_hippitch_active() && !target_kneepitch_active() && !target_anklepitch_active() && !target_ankleroll_active();
            }
        
            /**
             *  Are all of the leg's joints set to active
             *
             */
            bool isLegAllActive() {
                return target_hipyawpitch_active() && target_hiproll_active() && target_hippitch_active() && target_kneepitch_active() && target_anklepitch_active() && target_ankleroll_active();
            }
        
//MARK: CUSTOM SETTERS (Converting floats into Integer representations)
/// Movement Setters (Degrees)
            void set_hipyawpitch_DEG(float setting) {
                set_target_hipyawpitch(static_cast<int16_t>(setting * 10.0f));
            }
            
            void set_hiproll_DEG(float setting) {
                set_target_hiproll(static_cast<int16_t>(setting * 10.0f));
            }
        
            void set_hippitch_DEG(float setting) {
                set_target_hippitch(static_cast<int16_t>(setting * 10.0f));
            }
        
            void set_kneepitch_DEG(float setting) {
                set_target_kneepitch(static_cast<int16_t>(setting * 10.0f));
            }
            
            void set_anklepitch_DEG(float setting) {
                set_target_anklepitch(static_cast<int16_t>(setting * 10.0f));
            }

            void set_ankleroll_DEG(float setting) {
                set_target_ankleroll(static_cast<int16_t>(setting * 10.0f));
            }


/// Movement Setters (Radians)
            void set_hipyawpitch_RAD(float setting) {
                set_target_hipyawpitch(static_cast<int16_t>(setting* DEG_OVER_RAD_10));
            }
            
            void set_hiproll_RAD(float setting) {
                set_target_hiproll(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }
        
            void set_hippitch_RAD(float setting) {
                set_target_hippitch(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }
        
            void set_kneepitch_RAD(float setting) {
                set_target_kneepitch(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }
            
            void set_anklepitch_RAD(float setting) {
                set_target_anklepitch(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }

            void set_ankleroll_RAD(float setting) {
                set_target_ankleroll(static_cast<int16_t>(setting * DEG_OVER_RAD_10));
            }

/// Stiffness Setters
            void set_hipyawpitchstiffness(float setting) {
                set_target_hipyawpitchstiffness(static_cast<uint8_t>(setting * 100.0f));
            }
            
            void set_hiprollstiffness(float setting) {
                set_target_hiprollstiffness(static_cast<uint8_t>(setting * 100.0f));
            }
        
            void set_hippitchstiffness(float setting) {
                set_target_hippitchstiffness(static_cast<uint8_t>(setting * 100.0f));
            }
        
            void set_kneepitchstiffness(float setting) {
                set_target_kneepitchstiffness(static_cast<uint8_t>(setting * 100.0f));
            }
            
            void set_anklepitchstiffness(float setting) {
                set_target_anklepitchstiffness(static_cast<uint8_t>(setting * 100.0f));
            }

            void set_anklerollstiffness(float setting) {
                set_target_anklerollstiffness(static_cast<uint8_t>(setting * 100.0f));
            }


///// Duration Setter
//            void set_movement_time(int32_t time) {
//                set_target_movement_time(time);
//            }
        
//MARK: CUSTOM GETTERS (Converting Integer representations back to floats)
/// Movement Getters (Degrees)
            float get_hipyawpitch_DEG() {
                return static_cast<float>(target_hipyawpitch() * 0.1f);
            }
            
            float get_hiproll_DEG() {
                return static_cast<float>(target_hiproll() * 0.1f);
            }
        
            float get_hippitch_DEG() {
                return static_cast<float>(target_hippitch() * 0.1f);
            }
        
            float get_kneepitch_DEG() {
                return static_cast<float>(target_kneepitch() * 0.1f);
            }
            
            float get_anklepitch_DEG() {
                return static_cast<float>(target_anklepitch() * 0.1f);
            }

            float get_ankleroll_DEG() {
                return static_cast<float>(target_ankleroll() * 0.1f);
            }


/// Movement Getters (Radians)
            float get_hipyawpitch_RAD() {
                return static_cast<float>(target_hipyawpitch()) * RAD_OVER_DEG_10;
            }
            
            float get_hiproll_RAD() {
                return static_cast<float>(target_hiproll()) * RAD_OVER_DEG_10;
            }
        
            float get_hippitch_RAD() {
                return static_cast<float>(target_hippitch()) * RAD_OVER_DEG_10;
            }
        
            float get_kneepitch_RAD() {
                return static_cast<float>(target_kneepitch()) * RAD_OVER_DEG_10;
            }
            
            float get_anklepitch_RAD() {
                return static_cast<float>(target_anklepitch()) * RAD_OVER_DEG_10;
            }

            float get_ankleroll_RAD() {
                return static_cast<float>(target_ankleroll()) * RAD_OVER_DEG_10;
            }

/// Stiffness Getters
            float get_hipyawpitchstiffness() {
                return static_cast<float>(target_hipyawpitchstiffness()) * 0.01f;
            }
            
            float get_hiprollstiffness() {
                return static_cast<float>(target_hiprollstiffness()) * 0.01f;
            }
        
            float get_hippitchstiffness() {
                return static_cast<float>(target_hippitchstiffness()) * 0.01f;
            }
        
            float get_kneepitchstiffness() {
                return static_cast<float>(target_kneepitchstiffness()) * 0.01f;
            }
            
            float get_anklepitchstiffness() {
                return static_cast<float>(target_anklepitchstiffness()) * 0.01f;
            }

            float get_anklerollstiffness() {
                return static_cast<float>(target_anklerollstiffness()) * 0.01f;
            }

//MARK: WHITEBOAR POSTER STRING CONVERSION & Description
        
            /**
             *  Description function
             */
            std::string description() const
            {
                std::stringstream ss;
                ss << static_cast<int>(target_hipyawpitch()) << "-|-"
                << static_cast<int>(target_hiproll()) << "-|-"
                << static_cast<int>(target_hippitch()) << "-|-"
                << static_cast<int>(target_kneepitch()) << "-|-"
                << static_cast<int>(target_anklepitch()) << "-|-"
                << static_cast<int>(target_ankleroll()) << "-|-"
                << static_cast<int>(target_hipyawpitchstiffness()) << "-|-"
                << static_cast<int>(target_hiprollstiffness()) << "-|-"
                << static_cast<int>(target_hippitchstiffness()) << "-|-"
                << static_cast<int>(target_kneepitchstiffness()) << "-|-"
                << static_cast<int>(target_anklepitchstiffness()) << "-|-"
                << static_cast<int>(target_anklerollstiffness()) << "-|-"
                << static_cast<int>(target_hipyawpitch_active()) << "-|-"
                << static_cast<int>(target_hiproll_active()) << "-|-"
                << static_cast<int>(target_hippitch_active()) << "-|-"
                << static_cast<int>(target_kneepitch_active()) << "-|-"
                << static_cast<int>(target_anklepitch_active()) << "-|-"
                << static_cast<int>(target_ankleroll_active()) << "-|-"
                << static_cast<int>(target_movement_time()) << "-|-"
                << static_cast<int>(target_pliability()) << "-|-"
                << static_cast<int>(target_leg_at_goal()) << "-|-"
                << static_cast<int>(target_leg_stop());
                return ss.str();
            }


#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            /**
             * String constructor (NYI)
             * @param str the string to parse and use to recreate the this object
             */
            HAL_LegTarget(const std::string &str) { from_string(str); }

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

#endif //HAL_LegTarget_DEFINED
