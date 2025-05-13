#include <stdio.h>

#define ROWS 3
#define COLS 2

/*
  1. Implemente a função para realizar a leitura dos valores para uma matriz bidimensional.
    Argumento: o endereço para uma matriz de reais
    Valor gerado: nenhum
*/

void readMatrix(float matrix[ROWS][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    printf("\n");
    for (int col = 0; col < COLS; col++) {
      float cell;
      printf("%i-%i: ", row + 1, col + 1);
      scanf(" %f", &cell);

      matrix[row][col] = cell;
      printf("\t");
    }
  }
}

int main() {
  float matrix[ROWS][COLS] = {};

  readMatrix(matrix);

  for (int row = 0; row < ROWS; row++) {
    printf("\n");

    for (int col = 0; col < COLS; col++) {
      printf("%i-%i: %.0f\t", row + 1, col + 1, matrix[row][col]);
    }
  }

  return 0;
}