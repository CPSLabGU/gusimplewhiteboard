/*
 *  guudpbridgenetworkutil.cpp
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */

#include "guudpUtil.h"



int my_udp_id = -1;

int get_udp_id()
{
    return my_udp_id;
}

void set_udp_id(int udp_id)
{
    my_udp_id = udp_id;
}



static WBMsg getWBMsg(gu_simple_message *m)
{
    switch (m->wbmsg.type)
    {
        case WBMsg::TypeBool:
            return WBMsg((bool)m->sint);
            
        case WBMsg::TypeInt:
            return WBMsg(m->sint);
            
        case WBMsg::TypeFloat:
            return WBMsg(m->sfloat);
            
        case WBMsg::TypeString:
            return WBMsg(m->wbmsg.data);
            
        case WBMsg::TypeBinary:
            return WBMsg(m->wbmsg.data, m->wbmsg.len);
            
        case WBMsg::TypeArray:
        {
            std::vector<int> *v = new std::vector<int>();
            for (int i = 0; i < m->wbmsg.len; i++)
                v->push_back(m->ivec[i]);
            return WBMsg(*v, true);
        }
        default:
            return WBMsg();
    }
    /* NOTREACHED */
}

static void printWBMsg(std::string dataName, WBMsg *value)
{
	std::ostringstream out;
	switch ((int)value->getType()) 
	{
		case WBMsg::TypeBool:
		{
			out << (int)value->getBoolValue();
			break;
		}
		case WBMsg::TypeInt:
		{
			out << value->getIntValue();
			break;
		}
		case WBMsg::TypeFloat:
		{
			out << value->getFloatValue();
			break;
		}
		case WBMsg::TypeString:
		{
			out << value->getStringValue();
			break;
		}
		case WBMsg::TypeArray:
        {
            const std::vector<int> &vec = value->getArrayValue();
            int n = vec.size();
            out << "( ";
            for (int i = 0; i < n; i++)
            {
                out << vec[i];
                if (i < n-1) out << ", ";
            }
            out << " )";
        }
		default:
		{
			break;
		}
	}
	printf("Type: \t%s\t\tValue:\t%s\n", (char *)dataName.c_str(), (char *)out.str().c_str());
}


static u_int32_t hash_of(const char *s)
{
    u_int32_t hash = *s;
    while (*s++)
    {
        u_int32_t stir = hash & 0xf8000000U;
        hash &= 0x07ffffffU;
        hash <<= 5;
        hash ^= stir >> 27;
        hash ^= *s;
    }
    return hash;
}


static u_int32_t alt_hash(const char *s)
{
    u_int32_t hash = *s;
    while (*s++)
    {
        hash &= 0x0fffffffU;
        hash <<= 4;
        hash += *s;
        u_int32_t stir = hash & 0xf0000000U;
        if (stir != 0)
        {
            hash ^= stir >> 24;
            hash ^= stir;
        }
    }
    hash |= 1;              // needs to be an odd number
    
    return hash;
}

int gsw_hash_for_message_type(gu_simple_whiteboard_descriptor *wbd, const char *name)
{
    gu_simple_whiteboard *wb = wbd->wb;
    unsigned offs = hash_of(name) % GSW_TOTAL_MESSAGE_TYPES;
    gu_simple_message *type; // = &wb->hashes[offs];
    for (int i = 0; i < GSW_TOTAL_MESSAGE_TYPES; i++)
    {
        type = &wb->hashes[offs];
        if (!*type->hash.string)                        // new message type?
            return -1;
        if (strcmp(type->hash.string, name) == 0)
            return offs;
        /* hash collision, add to the offset */
        offs += alt_hash(name);
        offs %= GSW_TOTAL_MESSAGE_TYPES;
    }
    
    fprintf(stderr, "Cannot get offset for message type '%s': hash table full (%d entries)\n", name, wb->num_types);
    
    return -1;
}


void convWBMsgToSimpleMsg(WBMsg *value, gsw_simple_message *m)
{
        m->wbmsg.type = value->getType();
        switch (m->wbmsg.type)
        {
                case WBMsg::TypeEmpty:
                        m->wbmsg.len = 0;
                        break;
                        
                case WBMsg::TypeBool:
                        m->wbmsg.len = sizeof(int);
                        m->sint = value->getBoolValue();
                        break;
                        
                case WBMsg::TypeInt:
                        m->wbmsg.len = sizeof(int);
                        m->sint = value->getIntValue();
                        break;
                        
                case WBMsg::TypeFloat:
                        m->wbmsg.len = sizeof(float);
                        m->sfloat = value->getFloatValue();
                        break;
                        
                case WBMsg::TypeString:
                        gu_strlcpy(m->wbmsg.data, value->getStringValue().c_str(), sizeof(m->wbmsg.data));
                        m->wbmsg.len = strlen(m->wbmsg.data) + 1;
                        break;
                        
                case WBMsg::TypeArray:
                {
                        int k = 0;
                        for (std::vector<int>::const_iterator i = value->getArrayValue().begin(); i < value->getArrayValue().end(); i++)
                                m->ivec[k++] = *i;
                        m->wbmsg.len = k;
                        break;
                }
                case WBMsg::TypeBinary:
                {
                        int len = value->getSizeInBytes();
                        if (len > sizeof(m->wbmsg.data)) len = sizeof(m->wbmsg.data);
                        m->wbmsg.len = len;
                        if (len) memcpy(m->wbmsg.data, value->getBinaryValue(), len);
                        break;
                }
        }
}

//https://developer.apple.com/library/mac/#documentation/General/Conceptual/ConcurrencyProgrammingGuide/GCDWorkQueues/GCDWorkQueues.html
dispatch_source_t CreateDispatchTimer(timespec *when,
                                      uint64_t interval,
                                      uint64_t leeway,
                                      dispatch_queue_t queue,
                                      void (*function)(void *),
                                      void *data)
{
    dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER,
                                                     0, 0, queue);
    if (timer)   
    {
        dispatch_set_context(timer, data);
        //        dispatch_source_set_timer(timer, dispatch_time(DISPATCH_TIME_NOW, secToWait * NSEC_PER_SEC), interval, leeway);
        dispatch_source_set_timer(timer, dispatch_walltime(when, 0), interval, leeway);
        dispatch_source_set_event_handler_f(timer, function);
        dispatch_resume(timer);
    }
    return timer;
}
