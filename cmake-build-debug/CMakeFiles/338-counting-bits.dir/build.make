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
include CMakeFiles/338-counting-bits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/338-counting-bits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/338-counting-bits.dir/flags.make

CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.o: CMakeFiles/338-counting-bits.dir/flags.make
CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.o: ../leetcode/editor/cn/338-counting-bits.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.o -c /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/338-counting-bits.cpp

CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/338-counting-bits.cpp > CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.i

CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/338-counting-bits.cpp -o CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.s

# Object files for target 338-counting-bits
338__counting__bits_OBJECTS = \
"CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.o"

# External object files for target 338-counting-bits
338__counting__bits_EXTERNAL_OBJECTS =

338-counting-bits: CMakeFiles/338-counting-bits.dir/leetcode/editor/cn/338-counting-bits.cpp.o
338-counting-bits: CMakeFiles/338-counting-bits.dir/build.make
338-counting-bits: CMakeFiles/338-counting-bits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 338-counting-bits"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/338-counting-bits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/338-counting-bits.dir/build: 338-counting-bits

.PHONY : CMakeFiles/338-counting-bits.dir/build

CMakeFiles/338-counting-bits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/338-counting-bits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/338-counting-bits.dir/clean

CMakeFiles/338-counting-bits.dir/depend:
	cd /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles/338-counting-bits.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/338-counting-bits.dir/depend
