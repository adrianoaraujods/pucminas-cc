#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
  Para cada item desta lista, implemente todas as funções necessárias para implementar sua solução. Ao planejá-las, analise bem o grau de reusabilidade provido por cada função proposta. Em seguida, construa uma função principal (main) que permita a você testar sua solução. Em cada questão, planeje bem:

  - Qual o tipo de dado gerado pela função ou se o retorno é vazio;
  - Quais parâmetros precisam ser enviados à função para sua correta execução;
  - Qual nome melhor descreve o dado gerado (ou a funcionalidade provida) pela função.

  7. Identificar se um número natural é primo ou não.
*/

int readInteger();
bool isPrime(int);
void writePrimeOrNot(int);

void main() {
  printf("\nFind if a number is prime.");

  int number = readInteger();

  writePrimeOrNot(number);
}

int readInteger() {
  int number;
  printf("\nEnter a number: ");
  scanf(" %i", &number);

  return number;
}

bool isPrime(int number) {
  int i = 2;
  bool numberIsPrime = true;
  int numberSqrt = (int)sqrt(number);

  while (i <= numberSqrt && numberIsPrime) {
    if (number % i == 0) {
      numberIsPrime = false;
    }

    i++;
  }

  return numberIsPrime;
}

void writePrimeOrNot(int number) {
  if (isPrime(number)) {
    printf("\nThe number %i is prime.", number);
  } else {
    printf("\nThe number %i is not prime.", number);
  }
}
