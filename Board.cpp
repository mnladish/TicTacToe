/******************************************************************
** Author: Megan Ladish
** Date: 8-2-16
** Description: The is the function definition (implementation)
** for the class Board. It starts with a cleared game board, tests
** for all winning combos, draw, and unfinished games, and it 
** prints the game board to the screen.
******************************************************************/
#include "Board.hpp"
#include <iostream>

Board::Board()
{ 
  //initializes game board to be empty
  for (int i=0; i < ROWS; i++)
  {  
    for (int j=0; j < COLS; j++)
    {
      gameBoard[i][j] = '.';  
    }
  }
}

bool Board::makeMove(int xVal, int yVal, char playerID)
{ 
  //record move only if space is empty
  if (gameBoard[xVal][yVal] == '.')
  {
    gameBoard[xVal][yVal] = playerID;
    return true;
  }
  else
  {
    return false;
  }
}

PossibleOutcomes Board::gameState()
{
  //test for winning combinations
  char winner = '.';
  //first row
  if (gameBoard[0][0] != '.' 
      && gameBoard[0][0] == gameBoard[0][1] 
      && gameBoard[0][0] == gameBoard[0][2])
  {
    winner = gameBoard[0][0];
  }
  //second row
  if (gameBoard[1][0] != '.' 
      && gameBoard[1][0] == gameBoard[1][1] 
      && gameBoard[1][0] == gameBoard[1][2])
  {
    winner = gameBoard[1][0];
  }
  //third row
  if (gameBoard[2][0] != '.' 
      && gameBoard[2][0] == gameBoard[2][1] 
      && gameBoard[2][0] == gameBoard[2][2])
  {
    winner = gameBoard[2][0];
  }
  //first column
  if (gameBoard[0][0] != '.' 
      && gameBoard[1][0] == gameBoard[0][0] 
      && gameBoard[2][0] == gameBoard[0][0])
  {
    winner = gameBoard[0][0];
  }
  //second column
  if (gameBoard[0][1] != '.' 
      && gameBoard[1][1] == gameBoard[0][1] 
      && gameBoard[2][1] == gameBoard[0][1])
  {
    winner = gameBoard[0][1];
  }
  //third column
  if (gameBoard[0][2] != '.' 
      && gameBoard[1][2] == gameBoard[0][2] 
      && gameBoard[2][2] == gameBoard[0][2])
  {
    winner = gameBoard[0][2];
  }
  //first diagonal
  if (gameBoard[0][0] != '.' 
      && gameBoard[1][1] == gameBoard[0][0] 
      && gameBoard[2][2] == gameBoard[0][0])
  {
    winner = gameBoard[0][0];
  }
  //second diagonal
  if (gameBoard[2][0] != '.' 
      && gameBoard[1][1] == gameBoard[2][0] 
      && gameBoard[0][2] == gameBoard[2][0])
  {
    winner = gameBoard[2][0];
  }
  
  if (winner == 'X')
    return X_WON;

  if (winner == 'O')
    return O_WON;

  //check for draw
  for (int i=0; i < ROWS; i++)
  {  
    for (int j=0; j < COLS; j++)
    {
      if (gameBoard[i][j] == '.')
      {
        return UNFINISHED;
      }
    }
  }
  return DRAW;
}

void Board::print()
{
  //prints current game board
  std::cout << "  0 1 2" << std::endl;
  std::cout << "0 " << gameBoard[0][0] << " " << gameBoard[0][1] << " " << gameBoard[0][2] << std::endl;
  std::cout << "1 " << gameBoard[1][0] << " " << gameBoard[1][1] << " " << gameBoard[1][2] << std::endl;
  std::cout << "2 " << gameBoard[2][0] << " " << gameBoard[2][1] << " " << gameBoard[2][2] << std::endl;
}
