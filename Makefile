#
#	$Id$
#
# GU localisation module Makefile
#
LIB=gusimplewhiteboard

CATKIN_COMPILE_WHITEBOARD=yes		# need wb in catkin
USE_READLINE=yes			# command line history and completion

ALL_TARGETS=host-local

CC_SRCS=libgusimplewhiteboardmain.cc

CFLAGS=-stdlib=libc++
LDFLAGS=-stdlib=libc++ 


.include "../../mk/whiteboard.mk"	# required for whiteboard clients
.include "../../mk/mipal.mk"		# comes last!
