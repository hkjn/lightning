# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/drgrid/lightning/hardwared/yajl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/drgrid/lightning/hardwared/yajl

# Utility rule file for test-api.

# Include the progress variables for this target.
include CMakeFiles/test-api.dir/progress.make

CMakeFiles/test-api:
	cd /home/drgrid/lightning/hardwared/yajl/test/api && /home/drgrid/lightning/hardwared/yajl/test/api/run_tests.sh

test-api: CMakeFiles/test-api
test-api: CMakeFiles/test-api.dir/build.make

.PHONY : test-api

# Rule to build all files generated by this target.
CMakeFiles/test-api.dir/build: test-api

.PHONY : CMakeFiles/test-api.dir/build

CMakeFiles/test-api.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test-api.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test-api.dir/clean

CMakeFiles/test-api.dir/depend:
	cd /home/drgrid/lightning/hardwared/yajl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/drgrid/lightning/hardwared/yajl /home/drgrid/lightning/hardwared/yajl /home/drgrid/lightning/hardwared/yajl /home/drgrid/lightning/hardwared/yajl /home/drgrid/lightning/hardwared/yajl/CMakeFiles/test-api.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test-api.dir/depend
