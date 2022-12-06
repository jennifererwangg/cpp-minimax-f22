#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "core/games/game_state.h"

namespace minimax {
namespace core {
namespace checkers {

enum CBoardEntry { BLACK = 'b', WHITE = 'w', BLACK_KING = 'B', WHITE_KING = 'W', EMPTY = '-' };
using Board = std::vector<std::vector<CBoardEntry>>;

class Checkers : public GameState {  
public:

  explicit Checkers();

  // GameState BoardEntryerface
  bool isDone() override;
  int evalHeuristics() override;
  void printState() override;
  std::vector<std::shared_ptr<GameState>> getNextState() override;
  void printWinner() override;
  bool makeMove(int y1, int x1, int y2, int x2) override;


  // getters & setters
  inline std::vector<std::vector<CBoardEntry>> getBoard() {
    return board;
  }
  inline void setBoard(const std::vector<std::vector<CBoardEntry>> &board_) {
    board = board_;
  }

  inline void switchTurn(bool is_white_turn) {
    white_turn = !is_white_turn;
  }

  // game-specific functions
  bool isValidMove(std::vector<int> initialPlace, std::vector<int> newPlace, std::vector<int> jump);
  std::vector<int> checkIfJump(std::vector<int> initialPlace, std::vector<int> newPlace);

  std::tuple<bool, std::shared_ptr<Checkers>> moveRightAndUp(int i, int j, CBoardEntry piece1, CBoardEntry piece2);
  std::tuple<bool, std::shared_ptr<Checkers>> moveLeftAndUp(int i, int j, CBoardEntry piece1, CBoardEntry piece2);
  std::tuple<bool, std::shared_ptr<Checkers>> moveRightAndDown(int i, int j, CBoardEntry piece1, CBoardEntry piece2);
  std::tuple<bool, std::shared_ptr<Checkers>> moveLeftAndDown(int i, int j, CBoardEntry piece1, CBoardEntry piece2);

  std::vector<std::vector<CBoardEntry>> movePiece(std::vector<int> initialPlace, std::vector<int> newPlace, std::vector<int> jump);
  int countPieces(CBoardEntry color, CBoardEntry color_king);
  
protected:
  
private:
  std::vector<std::vector<CBoardEntry>> board;
  bool white_turn = false;
  int white_next_states = 1;
  int black_next_states = 1;
};

}  // namespace checkers
}  // namespace core
}  // namespace minimax
