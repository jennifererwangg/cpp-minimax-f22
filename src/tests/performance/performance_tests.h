#include <map>
#include <vector>
#include "core/games/game_state.h"

using ll = long long;

void depthTest(int max_depth);
void depthGameTest(int max_depth, std::shared_ptr<minimax::core::GameState> game, std::map<int, std::vector<ll>> &depth_to_time, bool optimized = true);
void writeToCSV(std::string name, std::map<int, std::vector<ll>> depth_to_time);