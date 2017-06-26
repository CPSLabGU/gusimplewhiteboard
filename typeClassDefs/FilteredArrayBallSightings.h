/** 
 * file FilteredArrayBallSightings.h 
 * 
 * This file was generated by classgenerator from Filtered_ArrayBallSightings.txt. 
 * DO NOT CHANGE MANUALLY! 
 * 
 * Created by Vlad Estivill-Castro on 17:25, 24/6/2017 
 * Copyright (c) 2017 Vlad Estivill-Castro 
 * All rights reserved. 
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
 *    This product includes software developed by Vlad Estivill-Castro. 
 * 
 * 4. Neither the name of the author nor the names of contributors 
 *    may be used to endorse or promote products derived from this 
 *    software without specific prior written permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * 'AS IS' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
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
 */ 


#ifndef FilteredArrayBallSightings_DEFINED 
#define FilteredArrayBallSightings_DEFINED 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION 
#include <cstdlib> 
#include <string.h> 
#include <sstream> 
#endif 

#include "wb_filtered_arrayballsightings.h" 

namespace guWhiteboard 
{
    /** 
     * The class of landmarks filtered regarding goal sigthings 
     */ 
    class FilteredArrayBallSightings: public wb_filtered_arrayballsightings 
    { 
    public:
        /** Constructor */ 
        FilteredArrayBallSightings()
        { 
        } 

        /** Copy Constructor */ 
        FilteredArrayBallSightings(const FilteredArrayBallSightings &other) : wb_filtered_arrayballsightings() 
        { 
            set_objects(other.objects(0), 0); 
            set_objects(other.objects(1), 1); 
        } 

        /** Copy Assignment Operator */ 
        FilteredArrayBallSightings &operator = (const FilteredArrayBallSightings &other) 
        { 
            set_objects(other.objects(0), 0); 
            set_objects(other.objects(1), 1); 
            return *this; 
        } 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION 
        /** String Constructor */ 
        FilteredArrayBallSightings(const std::string &str) { from_string(str.c_str()); }  

        std::string description() 
        { 
#ifdef USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION 
            char buffer[FILTERED_ARRAYBALLSIGHTINGS_DESC_BUFFER_SIZE]; 
            wb_filtered_arrayballsightings_description(this, buffer, sizeof(buffer)); 
            std::string descr = buffer; 
            return descr; 
#else 
            std::ostringstream ss; 

            bool objects_first = true; 
            ss << "objects={"; 
            for (int i = 0; i < FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE; i++) 
            { 
                ss << (objects_first ? "" : ",") << static_cast<FilteredVisionobject *>(&objects(i))->description(); 
                objects_first = false;  
            } 
            ss << "}"; 

            return ss.str(); 

#endif /// USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
        } 

        std::string to_string() 
        { 
#ifdef USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION 
            char buffer[FILTERED_ARRAYBALLSIGHTINGS_DESC_BUFFER_SIZE]; 
            wb_filtered_arrayballsightings_to_string(this, buffer, sizeof(buffer)); 
            std::string toString = buffer; 
            return toString; 
#else 
            std::ostringstream ss; 

            bool objects_first = true; 
            ss << "objects={"; 
            for (int i = 0; i < FILTERED_ARRAYBALLSIGHTINGS_OBJECTS_ARRAY_SIZE; i++) 
            { 
                ss << (objects_first ? "" : ",") << static_cast<FilteredVisionobject *>(&objects(i))->to_string(); 
                objects_first = false;  
            } 
            ss << "}"; 

            return ss.str(); 

#endif /// USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
        } 

        void from_string(const std::string &str) 
        { 
#ifdef USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION 
            wb_filtered_arrayballsightings_from_string(this, str); 
#else 
            char var[100]; 
            unsigned long objects_index = str.find("objects");
            if(objects_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(objects_index, str.length()).c_str(), "objects = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                } 
            } 

#endif /// USE_WB_FILTERED_ARRAYBALLSIGHTINGS_C_CONVERSION
        } 
#endif ///   WHITEBOARD_POSTER_STRING_CONVERSION
    }; 
} /// namespace guWhiteboard 
#endif /// FilteredArrayBallSightings_DEFINED 
