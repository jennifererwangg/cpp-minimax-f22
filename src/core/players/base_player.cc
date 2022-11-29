#include <iostream>
#include "core/players/base_player.h"

namespace minimax {
namespace core {

BasePlayer::BasePlayer(std::shared_ptr<GameState> game, int depth)
    : game_(game), depth_(depth) {}

void BasePlayer::play() {
  std::cout << "WARNING: BasePlayer::play() called" << std::endl;
}

}  // namespace core
}  // namespace minimax