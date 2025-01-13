#include <iostream>

void incrementar(int a, int &b, int *c) {
  a++;
  b++;
  (*c)++;
}

int main(void) {
  // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na
  // entrada
  int var1;
  std::cin >> var1;

  // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
  int *ptr1 = nullptr;
  int tamanho;

  // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha
  // com dados lidos da entrada
  std::cin >> tamanho;
  int vetor[tamanho];
  for (int i = 0; i < tamanho; i++)
    std::cin >> vetor[i];

  // 4) Imprima o ENDEREÇO da variável declarada em (1)
  std::cout << &var1 << std::endl;

  // 5) Imprima o VALOR da variável declarada em (1)
  std::cout << var1 << std::endl;

  // 6) Imprima o ENDEREÇO da variável declarada em (2)
  std::cout << &ptr1 << std::endl;

  // 7) Imprima o VALOR da variável declarada em (2)
  std::cout << ptr1 << std::endl;

  // 8) Imprima o ENDEREÇO da variável declarada em (3)
  std::cout << &vetor << std::endl;

  // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
  std::cout << &vetor[0] << std::endl;

  // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
  std::cout << vetor[0] << std::endl;

  // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em
  // (2)
  ptr1 = &var1;

  // 12) Imprima o VALOR da variável declarada em (2)
  std::cout << ptr1 << std::endl;

  // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
  std::cout << *ptr1 << std::endl;

  // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
  *ptr1 = 5;

  // 15) Imprima o VALOR da variável declarada em (1)
  std::cout << var1 << std::endl;

  // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
  ptr1 = vetor;

  // 17) Imprima o VALOR da variável declarada em (2)
  std::cout << ptr1 << std::endl;

  // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
  std::cout << *ptr1 << std::endl;

  // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada
  // em (2)
  ptr1 = &vetor[0];

  // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais
  // e 'N' se forem diferentes

  std::cout << (ptr1 == &vetor[0] ? 'S' : 'N') << std::endl;

  // 21) Imprima o VALOR da variável declarada em (2)
  std::cout << ptr1 << std::endl;

  // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
  std::cout << *ptr1 << std::endl;

  // 23) Multiplique todos os valores do vetor declarado em (3) por '10',
  // porém manipulando apenas a variável (2)

  for (int i = 0; i < tamanho; i++)
    *(ptr1 + i) *= 10;

  // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a
  // notação [] (colchetes)

  for (int i = 0; i < tamanho; i++) {
    std::cout << vetor[i] << (i < tamanho - 1 ? " " : "");
  }
  std::cout << std::endl;

  // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a
  // notação ponteiro/deslocamento Ou seja, você NÃO deve efetivamente
  // alterar o valor do ponteiro inicial de (3)
  for (int i = 0; i < tamanho; i++) {
    std::cout << *(vetor + i) << (i < tamanho - 1 ? " " : "");
  }
  std::cout << std::endl;

  // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação
  // ponteiro/deslocamento Ou seja, você NÃO deve efetivamente alterar o
  // valor do ponteiro inicial de (2)
  for (int i = 0; i < tamanho; i++)
    std::cout << *(ptr1 + i) << (i < tamanho - 1 ? " " : "");
  std::cout << std::endl;

  // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em
  // (2)
  ptr1 = &vetor[tamanho - 1];

  // 28) Imprima o VALOR da variável declarada em (2)
  std::cout << ptr1 << std::endl;

  // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
  std::cout << *ptr1 << std::endl;

  // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da
  // variável (2)
  int **ptr2 = &ptr1;

  // 31) Imprima o VALOR da variável declarada em (30)
  std::cout << ptr2 << std::endl;

  // 32) Imprima o ENDEREÇO da variável declarada em (30)
  std::cout << &ptr2 << std::endl;

  // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
  std::cout << *ptr2 << std::endl;

  // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
  std::cout << **ptr2 << std::endl;

  // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
  int a, b, c;
  std::cin >> a >> b >> c;

  // 36) Chame a função criada em (0) passando as 3 variáveis criadas em
  // (35) como parâmetro.
  incrementar(a, b, &c);

  // 37) Imprima o valor das 3 variáveis criadas em (35)
  std::cout << a << " " << b << " " << c;

  return 0;
}
