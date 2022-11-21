#include "core/solver/minimax_solver.h"

namespace minimax {
namespace core {

MinimaxSolver::MinimaxSolver(int max_depth)
  : max_depth_{max_depth} {}

GameState::Ptr MinimaxSolver::evaluate(GameState::Ptr initial_gs) {
  return maximize(initial_gs, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()).first;
}


std::pair<GameState::Ptr, int> MinimaxSolver::maximize(GameState::Ptr gs, int curr_depth, int alpha, int beta) {
  if (curr_depth == max_depth_ || gs->isDone()) {
    int utility = gs->evalHeuristics();
    return std::pair<GameState::Ptr, int>(gs, utility);
  }

  int max_utility = std::numeric_limits<int>::min();
  GameState::Ptr max_state = nullptr;

  for (GameState::Ptr next_state : gs->getNextState()) {
    std::pair<GameState::Ptr, int> curr = minimize(next_state, curr_depth + 1, alpha, beta);
    // GameState::Ptr curr_state = curr.first;
    int curr_utility = curr.second;

    if (curr_utility > max_utility) {
      max_utility = curr_utility;
      max_state = next_state;
    }

    if (max_utility >= beta) {
      return std::pair<GameState::Ptr, int>(max_state, max_utility);
    }

    alpha = std::max(alpha, max_utility);
  }
  return std::pair<GameState::Ptr, int>(max_state, max_utility);
}


std::pair<GameState::Ptr, int>  MinimaxSolver::minimize(GameState::Ptr gs, int curr_depth, int alpha, int beta) {
  if (curr_depth == max_depth_ || gs->isDone()) {
    int utility = gs->evalHeuristics();
    return std::pair<GameState::Ptr, int>(gs, utility);
  }

  int min_utility = std::numeric_limits<int>::max();
  GameState::Ptr min_state = nullptr;

  for (GameState::Ptr next_state : gs->getNextState()) {
    std::pair<GameState::Ptr, int> curr = maximize(next_state, curr_depth + 1, alpha, beta);
    // GameState::Ptr curr_state = curr.first;
    int curr_utility = curr.second;

    if (curr_utility < min_utility) {
      min_utility = curr_utility;
      min_state = next_state;
    }

    if (min_utility <= alpha) {
      return std::pair<GameState::Ptr, int>(min_state, min_utility);
    }

    beta = std::min(beta, min_utility);
  }
  return std::pair<GameState::Ptr, int>(min_state, min_utility);
}

}  // namespace core
}  // namespace minimax