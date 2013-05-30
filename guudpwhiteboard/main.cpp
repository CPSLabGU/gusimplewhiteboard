/*
 *  main.c
 *
 *  Created by Carl Lusty on 11/5/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */


#include <stdio.h> //fprintf
#include <unistd.h> //optargs
#include <stdlib.h> //atoi
#include <sys/time.h> //gettimeofday
#include <vector> //for vectors, clearly

//Might not need all of these
#include <errno.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <cmath>


//module files
#include "udp_config.h"
#include "udp_util.h"

//#include "guudpUtil.h"
//#include "guudpBroadcaster.h"
//#include "guudpListener.h"
//#include "guudpWhiteboardLayer.h"



void setup_udp_whiteboard_with_id(int id);


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

int main(int argc, char *argv[])
{
        fprintf(stderr, " **** UDP WHITEBOARD ****\t (c) 2013 Carl Lusty\n\n");
        
        int robot_id = -1;
        
        int op;
	char *specAddressOfWB = (char *)"";
	
	while((op = getopt(argc, argv, "wr:")) != -1)
	{
		switch(op)
		{
			case 'w':
				specAddressOfWB = optarg;
				break;
			case 'r':
				robot_id = atoi(optarg);
				break;
			case '?':
				fprintf(stderr, "\n\nUsage: guudpbridge [OPTION] \n");
				fprintf(stderr, "-w, The name of the local Whiteboard to connect to. ** NYI **\n");
				fprintf(stderr, "-r, Robot id to utilise impersonate.\n");
				return EXIT_FAILURE;
			default:
				break;
		}
	}
        
        
        
        if(robot_id != -1)
                fprintf(stderr, " **** Running UDP Whiteboard (FAKING ROBOT %d) ****\n", robot_id);
        
        mipal_err_file(WARNINGS_FILE); //setup warning file
        
        setup_udp_whiteboard_with_id(robot_id); //Should never return
        return EXIT_SUCCESS;
}

#pragma GCC diagnostic pop


