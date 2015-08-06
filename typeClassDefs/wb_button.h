/**                                                                     
 *  /file wb_button.h 
 *                                                                      
 *  Created by Vlad Estivill-Castro in 2015.                                      
 *  Copyright (c) 2015 Vlad Estivill-Castro                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_button_h
#define wb_button_h

#include <gu_util.h>

/**
 * Touch sensors and button struct
 */
struct wb_button
{
    PROPERTY(bool, is_pressed)       	

#ifdef __cplusplus
        /** Default constructor */
        wb_button() : _is_pressed(false)  {}
	        /* _padding(0)  // Not needed I think */

	  /** Copy Constructor */
         wb_button(const  wb_button &other) :
			    _is_pressed(other._is_pressed)
					     {}

          /** Assignment Operator */
	  wb_button &operator= (const wb_button &other) {
		     _is_pressed = other._is_pressed;
		    return *this;
            }
#endif

};
#endif //wb_button_h
