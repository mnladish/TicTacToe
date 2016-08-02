#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

class TicTacToe
{
  private:
    Board newGame;
    char playerTurn;

  public:
    TicTacToe(char);
    void play();
};
#endif

