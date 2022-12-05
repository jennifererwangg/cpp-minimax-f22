#pragma once

#include <string>
#include "core/players/base_player.h"
#include "core/games/game_state.h"

namespace minimax {
namespace core {

class InteractiveCheckersPlayer : public BasePlayer {
public:

  explicit InteractiveCheckersPlayer(std::shared_ptr<GameState> game, int depth,
                             std::string player_name, std::string opponent_name);

  void play() override;

protected:
  std::shared_ptr<GameState> game_state_; // pointer to game state
  std::string player_name_; // name of player
  std::string opponent_name_; // name of opponent

private:
};

}  // namespace core
}  // namespace minimax