#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>

#include "Onibus.hpp"

Onibus::Onibus(const std::string &placa, size_t capacidadeMax)
    : mPlaca(std::move(placa)), mCapacidade(capacidadeMax) {}

bool Onibus::descer_passageiros(size_t quantidade) {
  if (quantidade > mPassageiros) {
    std::cerr << "ERRO : faltam passageiros" << std::endl;
    return false;
  }

  mPassageiros -= quantidade;

  return true;
}

bool Onibus::subir_passageiros(size_t quantidade) {
  if ((quantidade + mPassageiros) > mCapacidade) {
    std::cerr << "ERRO : onibus lotado" << std::endl;
    return false;
  }
  mPassageiros += quantidade;
  return true;
}

bool Onibus::transfere_passageiros(Onibus *outro, size_t quantidade) {
  if (quantidade > mPassageiros ||
      quantidade + outro->mPassageiros > outro->mCapacidade) {
    std::cerr << "ERRO : transferencia cancelada" << std::endl;
    return false;
  }
  this->descer_passageiros(quantidade);
  outro->subir_passageiros(quantidade);
  return true;
}

void Onibus::imprimir_estado() {
  std::cout << mPlaca << " (" << mPassageiros << '/' << mCapacidade << ")\n";
}
