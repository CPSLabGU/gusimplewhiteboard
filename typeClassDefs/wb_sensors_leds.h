/**                                                                     
 *  /file wb_sensors_leds.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_sensors_leds_h
#define _wb_sensors_leds_h

#include <gu_util.h>

#define _wb_sensors_leds_h_NUMBER_OF_LEDS 77 	//taken from the c++ namespace enum value: LEDs::NUMBER_OF_LEDS

/**
 * LED sensors c struct
 */
struct wb_sensors_leds
{
                ARRAY_PROPERTY(u_int8_t, leds, _wb_sensors_leds_h_NUMBER_OF_LEDS) ///< an array of values for the LED intensity, percentage based (0 == Off, 100 == Max)
};

#endif //_wb_sensors_leds_h
