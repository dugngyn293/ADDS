#include "LinkedList.h"

#include <iostream>
#include <limits>

LinkedList::LinkedList() { head = nullptr; }

LinkedList::LinkedList(int* array, int len) {
  head = new Node(array[0], nullptr);
  Node* current_node = head;
  for (int i = 1; i < len; i++) {
    Node* new_node = new Node(array[i], nullptr);
    current_node->link = new_node;
    current_node = current_node->link;
  }
}

LinkedList::~LinkedList() {
  while (head != nullptr) {
    deletePosition(1);
  }
}

void LinkedList::insertPosition(int pos, int newNum) {
  if (pos <= 1 || head == nullptr) {
    Node* new_node = new Node(newNum, head);
    head = new_node;
    return;
  }

  Node* previous_node = head;
  for (int i = 1; i < pos - 1; i++) {
    if (previous_node->link == nullptr) {
      previous_node->link = new Node(newNum, nullptr);
      return;
    } else {
      previous_node = previous_node->link;
    }
  }
  Node* new_node = new Node(newNum, previous_node->link);
  previous_node->link = new_node;
}

bool LinkedList::deletePosition(int pos) {
  if (head == nullptr) {
    return false;
  }
  if (pos < 1) {
    return false;
  }
  if (pos == 1) {
    Node* temp = head;
    head = head->link;
    delete temp;
    return true;
  }
  Node* previous_node = head;
  for (int i = 1; i < pos - 1; i++) {
    if (previous_node->link == nullptr) {
      return false;
    } else {
      previous_node = previous_node->link;
    }
  }
  Node* target_node = previous_node->link;
  previous_node->link = target_node->link;
  delete target_node;
  return true;
}

int LinkedList::get(int pos) {
  if (head == nullptr) {
    return std::numeric_limits<int>::max();
  }
  if (pos < 1) {
    return std::numeric_limits<int>::max();
  }
  Node* current_node = head;
  for (int i = 1; i <= pos - 1; i++) {
    if (current_node->link == nullptr) {
      return std::numeric_limits<int>::max();
    } else {
      current_node = current_node->link;
    }
  }
  return current_node->data;
}

int LinkedList::search(int target) {
  if (head == nullptr) {
    return -1;
  }
  Node* current_node = head;
  int position = 1;
  while (current_node != nullptr) {
    if (current_node->data == target) {
      return position;
    } else {
      current_node = current_node->link;
      position++;
    }
  }
  return -1;
}

void LinkedList::printList() {
  if (head == nullptr) {
    return;
  } else {
    Node* current_node = head;
    std::cout << "[";
    while (current_node != nullptr) {
      std::cout << current_node->data;
      if (current_node->link != nullptr) {
        std::cout << " ";
      }
      current_node = current_node->link;
    }
    std::cout << "]";
  }
}
