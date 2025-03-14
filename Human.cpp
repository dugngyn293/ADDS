#include "Human.h"

#include <iostream>

Human::Human() : Human("Human") {}

Human::Human(std::string human_name) : Player(human_name) {}

Move* Human::makeMove() {
  std::string current_move;
  std::cout << "Enter move: ";
  std::cin >> current_move;
  MoveFactory factory;
  return factory.moveGenerator(current_move);
}
