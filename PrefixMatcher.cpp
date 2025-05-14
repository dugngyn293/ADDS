#include "PrefixMatcher.h"

Node::Node() { routerNumber = 0; }

PrefixMatcher::PrefixMatcher() { root = new Node(); }

void PrefixMatcher::insert(std::string address, int routerNumber) {
  Node* current = root;
  for (auto c : address) {
    if (current->addresses.find(c) == current->addresses.end()) {
      current->addresses.insert({c, new Node()});
    }
    current = current->addresses.find(c)->second;
  }
  if (current->routerNumber != 0) {
    return;
  }
  current->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
  std::string result;
  Node* current = root;
  for (auto c : networkAddress) {
    if (current->addresses.find(c) == current->addresses.end()) {
      break;
    }
    result = result + c;
    current = current->addresses.find(c)->second;
  }
  return current->routerNumber;
}