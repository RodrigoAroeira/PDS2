#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>

#include "Circulo.hpp"
#include "FiguraGeometrica.hpp"
#include "Ponto.hpp"
#include "Retangulo.hpp"
#include "Triangulo.hpp"

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

    switch (Opt(opt)) {

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
      float soma{};
      for (auto figura : figuras)
        soma += figura->CalculaArea();

      std::stringstream ss; // para não alterar precisão global
      ss << std::fixed << std::setprecision(2) << soma;
      std::cout << ss.str() << std::endl;
    } break;

    case Opt::END: {

      for (auto &ptr : figuras) {
        delete ptr;
      }

      return 0;
    }

    default:
      std::cerr << "Input incorreto: " << opt << std::endl;
      break;
    }
  }
}
