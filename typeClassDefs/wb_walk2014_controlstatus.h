/**                                                                     
 *  /file wb_walk2014_controlstatus.h 
 *                                                                      
 *  Created by Carl Lusty in 2015.  
 *  Copyright (c) 2015 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_walk2014_controlstatus_h
#define wb_walk2014_controlstatus_h

#include <gu_util.h>

#ifdef __cplusplus
#include <float.h>
#endif

#ifndef USE_UNSW_ODOMETRY
#ifndef wb_walk_odometry_h
#define wb_walk_odometry_h
struct Odometry                         ///< needs to mimic UNSW odometry!
{
        float forward;		///< forward, mm/s
        float left;		///< sideways, mm/s
        float turn;		///< rotation, deg/s

#ifdef __cplusplus
   /** Comparison operator for Odometry objects */
   inline bool operator== (const Odometry& a) {
      return (	fabs(static_cast<double>(forward - a.forward)) < DBL_EPSILON &&
		fabs(static_cast<double>(left - a.left)) < DBL_EPSILON &&
		fabs(static_cast<double>(turn - a.turn)) < DBL_EPSILON);
   }
#endif

};
#endif // wb_walk_odometry_h
#endif //USE_UNSW_ODOMETRY

/**
 * Options for ControlStatus
 * This is a superset of the options present in the original UNSW 2014 Walk Engine. I could change all the names however it would make code comparison difficult later. - Carl.
 */
enum Walk2014Option 
{
    DISCONNECT   = 0,       ///< walk is disconnected from the DCM (auto connects in any other state)
    STAND        = 1, ///< with knees straight and stiffness set to zero to conserve energy and heat generation in motors
    WALK         = 2, ///< walking state
    READY        = 3, ///< stand still ready to walk (stiffness on)
    KICK         = 4, ///< NYI kicking option
    RESET_ODOMETRY = 5,     ///< resets the odometry objects

    //Internal options
    STANDUP      = 6, ///< process of moving from WALK crouch to STAND (internal)
    CROUCH       = 7, ///< process of transitioning from STAND to WALK (internal)
    NONE         = 8, ///< Do nothing (internal)
    NUMBER_OF_WALK_OPTIONS = 9 ///< Helper value
};

/** Walk status enum */
enum WalkState {
   NOT_WALKING    = 0,	///< Not walking at this point
   WALKING        = 1,	///< Currently walking
   STARTING       = 2,	///< Currently starting to walk
   STOPPING       = 3	///< Currently stopping
};

/** Part of the NYI kicking option */
enum KickingFoot {
   LEFT     = 0,	///< Kick with left foot
   RIGHT    = 1		///< Kick with right foot
};

/** Part of the NYI kicking option */
enum ActionState {
   WALK_Action  = 0,	///< TBD
   KICK_Action 	= 1,	///< TBD
   NUMBER_OF_ACTIONS	///< Helper value
};

/**
 * walk c struct
 */
struct wb_walk2014_controlstatus
{
	/** Forward movement, mm/sec */
	PROPERTY(float, forward)      	
	/** Side step movement, mm/sec */
        PROPERTY(float, left)           
	/** Rotation in DEG/sec */
        PROPERTY(float, turn)           
	/** Power value, alters the stiffness and 'power' of kicks (kick part NYI), percentage 0 - 100 */
        PROPERTY(float, power)          

	/** Which foot to use when kicking, NYI */
        PROPERTY(enum KickingFoot, foot)
	/** Sets the current state of the walk engine */
        PROPERTY(enum Walk2014Option, walk_state)
	/** Reports the current walking state (can not be set, use setters / helper functions to change what the walk is doing) */
        PROPERTY(enum WalkState, walking_status)

	/** Odometry object, tracking walk distances over time */
        PROPERTY(struct Odometry, odometry)

#ifdef __cplusplus
   /** Constructor with some default values */
    wb_walk2014_controlstatus()
    {
        memset(this, 0, sizeof(*this)); 
    }

    wb_walk2014_controlstatus(Walk2014Option option, float forward = 0, float left = 0, float turn = 0, float power = 0, KickingFoot foot = LEFT)
    {
        memset(this, 0, sizeof(*this)); 
        _forward = forward;
        _left = left;
        _turn = turn;
        _power = power;
        _foot = foot;
        _walk_state = option;
    }

    wb_walk2014_controlstatus(Walk2014Option option, float forward, float left, float turn, float power, KickingFoot foot, WalkState w_status, Odometry odo) : _forward(forward), _left(left), _turn(turn), _power(power), _foot(foot), _walk_state(option), _walking_status(w_status), _odometry(odo)
    {

    }

#endif

};

#endif // wb_walk2014_controlstatus_h
