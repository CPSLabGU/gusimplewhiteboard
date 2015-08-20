/**                                                                     
 *  /file wb_sound.h 
 *                                                                      
 *  Created by Vlad Estivill-Castro in 2015.                                      
 *  Copyright (c) 2015 Vlad Estivill-Castro                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_sound_h
#define wb_sound_h

#include <gu_util.h>

/**
 * Touch sensors and sound struct
 */
struct wb_sound
{
    PROPERTY(uint16_t, frequency)       	
/**
 * duraiton is milli-seconds
 */
    PROPERTY(uint16_t, duration)       	

#ifdef __cplusplus
        /** Default constructor */
        wb_sound() : _frequency(0), _duration(0)  {}
	        /* _padding(0)  // Not needed I think */

	  /** Copy Constructor */
         wb_sound(const  wb_sound &other) :
			    _frequency(other._frequency),
			    _duration(other._duration)
					     {}

          /** Assignment Operator */
	  wb_sound &operator= (const wb_sound &other) {
		     _frequency = other._frequency;
		     _duration = other._duration;
		    return *this;
            }
#endif

};
#endif //wb_sound_h
