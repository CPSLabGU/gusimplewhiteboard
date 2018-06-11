/*
 * file VisionControlStatus.h
 *
 * This file was generated by classgenerator from vision_control_status.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Eugene Gilmore at 13:30, 11/06/2018.
 * Copyright © 2018 Eugene Gilmore. All rights reserved.
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
 *        This product includes software developed by Eugene Gilmore.
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

#ifndef VisionControlStatus_DEFINED
#define VisionControlStatus_DEFINED

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <cstdlib>
#include <string.h>
#include <sstream>
#endif

#include <gu_util.h>
#include "wb_vision_control_status.h"

namespace guWhiteboard {

    /**
     * Provides a C++ wrapper around `wb_vision_control_status`.
     */
    class VisionControlStatus: public wb_vision_control_status {

    public:

        /**
         * Create a new `VisionControlStatus`.
         */
        VisionControlStatus(enum Resolutions cameraResolution = VGA, bool pipelineRunning = true, enum VisionCamera selectedCamera = Top, enum SaveFileType saveImage = None, bool saveClassifiedImage = false, enum NamedPipeline pipeline = Soccer, enum StreamingType streamingSource = Normal, bool imageInput = false, int jpegStreamQuality = 30, int jpegStreamStride = 4, int frameRate = 0, bool runPipelineOnce = false, uint64_t frameNumber = 0, std::string colourCalibration = "class") {
            set_cameraResolution(cameraResolution);
            set_pipelineRunning(pipelineRunning);
            set_selectedCamera(selectedCamera);
            set_saveImage(saveImage);
            set_saveClassifiedImage(saveClassifiedImage);
            set_pipeline(pipeline);
            set_streamingSource(streamingSource);
            set_imageInput(imageInput);
            set_jpegStreamQuality(jpegStreamQuality);
            set_jpegStreamStride(jpegStreamStride);
            set_frameRate(frameRate);
            set_runPipelineOnce(runPipelineOnce);
            set_frameNumber(frameNumber);
            gu_strlcpy(const_cast<char *>(this->colourCalibration()), colourCalibration.c_str(), 10);
        }

        /**
         * Copy Constructor.
         */
        VisionControlStatus(const VisionControlStatus &other): wb_vision_control_status() {
            set_cameraResolution(other.cameraResolution());
            set_pipelineRunning(other.pipelineRunning());
            set_selectedCamera(other.selectedCamera());
            set_saveImage(other.saveImage());
            set_saveClassifiedImage(other.saveClassifiedImage());
            set_pipeline(other.pipeline());
            set_streamingSource(other.streamingSource());
            set_imageInput(other.imageInput());
            set_jpegStreamQuality(other.jpegStreamQuality());
            set_jpegStreamStride(other.jpegStreamStride());
            set_frameRate(other.frameRate());
            set_runPipelineOnce(other.runPipelineOnce());
            set_frameNumber(other.frameNumber());
            gu_strlcpy(const_cast<char *>(this->colourCalibration()), other.colourCalibration(), 10);
        }

        /**
         * Copy Constructor.
         */
        VisionControlStatus(const struct wb_vision_control_status &other): wb_vision_control_status() {
            set_cameraResolution(other.cameraResolution());
            set_pipelineRunning(other.pipelineRunning());
            set_selectedCamera(other.selectedCamera());
            set_saveImage(other.saveImage());
            set_saveClassifiedImage(other.saveClassifiedImage());
            set_pipeline(other.pipeline());
            set_streamingSource(other.streamingSource());
            set_imageInput(other.imageInput());
            set_jpegStreamQuality(other.jpegStreamQuality());
            set_jpegStreamStride(other.jpegStreamStride());
            set_frameRate(other.frameRate());
            set_runPipelineOnce(other.runPipelineOnce());
            set_frameNumber(other.frameNumber());
            gu_strlcpy(const_cast<char *>(this->colourCalibration()), other.colourCalibration(), 10);
        }

        /**
         * Copy Assignment Operator.
         */
        VisionControlStatus &operator = (const VisionControlStatus &other) {
            set_cameraResolution(other.cameraResolution());
            set_pipelineRunning(other.pipelineRunning());
            set_selectedCamera(other.selectedCamera());
            set_saveImage(other.saveImage());
            set_saveClassifiedImage(other.saveClassifiedImage());
            set_pipeline(other.pipeline());
            set_streamingSource(other.streamingSource());
            set_imageInput(other.imageInput());
            set_jpegStreamQuality(other.jpegStreamQuality());
            set_jpegStreamStride(other.jpegStreamStride());
            set_frameRate(other.frameRate());
            set_runPipelineOnce(other.runPipelineOnce());
            set_frameNumber(other.frameNumber());
            gu_strlcpy(const_cast<char *>(this->colourCalibration()), other.colourCalibration(), 10);
            return *this;
        }

        /**
         * Copy Assignment Operator.
         */
        VisionControlStatus &operator = (const struct wb_vision_control_status &other) {
            set_cameraResolution(other.cameraResolution());
            set_pipelineRunning(other.pipelineRunning());
            set_selectedCamera(other.selectedCamera());
            set_saveImage(other.saveImage());
            set_saveClassifiedImage(other.saveClassifiedImage());
            set_pipeline(other.pipeline());
            set_streamingSource(other.streamingSource());
            set_imageInput(other.imageInput());
            set_jpegStreamQuality(other.jpegStreamQuality());
            set_jpegStreamStride(other.jpegStreamStride());
            set_frameRate(other.frameRate());
            set_runPipelineOnce(other.runPipelineOnce());
            set_frameNumber(other.frameNumber());
            gu_strlcpy(const_cast<char *>(this->colourCalibration()), other.colourCalibration(), 10);
            return *this;
        }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        /**
         * String Constructor.
         */
        VisionControlStatus(const std::string &str) { wb_vision_control_status_from_string(this, str.c_str()); }

        std::string description() {
#ifdef USE_WB_VISION_CONTROL_STATUS_C_CONVERSION
            char buffer[VISION_CONTROL_STATUS_DESC_BUFFER_SIZE];
            wb_vision_control_status_description(this, buffer, sizeof(buffer));
            std::string descr = buffer;
            return descr;
#else
            std::ostringstream ss;
            ss << "cameraResolution=" << this->cameraResolution();
            ss << ", ";
            ss << "pipelineRunning=" << (this->pipelineRunning() ? "true" : "false");
            ss << ", ";
            ss << "selectedCamera=" << this->selectedCamera();
            ss << ", ";
            ss << "saveImage=" << this->saveImage();
            ss << ", ";
            ss << "saveClassifiedImage=" << (this->saveClassifiedImage() ? "true" : "false");
            ss << ", ";
            ss << "pipeline=" << this->pipeline();
            ss << ", ";
            ss << "streamingSource=" << this->streamingSource();
            ss << ", ";
            ss << "imageInput=" << (this->imageInput() ? "true" : "false");
            ss << ", ";
            ss << "jpegStreamQuality=" << static_cast<signed>(this->jpegStreamQuality());
            ss << ", ";
            ss << "jpegStreamStride=" << static_cast<signed>(this->jpegStreamStride());
            ss << ", ";
            ss << "frameRate=" << static_cast<signed>(this->frameRate());
            ss << ", ";
            ss << "runPipelineOnce=" << (this->runPipelineOnce() ? "true" : "false");
            ss << ", ";
            ss << "frameNumber=" << this->frameNumber();
            ss << ", ";
            if (0 == strncmp("", this->colourCalibration(), 1)) {
                ss << "colourCalibration=" << "";
            } else {
                ss << "colourCalibration=" << this->colourCalibration();
            }
            return ss.str();
#endif /// USE_WB_VISION_CONTROL_STATUS_C_CONVERSION
        }

        std::string to_string() {
#ifdef USE_WB_VISION_CONTROL_STATUS_C_CONVERSION
            char buffer[VISION_CONTROL_STATUS_TO_STRING_BUFFER_SIZE];
            wb_vision_control_status_to_string(this, buffer, sizeof(buffer));
            std::string toString = buffer;
            return toString;
#else
            std::ostringstream ss;
            ss << this->cameraResolution();
            ss << ", ";
            ss << (this->pipelineRunning() ? "true" : "false");
            ss << ", ";
            ss << this->selectedCamera();
            ss << ", ";
            ss << this->saveImage();
            ss << ", ";
            ss << (this->saveClassifiedImage() ? "true" : "false");
            ss << ", ";
            ss << this->pipeline();
            ss << ", ";
            ss << this->streamingSource();
            ss << ", ";
            ss << (this->imageInput() ? "true" : "false");
            ss << ", ";
            ss << static_cast<signed>(this->jpegStreamQuality());
            ss << ", ";
            ss << static_cast<signed>(this->jpegStreamStride());
            ss << ", ";
            ss << static_cast<signed>(this->frameRate());
            ss << ", ";
            ss << (this->runPipelineOnce() ? "true" : "false");
            ss << ", ";
            ss << this->frameNumber();
            ss << ", ";
            if (0 == strncmp("", this->colourCalibration(), 1)) {
                ss << "";
            } else {
                ss << this->colourCalibration();
            }
            return ss.str();
#endif /// USE_WB_VISION_CONTROL_STATUS_C_CONVERSION
        }

#ifdef USE_WB_VISION_CONTROL_STATUS_C_CONVERSION
        void from_string(const std::string &str) {
            wb_vision_control_status_from_string(this, str.c_str());
#else
        void from_string(const std::string &str) {
            char * str_cstr = const_cast<char *>(str.c_str());
            size_t temp_length = strlen(str_cstr);
            int length = (temp_length <= INT_MAX) ? static_cast<int>(static_cast<ssize_t>(temp_length)) : -1;
            if (length < 1) {
                return;
            }
            char var_str_buffer[VISION_CONTROL_STATUS_TO_STRING_BUFFER_SIZE + 1];
            char* var_str = &var_str_buffer[0];
            char key_buffer[20];
            char* key = &key_buffer[0];
            int bracecount = 0;
            int lastBrace = -1;
            int startVar = 0;
            int index = 0;
            int startKey = 0;
            int endKey = 0;
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
                        if (bracecount == 1) {
                            lastBrace = i;
                        }
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
                    strncpy(key, str_cstr + startKey, (endKey - startKey) + 1);
                    key[(endKey - startKey) + 1] = 0;
                } else {
                    key[0] = 0;
                }
                strncpy(var_str, str_cstr + startVar, (index - startVar) + 1);
                var_str[(index - startVar) + 1] = 0;
                bracecount = 0;
                index += 2;
                startVar = index;
                startKey = startVar;
                endKey = -1;
                if (key != NULLPTR) {
                    if (0 == strcmp("cameraResolution", key)) {
                        varIndex = 0;
                    } else if (0 == strcmp("pipelineRunning", key)) {
                        varIndex = 1;
                    } else if (0 == strcmp("selectedCamera", key)) {
                        varIndex = 2;
                    } else if (0 == strcmp("saveImage", key)) {
                        varIndex = 3;
                    } else if (0 == strcmp("saveClassifiedImage", key)) {
                        varIndex = 4;
                    } else if (0 == strcmp("pipeline", key)) {
                        varIndex = 5;
                    } else if (0 == strcmp("streamingSource", key)) {
                        varIndex = 6;
                    } else if (0 == strcmp("imageInput", key)) {
                        varIndex = 7;
                    } else if (0 == strcmp("jpegStreamQuality", key)) {
                        varIndex = 8;
                    } else if (0 == strcmp("jpegStreamStride", key)) {
                        varIndex = 9;
                    } else if (0 == strcmp("frameRate", key)) {
                        varIndex = 10;
                    } else if (0 == strcmp("runPipelineOnce", key)) {
                        varIndex = 11;
                    } else if (0 == strcmp("frameNumber", key)) {
                        varIndex = 12;
                    } else if (0 == strcmp("colourCalibration", key)) {
                        varIndex = 13;
                    }
                }
                switch (varIndex) {
                    case 0:
                    {
                        this->set_cameraResolution(static_cast<enum Resolutions>(atoi(var_str)));
                        break;
                    }
                    case 1:
                    {
                        this->set_pipelineRunning(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 2:
                    {
                        this->set_selectedCamera(static_cast<enum VisionCamera>(atoi(var_str)));
                        break;
                    }
                    case 3:
                    {
                        this->set_saveImage(static_cast<enum SaveFileType>(atoi(var_str)));
                        break;
                    }
                    case 4:
                    {
                        this->set_saveClassifiedImage(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 5:
                    {
                        this->set_pipeline(static_cast<enum NamedPipeline>(atoi(var_str)));
                        break;
                    }
                    case 6:
                    {
                        this->set_streamingSource(static_cast<enum StreamingType>(atoi(var_str)));
                        break;
                    }
                    case 7:
                    {
                        this->set_imageInput(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 8:
                    {
                        this->set_jpegStreamQuality(static_cast<int>(atoi(var_str)));
                        break;
                    }
                    case 9:
                    {
                        this->set_jpegStreamStride(static_cast<int>(atoi(var_str)));
                        break;
                    }
                    case 10:
                    {
                        this->set_frameRate(static_cast<int>(atoi(var_str)));
                        break;
                    }
                    case 11:
                    {
                        this->set_runPipelineOnce(strcmp(var_str, "true") == 0 || strcmp(var_str, "1") == 0);
                        break;
                    }
                    case 12:
                    {
                        this->set_frameNumber(static_cast<uint64_t>(atoll(var_str)));
                        break;
                    }
                    case 13:
                    {
                        strncpy(this->colourCalibration(), var_str, 10);
                        break;
                    }
                }
                varIndex++;
            } while(index < length);
#endif /// USE_WB_VISION_CONTROL_STATUS_C_CONVERSION
        }
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION
    };

    /**
     * @brief Resolution wrapper class for Resolutions enum
     * Contains a Resolution and provides a number of convenience
     * methods for each resolution. Width Height etc.
     */
    class ResolutionType {
    private:
    	/** The resolution that this object should work with*/
    	PROPERTY(Resolutions, resolution)
    public:
    	/**
    	 * @brief Constructor using value from Resolutions enum
    	 * @param res The resolution to use
    	*/
    	ResolutionType(Resolutions res = VGA): _resolution(res) {}

    	/** get the width of the current resolution */
    	int width() const
    	{
    		static const int Widths[] = {160, 320, 640, 1280, 800};
    		return Widths[_resolution];
    	}

    	/** get the height of the current resolution */
    	int height() const
    	{
    		static const int Heights[] = {120, 240, 480, 960, 600};
    		return Heights[_resolution];
    	}
    };

} /// namespace guWhiteboard
#endif /// VisionControlStatus_DEFINED
