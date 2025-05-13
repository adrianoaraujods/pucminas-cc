#include <stdio.h>
#include <stdlib.h>

void main() {
  printf("Find if a number is even!\n");

  int number;
  printf("Type a number: ");
  scanf(" %d", &number);

  if ((number % 2) == 0) {
    printf("The number: '%d' is even.\n", number);
  } else {
    printf("The number: '%d' is odd.\n", number);
  }
}
