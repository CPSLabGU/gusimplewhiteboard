/**                                                                     
 *  /file gusimplewhiteboard/guwhiteboarddeserialiser.h
 *                                                                      
 *  Created by Carl Lusty in 2017.                                      
 *  Copyright (c) 2017 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
#ifndef gusimplewhiteboard_guwhiteboarddeserialiser_h
#define gusimplewhiteboard_guwhiteboarddeserialiser_h

#include "guwhiteboard_c_types.h"

bool deserialisemsg(WBTypes message_index, void *serialised_in, void *message_out);


#endif //gusimplewhiteboard_guwhiteboarddeserialiser_h

