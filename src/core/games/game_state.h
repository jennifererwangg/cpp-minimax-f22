#pragma once

#include <memory>
#include <string>
#include <vector>

namespace minimax {
namespace core {

using uint = unsigned int;

// Base class for games
class GameState {
public:

  explicit GameState();
  virtual ~GameState() {}

  /**
   * Used by the Minimax Solver
   */
  // return a vector of all possible next states
  virtual std::vector<std::shared_ptr<GameState>> getNextState();

  // return the heuristic value of the current state (bigger == more favorable for the player)
  virtual int evalHeuristics();

  // return true if the game has reached a terminal state, false otherwise
  virtual bool isDone();

  /**
   * Used by players
   */
  
  // print the current state
  virtual void printState();
  // get the winner of the game
  virtual void printWinner();
  // prompt for, take in, and process user input
  virtual void processUserInput();

protected:
private:
};

}  // namespace core
}  // namespace minimax