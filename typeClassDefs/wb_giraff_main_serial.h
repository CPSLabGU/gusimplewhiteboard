/**                                                                     
 *  /file wb_giraff_main_serial.h 
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
 
#ifndef _wb_giraff_main_serial_h
#define _wb_giraff_main_serial_h

#include <gu_util.h>

/**
 * Controls the type of movement the giraff uses
 */
enum Giraff_MovementType
{
    Rotation    = 0,    ///< Giraff rotates when position is set (deg/sec)
    Straight    = 1,    ///< Giraff moves forward and backwards via position (m/sec)
    Arc         = 51    ///< Giraff arcs based on vg and position (position forward and backwards (m/s) and vg controls the wheel gear ratio)
};

/**
 * Controls when position uses relative and absolute distances (absolute is based on odometry and is reset when coord_type is changed).
 */
enum Giraff_CoordType
{
    Relative_Coords = 0,        ///< Distances passed to position are relative to the current position
    Absolute_Coords = 1,        ///< Distances to be are relative to the odometry zero position (odometry is reset when this is toggled to absolute mode).
    BufferedAbsolute_Coords = 4 ///< Distances are absolute however commands are blocking and wait for previous commands to finish (buffer of 4).
};

/**
 * Serial interface for the main giraff board.
 * This includes the buttons, battery data and motor control.
 */
struct wb_giraff_main_serial
{
    /** Giraff maximum velocity , Unit: m/s, Range: 0.0 / 150.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, velocity)

    /** The type of movement ot be done. See Giraff_MovementType, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(Giraff_MovementType, movement_type)

    /** Giraff acceleration, Unit: m/s2, Range: 0.0 / 150.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, acceleration)

    /** Distance or angle to move, Unit: m or deg, Range: -1000.0 / 1000.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, position)

    /** Changes the distances of position to relative or absolute. Also controls command preemption when in absolute mode by allowing 4 buffered commands to be sent. See Giraff_CoordType, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(Giraff_CoordType, coord_type)

    /** Current head tilt angle, Unit: rad, Range: 0.0872664 / 2.0943935, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, head_angle)

    /** Maximum virtual gear ratio, Unit: gr, Range: -1000.0 / 1000.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, max_gear_ratio)

    /** Viritual gear rate of change, Unit: gr/m, Range: 1000.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, gear_ratio_increments)

    /** Clothoid decelaration point, Unit: m, Range: -1000.0 / 1000.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, gear_ratio_slowdown_dist)

    /** Current virtual gear ratio, Unit: gr, Range: -1000.0 / 1000.0, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(float, current_gear_ratio)

    /** Number of red button presses, Unit: presses, Range: 0 / 2147483647, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(int16_t, red_button_presses)

    /** Number of green button presses, Unit: presses, Range: 0 / 2147483647, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(int16_t, blue_button_presses)

    /** Incremental value of dial, Unit: value, Range: -2147483648 / 2147483647, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(int16_t, dial_increments)

    /** Fix alignment */
    PROPERTY(int16_t, padding)

    /** Left drive motor encoder pulses, Unit: pulses, Range: -100000000 / 100000000, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(int32_t, left_motor_encoder_ticks)

    /** Right drive motor encoder pulses, Unit: pulses, Range: -100000000 / 100000000, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(int32_t, right_motor_encoder_ticks)

    /** Head tilt motor encoder pulses, Unit: pulses, Range: -100000000 / 100000000, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(int32_t, head_motor_encoder_ticks)

    /** Charger/battery data, Unit: multiple, Range: See individuals, Setter: No, Getter: Yes*/
    //CONTROLLED_PROPERTY(multiple, charger_data)

    /** Control bit (mask) */
    CONTROL_BIT(velocity)

    /** Control bit (mask) */
    CONTROL_BIT(movement_type)

    /** Control bit (mask) */
    CONTROL_BIT(acceleration)

    /** Control bit (mask) */
    CONTROL_BIT(position)

    /** Control bit (mask) */
    CONTROL_BIT(coord_type)

    /** Control bit (mask) */
    CONTROL_BIT(head_angle)

    /** Control bit (mask) */
    CONTROL_BIT(max_gear_ratio)

    /** Control bit (mask) */
    CONTROL_BIT(gear_ratio_increments)

    /** Control bit (mask) */
    CONTROL_BIT(gear_ratio_slowdown_dist)

    /** Control bit (mask) */
    CONTROL_BIT(current_gear_ratio)

    /** Control bit (mask) */
    CONTROL_BIT(red_button_presses)

    /** Control bit (mask) */
    CONTROL_BIT(blue_button_presses)

    /** Control bit (mask) */
    CONTROL_BIT(dial_increments)

    /** Control bit (mask) */
    CONTROL_BIT(left_motor_encoder_ticks)

    /** Control bit (mask) */
    CONTROL_BIT(right_motor_encoder_ticks)

    /** Control bit (mask) */
    CONTROL_BIT(head_motor_encoder_ticks)

    /** Fix alignment */
    PROPERTY(int16_t, padding2)

#ifdef __cplusplus
    /**
    * stuct constructor 
    */       
    wb_giraff_main_serial()
    {
        memset(this, 0, sizeof(*this));
    }
#endif
};

#endif //_wb_giraff_main_serial_h
