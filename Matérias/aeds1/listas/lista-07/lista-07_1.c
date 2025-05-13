#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

void main() {
  printf("\nSequence calculator!");

  int nTerms;
  printf("\nEnter how many terms you want: ");
  scanf(" %i", &nTerms);

  for (int i = 0; i < nTerms; i++) {
    int dividend = 1;

    for (int j = 0; j < i; j++) // could be changed for pow() in the <math.h>
    {
      dividend *= 3;
    }

    float result = 1.0 / dividend;

    printf("\n%f", result);
  }
}
