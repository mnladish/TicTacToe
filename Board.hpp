/**********************************************************************
** Author: Megan Ladish
** Date: 8-2-16
** Description: This is the class declaration (interface) for the class
** Board. It defines the member variables and functions.
**********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

enum PossibleOutcomes{X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
  private:
    static const int ROWS = 3;
    static const int COLS = 3;
    char gameBoard[ROWS][COLS];

  public:
    Board();
    bool makeMove(int, int, char);  //assigns user's move to gameboard
    PossibleOutcomes gameState();   //returns outcome of game after move
    void print();                   //prints current board to screen

};
#endif
