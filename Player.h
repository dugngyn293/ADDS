#ifndef PLAYER_H
#define PLAYER_H
#include <string>

#include "Move.h"

class Player {
 protected:
  std::string player_name;
  Move* player_move;

 public:
  Player();
  Player(std::string player_name);
  virtual Move* makeMove() = 0;
  std::string getName();
};

#endif