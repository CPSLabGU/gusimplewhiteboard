#
#	$Id$
#
# GU Unit Test Makefile
#
BIN=SimpleWhiteboardTest
ALL_TARGETS=test
OCUNIT_SUBDIR=${BIN}

OCUNIT_HDRS     = SimpleWhiteboardTest.h
OCUNIT_MMFILES  = SimpleWhiteboardTest.mm

.ifdef GNUSTEP_MAKEFILES
OCUNIT_CPPFILES+= ${UTIL_SRCS}
OCUNIT_CPPFILES+= ${NEW_WHITEBOARD_SRCS}
OCUNIT_CCFILES += ${WHITEBOARD_PRIVATE_CCS}
OCUNIT_CFILES  += ${WHITEBOARD_PRIVATE_CS}
.endif

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
