#pragma once

#include "Onibus.hpp"
#include <array>
#include <cstddef>

class Empresa {
public:
  Empresa();

  ~Empresa();

  Onibus *adicionar_onibus(const std::string &placa, size_t lotacaoMax);

  Onibus *busca_onibus(const std::string &placa) const;

  void imprimir_estado();

private:
  std::array<Onibus *, 20> mOnibusPtrArr;
  size_t mLastUsedIdx;
};
