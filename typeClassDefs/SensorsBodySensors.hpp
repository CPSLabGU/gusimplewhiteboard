/*
 * file SensorsBodySensors.hpp
 *
 * This file was generated by classgenerator from sensors_body_sensors.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Copyright © 2021 Carl Lusty. All rights reserved.
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
 *        This product includes software developed by Carl Lusty.
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

#ifndef guWhiteboard_SensorsBodySensors_h
#define guWhiteboard_SensorsBodySensors_h

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_sensors_body_sensors.h"
#include <float.h>

#undef guWhiteboard_SensorsBodySensors_DEFINED
#define guWhiteboard_SensorsBodySensors_DEFINED

#undef SensorsBodySensors_DEFINED
#define SensorsBodySensors_DEFINED

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_sensors_body_sensors`.
     */
    class SensorsBodySensors: public wb_sensors_body_sensors {

    private:

        /**
         * Set the members of the class.
         */
        void init(signed int t_DCM_Time = 0, float t_InertialSensor_AccX = 0.0f, float t_InertialSensor_AccY = 0.0f, float t_InertialSensor_AccZ = 0.0f, float t_InertialSensor_GyrX = 0.0f, float t_InertialSensor_GyrY = 0.0f, float t_InertialSensor_GyrZ = 0.0f, float t_InertialSensor_AngleX = 0.0f, float t_InertialSensor_AngleY = 0.0f, float t_InertialSensor_AngleZ = 0.0f, float t_InertialSensor_AccelerometerX = 0.0f, float t_InertialSensor_AccelerometerY = 0.0f, float t_InertialSensor_AccelerometerZ = 0.0f, float t_InertialSensor_GyroscopeX = 0.0f, float t_InertialSensor_GyroscopeY = 0.0f, float t_InertialSensor_GyroscopeZ = 0.0f, uint8_t t_Battery_Charge = 0, uint8_t t_Battery_Current = 0, float t_US = 0.0f, bool t_ChestBoard_Button = true) {
            set_DCM_Time(t_DCM_Time);
            set_InertialSensor_AccX(t_InertialSensor_AccX);
            set_InertialSensor_AccY(t_InertialSensor_AccY);
            set_InertialSensor_AccZ(t_InertialSensor_AccZ);
            set_InertialSensor_GyrX(t_InertialSensor_GyrX);
            set_InertialSensor_GyrY(t_InertialSensor_GyrY);
            set_InertialSensor_GyrZ(t_InertialSensor_GyrZ);
            set_InertialSensor_AngleX(t_InertialSensor_AngleX);
            set_InertialSensor_AngleY(t_InertialSensor_AngleY);
            set_InertialSensor_AngleZ(t_InertialSensor_AngleZ);
            set_InertialSensor_AccelerometerX(t_InertialSensor_AccelerometerX);
            set_InertialSensor_AccelerometerY(t_InertialSensor_AccelerometerY);
            set_InertialSensor_AccelerometerZ(t_InertialSensor_AccelerometerZ);
            set_InertialSensor_GyroscopeX(t_InertialSensor_GyroscopeX);
            set_InertialSensor_GyroscopeY(t_InertialSensor_GyroscopeY);
            set_InertialSensor_GyroscopeZ(t_InertialSensor_GyroscopeZ);
            set_Battery_Charge(t_Battery_Charge);
            set_Battery_Current(t_Battery_Current);
            set_US(t_US);
            set_ChestBoard_Button(t_ChestBoard_Button);
        }

    public:

        /**
         * Create a new `SensorsBodySensors`.
         */
        SensorsBodySensors(signed int t_DCM_Time = 0, float t_InertialSensor_AccX = 0.0f, float t_InertialSensor_AccY = 0.0f, float t_InertialSensor_AccZ = 0.0f, float t_InertialSensor_GyrX = 0.0f, float t_InertialSensor_GyrY = 0.0f, float t_InertialSensor_GyrZ = 0.0f, float t_InertialSensor_AngleX = 0.0f, float t_InertialSensor_AngleY = 0.0f, float t_InertialSensor_AngleZ = 0.0f, float t_InertialSensor_AccelerometerX = 0.0f, float t_InertialSensor_AccelerometerY = 0.0f, float t_InertialSensor_AccelerometerZ = 0.0f, float t_InertialSensor_GyroscopeX = 0.0f, float t_InertialSensor_GyroscopeY = 0.0f, float t_InertialSensor_GyroscopeZ = 0.0f, uint8_t t_Battery_Charge = 0, uint8_t t_Battery_Current = 0, float t_US = 0.0f, bool t_ChestBoard_Button = true) {
            this->init(t_DCM_Time, t_InertialSensor_AccX, t_InertialSensor_AccY, t_InertialSensor_AccZ, t_InertialSensor_GyrX, t_InertialSensor_GyrY, t_InertialSensor_GyrZ, t_InertialSensor_AngleX, t_InertialSensor_AngleY, t_InertialSensor_AngleZ, t_InertialSensor_AccelerometerX, t_InertialSensor_AccelerometerY, t_InertialSensor_AccelerometerZ, t_InertialSensor_GyroscopeX, t_InertialSensor_GyroscopeY, t_InertialSensor_GyroscopeZ, t_Battery_Charge, t_Battery_Current, t_US, t_ChestBoard_Button);
        }

        /**
         * Copy Constructor.
         */
        SensorsBodySensors(const SensorsBodySensors &t_other): wb_sensors_body_sensors() {
            this->init(t_other.DCM_Time(), t_other.InertialSensor_AccX(), t_other.InertialSensor_AccY(), t_other.InertialSensor_AccZ(), t_other.InertialSensor_GyrX(), t_other.InertialSensor_GyrY(), t_other.InertialSensor_GyrZ(), t_other.InertialSensor_AngleX(), t_other.InertialSensor_AngleY(), t_other.InertialSensor_AngleZ(), t_other.InertialSensor_AccelerometerX(), t_other.InertialSensor_AccelerometerY(), t_other.InertialSensor_AccelerometerZ(), t_other.InertialSensor_GyroscopeX(), t_other.InertialSensor_GyroscopeY(), t_other.InertialSensor_GyroscopeZ(), t_other.Battery_Charge(), t_other.Battery_Current(), t_other.US(), t_other.ChestBoard_Button());
        }

        /**
         * Copy Constructor.
         */
        SensorsBodySensors(const struct wb_sensors_body_sensors &t_other): wb_sensors_body_sensors() {
            this->init(t_other.DCM_Time, t_other.InertialSensor_AccX, t_other.InertialSensor_AccY, t_other.InertialSensor_AccZ, t_other.InertialSensor_GyrX, t_other.InertialSensor_GyrY, t_other.InertialSensor_GyrZ, t_other.InertialSensor_AngleX, t_other.InertialSensor_AngleY, t_other.InertialSensor_AngleZ, t_other.InertialSensor_AccelerometerX, t_other.InertialSensor_AccelerometerY, t_other.InertialSensor_AccelerometerZ, t_other.InertialSensor_GyroscopeX, t_other.InertialSensor_GyroscopeY, t_other.InertialSensor_GyroscopeZ, t_other.Battery_Charge, t_other.Battery_Current, t_other.US, t_other.ChestBoard_Button);
        }

        /**
         * Copy Assignment Operator.
         */
        SensorsBodySensors &operator = (const SensorsBodySensors &t_other) {
            this->init(t_other.DCM_Time(), t_other.InertialSensor_AccX(), t_other.InertialSensor_AccY(), t_other.InertialSensor_AccZ(), t_other.InertialSensor_GyrX(), t_other.InertialSensor_GyrY(), t_other.InertialSensor_GyrZ(), t_other.InertialSensor_AngleX(), t_other.InertialSensor_AngleY(), t_other.InertialSensor_AngleZ(), t_other.InertialSensor_AccelerometerX(), t_other.InertialSensor_AccelerometerY(), t_other.InertialSensor_AccelerometerZ(), t_other.InertialSensor_GyroscopeX(), t_other.InertialSensor_GyroscopeY(), t_other.InertialSensor_GyroscopeZ(), t_other.Battery_Charge(), t_other.Battery_Current(), t_other.US(), t_other.ChestBoard_Button());
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        SensorsBodySensors &operator = (const struct wb_sensors_body_sensors &t_other) {
            this->init(t_other.DCM_Time, t_other.InertialSensor_AccX, t_other.InertialSensor_AccY, t_other.InertialSensor_AccZ, t_other.InertialSensor_GyrX, t_other.InertialSensor_GyrY, t_other.InertialSensor_GyrZ, t_other.InertialSensor_AngleX, t_other.InertialSensor_AngleY, t_other.InertialSensor_AngleZ, t_other.InertialSensor_AccelerometerX, t_other.InertialSensor_AccelerometerY, t_other.InertialSensor_AccelerometerZ, t_other.InertialSensor_GyroscopeX, t_other.InertialSensor_GyroscopeY, t_other.InertialSensor_GyroscopeZ, t_other.Battery_Charge, t_other.Battery_Current, t_other.US, t_other.ChestBoard_Button);
            return *this;
        }

        bool operator ==(const SensorsBodySensors &t_other) const
        {
            return DCM_Time() == t_other.DCM_Time()
                && fabsf(InertialSensor_AccX() - t_other.InertialSensor_AccX()) < FLT_EPSILON
                && fabsf(InertialSensor_AccY() - t_other.InertialSensor_AccY()) < FLT_EPSILON
                && fabsf(InertialSensor_AccZ() - t_other.InertialSensor_AccZ()) < FLT_EPSILON
                && fabsf(InertialSensor_GyrX() - t_other.InertialSensor_GyrX()) < FLT_EPSILON
                && fabsf(InertialSensor_GyrY() - t_other.InertialSensor_GyrY()) < FLT_EPSILON
                && fabsf(InertialSensor_GyrZ() - t_other.InertialSensor_GyrZ()) < FLT_EPSILON
                && fabsf(InertialSensor_AngleX() - t_other.InertialSensor_AngleX()) < FLT_EPSILON
                && fabsf(InertialSensor_AngleY() - t_other.InertialSensor_AngleY()) < FLT_EPSILON
                && fabsf(InertialSensor_AngleZ() - t_other.InertialSensor_AngleZ()) < FLT_EPSILON
                && fabsf(InertialSensor_AccelerometerX() - t_other.InertialSensor_AccelerometerX()) < FLT_EPSILON
                && fabsf(InertialSensor_AccelerometerY() - t_other.InertialSensor_AccelerometerY()) < FLT_EPSILON
                && fabsf(InertialSensor_AccelerometerZ() - t_other.InertialSensor_AccelerometerZ()) < FLT_EPSILON
                && fabsf(InertialSensor_GyroscopeX() - t_other.InertialSensor_GyroscopeX()) < FLT_EPSILON
                && fabsf(InertialSensor_GyroscopeY() - t_other.InertialSensor_GyroscopeY()) < FLT_EPSILON
                && fabsf(InertialSensor_GyroscopeZ() - t_other.InertialSensor_GyroscopeZ()) < FLT_EPSILON
                && Battery_Charge() == t_other.Battery_Charge()
                && Battery_Current() == t_other.Battery_Current()
                && fabsf(US() - t_other.US()) < FLT_EPSILON
                && ChestBoard_Button() == t_other.ChestBoard_Button();
        }

        bool operator !=(const SensorsBodySensors &t_other) const
        {
            return !(*this == t_other);
        }

        bool operator ==(const wb_sensors_body_sensors &t_other) const
        {
            return *this == SensorsBodySensors(t_other);
        }

        bool operator !=(const wb_sensors_body_sensors &t_other) const
        {
            return !(*this == t_other);
        }

        signed int & DCM_Time()
        {
            return wb_sensors_body_sensors::DCM_Time;
        }

        const signed int & DCM_Time() const
        {
            return wb_sensors_body_sensors::DCM_Time;
        }

        void set_DCM_Time(const signed int &t_newValue)
        {
            wb_sensors_body_sensors::DCM_Time = t_newValue;
        }

        float & InertialSensor_AccX()
        {
            return wb_sensors_body_sensors::InertialSensor_AccX;
        }

        const float & InertialSensor_AccX() const
        {
            return wb_sensors_body_sensors::InertialSensor_AccX;
        }

        void set_InertialSensor_AccX(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AccX = t_newValue;
        }

        float & InertialSensor_AccY()
        {
            return wb_sensors_body_sensors::InertialSensor_AccY;
        }

        const float & InertialSensor_AccY() const
        {
            return wb_sensors_body_sensors::InertialSensor_AccY;
        }

        void set_InertialSensor_AccY(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AccY = t_newValue;
        }

        float & InertialSensor_AccZ()
        {
            return wb_sensors_body_sensors::InertialSensor_AccZ;
        }

        const float & InertialSensor_AccZ() const
        {
            return wb_sensors_body_sensors::InertialSensor_AccZ;
        }

        void set_InertialSensor_AccZ(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AccZ = t_newValue;
        }

        float & InertialSensor_GyrX()
        {
            return wb_sensors_body_sensors::InertialSensor_GyrX;
        }

        const float & InertialSensor_GyrX() const
        {
            return wb_sensors_body_sensors::InertialSensor_GyrX;
        }

        void set_InertialSensor_GyrX(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_GyrX = t_newValue;
        }

        float & InertialSensor_GyrY()
        {
            return wb_sensors_body_sensors::InertialSensor_GyrY;
        }

        const float & InertialSensor_GyrY() const
        {
            return wb_sensors_body_sensors::InertialSensor_GyrY;
        }

        void set_InertialSensor_GyrY(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_GyrY = t_newValue;
        }

        float & InertialSensor_GyrZ()
        {
            return wb_sensors_body_sensors::InertialSensor_GyrZ;
        }

        const float & InertialSensor_GyrZ() const
        {
            return wb_sensors_body_sensors::InertialSensor_GyrZ;
        }

        void set_InertialSensor_GyrZ(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_GyrZ = t_newValue;
        }

        float & InertialSensor_AngleX()
        {
            return wb_sensors_body_sensors::InertialSensor_AngleX;
        }

        const float & InertialSensor_AngleX() const
        {
            return wb_sensors_body_sensors::InertialSensor_AngleX;
        }

        void set_InertialSensor_AngleX(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AngleX = t_newValue;
        }

        float & InertialSensor_AngleY()
        {
            return wb_sensors_body_sensors::InertialSensor_AngleY;
        }

        const float & InertialSensor_AngleY() const
        {
            return wb_sensors_body_sensors::InertialSensor_AngleY;
        }

        void set_InertialSensor_AngleY(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AngleY = t_newValue;
        }

        float & InertialSensor_AngleZ()
        {
            return wb_sensors_body_sensors::InertialSensor_AngleZ;
        }

        const float & InertialSensor_AngleZ() const
        {
            return wb_sensors_body_sensors::InertialSensor_AngleZ;
        }

        void set_InertialSensor_AngleZ(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AngleZ = t_newValue;
        }

        float & InertialSensor_AccelerometerX()
        {
            return wb_sensors_body_sensors::InertialSensor_AccelerometerX;
        }

        const float & InertialSensor_AccelerometerX() const
        {
            return wb_sensors_body_sensors::InertialSensor_AccelerometerX;
        }

        void set_InertialSensor_AccelerometerX(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AccelerometerX = t_newValue;
        }

        float & InertialSensor_AccelerometerY()
        {
            return wb_sensors_body_sensors::InertialSensor_AccelerometerY;
        }

        const float & InertialSensor_AccelerometerY() const
        {
            return wb_sensors_body_sensors::InertialSensor_AccelerometerY;
        }

        void set_InertialSensor_AccelerometerY(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AccelerometerY = t_newValue;
        }

        float & InertialSensor_AccelerometerZ()
        {
            return wb_sensors_body_sensors::InertialSensor_AccelerometerZ;
        }

        const float & InertialSensor_AccelerometerZ() const
        {
            return wb_sensors_body_sensors::InertialSensor_AccelerometerZ;
        }

        void set_InertialSensor_AccelerometerZ(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_AccelerometerZ = t_newValue;
        }

        float & InertialSensor_GyroscopeX()
        {
            return wb_sensors_body_sensors::InertialSensor_GyroscopeX;
        }

        const float & InertialSensor_GyroscopeX() const
        {
            return wb_sensors_body_sensors::InertialSensor_GyroscopeX;
        }

        void set_InertialSensor_GyroscopeX(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_GyroscopeX = t_newValue;
        }

        float & InertialSensor_GyroscopeY()
        {
            return wb_sensors_body_sensors::InertialSensor_GyroscopeY;
        }

        const float & InertialSensor_GyroscopeY() const
        {
            return wb_sensors_body_sensors::InertialSensor_GyroscopeY;
        }

        void set_InertialSensor_GyroscopeY(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_GyroscopeY = t_newValue;
        }

        float & InertialSensor_GyroscopeZ()
        {
            return wb_sensors_body_sensors::InertialSensor_GyroscopeZ;
        }

        const float & InertialSensor_GyroscopeZ() const
        {
            return wb_sensors_body_sensors::InertialSensor_GyroscopeZ;
        }

        void set_InertialSensor_GyroscopeZ(const float &t_newValue)
        {
            wb_sensors_body_sensors::InertialSensor_GyroscopeZ = t_newValue;
        }

        uint8_t & Battery_Charge()
        {
            return wb_sensors_body_sensors::Battery_Charge;
        }

        const uint8_t & Battery_Charge() const
        {
            return wb_sensors_body_sensors::Battery_Charge;
        }

        void set_Battery_Charge(const uint8_t &t_newValue)
        {
            wb_sensors_body_sensors::Battery_Charge = t_newValue;
        }

        uint8_t & Battery_Current()
        {
            return wb_sensors_body_sensors::Battery_Current;
        }

        const uint8_t & Battery_Current() const
        {
            return wb_sensors_body_sensors::Battery_Current;
        }

        void set_Battery_Current(const uint8_t &t_newValue)
        {
            wb_sensors_body_sensors::Battery_Current = t_newValue;
        }

        float & US()
        {
            return wb_sensors_body_sensors::US;
        }

        const float & US() const
        {
            return wb_sensors_body_sensors::US;
        }

        void set_US(const float &t_newValue)
        {
            wb_sensors_body_sensors::US = t_newValue;
        }

        bool & ChestBoard_Button()
        {
            return wb_sensors_body_sensors::ChestBoard_Button;
        }

        const bool & ChestBoard_Button() const
        {
            return wb_sensors_body_sensors::ChestBoard_Button;
        }

        void set_ChestBoard_Button(const bool &t_newValue)
        {
            wb_sensors_body_sensors::ChestBoard_Button = t_newValue;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        SensorsBodySensors(const std::string &t_str) {
            this->init();
            this->from_string(t_str);
        }

        std::string description() {
#ifdef USE_WB_SENSORS_BODY_SENSORS_C_CONVERSION
            char buffer[SENSORS_BODY_SENSORS_DESC_BUFFER_SIZE];
            wb_sensors_body_sensors_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "DCM_Time=" << static_cast<signed>(this->DCM_Time());
            ss << ", ";
            ss << "InertialSensor_AccX=" << this->InertialSensor_AccX();
            ss << ", ";
            ss << "InertialSensor_AccY=" << this->InertialSensor_AccY();
            ss << ", ";
            ss << "InertialSensor_AccZ=" << this->InertialSensor_AccZ();
            ss << ", ";
            ss << "InertialSensor_GyrX=" << this->InertialSensor_GyrX();
            ss << ", ";
            ss << "InertialSensor_GyrY=" << this->InertialSensor_GyrY();
            ss << ", ";
            ss << "InertialSensor_GyrZ=" << this->InertialSensor_GyrZ();
            ss << ", ";
            ss << "InertialSensor_AngleX=" << this->InertialSensor_AngleX();
            ss << ", ";
            ss << "InertialSensor_AngleY=" << this->InertialSensor_AngleY();
            ss << ", ";
            ss << "InertialSensor_AngleZ=" << this->InertialSensor_AngleZ();
            ss << ", ";
            ss << "InertialSensor_AccelerometerX=" << this->InertialSensor_AccelerometerX();
            ss << ", ";
            ss << "InertialSensor_AccelerometerY=" << this->InertialSensor_AccelerometerY();
            ss << ", ";
            ss << "InertialSensor_AccelerometerZ=" << this->InertialSensor_AccelerometerZ();
            ss << ", ";
            ss << "InertialSensor_GyroscopeX=" << this->InertialSensor_GyroscopeX();
            ss << ", ";
            ss << "InertialSensor_GyroscopeY=" << this->InertialSensor_GyroscopeY();
            ss << ", ";
            ss << "InertialSensor_GyroscopeZ=" << this->InertialSensor_GyroscopeZ();
            ss << ", ";
            ss << "Battery_Charge=" << static_cast<unsigned>(this->Battery_Charge());
            ss << ", ";
            ss << "Battery_Current=" << static_cast<unsigned>(this->Battery_Current());
            ss << ", ";
            ss << "US=" << this->US();
            ss << ", ";
            ss << "ChestBoard_Button=" << (this->ChestBoard_Button() ? "true" : "false");
            return ss.str();
#endif /// USE_WB_SENSORS_BODY_SENSORS_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_SENSORS_BODY_SENSORS_C_CONVERSION
            char buffer[SENSORS_BODY_SENSORS_TO_STRING_BUFFER_SIZE];
            wb_sensors_body_sensors_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << static_cast<signed>(this->DCM_Time());
            ss << ", ";
            ss << this->InertialSensor_AccX();
            ss << ", ";
            ss << this->InertialSensor_AccY();
            ss << ", ";
            ss << this->InertialSensor_AccZ();
            ss << ", ";
            ss << this->InertialSensor_GyrX();
            ss << ", ";
            ss << this->InertialSensor_GyrY();
            ss << ", ";
            ss << this->InertialSensor_GyrZ();
            ss << ", ";
            ss << this->InertialSensor_AngleX();
            ss << ", ";
            ss << this->InertialSensor_AngleY();
            ss << ", ";
            ss << this->InertialSensor_AngleZ();
            ss << ", ";
            ss << this->InertialSensor_AccelerometerX();
            ss << ", ";
            ss << this->InertialSensor_AccelerometerY();
            ss << ", ";
            ss << this->InertialSensor_AccelerometerZ();
            ss << ", ";
            ss << this->InertialSensor_GyroscopeX();
            ss << ", ";
            ss << this->InertialSensor_GyroscopeY();
            ss << ", ";
            ss << this->InertialSensor_GyroscopeZ();
            ss << ", ";
            ss << static_cast<unsigned>(this->Battery_Charge());
            ss << ", ";
            ss << static_cast<unsigned>(this->Battery_Current());
            ss << ", ";
            ss << this->US();
            ss << ", ";
            ss << (this->ChestBoard_Button() ? "true" : "false");
            return ss.str();
#endif /// USE_WB_SENSORS_BODY_SENSORS_C_CONVERSION
        }

#ifdef USE_WB_SENSORS_BODY_SENSORS_C_CONVERSION
        void from_string(const std::string &t_str) {
            wb_sensors_body_sensors_from_string(this, t_str.c_str());
#else
        void from_string(const std::string &t_str) {
            char * str_cstr = const_cast<char *>(t_str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1 || length > SENSORS_BODY_SENSORS_DESC_BUFFER_SIZE) {
                return;
            }
            char var_str_buffer[SENSORS_BODY_SENSORS_DESC_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[30];
            char* key = &key_buffer[0];
            int bracecount = 0;
            int startVar = 0;
            int index = 0;
            int startKey = 0;
            int endKey = -1;
            int varIndex = 0;
            if (index == 0 && str_cstr[0] == '{') {
                index = 1;
            }
            startVar = index;
            startKey = startVar;
            do {
                for (int i = index; i < length; i++) {
                    index = i + 1;
                    if (bracecount == 0 && str_cstr[i] == '=') {
                        endKey = i - 1;
                        startVar = index;
                        continue;
                    }
                    if (bracecount == 0 && isspace(str_cstr[i])) {
                        startVar = index;
                        if (endKey == -1) {
                            startKey = index;
                        }
                        continue;
                    }
                    if (bracecount == 0 && str_cstr[i] == ',') {
                        index = i - 1;
                        break;
                    }
                    if (str_cstr[i] == '{') {
                        bracecount++;
                        continue;
                    }
                    if (str_cstr[i] == '}') {
                        bracecount--;
                        if (bracecount < 0) {
                            index = i - 1;
                            break;
                        }
                    }
                    if (i == length - 1) {
                        index = i;
                    }
                }
                if (endKey >= startKey && endKey - startKey < length) {
                    strncpy(key, str_cstr + startKey, static_cast<size_t>((endKey - startKey) + 1));
                    key[(endKey - startKey) + 1] = 0;
                } else {
                    key[0] = 0;
                }
                strncpy(var_str, str_cstr + startVar, static_cast<size_t>((index - startVar) + 1));
                var_str[(index - startVar) + 1] = 0;
                bracecount = 0;
                index += 2;
                startVar = index;
                startKey = startVar;
                endKey = -1;
                if (strlen(key) > 0) {
                    if (0 == strcmp("DCM_Time", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("InertialSensor_AccX", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("InertialSensor_AccY", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("InertialSensor_AccZ", key)) {
                        varIndex = 3;
                    } else if (0 == strcmp("InertialSensor_GyrX", key)) {
                        varIndex = 4;
                    } else if (0 == strcmp("InertialSensor_GyrY", key)) {
                        varIndex = 5;
                    } else if (0 == strcmp("InertialSensor_GyrZ", key)) {
                        varIndex = 6;
                    } else if (0 == strcmp("InertialSensor_AngleX", key)) {
                        varIndex = 7;
                    } else if (0 == strcmp("InertialSensor_AngleY", key)) {
                        varIndex = 8;
                    } else if (0 == strcmp("InertialSensor_AngleZ", key)) {
                        varIndex = 9;
                    } else if (0 == strcmp("InertialSensor_AccelerometerX", key)) {
                        varIndex = 10;
                    } else if (0 == strcmp("InertialSensor_AccelerometerY", key)) {
                        varIndex = 11;
                    } else if (0 == strcmp("InertialSensor_AccelerometerZ", key)) {
                        varIndex = 12;
                    } else if (0 == strcmp("InertialSensor_GyroscopeX", key)) {
                        varIndex = 13;
                    } else if (0 == strcmp("InertialSensor_GyroscopeY", key)) {
                        varIndex = 14;
                    } else if (0 == strcmp("InertialSensor_GyroscopeZ", key)) {
                        varIndex = 15;
                    } else if (0 == strcmp("Battery_Charge", key)) {
                        varIndex = 16;
                    } else if (0 == strcmp("Battery_Current", key)) {
                        varIndex = 17;
                    } else if (0 == strcmp("US", key)) {
                        varIndex = 18;
                    } else if (0 == strcmp("ChestBoard_Button", key)) {
                        varIndex = 19;
                    } else {
                        varIndex = -1;
                    }
                }
                switch (varIndex) {
                    case -1: { break; }
                    case 0:
                    {
                        this->set_DCM_Time(static_cast<signed int>(atoi(var_str)));
                        break;
                    }
                    case 1:
                    {
                        this->set_InertialSensor_AccX(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 2:
                    {
                        this->set_InertialSensor_AccY(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_InertialSensor_AccZ(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 4:
                    {
                        this->set_InertialSensor_GyrX(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 5:
                    {
                        this->set_InertialSensor_GyrY(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 6:
                    {
                        this->set_InertialSensor_GyrZ(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 7:
                    {
                        this->set_InertialSensor_AngleX(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 8:
                    {
                        this->set_InertialSensor_AngleY(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 9:
                    {
                        this->set_InertialSensor_AngleZ(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 10:
                    {
                        this->set_InertialSensor_AccelerometerX(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 11:
                    {
                        this->set_InertialSensor_AccelerometerY(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 12:
                    {
                        this->set_InertialSensor_AccelerometerZ(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 13:
                    {
                        this->set_InertialSensor_GyroscopeX(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 14:
                    {
                        this->set_InertialSensor_GyroscopeY(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 15:
                    {
                        this->set_InertialSensor_GyroscopeZ(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 16:
                    {
                        this->set_Battery_Charge(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 17:
                    {
                        this->set_Battery_Current(static_cast<uint8_t>(atoi(var_str)));
                        break;
                    }
                    case 18:
                    {
                        this->set_US(static_cast<float>(atof(var_str)));
                        break;
                    }
                    case 19:
                    {
                        this->set_ChestBoard_Button(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                }
                if (varIndex >= 0) {
                    varIndex++;
                }
            } while(index < length);
#endif /// USE_WB_SENSORS_BODY_SENSORS_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

} /// namespace guWhiteboard

#endif /// guWhiteboard_SensorsBodySensors_h
