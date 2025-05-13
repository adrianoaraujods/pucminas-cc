#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
  printf("\nThis program writes the numbers from 10 to 1:\n");

  int n = 10;

  do {
    printf("%i ", n);
    n--;
  } while (n > 0);
}
