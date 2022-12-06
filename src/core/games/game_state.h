#pragma once

#include <memory>
#include <string>
#include <vector>

namespace minimax {
namespace core {

using uint = unsigned int;

enum BoardEntry { 
  X = 'X', O = 'O', // TicTacToe
  BLOCKED = 'X', FREE = '-', P1 = '1', P2 = '2', // isolation
  BLACK = 'b', WHITE = 'w', BLACK_KING = 'B', WHITE_KING = 'W', // checkers
  EMPTY = '-' // for tic tac toe and checkers
};

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
   * 
   */
  
  // print the current state
  virtual void printState();

  // make a move on the board (used by the player)
  // TODO: don't like that there are 2 different args here, will have to change
  virtual bool makeMove(uint row, uint col);
  virtual bool makeMove(std::vector<int> initialPlace, std::vector<int> newPlace);

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