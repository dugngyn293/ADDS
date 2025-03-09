#include "Computer.h"

Computer::Computer() {
  name = "Computer";
  move = 'R';
}

std::string Computer::getName() { return "Computer"; }

char Computer::makeMove() { return 'R'; }