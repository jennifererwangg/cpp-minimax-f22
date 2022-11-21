#pragma once

#include "core/games/game_state.h"
#include <iostream>
#include <utility>

namespace minimax {
namespace core {

class MinimaxSolver {
public:

  MinimaxSolver(int max_depth);

  // return the best state to play for the player
  std::shared_ptr<GameState> evaluate(std::shared_ptr<GameState> initial_gs);

  std::pair<std::shared_ptr<GameState>, int> minimize(std::shared_ptr<GameState> gs, int curr_depth, int alpha, int beta);

  std::pair<std::shared_ptr<GameState>, int> maximize(std::shared_ptr<GameState> gs,int curr_depth, int alpha, int beta);

private:
  int max_depth_ = 1;
};

}  // namespace core
}  // namespace minimax