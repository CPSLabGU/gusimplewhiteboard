/**                                                                     
*  /file wb_switch_subsumption.h 
*   *                                                                      
*  Created by Vlad Estivill-Castro in 2015.
*  * Copyright (c) 2015 Vlad Estivill-Castro
*  *   All rights reserved*       
*/   
#ifndef wb_switch_subsumption_h
#define wb_switch_subsumption_h

#include <gu_util.h>

/**
 *  * Motion of Toto are converted to motions on Gazebo for Tiago
*/
#define SUMPSUMSION_LEVELS	6 // number of subsumption levels

enum TotoMotionCommand
{	NO_COMMAND, // no command do not subsumme
	STOP,
	BACKWARDS,
	MOVE_FORWARD,
	TUYRN_LEFT,
	TURN_RIGHT
};

struct toto_motion_command
{
        PROPERTY(TotoMotionCommand, motionCommand)
};


struct wb_switch_subsumption
{
      //ARRAY_PROPERY(int, theMotions, SUMPSUMSION_LEVELS)        
     ARRAY_PROPERTY(enum TotoMotionCommand, theMotions, SUMPSUMSION_LEVELS)

#ifdef __cplusplus
        /** struct constructor */
	wb_switch_subsumption()
	{ memset(this, 0, sizeof(*this));
	}
	      	
#endif

};
#endif //wb_switch_subsumption_h
