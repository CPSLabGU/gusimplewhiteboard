/**                                                                     
*  /file wb_switch_subsumption.h 
*                                                                         
*  Created by Vlad Estivill-Castro in 2015.
*  Copyright (c) 2015 Vlad Estivill-Castro
*  All rights reserved
*/   
#ifndef wb_switch_subsumption_h
#define wb_switch_subsumption_h

#include <gu_util.h>

/**
 *  Motion of Toto are converted to motions on Gazebo for Tiago
*/
#define SUBSUMPTION_LEVELS	6 // number of subsumption levels
#define SUMPSUMSION_LEVELS	SUBSUMPTION_LEVELS // XXX: typo in machines 

enum TotoMotionCommand
{	TOTO_NO_COMMAND, // no command do not subsumme
	TOTO_STOP,
	TOTO_BACKWARDS,
	TOTO_MOVE_FORWARD,
	TOTO_TURN_LEFT,
	TOTO_TURN_RIGHT
};

struct wb_toto_doing_motion
{
        PROPERTY(TotoMotionCommand, motionCommand)
};


struct wb_switch_subsumption
{
     ARRAY_PROPERTY(enum TotoMotionCommand, theMotions, SUBSUMPTION_LEVELS)

#ifdef __cplusplus
        /** struct constructor */
	wb_switch_subsumption()
	{ memset(this, 0, sizeof(*this));
	}
	      	
#endif

};
#endif //wb_switch_subsumption_h
