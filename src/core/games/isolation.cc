#include <iostream>
#include <random>
#include "core/games/isolation.h"

namespace minimax {
namespace core {

using uint = unsigned int;

Isolation::Isolation(int player) {
  // initialize empty board
  board_ = std::vector<std::vector<IBoardEntry>>(3, std::vector<IBoardEntry>(3, FREE));
  if (player == 1) {
    player_ = P1;
  } else {
    player_ = P2;
  }
}

/**
 * GameState interface
 */
bool Isolation::isDone() {
  for (uint i = 0; i < board_.size(); ++i) {
    for (uint j = 0; j < board_[i].size(); ++j) {
      if (board_[i][j] == P1 || board_[i][j] == P2) {
        auto canMove = Isolation::hasAvailableMoves(i, j);
        if (!canMove) {
          return true;
        }
      }
    }
  }
  return false;
}

int Isolation::evalHeuristics() {
  std::vector<std::shared_ptr<GameState>> possibleNextStates = getNextState();
  int utility = (int)possibleNextStates.size();
  return -1*utility;
}

void Isolation::printState() {
  for (auto &row : board_) {
    for (auto &cell : row) {
      std::cout << (char) cell << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

std::vector<std::shared_ptr<GameState>> Isolation::getNextState() {
  std::vector<std::shared_ptr<GameState>> next_states;
  std::vector<Direction> all_directions = {NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST};
  std::pair<uint, uint> pos = getCurrPos(player_);
  uint row = pos.first, col = pos.second;
 if (row == board_.size()) {
    next_states.push_back(Isolation::randomFirstMove());
    return next_states;
 }
 for (auto dir : all_directions) {
     auto dir_states = moveInDirection(row, col, dir);
     next_states.insert(next_states.end(), dir_states.begin(), dir_states.end());
 }
  return next_states;
}

bool Isolation::makeMove(uint row, uint col) {
  if (!isValidMove(row, col)) {
    return false;
  }
  std::pair<uint, uint> pos = getCurrPos(P1);
  uint curr_row = pos.first, curr_col = pos.second;
  if (curr_row == static_cast<uint>(board_.size())) {
    board_[row][col] = P1;
    return true;
  }
  std::vector<std::vector<IBoardEntry>> next_board(board_);
  if (curr_row == row) {
    uint begin = (curr_col < col) ? curr_col : col;
    uint end = (curr_col < col) ? col : curr_col;
    for (uint i = begin; i <= end; i++) {
      if (board_[curr_row][i] != FREE && board_[curr_row][i] != P1) {
        return false;
     }
     next_board[curr_row][i] = BLOCKED;
    }
  } else if (curr_col == col) {
    uint begin = (curr_row < row) ? curr_row : row;
    uint end = (curr_row < row) ? row : curr_row;
    for (uint i = begin; i <= end; i++) {
      if (board_[i][curr_col] != FREE && board_[i][curr_col] != P1) {
        return false;
      }
      next_board[i][curr_col] = BLOCKED;
    }
  } else if (abs(static_cast<int>(curr_row) - static_cast<int>(row)) == abs(static_cast<int>(curr_col) - static_cast<int>(col))) {
    auto diff = abs(static_cast<int>(curr_row) - static_cast<int>(row));
    bool up = (curr_row > row);
    bool left = (curr_col > col);
    for (; diff >= 0; diff--) {
      if (board_[curr_row][curr_col] != FREE && board_[curr_row][curr_col] != P1) {
        return false;
      }
      next_board[curr_row][curr_col] = BLOCKED;
      if (up) {
        curr_row--;
      } else {
        curr_row++;
      }
      if (left) {
        curr_col--;
      } else {
        curr_col++;
      }
    }
  } else {
    return false;
  }
  next_board[row][col] = P1;
  board_ = next_board;
  return true;
}

void Isolation::printWinner() {
  // see who is blocked. If both are blocked, return the opposite of the current player. 
  bool player1_can_move = true;
  bool player2_can_move = true;
  for (uint i = 0; i < board_.size(); ++i) {
    for (uint j = 0; j < board_[i].size(); ++j) {
      if (board_[i][j] == P1) {
        player1_can_move = Isolation::hasAvailableMoves(i, j);
      }
      if (board_[i][j] == P2) {
        player2_can_move = Isolation::hasAvailableMoves(i, j);
      }
    }
  }
  if (!player1_can_move && player2_can_move) {
    std::cout << "Player 2 wins!" << std::endl;
  } else if (!player2_can_move && player1_can_move) {
    std::cout << "Player 1 wins!" << std::endl;
  } else if (player_ == P2) {
    std::cout << "Player 2 wins!" << std::endl;
  } else {
    std::cout << "Player 1 wins!" << std::endl;
  }
}

void Isolation::setPlayer(int p) {
  if (p== 1) {
    player_ = P1;
  } else {
    player_ = P2;
  }
}

/**
 * Isolation game specific functions
 */
bool Isolation::hasAvailableMoves(uint row, uint col) {
  bool canMove = false;
  canMove |= (row >= 1 && board_[row-1][col] == FREE);
  canMove |= (col >= 1 && board_[row][col-1] == FREE);
  canMove |= (row + 1 < board_.size() && board_[row+1][col] == FREE);
  canMove |= (col + 1 < board_[row].size() && board_[row][col+1] == FREE);
  canMove |= (row >= 1 && col >= 1 && board_[row-1][col-1] == FREE);
  canMove |= (row >= 1 && col + 1 < board_[row].size() && board_[row-1][col+1] == FREE);
  canMove |= (row + 1 < board_.size() && col + 1 < board_[row].size() && board_[row+1][col+1] == FREE);
  canMove |= (row + 1 < board_.size() && col >= 1 && board_[row+1][col-1] == FREE);
  return canMove;
}

std::vector<std::shared_ptr<GameState>> Isolation::moveInDirection(uint row, uint col, Direction dir) {
    std::vector<std::shared_ptr<GameState>> next_states;
    std::vector<std::vector<IBoardEntry>> next_board(board_);
    auto new_row = static_cast<int>(row), new_col = static_cast<int>(col);
    for (; ;) {
        if (dir == NORTHEAST || dir == EAST || dir == SOUTHEAST) {
            new_col++;
        }
        if (dir == NORTHWEST || dir == WEST || dir == SOUTHWEST) {
            new_col--;
        }
        if (dir == NORTHWEST || dir == NORTH || dir == NORTHEAST) {
            new_row--;
        }
        if (dir == SOUTHWEST || dir == SOUTH || dir == SOUTHEAST) {
            new_row++;
        }
        if (new_row < 0 || new_row >= static_cast<int>(board_.size()) || new_col < 0 || new_col >= static_cast<int>(board_[0].size())) {
          break;
        }
        auto u_new_row = static_cast<uint>(new_row);
        auto u_new_col = static_cast<uint>(new_col);
        if (board_[u_new_row][u_new_col] == BLOCKED || board_[u_new_row][u_new_col]  == P1 || board_[u_new_row][u_new_col] == P2) {
            break;
        }
        next_board[row][col] = BLOCKED;
        if (player_ == P1) {
          next_board[u_new_row][u_new_col] = P1;
        } else {
          next_board[u_new_row][u_new_col] = P2;
        }
        std::shared_ptr<Isolation> next_state = std::make_shared<Isolation>();
        next_state->setBoard(next_board);
        if (player_ == P1) {
          next_state->setPlayer(2);
        } else {
          next_state->setPlayer(1);
        }
        next_states.push_back(next_state);
        row = u_new_row;
        col = u_new_col;
    }
    return next_states;
}

std::shared_ptr<GameState> Isolation::randomFirstMove() {
  using my_engine = std::default_random_engine;
  using uniform_distribution = std::uniform_int_distribution<>;
  std::shared_ptr<Isolation> next_state = std::make_shared<Isolation>();
  std::vector<std::vector<IBoardEntry>> next_board(board_);
  my_engine re {};
  uniform_distribution generate_unique {0, (int)board_.size() - 1};
  re.seed((uint)time(NULL));
  uint row = (uint)generate_unique(re);
  uint col = (uint)generate_unique(re);
  while (next_board[row][col] != player_) {
    if (next_board[row][col] == FREE) {
      next_board[row][col] = player_;
    } else {
      row = (uint)generate_unique(re);
      col = (uint)generate_unique(re);
    }
  }
  next_state->setBoard(next_board);
  if (player_ == P1) {
    next_state->setPlayer(2);
  } else {
    next_state->setPlayer(1);
  }
  return next_state;
}

bool Isolation::isValidMove(uint row, uint col) {
  if (row < 0 || row >= 3 || col < 0 || col >= 3) {
    return false;
  }
  if (board_[row][col] != FREE) {
    return false;
  }
  return true;
}

std::pair<uint, uint> Isolation::getCurrPos(IBoardEntry p) {
  uint r, c;
  bool found = false;
  for (r = 0; r < board_.size(); r++) {
    for (c = 0; c < board_[r].size(); c++) {
      if (board_[r][c] == p) {
        found = true;
        break;
      }
    }
    if (found) {
      break;
    }
  }
  return std::pair<uint, uint>(r, c);
}

}  // namespace core
}  // namespace minimax