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
  GameState::Ptr evaluate(GameState::Ptr initial_gs);

  std::pair<GameState::Ptr, int> minimize(GameState::Ptr gs, int curr_depth, int alpha, int beta);

  std::pair<GameState::Ptr, int> maximize(GameState::Ptr gs,int curr_depth, int alpha, int beta);

private:
  int max_depth_ = 1;
};

}  // namespace core
}  // namespace minimax