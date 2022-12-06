#include <iostream>
#include <string>
#include "core/players/automatic_player.h"
#include "core/players/interactive_player.h"
#include "core/games/isolation.h"

using namespace std;
using namespace minimax::core;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Incorrect usage. Please run: ./isolation <a/i>\n";
    return 0;
  }

  string option = argv[1];
  if (option != "a" && option != "i") {
    cout << "Incorrect usage. Please run: ./isolation <a/i>\n";
    return 0;
  }

  cout << "Welcome to isolation player!\n";

  if (option == "a") {
    // Automatically play isolation (uncomment to play)
    std::shared_ptr<GameState> isolation = std::make_shared<Isolation>(); // create game
    AutomaticPlayer isolation_auto_player(isolation, 5); // create player
    isolation_auto_player.play(); // play game
  } else {
    // Interactive isolation (uncomment to play)
    std::shared_ptr<Isolation> isolation = std::make_shared<Isolation>(2); // create game
    InteractivePlayer interactive_isolation_player(isolation, 10); // create player
    interactive_isolation_player.play(); // play game
  }

  return 0;
}