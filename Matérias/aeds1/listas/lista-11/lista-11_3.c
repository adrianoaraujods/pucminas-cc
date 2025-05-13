#include <stdio.h>
#include <stdlib.h>

/*
  Para cada item desta lista, implemente todas as funções necessárias para implementar sua solução. Ao planejá-las, analise bem o grau de reusabilidade provido por cada função proposta. Em seguida, construa uma função principal (main) que permita a você testar sua solução. Em cada questão, planeje bem:

  - Qual o tipo de dado gerado pela função ou se o retorno é vazio;
  - Quais parâmetros precisam ser enviados à função para sua correta execução;
  - Qual nome melhor descreve o dado gerado (ou a funcionalidade provida) pela função.

  3. Calcular o perímetro de um quadrado.
*/

float readFloat();
float getPerimeterOfSquare(float);

void main() {
  printf("\nFind the perimeter of a square.");

  printf("\nEnter the side of the square: ");
  float side = readFloat();

  printf("The perimeter of the square is: %f", getPerimeterOfSquare(side));
}

float readFloat() {
  float number;
  scanf(" %f", &number);

  return number;
}

float getPerimeterOfSquare(float side) {
  return side * 4;
}