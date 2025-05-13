#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
  Construa uma função que receba um arranjo de reais e o ordene em ordem crescente.
*/

void sortArrayIncreasingly(float array[], int lenght) {
  float temp;

  for (int i = 0; i < lenght; i++) {
    int curr = i;

    while (curr > 0 && array[curr] < array[curr - 1]) {
      temp = array[curr];

      array[curr] = array[curr - 1];
      array[curr - 1] = temp;

      curr--;
    }
  }
}

int main() {
  float numbers[] = { 3, 10, 9, 8, 7, 6, 7, 8, 9, 2 };
  int lenght = (numbers, sizeof(numbers) / sizeof(numbers[0]));

  sortArrayIncreasingly(numbers, lenght);

  for (int i = 0; i < lenght; i++) {
    printf("%.0f, ", numbers[i]);
  }

  return 0;
}