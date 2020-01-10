/**
 *  /file guWhiteboard_gugenericwhiteboardobject.h
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2018 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

#ifndef GUWHITEBOARD_GUGENERICWHITEBOARDOBJECT_H
#define GUWHITEBOARD_GUGENERICWHITEBOARDOBJECT_H

/** Auto-generated, don't modify! */

#include "gugenericwhiteboardobject.h"

//Prototype for custom singleton whiteboard methods.
gu_simple_whiteboard_descriptor *get_guWhiteboard_singleton_whiteboard(void);

template <class object_type> class guWhiteboard_generic_whiteboard_object : public generic_whiteboard_object<object_type>
{
public:
    /**                                                                                                                   
     * designated constructor
    */
    guWhiteboard_generic_whiteboard_object(gu_simple_whiteboard_descriptor *wbd, uint16_t toffs, bool want_atomic = true, bool do_notify_subscribers = true) : generic_whiteboard_object<object_type>(wbd, toffs, want_atomic, do_notify_subscribers)
    {

    }

    /**
     * value conversion reference constructor
    */
    guWhiteboard_generic_whiteboard_object(const object_type &value, uint16_t toffs, gu_simple_whiteboard_descriptor *wbd = NULLPTR, bool want_atomic = true) : generic_whiteboard_object<object_type>(value, toffs, wbd, want_atomic)
    {

    }

    /**
     * intialiser (called from constructors)
     * This is specific to a custom whiteboard, this way the default singleton whiteboard is correct.
    */
    void init(uint16_t toffs, gu_simple_whiteboard_descriptor *wbd = NULLPTR, bool want_atomic = true, bool do_notify_subscribers = true)
    {
        if(!wbd)
        {
            wbd = get_guWhiteboard_singleton_whiteboard();
        }
        this->type_offset = toffs;
        this->atomic = want_atomic;
        this->notify_subscribers = do_notify_subscribers;
        this->_wbd = wbd;
    }
};

#endif //GUWHITEBOARD_GUGENERICWHITEBOARDOBJECT_H
