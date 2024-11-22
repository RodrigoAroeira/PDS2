#include "aluno.hpp"

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>

void reportAluno(const Aluno &aluno) {
  std::cout << aluno.getMatricula() << " " << aluno.getNome() << " ";
  const auto &notas = aluno.getNotas();
  for (int i = 0; i < notas.size(); i++) {
    std::cout << notas[i] << (i < notas.size() - 1 ? " " : "");
  }
  std::cout << std::endl;

  std::cout << std::fixed << std::setprecision(2) << aluno.getMedia();
  std::cout << aluno.getNotaMax() << " " << aluno.getNotaMin() << std::endl;
}

int main(int argc, char *argv[]) {
  std::vector<Aluno> alunos;

  while (true) {
    std::string nome;
    int matricula;
    std::vector<int> notas;
    std::cin >> nome;
    if (nome == "END")
      break;

    std::cin >> matricula;

    int nota;
    while (std::cin >> nota && nota != -1)
      notas.push_back(nota);

    alunos.push_back({notas, nome, matricula});
  }
  std::sort(alunos.begin(), alunos.end(), [](const Aluno &a, const Aluno &b) {
    return a.getNome()[0] < b.getNome()[0];
  });

  for (const auto &aluno : alunos)
    reportAluno(aluno);
}
