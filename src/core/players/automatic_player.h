#pragma once

#include "core/players/base_player.h"

namespace minimax {
namespace core {

/**
 * \brief Represents an automatic player.
 * 
 * This class is used to represent an automatic game player, which pits two
 * AI players against each other.
 */
class AutomaticPlayer : public BasePlayer {
public:

  explicit AutomaticPlayer(std::shared_ptr<GameState> game, int depth);

  void play() override;

protected:
private:
};

}  // namespace core
}  // namespace minimax