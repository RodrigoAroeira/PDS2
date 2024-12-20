#pragma once

#include <iostream>

struct Ponto {
  double x, y;

  Ponto(double x, double y);

  friend std::ostream &operator<<(std::ostream &os, const Ponto &p);
};
