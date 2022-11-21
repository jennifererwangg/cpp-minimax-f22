#pragma once

#include <memory>
#include <string>
#include <vector>

namespace minimax {
namespace core {

// Base class for games
class GameState {
public:

  explicit GameState();
  virtual ~GameState() {}

  // return true if the game has reached a terminal state, false otherwise
  virtual bool isDone();

  // return the heuristic value of the current state (bigger == more favorable for the player)
  virtual int evalHeuristics();

  // print the current state
  virtual void printState();

  // return a vector of all possible next states
  virtual std::vector<std::shared_ptr<GameState>> getNextState();

protected:
private:
};

}  // namespace core
}  // namespace minimax