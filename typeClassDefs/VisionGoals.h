/* 
 * File:   VisionGoals.h
 * Author: eugene
 *
 * Created on 1 December 2013, 8:02 PM
 */

#ifndef VisionGoals_DEFINED
#define	VisionGoals_DEFINED

#include <SimpleShapes.h>
#include <string>
#include <gu_util.h>
#include "wb_goal.h"

#include "Vision_Control.h"

namespace guWhiteboard {
/**
 * @brief Class to post information about goal posts detected from vision
 * This class contains information the dimension of goal posts. The message 
 * contains information for left and right goal post on top and bottom camera's
 * 
 * Examples
 * --------
 * 
 * Retrieve the current information about the a left goal post in the top camera
 * 
 *		VisionGaols v = VisionGaols_t.get(); //get the goal message off the whiteboard
 *		wb_goal g = v.leftPost(Top); //get the left post from the top camera
 *		bool visible = g.visible(); //get the visibile flag for the post
 *		int x1 = g.outerBottom_X(); //get the outer bottom x coordinate for the post
 */
class VisionGoals {
private:
	wb_goal topLeft;//top camera
	wb_goal topRight;
	wb_goal bottomLeft;//bottom camera
	wb_goal bottomRight;
	unsigned long _frameNumber;
public:
	/**Default Constructor*/
    VisionGoals() : topLeft(), topRight(), bottomLeft(), bottomRight(), _frameNumber(0) {
    }

	/**
	 * @brief String Constructor
	 * Converts a serialized string to a VisionGoal object
     * @param s The String to convert
     */
	VisionGoals(std::string s) {
        from_string(s);
    }

    void from_string(std::string &s)  {
        topLeft = wb_goal();
        topRight = wb_goal();
        bottomLeft = wb_goal();
        bottomRight = wb_goal();
        _frameNumber = 0; 
		
		size_t n = static_cast<size_t>(-8);
		std::string command = "LEFTPOST";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+8);
			if (n!=std::string::npos) {
				std::string t = s.substr(n+command.length()+1);
				wb_goal postInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;
	
				std::vector<std::string> com = components_of_string_separated(t, '(');
				GUPoint<int16_t> outerBottom(com.at(1).c_str());
				GUPoint<int16_t> outerTop(com.at(2).c_str());
				GUPoint<int16_t> innerBottom(com.at(3).c_str());
				GUPoint<int16_t> innerTop(com.at(4).c_str());

				postInfo.set_outerBottom_X(outerBottom.x);
				postInfo.set_outerBottom_Y(outerBottom.y);

				postInfo.set_outerTop_X(outerTop.x);
				postInfo.set_outerTop_Y(outerTop.y);

				postInfo.set_innerBottom_X(innerBottom.x);
				postInfo.set_innerBottom_Y(innerBottom.y);

				postInfo.set_innerTop_X(innerTop.x);
				postInfo.set_innerTop_Y(innerTop.y);

				setLeftGoalPost(postInfo, cam);
			}
		}
		
