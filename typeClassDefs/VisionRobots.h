/* 
 * File:   VisionRobots.h
 * Author: eugene
 *
 * Created on 1 December 2013, 8:02 PM
 */

#ifndef VisionRobots_DEFINED
#define	VisionRobots_DEFINED

#include <SimpleShapes.h>
#include <string>
#include <gu_util.h>
#include "wb_robot.h"

#include "Vision_Control.h"

namespace guWhiteboard {
/**
 * @brief Class to post information about Robot posts detected from vision
 * This class contains information the dimension of Robot posts. The message 
 * contains information for left and right Robot post on top and bottom camera's
 * 
 * Examples
 * --------
 * 
 * Retrieve the current information about the Robots in the top camera
 * 
 *		VisionRobot v = VisionRobot_t.get(); //get the Robot message off the whiteboard
 *		std::vector<wb_robot> r = v.robots(Top); //get the robots from the top camera
 *      if( !r.empty() ) {
 *          bool visible = r[0].visible(); //get the visibile flag for the robot
 *          int x1 = r[0].bottomLeft_X(); //get the bottom left x coordinate for the robot
 *      }
 */
class VisionRobots {
private:
    std::vector<wb_robot> topRobots;
    std::vector<wb_robot> bottomRobots;
	unsigned long _frameNumber;
public:
	/**Default Constructor*/
    VisionRobots() : _frameNumber(0) {
    }

	/**
	 * @brief String Constructor
	 * Converts a serialized string to a VisionRobot object
     * @param s The String to convert
     */
	VisionRobots(std::string s) {
        from_string(s);
    }

    void from_string(std::string &s)  {
        _frameNumber = 0; 
		
		size_t n = static_cast<size_t>(-5);
		std::string command = "ROBOT";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+5);
			if (n!=std::string::npos) {
				std::string t = s.substr(n+command.length()+1);
				wb_robot robotInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;
	
				std::vector<std::string> com = components_of_string_separated(t, '(');
				GUPoint<int16_t> bottomLeft(com.at(1).c_str());
				GUPoint<int16_t> topLeft(com.at(2).c_str());
				GUPoint<int16_t> bottomRight(com.at(3).c_str());
				GUPoint<int16_t> topRight(com.at(4).c_str());

				robotInfo.set_bottomLeft_X(bottomLeft.x);
				robotInfo.set_bottomLeft_Y(bottomLeft.y);

				robotInfo.set_topLeft_X(topLeft.x);
				robotInfo.set_topLeft_Y(topLeft.y);

				robotInfo.set_bottomRight_X(bottomRight.x);
				robotInfo.set_bottomRight_Y(bottomRight.y);

				robotInfo.set_topRight_X(topRight.x);
				robotInfo.set_topRight_X(topRight.y);

				setRobot(robotInfo, cam);
			}
		}
	}
	/**
	 * @brief Set the Robot for this VisionRobot message
     * @param robotInfo The post information to be set
     * @param camera The camera this post was seen on
     */
	void setRobot(wb_robot robotInfo, VisionCamera camera) {
		if(camera == Top) {
			topRobots.push_back(robotInfo);
			topRobots.back().set_visible(true);
		}
        else {
            bottomRobots.push_back(robotInfo);
            bottomRobots.back().set_visible(true);
		}
	}
	
	/**
	 * @brief Get the current Robots for this message
     * @param camera The camera to get Robot post information from
     * @return The Robot post information.
     */
    const std::vector<wb_robot> &robots(VisionCamera camera) const
	{
		if(camera == Top)
			return topRobots;
		else
			return bottomRobots;
    }
    
    /**
     * @brief Get the current Robots for this message
     * @param camera The camera to get Robot post information from
     * @return The Robot post information.
     */
    std::vector<wb_robot> &robots(VisionCamera camera)
    {
        if(camera == Top)
            return topRobots;
        else
            return bottomRobots;
    }
	
	/**
	 * @brief Reset the visible flag for all four different posts to false
     */
	void Reset() {
        topRobots.clear();
        bottomRobots.clear();
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
		
        for (unsigned long i = 0; i < topRobots.size(); i++) {
            result << "TopRobot:("
            << topRobots[i].bottomLeft_X() << "," << topRobots[i].bottomLeft_Y() << ")("
            << topRobots[i].topLeft_X() << "," << topRobots[i].topLeft_Y() << ")("
            << topRobots[i].bottomRight_X() << "," << topRobots[i].bottomRight_Y() << ")("
            << topRobots[i].topRight_X() << "," << topRobots[i].topRight_Y() << ") ";
        }
        for (unsigned long i = 0; i < bottomRobots.size(); i++) {
            result << "BottomRobot:("
            << bottomRobots[i].bottomLeft_X() << "," << bottomRobots[i].bottomLeft_Y() << ")("
            << bottomRobots[i].topLeft_X() << "," << bottomRobots[i].topLeft_Y() << ")("
            << bottomRobots[i].bottomRight_X() << "," << bottomRobots[i].bottomRight_Y() << ")("
            << bottomRobots[i].topRight_X() << "," << bottomRobots[i].topRight_Y() << ") ";
        }
    }
};
}

#endif	/* VisionRobots_DEFINED */

