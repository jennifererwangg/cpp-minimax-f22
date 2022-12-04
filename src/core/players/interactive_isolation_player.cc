#include <iostream>
#include "core/solver/minimax_solver.h"
#include "core/players/interactive_isolation_player.h"

namespace minimax {
namespace core {

InteractiveIsolationPlayer::InteractiveIsolationPlayer(std::shared_ptr<Isolation> game, int depth)
    : BasePlayer(game, depth) {
  isolation_game_ = game;
}

void InteractiveIsolationPlayer::play() {
  MinimaxSolver minimax_solver(depth_);
  isolation_game_->printState();
  while (!isolation_game_->isDone()) {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Your turn (1)" << std::endl;
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
      if (isolation_game_->makeMove(x_int, y_int)) {
        break;
      }
      std::cout << "Invalid move. Try again." << std::endl;
    }
    isolation_game_->printState();
    if (isolation_game_->isDone()) {
      isolation_game_->getWinner();
      break;
    }
    // Computer Move
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "\n2's turn" << std::endl;
    std::shared_ptr<GameState> next_state = minimax_solver.evaluate(isolation_game_);
    isolation_game_ = std::dynamic_pointer_cast<Isolation>(next_state);
    isolation_game_->printState();
    isolation_game_->setPlayer(2);
    if (isolation_game_->isDone()) {
      isolation_game_->getWinner();
      break;
    }
  }
}

}  // namespace core
}  // namespace minimax