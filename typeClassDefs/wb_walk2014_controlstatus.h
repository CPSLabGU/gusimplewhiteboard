/**                                                                     
 *  /file wb_walk2014_controlstatus.h 
 *                                                                      
 *  Created by Carl Lusty in 2015.  
 *  Copyright (c) 2015 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_walk2014_controlstatus_h
#define _wb_walk2014_controlstatus_h

#include <gu_util.h>

#ifdef __cplusplus
#include <float.h>
#endif

struct Odometry                         ///< needs to mimic UNSW odometry!
{
        float forward;		///< forward, mm/s
        float left;		///< sideways, mm/s
        float turn;		///< rotation, deg/s

#ifdef __cplusplus
   /** Comparison operator for Odometry objects */
   inline bool operator== (const Odometry& a) {
      return (	fabs(forward - a.forward) < FLT_EPSILON &&
		fabs(left - a.left) < FLT_EPSILON &&
		fabs(turn - a.turn) < FLT_EPSILON);
   }
#endif

};

/**
 * Options for ControlStatus
 * This is a superset of the options present in the original UNSW 2014 Walk Engine. I could change all the names however it would make code comparison difficult later. - Carl.
 */
enum Walk2014Option 
{
    DISCONNECT   = 0,       ///< walk is disconnected from the DCM (auto connects in any other state)
    STAND        = 7, ///< with knees straight and stiffness set to zero to conserve energy and heat generation in motors
    WALK         = 3, ///< walking state
    READY        = 4, ///< stand still ready to walk (stiffness on)
    KICK         = 5, ///< NYI kicking option
    RESET_ODOMETRY = 8,     ///< resets the odometry objects

    //Internal options
    STANDUP      = 1, ///< process of moving from WALK crouch to STAND (internal)
    CROUCH       = 2, ///< process of transitioning from STAND to WALK (internal)
    NONE         = 6 ///< Do nothing (internal)
};

/** Walk status enum */
enum WalkState {
   NOT_WALKING    = 0,	///< Not walking at this point
   WALKING        = 1,	///< Currently walking
   STARTING       = 2,	///< Currently starting to walk
   STOPPING       = 3,	///< Currently stopping
   NUMBER_OF_WALK_STATES ///< Helper value
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
        PROPERTY(KickingFoot, foot)          
	/** Sets the current state of the walk engine */
        PROPERTY(Walk2014Option, walk_state)          
	/** Reports the current walking state (can not be set, use setters / helper functions to change what the walk is doing) */
        PROPERTY(WalkState, walking_status)          

	/** Odometry object, tracking walk distances over time */
        PROPERTY(Odometry, odometry) 				

#ifdef __cplusplus
   /** Constructor with some default values */
    wb_walk2014_controlstatus()
    {
        memset(this, 0, sizeof(*this)); 
    }
#endif

};

#endif //_wb_walk2014_controlstatus_h
