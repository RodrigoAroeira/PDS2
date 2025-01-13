#include "FiguraGeometrica.hpp"

class Triangulo final : public FiguraGeometrica {
public:
  Triangulo(const Ponto &centro, double base, double altura);

  double CalculaArea() const override;

  void Desenha() const override;

private:
  double mBase, mAltura;
};
