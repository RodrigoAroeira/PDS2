#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

struct Ponto {
  double x, y;

  Ponto(double x, double y) : x(x), y(y) {}

  friend std::ostream &operator<<(std::ostream &os, const Ponto &p) {
    os << p.x << " " << p.y;
    return os;
  }
};

class FiguraGeometrica {
public:
  FiguraGeometrica(const std::string &tipo) : mCentro{0, 0}, mNome(tipo) {}
  virtual ~FiguraGeometrica() = default;

  virtual double CalculaArea() const = 0;

  virtual void Desenha() { std::cout << mCentro << " " << mNome << std::endl; }

  virtual const Ponto &getCentro() const { return mCentro; }

  virtual void setCentro(const Ponto &ponto) { mCentro = ponto; }

private:
  Ponto mCentro;
  const std::string mNome;
};

class Retangulo final : public FiguraGeometrica {
public:
  Retangulo(const Ponto &centro, double lado1, double lado2)
      : FiguraGeometrica("RETANGULO"), mLado1(lado1), mLado2(lado2) {
    setCentro(centro);
  }

  double CalculaArea() const override { return mLado1 * mLado2; }

private:
  double mLado1, mLado2;
};

class Circulo final : public FiguraGeometrica {
public:
  Circulo(const Ponto &centro, double raio)
      : FiguraGeometrica("CIRCULO"), mRaio(raio) {
    setCentro(centro);
  };

  double CalculaArea() const override { return M_PI * mRaio * mRaio; };

private:
  double mRaio;
};

class Triangulo final : public FiguraGeometrica {
public:
  Triangulo(const Ponto &centro, double base, double altura)
      : FiguraGeometrica("TRIANGULO"), mBase(base), mAltura(altura) {
    setCentro(centro);
  };

  double CalculaArea() const override { return mBase * mAltura / 2; };

private:
  double mBase, mAltura;
};

enum class Opt {
  RETANGULO = 'R',
  CIRCULO = 'C',
  TRIANGULO = 'T',
  DESENHA = 'D',
  AREA = 'A',
  END = 'E'
};

int main() {
  std::vector<FiguraGeometrica *> figuras;

  while (true) {
    char opt;
    double x, y, raio, base, altura;
    std::cin >> opt;

    switch ((Opt)opt) {

    case Opt::RETANGULO: {
      std::cin >> x >> y >> base >> altura;
      figuras.push_back(new Retangulo({x, y}, base, altura));
    } break;

    case Opt::CIRCULO: {
      std::cin >> x >> y >> raio;
      figuras.push_back(new Circulo({x, y}, raio));
    } break;

    case Opt::TRIANGULO: {
      std::cin >> x >> y >> base >> altura;
      figuras.push_back(new Triangulo({x, y}, base, altura));
    } break;

    case Opt::DESENHA: {
      for (auto figura : figuras)
        figura->Desenha();
    } break;

    case Opt::AREA: {
      double soma{};
      for (auto figura : figuras)
        soma += figura->CalculaArea();

      std::stringstream ss; // para não alterar precisão global
      ss << std::fixed << std::setprecision(2) << soma << std::endl;
      std::cout << ss.str();
    } break;

    case Opt::END: {
      for (auto ptr : figuras) {
        delete ptr;
      }
      return 0;
    } break;

    default:
      break;
    }
  }
}
