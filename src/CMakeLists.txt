cmake_minimum_required(VERSION 3.1.0)

# core
add_subdirectory(core)

# minimax executable
add_subdirectory(minimax_exe)
add_dependencies(minimax_exe minimax_core)

# tests
add_subdirectory(tests)
add_dependencies(minimax_tests minimax_core)
