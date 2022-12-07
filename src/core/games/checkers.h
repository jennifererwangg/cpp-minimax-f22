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


/**
 * \brief The checkers game.
 * 
 * This class implements a checkers game with an 8x8 board.
 */
class Checkers : public GameState {  
public:

  explicit Checkers();

  /**
   * \brief Checks that both colors have pieces left that can move.
   * 
   * \return true if the game is over, false if not.
   */
  bool isDone() override;

  /**
   * \brief Finds utility of board.
   * 
   * Calculates utility of board state by taking the difference in the number of pieces between the two colors.
   * 
   * \return the utility of the board for the current player.
   */
  int evalHeuristics() override;

  /**
   * \brief Prints checkers board.
   */
  void printState() override;

  /**
   * \brief Generate all possible checkers moves.
   * 
   * Attempts to move each piece in all possible directions. Also attempts to jump pieces when possible.
   * 
   * \return a list of all of the possible next states for the game.
   */
  std::vector<std::shared_ptr<GameState>> getNextState() override;

  /**
   * \brief Determine winner of checkers game.
   * 
   * Checks if either color has lost all their pieces, and then checks if any player has no moves left.
   */
  void printWinner() override;

  /**
   * \brief Determine winner of checkers game.
   * 
   * Checks if either color has lost all their pieces, and then checks if any player has no moves left.
   */
  void processUserInput() override;


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
  bool makeMove(int y1, int x1, int y2, int x2);
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
