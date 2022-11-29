#include "core/games/tictactoe.h"

namespace minimax {
namespace core {

using uint = unsigned int;

Tictactoe::Tictactoe() {
  // initialize empty board
  board_ = std::vector<std::vector<BoardEntry>>(3, std::vector<BoardEntry>(3, EMPTY));
}

/**
 * GameState interface
 */
bool Tictactoe::isDone() {
  // check if there is a winner
  if (getMaxCount(X) == 3 || getMaxCount(O) == 3) {
    return true;
  }
  for (auto &row : board_) {
    for (auto &cell : row) {
      if (cell == EMPTY) {
        return false;
      }
    }
  }
  return true;
}

int Tictactoe::evalHeuristics() {
  int x_count = getMaxCount(X);
  int o_count = getMaxCount(O);
  int x_mark_count = getMarkCount(X);
  int o_mark_count = getMarkCount(O);
  if (x_mark_count <= o_mark_count) {
    // X plays next
    if (x_count == 3) return 1;
    if (o_count == 3) return -1;
  } else {
    // O plays next
    if (x_count == 3) return -1;
    if (o_count == 3) return 1;
  }
  return 0; // draw
}

void Tictactoe::printState() {
  for (auto &row : board_) {
    for (auto &cell : row) {
      std::cout << (char) cell << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

std::vector<std::shared_ptr<GameState>> Tictactoe::getNextState() {
  // Hardcode version for the 1st move (always put X in the center)
  if (getMarkCount(EMPTY) == 9) {
    auto next_state = std::make_shared<Tictactoe>();
    std::vector<std::vector<BoardEntry>> newBoard = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, X, EMPTY},
        {EMPTY, EMPTY, EMPTY}};
    next_state->setBoard(newBoard);
    return std::vector<std::shared_ptr<GameState>>{next_state};
  }
  
  if (getMarkCount(X) <= getMarkCount(O)) {
    // X's turn
    return putMark(X);
  } else {
    // O's turn
    return putMark(O);
  }
}

/**
 * Tictactoe game specific functions
 */
std::vector<std::shared_ptr<GameState>> Tictactoe::putMark(BoardEntry player) {
  std::vector<std::shared_ptr<GameState>> next_states;
  for (uint i = 0; i < board_.size(); ++i) {
    for (uint j = 0; j < board_[i].size(); ++j) {
      if (board_[i][j] == EMPTY) {
        std::shared_ptr<Tictactoe> next_state = std::make_shared<Tictactoe>();
        std::vector<std::vector<BoardEntry>> next_board(board_);
        next_board[i][j] = player;
        next_state->setBoard(next_board);
        next_states.push_back(next_state);
      }
    }
  }
  return next_states;
}

int Tictactoe::getMarkCount(BoardEntry player) {
  int count = 0;
  for (auto &row : board_) {
    for (auto &cell : row) {
      if (cell == player) {
        ++count;
      }
    }
  }
  return count;
}

int Tictactoe::getMaxCount(BoardEntry player) {
  int max_count = 0;
  // check rows & cols
  for (uint i = 0; i < 3; i++) {
    int row_cnt = 0;
    int col_cnt = 0;
    for (uint j = 0; j < 3; j++) {
      if (board_[i][j] == player)
        row_cnt++;
      if (board_[j][i] == player)
        col_cnt++;
    }
    max_count = std::max(max_count, row_cnt);
    max_count = std::max(max_count, col_cnt);
  }

  // check diagonals
  int diag_cnt = 0;
  int anti_diag_cnt = 0;
  for (uint i = 0; i < 3; i++) {
    if (board_[i][i] == player)
      diag_cnt++;
    if (board_[i][2 - i] == player)
      anti_diag_cnt++;
    max_count = std::max(max_count, diag_cnt);
    max_count = std::max(max_count, anti_diag_cnt);
  }
  return max_count;
}

bool Tictactoe::isValidMove(uint row, uint col) {
  if (row < 0 || row >= 3 || col < 0 || col >= 3) {
    return false;
  }
  return board_[row][col] == EMPTY;
}

void Tictactoe::makeMove(uint row, uint col) {
  if (isValidMove(row, col)) {
    board_[row][col] = X;
  } else {
    std::cout << "Invalid move\n";
  }
}

BoardEntry Tictactoe::getWinner() {
  if (getMaxCount(X) == 3) {
    std::cout << "X wins!\n";
    return X;
  }
  if (getMaxCount(O) == 3) {
    std::cout << "O wins!\n";
    return O;
  }
  std::cout << "Draw!\n";
  return EMPTY;
}

}  // namespace core
}  // namespace minimax