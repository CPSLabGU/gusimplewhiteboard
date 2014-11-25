#ifndef _WBGOAL_
#define _WBGOAL_

#include <sys/types.h>
#include <gu_util.h>
#include <SimpleShapes.h>

struct wb_goal
{
	/**The x,y coordinates of the outer bottom corner of the post*/
	PROPERTY(GUPoint<int16_t>, outerBottom)
	/**The x,y coordinates of the outer top corner of the post*/
	PROPERTY(GUPoint<int16_t>, outerTop)
	/**The x,y coordinates of the inner bottom corner of the post*/
	PROPERTY(GUPoint<int16_t>, innerBottom)
	/**The x,y coordinates of the inner Top corner of the post*/
	PROPERTY(GUPoint<int16_t>, innerTop)
	/**Whether this post was sighted in the frame*/
    PROPERTY(bool, visible)
	/**Explicit padding*/
	PROPERTY(bool, pad)                         ///< align to 16 bits
#ifdef __cplusplus
	/**Default Constructor*/
	wb_goal() : _outerBottom(), _outerTop(), _innerBottom(), _innerTop(), _visible(false), _pad(false) {}
#endif
};

#endif
