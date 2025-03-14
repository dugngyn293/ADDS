#include "MoveFactory.h"

Move* MoveFactory::moveGenerator(std::string current_move) {
  if (current_move == "Rock") {
    return new Rock();
  } else if (current_move == "Paper") {
    return new Paper();
  } else if (current_move == "Scissors") {
    return new Scissors();
  } else if (current_move == "Monkey") {
    return new Monkey();
  } else if (current_move == "Pirate") {
    return new Pirate();
  } else if (current_move == "Zombie") {
    return new Zombie();
  } else if (current_move == "Robot") {
    return new Robot();
  } else if (current_move == "Ninja") {
    return new Ninja();
  }
  return nullptr;
}