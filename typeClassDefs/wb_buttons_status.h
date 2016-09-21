/**                                                                     
 *  /file wb_buttons_status.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_buttons_status_h
#define wb_buttons_status_h

#include <gu_util.h>
#include "wb_button.h"

/** A handy enum for accessing the objects array */
enum nxt_buttons_id
{
	LEFT_BUTTON = 0,
	RIGHT_BUTTON,
        NUMBER_OF_NXT_BUTTONS
};

/**
 * An Array of buttons for talking with an NXT
 */
struct wb_buttons_status
{
    /** An array of sensors and motors plugged into the nxt ports. Objects 0,1,2,3 are the sensors 1-4, objects 4,5,6 are the motors A,B,C. */
    ARRAY_PROPERTY(struct wb_button, touch_sensors, NUMBER_OF_NXT_BUTTONS)

#ifdef __cplusplus
    /**
    * stuct constructor 
    */       
    wb_buttons_status()
    {
        memset(this, 0, sizeof(*this));
    }
#endif
};

#endif //wb_buttons_status_h
