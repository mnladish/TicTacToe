/*************************************************************
** Author:: Megan Ladish
** Date: 8-2-16
** Description: This is the class declaration for the class
** TicTacToe. It defines the member variables and functions.
*************************************************************/
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

class TicTacToe
{
  private:
    Board newGame;
    char playerTurn;  //holds which player's turn it is

  public:
    TicTacToe(char);
    void play();
};
#endif

