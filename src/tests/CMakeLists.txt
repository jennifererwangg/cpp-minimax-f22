cmake_minimum_required(VERSION 3.1.0)
project (minimax_tests)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

# headers
set (HEADERS
  tictactoe_tests/tictactoe_tests.h
  checkers_tests/checkers_test.h
  isolation_tests/isolation_tests.h
  performance/performance_tests.h
)

set (SOURCES
  tests.cc
  tictactoe_tests/tictactoe_tests.cc
  checkers_tests/checkers_test.cc
  isolation_tests/isolation_tests.cc
  performance/performance_tests.cc
)

set (SYSTEM_INCLUDES
)

set (EXTERNAL_LIBS
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}
  PRIVATE ./
  PRIVATE ${minimax_core_INCLUDE_DIRS}
  PRIVATE ${SYSTEM_INCLUDES})
target_link_libraries(${PROJECT_NAME}
  PRIVATE ${minimax_core_LIBRARIES}
  PRIVATE ${EXTERNAL_LIBS}
)

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
