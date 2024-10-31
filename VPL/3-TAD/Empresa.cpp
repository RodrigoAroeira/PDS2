#include "Empresa.hpp"
#include "Onibus.hpp"
#include <array>
#include <cstddef>
#include <cstdlib>

Empresa::Empresa() : mLastUsedIdx(0) {
  for (auto &ptr : mOnibusPtrArr) {
    ptr = nullptr;
  }
}

Empresa::~Empresa() {
  for (auto &ptr : mOnibusPtrArr) {
    delete ptr;
    ptr = nullptr;
  }
}

Onibus *Empresa::adicionar_onibus(const std::string &placa,
                                  size_t capacidadeMax) {
  if (busca_onibus(placa)) {
    return nullptr;
  }
  return mOnibusPtrArr.at(mLastUsedIdx++) = new Onibus{placa, capacidadeMax};
}

Onibus *Empresa::busca_onibus(const std::string &placa) const {
  Onibus tmp{placa, 0};
  for (const auto &ptr : mOnibusPtrArr) {
    if (tmp == ptr) {
      return ptr;
    }
  }
  return nullptr;
}

void Empresa::imprimir_estado() {
  for (auto &ptr : mOnibusPtrArr)
    if (ptr)
      ptr->imprimir_estado();
}
