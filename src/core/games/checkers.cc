#include <vector>
#include "core/games/checkers.h"

namespace minimax {
namespace core {
namespace checkers {

using uint = unsigned int;

Checkers::Checkers() {
  // initialize empty board
  board.push_back({EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE});
  board.push_back({WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY});
  board.push_back({EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE});
  board.push_back({EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY});
  board.push_back({EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY});
  board.push_back({BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY});
  board.push_back({EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK});
  board.push_back({BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY});
}

/**
 * GameState interface
 */
bool Checkers::isDone() {
  return countPieces(WHITE, WHITE_KING) == 0 || countPieces(BLACK, BLACK_KING) == 0 || white_next_states == 0 || black_next_states == 0;
}

int Checkers::evalHeuristics() {
  // TODO: improve this
  if (white_turn) {
    return countPieces(WHITE, WHITE_KING) - countPieces(BLACK, BLACK_KING);
  } else {
    return countPieces(BLACK, BLACK_KING) - countPieces(WHITE, WHITE_KING);
  }
}

void Checkers::printState() {
  std::string turn = white_turn ?  "Black's Turn:\n" : "White's Turn:\n"; // (bc it is whoever went last)

  std::cout << turn;
  std::cout << "------------------------------\n";
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if(board[i][j] == WHITE) {
        std::cout << "\u25EF";
      } else if(board[i][j] == BLACK) {
        std::cout << "\u25CD";
      } else if(board[i][j] == WHITE_KING) {
        std::cout << "\u25B3";
      } else if(board[i][j] == BLACK_KING) {
        std::cout << "\u25B2";
      } else {
        std::cout << " ";
      }

      std::cout << " | ";
    }
    std::cout << "\n------------------------------\n";
  }
}

std::vector<std::shared_ptr<GameState>> Checkers::getNextState() {
  std::vector<std::shared_ptr<GameState>> next_states;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      // TODO: implement double jumping
      // TODO: can only jump into empty space
      std::shared_ptr<GameState> next_state;
      bool isValid;


      if (white_turn && board[i][j] == WHITE) {
        // left and down
        tie(isValid, next_state) = moveLeftAndDown(i, j, BLACK, BLACK_KING);
        if(isValid) next_states.push_back(next_state);

        // right and down
        tie(isValid, next_state) = moveRightAndDown(i, j, BLACK, BLACK_KING);
        if(isValid) next_states.push_back(next_state);
      }

      if(white_turn && board[i][j] == WHITE_KING) {
        // left and down
        tie(isValid, next_state) = moveLeftAndDown(i, j, BLACK, BLACK_KING);
        if(isValid) next_states.push_back(next_state);

        // right and down
        tie(isValid, next_state) = moveRightAndDown(i, j, BLACK, BLACK_KING);
        if(isValid) next_states.push_back(next_state);

        // left and up
        tie(isValid, next_state) = moveLeftAndUp(i, j, BLACK, BLACK_KING);
        if(isValid) next_states.push_back(next_state);

        // right and up
        tie(isValid, next_state) = moveRightAndUp(i, j, BLACK, BLACK_KING);
        if(isValid) next_states.push_back(next_state);

      }

      if(!white_turn && board[i][j] == BLACK) {
        // left and up
        tie(isValid, next_state) = moveLeftAndUp(i, j, WHITE, WHITE_KING);
        if(isValid) next_states.push_back(next_state);

        // right and up
        tie(isValid, next_state) = moveRightAndUp(i, j, WHITE, WHITE_KING);
        if(isValid) next_states.push_back(next_state);
      }

      if(!white_turn && board[i][j] == BLACK_KING) {
        // left and down
        tie(isValid, next_state) = moveLeftAndDown(i, j, WHITE, WHITE_KING);
        if(isValid) next_states.push_back(next_state);

        // right and down
        tie(isValid, next_state) = moveRightAndDown(i, j, WHITE, WHITE_KING);
        if(isValid) next_states.push_back(next_state);

        // left and up
        tie(isValid, next_state) = moveLeftAndUp(i, j, WHITE, WHITE_KING);
        if(isValid) next_states.push_back(next_state);

        // right and up
        tie(isValid, next_state) = moveRightAndUp(i, j, WHITE, WHITE_KING);
        if(isValid) next_states.push_back(next_state);

      }
    }
  }

  if (white_turn) white_next_states = next_states.size();
  else black_next_states = next_states.size();

  // std::cout << "Next states num : " << next_states.size() << "\n";
  return next_states;
}

std::tuple<bool, std::shared_ptr<Checkers>> Checkers::moveRightAndUp(int i, int j, BoardEntry piece1, BoardEntry piece2) {
  auto next_state = std::make_shared<Checkers>();
  if ( !( i - 1 < 0 || j + 1 >= 8 ) ) {
    if ( board[i - 1][j + 1] == EMPTY ) {
      next_state->setBoard(movePiece({i, j}, {i - 1, j + 1}, {-1, -1}));
      next_state->switchTurn(white_turn);

      return std::make_tuple(true, next_state);
    } else if ( board[i - 1][j + 1] == piece1 || board[i - 1][j + 1] == piece2 ) { // we have a jump situation!
      if ( !( i - 2 < 0 || j + 2 >= 8 ) && board[i - 2][j + 2] == EMPTY) { // make sure it is in bounds and doesn't have a current piece
        next_state->setBoard(movePiece({i, j}, {i - 2, j + 2}, {i - 1, j + 1}));
        next_state->switchTurn(white_turn);

        return std::make_tuple(true, next_state);
      }
    }
  }

  return std::make_tuple(false, next_state);
}

