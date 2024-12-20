#pragma once

#include "Ponto.hpp"

class FiguraGeometrica {
public:
  FiguraGeometrica() : mCentro{0, 0} {}
  virtual ~FiguraGeometrica() = default;

  virtual double CalculaArea() const = 0;

  virtual void Desenha() const = 0;

  virtual const Ponto &getCentro() const;

  virtual void setCentro(const Ponto &ponto);

private:
  Ponto mCentro;
};
