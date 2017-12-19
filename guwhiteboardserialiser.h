/**                                                                     
 *  /file gusimplewhiteboard/guwhiteboardserialiser.h
 *                                                                      
 *  Created by Carl Lusty in 2017.                                      
 *  Copyright (c) 2017 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
#ifndef gusimplewhiteboard_guwhiteboardserialiser_h
#define gusimplewhiteboard_guwhiteboardserialiser_h

#include "guwhiteboard_c_types.h"

bool serialisemsg(WBTypes message_index, void *message_in, void *serialised_out);


#endif //gusimplewhiteboard_guwhiteboardserialiser_h
