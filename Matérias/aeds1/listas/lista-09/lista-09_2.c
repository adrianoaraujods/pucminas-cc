#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

void main() {
  printf("\nFind how many even numbers in your input from 1.000 to 10.000");

  int input, count = 0;

  while (input != 0) {
    printf("\nEnter a number: ");
    scanf(" %i", &input);

    bool isEven = (input % 2) == 0;

    if (isEven && input > 1000 && input < 10000) {
      count++;
    }
  }

  printf("\nFrom the provided numbers, there is %i even numbers between 1.000 and 10.000", count);
}
