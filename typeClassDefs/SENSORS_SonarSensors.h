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
        namespace Sonar
        {
                typedef enum ReadingCodesEnum {
                        Left0,
                        Left1,
                        Left2,
                        Left3,
                        Left4,
                        Left5,
                        Left6,
                        Left7,
                        Left8,
                        Left9,
                        Right0,
                        Right1,
                        Right2,
                        Right3,
                        Right4,
                        Right5,
                        Right6,
                        Right7,
                        Right8,
                        Right9,
                        NUMBER_OF_READINGS
                } ReadingCode;
        }
        
        
        class SENSORS_SonarSensors
        {
                ARRAY_PROPERTY(u_int8_t, sonar, Sonar::NUMBER_OF_READINGS)
                
        public:
                SENSORS_SonarSensors()
                {

                }
                
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /// string constructor (see from_string() below)
                SENSORS_SonarSensors(const std::string &str) { from_string(str); }
                
                void from_string(const std::string &str)
                {
                        //NYI, good luck, the values will be garbage.
                }
                
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wunreachable-code"
                
                /**
                 * return the head and body stiffness as a boolean
                 */
                std::string description() const
                {
                        std::stringstream ss;

                        for (int i = 0; i < (Sonar::NUMBER_OF_READINGS-1); i++)
                                ss << (int)sonar(i) << ",";
                        ss << (int)sonar(Sonar::NUMBER_OF_READINGS-1); //Don't want a ', ' for the last element.
                        
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
                
        };
}

#endif //SENSORS_SonarSensors_DEFINED