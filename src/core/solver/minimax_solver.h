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
   * \brief Minimax solver constructor.
   * 
   * \param int max_depth
   * 
   * Creates a game-agnostic instance of the minimax solver that iterates until a certain max_depth.
   */
  MinimaxSolver(int max_depth);

  /**
   * \brief Returns the best move for a player.
   * 
   * \param std::shared_ptr<GameState> initial_gs
   * \param bool pruning
   * 
   * \return std::shared_ptr<GameState> bestState
   * 
   * Evaluate determines and then returns the best move for a player based on the traversal of the minimax tree.
   * It initiates the DFS traversal by calling maximize with the starting game state at depth 0, with max/min values
   * for the alpha beta pruning parameters.
   */
  std::shared_ptr<GameState> evaluate(std::shared_ptr<GameState> initial_gs, bool pruning = true);

  /**
   * \brief Generates child states for a given state and returns the child with the minimum utility.
   * 
   * \param std::shared_ptr<GameState> gs
   * \param int curr_depth
   * \param int alpha
   * \param int beta
   * \param bool pruning
   * 
   * \return std::pair<std::shared_ptr<GameState>, int> bestState, utility
   * 
   * Minimize returns the GameState along with its evaluated heuristic if curr_depth == max_depth, and 
   * otherwise it generates the child states from the current state, and returns the child state with
   * the minimum utility value. It uses alpha-beta pruning for optimization.
   */
  std::pair<std::shared_ptr<GameState>, int> minimize(std::shared_ptr<GameState> gs, int curr_depth, int alpha, int beta, bool pruning = true);

  /**
   * \brief Generates child states for a given state and returns the child with the maximum utility.
   * 
   * \param std::shared_ptr<GameState> gs
   * \param int curr_depth
   * \param int alpha
   * \param int beta
   * \param bool pruning
   * 
   * \return std::pair<std::shared_ptr<GameState>, int> bestState, utility
   * 
   * Maximize returns the GameState along with its evaluated heuristic if curr_depth == max_depth, and 
   * otherwise it generates the child states from the current state, and returns the child state with
   * the maximize utility value. It uses alpha-beta pruning for optimization.
   */
  std::pair<std::shared_ptr<GameState>, int> maximize(std::shared_ptr<GameState> gs,int curr_depth, int alpha, int beta, bool pruning = true);

private:
  int max_depth_ = 1;
};

}  // namespace core
}  // namespace minimax