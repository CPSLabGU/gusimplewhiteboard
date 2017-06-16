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
 * Care must be taken to ensure the forearm does not collide with the
 * chest, thigh, or the other forearm.
 *
 */

struct wb_hal_armtarget
{
    /** target arm number */
    PROPERTY(uint8_t, target_arm)

    /** target shoulder pitch angle in 10ths of degrees */
    PROPERTY(int16_t, target_shoulderpitch)

    /** target shoulder roll angle in radians */
    PROPERTY(int16_t, target_shoulderroll)

    /** target elbow roll angle in radians */
    PROPERTY(int16_t, target_elbowroll)

    /** target elbow yaw angle in radians */
    PROPERTY(int16_t, target_elbowyaw)

    /** target wrist yaw in radians */
    PROPERTY(int16_t, target_wristyaw)

    /** target shoulder pitch stiffness */
    PROPERTY(uint8_t, target_shoulderpitchstiffness)

    /** target shoulder roll stiffness */
    PROPERTY(uint8_t, target_shoulderrollstiffness)

    /** target elbow roll stiffness */
    PROPERTY(uint8_t, target_elbowrollstiffness)

    /** target elbow yaw stiffness */
    PROPERTY(uint8_t, target_elbowyawstiffness)

    /** target wrist yaw stiffness */
    PROPERTY(uint8_t, target_wristyawstiffness)

    /** 
     *  Control Message:
     *      The elapsed time, in mSec, in which the movement should be completed.
     *  Status Message:
     *      Time when the current action will complete. (Thus this is an int32_t.)
     */
    PROPERTY(int32_t, target_movement_time)

    /**
     *  Is the arm active (true) or off (false)
     */
    BIT_PROPERTY(arm_active)

    /**
     *  Control Message:
     *      Not used
     *  Status Message:
     *      Goal location of all joints reached (within specified tolerance).
     */
    BIT_PROPERTY(arm_at_goal)
    

#ifdef __cplusplus
    /**
    * constructor for the stuct of HAL_ArmTarget. this is the data that is placed on the Whiteboard
    * @param target_shoulderpitch           desired shoulder pitch
    * @param target_shoulderroll            desired shoulder roll
    * @param target_elbowroll               desired elbow roll
    * @param target_elbowyaw                desired elbow yaw
    * @param target_wristyaw                desired wrist yaw
    * @param target_shoulderpitchstiffness  desired stiffness in the shoulder pitch axis
    * @param target_shoulderrollstiffness   desired stiffness in the shoulder roll axis
    * @param target_elbowrollstiffness      desired stiffness in the elbow roll axis
    * @param target_elbowyawstiffness       desired stiffness in the elbow yaw axis
    * @param target_wristyawstiffness       desired stiffness in the wrist yaw axis
    * @param target_movement_time           time, expressed mSec to complete the movement
    *                                          (Naoqi's way of setting the speed)
    * @param arm_active                     is the arm active (true) or switched off (false)
    */
    wb_hal_armtarget(uint8_t target_arm = LEFT_ARM,
                      int16_t target_shoulderpitch = 0,
                      int16_t target_shoulderroll = 0,
                      int16_t target_elbowroll = 0,
                      int16_t target_elbowyaw = 0,
                      int16_t target_wristyaw = 0,
                     uint8_t target_shoulderpitchstiffness = 0,
                     uint8_t target_shoulderrollstiffness = 0,
                     uint8_t target_elbowrollstiffness = 0,
                     uint8_t target_elbowyawstiffness = 0,
                     uint8_t target_wristyawstiffness = 0,
                     int32_t target_movement_time = INT_MAX,
                     bool arm_active = true,
                     bool arm_at_goal = false)
    {

        set_target_arm(target_arm);
        set_target_shoulderpitch(target_shoulderpitch);
        set_target_shoulderroll(target_shoulderroll);
        set_target_elbowroll(target_elbowroll);
        set_target_elbowyaw(target_elbowyaw);
        set_target_wristyaw(target_wristyaw);
        set_target_shoulderpitchstiffness(target_shoulderpitchstiffness);
        set_target_shoulderrollstiffness(target_shoulderrollstiffness);
        set_target_elbowrollstiffness(target_elbowrollstiffness);
        set_target_elbowyawstiffness(target_elbowyawstiffness);
        set_target_wristyawstiffness(target_wristyawstiffness);
        set_target_movement_time(target_movement_time);
        set_arm_active(arm_active);
        set_arm_at_goal(arm_at_goal);
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
        set_target_shoulderpitchstiffness(other.target_shoulderpitchstiffness());
        set_target_shoulderrollstiffness(other.target_shoulderrollstiffness());
        set_target_elbowrollstiffness(other.target_elbowrollstiffness());
        set_target_elbowyawstiffness(other.target_elbowyawstiffness());
        set_target_wristyawstiffness(other.target_wristyawstiffness());
        set_target_movement_time(other.target_movement_time());
        set_arm_active(other.arm_active());
        set_arm_at_goal(other.arm_at_goal());
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
        set_target_shoulderpitchstiffness(other.target_shoulderpitchstiffness());
        set_target_shoulderrollstiffness(other.target_shoulderrollstiffness());
        set_target_elbowrollstiffness(other.target_elbowrollstiffness());
        set_target_elbowyawstiffness(other.target_elbowyawstiffness());
        set_target_wristyawstiffness(other.target_wristyawstiffness());
        set_target_movement_time(other.target_movement_time());
        set_arm_active(other.arm_active());
        set_arm_at_goal(other.arm_at_goal());
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
            && target_shoulderpitchstiffness() == rhs.target_shoulderpitchstiffness()
            && target_shoulderrollstiffness() == rhs.target_shoulderrollstiffness()
            && target_elbowrollstiffness() == rhs.target_elbowrollstiffness()
            && target_elbowyawstiffness() == rhs.target_elbowyawstiffness()
            && target_wristyawstiffness() == rhs.target_wristyawstiffness()
            && target_movement_time() == rhs.target_movement_time()
            && arm_active() == rhs.arm_active()
            && arm_at_goal() == rhs.arm_at_goal()
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
