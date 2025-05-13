#include <stdio.h>
#include <stdlib.h>

void main() {
  printf("Find the Largest number!\n");

  float number1;
  printf("Type a number: ");
  scanf(" %f", &number1);

  float number2;
  printf("Type another number: ");
  scanf(" %f", &number2);

  float largest;
  if (number1 > number2) {
    largest = number1;
  } else {
    largest = number2;
  }

  printf("The largest number is %f.\n", largest);
}
