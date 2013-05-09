/**                                                                     
 *  /file SENSORS_LegJointSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_LegJointSensors_DEFINED
#define SENSORS_LegJointSensors_DEFINED

#define _USE_MATH_DEFINES
#include <gu_util.h>
#include <cmath>



namespace guWhiteboard                                                  
{
        class SENSORS_LegJointSensors
        {
                PROPERTY(float, LKneePitch)
                PROPERTY(float, LAnklePitch)
                PROPERTY(float, LAnkleRoll)
                PROPERTY(float, RKneePitch)
                PROPERTY(float, RAnklePitch)
                PROPERTY(float, RAnkleRoll)
                
        public:
                SENSORS_LegJointSensors()
                {

                }
        };
}

#endif //SENSORS_LegJointSensors_DEFINED
