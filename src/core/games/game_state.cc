#include "core/games/game_state.h"
#include <iostream>

namespace minimax {
namespace core {

GameState::GameState() {}

bool GameState::isDone() {
  std::cout << "WARNING: base GameState() invoked.\n";
  return true;
}

int GameState::evalHeuristics() {
  std::cout << "WARNING: base GameState() invoked.\n";
  return 0;
}

void GameState::printState() {
  std::cout << "WARNING: base GameState() invoked.\n";
}

std::vector<std::shared_ptr<GameState>> GameState::getNextState() {
  std::cout << "WARNING: base GameState() invoked.\n";
  return std::vector<std::shared_ptr<GameState>>();
}

void GameState::printWinner() {
  std::cout << "WARNING: base GameState() invoked.\n";
}

void GameState::setPlayer(int /*player*/) {
  std::cout << "WARNING: base GameState() setPlayer invoked.\n";
}

void GameState::processUserInput() {
  std::cout << "WARNING: base GameState() processUserInput invoked.\n";
}

}  // namespace core
}  // namespace minimax