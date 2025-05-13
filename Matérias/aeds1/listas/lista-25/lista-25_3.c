#include <stdio.h>

/*
  2. Construa uma função que calcule o número de elementos de um vetor de reais maior que x, sendo x também um argumento da função (também um valor parametrizado).
    a) Abordagem iterativa
    b) Abordagem recursiva
*/

int arrayElementsLargerThan_Iterrative(float array[], int lenght, float value) {
  int count = 0;

  for (int i = 0; i < lenght; i++) {
    if (array[i] > value) count++;
  }

  return count;
}

int arrayElementsLargerThan_Recursive(float array[], int lenght, float value) {
  int count = 0;
  lenght--;

  if (lenght >= 0 && array[lenght] > value) count++;

  if (lenght > 0) count += arrayElementsLargerThan_Recursive(array, lenght, value);

  return count;
}

int main() {
  float numbers[] = { -2, 5, -10, 20, -5 };
  int lenght = sizeof(numbers) / sizeof(numbers[0]);

  float value = 4;

  printf("\nNegative Numbers Count (Iterative): %i", arrayElementsLargerThan_Iterrative(numbers, lenght, value));
  printf("\nNegative Numbers Count (Recursive): %i", arrayElementsLargerThan_Recursive(numbers, lenght, value));

  return 0;
}