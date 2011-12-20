/*
 *  Whiteboard.cc
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
#include "Whiteboard.h"

using namespace guWhiteboard;
using namespace std;

Whiteboard::Whiteboard(const char *name, bool checkVersion)
{
        if (!(_wbd = gsw_new_whiteboard(name)))
        {
                cerr << "Unable to create whiteboard '" << name << "'" << endl;
                throw "Cannot create whiteboard";
        }
}


Whiteboard::~Whiteboard()
{
        if (_wbd) gsw_free_whiteboard(_wbd);
}


void Whiteboard::addMessage(const std::string &type, const WBMsg &msg)
{
        int t = gsw_offset_for_message_type(_wbd, type.c_str());

        gsw_procure(_wbd->sem, GSW_SEM_PUTMSG);

        gu_simple_message *m = gsw_next_message(_wbd->wb, t);
        m->wbmsg.type = msg.getType();

        switch (m->wbmsg.type)
        {
                case WBMsg::TypeEmpty:
                        m->wbmsg.len = 0;
                        break;

                case WBMsg::TypeBool:
                        m->wbmsg.len = sizeof(int);
                        m->sint = msg.getBoolValue();
                        break;

                case WBMsg::TypeInt:
                        m->wbmsg.len = sizeof(int);
                        m->sint = msg.getIntValue();
                        break;

                case WBMsg::TypeFloat:
                        m->wbmsg.len = sizeof(float);
                        m->sfloat = msg.getFloatValue();
                        break;

                case WBMsg::TypeString:
                        strlcpy(m->wbmsg.data, msg.getStringValue().c_str(), sizeof(m->wbmsg.data));
                        m->wbmsg.len = strlen(m->wbmsg.data) + 1;
                        break;

                case WBMsg::TypeBinary:
                        int len = msg.getSizeInBytes();
                        if (len > sizeof(m->wbmsg.data)) len = sizeof(m->wbmsg.data);
                        m->wbmsg.len = len;
                        if (len) memcpy(m->wbmsg.data, msg.getBinaryValue(), len);
                        break;
        }
        gsw_vacate(_wbd->sem, GSW_SEM_PUTMSG);
}


WBMsg Whiteboard::getMessage(std::string type, WBResult *result)
{
        int t = gsw_offset_for_message_type(_wbd, type.c_str());
        gu_simple_message *m = gsw_current_message(_wbd->wb, t);

        if (result)
        {
                if (m->wbmsg.type || m->wbmsg.len)
                        *result = METHOD_OK;
                else
                        *result = METHOD_FAIL;
        }

        switch (m->wbmsg.type)
        {
                case WBMsg::TypeBool:
                        return WBMsg((bool)m->sint);

                case WBMsg::TypeInt:
                        return WBMsg(m->sint);

                case WBMsg::TypeFloat:
                        return WBMsg(m->sfloat);

                case WBMsg::TypeString:
                        return WBMsg(m->wbmsg.data);
                        
                case WBMsg::TypeBinary:
                        return WBMsg(m->wbmsg.data, m->wbmsg.len);

                default:
                        return WBMsg();
        }
        /* NOTREACHED */
}
