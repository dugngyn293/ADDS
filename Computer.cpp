#include "Computer.h"

#include "Rock.h"

Move* Computer::makeMove() { return new Rock(); }

Computer::Computer() : Player("Computer") {}