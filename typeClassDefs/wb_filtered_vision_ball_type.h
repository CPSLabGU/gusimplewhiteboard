#ifndef WB_FILTERED_VISION_BALL_TYPE_H
#define WB_FILTERED_VISION_BALL_TYPE_H

#include <sys/types.h>

/************************ For some strange reasong the
        Hexapod models starts numebring legs from zero
        but the joitns from 1 */

enum FILTERED_VISION_BALL_TYPE  //: int32_t
{       FVOBallTop =0, ///< Filtered informaiton ball on top camera
        FVOBallBottom =1,  ///< Filtered informaiton ball on bottom camera
        FVO_NUM_CAMERAS = 2 ///< number of different cameras
};

#endif //	WB_FILTERED_VISION_BALL_TYPE_H