void setup_udp_whiteboard_with_id(int id)
{
        if(id == -1)
                set_udp_id(getplayernumber());
        else
                set_udp_id(id);
        
        std::string schedule_file = getenv("HOME");
        schedule_file += SCHEDULE_FILE;
        if(!file_exists((char *)schedule_file.c_str()))
        {
                fprintf(stderr, "No schedule file found. It should be at: '%s'\nExiting.\n", (char *)schedule_file.c_str());
                mipal_warn("No schedule file found. It should be at: '%s'\nExiting.\n", (char *)schedule_file.c_str());
                exit(1);
        }

        std::string schedule_file_content = string_from_file((char *)schedule_file.c_str());
        std::string machine_token("messages_per_packet:");
        std::string delay_token("packet_interval:");

        //Get the num of machines and the delay (usec)
        int types_per_packet = atoi((char *)schedule_file_content.substr(schedule_file_content.find(machine_token)+machine_token.length(), schedule_file_content.find("\n", schedule_file_content.find(machine_token))).c_str());
        int schedule_delay = atoi((char *)schedule_file_content.substr(schedule_file_content.find(delay_token)+delay_token.length(), schedule_file_content.find("\n", schedule_file_content.find(delay_token))).c_str());
        
        std::remove(schedule_file_content.begin(), schedule_file_content.end(), ' '); //remove whitespace
        

        //Get the lines
        std::vector<std::string> lines = basic_parse(schedule_file_content, (char *)"\n");
        lines.erase(lines.end()); //I seem to get a newline at the end of a line regardless of there not being a new line under it.

        std::vector<std::vector<std::string> > types_to_send;
        int packet_destination_ids[MAX_NODES];
        //start at two in order to ignore the header info
        for(int i = 2; i < (int)lines.size(); i++)
        {
                int start_of_type_definition = ((int)lines.at(i).find(':'))+1;
                packet_destination_ids[i-2] = atoi((char *)lines.at(i).substr(0, start_of_type_definition).c_str());

                std::vector<std::string> types = basic_parse(lines.at(i).substr(start_of_type_definition, lines.at(i).length()), (char *)",");
                types_to_send.push_back(types);
        }


        // Construct packet data structures
        int number_of_packets = (int)types_to_send.size();
        gsw_udp_packet_info *packets = (gsw_udp_packet_info *) malloc(sizeof(gsw_udp_packet_info) * number_of_packets);

        for (int i = 0; i < number_of_packets; i++)
        {
                packets[i].sender = (u_int8_t)packet_destination_ids[i];
                packets[i].num_of_types = (u_int8_t)types_to_send.at(i).size();
                packets[i].offset = (u_int16_t *) malloc(sizeof(u_int16_t) * packets[i].num_of_types);

                for (int g = 0; g < (int)types_to_send.at(i).size(); g++)
                {
//                        fprintf(stderr, "\t%s", (char *)types_to_send.at(i).at(g).c_str());
                        packets[i].offset[g] = (u_int16_t)get_wb_offset_from_string(types_to_send.at(i).at(g));
                }
//                fprintf(stderr, "\n");
        }

//        float iterations_per_sec = USEC_PER_SEC/(float)schedule_delay;
//        int size_of_all_packets = 
//        float bytes_per_sec = iterations_per_sec * GU_SIMPLE_WHITEBOARD_BUFSIZE;
//        int kilobytes_per_sec = ceil(bytes_per_sec / 1024);

        mipal_warn("Messages per packet: %d\tBroadcast interval:%d\tKilobytes per sec: %d\n", types_per_packet, schedule_delay, -1);
        pretty_print_packet_types(packets, number_of_packets);



        
       // fprintf(stdout, "Bandwidth usage: %dkbps\n", );
        
        //gu_simple_whiteboard_descriptor *_wbd = get_local_singleton_whiteboard();
        
        

        
        /*
        
        //Setup listener wbs
        gu_simple_whiteboard_descriptor *_wbds[NUM_OF_BROADCASTERS];
        guWhiteboard::Whiteboard *_whiteboards[NUM_OF_BROADCASTERS];
        
        for (int i = 0; i < NUM_OF_BROADCASTERS; i++)
        {
                const char *base_wb_name = REMOTE_WHITEBOARD_BASENAME;
                std::stringstream ss;
                std::stringstream ss2;
                ss << base_wb_name << (i+1); //line the wb names up to the player names
                
                _whiteboards[i] = new guWhiteboard::Whiteboard(ss.str().c_str());
                if(_whiteboards[i])
                        _wbds[i] = _whiteboards[i]->_wbd;
        }
        
        
        timeval tim;
        gettimeofday(&tim, NULL);
        
        
#ifdef DEBUG
        //    fprintf(stderr, "\nMessage on the wb: %d\n\nMessages to a packet: %d\nPackets to send all messages: %d\nHashes to a packet: %d\nPackets to send all hashes: %d\nInjections to a packet: %d\n\nCYCLES_PER_SECOND: %d\nPACKETS_PER_TS_INTERVAL %d\n", _wbd->wb->num_types, MESSAGES_PER_PACKET, TOTAL_MESSAGE_PACKETS, HASHES_PER_PACKET, TOTAL_HASH_PACKETS, INJECTIONS_PER_PACKET, CYCLES_PER_SEC, PACKETS_PER_TS_INTERVAL);
        //
        //    fprintf(stderr, "\nMessages sizes:\n\tgsw_single_message:\t%d\n\tgsw_hash_message:\t%d\n\n", (int)sizeof(gsw_single_message), (int)sizeof(gsw_hash_message));
#endif
        
        
        WhiteboardLayer *wl = new WhiteboardLayer(whiteboard, _whiteboards);
        BridgeBroadcaster *broadcaster = new BridgeBroadcaster(_wbd, &wl->dynamic_msg_types_to_broadcast, &wl->dynamic_messages_to_inject, &wl->injection_mutex, tim);
        BridgeListener *listener = new BridgeListener(_wbds, whiteboard, wl->recieved_generations, tim, &wl->dynamic_msg_types_to_broadcast, &wl->dynamic_msg_types_to_listen_for, &wl->injection_mutex);    //May not end if loop reading
        
        delete listener;
        delete broadcaster;
        delete wl;
        for (int i = 0; i < NUM_OF_BROADCASTERS; i++) 
        {
                delete _wbds[i];
        }
        delete whiteboard;
        
	return 0;
         */
}
