/* 
 * File:   VisionBall.h
 * Author: eugene
 *
 * Created on 25 November 2013, 6:03 PM
 */

#ifndef VisionBall_DEFINED
#define	VisionBall_DEFINED

#include <string>
#include <cstdlib>

#include <SimpleShapes.h>
#include "Vision_Control.h"
#include "wb_ball.h"



namespace guWhiteboard {
	
/**
 * @brief Whiteboard Class used by vision to report detect ball
 * Reports balls detected in top or bottom camera, including position and size
 * 
 * Examples
 * --------
 * 
 * Get 
 */
class VisionBall {
	/**The frame number that this message is from*/
	PROPERTY(uint64_t, frameNumber)
	/** ball detected in the image from the top camera*/
	PROPERTY(wb_ball, topBall)
	/** ball detected in the image from the bottom camera*/
	PROPERTY(wb_ball, bottomBall)
    /** True if a ball was detected in the top camera in this frame*/
	PROPERTY(bool, topVisible)
	/** True if a ball was detected in the bottom camera in this frame*/
	PROPERTY(bool, bottomVisible)
	/** align to 32 bits */
	PROPERTY(int16_t, pad)
public:
    /** Default Constructor*/
	VisionBall() : _frameNumber(0), _topBall(), _bottomBall() {
    }
	
	/** Equals Operator sets the frame number as well as 
	 * contents of top and bottom ball and there visibility
	 */
	VisionBall &operator=(const VisionBall& a) {
		_frameNumber = a.frameNumber();
		_topBall = a.topBall();
		_bottomBall = a.bottomBall();
		set_topVisible(a.topVisible());
		set_bottomVisible(a.bottomVisible());
		return *this;
	}
	
	/** Const reference constructor, copys contents of passed object
	 * @param ball The ball whose contents is copied
	 */
	VisionBall(const VisionBall &ball) {
		_frameNumber = ball.frameNumber();
		_topBall = ball.topBall();
		_bottomBall = ball.bottomBall();
		set_topVisible(ball.topVisible());
		set_bottomVisible(ball.bottomVisible());
	}
	
	/**DEPRICATED*/
	std::bitset<2> getMask() const {
		std::bitset<2> objectMask;
		objectMask[Top] = _topVisible;
		objectMask[Bottom] = _bottomVisible;
		return objectMask;
	}

	/** Set the ball for this message for a specified camera
	 * @param ballInfo the ball to set
	 * @param camera the camera this ball was seen on
	 */
	void setBall(SimpleCircle ballInfo, VisionCamera camera) {
		if(camera == Top) {
			topBall().set_x(ballInfo.GetCenter().x);
			topBall().set_y(ballInfo.GetCenter().y);
			topBall().set_radius(ballInfo.GetRadius());
			set_topVisible(true);
		}
		if(camera == Bottom) {
			bottomBall().set_x(ballInfo.GetCenter().x);
			bottomBall().set_y(ballInfo.GetCenter().y);
			bottomBall().set_radius(ballInfo.GetRadius());
                    
			set_bottomVisible(true);
		}
	}
	
	/**
	 * @brief Set the ball for this message for a specified camera
     * @param ballInfo the ball to set
     * @param camera the camera this ball was seen on 
     */
	void setBall(wb_ball ballInfo, VisionCamera camera) {
		if(camera == Top) {
			topBall().set_x(ballInfo.x());
			topBall().set_y(ballInfo.y());
                        topBall().set_radius(ballInfo.radius());
                        set_topVisible(true);
		}
		if(camera == Bottom) {
			bottomBall().set_x(ballInfo.x());
			bottomBall().set_y(ballInfo.y());
			bottomBall().set_radius(ballInfo.radius());
                        set_bottomVisible(true);

                }
	}

	/** 
	 * @brief Radius of the top ball. Undefined if !topVisible
	 * @return the radius
	 */
	int16_t topRadius() const { return topBall().radius(); }
	
	/**
	 * @brief Center X Position of the top ball. Undefined if !topVisible
     * @return Center X Position
     */
	int16_t topX() const { return topBall().x(); }
	
	/**
	 * @brief Center Y Position of the top ball. Undefined if !topVisible
     * @return Center Y Position
     */
	int16_t topY() const { return topBall().y(); }
	