std::tuple<bool, std::shared_ptr<Checkers>> Checkers::moveRightAndDown(int i, int j, BoardEntry piece1, BoardEntry piece2) {
  auto next_state = std::make_shared<Checkers>();
  if ( !( i + 1 >= 8 || j + 1 >= 8 ) ) {
    if ( board[i + 1][j + 1] == EMPTY ) {
      next_state->setBoard(movePiece({i, j}, {i + 1, j + 1}, {-1, -1}));
      next_state->switchTurn(white_turn);

      return std::make_tuple(true, next_state);
    } else if ( board[i + 1][j + 1] == piece1 || board[i + 1][j + 1] == piece2 ) { // we have a jump situation!
      if ( !( i + 2 >= 8 || j + 2 >= 8 ) && board[i + 2][j + 2] == EMPTY) { // make sure it is in bounds and doesn't have a current piece
        next_state->setBoard(movePiece({i, j}, {i + 2, j + 2}, {i + 1, j + 1}));
        next_state->switchTurn(white_turn);

        return std::make_tuple(true, next_state);
      }
    }
  }

  return std::make_tuple(false, next_state);
}

std::tuple<bool, std::shared_ptr<Checkers>> Checkers::moveLeftAndDown(int i, int j, BoardEntry piece1, BoardEntry piece2) {
  auto next_state = std::make_shared<Checkers>();
  if ( !( i + 1 >= 8 || j - 1 < 0 ) ) {
    if ( board[i + 1][j - 1] == EMPTY ) {
      next_state->setBoard(movePiece({i, j}, {i + 1, j - 1}, {-1, -1}));
      next_state->switchTurn(white_turn);

      return std::make_tuple(true, next_state);
    } else if ( board[i + 1][j - 1] == piece1 ||  board[i + 1][j - 1] == piece2 ) { // we have a jump situation!
      if ( !( i + 2 >= 8 || j - 2 < 0 ) && board[i + 2][j - 2] == EMPTY) { // make sure it is in bounds and doesn't have a current piece
        next_state->setBoard(movePiece({i, j}, {i + 2, j - 2}, {i + 1, j - 1}));
        next_state->switchTurn(white_turn);

        return std::make_tuple(true, next_state);
      }
    }
  }

  return std::make_tuple(false, next_state);
}

std::tuple<bool, std::shared_ptr<Checkers>> Checkers::moveLeftAndUp(int i, int j, BoardEntry piece1, BoardEntry piece2) {
  auto next_state = std::make_shared<Checkers>();
  if ( !( i - 1 < 0 || j - 1 < 0 ) ) {
    if ( board[i - 1][j - 1] == EMPTY ) {
      next_state->setBoard(movePiece({i, j}, {i - 1, j - 1}, {-1, -1}));
      next_state->switchTurn(white_turn);

      return std::make_tuple(true, next_state);
    } else if ( board[i - 1][j - 1] == piece1 || board[i - 1][j - 1] == piece2 ) { // we have a jump situation!
      if ( !( i - 2 < 0 || j - 2 < 0 ) && board[i - 2][j - 2] == EMPTY) { // make sure it is in bounds and doesn't have a current piece
        next_state->setBoard(movePiece({i, j}, {i - 2, j - 2}, {i - 1, j - 1}));
        next_state->switchTurn(white_turn);

        return std::make_tuple(true, next_state);
      }
    }
  }

  return std::make_tuple(false, next_state);
}

/**
 * Checkers game specific functions
 */
std::vector<std::vector<BoardEntry>> Checkers::movePiece(std::vector<int> initialPlace, std::vector<int> newPlace, std::vector<int> jump) {
  std::vector<std::vector<BoardEntry>> new_board = board;
  BoardEntry piece = new_board[initialPlace[0]][initialPlace[1]];

  new_board[newPlace[0]][newPlace[1]] = piece;
  new_board[initialPlace[0]][initialPlace[1]] = EMPTY;

  if(jump[0] != -1) {
    new_board[jump[0]][jump[1]] = EMPTY;
  }

  // check for kings
  if (newPlace[0] == 0 && piece == BLACK) {
    new_board[newPlace[0]][newPlace[1]] = BLACK_KING;
  }

  if (newPlace[0] == 7 && piece == WHITE) {
    new_board[newPlace[0]][newPlace[1]] = WHITE_KING;
  }

  return new_board;
}

int Checkers::countPieces(BoardEntry color, BoardEntry color_king) {
  int count = 0;

  for(auto row : board) {
    for(auto piece : row) {
      if (piece == color || piece == color_king) {
        count++;
      }
    }
  }

  return count;
}

}  // namespace checkers
}  // namespace core
}  // namespace minimax
