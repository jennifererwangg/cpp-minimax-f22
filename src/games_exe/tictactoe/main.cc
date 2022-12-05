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

int main(int /*argc*/, char **/*argv*/) {
  cout << "Welcome to tic tac toe player!\n";

  // Automatically play tic tac toe (uncomment to play)
  // std::shared_ptr<GameState> tictactoe = std::make_shared<Tictactoe>(); // create game
  // AutomaticPlayer tic_tac_toe_player(tictactoe, 5); // create player
  // tic_tac_toe_player.play(); // play game

  // Interactive tic tac toe (uncomment to play)
  std::shared_ptr<Tictactoe> tictactoe = std::make_shared<Tictactoe>(); // create game
  InteractivePlayer interactive_tic_tac_toe_player(tictactoe, 5, string{X}, string{O}); // create player
  interactive_tic_tac_toe_player.play(); // play game

  return 0;
}

void automaticTicTacToePlayer() {
  // Initialize tic tac toe game 
  std::shared_ptr<GameState> tictactoe = std::make_shared<Tictactoe>();

  for (;;) {
    MinimaxSolver solver(10);
    std::shared_ptr<GameState> next_best_state = solver.evaluate(tictactoe);
    next_best_state->printState();
    tictactoe = next_best_state;
    if (tictactoe->isDone()) {
      break;
    }
  }
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