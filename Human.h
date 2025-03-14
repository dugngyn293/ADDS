#ifndef HUMAN_H
#define HUMAN_H
#include "MoveFactory.h"
#include "Player.h"

class Human : public Player {
 public:
  Human();
  Human(std::string human_name);
  Move* makeMove();
};

#endif