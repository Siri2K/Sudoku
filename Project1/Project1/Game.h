#ifndef GAME_H
#define GAME_H

// Include Classes
#include "Board.h"

// Include Packages
#include <stdlib.h>
#include <time.h>

// Derive Class
class Game
{
	private:
		// Instant
		Board game_board;

	public:
		// Constructor
		Game(Board game_board);

		// Setter and Getter
		void setBoard(Board game_board);
		Board getBoard();

		// Methods
		void setupBoard(); // Place Random Numbers within Board
		void clearBoard(); // Empty Board and Reset it
		void insertNumber(int count); // Player fills up the board
		void stopGame(); // End Game 
};

#endif // !GAME_H



