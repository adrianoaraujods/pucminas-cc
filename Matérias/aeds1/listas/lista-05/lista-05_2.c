#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void main() {
  printf("\nPower Calculator!");

  float base;
  printf("\nEnter the base number: ");
  scanf(" %f", &base);

  int power;

  do {
    printf("\nEnter the power number: ");
    scanf(" %i", &power);
  } while (
    (power < 0)                                                                             //
    && printf("\aWarning: invalid input. The number should be a positive integer or zero.") //
    );

  float result = 1;

  for (int i = 0; i < power; i++) {
    result *= base;
  }

  printf("\n%fe%i = %f", base, power, result);
}
