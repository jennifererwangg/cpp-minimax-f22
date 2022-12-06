#include <iostream>
#include "core/solver/minimax_solver.h"
#include "core/players/interactive_player.h"
#include "core/players/checkers_player.h"

namespace minimax {
namespace core {

InteractiveCheckersPlayer::InteractiveCheckersPlayer(std::shared_ptr<GameState> game, int depth,
                                     std::string player_name, std::string opponent_name)
    : BasePlayer(game, depth), game_state_(game), player_name_(player_name),
      opponent_name_(opponent_name) {}

void InteractiveCheckersPlayer::play() {
  MinimaxSolver minimax_solver(depth_);
  game_state_->printState();
  while (!game_state_->isDone()) {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Your turn (" << player_name_ << ")" << std::endl;
    std::string x_start = "", y_start = "";
    std::string x_end = "", y_end = "";
    int x_start_int = 10, y_start_int = 10, x_end_int = 10, y_end_int = 10;
    while (true) {
      // initial place
      std::cout << "Enter x (0 to 7): ";
      std::cin >> x_start;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter y (0 to 7): ";
      std::cin >> y_start;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // if x and y are not integers, continue
      if (x_start.find_first_not_of("0123456789") != std::string::npos ||
          y_start.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "Invalid input. Please enter positive integers." << std::endl;
        continue;
      }

      x_start_int = std::stoi(x_start);
      y_start_int = std::stoi(y_start);
      
      // new place
      std::cout << "Enter x (0 to 7): ";
      std::cin >> x_end;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter y (0 to 7): ";
      std::cin >> y_end;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // if x and y are not integers, continue
      if (x_end.find_first_not_of("0123456789") != std::string::npos ||
          y_end.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "Invalid input. Please enter positive integers." << std::endl;
        continue;
      }
      x_end_int = std::stoi(x_end);
      y_end_int = std::stoi(y_end);

      if (game_state_->makeMove(y_start_int, x_start_int, y_end_int, x_end_int)) {
        break;
      }
      std::cout << "Invalid move. Try again." << std::endl;
    }
    game_state_->printState();
    if (game_state_->isDone()) {
      game_state_->getWinner();
      break;
    }
    // Computer Move
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "\n" << opponent_name_ << "'s turn" << std::endl;
    std::shared_ptr<GameState> next_state = minimax_solver.evaluate(game_state_);
    game_state_ = next_state;
    game_state_->printState();
    if (game_state_->isDone()) {
      game_state_->getWinner();
      break;
    }
  }
}

}  // namespace core
}  // namespace minimax