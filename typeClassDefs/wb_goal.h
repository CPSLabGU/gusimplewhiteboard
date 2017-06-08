#ifndef WBGOAL_
#define WBGOAL_

#include <sys/types.h>
#include <gu_util.h>

/**
 * Whiteboard structure for goal coordinates
 */
struct wb_goal
{
	/**The x,y coordinates of the outer bottom corner of the post*/
	PROPERTY(int16_t, outerBottom_X)
	/**The x,y coordinates of the outer bottom corner of the post*/
	PROPERTY(int16_t, outerBottom_Y)

	/**The x,y coordinates of the outer top corner of the post*/
	PROPERTY(int16_t, outerTop_X)
	/**The x,y coordinates of the outer top corner of the post*/
	PROPERTY(int16_t, outerTop_Y)

	/**The x,y coordinates of the inner bottom corner of the post*/
	PROPERTY(int16_t, innerBottom_X)
	/**The x,y coordinates of the inner bottom corner of the post*/
	PROPERTY(int16_t, innerBottom_Y)

	/**The x,y coordinates of the inner Top corner of the post*/
	PROPERTY(int16_t, innerTop_X)
	/**The x,y coordinates of the inner Top corner of the post*/
	PROPERTY(int16_t, innerTop_Y)

	/**Whether this post was sighted in the frame*/
    PROPERTY(bool, visible)
	/**Explicit padding*/
	PROPERTY(bool, pad)                         ///< align to 16 bits
#ifdef __cplusplus
	/**Default Constructor*/
	wb_goal() : _outerBottom_X(0), _outerBottom_Y(0), _outerTop_X(0), _outerTop_Y(0), _innerBottom_X(0), _innerBottom_Y(0), _innerTop_X(0), _innerTop_Y(0), _visible(false), _pad(false) {}
#endif
};

#endif
