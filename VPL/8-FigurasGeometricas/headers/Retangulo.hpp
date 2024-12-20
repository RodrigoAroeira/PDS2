#pragma once

#include "FiguraGeometrica.hpp"

class Retangulo final : public FiguraGeometrica {
public:
  Retangulo(const Ponto &centro, double lado1, double lado2);

  double CalculaArea() const override;

  void Desenha() const override;

private:
  double mLado1, mLado2;
};
