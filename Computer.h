#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {
 public:
  Computer(string name = "Computer");
  string getName() override;
  char makeMove() override;

 private:
  string name;
};

#endif