/**                                                                     
 *  /file wb_sensors_torsotemps.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_sensors_torsotemps_h
#define _wb_sensors_torsotemps_h

#include <gu_util.h>

/**
 * @brief Temp class for various joints
 * From Nao Docs: There are two different Devices that return a temperature: the MotorBoard, and the Battery. For both, the temperature returned in “Value” is in deg Celsius. The motor temperature is a simulated one, using electric current value of the motor. Even when the robot just starts, the temperature is quite high (50°C).The simulation starts at this value mainly due to the internal temperature value. The motor board implements a temperature limitation: as long as the simulated temperature reaches 75°C, the current limitation is decreased to stay under 85°C.
 */
struct wb_sensors_torsotemps
{
                PROPERTY(float, HeadYaw)	///< Deg Celsius. 
                PROPERTY(float, HeadPitch)	///< Deg Celsius.
                PROPERTY(float, LShoulderPitch)	///< Deg Celsius.
                PROPERTY(float, LShoulderRoll)	///< Deg Celsius.
                PROPERTY(float, LElbowYaw)	///< Deg Celsius.
                PROPERTY(float, LElbowRoll)	///< Deg Celsius.
                PROPERTY(float, LHipYawPitch)	///< Deg Celsius.
                PROPERTY(float, LHipRoll)	///< Deg Celsius.
                PROPERTY(float, LHipPitch)	///< Deg Celsius.
                PROPERTY(float, RHipRoll)	///< Deg Celsius.
                PROPERTY(float, RHipPitch)	///< Deg Celsius.
                PROPERTY(float, RShoulderPitch)	///< Deg Celsius.
                PROPERTY(float, RShoulderRoll)	///< Deg Celsius.
                PROPERTY(float, RElbowYaw)	///< Deg Celsius.
                PROPERTY(float, RElbowRoll)	///< Deg Celsius.
};

#endif //_wb_sensors_torsotemps_h
