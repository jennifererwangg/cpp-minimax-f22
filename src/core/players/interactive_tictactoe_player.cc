#include <iostream>
#include "core/solver/minimax_solver.h"
#include "core/players/interactive_tictactoe_player.h"

namespace minimax {
namespace core {

InteractiveTictactoePlayer::InteractiveTictactoePlayer(std::shared_ptr<Tictactoe> game, int depth)
    : BasePlayer(game, depth) {
  tictactoe_game_ = game;
}

void InteractiveTictactoePlayer::play() {
  MinimaxSolver minimax_solver(depth_);
  tictactoe_game_->printState();
  while (!tictactoe_game_->isDone()) {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Your turn (X)" << std::endl;
    std::string x = "", y = "";
    uint x_int = 10, y_int = 10;
    while (true) {
      std::cout << "Enter x (0 to 2): ";
      std::cin >> x;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter y (0 to 2): ";
      std::cin >> y;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // if x and y are not integers, continue
      if (x.find_first_not_of("0123456789") != std::string::npos ||
          y.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "Invalid input. Please enter positive integers." << std::endl;
        continue;
      }
      x_int = static_cast<uint>(std::stoi(x));
      y_int = static_cast<uint>(std::stoi(y));
      if (tictactoe_game_->isValidMove(x_int, y_int)) {
        break;
      }
      std::cout << "Invalid move. Try again." << std::endl;
    }
    // make the move as indicated by player
    tictactoe_game_->makeMove(x_int, y_int);
    tictactoe_game_->printState();
    if (tictactoe_game_->isDone()) {
      tictactoe_game_->getWinner();
      break;
    }
    // O's move (computer)
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "\nO's turn" << std::endl;
    std::shared_ptr<GameState> next_state = minimax_solver.evaluate(tictactoe_game_);
    tictactoe_game_ = std::dynamic_pointer_cast<Tictactoe>(next_state);
    tictactoe_game_->printState();
    if (tictactoe_game_->isDone()) {
      tictactoe_game_->getWinner();
      break;
    }
  }
}

}  // namespace core
}  // namespace minimax