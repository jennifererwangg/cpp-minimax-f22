- [Minimax Library](#minimax-library)
  - [How to run](#how-to-run)
  - [Design](#design)
  - [Pointer Management Tips](#pointer-management-tips)
  - [Compilation Tips](#compilation-tips)
  - [Current Directory Structure (inside `src`)](#current-directory-structure-inside-src)
  - [TODO](#todo)


# Minimax Library

## How to run
1. Make
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```
2. Stay inside the build directory
3. To run the main executable (play a game): `./src/minimax_exe/minimax_exe`
4. To run tests: `./src/tests/minimax_tests`

## Design
There are 2 main components to the MiniMax library. 
1. Everything related to the minimax algorithm is located in the `core/solver` folder
2. Everything related to the game is located in the `core/games` folder.

**Hierarchical design**: Game Inheritance example for tictactoe (node is there to help with pointer management)
GameState -> Tictactoe

Minimax Algorithm strictly uses `GameState`. It does not know anything about `Tictactoe`.

TODO: make a class/folder called "players" that contains all kinds of players. This will be used by `minimax_exe/main.cc`. For example:
* base (automatic/interactive/concurrent) player
* tictactoe automatic player, tictactoe interactive player, tictactoe concurrent player
* 2048 automatic player, ...

**All documentation is located in the `.h` files**

## Pointer Management Tips

To create a shared pointer: 
```cpp
std::shared_ptr<ClassName> pointer = std::make_shared<ClassName>();

// example:
std::shared_ptr<Tictactoe> tictactoe_ptr = std::make_shared<TicTacToe>();
```

## Compilation Tips
If you add a new file/directory, make sure to update the corresponding `CMakeList.txt` as well!

## Current Directory Structure (inside `src`)
```
.
├── CMakeLists.txt
├── core
│   ├── CMakeLists.txt
│   ├── games
│   │   ├── checkers.cc
│   │   ├── checkers.h
│   │   ├── game_state.cc
│   │   ├── game_state.h
│   │   ├── isolation.cc
│   │   ├── isolation.h
│   │   ├── tictactoe.cc
│   │   └── tictactoe.h
│   ├── players
│   │   ├── automatic_player.cc
│   │   ├── automatic_player.h
│   │   ├── base_player.cc
│   │   ├── base_player.h
│   │   ├── checkers_player.cc
│   │   ├── checkers_player.h
│   │   ├── interactive_player.cc
│   │   └── interactive_player.h
│   └── solver
│       ├── minimax_solver.cc
│       └── minimax_solver.h
├── games_exe
│   ├── checkers
│   │   ├── CMakeLists.txt
│   │   └── main.cc
│   ├── isolation
│   │   ├── CMakeLists.txt
│   │   └── main.cc
│   └── tictactoe
│       ├── CMakeLists.txt
│       └── main.cc
└── tests
    ├── CMakeLists.txt
    ├── checkers_tests
    │   ├── checkers_test.cc
    │   └── checkers_test.h
    ├── isolation_tests
    │   ├── isolation_tests.cc
    │   └── isolation_tests.h
    ├── performance
    │   ├── performance_tests.cc
    │   └── performance_tests.h
    ├── tests.cc
    └── tictactoe_tests
        ├── tictactoe_tests.cc
        └── tictactoe_tests.h
```

## TODO
Tic tac toe
- [ ] Implement a tic tac toe player (instead of the automated one in `minimax_exe/main.cc`) -- see TODO in the design section for more details

Others
...