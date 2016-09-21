/* 
 * File:   wb_oculus_prime_interface.h
 * Author: eugene
 * Copyright (c) 2015 Eugene Gilmore                                       
 * All rights reserved.  
 *
 * Created on 28 July 2015, 6:27 PM
 */

#ifndef WB_OCULUS_PRIME_INTERFACE_H
#define	WB_OCULUS_PRIME_INTERFACE_H

#include <gu_util.h>

enum MovementType {
	LEFT,
	RIGHT,
	FORWARD,
	BACKWARD,
	STOP
};

struct wb_oculus_prime_interface {
	/**Continues movement - performs this movement until another movement command is specified*/
	CONTROLLED_PROPERTY(enum MovementType, move)
	/**sets the drive motor speed. Value is PWM between 0-255*/
	CONTROLLED_PROPERTY(uint8_t, speed)
	/**move forward the specified distance in meters, then stop*/
	CONTROLLED_PROPERTY(double, forward)
	/**move backward the specified distance in meters, then stop*/
	CONTROLLED_PROPERTY(double, backward)
	/**rotate left the specified angle in degrees, then stop*/
	CONTROLLED_PROPERTY(double, left)
	/**rotate right the specified angle in degrees, then stop*/
	CONTROLLED_PROPERTY(double, right)
	
	CONTROL_BIT(move)
	CONTROL_BIT(speed)
	CONTROL_BIT(forward)
	CONTROL_BIT(backward)
	CONTROL_BIT(left)
	CONTROL_BIT(right)
		
#ifdef __cplusplus
	wb_oculus_prime_interface() : _move_mask(0), _speed_mask(0), _forward_mask(0), 
		_backward_mask(0), _left_mask(0), _right_mask(0) {}
#endif
};

#endif	/* WB_OCULUS_PRIME_INTERFACE_H */

