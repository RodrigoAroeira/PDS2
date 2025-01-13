#pragma once

#include <string>
#include <vector>

class Aluno {
public:
  Aluno(std::vector<int> &notas, const std::string &nome, const int matricula);
  float getMedia() const;
  int getNotaMax() const;
  int getNotaMin() const;
  const std::vector<int> &getNotas() const;
  const std::string &getNome() const;
  const int &getMatricula() const;
  std::vector<int> getNotas();
  std::string getNome();
  int getMatricula();

private:
  std::vector<int> mNotas;
  std::string mNome;
  int mMatricula;
};
