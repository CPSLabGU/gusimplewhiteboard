/**
 *  /file wb_hal_legtarget.h
 *
 *  Created by Dimitri Joukoff 2018.
 *  Copyright (c) 2016 Dimitri Joukoff
 *  All rights reserved.
 */

#ifndef wb_hal_legtarget_h
#define wb_hal_legtarget_h

#include <gu_util.h>
#include <stdint.h>

#define LEFT_LEG 0
#define RIGHT_LEG 1

/** Issued Commands that exceed the movement limits given below
 *  are treated as NO-OP.  I.e. the pose of the joint is not altered
 *  by the command.
 */

/** Limits expressed in degrees (from Aldebaran Docs ./family/nao_h25/joints_h25.html) */
#define HIP_YAWPITCH_LIMIT_BACK_DEG -65.62f
#define HIP_YAWPITCH_LIMIT_FRONT_DEG 42.44f

#define LEFT_HIP_ROLL_OUT_DEG 45.29f
#define LEFT_HIP_ROLL_IN_DEG -21.74f
#define LEFT_HIP_PITCH_FRONT_DEG -88.00f
#define LEFT_HIP_PITCH_BACK_DEG 27.73f
#define LEFT_KNEE_PITCH_FRONT_DEG -5.29f
#define LEFT_KNEE_PITCH_BACK_DEG 121.04f
#define LEFT_ANKLE_PITCH_FRONT_DEG -68.15f
#define LEFT_ANKLE_PITCH_BACK_DEG 52.86f
#define LEFT_ANKLE_ROLL_OUT_DEG 44.06f
#define LEFT_ANKLE_ROLL_IN_DEG -22.79f

#define RIGHT_HIP_ROLL_OUT_DEG -45.29f
#define RIGHT_HIP_ROLL_IN_DEG 21.74f
#define RIGHT_HIP_PITCH_FRONT_DEG -88.00f
#define RIGHT_HIP_PITCH_BACK_DEG 27.73f
#define RIGHT_KNEE_PITCH_FRONT_DEG -5.90f
#define RIGHT_KNEE_PITCH_BACK_DEG 121.47f
#define RIGHT_ANKLE_PITCH_FRONT_DEG -67.97f
#define RIGHT_ANKLE_PITCH_BACK_DEG 53.40f
#define RIGHT_ANKLE_ROLL_OUT_DEG -44.06f
#define RIGHT_ANKLE_ROLL_IN_DEG 22.80f

/** Limits expressed in radians */
#define HIP_YAWPITCH_LIMIT_BACK_RAD -1.145303f
#define HIP_YAWPITCH_LIMIT_FRONT_RAD 0.740810f

#define LEFT_HIP_ROLL_OUT_RAD 0.790477f
#define LEFT_HIP_ROLL_IN_RAD -0.379472f
#define LEFT_HIP_PITCH_FRONT_RAD -1.535889f
#define LEFT_HIP_PITCH_BACK_RAD 0.484090f
#define LEFT_KNEE_PITCH_FRONT_RAD -0.092346f
#define LEFT_KNEE_PITCH_BACK_RAD 2.112528f
#define LEFT_ANKLE_PITCH_FRONT_RAD -1.189516f
#define LEFT_ANKLE_PITCH_BACK_RAD 0.922747f
#define LEFT_ANKLE_ROLL_OUT_RAD 0.769001f
#define LEFT_ANKLE_ROLL_IN_RAD -0.397880f

#define RIGHT_HIP_ROLL_OUT_RAD -0.790477f
#define RIGHT_HIP_ROLL_IN_RAD 0.379472f
#define RIGHT_HIP_PITCH_FRONT_RAD -1.535889f
#define RIGHT_HIP_PITCH_BACK_RAD 0.484090f
#define RIGHT_KNEE_PITCH_FRONT_RAD -0.103083f
#define RIGHT_KNEE_PITCH_BACK_RAD 2.120198f
#define RIGHT_ANKLE_PITCH_FRONT_RAD -1.186448f
#define RIGHT_ANKLE_PITCH_BACK_RAD 0.932056f
#define RIGHT_ANKLE_ROLL_OUT_RAD -0.768992f
#define RIGHT_ANKLE_ROLL_IN_RAD 0.397935f

