#ifndef BOARD_H
#define BOARD_H

// Include Other Classes
#include "Square.h"
#include "Column.h"
#include "Row.h"

// Include Packages
#include <iostream>
#include <cmath>

// Setup Class 
class Board
{
	private:
		// Instances
		int size; // Size Of grid rows and columns
		char* guess; // Heap of Guesses allowed
		char* grid; // Full Sudoku Grid

	protected:

	public:
		// Constructor
		Board(); // Default board
		Board(int size); // Variable Board
		Board(Board& board); // Copy board

		// Setter & Getter Functions
		void setSize(int size);
		void setGuess(int size);
		void setGrid(int size);

		int getSize();
		char* getGuess();
		char* getGrid();

		// Methods
		void display(); // Display Current Board
		void insert(char num, int posX, int posY); // Enter Number in Sudoku Puzzle
		bool validate(char num, int posX, int posY); // Validate using Row, Square and Column Classes
		void updateGrid(char* grid);

		void test();
};

#endif // !BOARD_H



