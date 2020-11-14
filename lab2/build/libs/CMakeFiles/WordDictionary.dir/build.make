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
CMAKE_SOURCE_DIR = /home/nilsiker/edaf30/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nilsiker/edaf30/lab2/build

# Include any dependencies generated for this target.
include libs/CMakeFiles/WordDictionary.dir/depend.make

# Include the progress variables for this target.
include libs/CMakeFiles/WordDictionary.dir/progress.make

# Include the compile flags for this target's objects.
include libs/CMakeFiles/WordDictionary.dir/flags.make

libs/CMakeFiles/WordDictionary.dir/dictionary.cc.o: libs/CMakeFiles/WordDictionary.dir/flags.make
libs/CMakeFiles/WordDictionary.dir/dictionary.cc.o: ../libs/dictionary.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nilsiker/edaf30/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/CMakeFiles/WordDictionary.dir/dictionary.cc.o"
	cd /home/nilsiker/edaf30/lab2/build/libs && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WordDictionary.dir/dictionary.cc.o -c /home/nilsiker/edaf30/lab2/libs/dictionary.cc

libs/CMakeFiles/WordDictionary.dir/dictionary.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WordDictionary.dir/dictionary.cc.i"
	cd /home/nilsiker/edaf30/lab2/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nilsiker/edaf30/lab2/libs/dictionary.cc > CMakeFiles/WordDictionary.dir/dictionary.cc.i

libs/CMakeFiles/WordDictionary.dir/dictionary.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WordDictionary.dir/dictionary.cc.s"
	cd /home/nilsiker/edaf30/lab2/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nilsiker/edaf30/lab2/libs/dictionary.cc -o CMakeFiles/WordDictionary.dir/dictionary.cc.s

libs/CMakeFiles/WordDictionary.dir/word.cc.o: libs/CMakeFiles/WordDictionary.dir/flags.make
libs/CMakeFiles/WordDictionary.dir/word.cc.o: ../libs/word.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nilsiker/edaf30/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/CMakeFiles/WordDictionary.dir/word.cc.o"
	cd /home/nilsiker/edaf30/lab2/build/libs && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WordDictionary.dir/word.cc.o -c /home/nilsiker/edaf30/lab2/libs/word.cc

libs/CMakeFiles/WordDictionary.dir/word.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WordDictionary.dir/word.cc.i"
	cd /home/nilsiker/edaf30/lab2/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nilsiker/edaf30/lab2/libs/word.cc > CMakeFiles/WordDictionary.dir/word.cc.i

libs/CMakeFiles/WordDictionary.dir/word.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WordDictionary.dir/word.cc.s"
	cd /home/nilsiker/edaf30/lab2/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nilsiker/edaf30/lab2/libs/word.cc -o CMakeFiles/WordDictionary.dir/word.cc.s

# Object files for target WordDictionary
WordDictionary_OBJECTS = \
"CMakeFiles/WordDictionary.dir/dictionary.cc.o" \
"CMakeFiles/WordDictionary.dir/word.cc.o"

# External object files for target WordDictionary
WordDictionary_EXTERNAL_OBJECTS =

libs/libWordDictionary.a: libs/CMakeFiles/WordDictionary.dir/dictionary.cc.o
libs/libWordDictionary.a: libs/CMakeFiles/WordDictionary.dir/word.cc.o
libs/libWordDictionary.a: libs/CMakeFiles/WordDictionary.dir/build.make
libs/libWordDictionary.a: libs/CMakeFiles/WordDictionary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nilsiker/edaf30/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libWordDictionary.a"
	cd /home/nilsiker/edaf30/lab2/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/WordDictionary.dir/cmake_clean_target.cmake
	cd /home/nilsiker/edaf30/lab2/build/libs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WordDictionary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/CMakeFiles/WordDictionary.dir/build: libs/libWordDictionary.a

.PHONY : libs/CMakeFiles/WordDictionary.dir/build

libs/CMakeFiles/WordDictionary.dir/clean:
	cd /home/nilsiker/edaf30/lab2/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/WordDictionary.dir/cmake_clean.cmake
.PHONY : libs/CMakeFiles/WordDictionary.dir/clean

libs/CMakeFiles/WordDictionary.dir/depend:
	cd /home/nilsiker/edaf30/lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nilsiker/edaf30/lab2 /home/nilsiker/edaf30/lab2/libs /home/nilsiker/edaf30/lab2/build /home/nilsiker/edaf30/lab2/build/libs /home/nilsiker/edaf30/lab2/build/libs/CMakeFiles/WordDictionary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/CMakeFiles/WordDictionary.dir/depend
