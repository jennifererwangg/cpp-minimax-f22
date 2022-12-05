#pragma once

#include <memory>
#include <string>
#include <vector>

namespace minimax {
namespace core {

using uint = unsigned int;

enum BoardEntry { 
  EMPTY = '-', X = 'X', O = 'O', // TicTacToe
  BLOCKED = 'X', FREE = '-', P1 = '1', P2 = '2' // isolation
};

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

  // make a move on the board (used by the player)
  virtual bool makeMove(uint row, uint col);

  // get the winner of the game
  virtual BoardEntry getWinner();

  // set the current player (currently used only by isolation)
  // but has to be included here due to the interactive player
  // TODO: maybe remove this after some refactoring?
  virtual void setPlayer(int player);

protected:
private:
};

}  // namespace core
}  // namespace minimax