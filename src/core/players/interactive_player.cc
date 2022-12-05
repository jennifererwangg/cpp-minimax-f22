#include <iostream>
#include "core/solver/minimax_solver.h"
#include "core/players/interactive_player.h"

namespace minimax {
namespace core {

InteractivePlayer::InteractivePlayer(std::shared_ptr<GameState> game, int depth,
                                     std::string player_name, std::string opponent_name)
    : BasePlayer(game, depth), game_state_(game), player_name_(player_name),
      opponent_name_(opponent_name) {}

void InteractivePlayer::play() {
  MinimaxSolver minimax_solver(depth_);
  game_state_->printState();
  while (!game_state_->isDone()) {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Your turn (" << player_name_ << ")" << std::endl;
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
      if (game_state_->makeMove(x_int, y_int)) {
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
    game_state_->setPlayer(2);
    if (game_state_->isDone()) {
      game_state_->getWinner();
      break;
    }
  }
}

}  // namespace core
}  // namespace minimax