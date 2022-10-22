#ifndef SECTION_H
#define SECTION_H

// Include Classes
#include "Board.h"

// Deriva Class
class Section
{
	private:
		// Instances
		Board board;
		int size;

	public:
		// Virtual Method
		virtual bool validate(char num, int posX, int posY) = 0;

		// Method
		void setBoard(Board b);
		void setSize(int size);

		Board getBoard();
		int getSize();
};


#endif // !SECTION_H


