/*
 *  main.c
 *
 *  Created by Carl Lusty on 2/1/13.
 *  Copyright (c) 2011 Carl Lusty.
 *  All rights reserved.
 */


#include "guudpManager.h"
#include <stdio.h> //printf
#include <unistd.h> //optargs
#include <stdlib.h> //atoi

int main(int argc, char *argv[])
{
        fprintf(stderr, " **** GU UDP WHITEBOARD BRIDGE 2 ****\t (c) 2012 Carl Lusty\n\n");
        
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
				fprintf(stderr, "-w, The name of the Whiteboard to connect to.\n");
				fprintf(stderr, "-r, Robot id to utilise impersonate.\n");
				return EXIT_FAILURE;
				break;
			default:
				break;
		}
	}
        
        if(robot_id != -1)
                fprintf(stderr, " **** Running Bridge (FAKING ROBOT %d) ****\n", robot_id);
        
        
        return setup_udp_with_id(robot_id); //Should never return
}

