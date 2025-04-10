#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H
#include <vector>

class RecursiveBinarySearch {
 public:
  bool search(std::vector<int> list, int key);

 private:
  bool recursiveBinarySearch(std::vector<int>& list, int key, int start,
                             int end);
};

#endif