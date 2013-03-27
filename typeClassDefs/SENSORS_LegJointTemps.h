/**                                                                     
 *  /file SENSORS_LegJointTemps.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_LegJointTemps_DEFINED
#define SENSORS_LegJointTemps_DEFINED

#include <gu_util.h>

namespace guWhiteboard                                                  
{
        class SENSORS_LegJointTemps
        {
                PROPERTY(float, LKneePitch);
                PROPERTY(float, LAnklePitch);
                PROPERTY(float, LAnkleRoll);
                PROPERTY(float, RKneePitch);
                PROPERTY(float, RAnklePitch);
                PROPERTY(float, RAnkleRoll);
                
        public:
                SENSORS_LegJointTemps()
                {

                }
        };
}

#endif //SENSORS_LegJointTemps_DEFINED