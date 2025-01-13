#pragma once

#include <cstddef>
#include <string>

class Onibus {
public:
  Onibus(const std::string &Placa, size_t capacidadeMax);

  bool subir_passageiros(size_t quantidade);

  bool descer_passageiros(size_t quantidade);

  bool transfere_passageiros(Onibus *outro, size_t quantidade);

  void imprimir_estado();

  inline bool operator==(const Onibus &outro) const {
    return mPlaca == outro.mPlaca;
  }

  inline bool operator==(const Onibus *outro) const {
    if (!outro)
      return false;

    return *this == *outro;
  }

private:
  std::string mPlaca;
  const size_t mCapacidade;
  size_t mPassageiros;
};
