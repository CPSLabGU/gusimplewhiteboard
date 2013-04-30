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


#define JOINT_DEG_GETTER(t, n) public: t n##_degrees () { return float(_##n * (float)(180/M_PI)) ; }
#define JOINT_PROPERTY(type, name) PROPERTY_DECLARATION(type,name) PROPERTY_GETTER(type,name) JOINT_DEG_GETTER(type,name) PROPERTY_SETTER(type,name)



namespace guWhiteboard                                                  
{
        class SENSORS_LegJointSensors
        {
                JOINT_PROPERTY(float, LKneePitch)
                JOINT_PROPERTY(float, LAnklePitch)
                JOINT_PROPERTY(float, LAnkleRoll)
                JOINT_PROPERTY(float, RKneePitch)
                JOINT_PROPERTY(float, RAnklePitch)
                JOINT_PROPERTY(float, RAnkleRoll)
                
        public:
                SENSORS_LegJointSensors()
                {

                }
        };
}

#endif //SENSORS_LegJointSensors_DEFINED
