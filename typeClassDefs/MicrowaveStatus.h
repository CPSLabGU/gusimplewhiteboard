//
//  MicrowaveStatus.h
//  gusimplewhiteboard
//
//  Created by Josh Stover on 17/08/2015.
//  Copyright (c) 2015 ICT. All rights reserved.
//

#ifndef MicrowaveStatus_DEFINED
#define MicrowaveStatus_DEFINED


#include "wb_microwave_status.h"
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

namespace guWhiteboard
{
    /**
     * Class for controlling and getting the status of a simple microwave.
     */
    class MicrowaveStatus: public wb_microwave_status
    {
    public:
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /** string constructor */
        MicrowaveStatus(const std::string &state): wb_microwave_status() { from_string(state); }
        
        /** convert to a string */
        std::string description() const
        {
            std::ostringstream ss;
            ss << door_open() << ",";
            ss << button_pushed() << ",";
            ss << time_count();
            return ss.str();
        }
        
        /** convert from a string */
        void from_string(const std::string &str)
        {
            std::vector<std::string> msg = components_of_string_separated(str, ',', true);
            //if (msg.size()!=3) return;
            
            set_door_open(static_cast<uint16_t>(msg.size())); // TODO
            set_button_pushed(false); //TODO
            set_time_count(atou16(msg[2].c_str()));
        }
#endif
    };
}

#endif /* MicrowaveStatus_DEFINED */
