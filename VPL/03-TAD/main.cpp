#include "Empresa.hpp"
#include "Onibus.hpp"

#include <iostream>
#include <utility>

#define PRINT_ONIBUS_NOT_FOUND std::cout << "ERRO : onibus inexistente" << std::endl

enum Option {
  CRIAR_ONIBUS = 'C',
  SUBIR_PASSAGEIROS = 'S',
  DESCER_PASSAGEIROS = 'D',
  TRANSFERIR_PASSAGEIROS = 'T',
  IMPRIMIR_ESTADO = 'I',
  FINALIZAR = 'F'
};

std::pair<std::string, size_t> getPlacaLotacao() {
  std::string placa;
  size_t n;
  std::cin >> placa >> n;
  return {placa, n};
}

std::pair<std::string, std::pair<std::string, size_t>> getPlacaPlacaLotacao() {
  std::string p1;
  std::cin >> p1;
  auto placaLotacao = getPlacaLotacao();
  return {p1, placaLotacao};
}

void handleCreateBus(Empresa &e) {
  auto placaLotacao = getPlacaLotacao();
  std::string placa = placaLotacao.first;
  int n = placaLotacao.second;
  auto bus = e.adicionar_onibus(placa, n);
  std::cout << (bus ? "novo onibus cadastrado" : "ERRO : onibus repetido")
            << std::endl;
}

void handleBoardPassengers(Empresa &e) {
  auto placaLotacao = getPlacaLotacao();
  std::string placa = placaLotacao.first;
  int n = placaLotacao.second;
  auto bus = e.busca_onibus(placa);
  if (!bus) {
    PRINT_ONIBUS_NOT_FOUND;
    return;
  }
  if (bus->subir_passageiros(n)) {
    std::cout << "passageiros subiram com sucesso" << std::endl;
  }
}

void handleDisembarkPassengers(Empresa &e) {
  auto placaLotacao = getPlacaLotacao();
  std::string placa = placaLotacao.first;
  int n = placaLotacao.second;
  auto bus = e.busca_onibus(placa);
  if (!bus) {
    PRINT_ONIBUS_NOT_FOUND;
    return;
  }
  if (bus->descer_passageiros(n)) {
    std::cout << "passageiros desceram com sucesso" << std::endl;
  }
}

void handleTransferPassengers(Empresa &e) {
  auto elem = getPlacaPlacaLotacao();
  std::string placa1 = elem.first;
  std::string placa2 = elem.second.first;
  size_t n = elem.second.second;
  auto bus1 = e.busca_onibus(placa1);
  auto bus2 = e.busca_onibus(placa2);
  if (!bus1 || !bus2) {
    PRINT_ONIBUS_NOT_FOUND;
    return;
  }
  if (bus1->transfere_passageiros(bus2, n)) {
    std::cout << "transferencia de passageiros efetuada" << std::endl;
  }
}

int main() {
  Empresa e;
  char opt;

  while (true) {
    std::cin >> opt;
    opt = std::toupper(opt);

    switch (opt) {
    case CRIAR_ONIBUS:
      handleCreateBus(e);
      break;
    case SUBIR_PASSAGEIROS:
      handleBoardPassengers(e);
      break;
    case DESCER_PASSAGEIROS:
      handleDisembarkPassengers(e);
      break;
    case TRANSFERIR_PASSAGEIROS:
      handleTransferPassengers(e);
      break;
    case IMPRIMIR_ESTADO:
      e.imprimir_estado();
      break;
    case FINALIZAR:
      return 0;
    default:
      std::cerr << "Opção inválida" << std::endl;
      break;
    }
  }
}
