#
#	$Id$
#
# GU localisation module Makefile
#
LIB=gusimplewhiteboard
DEPENDS=gu_util guunits gucoordinates

CI_DISPLAYNAME?=wb			# short jenkins display name

DOC_RECURSIVE=YES			# build doxygen recursively

CATKIN_COMPILE_WHITEBOARD=yes		# need wb in catkin
COMPILE_WHITEBOARD_STRING_SOURCES=yes	# add inflection methods to library
COMPILE_WHITEBOARD_SERIALISATION=yes # add serialisation API

BUILD_WB_LIBRARY=yes
ALL_TARGETS=host-local atom-local analyse test xc whiteboard-wrapper

CATKIN_COMPILE_UTIL=YES

CC_SRCS=libgusimplewhiteboardmain.cc 

WB_MSG_C_FILES!= cd typeClassDefs && ls *.c
WBMSG_C_SRCS?=${WB_MSG_C_FILES}

SPECIFIC_LIBS=-lguunits -lgucoordinates

#CFLAGS=-stdlib=libc++
#LDFLAGS=-stdlib=libc++ 

.include "../../mk/c++11.mk"       # can't use C++11 due to naoqi
.include "../../mk/whiteboard.mk"	# required for whiteboard clients

CMAKE_ADDITIONAL_PRIVATE_INCLUDE_DIRECTORIES=${WB_TYPECLASSDEFS_SUBDIR}
CMAKE_ADDITIONAL_PUBLIC_INCLUDE_DIRECTORIES=${WB_TYPECLASSDEFS_SUBDIR}

${MODULE_BASE}_HDRS=${NEW_WHITEBOARD_HDRS} ${WHITEBOARD_COMMON_HDRS} ${WB_TYPECLASSDEFS} ${OLD_WB_SUBDIR} guwhiteboard_c_types.h guwhiteboardserialisation.h guwhiteboard_c_types_manual_definitions.h

WB_VERSION!=grep -Eo 'GU_SIMPLE_WHITEBOARD_VERSION *[[:digit:]]' gusimplewhiteboard.h | sed 's/GU_SIMPLE_WHITEBOARD_VERSION[ ]*//'

PKGCONFIG_NAME=${LIB}
PKGCONFIG_VERSION=${WB_VERSION}
PKGCONFIG_DESCRIPTION=Shared memory IPC mechanism

WB_MSG_GEN_FILES!= ls typeClassDefs/*.gen
WB_MSG_OLD_GEN_FILES!= ls typeClassDefs/*.txt

all: all-real

.include "../../mk/cmake.mk"	# required for cmake

CMAKE_HDIRS+=OLD_WB		# install OLD_WB

generate:
.for f in ${WB_MSG_GEN_FILES}
	classgenerator -s -G typeClassDefs --c-header typeClassDefs -n wb:guWhiteboard --squash-defines --squash-files ${f}
.endfor
.for f in ${WB_MSG_OLD_GEN_FILES}
	classgenerator -s -G typeClassDefs --c-header typeClassDefs -n wb:guWhiteboard --squash-defines --squash-files -b ${f}
.endfor

test:
. if !defined(LOCAL) || ${LOCAL} != _LOCAL
	cd SimpleWhiteboardTest && ${MAKE} ${MAKEFLAGS} test
.else
	$Eecho
.endif

post-clean:

whiteboard-wrapper-defaults: whiteboard-wrapper
	$Ecd ${WB_DIR} && ( \
    sed \
        -e 's/WB_NUM_TYPES_DEFINED/WB_NUM_TYPES_DEFINED_DEFAULT/g' \
        -e 's/wb_types/wb_types_default/g' \
        -e 's/wb_types_default_stringValues/wb_types_stringValues_default/g' \
        -e 's/wb_types_default_typeValues/wb_types_typeValues_default/g' \
    	< guwhiteboardtypelist_c_generated.h > guwhiteboardtypelist_c_generated_default.h && \
    sed \
        -e 's/guwhiteboardtypelist_c_generated.h/guwhiteboardtypelist_c_generated_default.h/g' \
        -e 's/WB_NUM_TYPES_DEFINED/WB_NUM_TYPES_DEFINED_DEFAULT/g' \
        -e 's/BUILD_WB_LIBRARY_GUWHITEBOARD/BUILD_WB_LIBRARY_GUWHITEBOARD_DEFAULT/g' \
        -e 's/wb_types/wb_types_default/g' \
        -e 's/wb_types_default_stringValues/wb_types_stringValues_default/g' \
        -e 's/wb_types_default_typeValues/wb_types_typeValues_default/g' \
    	< guwhiteboardtypelist_c_typestrings_generated.c > guwhiteboardtypelist_c_typestrings_generated_default.c \
    )

whiteboard-wrapper:
	cd ${WB_DIR}/../WhiteboardWrapperGenerator && ${MAKE} host SWIFT_BUILD_CONFIG=release && ./.build/release/WhiteboardWrapperGenerator
	cd SimpleWhiteboardTest && ${MAKE} ${MAKEFLAGS} clean

.include "../../mk/mipal.mk"		# comes last!
