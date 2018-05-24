#ifndef WB_FILTERED_VISION_BALL_TYPE_H
#define WB_FILTERED_VISION_BALL_TYPE_H

#include <sys/types.h>

/************************ 
            enum to index the cameras
         */

enum FilteredVisionObjectType  //: int32_t
{       FVOBallTop =0, ///< Filtered information ball on top camera
        FVOBallBottom =1,  ///< Filtered information ball on bottom camera
        FVO_NUM_CAMERAS = 2 ///< number of different cameras
};

#endif //	WB_FILTERED_VISION_BALL_TYPE_H
