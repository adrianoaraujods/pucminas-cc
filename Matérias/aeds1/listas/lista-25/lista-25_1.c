#include <stdio.h>

/*
  1. Construa uma função que calcule a quantidade de valores negativos presentes em um vetor.
    a) Abordagem iterativa
    b) Abordagem recursiva
*/

int arrayNegativeValuesCountIterrative(float array[], int lenght) {
  int count = 0;

  for (int i = 0; i < lenght; i++) {
    if (array[i] < 0) count++;
  }

  return count;
}

int arrayNegativeValuesCountRecursive(float array[], int lenght) {
  int count = 0;
  lenght--;

  if (lenght >= 0 && array[lenght] < 0) count++;

  if (lenght > 0) count += arrayNegativeValuesCountRecursive(array, lenght);

  return count;
}

int main() {
  float numbers[] = { -2, 5, -10, 20, -5 };
  int lenght = sizeof(numbers) / sizeof(numbers[0]);

  printf("\nNegative Numbers Count (Iterative): %i", arrayNegativeValuesCountIterrative(numbers, lenght));
  printf("\nNegative Numbers Count (Recursive): %i", arrayNegativeValuesCountRecursive(numbers, lenght));

  return 0;
}