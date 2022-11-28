#include <iostream>
#include <string>
#include "core/games/game_state.h"
#include "core/games/tictactoe.h"
#include "core/games/isolation.h"
#include "core/solver/minimax_solver.h"
#include "main.h"

using namespace std;
using namespace minimax::core;

int main(int /*argc*/, char **/*argv*/)
{
  // cout << "Welcome to the automatic player!\n";
  // automaticPlayer(ISOLATION);

  cout << "Welcome to the interactive player!\n";
  interactiveIsolationPlayer();
  return 0;
}

void automaticPlayer(Game g) {
  std::shared_ptr<GameState> game;
  switch(g) {
    case TICTACTOE:
      game = std::make_shared<Tictactoe>();
      break;
    case ISOLATION:
      game = std::make_shared<Isolation>();
      break;
  }
  for (;;) {
    MinimaxSolver solver(10);
    std::shared_ptr<GameState> next_best_state = solver.evaluate(game);
    next_best_state->printState();
    game = next_best_state;
    if (game->isDone()) {
      break;
    }
  }
}

void interactiveIsolationPlayer() {
  std::shared_ptr<Isolation> game = std::make_shared<Isolation>(2);
  MinimaxSolver minimax_solver(10);
  game->printState();
  while (!game->isDone()) {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Your turn (1)" << std::endl;
    std::string x = "", y = "";
    uint x_int = 10, y_int = 10;
    while (true) {
      std::cout << "Enter x (0 to 2): ";
      std::cin >> x;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter y (0 to 2): ";
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
      if (game->makeMove(x_int, y_int)) {
        break;
      }
      std::cout << "Invalid move. Try again." << std::endl;
    }
    game->printState();
    if (game->isDone()) {
      std::cout << "Player 1 wins!\n";
      break;
    }
    // Computer Move
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "\n2's turn" << std::endl;
    std::shared_ptr<GameState> next_state = minimax_solver.evaluate(game);
    game = std::dynamic_pointer_cast<Isolation>(next_state);
    game->printState();
    game->setPlayer(2);
    if (game->isDone()) {
      std::cout << "Player 2 wins!\n";
      break;
    }
  }
}