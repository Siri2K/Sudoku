#include "Square.h"

Square::Square(Board b)
{
	this->setBoard(b);
	this->setSize(b.getSize());
}

char* Square::GenerateSquares(int posX,int posY)
{
	// Setup the Variables
	int size = this->getSize();

	// Check if position is within grid
	if ((posX > 0 && posX <= size) && (posY > 0 && posY <= size))
	{
		std::cout << "Error: Desired Position is not in Grid\n";
		return this->getBoard().getGrid();
	}

	// Make Grid
	int dimension = sqrt(size);
	int start_pos[2] = { posX + size * posY, posX + size * (posY - 1) };
	char* square = new char[size];
	char* grid = this->getBoard().getGrid();

	int j = 0;
	while (j < size) 
	{
		if (j % 2 == 0)
		{
			for (int i = start_pos[1]; i < start_pos[1] + dimension; i++)
			{
				square[j] = grid[i];
			}
			j++;
		}
		else if (j % 2 == 1)
		{
			for (int i = start_pos[0]; i > start_pos[0] - dimension; i--)
			{
				square[j] = grid[i];
			}
			j++;
		}
	}
	
	return square;
}

bool Square::validate(char num, int posX, int posY)
{
	// Setup the Variables
	int size = this->getSize();

	// Check if position is within grid
	if ((posX > 0 && posX <= size) && (posY > 0 && posY <= size))
	{
		std::cout << "Error: Desired Position is not in Grid\n";
		return false;
	}

	// Check if Number is allowed
	char* guess = this->getBoard().getGuess();
	for (int i = 1; i <= size; i++)
	{
		char num_char = i;
		if (num == num_char)
		{
			break;
		}

		// Last Chance
		if (i == size && num != num_char)
		{
			std::cout << "Error: Desired Number is not in Allowed in Grid\n";
			return false;
		}
	}
	delete guess;

	// Make & Validate Square
	char*square = this->GenerateSquares(posX,posY);
	
	for (int i = 0; i < size; i++)
	{
		if (square[i] == num) 
		{
			std::cout << "Error: " << num << " is already in the same square";
			return false;
		}
	}
	return true;
}