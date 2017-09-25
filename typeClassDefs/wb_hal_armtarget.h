/**
 *  /file wb_hal_armtarget.h
 *
 *  Created by Dimitri Joukoff 2016.
 *  Copyright (c) 2016 Dimitri Joukoff
 *  All rights reserved.
 */

#ifndef wb_hal_armtarget_h
#define wb_hal_armtarget_h

#include <gu_util.h>
#include <stdint.h>

#define LEFT_ARM 0
#define RIGHT_ARM 1

/** Issued Commands that exceed the movement limits given below
 *  are treated as NO-OP.  I.e. the pose of the joint is not altered
 *  by the command.
 */

/** Limits expressed in degrees */
#define SHOULDER_PITCH_LIMIT_DOWN_DEG 119.5f
#define SHOULDER_PITCH_LIMIT_UP_DEG -SHOULDER_PITCH_LIMIT_DOWN_DEG

#define LEFT_SHOULDER_ROLL_OUT_DEG 76.0f
#define LEFT_SHOULDER_ROLL_IN_DEG -18.0f
#define RIGHT_SHOULDER_ROLL_OUT_DEG -LEFT_SHOULDER_ROLL_OUT_DEG
#define RIGHT_SHOULDER_ROLL_IN_DEG -LEFT_SHOULDER_ROLL_IN_DEG

#define LEFT_ELBOW_ROLL_STRAIGHT_DEG -2.0f
#define LEFT_ELBOW_ROLL_BENT_DEG -88.5f
#define RIGHT_ELBOW_ROLL_STRAIGHT_DEG -LEFT_ELBOW_ROLL_STRAIGHT_DEG
#define RIGHT_ELBOW_ROLL_BENT_DEG -LEFT_ELBOW_ROLL_BENT_DEG

#define LEFT_ELBOW_YAW_RIGHT_DEG 119.5f
#define LEFT_ELBOW_YAW_LEFT_DEG -LEFT_ELBOW_YAW_RIGHT_DEG
#define RIGHT_ELBOW_YAW_RIGHT_DEG LEFT_ELBOW_YAW_RIGHT_DEG
#define RIGHT_ELBOW_YAW_LEFT_DEG -LEFT_ELBOW_YAW_RIGHT_DEG

#define LEFT_WRIST_YAW_RIGHT_DEG 104.5f
#define LEFT_WRIST_YAW_LEFT_DEG -LEFT_WRIST_YAW_RIGHT_DEG
#define RIGHT_WRIST_YAW_RIGHT_DEG LEFT_WRIST_YAW_RIGHT_DEG
#define RIGHT_WRIST_YAW_LEFT_DEG -LEFT_WRIST_YAW_RIGHT_DEG

/** Limits expressed in radians */
#define SHOULDER_PITCH_LIMIT_DOWN_RAD 2.0857f
#define SHOULDER_PITCH_LIMIT_UP_RAD -SHOULDER_PITCH_LIMIT_DOWN_RAD

#define LEFT_SHOULDER_ROLL_OUT_RAD 1.3265f
#define LEFT_SHOULDER_ROLL_IN_RAD -0.3142f
#define RIGHT_SHOULDER_ROLL_OUT_RAD -LEFT_SHOULDER_ROLL_OUT_RAD
#define RIGHT_SHOULDER_ROLL_IN_RAD -LEFT_SHOULDER_ROLL_IN_RAD

#define LEFT_ELBOW_ROLL_STRAIGHT_RAD -0.0349f
#define LEFT_ELBOW_ROLL_BENT_RAD -1.5446f
#define RIGHT_ELBOW_ROLL_STRAIGHT_RAD -LEFT_ELBOW_ROLL_STRAIGHT_RAD
#define RIGHT_ELBOW_ROLL_BENT_RAD -LEFT_ELBOW_ROLL_BENT_RAD

