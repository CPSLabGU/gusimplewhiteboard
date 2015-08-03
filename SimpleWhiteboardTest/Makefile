#
#	$Id$
#
# GU Unit Test Makefile
#
ALL_TARGETS=test
OCUNIT_SUBDIR=

NO_OBJC_ARC= # defined

OCUNIT_HDRS     = SimpleWhiteboardTest.h
OCUNIT_MMFILES  = SimpleWhiteboardTest.mm

ANALYSE_OCUNIT_SRCFILES= # empty

XCPROJPATH=${SRCDIR}/../gusimplewhiteboard.xcodeproj
XCODEBUILD_ARGS=-project ${XCPROJPATH}
XCODEBUILD_TEST_SCHEME=${BIN}

#XCODE_USE_WORKSPACE=yes

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

all: all-real
test: xc
post-test:
	$E${RM} /tmp/guWhiteboard_SimpleWhiteboardTest

post-clean: post-test

.include "../../../mk/libcxx.mk"	# required for C++11
.include "../../../mk/util.mk"		# required for gu_util
.include "../../../mk/whiteboard.mk"	# required for Whiteboard
.include "../../../mk/ocunit.mk"	# required for Unit Tests

.include "../../../mk/mipal.mk"
