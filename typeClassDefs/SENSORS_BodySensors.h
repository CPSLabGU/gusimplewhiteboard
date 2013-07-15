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


namespace guWhiteboard                                                  
{
        class SENSORS_BodySensors
        {
                PROPERTY(float, InertialSensor_AccX)
                PROPERTY(float, InertialSensor_AccY)
                PROPERTY(float, InertialSensor_AccZ)
                PROPERTY(float, InertialSensor_GyrX)
                PROPERTY(float, InertialSensor_GyrY)
                PROPERTY(float, InertialSensor_GyrRef)
                PROPERTY(float, InertialSensor_AngleX)
                PROPERTY(float, InertialSensor_AngleY)
                
                PROPERTY(bool, ChestBoard_Button)       //could use a 1 bit var here
                PROPERTY(float, Battery_Charge)         //check if this is a float or not
                PROPERTY(float, Battery_Current)        //check if this is a float or not
                PROPERTY(float, US)                     //Not sure about this type, might only be 1 byte
        public:

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /// string constructor (see from_string() below)
                SENSORS_BodySensors(const std::string &str) { from_string(str); }

                void from_string(const std::string &/*str*/)
                {
                        //NYI, Good luck
                }

                std::string description() const
                {
                        std::stringstream ss;
                        ss << RAD2DEG(InertialSensor_AccX()) << " AccX, " << RAD2DEG(InertialSensor_AccY()) << " AccY, " << RAD2DEG(InertialSensor_AccZ()) << " AccZ, " << RAD2DEG(InertialSensor_GyrX()) << " GyrX, " << RAD2DEG(InertialSensor_GyrY()) << " GyrY, " << RAD2DEG(InertialSensor_GyrRef()) << " GyrRef, " << RAD2DEG(InertialSensor_AngleX()) << " X, " << RAD2DEG(InertialSensor_AngleY()) << " Y, " << ChestBoard_Button() << " Chest, " << Battery_Charge() << " Charge, " << Battery_Current() << " Current, " << US() << " US";
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
                
        };
}

#endif //SENSORS_BodySensors_DEFINED
