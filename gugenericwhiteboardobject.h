/*
 *  gugenericwhiteboardobject.h
 *
 *  Created by Carl Lusty in 2013.
 *  Copyright (c) 2013 Carl Lusty
 *  All rights reserved.
 */

#ifndef GENERIC_WB_OBJ_H
#define GENERIC_WB_OBJ_H


#include "gusimplewhiteboard.h"
#include <iostream>
#include <assert.h>

extern gu_simple_whiteboard_descriptor *local_whiteboard_descriptor;

template <class object_type> class generic_whiteboard_object
{
        uint16_t type_offset;
        bool atomic;
        bool notify_subscribers;
        gu_simple_whiteboard_descriptor *_wbd;
        
public:
        generic_whiteboard_object(gu_simple_whiteboard_descriptor *wbd, uint16_t toffs, bool want_atomic = true, bool do_notify_subscribers = true) //Constructor
        {
                if(!wbd)
                {
			wbd = get_local_singleton_whiteboard();
                }
                type_offset = toffs;
                atomic = want_atomic;
                notify_subscribers = do_notify_subscribers;
                _wbd = wbd;
        }

        void set(const object_type &msg);

        object_type &get()
        {
                return *(object_type *)gsw_current_message(_wbd->wb, type_offset);
        }

        object_type get_from(gu_simple_message *msg);
        

        //operators not working yet
//        void operator=(const object_type &value)
//        {
//                set(value);
//        }
//
//        void operator=(object_type value)
//        {
//                set(value);
//        }
//        
//
//        operator object_type()
//        {
//                return *get();
//        }
};

template <typename object_type>
object_type generic_whiteboard_object<object_type>::get_from(gu_simple_message *msg)
{
        return *(object_type *)msg;
}


template <class object_type>
void generic_whiteboard_object<object_type>::set(const object_type &msg)
{
        int t = type_offset;
        
#ifdef DEBUG
        assert(GU_SIMPLE_WHITEBOARD_BUFSIZE >= sizeof(object_type));
#endif
        if (atomic) gsw_procure(_wbd->sem, GSW_SEM_PUTMSG);
        
        gu_simple_whiteboard *wb = _wbd->wb;
        gu_simple_message *m = gsw_next_message(wb, t);
        object_type *wbobj = (object_type*)(m);
        *wbobj = msg;
        
        gsw_increment(wb, t);
        gsw_increment_event_counter(wb, t);
        if (atomic) gsw_vacate(_wbd->sem, GSW_SEM_PUTMSG);
        if (notify_subscribers && wb->subscribed) gsw_signal_subscribers(wb);
}





#endif //GENERIC_WB_OBJ_H
