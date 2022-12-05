#include <iostream>
#include <string>
#include "core/games/game_state.h"
#include "core/games/tictactoe.h"
#include "core/games/checkers.h"
#include "core/solver/minimax_solver.h"
#include "core/players/automatic_player.h"
#include "core/players/interactive_player.h"
#include "core/players/checkers_player.h"
#include "core/games/tictactoe.h"

using namespace std;
using namespace minimax::core;

int main(int /*argc*/, char **/*argv*/) {
  cout << "Welcome to checkers player!\n";

  // Automatically play tic tac toe (uncomment to play)
  // std::shared_ptr<GameState> tictactoe = std::make_shared<Tictactoe>(); // create game
  // AutomaticPlayer tic_tac_toe_player(tictactoe, 5); // create player
  // tic_tac_toe_player.play(); // play game

  // Interactive tic tac toe (uncomment to play)
  std::shared_ptr<checkers::Checkers> checkers = std::make_shared<checkers::Checkers>(); // create game
  InteractiveCheckersPlayer interactive_checkers_player(checkers, 5, "B", "W"); // create player
  interactive_checkers_player.play(); // play game

  return 0;
}

void automaticCheckersPlayer() {
  std::shared_ptr<GameState> checkers = std::make_shared<checkers::Checkers>();
  checkers->printState();
  for (;;) {
    MinimaxSolver solver(5);
    std::shared_ptr<GameState> next_best_state = solver.evaluate(checkers);
    next_best_state->printState();
    checkers = next_best_state;
    if (checkers->isDone()) {
      break;
    }
  }
}
