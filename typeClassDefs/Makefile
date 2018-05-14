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
CI_SERVER_DOC_SUBDIR=Reference/Classes/Whiteboard

.ifndef HDRS
TMP_HDRS!=ls *.h
HDRS?=${TMP_HDRS}
.endif
CI_DOC_JOBS?=${HDRS}
CI_MAKE_ARGS+= HDRS="${HDRS}"

.include "../../../mk/whiteboard.mk"

GEN_FILES!=ls ${WB_TYPECLASSDEFS}/*.gen
## Use the classgenerator (must be installed) to regenerate the generated code from the .gen files.
gen:
.for gen in ${GEN_FILES}
	-@cd ${WB_TYPECLASSDEFS} && classgenerator ${gen} ;
.endfor

.include "../../../mk/mipal.mk"		# comes last!
