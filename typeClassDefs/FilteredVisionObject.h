/** 
 * file FilteredVisionObject.h 
 * 
 * This file was generated by classgenerator from Filtered_Vision_Object.txt. 
 * DO NOT CHANGE MANUALLY! 
 * 
 * Created by Vlad Estivill-Castro on 18:41, 7/6/2018 
 * Copyright (c) 2018 Vlad Estivill-Castro 
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


#ifndef FilteredVisionObject_DEFINED 
#define FilteredVisionObject_DEFINED 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION 
#include <cstdlib> 
#include <string.h> 
#include <sstream> 
#endif 

#include "wb_filtered_vision_object.h" 

namespace guWhiteboard 
{
    /** 
     * @brief Posting by Kalman filter on object sighting  
     *   
     */ 
    class FilteredVisionObject: public wb_filtered_vision_object 
    { 
    public:
        /** Constructor */ 
        FilteredVisionObject(uint64_t visibilityHistory = 0, int32_t frameCounter = 0, int16_t distance = 0, int16_t x = 0, int16_t y = 0, int16_t yaw = 0, int16_t ray_angle = 0, bool isVisible = false, bool pad1 = false)
        { 
            set_visibilityHistory(visibilityHistory); 
            set_frameCounter(frameCounter); 
            set_distance(distance); 
            set_x(x); 
            set_y(y); 
            set_yaw(yaw); 
            set_ray_angle(ray_angle); 
            set_isVisible(isVisible); 
            set_pad1(pad1); 
        } 

        /** Copy Constructor */ 
        FilteredVisionObject(const FilteredVisionObject &other) : wb_filtered_vision_object() 
        { 
            set_visibilityHistory(other.visibilityHistory()); 
            set_frameCounter(other.frameCounter()); 
            set_distance(other.distance()); 
            set_x(other.x()); 
            set_y(other.y()); 
            set_yaw(other.yaw()); 
            set_ray_angle(other.ray_angle()); 
            set_isVisible(other.isVisible()); 
            set_pad1(other.pad1()); 
        } 

        /** Copy Assignment Operator */ 
        FilteredVisionObject &operator = (const FilteredVisionObject &other) 
        { 
            set_visibilityHistory(other.visibilityHistory()); 
            set_frameCounter(other.frameCounter()); 
            set_distance(other.distance()); 
            set_x(other.x()); 
            set_y(other.y()); 
            set_yaw(other.yaw()); 
            set_ray_angle(other.ray_angle()); 
            set_isVisible(other.isVisible()); 
            set_pad1(other.pad1()); 
            return *this; 
        } 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION 
        /** String Constructor */ 
        FilteredVisionObject(const std::string &str) { from_string(str.c_str()); }  

        std::string description() 
        { 
#ifdef USE_WB_FILTERED_VISION_OBJECT_C_CONVERSION 
            char buffer[FILTERED_VISION_OBJECT_DESC_BUFFER_SIZE]; 
            wb_filtered_vision_object_description(this, buffer, sizeof(buffer)); 
            std::string descr = buffer; 
            return descr; 
#else 
            std::ostringstream ss; 
            ss << "visibilityHistory=" << visibilityHistory(); 
            ss << ", "; 
            ss << "frameCounter=" << frameCounter(); 
            ss << ", "; 
            ss << "distance=" << distance(); 
            ss << ", "; 
            ss << "x=" << x(); 
            ss << ", "; 
            ss << "y=" << y(); 
            ss << ", "; 
            ss << "yaw=" << yaw(); 
            ss << ", "; 
            ss << "ray_angle=" << ray_angle(); 
            ss << ", "; 
            ss << "isVisible=" << isVisible(); 
            ss << ", "; 
            ss << "pad1=" << pad1(); 

            return ss.str(); 

#endif /// USE_WB_FILTERED_VISION_OBJECT_C_CONVERSION
        } 

        std::string to_string() 
        { 
#ifdef USE_WB_FILTERED_VISION_OBJECT_C_CONVERSION 
            char buffer[FILTERED_VISION_OBJECT_DESC_BUFFER_SIZE]; 
            wb_filtered_vision_object_to_string(this, buffer, sizeof(buffer)); 
            std::string toString = buffer; 
            return toString; 
#else 
            std::ostringstream ss; 
            ss << visibilityHistory(); 
            ss << ", "; 
            ss << frameCounter(); 
            ss << ", "; 
            ss << distance(); 
            ss << ", "; 
            ss << x(); 
            ss << ", "; 
            ss << y(); 
            ss << ", "; 
            ss << yaw(); 
            ss << ", "; 
            ss << ray_angle(); 
            ss << ", "; 
            ss << isVisible(); 
            ss << ", "; 
            ss << pad1(); 

            return ss.str(); 

#endif /// USE_WB_FILTERED_VISION_OBJECT_C_CONVERSION
        } 

        void from_string(const std::string &str) 
        { 
#ifdef USE_WB_FILTERED_VISION_OBJECT_C_CONVERSION 
            wb_filtered_vision_object_from_string(this, str); 
#else 
            char var[100]; 
            unsigned long visibilityHistory_index = str.find("visibilityHistory");
            if(visibilityHistory_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(visibilityHistory_index, str.length()).c_str(), "visibilityHistory = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_visibilityHistory(uint64_t(atoi(value.c_str()))); 
                } 
            } 

            unsigned long frameCounter_index = str.find("frameCounter");
            if(frameCounter_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(frameCounter_index, str.length()).c_str(), "frameCounter = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_frameCounter(int32_t(atoi(value.c_str()))); 
                } 
            } 

            unsigned long distance_index = str.find("distance");
            if(distance_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(distance_index, str.length()).c_str(), "distance = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_distance(int16_t(atoi(value.c_str()))); 
                } 
            } 

            unsigned long x_index = str.find("x");
            if(x_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(x_index, str.length()).c_str(), "x = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_x(int16_t(atoi(value.c_str()))); 
                } 
            } 

            unsigned long y_index = str.find("y");
            if(y_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(y_index, str.length()).c_str(), "y = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_y(int16_t(atoi(value.c_str()))); 
                } 
            } 

            unsigned long yaw_index = str.find("yaw");
            if(yaw_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(yaw_index, str.length()).c_str(), "yaw = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_yaw(int16_t(atoi(value.c_str()))); 
                } 
            } 

            unsigned long ray_angle_index = str.find("ray_angle");
            if(ray_angle_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(ray_angle_index, str.length()).c_str(), "ray_angle = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_ray_angle(int16_t(atoi(value.c_str()))); 
                } 
            } 

            unsigned long isVisible_index = str.find("isVisible");
            if(isVisible_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(isVisible_index, str.length()).c_str(), "isVisible = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_isVisible(value.compare("true") == 0  || value.compare("1") == 0 ? true : false); 
                } 
            } 

            unsigned long pad1_index = str.find("pad1");
            if(pad1_index != std::string::npos)
            {
                memset(&var[0], 0, sizeof(var));
                if(sscanf(str.substr(pad1_index, str.length()).c_str(), "pad1 = %[^,]", var) == 1)
                {
                    std::string value = std::string(var);
                    set_pad1(value.compare("true") == 0  || value.compare("1") == 0 ? true : false); 
                } 
            } 

#endif /// USE_WB_FILTERED_VISION_OBJECT_C_CONVERSION
        } 
#endif ///   WHITEBOARD_POSTER_STRING_CONVERSION
    }; 
} /// namespace guWhiteboard 
#endif /// FilteredVisionObject_DEFINED 