		n = static_cast<size_t>(-8);
		command = "RIGHTPOST";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+8);
			if (n!=std::string::npos) {
				std::string t = s.substr(n+command.length()+1);
				wb_goal postInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;

				std::vector<std::string> com = components_of_string_separated(t, '(');
				GUPoint<int16_t> outerBottom(com.at(1).c_str());
				GUPoint<int16_t> outerTop(com.at(2).c_str());
				GUPoint<int16_t> innerBottom(com.at(3).c_str());
				GUPoint<int16_t> innerTop(com.at(4).c_str());

				postInfo.set_outerBottom_X(outerBottom.x);
				postInfo.set_outerBottom_Y(outerBottom.y);

				postInfo.set_outerTop_X(outerTop.x);
				postInfo.set_outerTop_Y(outerTop.y);

				postInfo.set_innerBottom_X(innerBottom.x);
				postInfo.set_innerBottom_Y(innerBottom.y);

				postInfo.set_innerTop_X(innerTop.x);
				postInfo.set_innerTop_Y(innerTop.y);

				setRightGoalPost(postInfo, cam);
			}
		}
	}
	/**
	 * @brief Set the left goal post for this VisionGoal message
     * @param postInfo The post information to be set
     * @param camera The camera this post was seen on
     */
	void setLeftGoalPost(wb_goal postInfo, VisionCamera camera) {
		if(camera == Top) {
			topLeft = postInfo;
			topLeft.set_visible(true);
		}
		else {
			bottomLeft = postInfo;
			bottomLeft.set_visible(true);
		}
	}
	
	/**
	 * @brief Set the right goal post for this VisionGoal message
     * @param postInfo The post information to be set
     * @param camera The camera this post was seen on
     */
	void setRightGoalPost(wb_goal postInfo, VisionCamera camera) {
		if(camera == Top) {
			topRight = postInfo;
			topRight.set_visible(true);
		}
		else {
			bottomRight = postInfo;
			bottomRight.set_visible(true);
		}
	}
	
	/**
	 * @brief Get the current left goal post for this message
     * @param camera The camera to get goal post information from
     * @return The goal post information.
     */
	const wb_goal &leftPost(VisionCamera camera) const
	{
		if(camera == Top)
			return topLeft;
		else
			return bottomLeft;
	}
	
	/**
	 * @brief Get the current right goal post for this message
     * @param camera The camera to get goal post information from
     * @return The goal post information.
     */
	const wb_goal &rightPost(VisionCamera camera) const
	{
		if(camera == Top)
			return topRight;
		else
			return bottomRight;
	}
	
	/**
	 * @brief Get the current left goal post for this message
     * @param camera The camera to get goal post information from
     * @return The goal post information.
     */
	wb_goal &leftPost(VisionCamera camera)
	{
		if(camera == Top)
			return topLeft;
		else
			return bottomLeft;
	}
	
	/**
	 * @brief Get the current right goal post for this message
     * @param camera The camera to get goal post information from
     * @return The goal post information.
     */
	wb_goal &rightPost(VisionCamera camera)
	{
		if(camera == Top)
			return topRight;
		else
			return bottomRight;
	}
	
	/**
	 * @brief Reset the visible flag for all four different posts to false
     */
	void Reset() {
		topLeft.set_visible(false);
		topRight.set_visible(false);
		bottomLeft.set_visible(false);
		bottomRight.set_visible(false);
	}
	
	/**
	 * @brief Sets the frame number this information in this message was observed.
     * @param fn The frame number
     */
	void setFrameNumber(unsigned long fn) {
		_frameNumber = fn;
	}
	
	/**
	 * @brief Get the frame number the information in this message was observed.
     * @return The frame number
     */
	unsigned long frameNumber() const {
		return _frameNumber;
	}
	
	/**
	 * @brief Converts this message into a serialized string.
     * @return The serialized string
     */
	std::string description() {
		std::stringstream result;
		
		if(bottomLeft.visible())
			result << "BottomLeftPost:(" << bottomLeft.outerBottom_X() << "," << bottomLeft.outerBottom_Y() << ")("
			<< bottomLeft.outerTop_X() << "," << bottomLeft.outerTop_Y() << ")("
			<< bottomLeft.innerBottom_X() << "," << bottomLeft.innerBottom_Y() << ")("
			<< bottomLeft.innerTop_X() << "," << bottomLeft.innerTop_Y() << ") ";
		if(topLeft.visible())
			result << "TopLeftPost:(" << topLeft.outerBottom_X() << "," << topLeft.outerBottom_Y() << ")("
			<< topLeft.outerTop_X() << "," << topLeft.outerTop_Y() << ")("
			<< topLeft.innerBottom_X() << "," << topLeft.innerBottom_Y() << ")("
			<< topLeft.innerTop_X() << "," << topLeft.innerTop_Y() << ") ";
		if(bottomRight.visible())
			result << "BottomRightPost:(" << bottomRight.outerBottom_X() << "," << bottomRight.outerBottom_Y() << ")("
			<< bottomRight.outerTop_X() << "," << bottomRight.outerTop_Y() << ")("
			<< bottomRight.innerBottom_X() << "," << bottomRight.innerBottom_Y() << ")("
			<< bottomRight.innerTop_X() << "," << bottomRight.innerTop_Y() << ") ";
		if(topRight.visible())
			result << "TopRightPost:(" << topRight.outerBottom_X() << "," << topRight.outerBottom_Y() << ")("
			<< topRight.outerTop_X() << "," << topRight.outerTop_Y() << ")("
			<< topRight.innerBottom_X() << "," << topRight.innerBottom_Y() << ")("
			<< topRight.innerTop_X() << "," << topRight.innerTop_Y() << ") ";
		return result.str();
	}
	
};
}

#endif	/* VisionGoals_DEFINED */

