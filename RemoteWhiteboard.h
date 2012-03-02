/*
 *  RemoteWhiteboard.h
 *  
 *  Created by Carl Lusty on 21/12/11.
 *  Copyright (c) 2011 Carl Lusty.
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
#ifndef gusimplewhiteboard_RemoteWhiteboard_h
#define gusimplewhiteboard_RemoteWhiteboard_h

#define NO_WARN_WBMSG_H

#include <string>
#include <vector>
#include <iostream>
#include "guudpbridge/guudpbridgenetworkconfig.h"
#include "gusimplewhiteboard.h"
#include "WhiteboardConstants.h"
#include "WBFunctor.h"
#include "WBMsg.h"


namespace guWhiteboard 
{
        /**
         * compatibility API for accessing the remote whiteboard
         */
        class RemoteWhiteboard
        {
            int playerNum;
        public:
            gu_simple_whiteboard_descriptor *_wbds[NUM_OF_BROADCASTERS];  /// underlying whiteboards
                    /**
             * API Constructor
             * This sets up the API and the callback soap server
             * @param[in] sharedMemoryObjectName    (optional) Allows the user to specify a local shared-memory whiteboard to use.
                     * @param[in] checkVersion              indicate whether to check wb version (default: true)
             */
            RemoteWhiteboard(const char *name = "guWhiteboard");

            /**
             * Destructor.
             * shuts down the whiteboard
             */		
            ~RemoteWhiteboard();

            /**
             * Remote WB enum
             * @brief Allows the user specify a remote wb to talk about
             */
            typedef enum remote_wb_id
            {
                Machine1 = 0,
                Machine2,
                Machine3,
                Machine4            
            } RWBMachine;            

            /**
             * Return Type Enum
             * @brief Allows the user to test if an error has occured
             */
            typedef enum wb_method_result
            {
                METHOD_OK,		/**< No errors detected. */ 
                METHOD_FAIL,		/**< Errors detected. */ 
            } WBResult;            

#ifdef DEBUG            
            /**
             * Inject Message
             * Adds a message to a remote whiteboard that the API is connected to
             * @param[in] type The string type associated with the message object
             * @param[in] msg
             */
//            void injectRemoteMessage(const std::string &type, const WBMsg &msg);            
#endif            
            
            /**
             * Add Message
             * Adds a message to the whiteboard that the API is connected to
             * @param[in] type The string type associated with the message object
             * @param[in] machine Target machine id
             */
//            void addReplicationType(const std::string &type, RWBMachine machine);

            /**
             * Get Message
             * Gets a message from a remote simple whiteboard
             * @param[in] type The string type associated with the message object
             * @param[in] machine The target machine id / player number
             * @param[out] result A pointer (!) to WBResult to indicate whether a message existed or not
             * @return The message object
             */
            WBMsg getMessage(std::string type, RWBMachine machine, WBResult *result = NULL);
        };
}

#endif
