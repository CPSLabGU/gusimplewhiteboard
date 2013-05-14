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
                PROPERTY(float, Value0)
                PROPERTY(float, Value1)
                PROPERTY(float, Value2)
                PROPERTY(float, Value3)
                PROPERTY(float, Value4)
                PROPERTY(float, Value5)
                PROPERTY(float, Value6)
                PROPERTY(float, Value7)
                PROPERTY(float, Value8)
                PROPERTY(float, Value9)
                
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

                        ss << Value0() << ", " << Value1() << ", " << Value2() << ", " << Value3() << ", " << Value4() << ", " << Value5() << ", " << Value6() << ", " << Value7() << ", " << Value8() << ", " << Value9();

                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
                
        };
}

#endif //SENSORS_SonarSensors_DEFINED