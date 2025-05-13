#include <stdio.h>
#include <stdlib.h>

void main() {
  printf("Find the second largest number between three!\n");

  float number1;
  printf("\nEnter the 1rt number: ");
  scanf(" %f", &number1);

  float number2;
  printf("\nEnter the 2nd number: ");
  scanf(" %f", &number2);

  float number3;
  printf("\nEnter the 3rd number: ");
  scanf(" %f", &number3);

  float secondLargest;
  if (number1 > number2 && number1 > number3) {
    if (number2 > number3) {
      secondLargest = number2;
    } else {
      secondLargest = number3;
    }
  } else if (number1 > number2 || number1 > number3) {
    secondLargest = number1;
  } else if (number2 > number3) {
    secondLargest = number3;
  } else {
    secondLargest = number2;
  }

  printf("\nThe second largest number is: %f", secondLargest);
}
