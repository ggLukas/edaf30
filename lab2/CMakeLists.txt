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
 add_executable(Spell spell.cc)
 add_executable(DictProcessor dictprocessor.cc)
target_link_libraries (Spell WordDictionary Helpers)
target_link_libraries (DictProcessor Helpers)
