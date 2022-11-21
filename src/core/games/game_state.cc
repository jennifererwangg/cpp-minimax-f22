#include "core/games/game_state.h"
#include <iostream>

namespace minimax {
namespace core {

GameState::GameState(const std::string &name) :
  Node{name} {
  name_ = name.size() ? name : "GameState";
}


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

std::vector<GameState::Ptr> GameState::getNextState() {
  std::cout << "WARNING: base GameState() invoked.\n";
  return std::vector<GameState::Ptr>();
}

}  // namespace core
}  // namespace minimax