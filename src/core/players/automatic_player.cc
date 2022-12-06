#include "core/solver/minimax_solver.h"
#include "core/players/automatic_player.h"

namespace minimax {
namespace core {

AutomaticPlayer::AutomaticPlayer(std::shared_ptr<GameState> game, int depth)
    : BasePlayer(game, depth) {}

void AutomaticPlayer::play() {
  MinimaxSolver minimax_solver(depth_);
  for (;;) {
    std::shared_ptr<GameState> next_best_state = minimax_solver.evaluate(game_);
    next_best_state->printState();
    game_ = next_best_state;
    if (game_->isDone()) {
      break;
    }
  }
}

}  // namespace core
}  // namespace minimax