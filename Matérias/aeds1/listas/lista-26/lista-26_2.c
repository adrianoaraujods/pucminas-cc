#include <stdio.h>
#include <stdbool.h>

#define ROWS 2
#define COLS 3

/*
  2. Implemente a função que verifica se duas matrizes bidimensionais são iguais ou não.
    Argumentos: os endereços das duas matrizes a serem comparadas
    Valor gerado: true, caso sejam as matrizes iguais, ou false, caso contrário
*/

bool eqMatrix(float matrix1[ROWS][COLS], float matrix2[ROWS][COLS]) {
  bool equal = true;

  int row = 0;

  while (row < ROWS && equal) {
    int col = 0;

    while (col < COLS && equal) {
      printf("\nM1 = %.0f\t M2 = %.0f", matrix1[row][col], matrix2[row][col]);

      if (matrix1[row][col] != matrix2[row][col]) equal = false;

      col++;
    }
    row++;
  }

  return equal;
}

int main() {
  float matrix1[ROWS][COLS] = {
    1, 2, 3,
    4, 5, 6
  };
  float matrix2[ROWS][COLS] = {
    1, 2, 3,
    4, 5, 6
  };

  printf("\nEqual: %c", eqMatrix(matrix1, matrix2) ? 'y' : 'n');

  return 0;
}