/**                                                                     
 *  /file wb_sensors_legtemps.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_sensors_legtemps_h
#define wb_sensors_legtemps_h

#include <gu_util.h>

/**
 * joint temp c struct
 */
struct wb_sensors_legtemps
{
    /** left knee pitch temp */
    PROPERTY(float, LKneePitch) 	

    /** left ankle pitch temp */
    PROPERTY(float, LAnklePitch)	

    /** left ankle roll temp */
    PROPERTY(float, LAnkleRoll)	

    /** right knee pitch temp */
    PROPERTY(float, RKneePitch)	

    /** right ankle pitch temp */
    PROPERTY(float, RAnklePitch)	

    /** right ankle roll temp */
    PROPERTY(float, RAnkleRoll)	
 
};

#endif // wb_sensors_legtemps_h
