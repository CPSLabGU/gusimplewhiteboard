#
#	$Id$
#
# GU localisation module Makefile
#
LIB=gusimplewhiteboard

CATKIN_COMPILE_WHITEBOARD=yes		# need wb in catkin
USE_READLINE=yes			# command line history and completion

ALL_TARGETS=host-local robot-local test

CC_SRCS=libgusimplewhiteboardmain.cc

#CFLAGS=-stdlib=libc++
#LDFLAGS=-stdlib=libc++ 

.include "../../mk/libcxx.mk"
.include "../../mk/whiteboard.mk"	# required for whiteboard clients

INST_HDRS=${NEW_WHITEBOARD_HDRS} ${WHITEBOARD_COMMON_HDRS} ${WB_TYPECLASSDEFS}

all: all-real

.if ${LOCAL} != _LOCAL
host: host-local
	echo "Use 'make host-local' instead of 'make host'"

install: host-local
	mkdir -p -m 0755 ${WB_INST_DIR:Q}/include/gusimplewhiteboard
	mkdir -p -m 0755 ${WB_INST_DIR:Q}/lib
	cd ${BUILDDIR}-local && \
	install -m 0755 *${SOEXT}* ${WB_INST_DIR:Q}/lib
.for hdr in ${INST_HDRS}
	cd ${SRCDIR} && \
	if [ -d ${hdr:Q} ]; then \
	  cp -pR ${hdr:Q} ${WB_INST_DIR:Q}/include/gusimplewhiteboard ;\
	else \
	  install -m 0644 ${hdr} ${WB_INST_DIR:Q}/include/gusimplewhiteboard ;\
	fi
.endfor
.endif

test:
. if !defined(LOCAL) || ${LOCAL} != _LOCAL
	cd SimpleWhiteboardTest && ${MAKE} ${MAKEFLAGS} test
.else
	$Eecho
.endif

post-clean:
	cd SimpleWhiteboardTest && ${MAKE} ${MAKEFLAGS} clean

.include "../../mk/mipal.mk"		# comes last!
