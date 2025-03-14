#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H
#include "Monkey.h"
#include "Ninja.h"
#include "Paper.h"
#include "Pirate.h"
#include "Robot.h"
#include "Rock.h"
#include "Scissors.h"
#include "Zombie.h"

class MoveFactory {
 public:
  Move* moveGenerator(std::string current_move);
};

#endif