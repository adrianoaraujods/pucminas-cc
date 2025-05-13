#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

void main() {
  printf("\nFind the divisors of a number!");

  int number;
  printf("\nEnter a number: ");
  scanf(" %i", &number);

  int count = 0;

  printf("\n");

  for (int i = 1; i <= number; i++) {
    if (number % i == 0) {
      printf("%i, ", i);
      count++;
    }
  }

  printf("\nTotal count: %i", count);
}
