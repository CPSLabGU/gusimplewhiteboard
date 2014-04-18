#
#	$Id$
#
# GU whiteboard poster module Makefile
#

ALL_TARGETS=host robot

USE_READLINE=yes
CATKIN_COMPILE_UTIL=yes

CC_SRCS=get_test.cc main.cc perftest.cc post_test.cc 
HDRS=get_test.h perftest.h post_test.h

CATKIN_SRCS+=ros_publish_test.cc ros_subscribe_test.cc
CATKIN_HDRS+=ros_publish_test.h ros_subscribe_test.h

SPECIFIC_CPPFLAGS+=-DNO_ROS=1

.include "../../../mk/util.mk"		# required for gu_util
.include "../../../mk/libcxx.mk"	# required for C++11
.include "../../../mk/whiteboard.mk"	# required for whiteboard clients

test: host
	${BUILDDIR}/${BIN}

.include "../../../mk/mipal.mk"		# comes last!
