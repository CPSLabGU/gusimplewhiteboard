/*
 *  gugenericwhiteboardobject.h
 *
 *  Created by Carl Lusty in 2013.
 *  Copyright (c) 2013 Carl Lusty
 *  All rights reserved.
 */

#include "gugenericwhiteboardobject.h"

#error *** Error: Do not include this file

extern "C" {

        /** Whiteboard message (SHOULDN'T BE USED): Commands the slow walk that is built into the SDK
	 */
	extern const char *wb_reserved_SubscribeToAllTypes;
        
             
        /** Whiteboard message (SHOULDN'T BE USED): Commands the slow walk that is built into the SDK
	 */
	extern const char *kNaoIsReadyToRun;
             
        
        extern const char *kNaogtrfedRun;
        extern const char *kSuperTest;
}

#endif // _GUWHITEBOARD_TYPE_LIST_H