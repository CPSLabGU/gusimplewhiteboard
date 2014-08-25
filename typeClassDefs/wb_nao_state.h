/**                                                                     
 *  /file wb_nao_state.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_nao_state_h
#define _wb_nao_state_h

#include <gu_util.h>

enum Robot_Stance {
        Standing = 0,
        FallenForward,
        FallenBack,
        FallenLeft,
        FallenRight,
        Sitting,        //NYI
        Kneeling,       //NYI
        Knitting,       //NYI to be implemented by Rene
        NUM_OF_STANCES
};

enum Robot_Walk{
        Modded_UNSW_Walk = 0,
        ALMotion_Walk,
        NUM_OF_WALKS
};

/**
 * nao state c struct
 */
struct wb_nao_state
{
	/** Currently SMRobotPosition detects if the robot has fallen over. If not fallen over SMRobotPosition posts Standing. */
	PROPERTY(Robot_Stance, stance)          
	/** Tells the walk engine which walk to use */
	PROPERTY(Robot_Walk, walk)          
	/** chest pressed for more than half a second */
	PROPERTY(bool, chest_pressed_long)      
	/** left foot pressed for more than half a second */
	PROPERTY(bool, left_foot_pressed_long)  
	/** right foot pressed for more than half a second */
	PROPERTY(bool, right_foot_pressed_long)  
	/** chest pressed  */
	PROPERTY(bool, chest_pressed)      
	/** left foot pressed  */
	PROPERTY(bool, left_foot_pressed)  
	/** right foot pressed  */
	PROPERTY(bool, right_foot_pressed)  
	/** padding */
	int16_t pad;

#ifdef __cplusplus
	/** constructor */
	wb_nao_state(): _stance(Standing), _walk(Modded_UNSW_Walk),_chest_pressed_long(false), _left_foot_pressed_long(false), _right_foot_pressed_long(false), _chest_pressed(0), _left_foot_pressed(0), _right_foot_pressed(0) {}
#endif
};

#endif //_wb_nao_state_h
