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
#include <iostream>
#include <gu_util.h>
#include "wb_robot.h"

#include "Vision_Control.h"

#define TOPLIMIT 5
#define BOTTOMLIMIT 5

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
    wb_robot topRobots[TOPLIMIT];
    wb_robot bottomRobots[BOTTOMLIMIT];
	uint32_t _frameNumber;
    uint32_t topCntr;
    uint32_t bottomCntr;
public:
	/**Default Constructor*/
    VisionRobots() : _frameNumber(0), topCntr(0), bottomCntr(0) {
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
				GUPoint<int16_t> _topLeft(com.at(2).c_str());
				GUPoint<int16_t> _bottomRight(com.at(3).c_str());

				robotInfo.set_topLeft_X(_topLeft.x);
				robotInfo.set_topLeft_Y(_topLeft.y);

				robotInfo.set_bottomRight_X(_bottomRight.x);
				robotInfo.set_bottomRight_Y(_bottomRight.y);

				setRobot(robotInfo, cam);
			}
		}
	}
	/**
	 * @brief Add a the Robot to this VisionRobot message
     * @param robotInfo The post information to be set
     * @param camera The camera this post was seen on
     */
    void setRobot(wb_robot robotInfo, VisionCamera camera) {
		if(camera == Top && topCntr < TOPLIMIT) {
			topRobots[topCntr] = robotInfo;
			topRobots[topCntr++].set_visible(true);
		}
        else if( bottomCntr < BOTTOMLIMIT ) {
            bottomRobots[bottomCntr] = robotInfo;
            bottomRobots[bottomCntr++].set_visible(true);
		}
	}
	
	/**
	 * @brief Get the current Robots for this message
     * @param camera The camera to get Robot post information from
     * @param idx The index of the robot (must be between 0 and TOP or BOTTOMLIMIT)
     * @return The Robot post information.
     */
    const wb_robot &robots(VisionCamera camera, int idx) const
    {
		if(camera == Top)
        {
            idx = idx >= TOPLIMIT ? TOPLIMIT-1 : idx;
			return topRobots[idx];
        }
        else
        {
            idx = idx >= BOTTOMLIMIT ? BOTTOMLIMIT-1 : idx;
			return bottomRobots[idx];
        }
    }
    
    /**
     * @brief Get the current Robots for this message
     * @param camera The camera to get Robot post information from
     * @param idx The index of the robot (must be between 0 and TOP or BOTTOMLIMIT)
     * @return The Robot post information.
     */
    wb_robot &robots(VisionCamera camera, int idx)
    {
        if(camera == Top)
        {
            idx = idx >= TOPLIMIT ? TOPLIMIT-1 : idx;
            return topRobots[idx];
        }
        else
        {
            idx = idx >= BOTTOMLIMIT ? BOTTOMLIMIT-1 : idx;
            return bottomRobots[idx];
        }
    }
	
	/**
	 * @brief Reset the visible flag for all four different posts to false
     */
    void Reset() {
        topCntr = bottomCntr = 0;
        for( int i = 0; i < TOPLIMIT; i++ )
        {
            topRobots[i].set_visible(false);
        }
        for( int i = 0; i < BOTTOMLIMIT; i++ )
        {
            bottomRobots[i].set_visible(false);
        }
	}
	
	/**
	 * @brief Sets the frame number this information in this message was observed.
     * @param fn The frame number
     */
    void setFrameNumber(uint32_t fn) {
		_frameNumber = fn;
	}
	
	/**
	 * @brief Get the frame number the information in this message was observed.
     * @return The frame number
     */
    uint32_t frameNumber() const {
		return _frameNumber;
	}
	
	/**
	 * @brief Converts this message into a serialized string.
     * @return The serialized string
     */
    std::string description() {
		std::stringstream result;
		
        for (uint32_t i = 0; i < topCntr; i++) {
            result << "TopRobot:("
            << topRobots[i].topLeft_X() << "," << topRobots[i].topLeft_Y() << ")("
            << topRobots[i].bottomRight_X() << "," << topRobots[i].bottomRight_Y() << ") ";
        }
        for (uint32_t i = 0; i < bottomCntr; i++) {
            result << "BottomRobot:("
            << bottomRobots[i].topLeft_X() << "," << bottomRobots[i].topLeft_Y() << ")("
            << bottomRobots[i].bottomRight_X() << "," << bottomRobots[i].bottomRight_Y() << ") ";
        }
        return result.str();
    }
};
}

#endif	/* VisionRobots_DEFINED */

