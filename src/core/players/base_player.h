#pragma once

#include <memory>
#include <string>
#include <vector>
#include "core/games/game_state.h"

namespace minimax {
namespace core {

/**
 * \brief Represents a game player.
 * 
 * This class is used to represent a game player. It holds information about which 
 * game is being played and what the desired depth of the minimax tree is.
 */
class BasePlayer {
public:

  /**
   * \brief Constructor for the BasePlayer
   * 
   * \param std::shared_ptr<GameState> game
   * \param int depth
   */
  explicit BasePlayer(std::shared_ptr<GameState> game, int depth);

  /**
   * \brief Plays the game.
   */
  virtual void play();

protected:
  std::shared_ptr<GameState> game_; // pointer to game
  int depth_;                       // max depth of minimax search

private:
};

}  // namespace core
}  // namespace minimax