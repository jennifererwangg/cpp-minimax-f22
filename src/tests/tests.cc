#include <iostream>
#include "tests/tictactoe_tests/tictactoe_tests.h"
#include "tests/checkers_tests/checkers_test.h"
#include "tests/isolation_tests/isolation_tests.h"
#include "tests/performance/performance_tests.h"

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Incorrect usage. Please run: ./minimax_tests <u/p>\n";
    return 0;
  }

  string option = argv[1];
  if (option != "u" && option != "p") {
    cout << "Incorrect usage. Please run: ./minimax_tests <u/p>\n";
    return 0;
  }

  bool unit = false;
  if (option == "u")
    unit = true;

  if (!unit) { // run performance tests
    std::cout << "Running performance tests...\n";
    depthTest(7);
  } else {
    std::cout << "Running unit tests...\n";

    /**
     ********************************************************
    * Tic tac toe tests 
    ********************************************************
    */
    std::cout << "Running tic tac toe tests...\n";
    if (!testTicTacToeGetMaxCount()) {
      std::cout << "testTicTacToeGetMaxCount() failed!\n";
    }
    if (!testTicTacToeNextState()) { 
      // NOTE: this test always succeeds (need to uncomment the print statements in the function)
      std::cout << "testTicTacToeNextState() failed!\n";
    }
    std::cout << "Done running tic tac toe tests.\n";
    // ******************************************************

    /**
     ********************************************************
    * Checkers tests 
    ********************************************************
    */
    std::cout << "Running checkers tests...\n";
    if (!testCheckersSetup()) {
      std::cout << "testCheckersSetup() failed!\n";
    } else {
      std::cout << "testCheckersSetup() succeeded!\n";
    }

    if (!testGetNextMoves()) {
      std::cout << "testGetNextMoves() failed!\n";
    } else {
      std::cout << "testGetNextMoves() succeeded!\n";
    }

    if (!testJump()) {
      std::cout << "testJump() failed!\n";
    } else {
      std::cout << "testJump() succeeded!\n";
    }

    if (!testNextMove()) {
      std::cout << "testNextMove() failed!\n";
    } else {
      std::cout << "testNextMove() succeeded!\n";
    }

    if (!testJumpMove()) {
      std::cout << "testJumpMove() failed!\n";
    } else {
      std::cout << "testJumpMove() succeeded!\n";
    }
    
    std::cout << "Done running checkers tests.\n";
    // ******************************************************

    /**
     ********************************************************
    * Isolation tests 
    ********************************************************
    */
    std::cout << "Running isolation tests...\n";
    if (!testIsolationIsDone()) {
      std::cout << "testIsolationIsDone() failed!\n";
    }
    if (!testIsolationNextState()) {
      std::cout << "testIsolationNextState() failed!\n";
    }
    if (!testIsolationMakeMove()) { 
      // NOTE: this test always succeeds (need to uncomment the print statements in the function)
      std::cout << "testIsolationMakeMove() failed!\n";
    }
    std::cout << "Done running isolation tests.\n";
    // ******************************************************

    std::cout << "All unit tests done!\n";
  }

  return 0;
}