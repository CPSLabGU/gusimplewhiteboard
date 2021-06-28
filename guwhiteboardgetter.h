/**
 *  /file guwhiteboardgetter.h
 *
 *  Created by Carl Lusty in 2018.
 *  Copyright (c) 2013-2020 Carl Lusty and Rene Hexel
 *  All rights reserved.
 */

#ifndef WB_GUWHITEBOARDGETTER_H
#define WB_GUWHITEBOARDGETTER_H

/** Auto-generated, don't modify! */

#include "guwhiteboardposter.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * A generic C function that gets a message from the whiteboard.
 * Both the message type and the message content are strings.
 * The returned message string has to be freed!
 */
char *whiteboard_get(const char *message_type, gu_simple_message *msg);

/**
 * A generic C function that gets a message from the given whiteboard.
 * Both the message type and the message content are strings.
 * The returned message string has to be freed!
 */
char *whiteboard_get_from(gu_simple_whiteboard_descriptor *wbd, const char *message_type);

/**
 * Generic C function that gets a message with a given message number
 * from the whiteboard.
 * The returned message string has to be freed!
 */
char *whiteboard_getmsg(int message_index, gu_simple_message *msg);

/**
 * Generic C function that gets a message with a given message number
 * from the given whiteboard.
 * The returned message string has to be freed!
 */
char *whiteboard_getmsg_from(gu_simple_whiteboard_descriptor *wbd, int message_index);

#ifdef __cplusplus
} // extern "C"

namespace guWhiteboard {

        /**
         * A generic C++ function that gets a string from the whiteboard.
         * Both the message type and the message content are strings.
         * @param message_type the string version of the type
         * @param msg the data container, if NULLPTR then the message is gotten from the whiteboard
         * @param wbd the whiteboard to get the message from (NULLPTR for the default whiteboard) - this parameter has no effect if `msg` is non-NULLPTR
         * @return the pretty printed data string
         */
        std::string getmsg(std::string message_type, gu_simple_message *msg = NULLPTR, gu_simple_whiteboard_descriptor *wbd = NULLPTR);

        /**
         * Generic C++ function that gets a message with a given message number
         * to the whiteboard.
         * @param message_index the offset or enum value of the type to get
         * @param msg the data container, if NULLPTR then the message is gotten from the whiteboard
         * @param wbd the whiteboard to get the message from (NULLPTR for the default whiteboard) - this parameter has no effect if `msg` is non-NULLPTR
         * @return the pretty printed data string
         */
        std::string getmsg(guWhiteboard::wb_types message_index, gu_simple_message *msg = NULLPTR, gu_simple_whiteboard_descriptor *wbd = NULLPTR);

} // guWhiteboard

#endif // __cplusplus

#endif //WB_GUWHITEBOARDGETTER_H
