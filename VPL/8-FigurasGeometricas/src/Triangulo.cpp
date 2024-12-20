#include "Triangulo.hpp"

Triangulo::Triangulo(const Ponto &centro, double base, double altura)
    : mBase(base), mAltura(altura) {
  setCentro(centro);
}

double Triangulo::CalculaArea() const { return mBase * mAltura / 2; }

void Triangulo::Desenha() const {
  std::cout << getCentro() << " TRIANGULO" << std::endl;
}
