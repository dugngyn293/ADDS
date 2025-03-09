#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
 protected:
  char move;
  std::string name;

 public:
  virtual char makeMove() = 0;
  virtual std::string getName() = 0;
};

#endif