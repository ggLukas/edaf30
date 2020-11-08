cmake_minimum_required (VERSION 3.5)
project (Simple)
set (CMAKE_CXX_STANDARD 11)

# The version number.
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# add the binary tree to the search path for include files
# so that we will find SimpleConfig.h
include_directories("${PROJECT_BINARY_DIR}")

include_directories ("${PROJECT_SOURCE_DIR}/libs")
add_subdirectory (libs) 

# add the executable
 add_executable(encode encode.cc)
target_link_libraries (encode lab1)
 add_executable(test_coding test_coding.cc)
target_link_libraries (test_coding lab1)
 add_executable(test_editor test_editor.cc)
target_link_libraries (test_editor lab1)
