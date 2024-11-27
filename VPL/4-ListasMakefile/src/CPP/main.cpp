#include "list.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

  struct List lista;

  int n = 12;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    lista.insertNode(i);
  }

  lista.display();

  const auto nodeAddr = new Node *[n];
  Node *p = lista.head;
  for (int i = 0; i < n; i++) {
    nodeAddr[i] = p;
    p = p->next;
  }

  lista.inverte();
  lista.display();

  bool ok = true;

  p = lista.head;
  for (int i = n - 1; i >= 0; i--) {
    if (nodeAddr[i] != p) {
      ok = false;
      break;
    }
    p = p->next;
  }

  cout << (ok ? "SIM" : "NAO") << endl;
  delete[] nodeAddr;
}
