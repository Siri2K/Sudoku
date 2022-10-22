#include "Game.h"

Game::Game(Board game_board)
{
	setBoard(game_board);
}

void Game::setBoard(Board game_board)
{
	this->game_board = game_board;
}

Board Game::getBoard() 
{
	return this->game_board;
}

void Game::setupBoard() 
{
	// Initalize Random Numbers
	srand(time(NULL));
	
	// Get Board grid & Board Size
	int size = this->getBoard().getSize();

	// Fill in numbers
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			this->getBoard().insert(rand() % 100 + 1, j, i);
		}
	}
}

void Game::clearBoard() 
{
	// Get Size & Replace all characters Game Board
	char* currBoard = this->getBoard().getGrid();
	int size = this->getBoard().getSize();

	// Replace All Numbers with '*'
	for (int i = 0; i<size*size;i++) 
	{
		if (currBoard[i] = '*')
		{
			continue;
		}
		currBoard[i] = '*';
	}

	this->getBoard().updateGrid(currBoard);
}

void Game::insertNumber(int count) 
{
	// Initalize Variables
	int number, posX, posY;

	// Inform Player on how the numbers are entered into queare
	if (count<=1) 
	{
		std::cout << "Enter number and position in the following sequence\n";
		std::cout << "'number, row position, column position' \n";
		std::cout << "'2 1 1' \n";
	}

	std::cout << "Insert : ";
	std::cin >> number >> posX >> posY;

	this->getBoard().insert(number, posX, posY);
}

void Game::stopGame() 
{
	this->clearBoard();
}