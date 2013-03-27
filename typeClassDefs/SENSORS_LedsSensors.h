/**                                                                     
 *  /file SENSORS_LedsSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_LedsSensors_DEFINED
#define SENSORS_LedsSensors_DEFINED

#include <gu_util.h>

namespace guWhiteboard                                                  
{
        class SENSORS_LedsSensors
        {
                BITPROPERTY(LeftEar1,1);
                BITPROPERTY(LeftEar2,1);
                BITPROPERTY(LeftEar3,1);
                BITPROPERTY(LeftEar4,1);
                BITPROPERTY(LeftEar5,1);
                BITPROPERTY(LeftEar6,1);
                BITPROPERTY(LeftEar7,1);
                BITPROPERTY(LeftEar8,1);
                BITPROPERTY(LeftEar9,1);
                BITPROPERTY(LeftEar10,1);
                BITPROPERTY(RightEar1,1);
                BITPROPERTY(RightEar2,1);
                BITPROPERTY(RightEar3,1);
                BITPROPERTY(RightEar4,1);
                BITPROPERTY(RightEar5,1);
                BITPROPERTY(RightEar6,1);
                BITPROPERTY(RightEar7,1);
                BITPROPERTY(RightEar8,1);
                BITPROPERTY(RightEar9,1);
                BITPROPERTY(RightEar10,1);
                
                PROPERTY(u_int8_t, LeftEyeRed1);
                PROPERTY(u_int8_t, LeftEyeRed2);
                PROPERTY(u_int8_t, LeftEyeRed3);
                PROPERTY(u_int8_t, LeftEyeRed4);
                PROPERTY(u_int8_t, LeftEyeRed5);
                PROPERTY(u_int8_t, LeftEyeRed6);
                PROPERTY(u_int8_t, LeftEyeRed7);
                PROPERTY(u_int8_t, LeftEyeRed8);
                PROPERTY(u_int8_t, LeftEyeGreen1);
                PROPERTY(u_int8_t, LeftEyeGreen2);
                PROPERTY(u_int8_t, LeftEyeGreen3);
                PROPERTY(u_int8_t, LeftEyeGreen4);
                PROPERTY(u_int8_t, LeftEyeGreen5);
                PROPERTY(u_int8_t, LeftEyeGreen6);
                PROPERTY(u_int8_t, LeftEyeGreen7);
                PROPERTY(u_int8_t, LeftEyeGreen8);
                PROPERTY(u_int8_t, LeftEyeBlue1);
                PROPERTY(u_int8_t, LeftEyeBlue2);
                PROPERTY(u_int8_t, LeftEyeBlue3);
                PROPERTY(u_int8_t, LeftEyeBlue4);
                PROPERTY(u_int8_t, LeftEyeBlue5);
                PROPERTY(u_int8_t, LeftEyeBlue6);
                PROPERTY(u_int8_t, LeftEyeBlue7);
                PROPERTY(u_int8_t, LeftEyeBlue8);
                PROPERTY(u_int8_t, RightEyeRed1);
                PROPERTY(u_int8_t, RightEyeRed2);
                PROPERTY(u_int8_t, RightEyeRed3);
                PROPERTY(u_int8_t, RightEyeRed4);
                PROPERTY(u_int8_t, RightEyeRed5);
                PROPERTY(u_int8_t, RightEyeRed6);
                PROPERTY(u_int8_t, RightEyeRed7);
                PROPERTY(u_int8_t, RightEyeRed8);
                PROPERTY(u_int8_t, RightEyeGreen1);
                PROPERTY(u_int8_t, RightEyeGreen2);
                PROPERTY(u_int8_t, RightEyeGreen3);
                PROPERTY(u_int8_t, RightEyeGreen4);
                PROPERTY(u_int8_t, RightEyeGreen5);
                PROPERTY(u_int8_t, RightEyeGreen6);
                PROPERTY(u_int8_t, RightEyeGreen7);
                PROPERTY(u_int8_t, RightEyeGreen8);
                PROPERTY(u_int8_t, RightEyeBlue1);
                PROPERTY(u_int8_t, RightEyeBlue2);
                PROPERTY(u_int8_t, RightEyeBlue3);
                PROPERTY(u_int8_t, RightEyeBlue4);
                PROPERTY(u_int8_t, RightEyeBlue5);
                PROPERTY(u_int8_t, RightEyeBlue6);
                PROPERTY(u_int8_t, RightEyeBlue7);
                PROPERTY(u_int8_t, RightEyeBlue8);
                PROPERTY(u_int8_t, ChestRed);
                PROPERTY(u_int8_t, ChestGreen);
                PROPERTY(u_int8_t, ChestBlue);
                PROPERTY(u_int8_t, LeftFootRed);
                PROPERTY(u_int8_t, LeftFootGreen);
                PROPERTY(u_int8_t, LeftFootBlue);
                PROPERTY(u_int8_t, RightFootRed);
                PROPERTY(u_int8_t, RightFootGreen);
                PROPERTY(u_int8_t, RightFootBlue);
                
        public:
                SENSORS_LedsSensors()
                {

                }
        };
}

#endif //SENSORS_LedsSensors_DEFINED