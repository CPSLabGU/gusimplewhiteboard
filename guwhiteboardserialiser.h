/**                                                                     
 *  /file gusimplewhiteboard/guwhiteboardserialiser.h
 *                                                                      
 *  Created by Carl Lusty in 2017.                                      
 *  Copyright (c) 2017 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
#ifndef gusimplewhiteboard_guwhiteboardserialiser_h
#define gusimplewhiteboard_guwhiteboardserialiser_h

#define WHITEBOARD_POSTER_STRING_CONVERSION

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

bool serialisemsg(WBTypes message_index, void *message_in, void *serialised_out);


#endif //gusimplewhiteboard_guwhiteboardserialiser_h
