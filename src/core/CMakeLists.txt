cmake_minimum_required(VERSION 3.1.0)
project (minimax_core)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

# headers
set (HEADERS
  games/game_state.h
  games/tictactoe.h
  games/checkers.h
  solver/minimax_solver.h
)

set (SOURCES
  games/game_state.cc
  games/tictactoe.cc
  games/checkers.cc
  solver/minimax_solver.cc
)

set (SYSTEM_INCLUDES
)

set (EXTERNAL_LIBS
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}
  PRIVATE ./
  PRIVATE ../
  PUBLIC ${minimax_COMMON_SYSTEM_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PUBLIC
  ${minimax_COMMON_EXTERNAL_LIBRARIES}
)

# expose minimax_core's includes and libs to other subprojects
set (${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/..
  ${minimax_COMMON_SYSTEM_INCLUDE_DIRS}
  CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
set (${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME}
  ${minimax_COMMON_EXTERNAL_LIBRARIES}
  CACHE INTERNAL "${PROJECT_NAME}: External Libraries" FORCE)

# set warning/error level
if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion -Wsign-conversion)
endif()

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)