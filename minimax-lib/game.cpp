#include <random>
#include "minimax.cpp"

class Game {
    public:
        Game(GameState initialState) {
            /* user provides:
             * The initial state
             * GetNextPossibleMoves function
             * isDone function
             * eval() function to a state (the heuristic)
             * getUserNextMove() for CLI
             * printGameState() for CLI
             */
        }

        // make all the function definitions here

        void play(int maxDepth = 1) {
            int turn = startingTurn(); // 0 = user turn, 1 = minimax turn
            while (!isDone(currentState)) {
                printGameState(currentState);
                if (turn == 0) {
                    currentState = getUserNextMove();
                } else {
                    Minimax AIPlayer = new Minimax(*this, maxDepth);
                    currentState = AIPlayer.runMinimax();
                }
                turn = !turn;
            }
        }

    private: 
        int startingTurn() {
            using my_engine = std::default_random_engine;
            using my_distribution = std::uniform_int_distribution<>;
            my_engine re {};
            my_distribution generate_turn {0,1}; 
            return generate_turn(re);
        }
}