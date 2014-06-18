//
//  wb_arrayoffilteredvisionobjects.h
//  gusimplewhiteboard
//
//  Created by Vlad Estivill-Castro on 18/06/2014.
//  Copyright (c) 2014 ICT. All rights reserved.
//

#ifndef gusimplewhiteboard_wb_arrayoffilteredvisionobjects_h
#define gusimplewhiteboard_wb_arrayoffilteredvisionobjects_h

#include "wb_filteredvisionobject.h"


/**
 * Discriminate sigthings
 */
enum FilteredVisionObjectType
{
        FVOGoalPost,          ///< Filtered informaiton for a post we cannot tell is Left or right
        FVOGoalPostLeft,          ///< Filtered informaiton for a post we know is Left
        FVOGoalPostRight,          ///< Filtered informaiton for a post we know is right
        FVOGoalCrossBar,          ///< Filtered informaiton for the Ball
        FVO_NUM_OBJECTS          ///< number of different kind of objects
};

struct wb_arrayoffilteredvisionobjects
{
     struct wb_filteredvisionobject    _objects[FVO_NUM_OBJECTS];
};


#endif
