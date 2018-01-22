#
#	$Id$
#
# GU localisation module Makefile
#
LIB=gusimplewhiteboard
LOCAL=_LOCAL

CI_DISPLAYNAME?=wb			# short jenkins display name

DOC_RECURSIVE=YES			# build doxygen recursively

CATKIN_COMPILE_WHITEBOARD=yes		# need wb in catkin
COMPILE_WHITEBOARD_STRING_SOURCES=yes	# add inflection methods to library

ALL_TARGETS=host-local atom-local atom1-local geode-local analyse test xc

CATKIN_COMPILE_UTIL=YES

CC_SRCS=libgusimplewhiteboardmain.cc 

#CFLAGS=-stdlib=libc++
#LDFLAGS=-stdlib=libc++ 

.include "../../mk/c++11.mk"       # can't use C++11 due to naoqi
.include "../../mk/whiteboard.mk"	# required for whiteboard clients

${MODULE_BASE}_HDRS=${NEW_WHITEBOARD_HDRS} ${WHITEBOARD_COMMON_HDRS} ${WB_TYPECLASSDEFS} guwhiteboard_c_types.h guwhiteboardserialisation.h 

WB_VERSION!=grep -Eo 'GU_SIMPLE_WHITEBOARD_VERSION *[[:digit:]]' gusimplewhiteboard.h | sed 's/GU_SIMPLE_WHITEBOARD_VERSION[ ]*//'

all: all-real

pkg-config:
	-$Emkdir -p -m 0755 ${WB_INST_DIR:Q}/lib/pkgconfig
	$Erm -f ${WB_INST_DIR:Q}/lib/pkgconfig/libgusimplewhiteboard.pc
	$Erm -f libgusimplewhiteboard.pc
	$Esed -e 's|@WB_INST_DIR@|${WB_INST_DIR}|' -e 's/@WB_VERSION@/${WB_VERSION}/' libgusimplewhiteboard.pc.conf > libgusimplewhiteboard.pc
	$Ecp -pR libgusimplewhiteboard.pc ${WB_INST_DIR:Q}/lib/pkgconfig/libgusimplewhiteboard.pc
	$Erm -f libgusimplewhiteboard.pc

test:
. if !defined(LOCAL) || ${LOCAL} != _LOCAL
	cd SimpleWhiteboardTest && ${MAKE} ${MAKEFLAGS} test
.else
	$Eecho
.endif

post-clean:
	cd SimpleWhiteboardTest && ${MAKE} ${MAKEFLAGS} clean

.include "../../mk/mipal.mk"		# comes last!
