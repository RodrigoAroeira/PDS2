#include <algorithm>
#include <fstream>
#include <iostream>

const int MAX_VIDAS = 5;
const std::string NOME_ARQUIVO = "palavras.txt";

void toUpper(std::string &str) {
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

std::string pegarPalavraN(std::ifstream &arq, const size_t n) {
  std::string palavra;
  for (size_t i = 0; i < n + 1; i++) {
    if (!(arq >> palavra))
      return "";
  }
  return palavra;
}

void acharErradas(const std::string &chute, const std::string &chave,
                  std::string &erradas) {

  for (const char &c : chute) {
    if (chave.find(c) == std::string::npos &&
        (erradas.find(c) == std::string::npos))
      erradas += c;
  }
}

std::string processarResultado(const std::string &chute,
                               const std::string &chave) {

  std::string result(chave.length(), '*');

  for (size_t i = 0; i < chute.size(); i++) {
    const char &c = chute[i];

    if (chave.find(c) != std::string::npos) {
      if (c == chave[i])
        result[i] = std::toupper(c);
      else
        result[i] = std::tolower(c);
    }
  }

  return result;
}

void jogar(const std::string &chave) {
  int vidas = MAX_VIDAS;
  std::string erradas;

  while (vidas--) {
    std::string chute, result;
    std::cin >> chute;
    toUpper(chute);

    acharErradas(chute, chave, erradas);
    result = processarResultado(chute, chave);

    std::cout << result << " (" + erradas + ')' << std::endl;

    if (result == chave) {
      std::cout << "GANHOU!" << std::endl;
      return;
    }
  }

  std::cout << "PERDEU! " << chave << std::endl;
}

int main(void) {
  std::ifstream arquivo(NOME_ARQUIVO);

  size_t n;
  std::cin >> n;
  std::string chave = pegarPalavraN(arquivo, n);
  toUpper(chave);

  jogar(chave);
}
