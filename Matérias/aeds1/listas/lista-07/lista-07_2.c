#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

void main() {
  printf("\nFibonacci Sequence!");

  int nTerms;
  printf("\nEnter how many terms you want: ");
  scanf(" %i", &nTerms);

  int a = 0;
  int b = 1;

  printf("1, ");

  for (int i = 1; i < nTerms; i++) {
    int term = a + b;

    a = b;
    b = term;

    printf("%i, ", term);
  }
}
