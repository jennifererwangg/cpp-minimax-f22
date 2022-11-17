#pragma once

template<typename GameState>
class Game {
    public:
        Game() {};

        ~Game() = default;

        /**
         * Defined by the user: 
         * Given a current game state, returns a vector of the possible next configurations for the game.
         */
        virtual std::vector<GameState> getNextPossibleMoves(GameState state, bool isUserMove) = 0;

        /**
         * Defined by the user: 
         * Given a game state, returns -1 is it is not done, 0 if it is tied, 1 if it is a winning config.
         */
        virtual int isDone(GameState state) = 0;

        /**
         * Defined by the user: 
         * Given a game state, evaluates its utility based on user-defined heuristics.
         */
        virtual int evaluateState(GameState state) = 0;

        /**
         * Defined by the user: 
         * Prints instructions for user to enter their next move, processes the user response, 
         * and returns the next game state based on their response.
         */
        virtual GameState getNextUserMove() = 0;

        /**
         * Defined by the user: 
         * Prints the given game state.
         */
        virtual void printGameState(GameState state) = 0;

        /** 
         * Generic function that plays the game:
            * Prints the current game state
            * Gets the next user move
            * Gets the next AI move
            * Checks if the game is done and if it is, says the winner 
            * Repeat
        */
        void play();

    private:
        GameState currentState;
}