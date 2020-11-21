cmake_minimum_required (VERSION 3.5)
project (Simple)
set (CMAKE_CXX_STANDARD 11)

# The version number.
set (Simple_VERSION_MAJOR 1)
set (Simple_VERSION_MINOR 0)

# add the binary tree to the search path for include files
# so that we will find SimpleConfig.h
include_directories("${PROJECT_BINARY_DIR}")

include_directories ("${PROJECT_SOURCE_DIR}/libs")
add_subdirectory (libs) 

# add the executable
 add_executable(UserProgram UserProgram.cc)
target_link_libraries (UserProgram UserLib)
