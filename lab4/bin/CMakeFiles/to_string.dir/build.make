# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ungothar/edaf30/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ungothar/edaf30/lab4/bin

# Include any dependencies generated for this target.
include CMakeFiles/to_string.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/to_string.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/to_string.dir/flags.make

CMakeFiles/to_string.dir/to_string.cc.o: CMakeFiles/to_string.dir/flags.make
CMakeFiles/to_string.dir/to_string.cc.o: ../to_string.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ungothar/edaf30/lab4/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/to_string.dir/to_string.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/to_string.dir/to_string.cc.o -c /home/ungothar/edaf30/lab4/to_string.cc

CMakeFiles/to_string.dir/to_string.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/to_string.dir/to_string.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ungothar/edaf30/lab4/to_string.cc > CMakeFiles/to_string.dir/to_string.cc.i

CMakeFiles/to_string.dir/to_string.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/to_string.dir/to_string.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ungothar/edaf30/lab4/to_string.cc -o CMakeFiles/to_string.dir/to_string.cc.s

# Object files for target to_string
to_string_OBJECTS = \
"CMakeFiles/to_string.dir/to_string.cc.o"

# External object files for target to_string
to_string_EXTERNAL_OBJECTS =

to_string: CMakeFiles/to_string.dir/to_string.cc.o
to_string: CMakeFiles/to_string.dir/build.make
to_string: libs/libDateLib.a
to_string: CMakeFiles/to_string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ungothar/edaf30/lab4/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable to_string"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/to_string.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/to_string.dir/build: to_string

.PHONY : CMakeFiles/to_string.dir/build

CMakeFiles/to_string.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/to_string.dir/cmake_clean.cmake
.PHONY : CMakeFiles/to_string.dir/clean

CMakeFiles/to_string.dir/depend:
	cd /home/ungothar/edaf30/lab4/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ungothar/edaf30/lab4 /home/ungothar/edaf30/lab4 /home/ungothar/edaf30/lab4/bin /home/ungothar/edaf30/lab4/bin /home/ungothar/edaf30/lab4/bin/CMakeFiles/to_string.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/to_string.dir/depend

