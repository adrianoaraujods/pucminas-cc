#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

void main() {
  printf("\nEven and Odd counter!");

  bool hasInputError;
  int numbers;

  int evenNumbers = 0;
  int oddNumbers = 0;

  do {
    printf("\nEnter the numbers amount that will be entered: ");
    scanf(" %i", &numbers);

    if (numbers <= 0) {
      printf("Warning: invalid input, the number should be greater than zero.");
      hasInputError = true;
    } else {
      hasInputError = false;
    }
  } while (hasInputError);

  for (int i = 0; i < numbers; i++) {
    int number;
    do {
      printf("\nEnter a number: ");
      scanf(" %i", &number);

      if (number < 0) {
        printf("Warning: invalid input, the number should be positive.");
        hasInputError = true;
      } else {
        hasInputError = false;
      }
    } while (hasInputError);

    if (number % 2 == 0) {
      evenNumbers++;
    } else {
      oddNumbers++;
    }
  }

  float evenPercentage = evenNumbers * 100.0 / numbers;
  float oddPercentage = oddNumbers * 100.0 / numbers;

  printf("\nEven count: %i/%i, %.1f%%", evenNumbers, numbers, evenPercentage);
  printf("\nOdd count: %i/%i, %.1f%%", oddNumbers, numbers, oddPercentage);
}
