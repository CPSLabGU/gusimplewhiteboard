/*
 *  FSM_Control.h
 *  gusimplewhiteboard / clfsm
 *
 *  Created by Rene Hexel on 25/03/13.
 *  Copyright (c) 2013 Rene Hexel. All rights reserved.
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
#ifndef gusimplewhiteboard_FSM_Control_h
#define gusimplewhiteboard_FSM_Control_h

#include <bitset>
#include <gu_util.h>
#include "gusimplewhiteboard.h"

#define CONTROLSTATUS_SIZE          ((sizeof(gsw_simple_message))*8)
#define CONTROLSTATUS_BITS_RESERVED 2   // must be big enough for enum
#define CONTROLSTATUS_NUM_FSMS      (CONTROLSTATUS_SIZE - CONTROLSTATUS_BITS_RESERVED)
#define CONTROLSTATUS_CMD_LO        CONTROLSTATUS_NUM_FSMS
#define CONTROLSTATUS_CMD_HI        (CONTROLSTATUS_CMD_LO + 1)

namespace guWhiteboard
{
//    namespace fsm
//    {
        /**
         * command for ControlStatus
         */
        enum FSMControlType
        {
            FSMStatus,          ///< check status only
            FSMSuspend,         ///< suspend the corresponding state machines
            FSMResume,          ///< resume the corresponding state machines
            FSMRestart          ///< restart the corresponding state machine
        };

        /**
         * Class for controlling and getting the status of FSMs.
         * This is implemented as a bit vector with an enum for control and
         * one bit per FSM.
         */
        class FSMControlStatus
        {
            PROPERTY(std::bitset<CONTROLSTATUS_SIZE>, fsms) ///< bit set for fsms affected by command

        public:
            /** command getter */
            FSMControlType command() { return static_cast<FSMControlType>(_fsms[CONTROLSTATUS_CMD_LO] + (_fsms[CONTROLSTATUS_CMD_HI] << 1)); }

            /** command setter */
            void set_command(FSMControlType command) { _fsms[CONTROLSTATUS_CMD_LO] = ((command & (1 << 0)) != 0); _fsms[CONTROLSTATUS_CMD_HI] = ((command & (1 << 1)) != 0); }
        };
//    }
}


#endif
