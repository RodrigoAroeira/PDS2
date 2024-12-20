#include "FiguraGeometrica.hpp"

class Circulo final : public FiguraGeometrica {
public:
  Circulo(const Ponto &centro, double raio);

  double CalculaArea() const override;

  void Desenha() const override;

private:
  double mRaio;
};
