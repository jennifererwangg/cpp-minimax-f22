#pragma once

#include <memory>
#include <string>
#include <vector>
#include "core/games/game_state.h"

namespace minimax {
namespace core {

// Base class for players
class BasePlayer {
public:

  explicit BasePlayer(std::shared_ptr<GameState> game, int depth);

  virtual void play();

protected:
  std::shared_ptr<GameState> game_; // pointer to game
  int depth_;                       // max depth of minimax search

private:
};

}  // namespace core
}  // namespace minimax