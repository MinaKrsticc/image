# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/syrmia/modern c++/domaci/igg_image"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/syrmia/modern c++/domaci/igg_image/build"

# Utility rule file for ContinuousTest.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/ContinuousTest.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/ContinuousTest.dir/progress.make

tests/CMakeFiles/ContinuousTest:
	cd "/home/syrmia/modern c++/domaci/igg_image/build/tests" && /usr/local/bin/ctest -D ContinuousTest

ContinuousTest: tests/CMakeFiles/ContinuousTest
ContinuousTest: tests/CMakeFiles/ContinuousTest.dir/build.make
.PHONY : ContinuousTest

# Rule to build all files generated by this target.
tests/CMakeFiles/ContinuousTest.dir/build: ContinuousTest
.PHONY : tests/CMakeFiles/ContinuousTest.dir/build

tests/CMakeFiles/ContinuousTest.dir/clean:
	cd "/home/syrmia/modern c++/domaci/igg_image/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousTest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ContinuousTest.dir/clean

tests/CMakeFiles/ContinuousTest.dir/depend:
	cd "/home/syrmia/modern c++/domaci/igg_image/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/syrmia/modern c++/domaci/igg_image" "/home/syrmia/modern c++/domaci/igg_image/tests" "/home/syrmia/modern c++/domaci/igg_image/build" "/home/syrmia/modern c++/domaci/igg_image/build/tests" "/home/syrmia/modern c++/domaci/igg_image/build/tests/CMakeFiles/ContinuousTest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/ContinuousTest.dir/depend

