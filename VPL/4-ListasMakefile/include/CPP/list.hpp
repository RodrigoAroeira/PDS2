#pragma once

#include "node.hpp"

struct List {
  Node *head = nullptr;
  Node *tail = nullptr;

  void insertNode(int data);
  void display() const;
  void inverte();
  void sort_ascending(); // misterio
  void sort_reverse();   // misterio
  void sort(bool);
};
