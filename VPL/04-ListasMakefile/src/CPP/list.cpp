#include "list.hpp"

#include <iostream>

void List::insertNode(int data) {
  Node *aux = new Node{data, nullptr};

  if (!head) {
    head = aux;
    tail = aux;
  } else {
    tail->next = aux;
    tail = aux;
  }
}

List::~List() {
  Node *aux = head;
  while (aux) {
    Node *next = aux->next;
    delete aux;
    aux = next;
  }
}

void List::display() const {
  for (auto aux = head; aux; aux = aux->next)
    std::cout << aux->data << " ";

  std::cout << std::endl;
}

void List::inverte() {
  if (!head || head == tail)
    return;

  Node *prev = nullptr;
  Node *curr = head;
  Node *next = nullptr;

  tail = head;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
}

void List::sort_ascending() { // misterio
  Node *p = head;
  while (p->next) {
    Node *q = p->next;
    Node *m = p;
    while (q) {
      if (q->data < m->data)
        m = q;

      q = q->next;
    }
    int aux = m->data;
    m->data = p->data;
    p->data = aux;
    p = p->next;
  }
}

void List::sort_reverse() {
  Node *p = head;
  while (p->next) {
    Node *q = p->next;
    Node *m = p;
    while (q) {
      if (q->data > m->data)
        m = q;

      q = q->next;
    }
    int aux = m->data;
    m->data = p->data;
    p->data = aux;
    p = p->next;
  }
}

void List::sort(bool reverse = false) {
  return reverse ? sort_reverse() : sort_ascending();
}
