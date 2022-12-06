#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "core/games/game_state.h"

namespace minimax {
namespace core {
namespace checkers {

using Board = std::vector<std::vector<BoardEntry>>;

class Checkers : public GameState {  
public:

  explicit Checkers();

  // GameState BoardEntryerface
  bool isDone() override;
  int evalHeuristics() override;
  void printState() override;
  std::vector<std::shared_ptr<GameState>> getNextState() override;
  bool makeMove(int y1, int x1, int y2, int x2) override;
  BoardEntry getWinner() override;


  // getters & setters
  inline std::vector<std::vector<BoardEntry>> getBoard() {
    return board;
  }
  inline void setBoard(const std::vector<std::vector<BoardEntry>> &board_) {
    board = board_;
  }

  inline void switchTurn(bool is_white_turn) {
    white_turn = !is_white_turn;
  }

  // game-specific functions
  bool isValidMove(std::vector<int> initialPlace, std::vector<int> newPlace, std::vector<int> jump);
  std::vector<int> checkIfJump(std::vector<int> initialPlace, std::vector<int> newPlace);

  std::tuple<bool, std::shared_ptr<Checkers>> moveRightAndUp(int i, int j, BoardEntry piece1, BoardEntry piece2);
  std::tuple<bool, std::shared_ptr<Checkers>> moveLeftAndUp(int i, int j, BoardEntry piece1, BoardEntry piece2);
  std::tuple<bool, std::shared_ptr<Checkers>> moveRightAndDown(int i, int j, BoardEntry piece1, BoardEntry piece2);
  std::tuple<bool, std::shared_ptr<Checkers>> moveLeftAndDown(int i, int j, BoardEntry piece1, BoardEntry piece2);

  std::vector<std::vector<BoardEntry>> movePiece(std::vector<int> initialPlace, std::vector<int> newPlace, std::vector<int> jump);
  int countPieces(BoardEntry color, BoardEntry color_king);
  
protected:
  
private:
  std::vector<std::vector<BoardEntry>> board;
  bool white_turn = false;
  int white_next_states = 1;
  int black_next_states = 1;
};

}  // namespace checkers
}  // namespace core
}  // namespace minimax
