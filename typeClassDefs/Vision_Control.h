/**
 * /file Vision_Control.h
 *
 *  Created on: 10 Apr 2013
 *      Author: Eugene Gilmore
 */

#ifndef VisionControlStatus_DEFINED
#define VisionControlStatus_DEFINED

#include <gu_util.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <stdint.h>
#include <bitset>


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"
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

	/** Deprecated: use standard getter resolution() instead! */
	int getResolution() const { return _resolution; } // XXX: deprecated, will be phased out!!!

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
	
	/** deprecated, use width() instead!
	 */
	int Width() const { return width(); }
	/** deprecated, use height() instead!
	 */
	int Height() const { return height(); }
};

#pragma clang diagnostic pop

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
	OpenCVFaces ///< Pipeline to recognise faces
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
 * @brief List of calibrations files that vision can use
 */
enum CalibrationFile {
	Calibration0, ///< ~/data/class.dlc
	Calibration1, ///< ~/data/class1.dlc
	Calibration2, ///< ~/data/class2.dlc
	Calibration3  ///< ~/data/class3.dlc
};

/**
 * @brief List of file types that vision can save images as
 */
enum SaveFileType {
    AI2, ///< Raw YUV422 Image
    JPG ///< Compressed JPEG
};

/**
 * @brief Supported Message in Vision Control/Status messages. Used internally
 */
enum VisionMessages {
		Resolution,
		PipelineRunning,
		SelectedCamera,
		SaveImage,
		SaveClassifiedImage,
		ActivatePipeline,
		StreamingSource,
		ConservativeMode,
		ImageInput,
		LoadCalibration,
		PipelineRunOnce,
		JPEGStreamQuality,
		JPEGStreamStride,
		HorizionFactor,
		NUMBER_VISION_MESSAGES
};

/**Commands Strings. Used internally*/
static const char* Commands[] = {"RESOLUTION", "RUNPIPELINE", "SELECTCAMERA", "SAVEIMAGE",
		"SAVECLASSIFIEDIMAGE", "ACTIVATEPIPELINE", "STREAMINGSOURCE", "CONSERVATIVEMODE",
		"IMAGEINPUT", "LOADCALIBRATION", "RUNPIPELINEONCE", "JPEGSTREAMQUALITY", "JPEGSTREAMSTRIDE", "HORIZIONFACTOR", "Undefined"};
/**Status Strings. Used internally*/
static const char* Statuses[] = {"Resolution", "PipelineRunning", "SelectedCamera", "SaveImage",
		"SaveClassifiedImage", "ActivePipeline", "StreamingSource", "ConservativeMode",
		"ImageInput", "CalibrationLoaded", "PipelineRunningOnce", "JPEGSTREAMQUALITY", "JPEGSTREAMSTRIDE", "HorizionFactor", "FrameRate"};

static const char* ResolutionStrings[] = {"QQVGA", "QVGA", "VGA", "HD"};
static const Resolutions ResolutionValues[] = {QQVGA, QVGA, VGA, HD_4VGA};
static const char* CameraStrings[] = {"TOP", "BOTTOM"};
static const VisionCamera CameraValues[] = {Top, Bottom};
static const char* PipelineStrings[] = {"SOCCER", "OPENCHALLENGE", "STREAMING", "OPENCVFACES"};
static const NamedPipeline PipelineValues[] = {Soccer, OpenChallenge, Streaming, OpenCVFaces};
static const char* StreamingSourceStrings[] = {"NORMAL", "CLASSIFIED", "RECOGNIZED"};
static const StreamingType StreamingSourceValues[] = {Normal, Classified, Recognized};
static const char* CalibrationStrings[] = {"CALIBRATION0", "CALIBRATION1", "CALIBRATION2", "CALIBRATION3"};
static const CalibrationFile CalibrationValues[] = {Calibration0, Calibration1, Calibration2, Calibration3};
static const char* BoolStrings[] = {"YES", "NO"};
static const bool BoolValues[] = {true, false};
static const char* SaveImageStrings[] = {"AI2", "JPG"};
static const SaveFileType SaveImageValues[] = {AI2, JPG};

static const char** MessageParamaters[] = {ResolutionStrings, BoolStrings, CameraStrings, SaveImageStrings,
		BoolStrings, PipelineStrings, StreamingSourceStrings, BoolStrings, BoolStrings, CalibrationStrings, BoolStrings};
static const uint MessageParamaterSizes[] = {sizeof(ResolutionStrings)/sizeof(char*), sizeof(BoolStrings)/sizeof(char*),
                                                sizeof(CameraStrings)/sizeof(char*), sizeof(SaveImageStrings)/sizeof(char*),
                                                sizeof(BoolStrings)/sizeof(char*), sizeof(PipelineStrings)/sizeof(char*),
                                                sizeof(StreamingSourceStrings)/sizeof(char*), sizeof(BoolStrings)/sizeof(char*),
                                                sizeof(BoolStrings)/sizeof(char*), sizeof(CalibrationStrings)/sizeof(char*),
						sizeof(BoolStrings)/sizeof(char*)};

