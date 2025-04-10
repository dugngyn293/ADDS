#include <iostream>
#include <sstream>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
  std::stringstream ss;
  std::string nums;
  std::getline(std::cin, nums);
  ss << nums;
  std::vector<int> list;
  int num = 0;
  while (ss >> num) {
    list.push_back(num);
  }

  QuickSort quick_sort;
  list = quick_sort.sort(list);
  RecursiveBinarySearch search;
  bool check = search.search(list, 1);
  if (check) {
    std::cout << "true" << " ";
  } else {
    std::cout << "false" << " ";
  }
  for (auto i = list.begin(); i != list.end(); i++) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  return 0;
}