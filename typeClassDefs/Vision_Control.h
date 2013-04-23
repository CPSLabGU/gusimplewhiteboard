/*
 * Vision_Control.h
 *
 *  Created on: 10 Apr 2013
 *      Author: Eugene Gilmore
 */

#ifndef VisionControlStatus_DEFINED
#define VisionControlStatus_DEFINED

#include <gu_util.h>
#include <stdio.h>
#include <bitset>


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
		NUMBER_VISION_MESSAGES
	};

	enum ResolutionType {
		QQVGA,  // 160 x 120
		QVGA,   // 320 x 240
		VGA,    // 640 x 480
		HD_4VGA    // 1280x960
	};

	enum VisionCamera {
		Top,
		Bottom
	};

	enum NamedPipeline {
		soccer
	};

	enum StreamingType {
		Normal,
		Classified,
		Recognized //NYI
	};

	enum CalibrationFile {
		Calibration0,
		Calibration1,
		Calibration2,
		Calibration3
	};

namespace guWhiteboard
{

class VisionControlStatus {
public:
	VisionControlStatus() {
			memset(this, 0, sizeof(*this));
		}
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
			return *this;
		}

		CONTROLLED_PROPERTY(ResolutionType, resolution)
		CONTROLLED_PROPERTY(bool, pipelineRunning)
		CONTROLLED_PROPERTY(VisionCamera, selectedCamera)
		CONTROLLED_PROPERTY(bool, saveImage)
		CONTROLLED_PROPERTY(bool, saveClassifiedImage)
		CONTROLLED_PROPERTY(NamedPipeline, activatePipeline)
		CONTROLLED_PROPERTY(StreamingType, streamingSource)
		CONTROLLED_PROPERTY(bool, conservativeMode)
		CONTROLLED_PROPERTY(bool, imageInput)
		CONTROLLED_PROPERTY(CalibrationFile, loadCalibration)

		CONTROL_BIT(resolution)
		CONTROL_BIT(pipelineRunning)
		CONTROL_BIT(selectedCamera)
		CONTROL_BIT(saveImage)
		CONTROL_BIT(saveClassifiedImage)
		CONTROL_BIT(activatePipeline)
		CONTROL_BIT(streamingSource)
		CONTROL_BIT(conservativeMode)
		CONTROL_BIT(imageInput)
		CONTROL_BIT(loadCalibration)

	};
}


#endif /* VisionController_DEFINED */
