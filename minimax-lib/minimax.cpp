#include "minimax-lib/minimax.h"
#include "minimax-lib/game.h"
#include <utility>
#include <limits>

// template<typename GameState>
// MiniMax::MiniMax(Game<GameState> game, int maxDepth) {
//     game = game;
//     maxDepth = maxDepth;
// }

// template<typename GameState>
// Game<GameState> MiniMax::runMinimax() {
//     maximize(0);
// }

// template<typename GameState>
// std::pair<Game<GameState>, int> MiniMax::maximize(int depth) {
//     if (depth == maxDepth) {
//         return game.eval();
//     }
//     Game minChild = Game(); // TODO: this is a game pointer?
//     int minUtility = std::numeric_limits<int>::max();

//     for (Game child : )
// }

// template<typename GameState>
// std::pair<Game<GameState>, int> MiniMax::minimize(int depth) {
//     if (depth == maxDepth) {
//         return game.evaluateState();
//     }
    
// }

template<typename GameState>
class MiniMax {
    public:
        MiniMax(Game<GameState> game, int maxDepth) {
            game = game;
            maxDepth = maxDepth;
        }
        Game runMinimax() {
            maximize(game, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        }

    private:
        std::pair<Game, int> minimize(Game game, int depth, int alpha, int beta) {
            if (depth == maxDepth) {
                return game.eval();
            }
            Game minChild = Game(); // TODO: game pointer?
            int minUtility = std::numeric_limits<int>::max();

            for (Game child : game.getNextPossibleMoves()) {
                std::pair<Game, int> utility = maximize(child, alpha, beta);
                if (utility.second < minUtility) {
                    minChild = utility.first;
                    minUtility = utility.second;
                }

                if (minUtility <= alpha)
                    break;
                
                if (minUtility < beta) 
                    beta = minUtility;
            }
            return std::pair<>(minChild, minUtility);
        }

        std::pair<Game, int> maximize(Game game, int depth, int alpha, int beta) {
            if (depth == maxDepth) {
               return game.evaluateState();
            }

            Game maxChild = Gam(); // TODO: game pointer?
            int maxUtility = std::numeric_limits<int>::min();

            for (Game child : game.getNextPossibleMoves()) {
                std::pair<Game, int> utility = minimize(child, alpha, beta);
                if (utility.second > maxUtility) {
                    maxChild = child;
                    maxUtility = utility.first;
                }
                if (maxUtility >= beta) 
                    break;
                if (maxUtility > alpha)
                    alpha = maxUtility;
            }
            return std::pair<>(maxChild, maxUtility);
        }
};
