#include "Computer.h"

Computer::Computer(string name) : name(name) {}

char Computer::makeMove() { return 'R'; }

string Computer::getName() { return name; }