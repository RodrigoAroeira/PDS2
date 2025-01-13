#include <iostream>
#include <memory>

class Teste {
public:
  Teste(int valor) : valor(valor) {
    std::cout << "Construtor " << valor << std::endl;
  }

  Teste() : Teste(0) {}
  ~Teste() { std::cout << "Destrutor " << valor << std::endl; }

public:
  int valor;
};

int main() {
  unsigned short n;
  std::cin >> n;

  if (n % 2 == 0) {
    // Leak de memoria de n objetos
    for (size_t c{1}; c <= n; ++c) {
      auto a = new Teste(c);
      (void)a; // Evitar erro de não usado

      auto unique = std::unique_ptr<Teste>(new Teste(c));
    }
  } else {
    // Nenhum leak de memoria
    auto shared = std::make_shared<Teste>(0);
    for (size_t c{1}; c <= n; ++c) {
      auto sharedCpy = shared;
      sharedCpy->valor = c;
    }
    std::cout << shared.use_count() << std::endl;
  }
}
