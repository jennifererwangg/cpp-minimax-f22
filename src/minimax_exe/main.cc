#include <iostream>
#include <string>
#include "core/games/tictactoe.h"
#include "main.h"
#include "core/players/automatic_player.h"
#include "core/players/interactive_tictactoe_player.h"
#include "core/players/interactive_isolation_player.h"

using namespace std;
using namespace minimax::core;

int main(int /*argc*/, char **/*argv*/)
{
  

  /**
   * Tictactoe Games
   * 
   */
  // cout << "Welcome to tic tac toe player!\n";
  // Automatically play tic tac toe (uncomment to play)
  // std::shared_ptr<GameState> tictactoe = std::make_shared<Tictactoe>(); // create game
  // AutomaticPlayer tic_tac_toe_player(tictactoe, 10); // create player
  // tic_tac_toe_player.play(); // play game

  // Interactive tic tac toe (uncomment to play)
  // std::shared_ptr<Tictactoe> tictactoe = std::make_shared<Tictactoe>(); // create game
  // InteractiveTictactoePlayer interactive_tic_tac_toe_player(tictactoe, 10); // create player
  // interactive_tic_tac_toe_player.play(); // play game

  /**
   * Isolation games
   */
  cout << "Welcome to isolation player!\n";
  // Interactive isolation (uncomment to play)
  std::shared_ptr<Isolation> isolation = std::make_shared<Isolation>(2); // create game
  InteractiveIsolationPlayer interactive_isolation_player(isolation, 10); // create player
  interactive_isolation_player.play(); // play game

  return 0;
}