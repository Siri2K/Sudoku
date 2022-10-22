#ifndef COLUMN_H
#define COLUMN_H

// Include Classes
#include "Section.h"

// Derive Classes
class Column : public Section
{
	public:
		// Constructor
		Column(Board b);

		// Method
		bool validate(char num, int posX, int posY);
};

#endif // !COLUMN_H