#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k) {
  std::priority_queue<int> sorted;
  for (int i = 0; i < values.size(); i++) {
    sorted.push(values[i]);
  }
  for (int i = 0; i < k - 1; i++) {
    sorted.pop();
  }
  return sorted.top();
}