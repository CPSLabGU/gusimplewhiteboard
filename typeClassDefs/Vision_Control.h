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
		Calibration1,
		Calibration2,
		Calibration3,
		Calibration4
	};

namespace guWhiteboard
{

class VisionControlStatus {
public:
	VisionControlStatus() {
			memset(this, 0, sizeof(*this));
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
