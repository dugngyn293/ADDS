#ifndef Node_H
#define Node_H

class Node {
 private:
  int data;
  Node* link;

 public:
  Node();
  friend class LinkedList;
  Node(int data, Node* link);
};

#endif