#define LEFT_ELBOW_YAW_RIGHT_RAD 2.0857f
#define LEFT_ELBOW_YAW_LEFT_RAD -LEFT_ELBOW_YAW_RIGHT_RAD
#define RIGHT_ELBOW_YAW_RIGHT_RAD LEFT_ELBOW_YAW_RIGHT_RAD
#define RIGHT_ELBOW_YAW_LEFT_RAD -LEFT_ELBOW_YAW_RIGHT_RAD

#define LEFT_WRIST_YAW_RIGHT_RAD 1.8238f
#define LEFT_WRIST_YAW_LEFT_RAD -LEFT_WRIST_YAW_RIGHT_RAD
#define RIGHT_WRIST_YAW_RIGHT_RAD LEFT_WRIST_YAW_RIGHT_RAD
#define RIGHT_WRIST_YAW_LEFT_RAD -LEFT_WRIST_YAW_RIGHT_RAD

/**
 * HAL_ArmTarget c struct
 *
 * The struct is designed around a single arm,
 * allowing independent control of the NAO's arms.
 *
 * **** IMPORTANT NOTE: ****
 * This class only provides for movement limit detection.
 * There is no built in collision detection.
 * Care must be taken to ensure the fingers and forearm do not collide with the
 * chest, thigh, or the other forearm.
 *
 */

struct wb_hal_armtarget
{
    /** target arm number
     *  This property is used strictly for accounting purposes when
     *  the struct is stored within an array and the robot has numerous
     *  arms.
     */
    PROPERTY(uint8_t, target_arm)

    /** target shoulder pitch angle in 10ths of degrees */
    PROPERTY(int16_t, target_shoulderpitch)

    /** target shoulder roll angle angle in 10ths of degrees */
    PROPERTY(int16_t, target_shoulderroll)

    /** target elbow roll angle in 10ths of degrees */
    PROPERTY(int16_t, target_elbowroll)

    /** target elbow yaw angle in 10ths of degrees */
    PROPERTY(int16_t, target_elbowyaw)

    /** target wrist yaw angle in 10ths of degrees */
    PROPERTY(int16_t, target_wristyaw)

    /** target hand grasper opening as a percentage
     *  0   gripper will be clasped shut
     *  100 gripper will be fully openned
     */
    PROPERTY(uint8_t, target_hand)

    /** target shoulder pitch stiffness as a percentage */
    PROPERTY(uint8_t, target_shoulderpitchstiffness)

    /** target shoulder roll stiffness as a percentage */
    PROPERTY(uint8_t, target_shoulderrollstiffness)

    /** target elbow roll stiffness as a percentage */
    PROPERTY(uint8_t, target_elbowrollstiffness)

    /** target elbow yaw stiffness as a percentage */
    PROPERTY(uint8_t, target_elbowyawstiffness)

    /** target wrist yaw stiffness as a percentage */
    PROPERTY(uint8_t, target_wristyawstiffness)

    /** target hand grasper stiffness as a percentage */
    PROPERTY(uint8_t, target_handstiffness)

    /**
     *  Is the shoulderpitch Active (true[DEFAULT]) or Passive (false)
     *  Active :  The robot's DCM will prevent movement of the arm from
     *            the requested pose in accordance to the joint stiffness.
     *            (This is the normal behaviour of the robot.)
     *  Passive:  Once the requested pose is achieved, the DCM will automatically
     *            update the requested pose according to deviations in the joints.
     *            The effect of this is that the robot's arm will be susceptible
     *            to gravity (and will fall slowly over time) as well as to
     *            externally applied forces (allowing it to be manipulated).
     *
     */
    BIT_PROPERTY(target_shoulderpitch_active)

    /**
     *  Is the shoulderroll Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_shoulderroll_active)

    /**
     *  Is the elbowroll Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_elbowroll_active)

    /**
     *  Is the elbowyaw Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_elbowyaw_active)

    /**
     *  Is the wrist Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_wrist_active)
    
    /**
     *  Is the hand Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_hand_active)

    /**
     *  Control Message:
     *      The elapsed time, in mSec, in which the movement should be completed.
     *  Status Message:
     *      Absolute time when the current action will complete. (Thus this is an int32_t.)
     */
    PROPERTY(int32_t, target_movement_time)

