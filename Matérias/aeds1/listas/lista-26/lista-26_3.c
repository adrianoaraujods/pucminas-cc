#include <stdio.h>
#include <stdbool.h>

#define ROWS 2
#define COLS 3

/*
  3. Implemente uma função que identifique o maior valor presente na linha i de uma matriz de reais, sendo i também um argumento da função.
    Argumentos: o endereço da matriz de reais e um valor inteiro relativo à linha chave da pesquisa
    Valor gerado: um valor real correspondente ao maior valor encontrado na linha
*/

float matrixRowLargest(float matrix[ROWS][COLS], int row) {
  float largest = 0;

  if (row > 0 && row <= ROWS) {
    row--;

    largest = matrix[row][0];

    for (int col = 1; col < COLS; col++) {
      if (matrix[row][col] > largest) largest = matrix[row][col];
    }
  }

  return largest;
}

int main() {
  float matrix[ROWS][COLS] = {
    2, 8, 4,
    32, 64, 16
  };

  printf("\nLargest: %.0f", matrixRowLargest(matrix, 2));

  return 0;
}