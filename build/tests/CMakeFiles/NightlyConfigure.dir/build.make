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

# Utility rule file for NightlyConfigure.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/NightlyConfigure.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/NightlyConfigure.dir/progress.make

tests/CMakeFiles/NightlyConfigure:
	cd "/home/syrmia/modern c++/domaci/igg_image/build/tests" && /usr/local/bin/ctest -D NightlyConfigure

NightlyConfigure: tests/CMakeFiles/NightlyConfigure
NightlyConfigure: tests/CMakeFiles/NightlyConfigure.dir/build.make
.PHONY : NightlyConfigure

# Rule to build all files generated by this target.
tests/CMakeFiles/NightlyConfigure.dir/build: NightlyConfigure
.PHONY : tests/CMakeFiles/NightlyConfigure.dir/build

tests/CMakeFiles/NightlyConfigure.dir/clean:
	cd "/home/syrmia/modern c++/domaci/igg_image/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/NightlyConfigure.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/NightlyConfigure.dir/clean

tests/CMakeFiles/NightlyConfigure.dir/depend:
	cd "/home/syrmia/modern c++/domaci/igg_image/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/syrmia/modern c++/domaci/igg_image" "/home/syrmia/modern c++/domaci/igg_image/tests" "/home/syrmia/modern c++/domaci/igg_image/build" "/home/syrmia/modern c++/domaci/igg_image/build/tests" "/home/syrmia/modern c++/domaci/igg_image/build/tests/CMakeFiles/NightlyConfigure.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/NightlyConfigure.dir/depend

