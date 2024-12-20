#include "Ponto.hpp"

#include <ostream>

Ponto::Ponto(double x, double y) : x(x), y(y) {}

std::ostream &operator<<(std::ostream &os, const Ponto &ponto) {
  os << ponto.x << " " << ponto.y;
  return os;
}
