/**                                                                     
 *  /file gusimplewhiteboard/guwhiteboarddeserialiser.h
 *                                                                      
 *  Created by Carl Lusty in 2017.                                      
 *  Copyright (c) 2017 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
#ifndef gusimplewhiteboard_guwhiteboarddeserialiser_h
#define gusimplewhiteboard_guwhiteboarddeserialiser_h

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

bool deserialisemsg(WBTypes message_index, void *serialised_in, void *message_out);


#endif //gusimplewhiteboard_guwhiteboarddeserialiser_h

