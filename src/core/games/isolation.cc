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
  if (player_ == P2) {
    utility *= -1;
  }
  return utility;
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
  uint i = 0, j = 0;
  bool found = false;
  std::vector<Direction> all_directions = {NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST};
  for (uint r = 0; r < board_.size(); r++) {
    for (uint c = 0; c < board_[r].size(); c++) {
      // std::cout << i << j << std::endl;
      if (board_[r][c] == player_) {
        i = r;
        j = c;
        r += board_.size();
        found = true;
        break;
      }
    }
 }
 if (!found) {
    next_states.push_back(Isolation::randomFirstMove());
    return next_states;
 }
 for (auto dir : all_directions) {
     auto dir_states = moveInDirection(i, j, dir);
     next_states.insert(next_states.end(), dir_states.begin(), dir_states.end());
 }
  return next_states;
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
          next_state->setPlayer(P2);
        } else {
          next_state->setPlayer(P1);
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
    next_state->setPlayer(P2);
  } else {
    next_state->setPlayer(P1);
  }
  return next_state;
}

}  // namespace core
}  // namespace minimax