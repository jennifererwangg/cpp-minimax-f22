#include <iostream>
#include <string>
#include "core/games/game_state.h"
#include "core/games/checkers.h"
#include "core/solver/minimax_solver.h"
#include "core/players/automatic_player.h"
#include "core/players/interactive_player.h"

using namespace std;
using namespace minimax::core;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Incorrect usage. Please run: ./checkers <a/i>\n";
    return 0;
  }

  string option = argv[1];
  if (option != "a" && option != "i") {
    cout << "Incorrect usage. Please run: ./checkers <a/i>\n";
    return 0;
  }
  cout << "Welcome to checkers player!\n";

  if (option == "a") {
    //Automatically play checkers (uncomment to play)
    std::shared_ptr<GameState> checkers = std::make_shared<checkers::Checkers>(); // create game
    AutomaticPlayer automatic_checkers(checkers, 5); // create player
    automatic_checkers.play(); // play game
  } else {
    // Interactive tic tac toe (uncomment to play)
    std::shared_ptr<checkers::Checkers> checkers = std::make_shared<checkers::Checkers>(); // create game
    InteractivePlayer interactive_checkers_player(checkers, 5); // create player
    interactive_checkers_player.play(); // play game
  }

  return 0;
}
