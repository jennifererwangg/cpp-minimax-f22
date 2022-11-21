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
Node -> GameState -> Tictactoe

Minimax Algorithm strictly uses `GameState`. It does not know anything about `Tictactoe`.

**All documentation is located in the `.h` files**

## Pointer Management Tips

**DO NOT USE A RAW POINTER SUCH AS `*`!** Always use **`ClassName::Ptr`** to represent a pointer, and **`std::make_shared<ClassName>()`** to initialize one. All of the memory management is handled in `src/core/node.cc`.

To create a shared pointer: 
```cpp
ClassName::Ptr pointer = std::make_shared<ClassName>();

// example:
Tictactoe::Ptr tictactoe_ptr = std::make_shared<TicTacToe>();
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
│   │   ├── game_state.cc
│   │   ├── game_state.h
│   │   ├── tictactoe.cc
│   │   └── tictactoe.h
│   ├── node.cc
│   ├── node.h
│   └── solver
│       ├── minimax_solver.cc
│       └── minimax_solver.h
├── minimax_exe
│   ├── CMakeLists.txt
│   ├── main.cc
│   └── main.h
└── tests
    ├── CMakeLists.txt
    ├── tests.cc
    └── tictactoe_tests
        ├── tictactoe_tests.cc
        └── tictactoe_tests.h
```

## TODO
Tic tac toe
- [ ] Implement a tic tac toe player (instead of the automated one in `minimax_exe/main.cc`)

Others
...