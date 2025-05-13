#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

void main() {
  printf("\nFind if a number is prime!");

  long int number;

  while (true) {
    bool inputHasError;
    do {
      printf("\nEnter a number (Enter zero to stop): ");
      scanf(" %i", &number);

      if (number < 0) {
        inputHasError = true;
        printf("\aWarning: invalid input, the input should be a natural number.");
      } else {
        inputHasError = false;
      }
    } while (inputHasError);

    if (number == 0) {
      printf("\nThank you for using this program!");

      return;
    }

    bool isPrime = true;
    long int flagNumber = number;
    long int i = 2;

    int sqrtOfNumber = (int)sqrt(number);

    while (i <= sqrtOfNumber && isPrime) {
      if (number % i == 0) {
        isPrime = false;
      }

      i++;
    }

    if (isPrime && number != 0) {
      printf("\nThe number %i is prime.", number);
    } else {
      printf("\nThe number %i is not prime.", number);
    }
  }
}
