#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List *criarLista() {
  List *lista = (List *)calloc(1, sizeof(List));

  lista->head = NULL;
  lista->tail = NULL;
  lista->size = 0;

  return lista;
}

void insertNode(List *l, int data) {
  Node *newNode = (Node *)calloc(1, sizeof(Node));
  newNode->data = data;

  if (!l->head)
    l->head = newNode;
  else
    l->tail->next = newNode;

  l->tail = newNode;
  l->size++;
}

void display(List *l) {
  if (!l->size)
    return;

  for (Node *curr = l->head; curr != NULL; curr = curr->next) {
    printf("%d ", curr->data);
  }
  printf("\n");
}

void inverte(List *l) {
  if (!l->head || l->head == l->tail)
    return;

  Node *prev = NULL;
  Node *curr = l->head;
  Node *next = NULL;

  l->tail = l->head;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  l->head = prev;
}

void sort_ascending(List *l) {
  Node *p = l->head;
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

void deleteList(List *l) {
  if (l->size == 0)
    return;

  Node *curr = l->head;
  Node *next = NULL;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  free(l);
}
