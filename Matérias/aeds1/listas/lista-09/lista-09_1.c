#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

void main() {
  printf("\nFind the avarage of numbers!");

  int input, count = 0, sum = 0;

  while (input != 0) {
    printf("\nEnter a number: ");
    scanf(" %i", &input);

    if (input != 0) {
      sum += input;
      count++;
    }
  }

  if (count == 0) {
    printf("\nYou didn't enter any number!");

    return;
  }

  float avarage = (float)sum / count;

  printf("\nThe avarage is: %.2f", avarage);
}
