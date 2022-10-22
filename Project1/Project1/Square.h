#ifndef SQUARE_H
#define SQUARE_H

// Include Classes
#include "Section.h"

// Include Packages
#include <cmath>

// Derive Classes
class Square : public Section
{
	protected:
		// Method
		char* GenerateSquares(int posX, int posY);

	public:
		// Constructor
		Square(Board b);

		// Method
		bool validate(char num, int posX, int posY);
};


#endif // !SQUARE_H



