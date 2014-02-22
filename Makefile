#
#	$Id$
#
# GU localisation module Makefile
#
LIB=gusimplewhiteboard

USE_READLINE=yes			# command line history and completion

ALL_TARGETS=host-local

CC_SRCS=libgusimplewhiteboardmain.cc

CFLAGS=-stdlib=libc++
LDFLAGS=-stdlib=libc++ 

.include "../../mk/whiteboard.mk"	# required for whiteboard clients
#.include "../../mk/util.mk"		# required for GU utility functions
.include "../../mk/mipal.mk"		# comes last!

CATKIN_WS=${SRCDIR}/catkin_ws
CATKIN_DIR=${CATKIN_WS}/src/gusimplewhiteboard

clean: catkin-clean

catkin:
	$Emkdir -p ${CATKIN_DIR}/src
	$Emkdir -p ${CATKIN_DIR}/include
.for src in ${NEW_WHITEBOARD_SRCS} ${WHITEBOARD_PRIVATE_CS} ${NEW_WHITEBOARD_CS}
	$Ecp -p ${WB_DIR}/${src} ${CATKIN_DIR}/src
.endfor
.for hdr in ${NEW_WHITEBOARD_HDRS} ${WHITEBOARD_PRIVATE_HDRS}
	$Ecp -p ${WB_DIR}/${hdr} ${CATKIN_DIR}/include
.endfor
	$Ecp -p ${COMMON_DIR}/gu_util.h ${CATKIN_DIR}/include
	$Eecho done.

catkin-clean:
	rm -rf ${CATKIN_DIR}/src
	rm -rf ${CATKIN_DIR}/include
	rm -rf ${CATKIN_WS}/build
	rm -rf ${CATKIN_WS}/devel
	rm -rf ${CATKIN_WS}/src/CMakeLists.txt
