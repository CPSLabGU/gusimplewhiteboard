#
#	$Id$
#
# GU Objective C whiteboard Makefile
#
LIB=guobjcsimplewhiteboard

ALL_TARGETS=host-local # robot-local test

CI_DISPLAYNAME?=wb-objc			# short jenkins display name

CATKIN_COMPILE_WHITEBOARD=yes		# need wb in catkin

MM_SRCS=ObjCWhiteboard.mm

USE_WB_LIB=yes

.include "../../../mk/whiteboard.mk"	# required for whiteboard clients

.ifdef GNUSTEP_MAKEFILES
SPECIFIC_LIBS+=-lgnustep-base
.else
SPECIFIC_LIBS+=-framework Foundation
.endif

INST_HDRS=${WHITEBOARD_OBJC_HDRS}

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
	cd ../guobjcwhiteboardTests && ${MAKE} ${MAKEFLAGS} test
.else
	$Eecho
.endif

post-clean:
	cd ../guobjcwhiteboardTests && ${MAKE} ${MAKEFLAGS} clean

.include "../../../mk/mipal.mk"		# comes last!
