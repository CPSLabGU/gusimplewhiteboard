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
 *  flex_t is used to circumvent direct comparisons of floats.
 *  Its is specifically used to decide if two message are the same,
 *  or a message hasn't changed from a previous check.
 *
 *  It is not used to compare two separately computed float values.
 *
 */
 union flex_t {
    float   decimal;
    uint32_t integer;
};

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

    /** target shoulder pitch angle in radians */
    PROPERTY(float, target_shoulderpitch)

    /** target shoulder roll angle in radians */
    PROPERTY(float, target_shoulderroll)

    /** target elbow roll angle in radians */
    PROPERTY(float, target_elbowroll)

    /** target elbow yaw angle in radians */
    PROPERTY(float, target_elbowyaw)

    /** target wrist yaw in radians */
    PROPERTY(float, target_wristyaw)

    /** target shoulder pitch stiffness */
    PROPERTY(float, target_shoulderpitchstiffness)

    /** target shoulder roll stiffness */
    PROPERTY(float, target_shoulderrollstiffness)

    /** target elbow roll stiffness */
    PROPERTY(float, target_elbowrollstiffness)

    /** target elbow yaw stiffness */
    PROPERTY(float, target_elbowyawstiffness)

    /** target wrist yaw stiffness */
    PROPERTY(float, target_wristyawstiffness)

    /** The elapsed time in which the movement should be completed.
     *  Stored in micro seconds.
     */
    PROPERTY(int, target_movement_time)

    /** Should the current motion be stopped (if setting)
     *    or
     *  has the arm stopped (if a status message)
     */
    BIT_PROPERTY(arm_active)

    /** Should the command be processed again by the motion module?
     *  When changes are made, this bit is set to true.
     *  Motion sets this back to false when the command has been processed. */
    BIT_PROPERTY(arm_cmd_mask)


#ifdef __cplusplus
    /**
    * constructor for the stuct of HAL_ArmTarget. this is the data that is placed on the Whiteboard
    * @param target_shoulderpitch desired shoulder pitch
    * @param target_shoulderroll  desired shoulder roll
    * @param target_elbowroll     desired elbow roll
    * @param target_elbowyaw      desired elbow yaw
    * @param target_wristyaw      desired wrist yaw
    * @param target_movement_time time to take
    * @param arm_active           is the arm active
    */
    wb_hal_armtarget(uint8_t target_arm = LEFT_ARM,
                     float target_shoulderpitch = 0,
                     float target_shoulderroll = 0,
                     float target_elbowroll = 0,
                     float target_elbowyaw = 0,
                     float target_wristyaw = 0,
                     float target_shoulderpitchstiffness = 0,
                     float target_shoulderrollstiffness = 0,
                     float target_elbowrollstiffness = 0,
                     float target_elbowyawstiffness = 0,
                     float target_wristyawstiffness = 0,
                     int target_movement_time = 1000000,
                     bool arm_active = false)
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
        set_arm_cmd_mask(false);
    }

    bool operator == (const wb_hal_armtarget &rhs) {

        union flex_t lhsShouldPitch, lhsShoulderRoll, lhsElbowRoll,lhsElbowYaw;
        union flex_t lhsWristYaw, lhsShoulderPitchStiffness, lhsShoulderRollStiffness;
        union flex_t lhsElbowRollStiffness, lhsElbowYawStiffness, lhsWristYawStiffness;

        union flex_t rhsShouldPitch, rhsShoulderRoll, rhsElbowRoll, rhsElbowYaw;
        union flex_t rhsWristYaw,
        rhsShoulderPitchStiffness, rhsShoulderRollStiffness;
        union flex_t rhsElbowRollStiffness, rhsElbowYawStiffness, rhsWristYawStiffness;


        lhsShouldPitch.decimal = target_shoulderpitch();
        lhsShoulderRoll.decimal = target_shoulderroll();
        lhsElbowRoll.decimal = target_elbowroll();
        lhsElbowYaw.decimal = target_elbowyaw();
        lhsWristYaw.decimal = target_wristyaw();
        lhsShoulderPitchStiffness.decimal = target_shoulderpitchstiffness();
        lhsShoulderRollStiffness.decimal = target_shoulderrollstiffness();
        lhsElbowRollStiffness.decimal = target_elbowrollstiffness();
        lhsElbowYawStiffness.decimal = target_elbowyawstiffness();
        lhsWristYawStiffness.decimal = target_wristyawstiffness();

        rhsShouldPitch.decimal = rhs.target_shoulderpitch();
        rhsShoulderRoll.decimal = rhs.target_shoulderroll();
        rhsElbowRoll.decimal = rhs.target_elbowroll();
        rhsElbowYaw.decimal = rhs.target_elbowyaw();
        rhsWristYaw.decimal = rhs.target_wristyaw();
        rhsShoulderPitchStiffness.decimal = rhs.target_shoulderpitchstiffness();
        rhsShoulderRollStiffness.decimal = rhs.target_shoulderrollstiffness();
        rhsElbowRollStiffness.decimal = rhs.target_elbowrollstiffness();
        rhsElbowYawStiffness.decimal = rhs.target_elbowyawstiffness();
        rhsWristYawStiffness.decimal = rhs.target_wristyawstiffness();

        if (
            target_arm() == rhs.target_arm() &&
            lhsShouldPitch.integer == rhsShouldPitch.integer &&
            lhsShoulderRoll.integer == rhsShoulderRoll.integer &&
            lhsElbowRoll.integer == rhsElbowRoll.integer &&
            lhsElbowYaw.integer == rhsElbowYaw.integer &&
            lhsWristYaw.integer == rhsWristYaw.integer &&
            lhsShoulderPitchStiffness.integer == rhsShoulderPitchStiffness.integer &&
            lhsShoulderRollStiffness.integer == rhsShoulderRollStiffness.integer &&
            lhsElbowRollStiffness.integer == rhsElbowRollStiffness.integer &&
            lhsElbowYawStiffness.integer == rhsElbowYawStiffness.integer &&
            lhsWristYawStiffness.integer == rhsWristYawStiffness.integer &&
            target_movement_time() == rhs.target_movement_time() &&
            arm_active() == rhs.arm_active() &&
            arm_cmd_mask() == rhs.arm_cmd_mask()
            )
        {
            return true;
        } else {
            set_arm_cmd_mask(rhs.arm_cmd_mask());
            return false;
        }
    }

#endif
};

#endif //wb_hal_armtarget_h
