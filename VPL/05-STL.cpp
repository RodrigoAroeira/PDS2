#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <utility>
#include <vector>

int main() {
  std::string filename;
  std::getline(std::cin, filename);

  std::ifstream arq(filename);
  if (!arq.is_open())
    throw std::runtime_error("Não foi possível abrir o arquivo");

  std::map<std::string, int> pCounter;

  std::string linha, palavra;
  while (std::getline(arq, linha)) {
    palavra.clear();

    for (char &c : linha) {

      if (std::isalnum(c)) {
        palavra += std::tolower(c);
      } else {
        if (!palavra.empty()) {
          pCounter[palavra]++;
          palavra.clear();
        }
      }
    }

    if (!palavra.empty()) {
      pCounter[palavra]++;
    }
  }

  std::vector<std::pair<std::string, int>> sorted(pCounter.begin(),
                                                  pCounter.end());

  std::sort(sorted.begin(), sorted.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });

  for (const auto &entry : pCounter) {
    std::cout << entry.first << " " << entry.second << std::endl;
  }
}