    /** target arm's pliability when in Passive Mode
     *  When the arm is passive, this value reduces the update frequency, 
     *  thus making the arm more resistant to external forces.
     *  Use of values from 0 to 10 is recommended.
     *  When set to zero (0), the Arm, when fully extended out, will fall under its own weight.
     *  Higher values stiffen the arm and reduce responsiveness, the movement will become stepped.
     */
    PROPERTY(uint8_t, target_pliability)
    
    /**
     *  Control Message:
     *      Not used
     *  Status Message:
     *      Naoqiinterface reports that the goal location of all joints
     *      has been reached (within specified tolerance).
     */
    BIT_PROPERTY(target_arm_at_goal)
    
    /**
     *  Control Message:
     *      Stop the arm at its current location
     *  Status Message:
     *      Indicates if the last control message issued a STOP command.
     */
    BIT_PROPERTY(target_arm_stop)
    
    

#ifdef __cplusplus
    /**
    * constructor for the HAL_ArmTarget stuct. This is the data that is placed on the Whiteboard
    * @param arm                     uint8_t enumeration of the arm 
    * @param shoulderpitch           desired shoulder pitch
    * @param shoulderroll            desired shoulder roll
    * @param elbowroll               desired elbow roll
    * @param elbowyaw                desired elbow yaw
    * @param wristyaw                desired wrist yaw
    * @param hand                    desired percentage of grasper being openned
    * @param shoulderpitchstiffness  desired stiffness in the shoulder pitch axis
    * @param shoulderrollstiffness   desired stiffness in the shoulder roll axis
    * @param elbowrollstiffness      desired stiffness in the elbow roll axis
    * @param elbowyawstiffness       desired stiffness in the elbow yaw axis
    * @param wristyawstiffness       desired stiffness in the wrist yaw axis
    * @param handstiffness           desired stiffness of the grasper
    * @param shoulderpitch_active    is shoulder pitch active
    * @param shoulderroll_active     is shoulder roll active
    * @param elbowroll_active        is elbow roll active
    * @param elbowyaw_active         is elbow yaw active
    * @param wrist_active            is wrist yaw active
    * @param hand_active             is the hand active
    * @param movement_time           time, expressed mSec to complete the movement
    *                                   (Naoqi's way of setting the speed)
    * @param pliability              when the arm is passive, this value reduces the update frequency
    * @param arm_at_goal             are the arm's joints at the goal location (within tolerance)
    *                                   ***DOES NOT CONSIDER THE Grasper***
    * @param arm_stop                if true :  Naoqi Interface will stop the arm at its current pose,
    *                                           New motion commands will have no effect while arm is stopped.
    *                                   false:  Arm moves to requested pose.
    *
    */
    wb_hal_armtarget(uint8_t arm = LEFT_ARM,
                     int16_t shoulderpitch = 0,
                     int16_t shoulderroll = 0,
                     int16_t elbowroll = 0,
                     int16_t elbowyaw = 0,
                     int16_t wristyaw = 0,
                     uint8_t hand = 0,
                     uint8_t shoulderpitchstiffness = 0,
                     uint8_t shoulderrollstiffness = 0,
                     uint8_t elbowrollstiffness = 0,
                     uint8_t elbowyawstiffness = 0,
                     uint8_t wristyawstiffness = 0,
                     uint8_t handstiffness = 0,
                     bool shoulderpitch_active = true,
                     bool shoulderroll_active = true,
                     bool elbowroll_active = true,
                     bool elbowyaw_active = true,
                     bool wrist_active = true,
                     bool hand_active = true,
                     int32_t movement_time = INT_MAX, // Ensures sudden movements do not take place
                     uint8_t pliability = 0,
                     bool arm_at_goal = false,
                     bool arm_stop = false)
    {
        set_target_arm(arm);
        set_target_shoulderpitch(shoulderpitch);
        set_target_shoulderroll(shoulderroll);
        set_target_elbowroll(elbowroll);
        set_target_elbowyaw(elbowyaw);
        set_target_wristyaw(wristyaw);
        set_target_hand(hand);
        set_target_shoulderpitchstiffness(shoulderpitchstiffness);
        set_target_shoulderrollstiffness(shoulderrollstiffness);
        set_target_elbowrollstiffness(elbowrollstiffness);
        set_target_elbowyawstiffness(elbowyawstiffness);
        set_target_wristyawstiffness(wristyawstiffness);
        set_target_handstiffness(handstiffness);
        set_target_shoulderpitch_active(shoulderpitch_active);
        set_target_shoulderroll_active(shoulderroll_active);
        set_target_elbowroll_active(elbowroll_active);
        set_target_elbowyaw_active(elbowyaw_active);
        set_target_wrist_active(wrist_active);
        set_target_hand_active(hand_active);
        set_target_movement_time(movement_time);
        set_target_pliability(pliability);
        set_target_arm_at_goal(arm_at_goal);
        set_target_arm_stop(arm_stop);
    }

