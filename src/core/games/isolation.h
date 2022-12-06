#pragma once

#include <memory>
#include <string>
#include <vector>
#include "game_state.h"

namespace minimax {
namespace core {

enum IBoardEntry { BLOCKED = 'X', FREE = '-', P1 = '1', P2 = '2' };
enum Direction {NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST};

class Isolation : public GameState {  
public:

  explicit Isolation(const int player  = 1);

  // GameState interface
  bool isDone() override;
  int evalHeuristics() override;
  void printState() override;
  std::vector<std::shared_ptr<GameState>> getNextState() override;
  bool makeMove(uint row, uint col) override;
  void printWinner() override;
  void setPlayer(int player) override;

  // getters & setters
  inline std::vector<std::vector<IBoardEntry>> getBoard() {
    return board_;
  }
  inline void setBoard(const std::vector<std::vector<IBoardEntry>> &board) {
    board_ = board;
  }
  
protected:
  
private:
  std::vector<std::vector<IBoardEntry>> board_;
  IBoardEntry player_;
  bool hasAvailableMoves(uint row, uint col);
  std::vector<std::shared_ptr<GameState>> moveInDirection(uint row, uint col, Direction dir);
  std::shared_ptr<GameState> randomFirstMove();
  std::pair<uint, uint> getCurrPos(IBoardEntry p);
  bool isValidMove(uint row, uint col);
};

}  // namespace core
}  // namespace minimax