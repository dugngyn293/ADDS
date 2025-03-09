#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"

class Human : public Player {
 public:
  char makeMove() override;
  std::string getName() override;
  Human(std::string name);
  Human();
};

#endif