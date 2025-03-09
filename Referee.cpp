#include "Referee.h"

#include "Computer.h"
#include "Human.h"
#include "Player.h"
using namespace std;
#include <iostream>
int main() {
  Human human("Khanh");
  Computer comp;
  Referee ref;
  Player* winner = ref.refGame(&human, &comp);
  if (winner == nullptr) {
    cout << "It's a Tie." << endl;
  } else {
    cout << winner->getName() << " Wins." << endl;
  }
  return 0;
}