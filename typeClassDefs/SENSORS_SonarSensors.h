/**                                                                     
 *  /file SENSORS_SonarSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_SonarSensors_DEFINED
#define SENSORS_SonarSensors_DEFINED

#include <gu_util.h>

namespace guWhiteboard                                                  
{
        class SENSORS_SonarSensors
        {
                PROPERTY(u_int8_t, Left0);
                PROPERTY(u_int8_t, Left1);
                PROPERTY(u_int8_t, Left2);
                PROPERTY(u_int8_t, Left3);
                PROPERTY(u_int8_t, Left4);
                PROPERTY(u_int8_t, Left5);
                PROPERTY(u_int8_t, Left6);
                PROPERTY(u_int8_t, Left7);
                PROPERTY(u_int8_t, Left8);
                PROPERTY(u_int8_t, Left9);
                PROPERTY(u_int8_t, Right0);
                PROPERTY(u_int8_t, Right1);
                PROPERTY(u_int8_t, Right2);
                PROPERTY(u_int8_t, Right3);
                PROPERTY(u_int8_t, Right4);
                PROPERTY(u_int8_t, Right5);
                PROPERTY(u_int8_t, Right6);
                PROPERTY(u_int8_t, Right7);
                PROPERTY(u_int8_t, Right8);
                PROPERTY(u_int8_t, Right9);
                
        public:
                SENSORS_SonarSensors()
                {

                }
        };
}

#endif //SENSORS_SonarSensors_DEFINED