# Components: private_headers, compiler_support

include (FindPackageHandleStandardArgs)
include (CheckFunctionExists)
include (CheckCCompilerFlag)

find_path(BLOCKSRUNTIME_PUBLIC_INCLUDE_DIR dispatch/dispatch.h
  DOC "Path to dispatch/dispatch.h"
)

if (BLOCKSRUNTIME_PUBLIC_INCLUDE_DIR)
  list (APPEND BLOCKSRUNTIME_INCLUDE_DIRS ${BLOCKSRUNTIME_PUBLIC_INCLUDE_DIR})
endif ()

check_function_exists(BLOCKSRUNTIME_RUNTIME_IN_LIBC _dispatch_async_f)

if (BLOCKSRUNTIME_RUNTIME_IN_LIBC)
  set (BLOCKSRUNTIME_LIBRARIES "c")
else ()
  if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set (BLOCKSRUNTIME_LIBRARIES "c")
    set (BLOCKSRUNTIME_LINKER_FLAGS "-framework System")
  else ()
    find_library(BLOCKSRUNTIME_OBJC_LIBRARIES "objc" HINTS /usr/local/lib "${CMAKE_CURRENT_LIST_DIR}" /usr/lib)
    find_library(BLOCKSRUNTIME_LIBRARIES "BlocksRuntime" HINTS /usr/local/lib "${CMAKE_CURRENT_LIST_DIR}" /usr/lib)
  endif ()
endif ()

check_c_compiler_flag("-fblocks" BLOCKSRUNTIME_COMPILER_BLOCKS_SUPPORT_FOUND)
if (BLOCKSRUNTIME_COMPILER_BLOCKS_SUPPORT_FOUND)
  set (BLOCKSRUNTIME_COMPILE_FLAGS "-fblocks")
  set (CBlocks_compiler_support_FOUND TRUE)  # for FPHSA
endif ()

find_package_handle_standard_args(LibDispatch
  REQUIRED_VARS BLOCKSRUNTIME_LIBRARIES BLOCKSRUNTIME_PUBLIC_INCLUDE_DIR
  HANDLE_COMPONENTS
)

