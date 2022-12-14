#include <iostream>
#include "core/solver/minimax_solver.h"
#include "core/games/tictactoe.h"
#include "tests/tictactoe_tests/tictactoe_tests.h"

using namespace std;
using namespace minimax::core;

/**
 ********************************************************
 * Tic tac toe tests (src/core/games/tictactoe.cc)
 ********************************************************
 */
bool testTicTacToeGetMaxCount() {
  std::shared_ptr<Tictactoe> tictactoe = std::make_shared<Tictactoe>();
  
  // TBoardEntry Configuration 1 (horizontal)
  std::vector<std::vector<TBoardEntry>> board = {
      {X, X, X},
      {O, O, EMPTY},
      {EMPTY, EMPTY, EMPTY}};
  tictactoe->setBoard(board);
  // tictactoe->printState();
  if (tictactoe->getMaxCount(X) != 3) {
    std::cout << "testTicTacToeGetMaxCount() failed for configuration 1.a!\n";
    return false;
  }
  if (tictactoe->getMaxCount(O) != 2) {
    std::cout << "testTicTacToeGetMaxCount() failed for configuration 1.b!\n";
    return false;
  }

  // TBoardEntry Configuration 2 (vertical)
  board = {
      {X, O, EMPTY},
      {X, O, EMPTY},
      {X, EMPTY, EMPTY}};
  tictactoe->setBoard(board);
  // tictactoe->printState();
  if (tictactoe->getMaxCount(X) != 3) {
    std::cout << "testTicTacToeGetMaxCount() failed for configuration 2.a!\n";
    return false;
  }
  if (tictactoe->getMaxCount(O) != 2) {
    std::cout << "testTicTacToeGetMaxCount() failed for configuration 2.b!\n";
    return false;
  }

  // TBoardEntry Configuration 3 (diagonal)
  board = {
      {X, O, EMPTY},
      {O, X, EMPTY},
      {EMPTY, EMPTY, X}};
  tictactoe->setBoard(board);
  // tictactoe->printState();
  if (tictactoe->getMaxCount(X) != 3) {
    std::cout << "testTicTacToeGetMaxCount() failed for configuration 3.a!\n";
    return false;
  }
  if (tictactoe->getMaxCount(O) != 1) {
    std:: cout << "testTicTacToeGetMaxCount() failed for configuration 3.b!\n";
    return false;
  }

  return true;
}

bool testTicTacToeNextState() {
  std::shared_ptr<Tictactoe> tictactoe = std::make_shared<Tictactoe>();
  
  // TBoardEntry Configuration 1 (O's turn)
  std::vector<std::vector<TBoardEntry>> board = {
      {X, X, X},
      {O, O, EMPTY},
      {EMPTY, EMPTY, EMPTY}};
  tictactoe->setBoard(board);
  // tictactoe->printState();
  std::vector<std::shared_ptr<GameState>> nextStates = tictactoe->getNextState();
  // UNCOMMENT TO SEE NEXT STATES
  // for (auto &state : nextStates) {
  //   state->printState();
  // }

  // TBoardEntry Configuration 2 (X's turn)
  board = {
      {X, O, EMPTY},
      {X, O, EMPTY},
      {EMPTY, EMPTY, EMPTY}};
  tictactoe->setBoard(board);
  // tictactoe->printState();
  nextStates = tictactoe->getNextState();
  // UNCOMMENT TO SEE NEXT STATES
  // for (auto &state : nextStates) {
  //   state->printState();
  // }

  // TBoardEntry Configuration 3 (empty board: X's turn)
  board = {
      {EMPTY, EMPTY, EMPTY},
      {EMPTY, EMPTY, EMPTY},
      {EMPTY, EMPTY, EMPTY}};
  tictactoe->setBoard(board);
  // tictactoe->printState();
  nextStates = tictactoe->getNextState();
  // UNCOMMENT TO SEE NEXT STATES
  // for (auto &state : nextStates) {
  //   state->printState();
  // }

  return true;
}