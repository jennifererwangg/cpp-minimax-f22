#pragma once

#include <memory>
#include <string>
#include <vector>
#include "game_state.h"

namespace minimax {
namespace core {

enum Direction {NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST};

// using Board = std::vector<std::vector<BoardEntry>>;

class Isolation : public GameState {  
public:

  explicit Isolation(const int player  = 1);

  // GameState interface
  bool isDone() override;
  int evalHeuristics() override;
  void printState() override;
  std::vector<std::shared_ptr<GameState>> getNextState() override;
  void processUserInput() override;
  BoardEntry getWinner() override;
  void setPlayer(int player) override;
  bool makeMove(uint y, uint x);

  // getters & setters
  inline std::vector<std::vector<BoardEntry>> getBoard() {
    return board_;
  }
  inline void setBoard(const std::vector<std::vector<BoardEntry>> &board) {
    board_ = board;
  }
  
protected:
  
private:
  std::vector<std::vector<BoardEntry>> board_;
  BoardEntry player_;
  bool hasAvailableMoves(uint row, uint col);
  std::vector<std::shared_ptr<GameState>> moveInDirection(uint row, uint col, Direction dir);
  std::shared_ptr<GameState> randomFirstMove();
  std::pair<uint, uint> getCurrPos(BoardEntry p);
  bool isValidMove(uint row, uint col);
};

}  // namespace core
}  // namespace minimax