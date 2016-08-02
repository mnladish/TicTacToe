#include <iostream>
#include "TicTacToe.hpp"

TicTacToe::TicTacToe(char player)
{
  playerTurn = player;
}

PossibleOutcomes gameStatus; //Hold status of game, win/draw/unfinished
int xCoord, yCoord;

void TicTacToe::play()
{
  do
  {
    std::cout << "Player " << playerTurn << ": please enter your move." << std::endl;
    std::cin >> xCoord >> yCoord;

    if(newGame.makeMove(xCoord, yCoord, playerTurn))
    {
      //Send move to board
      newGame.makeMove(xCoord, yCoord, playerTurn);

      //Print current board
      newGame.print();

      //Update game status
      gameStatus = newGame.gameState();

      //Switch players
      if(playerTurn == 'X')
      {
        playerTurn = 'O';
      }
      else
      {
        playerTurn = 'X';
      }
    }
    else
    {
      std::cout << "This spot is occupied." << std::endl;
    }
  }while(gameStatus == UNFINISHED);

  if(gameStatus == X_WON)
  {
    std::cout << "Congratulations Player X! You win!" << std::endl;
  }

  if(gameStatus == O_WON)
  {
    std::cout << "Congratulations Player O! You win!" << std::endl;
  }

  if(gameStatus == DRAW)
  {
    std::cout << "It's a draw! Please play again to determine a winner." << std::endl;
  }
}

int main()
{
  char firstMove;
  
  std::cout << "Please enter which player (X or O) will go first." << std::endl;

  std::cin >> firstMove;

  firstMove = toupper(firstMove);
  
  TicTacToe game1(firstMove);

  game1.play();

  return 0;
}
