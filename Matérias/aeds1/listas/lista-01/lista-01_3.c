#include <stdio.h>
#include <stdlib.h>

void main() {
  printf("Find the largest number between tree numbers!\n");

  float number1;
  printf("Type a number: ");
  scanf(" %f", &number1);

  float number2;
  printf("Type another number: ");
  scanf(" %f", &number2);

  float number3;
  printf("Type the last number: ");
  scanf(" %f", &number3);

  float largest;
  if (number1 > number2 || number1 > number3) {
    largest = number1;
  } else if (number2 > number3) {
    largest = number2;
  } else {
    largest = number3;
  }

  printf("The largest number is %f.\n", largest);
}
