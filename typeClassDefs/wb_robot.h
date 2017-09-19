#ifndef WBROBOT_
#define WBROBOT_

#include <sys/types.h>
#include <gu_util.h>

/**
 * Whiteboard structure for robot coordinates
 * X and Y coordinates are posted as seen in the image
 * X ranges between [-320,319] (from left to right)
 * Y ranges between [-240,239] (from bottom to top)
 */
struct wb_robot
{
	/**The x,y coordinates of the bottom left corner of the post*/
	PROPERTY(int16_t, bottomLeft_X)
	/**The x,y coordinates of the bottom left corner of the post*/
	PROPERTY(int16_t, bottomLeft_Y)

	/**The x,y coordinates of the top left corner of the post*/
	PROPERTY(int16_t, topLeft_X)
	/**The x,y coordinates of the top left corner of the post*/
	PROPERTY(int16_t, topLeft_Y)

	/**The x,y coordinates of the bottom right corner of the post*/
	PROPERTY(int16_t, bottomRight_X)
	/**The x,y coordinates of the bottom right corner of the post*/
	PROPERTY(int16_t, bottomRight_Y)

	/**The x,y coordinates of the Top right corner of the post*/
	PROPERTY(int16_t, topRight_X)
	/**The x,y coordinates of the Top right corner of the post*/
	PROPERTY(int16_t, topRight_Y)

	/**Whether this post was sighted in the frame*/
    PROPERTY(bool, visible)
	/**Explicit padding*/
	PROPERTY(bool, pad)                         ///< align to 16 bits
#ifdef __cplusplus
	/**Default Constructor*/
	wb_robot() : _bottomLeft_X(0), _bottomLeft_Y(0), _topLeft_X(0), _topLeft_Y(0), _bottomRight_X(0), _bottomRight_Y(0), _topRight_X(0), _topRight_Y(0), _visible(false), _pad(false) {}
#endif
};

#endif
