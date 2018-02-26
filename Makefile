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
COMPILE_WHITEBOARD_SERIALISATION=yes # add serialisation API

ALL_TARGETS=host-local atom-local atom1-local geode-local analyse test xc whiteboard-wrapper

CATKIN_COMPILE_UTIL=YES

CC_SRCS=libgusimplewhiteboardmain.cc 

WB_MSG_C_FILES!= cd typeClassDefs && ls *.c
WBMSG_C_SRCS?=${WB_MSG_C_FILES}

#CFLAGS=-stdlib=libc++
#LDFLAGS=-stdlib=libc++ 

.include "../../mk/c++11.mk"       # can't use C++11 due to naoqi
.include "../../mk/whiteboard.mk"	# required for whiteboard clients

${MODULE_BASE}_HDRS=${NEW_WHITEBOARD_HDRS} ${WHITEBOARD_COMMON_HDRS} ${WB_TYPECLASSDEFS} guwhiteboard_c_types.h guwhiteboardserialisation.h 

WB_VERSION!=grep -Eo 'GU_SIMPLE_WHITEBOARD_VERSION *[[:digit:]]' gusimplewhiteboard.h | sed 's/GU_SIMPLE_WHITEBOARD_VERSION[ ]*//'

PKGCONFIG_NAME=${LIB}
PKGCONFIG_VERSION=${WB_VERSION}
PKGCONFIG_DESCRIPTION=Shared memory IPC mechanism

all: all-real

test:
. if !defined(LOCAL) || ${LOCAL} != _LOCAL
	cd SimpleWhiteboardTest && ${MAKE} ${MAKEFLAGS} test
.else
	$Eecho
.endif

post-clean:
	cd SimpleWhiteboardTest && ${MAKE} ${MAKEFLAGS} clean

whiteboard-wrapper:
	cd ${WB_DIR}/../WhiteboardWrapperGenerator && ${MAKE} host && ./.build/release/WhiteboardWrapperGenerator

.include "../../mk/mipal.mk"		# comes last!
