#include "aluno.hpp"
#include <algorithm>

Aluno::Aluno(std::vector<int> &notas, const std::string &nome,
             const int matricula)
    : mNotas(std::move(notas)), mNome(nome), mMatricula(matricula) {}

float Aluno::getMedia() const {
  float soma = 0;
  for (const auto nota : mNotas)
    soma += nota;

  return soma / mNotas.size();
}

int Aluno::getNotaMax() const {
  return *std::max_element(mNotas.begin(), mNotas.end());
}

int Aluno::getNotaMin() const {
  return *std::min_element(mNotas.begin(), mNotas.end());
}

const std::vector<int> &Aluno::getNotas() const { return mNotas; }
const std::string &Aluno::getNome() const { return mNome; }
const int &Aluno::getMatricula() const { return mMatricula; }
