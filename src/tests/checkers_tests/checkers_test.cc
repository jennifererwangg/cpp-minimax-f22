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
    std::vector<std::shared_ptr<GameState>> states = checkers->getNextState();

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

    std::vector<std::shared_ptr<GameState>> states = checkers->getNextState();

    states[0]->printState();

    return true;
}
