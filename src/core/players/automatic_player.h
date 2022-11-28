#pragma once

#include "core/players/base_player.h"

namespace minimax {
namespace core {

class AutomaticPlayer : public BasePlayer {
public:

  explicit AutomaticPlayer(std::shared_ptr<GameState> game, int depth);

  void play() override;

protected:
private:
};

}  // namespace core
}  // namespace minimax