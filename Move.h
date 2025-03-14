#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <vector>

class Move {
 protected:
  std::string move_name;
  std::vector<std::string> win_against_moves;

 public:
  Move(std::string move_name, std::vector<std::string> moves);
  std::string getName();
  std::vector<std::string> getWinAgainstMoves();
};

#endif