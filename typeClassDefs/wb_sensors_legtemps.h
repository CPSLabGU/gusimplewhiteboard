/**                                                                     
 *  /file wb_sensors_legtemps.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_sensors_legtemps_h
#define _wb_sensors_legtemps_h

#include <gu_util.h>

/**
 * joint temp c struct
 */
struct wb_sensors_legtemps
{
                PROPERTY(float, LKneePitch) 	///< left knee pitch temp
                PROPERTY(float, LAnklePitch)	///< left ankle pitch temp
                PROPERTY(float, LAnkleRoll)	///< left ankle roll temp
                PROPERTY(float, RKneePitch)	///< right knee pitch temp
                PROPERTY(float, RAnklePitch)	///< right ankle pitch temp
                PROPERTY(float, RAnkleRoll)	///< right ankle roll temp
 
};

#endif //_wb_sensors_legtemps_h
