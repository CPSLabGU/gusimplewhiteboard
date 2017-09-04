/* 
 * File:   VisionLines.h
 * Author: eugene
 *
 * Created on 1 December 2013, 8:02 PM
 */

#ifndef VisionLines_DEFINED
#define	VisionLines_DEFINED

#include <vector>
#include <string>
#include <SimpleShapes.h>

#include "wb_lines.h"
#include "Vision_Control.h"

namespace guWhiteboard {
/**
 * @brief Class to post information about field lines detected from vision
 * This message contains information about up to 6 lines detected in the top and
 * bottom camera's
 * 
 * Examples
 * --------
 * 
 * Retrieve the current information about the a left goal post in the top camera
 * 
 *		VisionGaols v = VisionGaols_t.get(); //get the goal message off the whiteboard
 *		wb_goal g = v.leftPost(Top); //get the left post from the top camera
 *		bool visible = g.visible(); //get the visibile flag for the post
 *		int x1 = g.outerBottom().x; //get the outer bottom x coordinate for the post
 */
class VisionLines : public wb_lines {
public:
	/**Default Constructor*/
    VisionLines() : wb_lines() {}
	
	
	/**
	 * @brief String Constructor. NYI!!
     * @param s The serialized string to convert
     */
	VisionLines(std::string s) : wb_lines() {
            (void)s;
		//NYI
	}

	void from_string(std::string s)   {
            (void)s;
		//NYI
	}
	
	
	/**
	 * @brief Add a line to the message.
     * @param line The line to add
     * @param camera The camera the line was seen on
     * @return true if the line was successfully added, false if all 6 elements in the array are already used
     */
	bool addLine(const wb_line &line, VisionCamera camera) {
		for (int i = 0; i<5; ++i) {
			if(camera == Top) {
				if(!(topMask() & (1 << i))) {
					set_topLines(line, i);
					set_topMask(static_cast<int8_t>(topMask() | (1 << i)));
					return true;
				}	
			}
			else {
				if(!(bottomMask() & (1 << i))) {
					set_bottomLines(line, i);
					set_bottomMask(static_cast<int8_t>(bottomMask() | (1 << i)));
					return true;
				}
			}
		}
		return false;
	}
	
	/**
	 * @brief Get the top lines in this message
	 * Finds the elements in the top lines array that are visible and add them to a vector
     * @return The vector of visible lines
     */
	std::vector<wb_line> topLines() const {
		std::vector<wb_line> result;
		for(int i = 0; i<5; ++i) {
			if(topMask() & (1 << i)) {
				result.push_back(wb_lines::topLines(i));
			}
		}
		return result;
	}
	
	/**
	 * @brief Get the bottom lines in this message
	 * Finds the elements in the bottom lines array that are visible and add them to a vector
     * @return The vector of visible lines
     */
	std::vector<wb_line> bottomLines() const {
		std::vector<wb_line> result;
		for(int i = 0; i<5; ++i) {
			if(bottomMask() & (1 << i)) {
				result.push_back(wb_lines::bottomLines(i));
			}
		}
		return result;
	}
    
	/**Set all the visible flags for the top and bottom lines array to false*/
	void reset() {
		set_topMask(0);
		set_bottomMask(0);
	}
	
	/**
	 * @brief Convert the line message into a serialized string
     * @return The serialized string
     */
	std::string description() const {
		std::stringstream result;
		result << topLines().size() << "," << bottomLines().size();
		return result.str();
	}
	
};
}

#endif	/* VisionBall_DEFINED */
