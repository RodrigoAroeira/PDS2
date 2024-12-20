#include "Retangulo.hpp"

#include <iostream>

Retangulo::Retangulo(const Ponto &centro, double lado1, double lado2)
    : mLado1(lado1), mLado2(lado2) {
  setCentro(centro);
}

double Retangulo::CalculaArea() const { return mLado1 * mLado2; }

void Retangulo::Desenha() const {
  std::cout << getCentro() << " RETANGULO" << std::endl;
}