namespace guWhiteboard
{
/**
 * @brief Class to post control messages to the vision module as well as retrieving current Status
 * This includes allows setting of various properties of the vision module. 
 * Pipeline running resolution saving image streaming settings etc. Also used as
 * a status message by the vision module to post current frame rate etc.
 * 
 * Examples
 * --------
 * 
 * Set the streaming type to normal and the resolution to VGA
 * 
 *		VisionControlStatus v;
 *		v.set_streamingSource(Normal);
 *		v.set_resolution(ResolutionType(VGA));
 *		Vision_Control_t.set(v);
 * 
 * Retrieve the current Frame Rate and Resolution
 * 
 *		VisionControlStatus v = Vision_Status_t.get(); //get the status message off the whiteboard
 *		int fr = v.frameRate(); //get the frame rate out of the message
 *		ResolutionType res = v.get_resolution();
 */
class VisionControlStatus {
public:
	/**
	 * @brief Default Constructor
     */
	VisionControlStatus() {
		memset(this, 0, sizeof(*this));
	}

	/**
	 * @brief String Constructor
     * @param s The string containing a valid serialized VisionControlStatus Message
     */
	VisionControlStatus(std::string s) {
		memset(this, 0, sizeof(*this));
		size_t n;
		std::string command;
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		for (unsigned i = 0; i<NUMBER_VISION_MESSAGES; ++i) {
			command = std::string(Commands[i]);
			n = s.find(command);
			if (n!=std::string::npos) {
                                std::string t = s.substr(n+command.length()+1);
                                if(i == HorizionFactor) {
                                    //get value
                                    set_horizionValue(static_cast<float>(atof(t.substr(0, t.find_first_not_of("-0123456789.")).c_str())));
                                    continue;
                                }
								if(i == JPEGStreamQuality) {
                                    //get value
                                    set_jpegStreamQuality(atoi(t.substr(0, t.find_first_not_of("-0123456789.")).c_str()));
                                    continue;
                                }
								if(i == JPEGStreamStride) {
                                    //get value
                                    set_jpegStreamStride(atoi(t.substr(0, t.find_first_not_of("-0123456789.")).c_str()));
                                    continue;
                                }
				for(uint j = 0; j<MessageParamaterSizes[i]; ++j) {
					if(t.compare(0, strlen(MessageParamaters[i][j]), MessageParamaters[i][j]) == 0) {
						switch(i) {
						case Resolution:
							set_resolution(ResolutionValues[j]);
							break;
						case PipelineRunning:
							set_pipelineRunning(BoolValues[j]);
							break;
						case SelectedCamera:
							set_selectedCamera(CameraValues[j]);
							break;
						case SaveImage:
							set_saveImage(SaveImageValues[j]);
							break;
						case SaveClassifiedImage:
							set_saveClassifiedImage(BoolValues[j]);
							break;
						case ActivatePipeline:
							set_activatePipeline(PipelineValues[j]);
							break;
						case StreamingSource:
							set_streamingSource(StreamingSourceValues[j]);
							break;
						case ConservativeMode:
							set_conservativeMode(BoolValues[j]);
							break;
						case ImageInput:
							set_imageInput(BoolValues[j]);
							break;
						case LoadCalibration:
							set_loadCalibration(CalibrationValues[j]);
							break;
						case PipelineRunOnce:
							set_pipelineRunOnce(BoolValues[j]);
						}
					}
				}
			}
		}
	}

	/**
	 * @brief String representation of the VisionControlStatus message
     * @return The String Representation
     */
	std::string description() const
        {
		std::stringstream result;
                
		if(resolution_mask())
			result << Statuses[0] << "=" << ResolutionStrings[resolution().getResolution()] << " ";//fixme
		if(pipelineRunning_mask())
			result << Statuses[1] << "=" << BoolStrings[pipelineRunning()?0:1] << " ";
		if(selectedCamera_mask())
			result << Statuses[2] << "=" << CameraStrings[selectedCamera()] << " ";
		if(saveImage_mask())
			result << Statuses[3] << "=" << BoolStrings[saveImage()?0:1] << " ";
		if(saveClassifiedImage_mask())
			result << Statuses[4] << "=" << BoolStrings[saveClassifiedImage()?0:1] << " ";
		if(activatePipeline_mask())
			result << Statuses[5] << "=" << PipelineStrings[activatePipeline()] << " ";
		if(streamingSource_mask())
			result << Statuses[6] << "=" << StreamingSourceStrings[streamingSource()] << " ";
		if(conservativeMode_mask())
			result << Statuses[7] << "=" << BoolStrings[conservativeMode()?0:1] << " ";
		if(imageInput_mask())
			result << Statuses[8] << "=" << BoolStrings[imageInput()?0:1] << " ";
		if(jpegStreamQuality_mask())
			result << Statuses[9] << "=" << jpegStreamQuality();
		if(jpegStreamStride_mask())
			result << Statuses[10] << "=" << jpegStreamStride();
		if(loadCalibration_mask())
			result << Statuses[11] << "=" << CalibrationStrings[loadCalibration()] << " ";
		if(pipelineRunOnce_mask())
			result << Statuses[12] << "=" << BoolStrings[pipelineRunOnce()?0:1] << " ";
                if(frameRate_mask())
                        result << Statuses[14] << "=" << frameRate() << " ";
                if(horizionValue_mask())
                    result << Statuses[13] << "=" << horizionValue();
		return result.str();
	}

