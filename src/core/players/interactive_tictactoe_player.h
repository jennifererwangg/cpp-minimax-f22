#pragma once

#include "core/players/base_player.h"
#include "core/games/tictactoe.h"

namespace minimax {
namespace core {

class InteractiveTictactoePlayer : public BasePlayer {
public:

  explicit InteractiveTictactoePlayer(std::shared_ptr<Tictactoe> game, int depth);

  void play() override;

protected:
  std::shared_ptr<Tictactoe> tictactoe_game_; // pointer to tictactoe
private:
};

}  // namespace core
}  // namespace minimax