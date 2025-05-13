#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Construa um programa que calcule a área de um retângulo. Planeje, com calma, cada uma das funções que deverão compor o programa: apresentação do objetivo do software; a leitura de cada um dos dados necessários para solucionar o problema (base e altura), rejeitando a leitura de valores negativos; o cálculo da área; a escrita do resultado e a função principal, encarregada de orquestrar o fluxo das chamadas para atender ao propósito desta questão.

float readPositiveFloat(char*);
float areaOfRectangle(float, float);
void writeAreaOfRectangle(float, float);

void main() {
  printf("\nArea of Rectangle");

  float base = readPositiveFloat("base");
  float height = readPositiveFloat("height");

  writeAreaOfRectangle(base, height);
}

float readPositiveFloat(char* message) {
  float number;
  bool hasInputError;

  do {
    printf("\nEnter the %s: ", message);
    scanf(" %f", &number);

    hasInputError = number < 0;

    if (hasInputError) {
      printf("\aWarning: invalid input, the number must be positive.");
    }
  } while (hasInputError);

  return number;
}

float areaOfRectangle(float base, float height) {
  float area = 0;

  if (base >= 0 && height >= 0) {
    area = base * height;
  } else {
    printf("\aError: base and height must be positive.");
  }

  return area;
}

void writeAreaOfRectangle(float base, float height) {
  printf("\nRetangle: %.2f x %.2f", base, height);
  printf("\n\tArea: %.2f", areaOfRectangle(base, height));
}