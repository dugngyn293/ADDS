#include "Reverser.h"

#include <cmath>

int Reverser::reverseDigit(int value) {
  if (value < 0) {
    return -1;
  }
  if (value < 10) {
    return value;
  } else {
    int reverse_num = 0;
    int power = 0;
    int sub_value = value;
    while (sub_value > 10) {
      power++;
      sub_value = (sub_value - sub_value % 10) / 10;
    }
    reverse_num = reverse_num + value % 10;
    int new_value = (value - value % 10) / 10;
    return reverse_num * pow(10, power) + reverseDigit(new_value);
  }
}

std::string Reverser::reverseString(std::string characters) {
  int strlen = characters.length();
  if (strlen <= 1) {
    return characters;
  } else {
    return characters[strlen - 1] +
           reverseString(characters.substr(0, strlen - 1));
  }
}