    /** Copy Constructor */
    wb_hal_armtarget(const wb_hal_armtarget &other)
    {
        set_target_arm(other.target_arm());
        set_target_shoulderpitch(other.target_shoulderpitch());
        set_target_shoulderroll(other.target_shoulderroll());
        set_target_elbowroll(other.target_elbowroll());
        set_target_elbowyaw(other.target_elbowyaw());
        set_target_wristyaw(other.target_wristyaw());
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
        set_target_arm_at_goal(other.target_arm_at_goal());
        set_target_arm_stop(other.target_arm_stop());
    }
    
    /** Copy Assignment Operator */
    wb_hal_armtarget &operator = (const wb_hal_armtarget &other)
    {
        set_target_arm(other.target_arm());
        set_target_shoulderpitch(other.target_shoulderpitch());
        set_target_shoulderroll(other.target_shoulderroll());
        set_target_elbowroll(other.target_elbowroll());
        set_target_elbowyaw(other.target_elbowyaw());
        set_target_wristyaw(other.target_wristyaw());
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
        set_target_arm_at_goal(other.target_arm_at_goal());
        set_target_arm_stop(other.target_arm_stop());
        return *this;
    }

    /**
      * Perform a BINARY comparision between two wb_hal_armtarget messages.
      *
     */
    inline bool operator == (const wb_hal_armtarget &rhs)
    {
        if (
            target_arm() == rhs.target_arm()
            && target_shoulderpitch() == rhs.target_shoulderpitch()
            && target_shoulderroll() == rhs.target_shoulderroll()
            && target_elbowroll() == rhs.target_elbowroll()
            && target_elbowyaw() == rhs.target_elbowyaw()
            && target_wristyaw() == rhs.target_wristyaw()
            && target_hand() == rhs.target_hand()
            && target_shoulderpitchstiffness() == rhs.target_shoulderpitchstiffness()
            && target_shoulderrollstiffness() == rhs.target_shoulderrollstiffness()
            && target_elbowrollstiffness() == rhs.target_elbowrollstiffness()
            && target_elbowyawstiffness() == rhs.target_elbowyawstiffness()
            && target_wristyawstiffness() == rhs.target_wristyawstiffness()
            && target_handstiffness() == rhs.target_handstiffness()
            && target_shoulderpitch_active() == rhs.target_shoulderpitch_active()
            && target_shoulderroll_active() == rhs.target_shoulderroll_active()
            && target_elbowroll_active() == rhs.target_elbowroll_active()
            && target_elbowyaw_active() == rhs.target_elbowyaw_active()
            && target_wrist_active() == rhs.target_wrist_active()
            && target_hand_active() == rhs.target_hand_active()
            && target_movement_time() == rhs.target_movement_time()
            && target_pliability() == rhs.target_pliability()
            && target_arm_at_goal() == rhs.target_arm_at_goal()
            && target_arm_stop() == rhs.target_arm_stop()
           )
        {
            return true;
        } else {
            return false;
        }
    }
    
    /** inverse comparison operator */
    inline bool operator != (const wb_hal_armtarget &rhs)
    {
        return !((*this) == rhs);
    }


#endif // __cplusplus
};



#endif //wb_hal_armtarget_h
