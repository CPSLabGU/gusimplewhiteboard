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
#include <sstream>
#include <gu_util.h>
#include "wb_goal.h"

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
    wb_goal topGeneric;
	wb_goal bottomLeft;//bottom camera
    wb_goal bottomRight;
    wb_goal bottomGeneric;
	size_t _frameNumber;
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
				GUPoint<int16_t> _bottomLeft(com.at(1).c_str());
				GUPoint<int16_t> _topLeft(com.at(2).c_str());
				GUPoint<int16_t> _bottomRight(com.at(3).c_str());
				GUPoint<int16_t> _topRight(com.at(4).c_str());

				postInfo.set_bottomLeft_X(_bottomLeft.x);
				postInfo.set_bottomLeft_Y(_bottomLeft.y);

				postInfo.set_topLeft_X(_topLeft.x);
				postInfo.set_topLeft_Y(_topLeft.y);

				postInfo.set_bottomRight_X(_bottomRight.x);
				postInfo.set_bottomRight_Y(_bottomRight.y);

				postInfo.set_topRight_X(_topRight.x);
				postInfo.set_topRight_X(_topRight.y);

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
                GUPoint<int16_t> _bottomLeft(com.at(1).c_str());
                GUPoint<int16_t> _topLeft(com.at(2).c_str());
                GUPoint<int16_t> _bottomRight(com.at(3).c_str());
                GUPoint<int16_t> _topRight(com.at(4).c_str());
                
                postInfo.set_bottomLeft_X(_bottomLeft.x);
                postInfo.set_bottomLeft_Y(_bottomLeft.y);
                
                postInfo.set_topLeft_X(_topLeft.x);
                postInfo.set_topLeft_Y(_topLeft.y);
                
                postInfo.set_bottomRight_X(_bottomRight.x);
                postInfo.set_bottomRight_Y(_bottomRight.y);
                
                postInfo.set_topRight_X(_topRight.x);
                postInfo.set_topRight_Y(_topRight.y);

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
     * @brief Set the generic goal post for this VisionGoal message
     * @param postInfo The post information to be set
     * @param camera The camera this post was seen on
     */
    void setGenericGoalPost(wb_goal postInfo, VisionCamera camera) {
        if(camera == Top) {
            topGeneric = postInfo;
            topGeneric.set_visible(true);
        }
        else {
            bottomGeneric = postInfo;
            bottomGeneric.set_visible(true);
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
     * @brief Get the current generic goal post for this message
     * @param camera The camera to get goal post information from
     * @return The goal post information.
     */
    const wb_goal &genericPost(VisionCamera camera) const
    {
        if(camera == Top)
            return topGeneric;
        else
            return bottomGeneric;
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
     * @brief Get the current generic goal post for this message
     * @param camera The camera to get goal post information from
     * @return The goal post information.
     */
    wb_goal &genericPost(VisionCamera camera)
    {
        if(camera == Top)
            return topGeneric;
        else
            return bottomGeneric;
    }
	
	/**
	 * @brief Reset the visible flag for all four different posts to false
     */
	void Reset() {
		topLeft.set_visible(false);
        topRight.set_visible(false);
        topGeneric.set_visible(false);
		bottomLeft.set_visible(false);
        bottomRight.set_visible(false);
        bottomGeneric.set_visible(false);
	}
	
	/**
	 * @brief Sets the frame number this information in this message was observed.
     * @param fn The frame number
     */
	void setFrameNumber(size_t fn) {
		_frameNumber = fn;
	}
	
	/**
	 * @brief Get the frame number the information in this message was observed.
     * @return The frame number
     */
	size_t frameNumber() const {
		return _frameNumber;
	}
	
	/**
	 * @brief Converts this message into a serialized string.
     * @return The serialized string
     */
	std::string description() {
		std::stringstream result;
		
		if(bottomLeft.visible())
			result << "BottomLeftPost:(" << bottomLeft.bottomLeft_X() << "," << bottomLeft.bottomLeft_Y() << ")("
			<< bottomLeft.topLeft_X() << "," << bottomLeft.topLeft_Y() << ")("
			<< bottomLeft.bottomRight_X() << "," << bottomLeft.bottomRight_Y() << ")("
			<< bottomLeft.topRight_X() << "," << bottomLeft.topRight_Y() << ") ";
		if(topLeft.visible())
			result << "TopLeftPost:(" << topLeft.bottomLeft_X() << "," << topLeft.bottomLeft_Y() << ")("
			<< topLeft.topLeft_X() << "," << topLeft.topLeft_Y() << ")("
			<< topLeft.bottomRight_X() << "," << topLeft.bottomRight_Y() << ")("
            << topLeft.topRight_X() << "," << topLeft.topRight_Y() << ") ";
        if(topGeneric.visible())
            result << "TopGenericPost:(" << topGeneric.bottomLeft_X() << "," << topGeneric.bottomLeft_Y() << ")("
            << topGeneric.topLeft_X() << "," << topGeneric.topLeft_Y() << ")("
            << topGeneric.bottomRight_X() << "," << topGeneric.bottomRight_Y() << ")("
            << topGeneric.topRight_X() << "," << topGeneric.topRight_Y() << ") ";
		if(bottomRight.visible())
			result << "BottomRightPost:(" << bottomRight.bottomLeft_X() << "," << bottomRight.bottomLeft_Y() << ")("
			<< bottomRight.topLeft_X() << "," << bottomRight.topLeft_Y() << ")("
			<< bottomRight.bottomRight_X() << "," << bottomRight.bottomRight_Y() << ")("
			<< bottomRight.topRight_X() << "," << bottomRight.topRight_Y() << ") ";
		if(topRight.visible())
			result << "TopRightPost:(" << topRight.bottomLeft_X() << "," << topRight.bottomLeft_Y() << ")("
			<< topRight.topLeft_X() << "," << topRight.topLeft_Y() << ")("
			<< topRight.bottomRight_X() << "," << topRight.bottomRight_Y() << ")("
            << topRight.topRight_X() << "," << topRight.topRight_Y() << ") ";
        if(bottomGeneric.visible())
            result << "BottomGenericPost:(" << bottomGeneric.bottomLeft_X() << "," << bottomGeneric.bottomLeft_Y() << ")("
            << bottomGeneric.topLeft_X() << "," << bottomGeneric.topLeft_Y() << ")("
            << bottomGeneric.bottomRight_X() << "," << bottomGeneric.bottomRight_Y() << ")("
            << bottomGeneric.topRight_X() << "," << bottomGeneric.topRight_Y() << ") ";
		return result.str();
	}
	
};
}

#endif	/* VisionGoals_DEFINED */

