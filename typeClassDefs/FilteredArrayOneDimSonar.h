
/*
 *  FilteredArrayOneDimSonar.h
 *  gusimplewhiteboard
 *
 *  Created by Vlad Estivill-Castro  on 18/06/2014..
 *  Copyright (c) 2013, 2014 Vlad Estivill-Castro. All rights reserved.
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



/****************** I M P O R T A N T   */
/* is <class_name>_DEFINED              */
/***************************************/

#ifndef FilteredArrayOneDimSonar_h
#define FilteredArrayOneDimSonar_h

#include <cstdlib>
#include <sstream>
#include <gu_util.h>
#include "wb_arrayoffilteredsonarobjects.h"

/**
 * Class for for the array of sonar messages, LEFT and RIGHT.
 */
class FilteredArrayOneDimSonar:  public wb_arrayoffilteredsonarobjects
{
        static const char SEPARATOR_IS_COMMA = ',';
        static const char SEPARATOR_IS_COLON = ':';
        
        static const char IS_VISIBLE_ID = 'I';
        
public:
        /** designated constructor */
        FilteredArrayOneDimSonar(): wb_arrayoffilteredsonarobjects()
        { /*  */ }
        
        /** constructor with one setter */
        FilteredArrayOneDimSonar(const class FilteredOneDimSonar &obj, enum FilteredSonarObjectType landmarkType  = FSLeft)
        {
                _objects[landmarkType]=obj;
        }
        
        /** string constructor */
        FilteredArrayOneDimSonar(const std::string &names) { from_string(names); }
        
        /** const char * constructor */
        FilteredArrayOneDimSonar(const char *names) { from_string(names); }
        
        /** copy constructor */
        FilteredSonarObjects(const FilteredSonarObjects &other)
        {
#ifdef DEBUG
                assert(sizeof(*this) == sizeof(wb_arrayoffilteredsonarobjects));
#endif
                memcpy(this, &other, sizeof(other));
        }
        
        /** copy assignment operator **/
        FilteredSonarObjects &operator=(const FilteredSonarObjects &other)
        {
                memcpy(this, &other, sizeof(other));
                
                return *this;
        }
        
        /** property getter */
        class FilteredSonarObject *objects() { return _objects; }
        
        /** property setter */
        void set_objects(const class FilteredSonarObject *objects)
        {
                memcpy(_objects, objects, sizeof(_objects));
        }
        
        /** single vision object setter */
        void set_object(const class FilteredSonarObject &obj, enum FilteredSonarObjectType landmarkType  = FSLeft)
        {
                _objects[landmarkType]=obj;
        }
        
        /** single vision object setter */
        FilteredSonarObject  get_object( enum FilteredSonarObjectType landmarkType  = FSLeft)
        {
                return _objects[landmarkType];
        }
        
        
        /** convert to a string; string serialization */

        std::string description()
        {
                std::ostringstream ss;
                for ( int i =FSLeft; i< FSO_NUM_OBJECTS; i++ )
                {
                        FilteredSonarObjectType landmarkType = FilteredSonarObjectType(i);
                        switch (landmarkType )
                        {
                                case FSLeft : ss << "aLeftSonar:";
                                        break;
                                case FSRight : ss << "aRightSonar:";
                                        break;
                                case FSO_NUM_OBJECTS : mipal_warn( "ERROR:");
                                        break;
                        }// switch
                        ss <<_objects[landmarkType].description();
                } //for
                return ss.str();
        }
        
        /* build froms tring */
        void from_string(const std::string &str)
        {
                std::istringstream iss(str);
                std::string token;
                if (getline(iss, token, SEPARATOR_IS_COMMA))
                { if (IS_VISIBLE_ID==token[0])
                { set_isVisible ( true );
                        set_distance ( 0 );
                        set_frameCounter ( 0 );
                        std::string comaDel (1,SEPARATOR_IS_COMMA);
                        std::size_t found = str.find(comaDel);
                        if (std::string::npos!=found )
                        { std::string strSecond=str.substr (found+comaDel.size());
                                std::istringstream second_iss(strSecond);
                                if (getline(second_iss, token, SEPARATOR_IS_COMMA))
                                {
                                        int16_t distance_value = int16_t ( atoi(token.c_str()));
                                        set_distance ( distance_value);
                                        std::string colonDel (1,SEPARATOR_IS_COLON);
                                        found = strSecond.find(colonDel);
                                        if (std::string::npos!=found )
                                        { std::string strThird=strSecond.substr (found+colonDel.size());
                                                std::istringstream third_iss(strThird);
                                                if (getline(third_iss, token, SEPARATOR_IS_COMMA))
                                                {
                                                        int32_t frameValue=int32_t ( atoi(token.c_str()));
                                                        set_frameCounter (frameValue);
                                                        
                                                }
                                                
                                                
                                        }
                                        
                                }
                                
                        }
                        
                        
                }
                else
                { *this=FilteredOneDimSonar();     }
                        
                        
                        
                }
                else
                {
                        *this=FilteredOneDimSonar();
                }
        }
        
};


#endif // FilteredArrayOneDimSonar_h
