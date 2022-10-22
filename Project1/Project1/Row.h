#ifndef ROW_H
#define ROW_H

// Include Classes
#include "Section.h"

// Derive Class
class Row : public Section
{
	public:
		// Constructor
		Row(Board b);
	
		// Method
		bool validate(char num, int posX, int posY);
};

#endif // !ROW_H
