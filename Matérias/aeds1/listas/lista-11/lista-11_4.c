#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
  Para cada item desta lista, implemente todas as funções necessárias para implementar sua solução. Ao planejá-las, analise bem o grau de reusabilidade provido por cada função proposta. Em seguida, construa uma função principal (main) que permita a você testar sua solução. Em cada questão, planeje bem:

  - Qual o tipo de dado gerado pela função ou se o retorno é vazio;
  - Quais parâmetros precisam ser enviados à função para sua correta execução;
  - Qual nome melhor descreve o dado gerado (ou a funcionalidade provida) pela função.

  4. Identificar se um inteiro é par ou ímpar.
*/

int readInteger();
bool numberIsEven(int);
void writeEvenOrOdd(int);

void main() {
  printf("\nFind if a number is even.");

  int number = readInteger();

  writeEvenOfOdd(number);
}

int readInteger() {
  int number;
  printf("\nEnter a number: ");
  scanf(" %i", &number);

  return number;
}

bool numberIsEven(int number) {
  return number % 2 == 0;
}

void writeEvenOrOdd(int number) {
  if (numberIsEven(number)) {
    printf("\nThe number %i is even.", number);
  } else {
    printf("\nThe number %i is odd.", number);
  }
}