#include <iostream>
#include <string>
#include "core/games/game_state.h"
#include "core/games/checkers.h"
#include "core/solver/minimax_solver.h"
#include "core/players/automatic_player.h"
#include "core/players/checkers_player.h"

using namespace std;
using namespace minimax::core;

int main(int /*argc*/, char **/*argv*/) {
  cout << "Welcome to checkers player!\n";

  // Automatically play checkers (uncomment to play)
  // std::shared_ptr<GameState> checkers = std::make_shared<checkers::Checkers>(); // create game
  // AutomaticPlayer automatic_checkers(checkers, 5); // create player
  // automatic_checkers.play(); // play game

  // Interactive tic tac toe (uncomment to play)
  std::shared_ptr<checkers::Checkers> checkers = std::make_shared<checkers::Checkers>(); // create game
  InteractiveCheckersPlayer interactive_checkers_player(checkers, 5, "B", "W"); // create player
  interactive_checkers_player.play(); // play game

  return 0;
}
