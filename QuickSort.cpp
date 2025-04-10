#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list) {
  quickSort(list, 0, list.size() - 1);
  return list;
}

void QuickSort::quickSort(std::vector<int>& list, int start, int end) {
  if (start >= end) {
    return;
  }

  int pivot;
  if (end - start >= 2) {
    pivot = list.at(start + 2);
    std::swap(list.at(start + 2), list.at(end));
  } else {
    pivot = list.at(end);
  }
  int pivot_index = start;
  for (int i = start; i < end; i++) {
    if (list.at(i) < pivot) {
      std::swap(list.at(i), list.at(pivot_index));
      pivot_index++;
    }
  }
  std::swap(list.at(pivot_index), list.at(end));

  quickSort(list, start, pivot_index - 1);
  quickSort(list, pivot_index + 1, end);
}