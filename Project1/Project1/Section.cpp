#include "Section.h"

void Section::setBoard(Board b) { this->board = b; }

void Section::setSize(int size) { this->size = size; }

Board Section::getBoard() { return this->board; }

int Section::getSize() { return this->size; }