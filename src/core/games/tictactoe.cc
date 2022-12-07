#include "core/games/tictactoe.h"

namespace minimax {
namespace core {

using uint = unsigned int;

Tictactoe::Tictactoe() {
  // initialize empty board
  board_ = std::vector<std::vector<TBoardEntry>>(3, std::vector<TBoardEntry>(3, EMPTY));
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

void Tictactoe::processUserInput() {
  std::cout << "Your turn (X)" << std::endl;
  std::string x = "", y = "";
  uint x_int = 10, y_int = 10;
  while (true) {
    std::cout << "Enter the row number (0 to 2): ";
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the column number (0 to 2): ";
    std::cin >> y;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // if x and y are not integers, continue
    if (x.find_first_not_of("0123456789") != std::string::npos ||
        y.find_first_not_of("0123456789") != std::string::npos) {
      std::cout << "Invalid input. Please enter positive integers." << std::endl;
      continue;
    }
    x_int = static_cast<uint>(std::stoi(x));
    y_int = static_cast<uint>(std::stoi(y));
    if (makeMove(x_int, y_int)) {
      break;
    }
    std::cout << "Invalid move. Try again." << std::endl;
  }
}

void Tictactoe::printWinner() {
  if (getMaxCount(X) == 3) {
    std::cout << "X wins!\n";
  } else if (getMaxCount(O) == 3) {
    std::cout << "O wins!\n";
  } else {
    std::cout << "Draw!\n";
  }
}

/**
 * Tictactoe game specific functions
 */
bool Tictactoe::makeMove(uint r, uint c) {
  if (isValidMove(r, c)) {
    board_[r][c] = X;
    return true;
  } else {
    // std::cout << "Invalid move\n";
    return false;
  }
}

bool Tictactoe::isValidMove(uint row, uint col) {
  if (row < 0 || row >= 3 || col < 0 || col >= 3) {
    return false;
  }
  return board_[row][col] == EMPTY;
}

std::vector<std::shared_ptr<GameState>> Tictactoe::putMark(TBoardEntry player) {
  std::vector<std::shared_ptr<GameState>> next_states;
  for (uint i = 0; i < board_.size(); ++i) {
    for (uint j = 0; j < board_[i].size(); ++j) {
      if (board_[i][j] == EMPTY) {
        std::shared_ptr<Tictactoe> next_state = std::make_shared<Tictactoe>();
        std::vector<std::vector<TBoardEntry>> next_board(board_);
        next_board[i][j] = player;
        next_state->setBoard(next_board);
        next_states.push_back(next_state);
      }
    }
  }
  return next_states;
}

int Tictactoe::getMarkCount(TBoardEntry player) {
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

int Tictactoe::getMaxCount(TBoardEntry player) {
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