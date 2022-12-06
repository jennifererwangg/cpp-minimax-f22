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
    game_state_->processUserInput();
    game_state_->printState();
    if (game_state_->isDone()) {
      game_state_->printWinner();
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
      game_state_->printWinner();
      break;
    }
  }
}

}  // namespace core
}  // namespace minimax