/**                                                                     
 *  /file wb_oculus_prime_serial.h 
 *                                                                      
 *  Created by Carl Lusty in 2015.                                      
 *  Copyright (c) 2015 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_oculus_prime_serial_h
#define wb_oculus_prime_serial_h

#include <gu_util.h>

/**
 * Serial interface for the main giraff board.
 * This includes the buttons, battery data and motor control.
 */
struct wb_oculus_prime_serial
{
    /** speed for each wheel */
    CONTROLLED_ARRAY_PROPERTY(uint8_t, forward, 2)



    /** stop */
    CONTROLLED_PROPERTY(uint8_t, stop) ///< value ignored, mask setting is what's used

    /** Control bit (mask) */
    CONTROL_BIT(forward)
    /** Control bit (mask) */
    CONTROL_BIT(stop)

#ifdef __cplusplus
    /**
    * stuct constructor 
    */       
    wb_oculus_prime_serial()
    {
        memset(this, 0, sizeof(*this));
    }
#endif
};

#endif //_wb_oculus_prime_serial_h