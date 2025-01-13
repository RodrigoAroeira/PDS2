#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define LOG_ERROR(fmt, ...)                                                    \
  fprintf(stderr, "\033[1;31m" fmt "\033[0m", ##__VA_ARGS__);

int main(void) {
  List *l = criarLista();
  int n = 5;
  if (!scanf("%d", &n))
    LOG_ERROR("Invalid value. Using standard value of %d.\n", n);

  if (n < 0) {
    LOG_ERROR("Bad allocation: invalid size `%d`\n", n);
    exit(1);
  }

  for (int i = 1; i <= n; i++)
    insertNode(l, i);

  display(l);

  Node **nodeAddr;
  nodeAddr = (Node **)calloc(n, sizeof(Node *));
  if (!nodeAddr) {
    free(nodeAddr);
    LOG_ERROR("Bad Allocation: Insufficient memory. Now Exiting")
    exit(1);
  }

  Node *p = l->head;

  for (int i = 0; i < n; i++) {
    nodeAddr[i] = p;
    p = p->next;
  }

  inverte(l);
  display(l);

  int ok = 1;
  p = l->head;
  for (int i = n - 1; i >= 0; i--) {
    if (nodeAddr[i] != p) {
      ok = 0;
      break;
    }
    p = p->next;
  }

  printf("%s\n", (ok ? "SIM" : "NAO"));

  deleteList(l);
  free(nodeAddr);
  return 0;
}
