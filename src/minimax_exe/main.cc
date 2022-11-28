#include <iostream>
#include <string>
#include "core/games/game_state.h"
#include "core/games/tictactoe.h"
#include "core/games/isolation.h"
#include "core/solver/minimax_solver.h"
#include "main.h"

using namespace std;
using namespace minimax::core;

int main(int /*argc*/, char **/*argv*/)
{
  cout << "Welcome to the automatic player!\n";

  automaticPlayer(ISOLATION);
  return 0;
}

void automaticPlayer(Game g) {
  std::shared_ptr<GameState> game;
  switch(g) {
    case TICTACTOE:
      game = std::make_shared<Tictactoe>();
      break;
    case ISOLATION:
      game = std::make_shared<Isolation>();
      break;
  }
  for (;;) {
    MinimaxSolver solver(10);
    std::shared_ptr<GameState> next_best_state = solver.evaluate(game);
    next_best_state->printState();
    game = next_best_state;
    if (game->isDone()) {
      break;
    }
  }
}