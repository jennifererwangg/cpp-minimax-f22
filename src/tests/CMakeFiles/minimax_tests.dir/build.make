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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shrutiverma/cpp-minimax-f22

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shrutiverma/cpp-minimax-f22

# Include any dependencies generated for this target.
include src/tests/CMakeFiles/minimax_tests.dir/depend.make

# Include the progress variables for this target.
include src/tests/CMakeFiles/minimax_tests.dir/progress.make

# Include the compile flags for this target's objects.
include src/tests/CMakeFiles/minimax_tests.dir/flags.make

src/tests/CMakeFiles/minimax_tests.dir/tests.cc.o: src/tests/CMakeFiles/minimax_tests.dir/flags.make
src/tests/CMakeFiles/minimax_tests.dir/tests.cc.o: src/tests/tests.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shrutiverma/cpp-minimax-f22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/tests/CMakeFiles/minimax_tests.dir/tests.cc.o"
	cd /Users/shrutiverma/cpp-minimax-f22/src/tests && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimax_tests.dir/tests.cc.o -c /Users/shrutiverma/cpp-minimax-f22/src/tests/tests.cc

src/tests/CMakeFiles/minimax_tests.dir/tests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimax_tests.dir/tests.cc.i"
	cd /Users/shrutiverma/cpp-minimax-f22/src/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shrutiverma/cpp-minimax-f22/src/tests/tests.cc > CMakeFiles/minimax_tests.dir/tests.cc.i

src/tests/CMakeFiles/minimax_tests.dir/tests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimax_tests.dir/tests.cc.s"
	cd /Users/shrutiverma/cpp-minimax-f22/src/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shrutiverma/cpp-minimax-f22/src/tests/tests.cc -o CMakeFiles/minimax_tests.dir/tests.cc.s

src/tests/CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.o: src/tests/CMakeFiles/minimax_tests.dir/flags.make
src/tests/CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.o: src/tests/tictactoe_tests/tictactoe_tests.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shrutiverma/cpp-minimax-f22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/tests/CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.o"
	cd /Users/shrutiverma/cpp-minimax-f22/src/tests && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.o -c /Users/shrutiverma/cpp-minimax-f22/src/tests/tictactoe_tests/tictactoe_tests.cc

src/tests/CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.i"
	cd /Users/shrutiverma/cpp-minimax-f22/src/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shrutiverma/cpp-minimax-f22/src/tests/tictactoe_tests/tictactoe_tests.cc > CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.i

src/tests/CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.s"
	cd /Users/shrutiverma/cpp-minimax-f22/src/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shrutiverma/cpp-minimax-f22/src/tests/tictactoe_tests/tictactoe_tests.cc -o CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.s

# Object files for target minimax_tests
minimax_tests_OBJECTS = \
"CMakeFiles/minimax_tests.dir/tests.cc.o" \
"CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.o"

# External object files for target minimax_tests
minimax_tests_EXTERNAL_OBJECTS =

src/tests/minimax_tests: src/tests/CMakeFiles/minimax_tests.dir/tests.cc.o
src/tests/minimax_tests: src/tests/CMakeFiles/minimax_tests.dir/tictactoe_tests/tictactoe_tests.cc.o
src/tests/minimax_tests: src/tests/CMakeFiles/minimax_tests.dir/build.make
src/tests/minimax_tests: src/core/libminimax_core.a
src/tests/minimax_tests: src/tests/CMakeFiles/minimax_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shrutiverma/cpp-minimax-f22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable minimax_tests"
	cd /Users/shrutiverma/cpp-minimax-f22/src/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minimax_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tests/CMakeFiles/minimax_tests.dir/build: src/tests/minimax_tests

.PHONY : src/tests/CMakeFiles/minimax_tests.dir/build

src/tests/CMakeFiles/minimax_tests.dir/clean:
	cd /Users/shrutiverma/cpp-minimax-f22/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/minimax_tests.dir/cmake_clean.cmake
.PHONY : src/tests/CMakeFiles/minimax_tests.dir/clean

src/tests/CMakeFiles/minimax_tests.dir/depend:
	cd /Users/shrutiverma/cpp-minimax-f22 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shrutiverma/cpp-minimax-f22 /Users/shrutiverma/cpp-minimax-f22/src/tests /Users/shrutiverma/cpp-minimax-f22 /Users/shrutiverma/cpp-minimax-f22/src/tests /Users/shrutiverma/cpp-minimax-f22/src/tests/CMakeFiles/minimax_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tests/CMakeFiles/minimax_tests.dir/depend
