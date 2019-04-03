/**                                                                     
 *  /file gusimplewhiteboard/guwhiteboardserialiser.h
 *                                                                      
 *  Created by Carl Lusty in 2017.                                      
 *  Copyright (c) 2017 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
#ifndef gusimplewhiteboard_guwhiteboardserialiser_h
#define gusimplewhiteboard_guwhiteboardserialiser_h

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

int32_t serialisemsg(WBTypes message_index, const void *message_in, void *serialised_out);

int32_t deserialisemsg(WBTypes message_index, const void *serialised_in, void *message_out);

#endif //gusimplewhiteboard_guwhiteboardserialiser_h
