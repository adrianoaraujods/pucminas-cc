#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

void main() {
  int n1 = 10;
  int n2 = 100;

  for (int n1 = 10, n2 = 100; n1 < 20; n1++, n2--) {
    if (n1 % 2 == 0) {
      printf("\n\t%i/%i = %f", n1, n2, (float)n1 / n2);
    } else {
      printf("\n\t%i/%i = %f", n2, n1, (float)n2 / n1);
    }
  }
}
