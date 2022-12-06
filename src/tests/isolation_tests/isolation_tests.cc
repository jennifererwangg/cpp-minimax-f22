#include <iostream>
#include "core/solver/minimax_solver.h"
#include "core/games/isolation.h"
#include "tests/isolation_tests/isolation_tests.h"

using namespace std;
using namespace minimax::core;

/**
 ********************************************************
 * Isolation tests (src/core/games/isolation.cc)
 ********************************************************
 */
bool testIsolationIsDone() {
  std::shared_ptr<Isolation> isolation = std::make_shared<Isolation>();
  
  // IBoardEntry Configuration 1 (One player is completely blocked)
  std::vector<std::vector<IBoardEntry>> board = {
      {BLOCKED, BLOCKED, BLOCKED},
      {P1, BLOCKED, FREE},
      {BLOCKED, BLOCKED, P2}};
  isolation->setBoard(board);
  // tictactoe->printState();
  if (!isolation->isDone()) {
    std::cout << "testIsolationIsDone() failed for configuration 1!\n";
    return false;
  }

  // IBoardEntry Configuration 2 (Both players are completely blocked)
  board = {
      {BLOCKED, BLOCKED, BLOCKED},
      {P1, BLOCKED, BLOCKED},
      {BLOCKED, BLOCKED, P2}};
  isolation->setBoard(board);
  if (!isolation->isDone()) {
    std::cout << "testIsolationIsDone() failed for configuration 2!\n";
    return false;
  }

  // IBoardEntry Configuration 3 (Both players have available moves)
  board = {
      {FREE, BLOCKED, BLOCKED},
      {P1, BLOCKED, FREE},
      {BLOCKED, BLOCKED, P2}};
  isolation->setBoard(board);
  // tictactoe->printState();
  if (isolation->isDone()) {
    std::cout << "testIsolationIsDone() failed for configuration 3!\n";
    return false;
  }

  return true;
}

bool testIsolationNextState() {
  std::shared_ptr<Isolation> isolation = std::make_shared<Isolation>(2);
  
  // IBoardEntry Configuration 1 (Restricted Movement)
  std::vector<std::vector<IBoardEntry>> board = {
      {BLOCKED, BLOCKED, FREE},
      {P1, BLOCKED, FREE},
      {BLOCKED, FREE, P2}};
  isolation->setBoard(board);
  std::vector<std::shared_ptr<GameState>> nextStates = isolation->getNextState();
  // UNCOMMENT TO SEE NEXT STATES
  // for (auto &state : nextStates) {
  //   state->printState();
  // }
  if (nextStates.size() != 3) {
    std::cout << "testIsolationNextState() failed for configuration 1!\n";
    return false;
  }

  // IBoardEntry Configuration 2 (Unrestricted Movement, but check that it can only move in one direction at a time)
  board = {
      {FREE, FREE, FREE},
      {P1, FREE, FREE},
      {FREE, FREE, P2}};
  isolation->setBoard(board);
  nextStates = isolation->getNextState();
  // UNCOMMENT TO SEE NEXT STATES
  // for (auto &state : nextStates) {
  //   state->printState();
  // }
  if (nextStates.size() != 6) {
    std::cout << "testIsolationNextState() failed for configuration 2!\n";
    return false;
  }

  return true;
}

bool testIsolationMakeMove() {
  std::shared_ptr<Isolation> isolation = std::make_shared<Isolation>();
  
  // IBoardEntry Configuration 1 (Allowed move)
  std::vector<std::vector<IBoardEntry>> board = {
      {FREE, BLOCKED, FREE},
      {P1, BLOCKED, FREE},
      {BLOCKED, FREE, P2}};
  isolation->setBoard(board);
  bool possible = isolation->makeMove(0, 0);
  if (!possible) {
    std::cout << "testIsolationMakeMove() failed for configuration 1!\n";
    return false;
  }

  // IBoardEntry Configuration 2 (Not allowed move-- blocked space)
  board = {
      {BLOCKED, FREE, FREE},
      {P1, FREE, FREE},
      {FREE, FREE, P2}};
  possible = isolation->makeMove(0, 0);
  if (possible) {
    std::cout << "testIsolationMakeMove() failed for configuration 2!\n";
    return false;
  }

  // IBoardEntry Configuration 3 (Not allowed move-- free space but no direct path)
  board = {
      {BLOCKED, FREE, FREE},
      {P1, FREE, FREE},
      {FREE, FREE, P2}};
  possible = isolation->makeMove(0, 2);
  if (possible) {
    std::cout << "testIsolationMakeMove() failed for configuration 3!\n";
    return false;
  }

  return true;
}