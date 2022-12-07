- [Introduction](#introduction)
- [Design Choices](#design-choices)
  - [The Core: Minimax Algorithm, Games, and Players](#the-core-minimax-algorithm-games-and-players)
  - [Unit Tests](#unit-tests)
  - [Performance](#performance)
  - [Game Executables](#game-executables)
- [Looking ahead: C++ 20](#looking-ahead-c-20)
- [Folder Structure](#folder-structure)

# Introduction
*Elementary* is a framework for developers to build their own games and play them against intelligent agents. It allows developers with zero background in AI to leverage an optimized version of the Minimax Algorithm. The framework utilizes multiple layers of abstraction. It is separated into three main components: 1) core components such as the minimax solver, games, and players; 2) unit tests and performance tests; and 3) separate executables for each user-implemented game.

# Design Choices
## The Core: Minimax Algorithm, Games, and Players
The core of our Minimax library lays in the [core folder](/src/core/). Here is an overview of the major components.
![](data/design/core-design.png)

At its top, we have the generic minimax solver. It has an `evaluate` that kicks off the minimax algorithm. When the algorithm queries for states specific to the game, it uses four generic functions built in the `GameState` generic class: `getNextState()`, `evalHeuristics()`, and `isDone()`. However, it should be emphasized that there is no need for the game implementers themselves to thoroughly understand the inner-workings of the minimax algorithm. The only knowledge needed is a good understanding of the games themselves. Game implementers are encouraged to think about the different states of their games during the playing process. `getNextState()` generates all possible next states of the game given the current state, `evalHeuristic()` return the utility of the current state in an integer format, and `isDone()` checks to see if a game has reached its final state.  

Individual games, such as checkers, isolation, and tic-tac-toe, must implement these three functions in order to utilize the minimax algorithm. Of course, these classes can contain many other functions to manipulate its own state.

To facilitate the playing of the games, we implemented a generic player library. There are two main types of players: automatic player and interactive player. The automatic player, implemented via the `AutomaticPlayer` class, simulates the playing of two opponents via optimal strategies, while the interactive player, implemented via the `InteractivePlayer` class, allows users to directly play games on the terminal. Both types of players inherit from the base class `BasePlayer` and must implement the `play()` function. 

Both `AutomaticPlayer` and `InteractivePlayer` invoke the four functions `printState()`, `processUserInput()`, and `printWinner()` from the base GameState class. Similar to the minimax framework above, it is also the individual game's responsibility to implement these four generic functions. `printState()` outputs the game's current state onto the terminal, `processUserInput()` prompts users to make a move in the game and changes the internal state of the game. Finally, `printWinner()` outputs the game's winner onto the terminal.

In summary, our library is very adaptable for supporting new games. In order to utilize the minimax solver, one will need to implement three functions specific to state management: `getNextState()`, `evalHeuristics()`, and `isDone()`. In order to support automatic and interactive player, one will need to implement another set of functions: `printState()`, `processUserInput()`, and `printWinner()`. The inner-workings of the minimax algorithm and the playing interface are abstracted away from the game implementer's perspective.

## Unit Tests
Tests are an integral part of any code development process. While developing indivdiual games such as tic-tac-toe, isolation, and checkers, we also wrote unit tests to ensure the proper functionalities of each game's core member functions as discussed above, as well as their helper member functions. All unit tests can be found in the [tests folder](/src/tests/), which is further separated into three individual folders for the three individual games that we have implemented: `checkers_test`, `isolation_tests`, and `tictactoe_tests`. 

## Performance
We measured the performance of the tic-tac-toe game at various search depths. We found that as expected, greater search depths lead to longer runtime. As the board becomes less empty, the max search depth decreases, leading to a smaller tree and therefore a faster runtime. 

The runtime is also significantly impacted by alpha-beta pruning. We can drastically decrease runtime by utilizing alpha-beta pruning.

|Tictactoe Runtime Performance With Alpha-beta Pruning | Tictactoe Runtime Performance Without Alpha-beta Pruning|
|--|--|
|![](data/pics/tictactoe-with-pruning.png)|![](data/pics/tictactoe-no-pruning.png)|

A comparison between pruning vs. no pruning is made for an initially empty tic-tac-toe board. We can see that especially when the max search depth is very large, alpha-beta pruning reduces the search time by more than 1/2.

![](data/pics/tictactoe-comparison.png)

All performance code can be found in the [tests/performance folder](/src/tests/performance/). The code can be easily adaptable to measure and generate data for checkers, isolation, or any other game (only a 1-line change in [performance_tests.cc](src/tests/performance/performance_tests.cc)!). We only measured the performance of tic-tac-toe for the sake of simplicity.

## Game Executables
All game executables are located in the [games_exe folder](src/games_exe/). Currently, it has three `main` functions for to kick off the three games that we have implemented. This is the place where everything discussed above come together. Memory is managed according to the **"resource acquisition is initialization" (RAII)** principle. Smart shared pointers are used to "pass around" game states.

# Looking ahead: C++ 20
Currently, clang and CMake do not fully support C++ 20. If these conditions changes, we hope to incorporate the following into our library:
* Modules: export the minimax solver as modules
* Parallelism: support parallel evaluation of the minimax algorithm for even better performance

# Folder Structure
Lastly, here is the folder structure of our entire codebase for reference.
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

13 directories, 34 files
```