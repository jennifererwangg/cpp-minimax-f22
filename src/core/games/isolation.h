#pragma once

#include <memory>
#include <string>
#include <vector>
#include "game_state.h"

namespace minimax {
namespace core {

enum IBoardEntry { BLOCKED = 'X', FREE = '-', P1 = '1', P2 = '2' };
enum Direction {NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST};

// using Board = std::vector<std::vector<IBoardEntry>>;

class Isolation : public GameState {  
public:

  explicit Isolation(const int player  = 1);

  // GameState interface
  bool isDone() override;
  int evalHeuristics() override;
  void printState() override;
  std::vector<std::shared_ptr<GameState>> getNextState() override;

  // getters & setters
  inline std::vector<std::vector<IBoardEntry>> getBoard() {
    return board_;
  }
  inline void setBoard(const std::vector<std::vector<IBoardEntry>> &board) {
    board_ = board;
  }
  inline void setPlayer(const IBoardEntry p) {
    player_ = p;
  }
  
protected:
  
private:
  std::vector<std::vector<IBoardEntry>> board_;
  IBoardEntry player_;
  bool hasAvailableMoves(uint row, uint col);
  std::vector<std::shared_ptr<GameState>> moveInDirection(uint row, uint col, Direction dir);
  std::shared_ptr<GameState> randomFirstMove();
};

}  // namespace core
}  // namespace minimax