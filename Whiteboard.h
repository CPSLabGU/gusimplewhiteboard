/*
 *  Whiteboard.h
 *  
 *  Created by René Hexel on 21/12/11.
 *  Copyright (c) 2011 Rene Hexel.
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Rene Hexel.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */
#ifndef gusimplewhiteboard_Whiteboard_h
#define gusimplewhiteboard_Whiteboard_h

#include <string>
#include <vector>
#include <iostream>
#include "gusimplewhiteboard.h"
#include "WhiteboardConstants.h"
#include "WBFunctor.h"
#include "WBMsg.h"

#ifdef WHITEBOARD_OLD_H
#error *** Error: attempt to mix old and simple Whiteboard!
#endif
#ifdef _BOOST_WHITEBOARD_H_
#error *** Error: attempt to mix boost and simple Whiteboard!
#endif

namespace guWhiteboard 
{
        /**
         * compatibility API for accessing the whiteboard
         */
        class Whiteboard
        {
                struct callback_descr
                {
                        int type;                       /// message type
                        int current;                    /// last message index
                        WBFunctorBase *func;            /// functor to call

                        callback_descr(WBFunctorBase *f, int t = -1, int o = -1): type(t), current(o), func(f) {}
                };

                gu_simple_whiteboard_descriptor *_wbd;  /// underlying whiteboard
                std::vector<callback_descr> _sub;  /// subscription indexes
        public:
                /**
		 * API Constructor
		 * This sets up the API and the callback soap server
		 * @param[in] sharedMemoryObjectName    (optional) Allows the user to specify a local shared-memory whiteboard to use.
                 * @param[in] checkVersion              indicate whether to check wb version (default: true)
		 */
                Whiteboard(const char *sharedMemoryObjectName = "guWhiteboard", bool checkVersion = true);

		/**
		 * Destructor.
		 * shuts down the whiteboard
		 */		
                ~Whiteboard();

		/**
		 * Add Message
		 * Adds a message to the whiteboard that the API is connected to
		 * @param[in] type The string type associated with the message object
		 * @param[in] msg The message object to post to the whiteboard
		 */
                void addMessage(const std::string &type, const WBMsg &msg);

                /**
		 * Compatibility Add Message (ignores life span and prints a warning)
		 * Adds a message to the whiteboard that the API is connected to
		 * @param[in] type The string type associated with the message object
		 * @param[in] msg The message object to post to the whiteboard
		 * @param[in] lifespan (ignored) Every message will remain on the whiteboard until its default lifespan has expired.
		 */
                void addMessage(const std::string &type, const WBMsg &msg, int lifespan)
                {
                        std::cerr << "Life span (%d) not supported on addMessage()\n" << std::endl;
                        addMessage(type, msg);
                }

		/**
		 * Return Type Enum
		 * @brief Allows the user to test if an error has occured
		 */
		typedef enum wb_method_result
		{
			METHOD_OK,		/**< No errors detected. */ 
			METHOD_FAIL,		/**< Errors detected. */ 
		} WBResult;

                /**
		 * Get Message
		 * Gets a message from a simple whiteboard
		 * @param[in] type The string type associated with the message object
		 * @param[out] result A pointer (!) to WBResult to indicate whether a message existed or not
		 * @return The message object
		 */
		WBMsg getMessage(std::string type, WBResult *result = NULL);

		/**
		 * Subscribe To Message
		 * Subscribes to a message type on a whiteboard or whiteboards
		 * @param[in] type The string type to subscribe to
		 * @param[in] func The function to call when a message of the type enter is added		 
		 * @param[out] result An enum showing that either an error occured or the operation was completed successfully
		 */
		void subscribeToMessage(const std::string &type, WBFunctorBase *func, WBResult &result);

		/**
		 * Unsubscribe To Message (sic!)
		 * Unsubscribes from a message type on a whiteboard or whiteboards
		 * @param[in] type The string type to unsubscribe from
		 * @param[out] result An enum showing that either an error occured or the operation was completed successfully
		 */		
		void unsubscribeToMessage(std::string type, WBResult &result);

                /**
                 * subscription callback: not really public!
                 */
                void subscriptionCallback(void);
        };
}

#endif
