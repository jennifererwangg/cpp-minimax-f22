#include <iostream>
#include "core/solver/minimax_solver.h"
#include "core/games/checkers.h"
#include "tests/checkers_tests/checkers_test.h"

using namespace std;
using namespace minimax::core;
using namespace minimax::core::checkers;

/**
 ********************************************************
 * Checkers tests (src/core/games/checkers.cc)
 ********************************************************
 */
bool testCheckersSetup() {
    std::shared_ptr<Checkers> checkers = std::make_shared<Checkers>();

    checkers->printState();

    return true;
}

bool testGetNextMoves() {
    std::shared_ptr<Checkers> checkers = std::make_shared<Checkers>();
    std::vector<std::shared_ptr<minimax::core::GameState>> states = checkers->getNextState();

    for (auto state : states) {
        state->printState();
    }

    auto states2 = states[0]->getNextState();

    for (auto state : states2) {
        state->printState();
    }

    return true;
}

bool testJump() {
    std::shared_ptr<Checkers> checkers = std::make_shared<Checkers>();

    std::vector<std::vector<BoardEntry>> new_board = checkers->movePiece({2, 1}, {4, 1}, {-1, -1});

    checkers->setBoard(new_board);

    checkers->printState();

    std::vector<std::shared_ptr<minimax::core::GameState>> states = checkers->getNextState();

    states[0]->printState();

    return true;
}

bool testNextMove() {
    std::shared_ptr<Checkers> checkers = std::make_shared<Checkers>();

    bool c = checkers->isValidMove({5, 0}, {4, 1}, {-1, -1});

    std::cout << c << "\n";

    return c;
}

bool testJumpMove() {
    std::shared_ptr<Checkers> checkers = std::make_shared<Checkers>();
    std::vector<std::vector<BoardEntry>> board;

    board.push_back({EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE});
    board.push_back({WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY});
    board.push_back({EMPTY, EMPTY, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE});
    board.push_back({EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY});
    board.push_back({EMPTY, WHITE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY});
    board.push_back({BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY});
    board.push_back({EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK});
    board.push_back({BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY});

    checkers->setBoard(board);

    auto j = checkers->checkIfJump({5, 0}, {3, 2});

    std::cout << j[0] << ", " << j[1] << " \n";

    bool c = checkers->isValidMove({5, 0}, {3, 2}, {4, 1});

    std::cout << c << "\n";

    return true;
}