/**
 * HAL_LegTarget c struct
 *
 * The struct is designed around a single leg,
 * allowing independent control of the NAO's legs.
 *
 * **** IMPORTANT NOTE: ****
 * This class only provides for movement limit detection.
 * There is no built in collision detection.
 * Care must be taken to ensure the legs do not collide with
 * other parts of the robot's body.
 *
 */

struct wb_hal_legtarget
{
    /**
     *  Control Message:
     *      The elapsed time, in mSec, in which the movement should be completed.
     *  Status Message:
     *      Absolute time when the current action will complete. (Thus this is an int32_t.)
     */
    PROPERTY(int32_t, target_movement_time)

    /** target hip yaw pitch angle in 10ths of degrees */
    PROPERTY(int16_t, target_hipyawpitch)

    /** target hip roll angle angle in 10ths of degrees */
    PROPERTY(int16_t, target_hiproll)

    /** target hip pitch angle in 10ths of degrees */
    PROPERTY(int16_t, target_hippitch)

    /** target knee pitch angle in 10ths of degrees */
    PROPERTY(int16_t, target_kneepitch)

    /** target ankle pitch angle in 10ths of degrees */
    PROPERTY(int16_t, target_anklepitch)

    /** target ankle roll angle in 10ths of degrees */
    PROPERTY(int16_t, target_ankleroll)

    /** target leg number
     *  This property is used strictly for accounting purposes when
     *  the struct is stored within an array and the robot has numerous
     *  legs.
     */
    PROPERTY(uint8_t, target_leg)

    /** target hip yaw pitch stiffness as a percentage */
    PROPERTY(uint8_t, target_hipyawpitchstiffness)

    /** target hip roll stiffness as a percentage */
    PROPERTY(uint8_t, target_hiprollstiffness)

    /** target hip pitch stiffness as a percentage */
    PROPERTY(uint8_t, target_hippitchstiffness)

    /** target knee pitch stiffness as a percentage */
    PROPERTY(uint8_t, target_kneepitchstiffness)

    /** target ankle pitch stiffness as a percentage */
    PROPERTY(uint8_t, target_anklepitchstiffness)

    /** target ankle roll stiffness as a percentage */
    PROPERTY(uint8_t, target_anklerollstiffness)

    /** target leg's pliability when in Passive Mode
     *  When the leg is passive, this value reduces the update frequency,
     *  thus making the leg more resistant to external forces.
     *  Use of values from 0 to 10 is recommended.
     *  A value of zero (0), allows the quickest reponse to external forces (e.g. gravity).
     *  Higher values stiffen the leg and reduce responsiveness, the movement will become stepped.
     *  HOWEVER, the robot will fall under its own weight unless active mode is re-engaged.
     */
    PROPERTY(uint8_t, target_pliability)

    /**
     *  Is the hipyawpitch Active (true[DEFAULT]) or Passive (false)
     *  Active :  The robot's DCM will prevent movement of the hip from
     *            the requested pose in accordance to the joint stiffness.
     *            (This is the normal behaviour of the robot.)
     *  Passive:  Once the requested pose is achieved, the DCM will automatically
     *            update the requested pose according to deviations in the joints.
     *            The effect of this is that the robot's legs will be susceptible
     *            to gravity (and will fall slowly over time) as well as to
     *            externally applied forces (allowing it to be manipulated).
     *
     */
    BIT_PROPERTY(target_hipyawpitch_active)

    /**
     *  Is the hip roll Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_hiproll_active)

    /**
     *  Is the hip pitch Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_hippitch_active)

    /**
     *  Is the knee pitch Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_kneepitch_active)

    /**
     *  Is the ankle pitch Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_anklepitch_active)
    
    /**
     *  Is the ankle roll Active (true[DEFAULT]) or Passive (false)
     *
     */
    BIT_PROPERTY(target_ankleroll_active)
    
