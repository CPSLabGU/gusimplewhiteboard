/*
 *  guudpbridgemanager.h
 *  
 *  Created by Carl Lusty on 15/2/12.
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


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib> //for system()

#include "guudpbridgemanager.h"


class BridgeManager
{
public:
    std::vector<std::string> dynamic_msg_types_to_broadcast;
    
    guWhiteboard::Whiteboard *wb;
    BridgeManager(guWhiteboard::Whiteboard *wbd)
    {
        dynamic_msg_types_to_broadcast = std::vector<std::string>();
        
        wb = wbd;
        guWhiteboard::Whiteboard::WBResult r;
        wb->subscribeToMessage(ADD_BROADCAST_TYPE_MSG_TYPE, WB_BIND(BridgeManager::addBroadcastMsgType), r);
    }
    
    void addBroadcastMsgType(std::string dataName, WBMsg *value)
    {
        if(value->getType() == WBMsg::TypeString)
        {
            dynamic_msg_types_to_broadcast.push_back(value->getStringValue());
        }
    }
};


int main(int argc, char *argv[])
{
    fprintf(stderr, "\n **** GU UDP WHITEBOARD BRIDGE ****\n (c) 2012 Carl Lusty\n\n");    
    
    if(getplayernumber() > 0)
    {
        fprintf(stderr, " **** Running NTP ****\n");        
        if(system("ntpd -s") != 0)
        {
            fprintf(stderr, " **** Failed to Run NTP, Exiting . . . ****\n");                    
            exit(EXIT_FAILURE);
        }
        fprintf(stderr, " **** Done Running NTP ****\n\n\n");        
        fprintf(stderr, " **** Running Bridge ****\n");                    
    }
    else
        fprintf(stderr, " **** Running Bridge (Listener Only) ****\n");            
    
    int op; 
	char *specAddressOfWB = (char *)"";
	
	while((op = getopt(argc, argv, "w:")) != -1)
	{
		switch(op)
		{
			case 'w':
				specAddressOfWB = optarg;
				break;
			case '?':			
				fprintf(stderr, "\n\nUsage: guudpbridge [OPTION] UDP_ID \n");
				fprintf(stderr, "-w, The name of the Whiteboard to connect to.\n");
				return EXIT_FAILURE;
				break;
			default:
				break;
		}
	}	
    
    int udp_id = getplayernumber();

    if(udp_id > (NUM_OF_BROADCASTERS))
    {
        fprintf(stderr, "Bad UDP_ID passed in, exiting...\n\n");
        return EXIT_FAILURE;        
    }
    
    set_udp_id(udp_id-1);
    
    //End cmd line arg parsing
    //----------------------------------------
    
    //Setup broadcast wb
    guWhiteboard::Whiteboard *whiteboard = new guWhiteboard::Whiteboard();
    gu_simple_whiteboard_descriptor *_wbd = whiteboard->_wbd;  /// underlying whiteboard to broadcast from


    //Setup listener wbs    
    gu_simple_whiteboard_descriptor *_wbds[NUM_OF_BROADCASTERS];
    
    for (int i = 0; i < NUM_OF_BROADCASTERS; i++) 
    {
        const char *base_wb_name = REMOTE_WHITEBOARD_BASENAME;
        std::stringstream ss;
        std::stringstream ss2;
        ss << base_wb_name << (i+1); //line the wb names up to the player names
        ss2 << "rm -f /tmp/" << ss.str().c_str();
        
        system(ss2.str().c_str()); //Don't care about return
            
        if((get_udp_id()+1) != (i+1))
        {
            if (!(_wbds[i] = gsw_new_whiteboard(ss.str().c_str())))
            {
                fprintf(stderr, "Unable to create whiteboard '%s'\n", (char *)"guWhiteboard");
                throw "Cannot create whiteboard";
            }
        }
        else
            _wbds[i] = _wbd;
    }

    
    timeval tim;
    gettimeofday(&tim, NULL);
    
    BridgeManager *bm = new BridgeManager(whiteboard);
    BridgeBroadcaster *broadcaster = new BridgeBroadcaster(_wbd, &bm->dynamic_msg_types_to_broadcast, tim);
    BridgeListener *listener = new BridgeListener(_wbds, tim);    //May not end if loop reading

    

    dispatch_main();                // run the dispatcher "forever"
    
	return 0;
}
