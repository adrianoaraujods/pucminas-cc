#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void main() {
  printf("\nFind if a year is bixest!");

  char again;

  do {
    int year;
    printf("\nEnter a year: ");
    scanf(" %i", &year);

    if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0)) {
      printf("\nThe year: %i is bixest!", year);
    } else {
      printf("\nThe year: %i is not bixest!", year);
    }

    do {
      printf("\n[Y/n] Do you wish to enter a new year? ");
      scanf(" %c", &again);
      again = toupper(again);
    } while (
      (again != 'Y' && again != 'N')                        //
      && printf("Warning: invalid input. Enter 'Y' or 'N'") //
      );
  } while (again == 'Y');
}
