#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
  2)

  Construa uma função que calcule a soma dos valores de um arranjo.

    a) Abordagem iterativa
    b) Abordagem recursiva
*/

float arraySumIterative(float array[], int lenght) {
  float sum = 0;

  for (int i = 0; i < lenght; i++) {
    sum += array[i];
  }

  return sum;
}

float arraySumRecursive(float array[], int lenght) {
  lenght--;

  float sum = array[lenght];

  if (lenght > 0) {
    sum += arraySumRecursive(array, lenght);
  }

  return sum;
}

int main() {
  float array[] = { 50, 25, 35 };
  int lenght = sizeof(array) / sizeof(array[0]);

  printf("\nIterative Array Sum: %.2f", arraySumIterative(array, lenght));
  printf("\nRecursive Array Sum: %.2f", arraySumRecursive(array, lenght));

  return 0;
}