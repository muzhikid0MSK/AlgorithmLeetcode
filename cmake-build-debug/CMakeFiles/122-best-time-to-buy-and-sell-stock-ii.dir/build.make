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
include CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/flags.make

CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.o: CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/flags.make
CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.o: ../leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.o -c /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp

CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp > CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.i

CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp -o CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.s

# Object files for target 122-best-time-to-buy-and-sell-stock-ii
122__best__time__to__buy__and__sell__stock__ii_OBJECTS = \
"CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.o"

# External object files for target 122-best-time-to-buy-and-sell-stock-ii
122__best__time__to__buy__and__sell__stock__ii_EXTERNAL_OBJECTS =

122-best-time-to-buy-and-sell-stock-ii: CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp.o
122-best-time-to-buy-and-sell-stock-ii: CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/build.make
122-best-time-to-buy-and-sell-stock-ii: CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 122-best-time-to-buy-and-sell-stock-ii"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/build: 122-best-time-to-buy-and-sell-stock-ii

.PHONY : CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/build

CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/cmake_clean.cmake
.PHONY : CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/clean

CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/depend:
	cd /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug /Users/muzhikid/CLionProjects/AlgorithmLeetcode/cmake-build-debug/CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/122-best-time-to-buy-and-sell-stock-ii.dir/depend

