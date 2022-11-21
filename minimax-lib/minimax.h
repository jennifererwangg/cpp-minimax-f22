#pragma once

#include "game.h"
#include <utility>
#include <memory>
#include <vector>

template <template <typename> class Game,
          typename GameState>
// template <template<class> class Game>
class Minimax {

    public:
    Game<GameState> runMinimax(Game<GameState> game, int maxDepth) {
        maximize(game, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), maxDepth);
    }

    private:
    typename std::pair<Game<GameState>, int> minimize(Game<GameState> game, int depth, int alpha, int beta, int maxDepth) {
        if (depth == maxDepth) {
            return game.eval();
        }
        Game<GameState> minChild; // TODO: game pointer?
        int minUtility = std::numeric_limits<int>::max();

        for (Game<GameState> child : game.getNextPossibleMoves()) {
            typename std::pair<Game<GameState>, int> utility = maximize(child, alpha, beta, maxDepth);
            if (utility.second < minUtility) {
                minChild = utility.first;
                minUtility = utility.second;
            }
            if (minUtility <= alpha)
                break;
            
            if (minUtility < beta) 
                beta = minUtility;
        }
        return typename std::pair<Game<GameState>, int>(minChild, minUtility);
    }

    std::pair<Game<GameState>, int> maximize(Game<GameState> game, int depth, int alpha, int beta, int maxDepth) {
        if (depth == maxDepth) {
            return game.evaluateState();
        }

        Game<GameState> maxChild; // TODO: game pointer?
        int maxUtility = std::numeric_limits<int>::min();

        for (Game<GameState> child : game.getNextPossibleMoves()) {
            std::pair<Game<GameState>, int> utility = minimize(child, alpha, beta, maxDepth);
            if (utility.second > maxUtility) {
                maxChild = child;
                maxUtility = utility.first;
            }
            if (maxUtility >= beta) 
                break;
            if (maxUtility > alpha)
                alpha = maxUtility;
        }
        return typename std::pair<Game<GameState>, int>(maxChild, maxUtility);
    }
};

// template<typename GameState>
// class MiniMax {
//     public:
//         MiniMax(Game<GameState> _game, int _maxDepth) {
//             game = _game;
//             maxDepth = _maxDepth;
//         }

//         Game<GameState> runMinimax() {
//             maximize(game, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
//         }

//     private:
//         Game<GameState> game;
//         int maxDepth;

//         std::pair<Game<GameState>, int> minimize(Game<GameState> game, int depth, int alpha, int beta) {
//             if (depth == maxDepth) {
//                 return game.eval();
//             }
//             Game<GameState> minChild; // TODO: game pointer?
//             int minUtility = std::numeric_limits<int>::max();

//             for (Game<GameState> child : game.getNextPossibleMoves()) {
//                 std::pair<Game<GameState>, int> utility = maximize(child, alpha, beta);
//                 if (utility.second < minUtility) {
//                     minChild = utility.first;
//                     minUtility = utility.second;
//                 }
//                 if (minUtility <= alpha)
//                     break;
                
//                 if (minUtility < beta) 
//                     beta = minUtility;
//             }
//             return std::pair<Game<GameState>, int>(minChild, minUtility);
//         }

//         std::pair<Game<GameState>, int> maximize(Game<GameState> game, int depth, int alpha, int beta) {
//             if (depth == maxDepth) {
//                return game.evaluateState();
//             }

//             Game<GameState> maxChild = Game(); // TODO: game pointer?
//             int maxUtility = std::numeric_limits<int>::min();

//             for (Game<GameState> child : game.getNextPossibleMoves()) {
//                 std::pair<Game<GameState>, int> utility = minimize(child, alpha, beta);
//                 if (utility.second > maxUtility) {
//                     maxChild = child;
//                     maxUtility = utility.first;
//                 }
//                 if (maxUtility >= beta) 
//                     break;
//                 if (maxUtility > alpha)
//                     alpha = maxUtility;
//             }
//             return std::pair<Game<GameState>, int>(maxChild, maxUtility);
//         }
// };
