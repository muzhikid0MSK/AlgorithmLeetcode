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
include CMakeFiles/39-combination-sum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/39-combination-sum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/39-combination-sum.dir/flags.make

CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.o: CMakeFiles/39-combination-sum.dir/flags.make
CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.o: ../leetcode/editor/cn/39-combination-sum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.o -c /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/39-combination-sum.cpp

CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/39-combination-sum.cpp > CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.i

CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/39-combination-sum.cpp -o CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.s

# Object files for target 39-combination-sum
39__combination__sum_OBJECTS = \
"CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.o"

# External object files for target 39-combination-sum
39__combination__sum_EXTERNAL_OBJECTS =

39-combination-sum: CMakeFiles/39-combination-sum.dir/leetcode/editor/cn/39-combination-sum.cpp.o
39-combination-sum: CMakeFiles/39-combination-sum.dir/build.make
39-combination-sum: CMakeFiles/39-combination-sum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 39-combination-sum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/39-combination-sum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/39-combination-sum.dir/build: 39-combination-sum

.PHONY : CMakeFiles/39-combination-sum.dir/build

CMakeFiles/39-combination-sum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/39-combination-sum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/39-combination-sum.dir/clean

CMakeFiles/39-combination-sum.dir/depend:
	cd /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles/39-combination-sum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/39-combination-sum.dir/depend

