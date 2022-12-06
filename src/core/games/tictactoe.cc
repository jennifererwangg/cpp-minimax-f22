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

const int win_idx[8][3] = {
  { 0, 1, 2 },  // row 0
  { 3, 4, 5 },  // row 1
  { 6, 7, 8 },  // row 2
  { 0, 3, 6 },  // col 0
  { 1, 4, 7 },  // col 1
  { 2, 5, 8 },  // col 2
  { 0, 4, 8 },  // diag 0
  { 2, 4, 6 }   // diag 1
};
const int weights[4][4] = {
  {     0,   -10,  -100, -1000 },
  {    10,     0,     0,     0 },
  {   100,     0,     0,     0 },
  {  1000,     0,     0,     0 }
};

int Tictactoe::evalHeuristics() {
  int x_mark_count = getMarkCount(X);
  int o_mark_count = getMarkCount(O);
  char player = x_mark_count == o_mark_count ? X : O;
  char opponent = x_mark_count <= o_mark_count ? O : X;
  int score = 0;
  
  for (uint i = 0; i < 8; i++)  {
    int player_score = 0;
    int other_score = 0;
    for (uint j = 0; j < 3; j++)  {
      int pos = win_idx[i][j];
      unsigned long r = static_cast<unsigned long>(pos / 3);
      unsigned long c = static_cast<unsigned long>(pos % 3);
      char piece = board_[r][c];
      if (piece == player)
        player_score++;
      else if (piece == opponent)
        other_score++;
    }
    score += weights[player_score][other_score];
  }
  return score;
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
  if (getMarkCount(X) <= getMarkCount(O)) {
    // X's turn
    return putMark(X);
  } else {
    // O's turn
    return putMark(O);
  }
}

bool Tictactoe::makeMove(int row, int col, int /*y2*/, int /*x2*/) {
  uint r = static_cast<uint>(row), c = static_cast<uint>(col);
  if (isValidMove(r, c)) {
    board_[r][c] = X;
    return true;
  } else {
    // std::cout << "Invalid move\n";
    return false;
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

void Tictactoe::setPlayer(int /*player*/) { /* do nothing */}

/**
 * Tictactoe game specific functions
 */
bool Tictactoe::isValidMove(uint row, uint col) {
  if (row < 0 || row >= 3 || col < 0 || col >= 3) {
    return false;
  }
  return board_[row][col] == EMPTY;
}

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

}  // namespace core
}  // namespace minimax