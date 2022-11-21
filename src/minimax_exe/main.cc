#include <iostream>
#include <string>
#include "core/node.h"
#include "core/games/game_state.h"
#include "core/games/tictactoe.h"
#include "core/solver/minimax_solver.h"
#include "main.h"

using namespace std;
using namespace minimax::core;

int main(int /*argc*/, char **/*argv*/)
{
  cout << "Welcome to tic tac toe player!\n";

  automaticTicTacToePlayer();

  return 0;
}

void automaticTicTacToePlayer() {
  // Initialize tic tac toe game 
  GameState::Ptr tictactoe = std::make_shared<Tictactoe>();

  for (;;) {
    MinimaxSolver solver(10);
    GameState::Ptr next_best_state = solver.evaluate(tictactoe);
    next_best_state->printState();
    tictactoe = next_best_state;
    if (tictactoe->isDone()) {
      break;
    }
  }
}