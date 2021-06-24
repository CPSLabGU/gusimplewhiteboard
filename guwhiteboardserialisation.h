/**
 *  /file guwhiteboardserialisation.h
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

/** Auto-generated, don't modify! */

#ifndef WB_GUWHITEBOARDSERIALISATION_H
#define WB_GUWHITEBOARDSERIALISATION_H

#ifndef __cplusplus
#include <stdbool.h>
#else
#if __cplusplus < 201103L
#include <stdbool.h>
#else
#include <cstdbool>
#endif
#endif // __cplusplus

#include "guwhiteboardtypelist_c_generated.h"

int32_t serialisemsg(wb_types message_index, const void *message_in, void *serialised_out);

int32_t deserialisemsg(wb_types message_index, const void *serialised_in, void *message_out);

#endif //WB_GUWHITEBOARDSERIALISATION_H
