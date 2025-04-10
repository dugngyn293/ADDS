#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
  for (int i = list.size() - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (list.at(j) > list.at(j + 1)) {
        std::swap(list.at(j), list.at(j + 1));
      }
    }
  }
  return list;
}