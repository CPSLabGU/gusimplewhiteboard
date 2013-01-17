#
#	$Id$
#
# GU localisation module Makefile
#
LIB=gusimplewhiteboard

USE_READLINE=yes			# command line history and completion

ALL_TARGETS=host-local

CC_SRCS=libgusimplewhiteboardmain.cc

.include "../../mk/whiteboard.mk"	# required for whiteboard clients
#.include "../../mk/util.mk"		# required for GU utility functions
.include "../../mk/mipal.mk"		# comes last!