	/**
	 * @brief += operator to add components of passed message with mask set to this message
     * @param a The VisionControlStatus that is added to this one where masks are set
     * @return The newly updated VisionControlStatus object
     */
	VisionControlStatus operator+=(VisionControlStatus a) {
		if(a.resolution_mask())
			this->set_resolution(a.resolution());
		if(a.pipelineRunning_mask())
			this->set_pipelineRunning(a.pipelineRunning());
		if(a.selectedCamera_mask())
			this->set_selectedCamera(a.selectedCamera());
		if(a.saveImage_mask())
			this->set_saveImage(a.saveImage());
		if(a.saveClassifiedImage_mask())
			this->set_saveClassifiedImage(a.saveClassifiedImage());
		if(a.activatePipeline_mask())
			this->set_activatePipeline(a.activatePipeline());
		if(a.streamingSource_mask())
			this->set_streamingSource(a.streamingSource());
		if(a.conservativeMode_mask())
			this->set_conservativeMode(a.conservativeMode());
		if(a.imageInput_mask())
			this->set_imageInput(a.imageInput());
		if(a.loadCalibration_mask())
			this->set_loadCalibration(a.loadCalibration());
		if(a.pipelineRunOnce_mask())
			this->set_pipelineRunOnce(a.pipelineRunOnce());
		if(a.jpegStreamQuality_mask())
			this->set_jpegStreamQuality(a.jpegStreamQuality());
		if(a.jpegStreamStride_mask())
			this->set_jpegStreamStride(a.jpegStreamStride());
        set_openChallengeStep(a.openChallengeStep());
		return *this;
	}

	/** The resolution that vision should capture images at*/
	CONTROLLED_PROPERTY(ResolutionType, resolution)
	/** Specify whether the pipeline should be runnning or not*/
	CONTROLLED_PROPERTY(bool, pipelineRunning)
	/** The camera that vision should capture images from*/
	CONTROLLED_PROPERTY(VisionCamera, selectedCamera)
	/** Tell vision to save an image in the specified format.
	 *  Images are saved as /tmp/visionXX.{ai2.jpeg"}
	 */
	CONTROLLED_PROPERTY(SaveFileType, saveImage)
	/** Tell vision to save a classifed image as a jpeg.
	 *  Images are saved as /tmp/vision-classifiedXX.jpg
	 */
	CONTROLLED_PROPERTY(bool, saveClassifiedImage)
	/** Specify Which pipeline vision should run*/
	CONTROLLED_PROPERTY(NamedPipeline, activatePipeline)
	/** Specify how vision should stream images to any client that connects*/
	CONTROLLED_PROPERTY(StreamingType, streamingSource)
	/** Vision mode to make vision more conservative? I don't think this does anything */
	CONTROLLED_PROPERTY(bool, conservativeMode)
	/** Tell vision to use the image in /tmp/test.ai2 instead of data from camera*/
	CONTROLLED_PROPERTY(bool, imageInput)
	/** Quality used in JPEG Compression to stream images.
	 * Default is 30. Range is 0-100
	 */
	CONTROLLED_PROPERTY(int, jpegStreamQuality)
	/** Stride used in JPEG Compression to stream images. Default is 4*/
	CONTROLLED_PROPERTY(int, jpegStreamStride)
	/** Tell vision to use this calibration file for image segmentation*/
	CONTROLLED_PROPERTY(CalibrationFile, loadCalibration)
	/** The horizon of the image after which point no image processing 
	 *  should be performed. 
	 */
	CONTROLLED_PROPERTY(float, horizionValue)
	/** Frame rate posted by VisionStatus that vision is currently processing images at*/
	CONTROLLED_PROPERTY(int, frameRate)
	/** Tell vision to run the pipeline once when set to true*/
	CONTROLLED_PROPERTY(bool, pipelineRunOnce)

	CONTROL_BIT(resolution)
	CONTROL_BIT(pipelineRunning)
	CONTROL_BIT(selectedCamera)
	CONTROL_BIT(saveImage)
	CONTROL_BIT(saveClassifiedImage)
	CONTROL_BIT(activatePipeline)
	CONTROL_BIT(streamingSource)
	CONTROL_BIT(conservativeMode)
	CONTROL_BIT(imageInput)
	CONTROL_BIT(jpegStreamQuality)
	CONTROL_BIT(jpegStreamStride)
	CONTROL_BIT(loadCalibration)
        CONTROL_BIT(horizionValue)
        CONTROL_BIT(frameRate)
	CONTROL_BIT(pipelineRunOnce)
		
	/** The state of the open challenge pipeline when it is running*/	
	PROPERTY(uint8_t, openChallengeStep)

};
}

#pragma clang diagnostic pop

#endif /* VisionController_DEFINED */
