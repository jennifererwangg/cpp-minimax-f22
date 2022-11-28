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
include src/core/CMakeFiles/minimax_core.dir/depend.make

# Include the progress variables for this target.
include src/core/CMakeFiles/minimax_core.dir/progress.make

# Include the compile flags for this target's objects.
include src/core/CMakeFiles/minimax_core.dir/flags.make

src/core/CMakeFiles/minimax_core.dir/games/game_state.cc.o: src/core/CMakeFiles/minimax_core.dir/flags.make
src/core/CMakeFiles/minimax_core.dir/games/game_state.cc.o: src/core/games/game_state.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shrutiverma/cpp-minimax-f22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/core/CMakeFiles/minimax_core.dir/games/game_state.cc.o"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimax_core.dir/games/game_state.cc.o -c /Users/shrutiverma/cpp-minimax-f22/src/core/games/game_state.cc

src/core/CMakeFiles/minimax_core.dir/games/game_state.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimax_core.dir/games/game_state.cc.i"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shrutiverma/cpp-minimax-f22/src/core/games/game_state.cc > CMakeFiles/minimax_core.dir/games/game_state.cc.i

src/core/CMakeFiles/minimax_core.dir/games/game_state.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimax_core.dir/games/game_state.cc.s"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shrutiverma/cpp-minimax-f22/src/core/games/game_state.cc -o CMakeFiles/minimax_core.dir/games/game_state.cc.s

src/core/CMakeFiles/minimax_core.dir/games/tictactoe.cc.o: src/core/CMakeFiles/minimax_core.dir/flags.make
src/core/CMakeFiles/minimax_core.dir/games/tictactoe.cc.o: src/core/games/tictactoe.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shrutiverma/cpp-minimax-f22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/core/CMakeFiles/minimax_core.dir/games/tictactoe.cc.o"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimax_core.dir/games/tictactoe.cc.o -c /Users/shrutiverma/cpp-minimax-f22/src/core/games/tictactoe.cc

src/core/CMakeFiles/minimax_core.dir/games/tictactoe.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimax_core.dir/games/tictactoe.cc.i"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shrutiverma/cpp-minimax-f22/src/core/games/tictactoe.cc > CMakeFiles/minimax_core.dir/games/tictactoe.cc.i

src/core/CMakeFiles/minimax_core.dir/games/tictactoe.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimax_core.dir/games/tictactoe.cc.s"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shrutiverma/cpp-minimax-f22/src/core/games/tictactoe.cc -o CMakeFiles/minimax_core.dir/games/tictactoe.cc.s

src/core/CMakeFiles/minimax_core.dir/games/isolation.cc.o: src/core/CMakeFiles/minimax_core.dir/flags.make
src/core/CMakeFiles/minimax_core.dir/games/isolation.cc.o: src/core/games/isolation.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shrutiverma/cpp-minimax-f22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/core/CMakeFiles/minimax_core.dir/games/isolation.cc.o"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimax_core.dir/games/isolation.cc.o -c /Users/shrutiverma/cpp-minimax-f22/src/core/games/isolation.cc

src/core/CMakeFiles/minimax_core.dir/games/isolation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimax_core.dir/games/isolation.cc.i"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shrutiverma/cpp-minimax-f22/src/core/games/isolation.cc > CMakeFiles/minimax_core.dir/games/isolation.cc.i

src/core/CMakeFiles/minimax_core.dir/games/isolation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimax_core.dir/games/isolation.cc.s"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shrutiverma/cpp-minimax-f22/src/core/games/isolation.cc -o CMakeFiles/minimax_core.dir/games/isolation.cc.s

src/core/CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.o: src/core/CMakeFiles/minimax_core.dir/flags.make
src/core/CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.o: src/core/solver/minimax_solver.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shrutiverma/cpp-minimax-f22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/core/CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.o"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.o -c /Users/shrutiverma/cpp-minimax-f22/src/core/solver/minimax_solver.cc

src/core/CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.i"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shrutiverma/cpp-minimax-f22/src/core/solver/minimax_solver.cc > CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.i

src/core/CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.s"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shrutiverma/cpp-minimax-f22/src/core/solver/minimax_solver.cc -o CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.s

# Object files for target minimax_core
minimax_core_OBJECTS = \
"CMakeFiles/minimax_core.dir/games/game_state.cc.o" \
"CMakeFiles/minimax_core.dir/games/tictactoe.cc.o" \
"CMakeFiles/minimax_core.dir/games/isolation.cc.o" \
"CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.o"

# External object files for target minimax_core
minimax_core_EXTERNAL_OBJECTS =

src/core/libminimax_core.a: src/core/CMakeFiles/minimax_core.dir/games/game_state.cc.o
src/core/libminimax_core.a: src/core/CMakeFiles/minimax_core.dir/games/tictactoe.cc.o
src/core/libminimax_core.a: src/core/CMakeFiles/minimax_core.dir/games/isolation.cc.o
src/core/libminimax_core.a: src/core/CMakeFiles/minimax_core.dir/solver/minimax_solver.cc.o
src/core/libminimax_core.a: src/core/CMakeFiles/minimax_core.dir/build.make
src/core/libminimax_core.a: src/core/CMakeFiles/minimax_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shrutiverma/cpp-minimax-f22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libminimax_core.a"
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && $(CMAKE_COMMAND) -P CMakeFiles/minimax_core.dir/cmake_clean_target.cmake
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minimax_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/core/CMakeFiles/minimax_core.dir/build: src/core/libminimax_core.a

.PHONY : src/core/CMakeFiles/minimax_core.dir/build

src/core/CMakeFiles/minimax_core.dir/clean:
	cd /Users/shrutiverma/cpp-minimax-f22/src/core && $(CMAKE_COMMAND) -P CMakeFiles/minimax_core.dir/cmake_clean.cmake
.PHONY : src/core/CMakeFiles/minimax_core.dir/clean

src/core/CMakeFiles/minimax_core.dir/depend:
	cd /Users/shrutiverma/cpp-minimax-f22 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shrutiverma/cpp-minimax-f22 /Users/shrutiverma/cpp-minimax-f22/src/core /Users/shrutiverma/cpp-minimax-f22 /Users/shrutiverma/cpp-minimax-f22/src/core /Users/shrutiverma/cpp-minimax-f22/src/core/CMakeFiles/minimax_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/core/CMakeFiles/minimax_core.dir/depend

