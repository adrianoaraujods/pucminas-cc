#include <stdio.h>

/*
  1. Escrever na tela um arranjo de reais de forma invertida (do último elemento do vetor ao primeiro).
    a) Abordagem iterativa
    b) Abordagem recursiva
*/

void arrayPrintInverted_Iterative(float array[], int lenght) {
  while (lenght > 0) {
    lenght--;
    printf("%f\n", array[lenght]);
  }
}

void arrayPrintInverted_Recursive(float array[], int lenght) {
  lenght--;

  if (lenght >= 0) {
    printf("%f\n", array[lenght]);

    arrayPrintInverted_Iterative(array, lenght);
  }
}

int main() {
  float array[] = { 1, 2, 3, 4, 5 };

  int lenght = sizeof(array) / sizeof(array[0]);

  arrayPrintInverted_Iterative(array, lenght);

  printf("\n\n");

  arrayPrintInverted_Recursive(array, lenght);

  return 0;
}