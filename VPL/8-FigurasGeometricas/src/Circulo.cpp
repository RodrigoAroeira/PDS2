#include "Circulo.hpp"

#include <cmath>
#include <iostream>

Circulo::Circulo(const Ponto &centro, double raio) : mRaio(raio) {
  setCentro(centro);
}

double Circulo::CalculaArea() const { return M_PI * mRaio * mRaio; }

void Circulo::Desenha() const {
  std::cout << getCentro() << " CIRCULO" << std::endl;
}
