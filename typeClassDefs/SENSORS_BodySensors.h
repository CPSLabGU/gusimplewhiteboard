/**                                                                     
 *  /file SENSORS_BodySensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_BodySensors_DEFINED
#define SENSORS_BodySensors_DEFINED

#include <gu_util.h>

#define DEG_GETTER(t, n) public: t n##_degrees () { return (_##n * (180/M_PI)) ; }
#define DEG_PROPERTY(type, name) PROPERTY_DECLARATION(type,name); PROPERTY_GETTER(type,name) DEG_GETTER(type,name) PROPERTY_SETTER(type,name)



namespace guWhiteboard                                                  
{
        class SENSORS_BodySensors
        {
                PROPERTY(float, InertialSensor_AccX);
                PROPERTY(float, InertialSensor_AccY);
                PROPERTY(float, InertialSensor_AccZ);
                PROPERTY(float, InertialSensor_GyrX);
                PROPERTY(float, InertialSensor_GyrY);
                PROPERTY(float, InertialSensor_GyrRef);
                DEG_PROPERTY(float, InertialSensor_AngleX);
                DEG_PROPERTY(float, InertialSensor_AngleY);
                
                PROPERTY(bool, ChestBoard_Button); //could use a 1 bit var here
                PROPERTY(float, Battery_Charge); //check if this is a float or not
                PROPERTY(float, Battery_Current); //check if this is a float or not
                PROPERTY(float, US); //Not sure about this type, might only be 1 byte
        public:
                SENSORS_BodySensors()
                {

                }
        };
}

#endif //SENSORS_BodySensors_DEFINED