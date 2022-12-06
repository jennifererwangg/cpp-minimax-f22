#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include "core/solver/minimax_solver.h"
#include "core/games/tictactoe.h"
#include "core/games/isolation.h"
#include "core/games/checkers.h"
#include "performance/performance_tests.h"

using namespace std;
using namespace minimax::core;
using namespace minimax::core::checkers;

void depthTest(int max_depth) {
  // with alpha-beta pruning performance
  std::cout << "Running depth tests with alpha-beta pruning...\n";
  std::map<int, vector<ll>> depth_to_time;
  for (int d = 2 ; d <= max_depth; d++) {
    depth_to_time.insert({d, vector<ll>()});
    std::shared_ptr<GameState> tictactoe_game = std::make_shared<Tictactoe>();
    depthGameTest(d, tictactoe_game, depth_to_time, true);
  }
  writeToCSV("performance_with_alpha_beta.csv", depth_to_time);

  // without alpha-beta pruning performance
  std::cout << "Running depth tests without alpha-beta pruning...\n";
  depth_to_time.clear();
  for (int d = 2 ; d <= max_depth; d++) {
    depth_to_time.insert({d, vector<ll>()});
    std::shared_ptr<GameState> tictactoe_game = std::make_shared<Tictactoe>();
    depthGameTest(d, tictactoe_game, depth_to_time, false);
  }
  writeToCSV("performance_without_alpha_beta.csv", depth_to_time);

  std::cout << "Files generated: performance_with_alpha_beta.csv, performance_without_alpha_beta.csv" << std::endl;
}

void depthGameTest(int depth, std::shared_ptr<GameState> game, std::map<int, vector<ll>> &depth_to_time, bool optimized) {
  MinimaxSolver minimax_solver(depth);
  for (;;) {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::shared_ptr<GameState> next_best_state = minimax_solver.evaluate(game, optimized);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    ll time = duration.count();
    depth_to_time[depth].push_back(time);
    game = next_best_state;
    if (game->isDone()) {
      break;
    }
  }
}

void writeToCSV(string name, std::map<int, vector<ll>> depth_to_time) {
  ofstream csv_file;
  csv_file.open(name);

  for (auto depth_time_pair : depth_to_time) {
    int depth = depth_time_pair.first;
    vector<ll> times = depth_time_pair.second;
    std::cout << "Depth " << depth << ": ";
    for (auto time : times) {
      std::cout << time << " ";
      csv_file << time << ",";
    }
    std::cout << std::endl;
    csv_file << std::endl;
  }
  csv_file.close();
}