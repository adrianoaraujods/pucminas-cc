#include <stdio.h>
#include <stdlib.h>

void main() {
  printf("Find your ideal weight!\n");

  char gender;
  printf("\nEnter your gender [M/F]: ");
  scanf(" %c", &gender);

  if (!(gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f')) {
    printf("\nThe typed gender: '%c' does not exist!", gender);

    return;
  };

  float height;
  printf("\nEnter your height in meters: ");
  scanf(" %f", &height);

  float idealWeight;

  if (gender == 'M' || gender == 'm') {
    idealWeight = (72.7 * height) - 58;
  } else {
    idealWeight = (62.1 * height) - 44.7;
  }

  printf("\nYour ideal weight is: %f kg", idealWeight);
}
