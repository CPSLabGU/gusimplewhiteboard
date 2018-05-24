#ifndef WB_FILTERED_VISION_OBJECT_TYPE_H
#define WB_FILTERED_VISION_OBJECT_TYPE_H

#include <sys/types.h>

/************************ For some strange reasong the
        Hexapod models starts numebring legs from zero
        but the joitns from 1 */

enum FILTERED_VISION_OBJECT_TYPE  //: int32_t
{       FVOGoalPostTop =0, ///< Filtered information for a post we cannot tell is Left or right
        FVOGoalPostLeftTop =1,  ///< Filtered information for a post we know is Left
        FVOGoalPostRightTop =2, ///< Filtered information for a post we know is right
        FVOGoalCrossBarTop =3, ///< Filtered information for the cross BAR
        FVO_NUM_OBJECTS = 4 ///< number of different kind of objects
};

#endif //	WB_FILTERED_VISION_OBJECT_TYPE_H
