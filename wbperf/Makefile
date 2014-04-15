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

CATKIN_SRCS+=ros_publish_test.cc
CATKIN_HDRS+=ros_publish_test.h

SPECIFIC_CPPFLAGS+=-DNO_ROS=1

#NEW_WHITEBOARD_SRCS+=guwhiteboardgetter.cpp guwhiteboardposter.cpp

.include "../../../mk/util.mk"		# required for gu_util
.include "../../../mk/libcxx.mk"	# required for C++11
.include "../../../mk/whiteboard.mk"	# required for whiteboard clients
.include "../../../mk/mipal.mk"		# comes last!
