#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "core/games/game_state.h"

namespace minimax {
namespace core {

enum TBoardEntry { X = 'X', O = 'O', EMPTY = '-' };

class Tictactoe : public GameState {  
public:

  explicit Tictactoe();

  // GameState interface
  bool isDone() override;
  int evalHeuristics() override;
  void printState() override;
  std::vector<std::shared_ptr<GameState>> getNextState() override;
  void printWinner() override;
  void processUserInput() override;

  // getters & setters
  inline std::vector<std::vector<TBoardEntry>> getBoard() {
    return board_;
  }
  inline void setBoard(const std::vector<std::vector<TBoardEntry>> &board) {
    board_ = board;
  }

  // game-specific functions
  // return the number of marks in a row/column/diagonal
  int getMaxCount(TBoardEntry player);
  // return the number of marks on the board for a given player (used to check which player plays next)
  int getMarkCount(TBoardEntry player);
  // place a mark on an empty cell of the board for a given player (ex: place X at position 1,1)
  std::vector<std::shared_ptr<GameState>> putMark(TBoardEntry player);
  // return if the given move is valid
  bool isValidMove(uint row, uint col);
  // place an X on the board
  bool makeMove(uint y1, uint x1);
  
protected:
  
private:
  std::vector<std::vector<TBoardEntry>> board_;
};

}  // namespace core
}  // namespace minimax