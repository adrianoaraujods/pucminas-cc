#include <stdio.h>

/*
  Questão 1:
  Construa uma função que receba um vetor de triângulos e o seu tamanho e calcule o número de triângulos equiláteros nele presentes.

  Um triângulo é descrito por seus três lados (tipo real): A, B, C
*/

typedef struct {
  float sideA;
  float sideB;
  float sideC;
} Triangle;

int triangleArrayEquilateralCount(Triangle triangles[], int lenght) {
  int count = 0;

  for (int i = 0; i < lenght; i++) {
    float sideA = triangles[i].sideA;
    float sideB = triangles[i].sideB;
    float sideC = triangles[i].sideC;

    if (sideA == sideB && sideA == sideC) count++;
  }

  return count;
}

int main() {
  Triangle triangles[] = {
    { 10, 10, 10 },
    { 10, 2, 10 },
    { 10, 10, 10 },
    { 10, 7, 10 },
    { 10, 10, 10 },
  };

  int lenght = sizeof(triangles) / sizeof(Triangle);

  printf("Count: %i", triangleArrayEquilateralCount(triangles, lenght));

  return 0;
}