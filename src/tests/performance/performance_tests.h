#include <map>
#include <vector>
#include "core/games/game_state.h"

using ll = long long;

/**
 * \brief depthTest measures the runtime of the minimax algorithm at each depth from 0 to max_depth.
 * 
 * \param int max_depth
 * 
 * depthTest measures the runtime of the minimax algorithm at each depth d from 0 to max_depth with 
 * alpha-beta pruning and without alpha-beta pruning. It writes the results to a CSV file.
 */
void depthTest(int max_depth);

/**
 * \brief depthGameTest runs the game to completion and times the runtime of each minimax evaluate() call.
 * 
 * \param int depth
 * \param std::shared_ptr<GameState> game
 * \param std::map<int, vector<ll>> &depth_to_time
 * \param bool optimized
 */
void depthGameTest(int max_depth, std::shared_ptr<minimax::core::GameState> game, std::map<int, std::vector<ll>> &depth_to_time, bool optimized = true);
void writeToCSV(std::string name, std::map<int, std::vector<ll>> depth_to_time);