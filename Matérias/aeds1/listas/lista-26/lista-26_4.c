#include <stdio.h>

#define ROWS 3
#define COLS 3

/*
  4. Para uma matriz quadrada de reais, construa uma função que calcule a diferença entre o maior valor
  presente acima de sua diagonal principal e o maior valor presente abaixo da diagonal principal.
    Argumento: o endereço da matriz quadrada de reais
    Valor gerado: um valor real relativo à diferença entre os maiores valores acima e abaixo da diagonal
*/

float matrixDiagonalAmpliture(float matrix[ROWS][COLS]) {
  float amplitude = 0;

  if (ROWS >= 2 && COLS >= 2) {
    float upper = matrix[0][1];
    float lower = matrix[1][0];

    for (int row = 0; row < ROWS; row++) {
      // Upper main diagonal
      for (int col = row + 1; col < COLS; col++) {
        if (matrix[row][col] > upper) upper = matrix[row][col];
      }

      // Lower main diagonal
      for (int col = 0; col < row; col++) {
        if (matrix[row][col] > lower) lower = matrix[row][col];
      }
    }

    printf("\nUpper: %f", upper);
    printf("\nLower: %f", lower);

    amplitude = upper - lower;
  }

  return amplitude;
}

int main() {
  float matrix[ROWS][COLS] = {
    2  , 4  , 8,
    16 , 32 , 64,
    128, 256, 512
  };

  printf("\nAmplitude: %f", matrixDiagonalAmpliture(matrix));

  return 0;
}