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
include CMakeFiles/71-simplify-path.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/71-simplify-path.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/71-simplify-path.dir/flags.make

CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.o: CMakeFiles/71-simplify-path.dir/flags.make
CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.o: ../leetcode/editor/cn/71-simplify-path.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.o -c /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/71-simplify-path.cpp

CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/71-simplify-path.cpp > CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.i

CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/71-simplify-path.cpp -o CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.s

# Object files for target 71-simplify-path
71__simplify__path_OBJECTS = \
"CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.o"

# External object files for target 71-simplify-path
71__simplify__path_EXTERNAL_OBJECTS =

71-simplify-path: CMakeFiles/71-simplify-path.dir/leetcode/editor/cn/71-simplify-path.cpp.o
71-simplify-path: CMakeFiles/71-simplify-path.dir/build.make
71-simplify-path: CMakeFiles/71-simplify-path.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 71-simplify-path"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/71-simplify-path.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/71-simplify-path.dir/build: 71-simplify-path

.PHONY : CMakeFiles/71-simplify-path.dir/build

CMakeFiles/71-simplify-path.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/71-simplify-path.dir/cmake_clean.cmake
.PHONY : CMakeFiles/71-simplify-path.dir/clean

CMakeFiles/71-simplify-path.dir/depend:
	cd /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles/71-simplify-path.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/71-simplify-path.dir/depend
