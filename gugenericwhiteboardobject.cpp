/*
 *  gugenericwhiteboardobject.cpp
 *
 *  Created by Carl Lusty in 2013.
 *  Copyright (c) 2013 Carl Lusty
 *  All rights reserved.
 */

#include "gugenericwhiteboardobject.h"
#include <gu_util.h>

/** 
 * @brief Generic object method for setting data into a specific whiteboard type. string specialisation 
 * @param msg The data to set into the whiteboard
 */
template <>
void generic_whiteboard_object<std::string>::set(const std::string &msg)
{
        int t = type_offset;
        
#ifndef NO_SAFETY
        assert(GU_SIMPLE_WHITEBOARD_BUFSIZE > msg.length());
#endif
        if (atomic) gsw_procure(_wbd->sem, GSW_SEM_PUTMSG);
        
        gu_simple_whiteboard *wb = _wbd->wb;
        gu_simple_message *m = gsw_next_message(wb, t);
        
        gu_strlcpy(m->string, msg.c_str(), msg.length()+1);
        
        gsw_increment(wb, t);
        gsw_increment_event_counter(wb, t);
        if (atomic) gsw_vacate(_wbd->sem, GSW_SEM_PUTMSG);
        if (notify_subscribers && wb->subscribed) gsw_signal_subscribers(wb);
}

/** 
 * @brief Generic object method for setting data into a specific whiteboard type. vector<int> specialisation 
 * @param msg The data to set into the whiteboard
 */
template <>
void generic_whiteboard_object<std::vector<int> >::set(const std::vector<int> &msg)
{
        int t = type_offset;
        
#ifndef NO_SAFETY
        assert(GU_SIMPLE_WHITEBOARD_BUFSIZE >= (msg.size()*sizeof(int)));
#endif
        if (atomic) gsw_procure(_wbd->sem, GSW_SEM_PUTMSG);
        
        gu_simple_whiteboard *wb = _wbd->wb;
        gu_simple_message *m = gsw_next_message(wb, t);
        
        memcpy(m->ivec, &msg[0], msg.size()*sizeof(int));
        
        gsw_increment(wb, t);
        gsw_increment_event_counter(wb, t);
        if (atomic) gsw_vacate(_wbd->sem, GSW_SEM_PUTMSG);
        if (notify_subscribers && wb->subscribed) gsw_signal_subscribers(wb);
}

/** 
 * @brief Generic object method for setting data into a specific whiteboard type. vector<bool> specialisation 
 * @param msg The data to set into the whiteboard
 */
template <>
void generic_whiteboard_object<std::vector<bool> >::set(const std::vector<bool> &msg)
{
        int t = type_offset;
        
#ifndef NO_SAFETY
        assert(GU_SIMPLE_WHITEBOARD_BUFSIZE >= (msg.size()*sizeof(bool)));
#endif
        if (atomic) gsw_procure(_wbd->sem, GSW_SEM_PUTMSG);
        
        gu_simple_whiteboard *wb = _wbd->wb;
        gu_simple_message *m = gsw_next_message(wb, t);
        
        //The STL vector specialisation for bool may not store an array of bools, it may be bits.
        //http://www.cplusplus.com/reference/vector/vector-bool/
        //That's why this loops instead of doing a memcpy
        for(size_t i = 0; i < msg.size(); i++)
            m->bvec[i] = msg.at(i); 
        
        gsw_increment(wb, t);
        gsw_increment_event_counter(wb, t);
        if (atomic) gsw_vacate(_wbd->sem, GSW_SEM_PUTMSG);
        if (notify_subscribers && wb->subscribed) gsw_signal_subscribers(wb);
}

/** 
 * @brief Generic object method for unwrapping data from the underlying whiteboard storage union. string specialisation 
 * @param msg The union pointer
 * @return The unwrapped data in the template type
 */
template<>
std::string generic_whiteboard_object<std::string>::get_from(gu_simple_message *msg)
{
        return msg->string;
}

/** 
 * @brief Generic object method for unwrapping data from the underlying whiteboard storage union. vector<int> specialisation 
 * @param msg The union pointer
 * @return The unwrapped data in the template type
 */
template<>
std::vector<int> generic_whiteboard_object<std::vector<int> >::get_from(gu_simple_message *msg)
{
        return std::vector<int> (msg->ivec, msg->ivec + sizeof msg->ivec / sizeof msg->ivec[0]);
}

/** 
 * @brief Generic object method for unwrapping data from the underlying whiteboard storage union. vector<bool> specialisation 
 * @param msg The union pointer
 * @return The unwrapped data in the template type
 */
template<>
std::vector<bool> generic_whiteboard_object<std::vector<bool> >::get_from(gu_simple_message *msg)
{
        return std::vector<bool> (msg->bvec, msg->bvec + sizeof msg->bvec / sizeof msg->bvec[0]);
}
