#include <iostream>
#include <string>
#include "core/games/game_state.h"
#include "core/games/tictactoe.h"
#include "core/games/checkers.h"
#include "core/solver/minimax_solver.h"
#include "core/players/automatic_player.h"
#include "core/players/interactive_player.h"
#include "core/games/tictactoe.h"

using namespace std;
using namespace minimax::core;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Incorrect usage. Please run: ./tictactoe <a/i>\n";
    return 0;
  }

  string option = argv[1];
  if (option != "a" && option != "i") {
    cout << "Incorrect usage. Please run: ./tictactoe <a/i>\n";
    return 0;
  }

  cout << "Welcome to tic tac toe player!\n";

  if (option == "a") {
    // Automatically play tic tac toe (uncomment to play)
    std::shared_ptr<GameState> tictactoe = std::make_shared<Tictactoe>(); // create game
    AutomaticPlayer tic_tac_toe_player(tictactoe, 5); // create player
    tic_tac_toe_player.play(); // play game
  } else {
    // Interactive tic tac toe (uncomment to play)
    std::shared_ptr<Tictactoe> tictactoe = std::make_shared<Tictactoe>(); // create game
    InteractivePlayer interactive_tic_tac_toe_player(tictactoe, 5, string{X}, string{O}); // create player
    interactive_tic_tac_toe_player.play(); // play game
  }

  return 0;
}