#include <stdio.h>

#define ROWS 2 

/*
  Construa uma função que calcule a soma da linha i da matriz, sendo i também um argumento da função.
*/

void printMatrix(float matrix[][ROWS], int lenght) {
  for (int row = 0; row < ROWS; row++) {
    printf("\n");

    for (int col = 0; col < lenght; col++) {
      printf("\t%.2f", matrix[col][row]);
    }
  }
}

float matrixRowSum(float matrix[][ROWS], int lenght, int row) {
  float sum = 0;

  for (int i = 0; i < lenght; i++) {
    sum += matrix[i][row - 1];
  }

  return sum;
}

int main() {
  float numbers[][ROWS] = { 1, 2, 4, 8, 16, 32 };

  int lenght = sizeof(numbers) / sizeof(numbers[0]);

  printMatrix(numbers, lenght);

  printf("\n\nSum: %.2f", matrixRowSum(numbers, lenght, 1));

  return 0;
}