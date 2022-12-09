# 1. Quick Links
- [Design Doc](Design.md)
- [Full Tutorial](https://docs.google.com/document/d/1xOSEW4J4jF1ODMN6chgXa8MjY5u1SJ4KZr2pthdEy44/edit?usp=sharing)
- [Manual]() -- TODO: insert link

# 2. How to run

## 2a. Build
1. Create `build` folder and run `make`
```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## 2b. Play games
Make sure to stay inside the `build` directory.

**Interactive Modes**
```bash
# Play interactive tic-tac-toe
$ ./src/games_exe/tictactoe/tictactoe i

# Play interactive isolation
./src/games_exe/isolation/isolation i

# Play interactive checkers
$ ./src/games_exe/checkers/checkers i
```

**Automatic Modes**
```bash
# Play interactive tic-tac-toe
$ ./src/games_exe/tictactoe/tictactoe a

# Play interactive isolation
./src/games_exe/isolation/isolation a

# Play interactive checkers
$ ./src/games_exe/checkers/checkers a
```

## 2c. Run Tests
Make sure to stay inside the `build` directory.
```bash
# Run performance tests
./src/tests/minimax_tests p

# Run unit tests
./src/tests/minimax_tests u
```
