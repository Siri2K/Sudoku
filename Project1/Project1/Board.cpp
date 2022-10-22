#include "Board.h"

// Constructors
Board::Board() : Board(9){}

Board::Board(int size) 
{
	this->setSize(size);
	this->setGuess(size);
	this->setGrid(size);
}

Board::Board(Board& board)
{
	this->size = board.getSize();
	this->guess = board.getGuess();
	this->grid = board.getGrid();
}

void Board::setSize(int size)
{
	// Check if Size is adquate for Sudoku
	long double size_check = sqrt(size) - floor(sqrt(size));
	while (size_check != 0)
	{
		// Update Size
		std::cout << "The size of the sudoku puzzle is not adequate\n";
		std::cout << "Please choose a new sudoku size : ";
		std::cin >> size;
		std::cout << "\n";
	}

	this->size = size;

}

void Board::setGuess(int size)
{
	// Check if Size is adquate for Sudoku
	long double size_check = sqrt(size) - floor(sqrt(size));
	while (size_check != 0)
	{
		// Update Size
		std::cout << "The size of the sudoku puzzle is not adequate\n";
		std::cout << "Please choose a new sudoku size : ";
		std::cin >> size;
		std::cout << "\n";
	}

	// Make the array of guesses
	char* guess_numbers = new char[size];

	for (int i = 1; i<=size; i++) 
	{
		guess_numbers[i - 1] = i;
	}
	this->guess = guess_numbers;
}

void Board::setGrid(int size)
{
	// Check if Size is adquate for Sudoku
	long double size_check = sqrt(size) - floor(sqrt(size));
	while (size_check != 0)
	{
		// Update Size
		std::cout << "The size of the sudoku puzzle is not adequate\n";
		std::cout << "Please choose a new sudoku size : ";
		std::cin >> size;
		std::cout << "\n";
	}

	// Make Full Grids
	char* startGrid = new char[size * size];
	for (int i = 0; i<size*size; i++) 
	{
		startGrid[i] = '*';
	}
	this->grid = startGrid;
}

int Board::getSize() { return this->size; }

char* Board::getGuess() { return this->guess; }

char* Board::getGrid() { return this->grid; }


void Board::display()
{
	// Setup Board 
	char* grid = this->getGrid();
	for (int i = 0; i < this->getSize() * this->getSize(); i++)
	{
		if (i > 0 && i % this->getSize() == 0)
		{
			std::cout << "\n";
		}
		std::cout << grid[i];
	}
	std::cout << "\n";
	std::cout << "---------------------\n";
	std::cout << "---------------------\n";
}

void Board::insert(char num, int posX, int posY)
{
	// Get Grid
	char* grid = this->getGrid();

	// Update Grid
	if (this->validate(num,posX,posY))
	{
		grid[(posX - 1) + size * (posY - 1)] = num;
		this->updateGrid(grid);
	}
}

bool Board::validate(char num, int posX, int posY)
{
	// Make Temporary Copy & Initialize Sudoku Parameters
	Board temp = *this;
	Square square(temp);
	Column column(temp);
	Row row(temp);
	
	// Confirm Validation
	bool row_validation = row.validate(num, posX, posY);
	bool column_validation = column.validate(num, posX, posY);
	bool square_validation = square.validate(num, posX, posY);

	if ((row_validation && column_validation && square_validation) == true)
	{
		return true;
	}
	return false;
}

void Board::updateGrid(char* grid) 
{
	this->grid = grid;
}