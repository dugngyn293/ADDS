#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
using namespace std;

class Human : public Player {
 public:
  Human(string name = "Human");
  char makeMove() override;
  string getName() override;

 private:
  string name;
};

#endif