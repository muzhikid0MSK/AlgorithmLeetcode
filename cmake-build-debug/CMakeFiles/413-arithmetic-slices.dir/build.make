# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/muzhikid/CLionProjects/AlgorithmLeetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/413-arithmetic-slices.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/413-arithmetic-slices.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/413-arithmetic-slices.dir/flags.make

CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.o: CMakeFiles/413-arithmetic-slices.dir/flags.make
CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.o: ../leetcode/editor/cn/413-arithmetic-slices.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.o -c /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/413-arithmetic-slices.cpp

CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/413-arithmetic-slices.cpp > CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.i

CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/413-arithmetic-slices.cpp -o CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.s

# Object files for target 413-arithmetic-slices
413__arithmetic__slices_OBJECTS = \
"CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.o"

# External object files for target 413-arithmetic-slices
413__arithmetic__slices_EXTERNAL_OBJECTS =

413-arithmetic-slices: CMakeFiles/413-arithmetic-slices.dir/leetcode/editor/cn/413-arithmetic-slices.cpp.o
413-arithmetic-slices: CMakeFiles/413-arithmetic-slices.dir/build.make
413-arithmetic-slices: CMakeFiles/413-arithmetic-slices.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 413-arithmetic-slices"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/413-arithmetic-slices.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/413-arithmetic-slices.dir/build: 413-arithmetic-slices

.PHONY : CMakeFiles/413-arithmetic-slices.dir/build

CMakeFiles/413-arithmetic-slices.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/413-arithmetic-slices.dir/cmake_clean.cmake
.PHONY : CMakeFiles/413-arithmetic-slices.dir/clean

CMakeFiles/413-arithmetic-slices.dir/depend:
	cd /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles/413-arithmetic-slices.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/413-arithmetic-slices.dir/depend

