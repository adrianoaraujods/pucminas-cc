#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void problem1() {
  printf("Check if a year is bixest!\n");

  int year;
  printf("Enter a year: ");
  scanf(" %d", &year);

  if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0)) {
    printf("The year: %d is bixest!", year);
  } else {
    printf("The year: %d is not bixest!", year);
  }
}
