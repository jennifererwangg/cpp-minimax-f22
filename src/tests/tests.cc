#include <iostream>
#include "tests/tictactoe_tests/tictactoe_tests.h"
#include "tests/isolation_tests/isolation_tests.h"

using namespace std;

int main() {
  std::cout << "Running tests...\n";

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

  std::cout << "All tests done!\n";

  return 0;
}