    /**
     *  Control Message:
     *      Not used
     *  Status Message:
     *      Naoqiinterface reports that the goal location of all joints
     *      have been reached (within specified tolerance).
     */
    BIT_PROPERTY(target_leg_at_goal)
    
    /**
     *  Control Message:
     *      Stop the leg at its current location
     *  Status Message:
     *      Indicates if the last control message issued a STOP command.
     */
    BIT_PROPERTY(target_leg_stop)
    
    

#ifdef __cplusplus
    /**
    * constructor for the HAL_LegTarget stuct. This is the data that is placed on the Whiteboard
    * @param leg                     uint8_t enumeration of the leg
    * @param hipyawpitch             desired hipyawpitch
    * @param hiproll                 desired hip roll
    * @param hippitch                desired hip pitch
    * @param kneepitch               desired knee pitch
    * @param anklepitch              desired ankle pitch
    * @param ankleroll               desired ankle roll
    * @param hipyawpitchstiffness    desired stiffness in the hipyawpitch joint
    * @param hiprollstiffness        desired stiffness in the hiproll joint
    * @param hippitchstiffness       desired stiffness in the hippitch joint
    * @param kneepitchstiffness      desired stiffness in the kneepitch joint
    * @param anklepitchstiffness     desired stiffness in the anklepitch joint
    * @param anklerollstiffness      desired stiffness of the ankleroll joint
    * @param hipyawpitch_active      is hip yaw pitch active
    * @param hiproll_active          is hip roll active
    * @param hippitch_active         is hip pitch active
    * @param kneepitch_active        is knee pitch active
    * @param anklepitch_active       is ankle pitch active
    * @param ankleroll_active        is ankle roll active
    * @param movement_time           time, expressed mSec to complete the movement
    *                                   (Naoqi's way of setting the speed)
    * @param pliability              when the leg is passive, this value reduces the update frequency
    * @param leg_at_goal             are the leg's joints at the goal location (within tolerance)
    * @param leg_stop                if true :  Naoqi Interface will stop the leg at its current pose,
    *                                           New motion commands will have no effect while leg is stopped.
    *                                   false:  Leg moves to requested pose.
    *
    */
    wb_hal_legtarget(uint8_t leg = LEFT_LEG,
                     int16_t hipyawpitch = 0,
                     int16_t hiproll = 0,
                     int16_t hippitch = 0,
                     int16_t kneepitch = 0,
                     int16_t anklepitch = 0,
                     int16_t ankleroll = 0,
                     uint8_t hipyawpitchstiffness = 0,
                     uint8_t hiprollstiffness = 0,
                     uint8_t hippitchstiffness = 0,
                     uint8_t kneepitchstiffness = 0,
                     uint8_t anklepitchstiffness = 0,
                     uint8_t anklerollstiffness = 0,
                     bool hipyawpitch_active = true,
                     bool hiproll_active = true,
                     bool hippitch_active = true,
                     bool kneepitch_active = true,
                     bool anklepitch_active = true,
                     bool ankleroll_active = true,
                     int32_t movement_time = INT_MAX, // Ensures sudden movements do not take place
                     uint8_t pliability = 0,
                     bool leg_at_goal = false,
                     bool leg_stop = false)
    {
        set_target_leg(leg);
        set_target_hipyawpitch(hipyawpitch);
        set_target_hiproll(hiproll);
        set_target_hippitch(hippitch);
        set_target_kneepitch(kneepitch);
        set_target_anklepitch(anklepitch);
        set_target_ankleroll(ankleroll);
        set_target_hipyawpitchstiffness(hipyawpitchstiffness);
        set_target_hiprollstiffness(hiprollstiffness);
        set_target_hippitchstiffness(hippitchstiffness);
        set_target_kneepitchstiffness(kneepitchstiffness);
        set_target_anklepitchstiffness(anklepitchstiffness);
        set_target_anklerollstiffness(anklerollstiffness);
        set_target_hipyawpitch_active(hipyawpitch_active);
        set_target_hiproll_active(hiproll_active);
        set_target_hippitch_active(hippitch_active);
        set_target_kneepitch_active(kneepitch_active);
        set_target_anklepitch_active(anklepitch_active);
        set_target_ankleroll_active(ankleroll_active);
        set_target_movement_time(movement_time);
        set_target_pliability(pliability);
        set_target_leg_at_goal(leg_at_goal);
        set_target_leg_stop(leg_stop);
    }

