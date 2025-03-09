#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
  char move1 = player1->makeMove();
  char move2 = player2->makeMove();
  if (player1->getName() != "Computer") {
    if (move1 == 'R') {
      return nullptr;
    } else if (move1 == 'P') {
      return player1;
    } else {
      return player2;
    }
  } else {
    if (move2 == 'R') {
      return nullptr;
    } else if (move2 == 'P') {
      return player2;
    } else {
      return player1;
    }
  }
}