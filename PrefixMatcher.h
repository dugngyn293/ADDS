#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>
#include <unordered_map>

class Node {
 private:
  int routerNumber;
  std::unordered_map<char, Node*> addresses;
  friend class PrefixMatcher;

 public:
  Node();
};
class PrefixMatcher {
 private:
  Node* root;

 public:
  PrefixMatcher();
  int selectRouter(std::string networkAddress);
  void insert(std::string address, int routerNumber);
};

#endif