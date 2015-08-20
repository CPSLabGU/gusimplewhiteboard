//
//  wb_microwave_status.h
//  gusimplewhiteboard
//
//  Created by Josh Stover on 17/08/2015.
//  Copyright (c) 2015 ICT. All rights reserved.
//

#ifndef wb_microwave_status_h
#define wb_microwave_status_h

#include <gu_util.h>

/**
 * Microwave status properties.
 */
struct wb_microwave_status
{
    // time remaining counter
    PROPERTY(uint16_t, time_count)
    
    // door open boolean
    BIT_PROPERTY(door_open)
    
    // button pushed boolean
    BIT_PROPERTY(button_pushed)
    
#ifdef __cplusplus
    wb_microwave_status(int16_t time = 0) :
        _time_count(time),
        _door_open(false),
        _button_pushed(false)
    {}
#endif
    
};


#endif /* wb_microwave_status_h */
