#include <stdio.h>

/*
  2. Construa uma função que calcule a soma de um vetor de reais.
    a) Abordagem iterativa
    b) Abordagem recursiva
*/

float arrayValuesTotal_Iterative(float array[], int lenght) {
  float sum = 0;

  for (int i = 0; i < lenght; i++) {
    sum += array[i];
  }

  return sum;
}

float arrayValuesTotal_Recursive(float array[], int lenght) {
  float sum = 0;
  lenght--;

  if (lenght >= 0) {
    sum = array[lenght] + arrayValuesTotal_Recursive(array, lenght);
  }

  return sum;
}

int main() {
  float numbers[] = { 10, 20, 30, 40 };
  int lenght = sizeof(numbers) / sizeof(numbers[0]);

  printf("\nArray sum total (Iterative): %.2f", arrayValuesTotal_Iterative(numbers, lenght));
  printf("\nArray sum total (Recursive): %.2f", arrayValuesTotal_Recursive(numbers, lenght));

  return 0;
}