    /** Copy Constructor */
    wb_hal_legtarget(const wb_hal_legtarget &other)
    {
        set_target_leg(other.target_leg());
        set_target_hipyawpitch(other.target_hipyawpitch());
        set_target_hiproll(other.target_hiproll());
        set_target_hippitch(other.target_hippitch());
        set_target_kneepitch(other.target_kneepitch());
        set_target_anklepitch(other.target_anklepitch());
        set_target_ankleroll(other.target_ankleroll());
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
        set_target_leg_at_goal(other.target_leg_at_goal());
        set_target_leg_stop(other.target_leg_stop());
    }
    
    /** Copy Assignment Operator */
    wb_hal_legtarget &operator = (const wb_hal_legtarget &other)
    {
        set_target_leg(other.target_leg());
        set_target_hipyawpitch(other.target_hipyawpitch());
        set_target_hiproll(other.target_hiproll());
        set_target_hippitch(other.target_hippitch());
        set_target_kneepitch(other.target_kneepitch());
        set_target_anklepitch(other.target_anklepitch());
        set_target_ankleroll(other.target_ankleroll());
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
        set_target_leg_at_goal(other.target_leg_at_goal());
        set_target_leg_stop(other.target_leg_stop());
        return *this;
    }

    /**
      * Perform a BINARY comparision between two wb_hal_legtarget messages.
      *
     */
    inline bool operator == (const wb_hal_legtarget &rhs)
    {
        if (
            target_leg() == rhs.target_leg()
            && target_hipyawpitch() == rhs.target_hipyawpitch()
            && target_hiproll() == rhs.target_hiproll()
            && target_hippitch() == rhs.target_hippitch()
            && target_kneepitch() == rhs.target_kneepitch()
            && target_anklepitch() == rhs.target_anklepitch()
            && target_ankleroll() == rhs.target_ankleroll()
            && target_hipyawpitchstiffness() == rhs.target_hipyawpitchstiffness()
            && target_hiprollstiffness() == rhs.target_hiprollstiffness()
            && target_hippitchstiffness() == rhs.target_hippitchstiffness()
            && target_kneepitchstiffness() == rhs.target_kneepitchstiffness()
            && target_anklepitchstiffness() == rhs.target_anklepitchstiffness()
            && target_anklerollstiffness() == rhs.target_anklerollstiffness()
            && target_hipyawpitch_active() == rhs.target_hipyawpitch_active()
            && target_hiproll_active() == rhs.target_hiproll_active()
            && target_hippitch_active() == rhs.target_hippitch_active()
            && target_kneepitch_active() == rhs.target_kneepitch_active()
            && target_anklepitch_active() == rhs.target_anklepitch_active()
            && target_ankleroll_active() == rhs.target_ankleroll_active()
            && target_movement_time() == rhs.target_movement_time()
            && target_pliability() == rhs.target_pliability()
            && target_leg_at_goal() == rhs.target_leg_at_goal()
            && target_leg_stop() == rhs.target_leg_stop()
           )
        {
            return true;
        } else {
            return false;
        }
    }
    
    /** inverse comparison operator */
    inline bool operator != (const wb_hal_legtarget &rhs)
    {
        return !((*this) == rhs);
    }


#endif // __cplusplus
};



#endif //wb_hal_legtarget_h
