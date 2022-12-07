#pragma once

#include "core/games/game_state.h"
#include <iostream>
#include <utility>

namespace minimax {
namespace core {

/**
 * \brief The implementation of the minimax algorithm.
 * 
 * This class contains the acutal implementation of the minimax algorithm. It is game-agnostic, as it only 
 * calls functions on the GameState base class, which all of the implemented games rely on.
 */
class MinimaxSolver {
public:

  /**
   * \brief 
   */
  MinimaxSolver(int max_depth);

  // return the best state to play for the player
  std::shared_ptr<GameState> evaluate(std::shared_ptr<GameState> initial_gs, bool pruning = true);

  std::pair<std::shared_ptr<GameState>, int> minimize(std::shared_ptr<GameState> gs, int curr_depth, int alpha, int beta, bool pruning = true);

  std::pair<std::shared_ptr<GameState>, int> maximize(std::shared_ptr<GameState> gs,int curr_depth, int alpha, int beta, bool pruning = true);

private:
  int max_depth_ = 1;
};

}  // namespace core
}  // namespace minimax