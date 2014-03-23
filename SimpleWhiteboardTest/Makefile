#
#	$Id$
#
# GU Unit Test Makefile
#
ALL_TARGETS=test
OCUNIT_SUBDIR=SimpleWhiteboardTest
BIN=${OCUNIT_SUBDIR}.bundle

OCUNIT_HDRS     = SimpleWhiteboardTest.h
OCUNIT_MMFILES  = SimpleWhiteboardTest.mm

OCUNIT_CPPFILES+= ${UTIL_SRCS}
OCUNIT_CPPFILES+= ${NEW_WHITEBOARD_SRCS}
OCUNIT_CCFILES += ${WHITEBOARD_PRIVATE_CCS}
OCUNIT_CFILES  += ${WHITEBOARD_PRIVATE_CS}

GNUSTEP_SUBST += NEW_WHITEBOARD_SRCS
GNUSTEP_SUBST += WHITEBOARD_PRIVATE_CCS
GNUSTEP_SUBST += NEW_WHITEBOARD_CS
GNUSTEP_SUBST += WHITEBOARD_PRIVATE_CS

SRCDIR!=cd .. && pwd

.include "../../../mk/libcxx.mk"	# required for C++11
.include "../../../mk/util.mk"		# required for gu_util
.include "../../../mk/whiteboard.mk"	# required for Whiteboard
.include "../../../mk/ocunit.mk"	# required for Unit Tests
.include "../../../mk/mipal.mk"
