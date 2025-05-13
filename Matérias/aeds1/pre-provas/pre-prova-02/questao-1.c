#include <stdio.h>

#define MAX_ROW 4
#define MAX_COL 4

int matrixSearch(float matrix[MAX_ROW][MAX_COL], float key) {
  int count = 0;

  for (int row = 1; row < MAX_ROW; row++) {
    for (int col = MAX_COL - row; col < MAX_COL; col++) {
      if (matrix[row][col] == key) count++;
    }
  }

  return count;
}

int main() {
  float matrix[MAX_COL][MAX_COL] = {
    0, 2, 0, 4,
    1, 0, 3, 4,
    0, 2, 3, 4,
    1, 2, 3, 4,
  };

  printf("\nCount: %d", matrixSearch(matrix, 2));

  return 0;
}