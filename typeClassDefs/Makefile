#
#	$Id$
#
# Documentation target
#
BIN=

ALL_TARGETS=documentation

CI_NAME=Docs.WB.Classes
CI_DESCRIPTION=This is the Doxygen documentation for the whiteboard classes used within GUNao.

DOCUMENTATION=${CI_NAME}

TMP_HDRS!=ls *.h
HDRS?=${TMP_HDRS}
CI_DOC_JOBS=${HDRS}
CI_MAKE_ARGS+= HDRS="${HDRS}"

WEB_SERVER_DIR=/Users/Shared/www/mipal.net

.if defined(IGNORE_RECURSIVE_JENKINS)
CI_EXTRA_COMMANDS=	
.else
CI_EXTRA_COMMANDS=							\
	rm -rf ${WEB_SERVER_DIR}/Docs/Whiteboard.Class.Docs;		\
	cp -R ${DOCUMENTATION} ${WEB_SERVER_DIR}/Docs/Whiteboard.Class.Docs;
.endif

.include "../../../mk/mipal.mk"		# comes last!
