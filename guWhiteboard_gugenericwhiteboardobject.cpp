/**
 *  /file guWhiteboard_gugenericwhiteboardobject.cpp
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */


/** Auto-generated, don't modify! */

#include "guWhiteboard_gugenericwhiteboardobject.h"
#include "guwhiteboardtypelist_c_generated.h"

#include <stdlib.h>

static void create_guWhiteboard_singleton_whiteboard(void *);

static gu_simple_whiteboard_descriptor *guWhiteboard_whiteboard_descriptor;

static void create_guWhiteboard_singleton_whiteboard(void *)
{
    const char *name = "guWhiteboard";

#ifndef GSW_IOS_DEVICE
    const char *env = getenv(GSW_DEFAULT_ENV);
    if (env && *env) name = env;
#endif

//taken from gusimplewhiteboard.c, should we make this from a hash of the whiteboard name?
#define SEMAPHORE_MAGIC_KEY     4242

    guWhiteboard_whiteboard_descriptor = gsw_new_custom_whiteboard(
        name, 
        wb_types_stringValues,
        WB_NUM_TYPES_DEFINED,
        SEMAPHORE_MAGIC_KEY
    );
}

gu_simple_whiteboard_descriptor *get_guWhiteboard_singleton_whiteboard(void)
{
#ifdef WITHOUT_LIBDISPATCH	// not thread-safe without libdispatch!
	if (!guWhiteboard_whiteboard_descriptor)
	{
		guWhiteboard_whiteboard_descriptor = (gu_simple_whiteboard_descriptor *)~0;
		create_guWhiteboard_singleton_whiteboard(NULLPTR);
	}
#else
	static dispatch_once_t onceToken;
	dispatch_once_f(&onceToken, NULLPTR, create_guWhiteboard_singleton_whiteboard);
#endif
	return guWhiteboard_whiteboard_descriptor;
}
