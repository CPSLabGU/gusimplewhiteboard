/* 
 * File:   wb_lines.h
 * Author: eugene
 *
 * Created on 22 July 2014, 2:12 PM
 */

#ifndef WB_LINES_H
#define	WB_LINES_H

#include "wb_point2D.h"
	
/**
 * @brief Simple struct to store information for a line
 */
struct wb_line {
	/**Start coordinates of the line*/
	PROPERTY(struct wb_point2D, start)
	/**End Coordinates of the line*/
	PROPERTY(struct wb_point2D, end)
	PROPERTY(uint8_t, startThickness)
	PROPERTY(uint8_t, endThickness)
#ifdef __cplusplus
	/**Default Constructor*/
	wb_line() : _start(), _end() {}
#endif
};
	
/**
 * @brief struct to store information about lines found in a frame processed by vision
 */
struct wb_lines {
	/**The frame number these lines were found in*/
	PROPERTY(uint64_t, frameNumber)
	/**Array of lines found in the top camera in this frame*/
	ARRAY_PROPERTY(struct wb_line, topLines, 5)
	/**Array of lines found in the top camera in this frame*/
	ARRAY_PROPERTY(struct wb_line, bottomLines, 5)
	/**
	 * @brief Mask for lines seen in top camera
	 * first bit represent visibility of first line in the array. Last two bits unused
	 */
	PROPERTY(int8_t, topMask)
	/**
	 * @brief Mask for lines seen in bottom camera
	 * first bit represent visibility of first line in the array. Last two bits unused
	 */
	PROPERTY(int8_t, bottomMask)
#ifdef __cplusplus
	/**Default Constructor*/
	wb_lines() : _frameNumber(0), _topMask(0), _bottomMask(0) {}
#endif
};


#endif	/* WB_LINES_H */

