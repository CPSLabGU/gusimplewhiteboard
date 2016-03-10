/**
 *  /file IoT_Control.h
 *
 *  Created by Carl Lusty in 2016.
 *  Copyright (c) 2016 Carl Lusty
 *  All rights reserved.
 */
 
#ifndef IoT_Control_DEFINED
#define IoT_Control_DEFINED

#include "wb_iot_control.h" 

namespace guWhiteboard                                                  
{
    /**
 	* @brief Class wrapper for wb_iot_control
 	*/
    class IoT_Control: public wb_iot_control
    {
        public:

        /** default constructor 
		 */
		IoT_Control() { }

    };
}

#endif //IoT_Control_DEFINED
