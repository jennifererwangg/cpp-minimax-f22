#pragma once

#include "core/players/base_player.h"
#include "core/games/isolation.h"

namespace minimax {
namespace core {

class InteractiveIsolationPlayer : public BasePlayer {
public:

  explicit InteractiveIsolationPlayer(std::shared_ptr<Isolation> game, int depth);

  void play() override;

protected:
  std::shared_ptr<Isolation> isolation_game_; // pointer to isolation
private:
};

}  // namespace core
}  // namespace minimax