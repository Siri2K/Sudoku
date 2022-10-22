#include "Column.h"

Column::Column(Board b) 
{
	this->setBoard(b);
	this->setSize(b.getSize());
}

bool Column::validate(char num, int posX, int posY)
{
	// Setup the Variables
	int size = this->getSize();

	// Check if position is within grid
	if ((posX>0 && posX<=size) && (posY > 0 && posY <= size))
	{
		std::cout << "Error: Desired Position is not in Grid\n";
		return false;
	}

	// Check if Number is allowed
	char* guess = this->getBoard().getGuess();
	for (int i = 1; i <= size; i++)
	{
		char num_char = guess[i - 1];
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

	// Create Column & Validate
	char* column = new char[size];
	char* grid = this->getBoard().getGrid();

	for (int i = 0; i < size; i++)
	{
		column[i] = grid[i + size * (i - 1)];

		if (column[i] == num)
		{
			std::cout << "Error: " << num << " is already in the same column";
			return false;
		}
	}
	return true;
}