#include "Node.h"

#include <iostream>
using namespace std;

Node::Node(int data, Node* link) {
  this->data = data;
  this->link = link;
}
Node::Node() {
  this->data = 0;
  this->link = nullptr;
}