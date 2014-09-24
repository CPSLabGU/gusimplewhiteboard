#
#	$Id$
#
# GU monitor whiteboard module Makefile
#
BIN=guudpwhiteboard

ALL_TARGETS=host robot

CPP_SRCS=main.cpp udp_util.cpp udp_sender.cpp udp_receiver.cpp tcp_receiver.cpp
#SPECIFIC_CPPFLAGS=-fblocks

.include "../../../mk/dispatch.mk"      # blocks runtime and libdispatch
.include "../../../mk/c++11.mk"        # needed for libc++ and C++11
.include "../../../mk/whiteboard.mk"
.include "../../../mk/mipal.mk"		# comes last!


