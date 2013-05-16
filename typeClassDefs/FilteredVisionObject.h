/*
 *  FilteredVisionObject.h
 *  gusimplewhiteboard / clfsm
 *
 *  Created by Rene Hexel on 25/03/13.
 *  Copyright (c) 2013 Rene Hexel. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Rene Hexel.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */
#ifndef FilteredVisionObjects_DEFINED
#define FilteredVisionObjects_DEFINED

#include <cstdlib>
#include <sstream>
#include <gu_util.h>

namespace guWhiteboard
{
        /**
         * Discriminate sigthings 
         */
        enum FilteredVisionObjectType
        {
            FVOBall,          ///< Filtered informaiton for the Ball
            FVOGoalPost,          ///< Filtered informaiton for a post we cannot tell is Left or right
            FVOGoalPostLeft,          ///< Filtered informaiton for a post we know is Left 
            FVOGoalPostRight,          ///< Filtered informaiton for a post we know is right 
            FVOGoalCrossBar,          ///< Filtered informaiton for the Ball
            FVO_NUM_OBJECTS          ///< number of different kind of objects
        };

	/*
	static FilteredVisionObjectType nextLandmark ( FilteredVisionObjectType value);

	static FilteredVisionObjectType nextLandmark ( FilteredVisionObjectType value)
	{
		int i =value; i++ ;
	        FilteredVisionObjectType temp  = FilteredVisionObjectType(i);
		return temp;
	}
	*/

        /**
         * Class for a single sigthing.
         */
        class FilteredVisionObject
        {
            PROPERTY(bool, isVisible) //  is this a credible sighting
            PROPERTY(int16_t, distance) //  distance to landmark in cm
            PROPERTY(int32_t, frameCounter) //  frame counter in cm
            PROPERTY(int16_t, x) //  center x-coordinate in image
            PROPERTY(int16_t, y) //  cneter y-coordinate in image

        public:
            /** designated constructor */
            FilteredVisionObject( bool isVisible = false,
                                       int16_t distance =0,
				       int32_t frameCounter =0,
                                       int16_t x = 0,
				       int16_t y = 0):
                                      _isVisible(isVisible), 
                                      _distance(distance), 
                                      _frameCounter(frameCounter), 
                                       _x(x), _y(y)  { /* better than set_x(x); set_y(y) */ }

            /** string constructor */
            FilteredVisionObject(const std::string &names) { from_string(names); }

            /** copy constructor */
            FilteredVisionObject(const FilteredVisionObject &other):
                      _isVisible(other._isVisible),
                      _distance(other._distance),
                      _frameCounter(other._frameCounter),
                      _x(other._x), _y(other._y) {}

            /** convert to a string */
            std::string description()
            {
                std::ostringstream ss;
		/*
		switch (landmarkType() )
		{ case FVOBall : ss << "aBall:";
			break;
		  case FVOGoalPost : ss << "aGoalPost:";
			break;
		  case FVOGoalPostLeft : ss << "aLeftGoalPost:";
			break;
		  case FVOGoalPostRight : ss << "aRightGoalPost:";
			break;
		  case FVOGoalCrossBar : ss << "aCrossbar:";
			break;
		}
		*/

		if ( isVisible())
                { ss<<" is visible ";
		  ss << "at distance " << distance() << "with location ("  <<  x() << "," << y() << ")";
		}
		else ss << " is NOT visible ";

		ss << " at frame  " << frameCounter();

                return ss.str();
            }

            /** Only grab the distance x,y positions convert from a string */
	    //*** TODO: still incomplete */
            void from_string(const std::string &str)
            {
                std::istringstream iss(str);
                std::string token;
                if (getline(iss, token, ','))
                {
		    set_x(  int16_t(atoi(token.c_str())));
		    set_y(0);
                    if (getline(iss, token, ','))
                    {
		        set_y(int16_t(atoi(token.c_str())));
                    }
                }
            }

        };

	/**
	 * Filtered vision objects on the whiteboard
	 */
        class FilteredVisionObjects
	{
	class FilteredVisionObject     _objects[FVO_NUM_OBJECTS];

        public:
	    FilteredVisionObjects()
	    {}

	    /** single vision object setter */
	    FilteredVisionObjects(const class FilteredVisionObject &obj, enum FilteredVisionObjectType landmarkType  = FVOBall)
	    {
		    /*
		for ( int i =FVOBall; i< FVO_NUM_OBJECTS; i++ )
		{ FilteredVisionObjectType iThLandmarkType = FilteredVisionObjectType(i);
		}
			*/
		_objects[landmarkType]=obj;
	    }

            /** string constructor */
            FilteredVisionObjects(const std::string &names) { from_string(names); }

            /** copy constructor */
            FilteredVisionObjects(const FilteredVisionObjects &other)
	    {
		    memcpy(this, &other, sizeof(other));
	    }

	    /** property getter */
	    class FilteredVisionObject *objects() { return _objects; }

	    /** property setter */
	    void set_objects(const class FilteredVisionObject *objects)
	    {
		    memcpy(_objects, objects, sizeof(_objects));
	    }

	    /** single vision object setter */
	    void set_object(const class FilteredVisionObject &obj, enum FilteredVisionObjectType landmarkType  = FVOBall)
	    {
		_objects[landmarkType]=obj;
	    }

	    /** single vision object setter */
	    FilteredVisionObject  get_object( enum FilteredVisionObjectType landmarkType  = FVOBall)
	    {
		return _objects[landmarkType];
	    }

            /** convert to a string */
            std::string description()
            {
                std::ostringstream ss;
		for ( int i =FVOBall; i< FVO_NUM_OBJECTS; i++ )
		{ 
			FilteredVisionObjectType landmarkType = FilteredVisionObjectType(i);
		  switch (landmarkType )
		   { case FVOBall : ss << "aBall:"; 
			break;
		    case FVOGoalPost : ss << "aGoalPost:";
			break;
		    case FVOGoalPostLeft : ss << "aLeftGoalPost:";
			break;
		    case FVOGoalPostRight : ss << "aLeftGoalPost:";
			break;
		    case FVOGoalCrossBar : ss << "aLeftGoalPost:";
			break;
		    case FVO_NUM_OBJECTS : mipal_warn( "ERROR:");
			break;
		  }// switch
		  ss <<_objects[landmarkType].description();
		} //for
                return ss.str();
	  }

	    /*
	     * TODO, this is only for the BALL, the axiom from_string() is inverse of description() 
	     * NOT WORKING
	     */
            void from_string(const std::string &str)
            {
		  _objects[FVOBall].from_string( str );
            }

	};
}


#endif // FilteredVisionObjects_DEFINED
