#include "BigNumCalc.h"

#include <cmath>

BigNumCalc::BigNumCalc() {}

BigNumCalc::~BigNumCalc() {}

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
  std::list<int> big_num;
  for (auto &i : numString) {
    big_num.push_back(i - '0');
  }
  return big_num;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  int carry = 0;
  while (!num1.empty() || !num2.empty() || carry != 0) {
    int sum = carry;
    if (!num1.empty()) {
      sum = sum + num1.back();
      num1.pop_back();
    }
    if (!num2.empty()) {
      sum = sum + num2.back();
      num2.pop_back();
    }
    carry = sum / 10;
    result.push_front(sum % 10);
  }
  return result;
}
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  int borrow = 0;
  while (!num1.empty() || !num2.empty()) {
    int diff = borrow;
    if (!num1.empty()) {
      diff = diff + num1.back();
      num1.pop_back();
    }
    if (!num2.empty()) {
      diff = diff - num2.back();
      num2.pop_back();
    }
    if (diff < 0) {
      diff = diff + 10;
      borrow = -1;
    } else {
      borrow = 0;
    }
    result.push_front(diff);
  }
  while (!result.empty() && result.front() == 0) {
    result.pop_front();
  }
  return result;
}
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
  int last_digit_num2 = num2.back();
  num2.pop_back();
  std::list<int> result;
  int carry = 0;
  while (!num1.empty() || carry != 0) {
    int product = carry;
    if (!num1.empty()) {
      product = product + last_digit_num2 * num1.back();
      num1.pop_back();
    }
    carry = product / 10;
    result.push_front(product % 10);
  }
  return result;
}