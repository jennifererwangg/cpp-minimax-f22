#pragma once

#include <memory>
#include <string>
#include <vector>

namespace minimax {
namespace core {

using uint = unsigned int;

/**
 * \brief Represent game state.
 * 
 * This class is used to represent the state of a game being implemented. It is a base class
 * with virtual functions, and all game implementations should inherit from it.
 * 
 * It holds information about:
 * The current board state
 * Whose turn it is
 * Any additional data required to determine who is winning/what point the game is at
 */
class GameState {
public:

  explicit GameState();
  virtual ~GameState() {}

  /**
   * Used by the Minimax Solver
   */
  
  /**
   * \brief getNextState(): Generate all possible next moves.
   * This function creates the search space for the next iteration of the minimax algorithm.
   * From the current board state, it should generate all of the next possible moves that 
   * could be made by the current player.
   * Eg. for tic tac toe, then we would generate all of the next states by placing an X in 
   * all of the empty spots of the board.
   * 
   * \return A vector of all the possible next game states
   */
  virtual std::vector<std::shared_ptr<GameState>> getNextState();

  /**
   * \brief evalHeuristics(): Determinte the utility of a state.
   * This function decides how favorable the current board state is for the player. The
   * higher the number, the more favorable the state is for the current player. This can 
   * be as simple as (for example, in checkers) counting the number of pieces on the board
   * for the current player, or can be a complex algorithm evaluating many different factors
   * for how favorable the current state is for the player.
   * 
   * \return an integer representing how favorable the board state is for the current player.
   */
  virtual int evalHeuristics();

  /**
   * \brief isDone(): Is the game done?
   * This function evaluates whether or not the game is over. It can do this by checking if 
   * the board is full, if there are no moves left for a player, or some other option indicating
   * whether or not the game has finished.
   * 
   * \return true if the game is over, false if not
   */
  virtual bool isDone();

  /**
   * Used by players
   */
  
  /**
   * \brief printState(): Print the game board.
   * Prints the game board along with any other information about the game that should be seen
   * by the player.
   */
  virtual void printState();
  
  /**
   * \brief printWinner(): Print the winner of a completed game.
   * Prints the winner of the game, only called when the game is done.
   */
  virtual void printWinner();
<<<<<<< HEAD

  /**
   * \brief processUserInput(): Prompt for and process user input.
   * Interacts with the user in order to take in and then process input. Should prompt the user for
   * input, and then make a move accordingly on the game board.
   */
=======
  // prompt for, take in, and process user input
>>>>>>> 1b6e7a5c9343c57851ab09303183f49e0576f60b
  virtual void processUserInput();

protected:
private:
};

}  // namespace core
}  // namespace minimax