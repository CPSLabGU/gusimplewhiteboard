#
#	$Id$
#
# Documentation target
#
BIN=

ALL_TARGETS=documentation

CI_NAME=Docs.WB.Classes
CI_DESCRIPTION=This is the Doxygen documentation for the whiteboard classes used within GUNao.

HDRS!=ls *.h
CI_HEADER_DOC_JOBS=yes

WEB_SERVER_DIR=/Users/Shared/www/mipal.net
CI_EXTRA_COMMANDS=								\
	rm -rf ${WEB_SERVER_DIR}/Docs/Whiteboard.Class.Docs;			\
	cp -r documentation ${WEB_SERVER_DIR}/Docs/Whiteboard.Class.Docs;

.include "../../../mk/mipal.mk"		# comes last!
