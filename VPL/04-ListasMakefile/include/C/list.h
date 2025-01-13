#pragma once

#include "node.h"

typedef struct List {
  struct Node *head;
  struct Node *tail;
  unsigned size;
} List;

List *criarLista();

void insertNode(List *l, int data);

void display(List *l);

void inverte(List *l);

void sort_ascending(List *l);

void deleteList(List *l);
