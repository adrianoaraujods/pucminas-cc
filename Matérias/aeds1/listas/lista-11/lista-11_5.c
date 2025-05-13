#include <stdio.h>
#include <stdlib.h>

/*
  Para cada item desta lista, implemente todas as funções necessárias para implementar sua solução. Ao planejá-las, analise bem o grau de reusabilidade provido por cada função proposta. Em seguida, construa uma função principal (main) que permita a você testar sua solução. Em cada questão, planeje bem:

  - Qual o tipo de dado gerado pela função ou se o retorno é vazio;
  - Quais parâmetros precisam ser enviados à função para sua correta execução;
  - Qual nome melhor descreve o dado gerado (ou a funcionalidade provida) pela função.

  5. Calcular o fatorial de um número natural.
*/

int readInteger();
long int factorial(int);

void main() {
  printf("\nFind the factorial of a number.");

  int number = readInteger();

  printf("\nThe factorial of %i is %i", number, factorial(number));
}

int readInteger() {
  int number;
  printf("\nEnter a number: ");
  scanf(" %i", &number);

  return number;
}

long int factorial(int number) {
  long int result = 1;

  while (number > 0) {
    result *= number;

    number--;
  }

  return result;
}
