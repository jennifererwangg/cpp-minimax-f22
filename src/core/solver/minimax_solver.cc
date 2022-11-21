#include "core/solver/minimax_solver.h"

namespace minimax {
namespace core {

MinimaxSolver::MinimaxSolver(int max_depth)
  : max_depth_{max_depth} {}

std::shared_ptr<GameState> MinimaxSolver::evaluate(std::shared_ptr<GameState> initial_gs) {
  return maximize(initial_gs, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()).first;
}


std::pair<std::shared_ptr<GameState>, int> MinimaxSolver::maximize(std::shared_ptr<GameState> gs, int curr_depth, int alpha, int beta) {
  if (curr_depth == max_depth_ || gs->isDone()) {
    int utility = gs->evalHeuristics();
    return std::pair<std::shared_ptr<GameState>, int>(gs, utility);
  }

  int max_utility = std::numeric_limits<int>::min();
  std::shared_ptr<GameState> max_state = nullptr;

  for (std::shared_ptr<GameState> next_state : gs->getNextState()) {
    std::pair<std::shared_ptr<GameState>, int> curr = minimize(next_state, curr_depth + 1, alpha, beta);
    // std::shared_ptr<GameState> curr_state = curr.first;
    int curr_utility = curr.second;

    if (curr_utility > max_utility) {
      max_utility = curr_utility;
      max_state = next_state;
    }

    if (max_utility >= beta) {
      return std::pair<std::shared_ptr<GameState>, int>(max_state, max_utility);
    }

    alpha = std::max(alpha, max_utility);
  }
  return std::pair<std::shared_ptr<GameState>, int>(max_state, max_utility);
}


std::pair<std::shared_ptr<GameState>, int>  MinimaxSolver::minimize(std::shared_ptr<GameState> gs, int curr_depth, int alpha, int beta) {
  if (curr_depth == max_depth_ || gs->isDone()) {
    int utility = gs->evalHeuristics();
    return std::pair<std::shared_ptr<GameState>, int>(gs, utility);
  }

  int min_utility = std::numeric_limits<int>::max();
  std::shared_ptr<GameState> min_state = nullptr;

  for (std::shared_ptr<GameState> next_state : gs->getNextState()) {
    std::pair<std::shared_ptr<GameState>, int> curr = maximize(next_state, curr_depth + 1, alpha, beta);
    // std::shared_ptr<GameState> curr_state = curr.first;
    int curr_utility = curr.second;

    if (curr_utility < min_utility) {
      min_utility = curr_utility;
      min_state = next_state;
    }

    if (min_utility <= alpha) {
      return std::pair<std::shared_ptr<GameState>, int>(min_state, min_utility);
    }

    beta = std::min(beta, min_utility);
  }
  return std::pair<std::shared_ptr<GameState>, int>(min_state, min_utility);
}

}  // namespace core
}  // namespace minimax