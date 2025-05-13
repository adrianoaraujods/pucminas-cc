#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Ordenar três valores lidos em ordem decrescente. Sua solução deverá conter:

// - Uma função que descreva na tela do monitor de vídeo os objetivos do programa.
void presentation() {
  printf("\nSort three numbers decreasingly!");
}

// - Uma função que leia um valor real.
float readFloat() {
  float number;
  printf("\nEnter a number: ");
  scanf(" %f", &number);

  return number;
}

// - Uma função que troque os valores entre duas variáveis passadas por referência.
void swapAddress(float* a, float* b) {
  float temp = *a;

  *a = *b;
  *b = temp;
}

// - Uma função que receba três valores reais passados por referência.
void sortThreeNumbers(float* a, float* b, float* c) {
  if (*c > *b && *c > *a) {
    printf(" swap");
    swapAddress(&*c, &*a);
  }

  if (*b > *a) {
    printf(" swap");
    swapAddress(&*b, &*a);
  }

  if (*c > *b) {
    printf(" swap");
    swapAddress(&*c, &*b);
  }
}

// - Uma função que escreva na tela do monitor de vídeo três valores passados por valor.
void writeThreeValues(float a, float b, float c) {
  printf("\nThe sorted numbers are:");
  printf("\n\t1. %f", a);
  printf("\n\t2. %f", b);
  printf("\n\t3. %f", c);
}

// A função principal deverá controlar os fluxos das chamadas às funções de forma a atender o enunciado deste exercício.
void main() {
  presentation();

  float a = readFloat();
  float b = readFloat();
  float c = readFloat();

  sortThreeNumbers(&a, &b, &c);

  writeThreeValues(a, b, c);
}