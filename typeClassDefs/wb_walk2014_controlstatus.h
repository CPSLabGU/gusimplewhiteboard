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
    STAND        = 0, ///< with knees straight and stiffness set to zero to conserve energy and heat generation in motors
    WALK         = 3, ///< walking state
    READY        = 4, ///< stand still ready to walk (stiffness on)
    KICK         = 5, ///< NYI kicking option
    DISCONNECT   = 7,       ///< walk is disconnected from the DCM (auto connects in any other state)
    RESET_ODOMETRY = 8,     ///< resets the odometry objects

    //Internal options
    STANDUP      = 1, ///< process of moving from WALK crouch to STAND (internal)
    CROUCH       = 2, ///< process of transitioning from STAND to WALK (internal)
    NONE         = 6 ///< Do nothing (internal)
};


enum WALK_ControlStatus_Mode
{
};

/**
 * walk c struct
 */
struct wb_walk2014_controlstatus
{
	/** Forward movement, -100 to 100 percent */
	PROPERTY(float, forward)      	
	/** Side step movement, -100 to 100 percent */
        PROPERTY(float, left)           
	/** Rotation in RAD */
        PROPERTY(float, turn)           
	/** Power value, best set to 100 and forgotten - Carl. */
        PROPERTY(float, power)          

	/** Walk State, getting / setting the state of the walk engine. Such as setting WALK_Stop to stop walking. */
        PROPERTY(WALK_ControlStatus_Mode, controlStatus) 	
	/** Odometry object, tracking walk distances over time */
        PROPERTY(Odometry, odometry) 				
	/** Odometry mask, for overwriting the odomety in the walk */
        PROPERTY(bool, odometry_mask) 				
	/** Just padding, ignore  */
        PROPERTY(bool, pad1) 					
	/** Just padding, ignore */
        PROPERTY(int16_t, pad2) 				

#ifdef __cplusplus
   /** Constructor with some default values */
    wb_walk2014_controlstatus(WALK_ControlStatus_Mode c = WALK_Disconnected, float forward = 0, float left = 0, float turn = 0, float power = 0): _forward(forward), _left(left), _turn(turn), _power(power), _controlStatus(c), _odometry_mask(false) {}
#endif

};

#endif //_wb_walk2014_controlstatus_h
