#include <stdio.h>
#include <stdlib.h>

/*
  Para cada item desta lista, implemente todas as funções necessárias para implementar sua solução. Ao planejá-las, analise bem o grau de reusabilidade provido por cada função proposta. Em seguida, construa uma função principal (main) que permita a você testar sua solução. Em cada questão, planeje bem:

  - Qual o tipo de dado gerado pela função ou se o retorno é vazio;
  - Quais parâmetros precisam ser enviados à função para sua correta execução;
  - Qual nome melhor descreve o dado gerado (ou a funcionalidade provida) pela função.

  2. Calcular o maior entre dois valores reais.
*/

float readFloat();
float getLargestOf2(float, float);

void main() {
  printf("\nFind the largest number off two.");

  float n1 = readFloat();
  float n2 = readFloat();

  printf("The largest number is: %f", getLargestOf2(n1, n2));
}

float readFloat() {
  float number;
  printf("\nEnter a number: ");
  scanf(" %f", &number);

  return number;
}

float getLargestOf2(float a, float b) {
  float largest;

  if (a >= b) {
    largest = a;
  } else {
    largest = b;
  }

  return largest;
}