/*
 *  RemoteWhiteboard.cc
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
#include <cstring>
#include <cstdio>
#include <gu_util.h>
#include <sstream>
#include "RemoteWhiteboard.h"

using namespace guWhiteboard;
using namespace std;


RemoteWhiteboard::RemoteWhiteboard(const char *name)
{
    wb = new Whiteboard();
    playerNum = getplayernumber();
    
    for (int i = 0; i < NUM_OF_BROADCASTERS; i++) 
    {
        const char *base_wb_name = REMOTE_WHITEBOARD_BASENAME;
        std::stringstream ss;
        ss << base_wb_name << (i+1); //line the wb names up to the player names
        
        if(playerNum != i+1)
        {
            if (!(_wbds[i] = gsw_new_whiteboard(ss.str().c_str())))
            {
                fprintf(stderr, "Unable to create whiteboard '%s'\n", (char *)"guWhiteboard");
                throw "Cannot create whiteboard";
            }
        }
        else
        {
            if (!(_wbds[i] = gsw_new_whiteboard(name)))
            {
                cerr << "Unable to create whiteboard '" << name << "'" << endl;
                throw "Cannot create whiteboard";
            }            
        }
    }    
}


RemoteWhiteboard::~RemoteWhiteboard()
{
    for (int i = 0; i < NUM_OF_BROADCASTERS; i++) 
        if (_wbds[i]) gsw_free_whiteboard(_wbds[i]);
}

static WBMsg getWBMsg(gu_simple_message *m)
{
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
                        
                case WBMsg::TypeArray:
                {
                        vector<int> *v = new vector<int>();
                        for (int i = 0; i < m->wbmsg.len; i++)
                                v->push_back(m->ivec[i]);
                        return WBMsg(*v, true);
                }
                default:
                        return WBMsg();
        }
        /* NOTREACHED */
}

void RemoteWhiteboard::injectRemoteMessage(const std::string &type, const WBMsg &msg, RWBMachine machine)
{    
    //Add type
    const char *base_injection_type = INJECTION_TYPE;
    std::stringstream ss;
    ss << base_injection_type << (machine+1);
    
    wb->addMessage((char *)ss.str().c_str(), WBMsg(type));
    
    //Add content
    const char *base_injection_content = INJECTION_CONTENT;
    std::stringstream ss2;
    ss2 << base_injection_content << (machine+1);
    
    wb->addMessage((char *)ss2.str().c_str(), msg);
}

void RemoteWhiteboard::addReplicationType(const std::string &type, RWBMachine machine)
{
    injectRemoteMessage(string(ADD_BROADCAST_TYPE_MSG_TYPE), WBMsg(type), machine);
}

WBMsg RemoteWhiteboard::getMessage(string type, RWBMachine machine, WBResult *result)
{
        if(machine >= NUM_OF_BROADCASTERS)
        {
            *result = METHOD_FAIL;
            return WBMsg();
        }
        
        int t = gsw_offset_for_message_type(_wbds[machine], type.c_str());
        gu_simple_message *m = gsw_current_message(_wbds[machine]->wb, t);

        if (result)
        {
                if (m->wbmsg.type || m->wbmsg.len)
                        *result = METHOD_OK;
                else
                        *result = METHOD_FAIL;
        }
        return getWBMsg(m);

    return WBMsg();
}

std::vector<std::string> RemoteWhiteboard::getKnownTypesForMachine(RWBMachine machine)
{
    gsw_procure(_wbds[machine]->sem, GSW_SEM_MSGTYPE);
    std::vector<std::string> known_types;
    int i = 0;
    while (i < GSW_TOTAL_MESSAGE_TYPES)
    {
        if(strlen(_wbds[machine]->wb->typenames[i].hash.string) > 0)
        {
            known_types.push_back(std::string(_wbds[machine]->wb->typenames[i].hash.string));
            if(known_types.size() > _wbds[machine]->wb->num_types)
                break;
        }
        i++;
    }
    gsw_vacate(_wbds[machine]->sem, GSW_SEM_MSGTYPE);

    return known_types;
}
