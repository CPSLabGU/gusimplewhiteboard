//Currently faked



/*
 *  guwhiteboardtypelist_generated.h
 *
 *  Created by Carl Lusty in 2013.
 *  Copyright (c) 2013 Carl Lusty
 *  All rights reserved.
 */


#ifndef _GUGENERICWHITEBOARDOBJECT_H_
#define _GUGENERICWHITEBOARDOBJECT_H_

#include "create_map.h" //std::map template creation shorthand

namespace guWhiteboard
{
        typedef enum wb_types
        {
                wb_reserved_SubscribeToAllTypes = 1, //used for the global subscriptions, don't add to this type
                kNaoRun = 12,
                kNaoIsRunning = 56,
                kNaoIsReadyToRun = 82
        } WBTypes;
        
        static std::map<int, int> mymap = create_map<int, int >(1,2)(3,4)(5,6);
        
        const std::string WBTypes_stringValues[] = {
                "US/Left/Sensor/Value",
                "US/Left/Sensor/Value1",
                "US/Left/Sensor/Value2",
                "US/Left/Sensor/Value3",
                "US/Left/Sensor/Value4",
                "US/Left/Sensor/Value5",
                "US/Left/Sensor/Value6",
                "US/Left/Sensor/Value7",
                "US/Left/Sensor/Value8",
                "US/Left/Sensor/Value9",
                "US/Right/Sensor/Value",
                "US/Right/Sensor/Value1",
                "US/Right/Sensor/Value2",
                "US/Right/Sensor/Value3",
                "US/Right/Sensor/Value4",
                "US/Right/Sensor/Value5",
                "US/Right/Sensor/Value6",
                "US/Right/Sensor/Value7",
                "US/Right/Sensor/Value8",
                "US/Right/Sensor/Value9"
        };
}

#endif // _GUGENERICWHITEBOARDOBJECT_H_
