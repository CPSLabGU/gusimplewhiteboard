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
 * Serial interface for the main giraff board.
 * This includes the buttons, battery data and motor control.
 */
struct wb_giraff_main_serial
{
    /** Giraff maximum velocity , Unit: m/s, Range: 0.0 / 150.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, v)

    /** Move straight( > 0 ) or rotate, Unit: -, Range: -1.0E8 / 1.0E8, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, r)

    /** Giraff acceleration, Unit: m/s2, Range: 0.0 / 150.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, a)

    /** Distance or angle to move, Unit: m or deg, Range: -1000.0 / 1000.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, p)

    /** Current movement mode, Unit: -, Range: 0 / 255, Setter: Lower 4 bits, Getter: Yes*/
    CONTROLLED_PROPERTY(uint8_t, mode)

    /** Undock with specified backup distance, Unit: m, Range: -1.0 / 1.0, Setter: Yes, Getter: No*/
    CONTROLLED_PROPERTY(float, undock)

    /** Head homing sequence NOTE: Seems broken, commented out for now - Carl. , Unit: -, Range: -, Setter: -, Getter: -*/
    //CONTROLLED_PROPERTY(-, home)

    /** Tilt homing state, Unit: -, Range: 0 / 255, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(uint8_t, tilt_homing_state)

    /** Current head tilt angle, Unit: rad, Range: 0.0872664 / 2.0943935, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, tilt_angle_from_home)

    /** Maximum virtual gear ratio, Unit: gr, Range: -1000.0 / 1000.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, vg)

    /** Viritual gear rate of change, Unit: gr/m, Range: 1000.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, vgr)

    /** Clothoid decelaration point, Unit: m, Range: -1000.0 / 1000.0, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(float, cdp)

    /** Current virtual gear ratio, Unit: gr, Range: -1000.0 / 1000.0, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(float, cvg)

    /** Number of red button presses, Unit: presses, Range: 0 / 2147483647, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(int16_t, but0)

    /** Number of green button presses, Unit: presses, Range: 0 / 2147483647, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(int16_t, but1)

    /** Incremental value of dial, Unit: value, Range: -2147483648 / 2147483647, Setter: No, Getter: Yes*/
    CONTROLLED_PROPERTY(int16_t, dial)

    /** Left drive motor encoder pulses, Unit: pulses, Range: -100000000 / 100000000, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(int32_t, enc0)

    /** Right drive motor encoder pulses, Unit: pulses, Range: -100000000 / 100000000, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(int32_t, enc1)

    /** Head tilt motor encoder pulses, Unit: pulses, Range: -100000000 / 100000000, Setter: Yes, Getter: Yes*/
    CONTROLLED_PROPERTY(int32_t, enc2)

    /** but0, but1, dial values, Unit: multiple, Range: See individuals, Setter: No, Getter: Yes*/
    //CONTROLLED_PROPERTY(multiple, button_data)

    /** varius parameter values, Unit: multiple, Range: See individuals, Setter: No, Getter: Yes*/
    //CONTROLLED_PROPERTY(multiple, bulk_data)

    /** Charger/battery data, Unit: multiple, Range: See individuals, Setter: No, Getter: Yes*/
    //CONTROLLED_PROPERTY(multiple, charger_data)

    CONTROL_BIT(v)
    CONTROL_BIT(r)
    CONTROL_BIT(a)
    CONTROL_BIT(p)
    CONTROL_BIT(mode)
    CONTROL_BIT(undock)
    //CONTROL_BIT(home)
    CONTROL_BIT(tilt_homing_state)
    CONTROL_BIT(tilt_angle_from_home)
    CONTROL_BIT(vg)
    CONTROL_BIT(vgr)
    CONTROL_BIT(cdp)
    CONTROL_BIT(cvg)
    CONTROL_BIT(but0)
    CONTROL_BIT(but1)
    CONTROL_BIT(dial)
    CONTROL_BIT(enc0)
    CONTROL_BIT(enc1)
    CONTROL_BIT(enc2)
    //CONTROL_BIT(button_data)
    //CONTROL_BIT(bulk_data)
    //CONTROL_BIT(charger_data)

#ifdef __cplusplus
    /**
    * stuct constructor 
    */       
    wb_giraff_main_serial()
    {
        set_v(0);
        set_r(0);
        set_a(0);
        set_p(0);
        //set_mode();
        set_undock(0);
        //set_home();
        //set_tilt_homing_state();
        set_tilt_angle_from_home(0);
        set_vg(0);
        set_vgr(0);
        set_cdp(0);
        set_cvg(0);
        set_but0(0);
        set_but1(0);
        set_dial(0);
        set_enc0(0);
        set_enc1(0);
        set_enc2(0);
        //set_button_data();
        //set_bulk_data();
        //set_charger_data();
    }
#endif
};

#endif //_wb_giraff_main_serial_h
