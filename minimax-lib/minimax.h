#include "minimax-lib/game.h"
#include <utility>
#include <memory>

template<typename GameState>
class MiniMax {
    public:
        MiniMax(Game<GameState> game, int maxDepth);
        Game runMinimax();

    private:
        // std::shared_ptr<Game> game; // TODO: make Game a shared pointer
        Game game;

        std::pair<Game, int> minimize(Game game, int depth, int alpha, int beta);

        std::pair<Game, int> maximize(Game game, int depth, int alpha, int beta);
};