	/** 
	 * @brief Radius of the bottom ball. Undefined if !bottomVisible
	 * @return the radius
	 */
	int16_t bottomRadius() const { return bottomBall().radius(); }
	
	/**
	 * @brief Center X Position of the bottom ball. Undefined if !bottomVisible
     * @return Center X Position
     */
	int16_t bottomX() const { return bottomBall().x(); }
	
	/**
	 * @brief Center Y Position of the bottom ball. Undefined if !bottomVisible
     * @return Center Y Position
     */
	int16_t bottomY() const { return bottomBall().y(); }
	
	/**
	 * @brief Return true if either the top or bottom ball is visible in this message
     * @return True if top or bottom is visible
     */
	bool visible() {return topVisible() || bottomVisible(); }
	
	/**
	 * Return the radius one of the balls
     * @return The top ball radius if it is visible else the bottom ball radius if it is visible else 0
     */
	int16_t radius() const { 
		if (topVisible())
			return topBall().radius();
		else if (bottomVisible())
			return bottomBall().radius();
		else
			return 0;
	}
	
	/**
	 * Return the center x coordinate of one of the balls
     * @return The top ball x coordinate if it is visible else the bottom ball x coordinate if it is visible else 0
     */
	int16_t x() const { 
                if (topVisible())
			return topBall().x();
                else if (bottomVisible())
			return bottomBall().x();
		else
			return 0;
	}
	
	/**
	 * Return the center y coordinate of one of the balls
     * @return The top ball y coordinate if it is visible else the bottom ball y coordinate if it is visible else 0
     */
	int16_t y() const { 
                if (topVisible())
                    return topBall().y();
                else if (bottomVisible())
                    return bottomBall().y();
		else
			return 0;
	}
	
	/**
	 * @brief Set the top and bottom visible flags to false
     */
	void Reset() {
		set_topVisible(false);
		set_bottomVisible(false);
	}

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        
		/**USED INTERNALLY FOR STRING PARSER*/
        static const char SEPARATOR_IS_AT = '@';

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"
		/**
		 * String constructor
         * @param s The tokenized string to parse 
         */
        VisionBall(std::string s): VisionBall() {
                from_string(s);
        }

		/**
		 * Const char array constructor
         * @param s The tokenized const char array to parse 
         */
        VisionBall(const char *s): VisionBall() {
                from_string(std::string(s));
        }
#pragma clang diagnostic pop
        
	/**
	 * Parse as string and set this object to the tokenized contents
     * @param s The string to parse
     */
	void from_string(std::string s) {
		std::string radiousDel (1,SEPARATOR_IS_AT);
		set_frameNumber(0);
		Reset();
		size_t n = -4;
		std::string command = "BALL";
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		while(n!=std::string::npos) {
			n = s.find(command, n+4);
			if (n!=std::string::npos && n>=3) {
				std::string t = s.substr(n+command.length()+1);
				SimpleCircle ballInfo;
				VisionCamera cam;
				if(s.substr(n-3, 3).find("TOP") != std::string::npos)
					cam = Top;
				else
					cam = Bottom;
				
				ballInfo.setCenter(t.c_str());
                                 std::size_t found = t.find(SEPARATOR_IS_AT);
                                if (std::string::npos!=found )
                                { std::string strRadious=t.substr (found+1);
                                        ballInfo.setRadius(static_cast<u_int16_t>(::atoi(strRadious.c_str())));
                                }
				setBall(ballInfo, cam);
			}
		}
		std::string fnum = "FRAMENUMBER";
		n = s.find(fnum);
		if(n != std::string::npos) {
			
			set_frameNumber(atol(s.substr(n+fnum.length()+1).c_str()));
		}
	}
	
	/**
	 * Description of the VisionBall object
     * @return The string description
     */
	std::string description() {
		std::stringstream result;
		if(_topVisible) {
			result << "TopBall:(" << topBall().x() << "," << topBall().y() << ")"<< SEPARATOR_IS_AT << topBall().radius();
		}
		if(_bottomVisible) {
			result << "BottomBall:(" << bottomBall().x() << "," << bottomBall().y() << ")"<< SEPARATOR_IS_AT << bottomBall().radius();
		}
		result << "FrameNumber=" << frameNumber();
		return result.str();
	}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

};
}

#endif	/* VisionBall_DEFINED */

