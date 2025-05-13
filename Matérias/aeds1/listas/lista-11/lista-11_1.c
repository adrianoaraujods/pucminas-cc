#include <stdio.h>
#include <stdlib.h>

/*
  Para cada item desta lista, implemente todas as funções necessárias para implementar sua solução. Ao planejá-las, analise bem o grau de reusabilidade provido por cada função proposta. Em seguida, construa uma função principal (main) que permita a você testar sua solução. Em cada questão, planeje bem:

  - Qual o tipo de dado gerado pela função ou se o retorno é vazio;
  - Quais parâmetros precisam ser enviados à função para sua correta execução;
  - Qual nome melhor descreve o dado gerado (ou a funcionalidade provida) pela função.

  1. Calcular a soma de dois valores reais.
*/

float readFloat();
float sumOf2(float, float);

void main() {
  printf("\nGet the sum of two numbers.");

  float n1 = readFloat();
  float n2 = readFloat();

  printf("%f + %f = %f", n1, n2, sumOf2(n1, n2));
}

float readFloat() {
  float number;
  printf("\nEnter a number: ");
  scanf(" %f", &number);

  return number;
}

float sumOf2(float a, float b) {
  return a + b;
}