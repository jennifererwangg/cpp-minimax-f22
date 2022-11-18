#include "../minimax-lib/game.h"
#include "../minimax-lib/minimax.h"

using namespace std;

class TicTacToe : Game<char[3][3]> {
    public:
        TicTacToe() {
            currentState = {{"_", "_", "_"}, {"_", "_", "_"}, {"_", "_", "_"}};
        }

    /**
    * Defined by the user: 
    * Given a current game state, returns a vector of the possible next configurations for the game.
    */
    std::vector<char[3][3]> getNextPossibleMoves(char[3][3] state, bool isUserMove) {
        std::vector<char[3][3]> nextStates;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; i < 3; j++) {
                if(state[i][j] == "_") {
                    char[3][3] newState = std::make_shared<char[3][3]>();
                    std::copy(std::begin(state), std::end(state), std::begin(newState));

                    newState[i][j] = isUserMove ? "o" : "x";

                    nextStates.pushBack(newState);
                }
            }
        }

        return nextStates;
    };

    /**
        * Defined by the user: 
        * Given a game state, returns -1 is it is not done, 0 if it is tied, 
        * 1 if it is a winning config for x, 2 if it is a winning config for o.
        */
    int isDone(char[3][3] state) {
        bool isFull = true;
        char[] xWinning = {"x", "x", "x"};
        char[] oWinning = {"o", "o", "o"};
        
        // Check rows
        for(int i = 0; i < 3; i++) {
            if(std::equal(std::begin(state[i]), std::end(state[i]), std::begin(xWinning))) {
                return 1;
            }
            if(std::equal(std::begin(state[i]), std::end(state[i]), std::begin(oWinning))) {
                return 2;
            }
        }

        // Check columns
        for(int i = 0; i < 3; i++) {
            char[] col = {state[i][0], state[i][1], state[i][2]};

            if(std::equal(std::begin(col), std::end(col), std::begin(xWinning))) {
                return 1;
            }
            if(std::equal(std::begin(col), std::end(col), std::begin(oWinning))) {
                return 2;
            }
        }

        // Check diagnoals
        char[] diag1 = {state[0][0], state[1][1], state[2][2]};
        char[] diag2 = {state[2][0], state[1][1], state[0][2]};

        if(std::equal(std::begin(diag1), std::end(diag1), std::begin(xWinning))) {
            return 1;
        }
        if(std::equal(std::begin(diag1), std::end(diag1), std::begin(oWinning))) {
            return 1;
        }
        if(std::equal(std::begin(diag2), std::end(diag2), std::begin(xWinning))) {
            return 2;
        }
        if(std::equal(std::begin(diag2), std::end(diag2), std::begin(oWinning))) {
            return 2;
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(state[i][j] == "_") {
                    return -1;
                }
            }
        }

        return 0;
    }

    /**
    * Defined by the user: 
    * Given a game state, evaluates its utility based on user-defined heuristics.
    */
    int evaluateState(char[3][3] state) {
        int done = isDone(state);

        if done > 0 {
            return 1;
        }

        return 0;
    }

    /**
        * Defined by the user: 
        * Prints instructions for user to enter their next move, processes the user response, 
        * and returns the next game state based on their response.
        */
    char[3][3] getNextUserMove() {
        std::string move;
        std::string cols = "ABC";
        std::string rows = "123";

        std::cout << "Please enter the grid spot (eg A2) that you want to place your o at: ";
        std::cin >> move;

        int col = cols.find(move[0]);
        int row = rows.find(move[1]);

        while (col == std::string::npos || row == std::string::npos) {
            std::cout << "Invalid input, please enter the grid spot (eg A2) that you want to place your o at: ";
            std::cin >> move;

            col = cols.find(move[0]);
            row = rows.find(move[1]);
        }

        char[3][3] newState = std::make_shared<char[3][3]>();
        std::copy(std::begin(state), std::end(state), std::begin(newState));

        newState[row][col] = "o";

        return newState;
    }

    /**
        * Defined by the user: 
        * Prints the given game state.
        */
    void printGameState(char[3][3] state) {
        printf("A B C");
        for(int i = 0; i < 3; i++) {
            printf("\n %d ", i);
            for(int j = 0; j < 3; j++) {
                printf("%s ", state[i][j]);
            }
        }
    }
}


int main() {
    // instantiate TicTacToe instance

    // tictactoe.play()
}