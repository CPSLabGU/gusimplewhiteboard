/**                                                                     
 *  /file wb_nxt_interface.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_nxt_interface_h
#define _wb_nxt_interface_h

#include <gu_util.h>

/** A handy enum for accessing the objects array */
enum nxt_ports
{
	Port1 = 0,
	Port2,
	Port3,
	Port4,
	MotorA,
	MotorB,
	MotorC,
	NUMBER_OF_NXT_PORTS
};

/** Used to determine what type of object is plugged into each port on the nxt currently */
enum nxt_port_object_type
{
	Empty_Port = 0,
	Sonar_Sensor,
	Touch_Sensor,
	Passive_Light_Sensor,
	Active_Light_Sensor,
	Motor,
	NUMBER_OF_NXT_OBJECT_TYPES
};

//! @cond Doxygen_Suppress
    //Doxy is warning about undocumented functions as a result of our macros and the fact that they're used in this union. This will disable doxy from parsing this section, which means no warnings but also no generated documentation for this section. The other option is to redefine the macros locally to fix the naming problem. - Carl.

/**
 * object to contain the values for a generic nxt port connection
 */
union nxt_port_object_data
{
    struct {
	/** sonar distance reported in cm */
	PROPERTY(uint8_t, distance)
	} sonar_sensor; ///< sonar object 

    struct {
	/** buttonm pressed state: true == pressed */
	PROPERTY(bool, pressed)
	}  touch_sensor;  ///< touch object

    struct {
	/** Needs investigating */
	PROPERTY(int32_t, value)
	}    passive_light_sensor; ///< passive light object

    struct {
	/** Needs investigating */
	PROPERTY(int32_t, value)
	}    active_light_sensor; ///< active light object

    struct {
	/** encoder ticks */
	CONTROLLED_PROPERTY(uint32_t, enc_ticks) 
	/** percentage of speed: 0 == stopped, 100 == forward max, -100 backwards max*/
	CONTROLLED_PROPERTY(int16_t, speed) 
	/** reset encoders? */
	CONTROL_BIT(enc_ticks)
	/** set speed? */
	CONTROL_BIT(speed)
    
    /** padding */
    unsigned int _padding : 14;
	}    motor;  ///< motor object
};
//! @endcond

/** An object that contains the type and data of an nxt sensor */
struct nxt_port_object
{
	/** what type of sensor / motor */
	PROPERTY(nxt_port_object_type, type) 
	/** the sensor / motor data */
	PROPERTY(nxt_port_object_data, data) 
};

/**
 * Interface for talking with an NXT
 */
struct wb_nxt_interface
{
    /** An array of sensors and motors plugged into the nxt ports. Objects 0,1,2,3 are the sensors 1-4, objects 4,5,6 are the motors A,B,C. */
    ARRAY_PROPERTY(nxt_port_object, objects, NUMBER_OF_NXT_PORTS)

#ifdef __cplusplus
    /**
    * stuct constructor 
    */       
    wb_nxt_interface()
    {
        memset(this, 0, sizeof(*this));
    }
#endif
};

#endif //_wb_nxt_interface_h
