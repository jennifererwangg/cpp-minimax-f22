#pragma once

#include <memory>
#include <string>
#include <vector>

namespace minimax {
namespace core {

enum BoardEntry { EMPTY = '-', X = 'X', O = 'O' };

// using Board = std::vector<std::vector<BoardEntry>>;

class Tictactoe : public GameState {  
public:

  explicit Tictactoe();

  // GameState interface
  bool isDone() override;
  int evalHeuristics() override;
  void printState() override;
  std::vector<std::shared_ptr<GameState>> getNextState() override;

  // getters & setters
  inline std::vector<std::vector<BoardEntry>> getBoard() {
    return board_;
  }
  inline void setBoard(const std::vector<std::vector<BoardEntry>> &board) {
    board_ = board;
  }

  // game-specific functions
  // return the number of marks in a row/column/diagonal
  int getMaxCount(BoardEntry player);
  // return the number of marks on the board for a given player (used to check which player plays next)
  int getMarkCount(BoardEntry player);
  // place a mark on an empty cell of the board for a given player (ex: place X at position 1,1)
  std::vector<std::shared_ptr<GameState>> putMark(BoardEntry player);
  
protected:
  
private:
  std::vector<std::vector<BoardEntry>> board_;
};

}  // namespace core
}  // namespace minimax