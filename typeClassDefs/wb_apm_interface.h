/**                                                                     
 *  /file wb_apm_interface.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef wb_apm_interface_h
#define wb_apm_interface_h

#include <gu_util.h>

/** What type of object is using this APM */
enum apm_mode
{
	Quad = 0,
	Plane,
	NUMBER_OF_MODES
};

//! @cond Doxygen_Suppress
    //Doxy is warning about undocumented functions as a result of our macros and the fact that they're used in this union. This will disable doxy from parsing this section, which means no warnings but also no generated documentation for this section. The other option is to redefine the macros locally to fix the naming problem. - Carl.

/**
 * Param for each mode
 */
union apm_data
{
    struct {
	    /** thrust value, percentage */
	    PROPERTY(uint8_t, thrust)
            /** padding */
            PROPERTY(uint8_t, pad_)
	    /** quad pitch target angle, DEG */
	    PROPERTY(int16_t, pitch)
	    /** quad roll target angle, DEG */
	    PROPERTY(int16_t, roll)
	    /** quad yaw target angle, DEG */
	    PROPERTY(int16_t, yaw)
	} quad; ///< quad instructions

    struct {
	    /** thrust value, percentage */
	    PROPERTY(uint8_t, thrust)
	} plane; ///< plane instructions NYI!

    /** padding */
    //unsigned int _padding : 14;
	//}    motor;  ///< motor object
};
//! @endcond

/**
 * Interface for talking with an APM
 */
struct wb_apm_interface
{
	/** what type of machine */
	PROPERTY(enum apm_mode, mode)
	/** serial data */
	PROPERTY(union apm_data, data)

#ifdef __cplusplus
    /**
    * stuct constructor 
    */       
    wb_apm_interface()
    {
        memset(this, 0, sizeof(*this));
    }
#endif
};

#endif //wb_apm_interface_h
