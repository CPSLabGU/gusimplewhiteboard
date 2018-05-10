/*
 * file wb_vision_status_control.h
 *
 * This file was generated by classgenerator from vision_status_control.gen.
 * DO NOT CHANGE MANUALLY!
 *
 * Created by Eugene Gilmore at 17:06, 10/05/2018.
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

#ifndef wb_vision_status_control_h
#define wb_vision_status_control_h

#ifdef __linux
# ifndef _POSIX_SOURCE
#  define _POSIX_SOURCE 200112L
# endif
#endif
#ifndef _XOPEN_SOURCE
# define _XOPEN_SOURCE 700
#endif
#ifdef __APPLE__
# ifndef _DARWIN_C_SOURCE
#  define _DARWIN_C_SOURCE 200112L
# endif
# ifndef __DARWIN_C_LEVEL
#  define __DARWIN_C_LEVEL 200112L
# endif
#endif

#include <gu_util.h>
#include <stdint.h>

/**
 * @brief Resolutions Supported by Vision
 */
enum Resolutions {
	QQVGA,  ///< 160 x 120
	QVGA,   ///< 320 x 240
	VGA,    ///< 640 x 480
	HD_4VGA,    ///< 1280x960
	SVGA   ///< 800 x 600
};

/**
 * @brief Enum of available camera's that can be used by vision
 */
enum VisionCamera {
	Top, ///< Top Camera on the nao
	Bottom ///< Bottom Camera on the nao
};

/**
 * @brief Enum listing available vision pipelines
 */
enum NamedPipeline {
	Soccer, ///< Soccer Pipeline
	OpenChallenge, ///< 2013 Open Challange Pipeline
	Streaming, ///< Pipeline that just streams images
	Neural_Network, ///< Pipeline to rec objects with a nn
	OpenCVFaces, ///< Pipeline to recognise faces
	HTWK  ///<Pipeline that runs htwk's image algorithms and post soccer object info to mipal whiteboard
};

/**
 * @brief Streaming modes available in vision
 */
enum StreamingType {
	Normal, ///< Images straight from camera
	Classified, ///<Images that has been segmented into recognised colours
	Recognized ///< Image showing only objects that have been recognised NYI
};

/**
 * @brief List of file types that vision can save images as
 */
enum SaveFileType {
	AI2, ///< Raw YUV422 Image
	JPG, ///< Compressed JPEG
	None
};

#define VISION_STATUS_CONTROL_GENERATED 
#define VISION_STATUS_CONTROL_C_STRUCT wb_vision_status_control 
#define VISION_STATUS_CONTROL_NUMBER_OF_VARIABLES 14

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#define VISION_STATUS_CONTROL_DESC_BUFFER_SIZE 1600
#define VISION_STATUS_CONTROL_TO_STRING_BUFFER_SIZE 1395
#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

/**
 * The control status message used by guvision, guvision will post the current state of the pipeline once a frame with the message, various properties can also be set by post a vision_controll message with this type
 */
struct wb_vision_status_control
{

    /**
     * Resolution that the camera should caputre images at
     */
    PROPERTY(enum Resolutions, cameraResolution)

    /**
     * Whether the pipeline is running or not
     */
    PROPERTY(bool, pipelineRunning)

    /**
     * Which camera to use
     */
    PROPERTY(enum VisionCamera, selectedCamera)

    /**
     * Whether to save the image used in the next iteration of the pipeline to file
     */
    PROPERTY(enum SaveFileType, saveImage)

    /**
     * Whether to save the classified version of the image used in the next iteration of the pipeline to file
     */
    PROPERTY(bool, saveClassifiedImage)

    /**
     * vision pipeline to be run
     */
    PROPERTY(enum NamedPipeline, pipeline)

    /**
     * The type of streaming to be used
     */
    PROPERTY(enum StreamingType, streamingSource)

    /**
     * Use /tmp/test.ai2 as pipeline image rather then camera if true
     */
    PROPERTY(bool, imageInput)

    /**
     * The quality to compress jpeg images at for streaming can be between 0 and 100
     */
    PROPERTY(int, jpegStreamQuality)

    /**
     * The stride to use when streaming jpeg images
     */
    PROPERTY(int, jpegStreamStride)

    /**
     * The current framerate that the pipeline is running at
     */
    PROPERTY(int, frameRate)

    /**
     * run the pipeline one time only if true
     */
    PROPERTY(bool, runPipelineOnce)

    /**
     * The current frame number reported by guvison
     */
    PROPERTY(uint64_t, frameNumber)

    /**
     * the DLC file to use for segmentation, searched in $HOME/data/ with the .dlc extension
     */
    STRING_PROPERTY(colourCalibration, 20)

};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

/**
 * Convert to a description string.
 */
const char* wb_vision_status_control_description(const struct wb_vision_status_control* self, char* descString, size_t bufferSize);

/**
 * Convert to a string.
 */
const char* wb_vision_status_control_to_string(const struct wb_vision_status_control* self, char* toString, size_t bufferSize);

/**
 * Convert from a string.
 */
struct wb_vision_status_control* wb_vision_status_control_from_string(struct wb_vision_status_control* self, const char* str);

#endif /// WHITEBOARD_POSTER_STRING_CONVERSION

/*#ifdef WHITEBOARD_SERIALISATION*/

/**
 * Network stream serialisation
 */
size_t wb_vision_status_control_to_network_serialised(const struct wb_vision_status_control *self, char *dst);

/**
 * Network stream deserialisation
 */
size_t wb_vision_status_control_from_network_serialised(const char *src, struct wb_vision_status_control *dst);

/*#endif /// WHITEBOARD_SERIALISATION*/

#ifdef __cplusplus
}
#endif

#endif /// wb_vision_status_control_h
