#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
  Move* move1 = player1->makeMove();
  Move* move2 = player2->makeMove();
  if (move2->getName() == move1->getName()) {
    return nullptr;
  }
  std::vector<std::string>::iterator it;
  for (const std::string& it : move1->getWinAgainstMoves()) {
    if (move2->getName() == it) {
      return player1;
    }
  }
  return player2;
}