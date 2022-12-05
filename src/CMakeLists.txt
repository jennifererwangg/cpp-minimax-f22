cmake_minimum_required(VERSION 3.1.0)

# core
add_subdirectory(core)

# tests
add_subdirectory(tests)
add_dependencies(minimax_tests minimax_core)

# tictactoe executable
add_subdirectory(games_exe/tictactoe)
add_dependencies(tictactoe minimax_core)

# isolation executable
add_subdirectory(games_exe/isolation)
add_dependencies(isolation minimax_core)

# checkers executable
add_subdirectory(games_exe/checkers)
add_dependencies(checkers minimax_core)
