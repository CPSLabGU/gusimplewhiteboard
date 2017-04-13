/**                                                                     
 *  /file wb_lights.h 
 *                                                                      
 *  Created by Vlad Estivill-Castro in 2015.                                      
 *  Copyright (c) 2015 Vlad Estivill-Castro                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_lights_h
#define wb_lights_h

#include <gu_util.h>

#define wb_lights_h_NUMBER_OF_LIGHTS 1 	

/**
 * Lights that can go an on --- C struct
 */
struct wb_lights
{
    /** an array of values for the LIGHTS intensity, percentage based (0 == Off, 100 == Max) */
    ARRAY_PROPERTY(u_int8_t, lights, wb_lights_h_NUMBER_OF_LIGHTS) 
};

#endif //wb_lights_h
