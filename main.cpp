#include <iostream>

#include "Reverser.h"
#include "Truckloads.h"

int main() {
  // first problem
  Truckloads truck1;
  std::cout << truck1.numTrucks(15, 1) << std::endl;
  // second problem
  Reverser r;
  std::cout << r.reverseString("Adam") << std::endl;
  std::cout << r.reverseDigit(10) << std::endl;
  return 0;
}